//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : externaltools.cpp
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "environmentconfig.h"
#include "imacromanager.h"
#include <wx/aui/framemanager.h>
#include "async_executable_cmd.h"
#include <wx/bitmap.h>
#include "dirsaver.h"
#include "cl_aui_tb_are.h"
#include <wx/app.h>
#include "workspace.h"
#include "globals.h"
#include "externaltooldlg.h"
#include <wx/menu.h>
#include "externaltools.h"
#include <wx/xrc/xmlres.h>
#include <wx/log.h>
#include <algorithm>
#include "plugin_version.h"

static ExternalToolsPlugin* thePlugin = NULL;

struct DecSort {
	bool operator()(const ToolInfo &t1, const ToolInfo &t2) {
		return t1.GetName().CmpNoCase(t2.GetName()) > 0;
	}
};

//Define the plugin entry point
extern "C" EXPORT IPlugin *CreatePlugin(IManager *manager)
{
	if (thePlugin == 0) {
		thePlugin = new ExternalToolsPlugin(manager);
	}
	return thePlugin;
}

extern "C" EXPORT PluginInfo GetPluginInfo()
{
	PluginInfo info;
	info.SetAuthor(wxT("Eran Ifrah"));
	info.SetName(wxT("ExternalTools"));
	info.SetDescription(_("A plugin that allows user to launch external tools from within CodeLite"));
	info.SetVersion(wxT("v1.0"));
	return info;
}

extern "C" EXPORT int GetPluginInterfaceVersion()
{
	return PLUGIN_INTERFACE_VERSION;
}

ExternalToolsPlugin::ExternalToolsPlugin(IManager *manager)
		: IPlugin       (manager)
		, topWin        (NULL)
		, m_pipedProcess(NULL)
		, m_parentMenu  (NULL)
{
	m_longName = _("A plugin that allows user to launch external tools from within CodeLite");
	m_shortName = wxT("ExternalTools");
	topWin = m_mgr->GetTheApp();

	topWin->Connect(XRCID("stop_external_tool"), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnStopExternalTool), NULL, (wxEvtHandler*)this);
	topWin->Connect(34733,                       wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnRecreateTB), NULL, (wxEvtHandler*)this);
	topWin->Connect(XRCID("stop_external_tool"), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ExternalToolsPlugin::OnStopExternalToolUI), NULL, (wxEvtHandler*)this);

	for (int i=0; i<MAX_TOOLS; i++) {
		wxString winid = wxString::Format(wxT("external_tool_%d"), i);
		topWin->Connect(wxXmlResource::GetXRCID(winid.c_str()), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnLaunchExternalTool), NULL, this);
		topWin->Connect(wxXmlResource::GetXRCID(winid.c_str()), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ExternalToolsPlugin::OnLaunchExternalToolUI), NULL, this);
	}
}

ExternalToolsPlugin::~ExternalToolsPlugin()
{
	topWin->Disconnect(XRCID("external_tools_settings"), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnSettings), NULL, (wxEvtHandler*)this);
	topWin->Disconnect(XRCID("stop_external_tool"), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnStopExternalTool), NULL, (wxEvtHandler*)this);
	topWin->Disconnect(34733,                       wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnRecreateTB), NULL, (wxEvtHandler*)this);
	topWin->Disconnect(XRCID("stop_external_tool"), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ExternalToolsPlugin::OnStopExternalToolUI), NULL, (wxEvtHandler*)this);

	for (int i=0; i<MAX_TOOLS; i++) {
		wxString winid = wxString::Format(wxT("external_tool_%d"), i);
		topWin->Disconnect(wxXmlResource::GetXRCID(winid.c_str()), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnLaunchExternalTool), NULL, this);
		topWin->Disconnect(wxXmlResource::GetXRCID(winid.c_str()), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(ExternalToolsPlugin::OnLaunchExternalToolUI), NULL, this);
	}
}

clToolBar *ExternalToolsPlugin::CreateToolBar(wxWindow *parent)
{
	//support both toolbars icon size
	m_tb = NULL;
	if (m_mgr->AllowToolbar()) {
		int size = m_mgr->GetToolbarIconSize();

		m_tb = new clToolBar(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, clTB_DEFAULT_STYLE);
		m_tb->SetToolBitmapSize(wxSize(size, size));

		ExternalToolsData inData;
		m_mgr->GetConfigTool()->ReadObject(wxT("ExternalTools"), &inData);

		if (size == 24) {
			m_tb->AddTool(XRCID("external_tools_settings"), _("Configure external tools..."), m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/24/external-tools/configure")), _("Configure external tools..."));
			m_tb->AddTool(XRCID("stop_external_tool"),      _("Stop external tool"),          m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/24/build/stop")),               _("Stop external tool"));
		} else {
			m_tb->AddTool(XRCID("external_tools_settings"), _("Configure external tools..."), m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/16/external-tools/configure") ), _("Configure external tools..."));
			m_tb->AddTool(XRCID("stop_external_tool"),      _("Stop external tool"),          m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/16/build/stop")),                _("Stop external tool"));
		}
		m_tb->AddSeparator();
#if USE_AUI_TOOLBAR
		m_tb->SetArtProvider(new CLMainAuiTBArt());
#endif
		std::vector<ToolInfo> tools = inData.GetTools();
		std::sort(tools.begin(), tools.end(), DecSort());

		for (size_t i=0; i<tools.size(); i++) {
			ToolInfo ti = tools.at(i);

			wxFileName icon24(ti.GetIcon24());
			wxFileName icon16(ti.GetIcon16());

			if (size == 24) {
				wxBitmap bmp( m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/24/external-tools/cog") ));
				if (icon24.FileExists()) {
					bmp.LoadFile(icon24.GetFullPath(), wxBITMAP_TYPE_PNG);
					if (bmp.IsOk() == false) {
						bmp = m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/24/external-tools/cog") );
					}
				}
				m_tb->AddTool(wxXmlResource::GetXRCID(ti.GetId().c_str()), ti.GetName(), bmp, ti.GetName());

			} else if (size == 16) {
				wxBitmap bmp(m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/16/external-tools/cog") ));
				if (icon16.FileExists()) {
					bmp.LoadFile(icon16.GetFullPath(), wxBITMAP_TYPE_PNG);
					if (bmp.IsOk() == false) {
						bmp = m_mgr->GetStdIcons()->LoadBitmap(wxT("toolbars/16/external-tools/cog") );
					}
				}

				m_tb->AddTool(wxXmlResource::GetXRCID(ti.GetId().c_str()), ti.GetName(), bmp, ti.GetName());
			}
		}

		m_tb->Realize();
	}

	return m_tb;
}

void ExternalToolsPlugin::CreatePluginMenu(wxMenu *pluginsMenu)
{
	m_parentMenu = pluginsMenu;
	DoCreatePluginMenu();
}

void ExternalToolsPlugin::HookPopupMenu(wxMenu *menu, MenuType type)
{
	wxUnusedVar(menu);
	wxUnusedVar(type);
}

void ExternalToolsPlugin::UnPlug()
{
}

void ExternalToolsPlugin::OnSettings(wxCommandEvent& e)
{
	ExternalToolsData inData;
	m_mgr->GetConfigTool()->ReadObject(wxT("ExternalTools"), &inData);
	ExternalToolDlg dlg(m_mgr->GetTheApp()->GetTopWindow(), m_mgr);
	dlg.SetTools(inData.GetTools());

	if (dlg.ShowModal() == wxID_OK) {
		//Do something here
		ExternalToolsData data;
		data.SetTools(dlg.GetTools());
		m_mgr->GetConfigTool()->WriteObject(wxT("ExternalTools"), &data);

		wxCommandEvent evt(wxEVT_COMMAND_MENU_SELECTED, 34733);
		wxPostEvent(this, evt);
	}
}

void ExternalToolsPlugin::OnRecreateTB(wxCommandEvent &e)
{
	wxUnusedVar(e);
	DoRecreateToolbar();
	DoCreatePluginMenu();
}

void ExternalToolsPlugin::OnLaunchExternalTool(wxCommandEvent& e)
{
	ExternalToolsData inData;
	m_mgr->GetConfigTool()->ReadObject(wxT("ExternalTools"), &inData);

	for (size_t i=0; i<inData.GetTools().size(); i++) {
		ToolInfo ti = inData.GetTools().at(i);
		if (wxXmlResource::GetXRCID(ti.GetId().c_str()) == e.GetId()) {
			DoLaunchTool(ti);
		}
	}
}

void ExternalToolsPlugin::DoLaunchTool(const ToolInfo& ti)
{
	wxString command, working_dir;

	command << wxT("\"") << ti.GetPath() << wxT("\" ") << ti.GetArguments();
	working_dir = ti.GetWd();

	if (m_mgr->IsWorkspaceOpen()) {
		command     = m_mgr->GetMacrosManager()->Expand(command, m_mgr, m_mgr->GetWorkspace()->GetActiveProjectName());
		working_dir = m_mgr->GetMacrosManager()->Expand(working_dir, m_mgr, m_mgr->GetWorkspace()->GetActiveProjectName());
	}

	// check to see if we require to save all files before continuing
	if (ti.GetSaveAllFiles() && !m_mgr->SaveAll())
		return;

	if (ti.GetCaptureOutput() == false) {
		// change the directory to the requested working directory
		DirSaver ds;
		wxSetWorkingDirectory(working_dir);

		// apply environment
		EnvSetter envGuard(m_mgr->GetEnv());
		wxExecute(command);

	} else {
		// create a piped process
		if (m_pipedProcess && m_pipedProcess->IsBusy()) {
			// a process is already running
			return;
		}

		m_pipedProcess = new AsyncExeCmd(m_mgr->GetOutputWindow());

		DirSaver ds;
		EnvSetter envGuard(m_mgr->GetEnv());
		wxSetWorkingDirectory(working_dir);

		// hide console if any,
		// redirect output
		m_pipedProcess->Execute(command, true, true);
		if (m_pipedProcess->GetProcess()) {
			m_pipedProcess->GetProcess()->Connect(wxEVT_END_PROCESS, wxProcessEventHandler(ExternalToolsPlugin::OnProcessEnd), NULL, this);
		}
	}
}

void ExternalToolsPlugin::OnProcessEnd(wxProcessEvent &event)
{
	m_pipedProcess->ProcessEnd(event);
	m_pipedProcess->GetProcess()->Disconnect(wxEVT_END_PROCESS, wxProcessEventHandler(ExternalToolsPlugin::OnProcessEnd), NULL, this);
	delete m_pipedProcess;
	m_pipedProcess = NULL;
}

void ExternalToolsPlugin::DoRecreateToolbar()
{
	wxWindow *parent(NULL);
	if (m_tb) {
		// we have a toolbar, remove it from the docking manager
		m_mgr->GetDockingManager()->DetachPane(m_tb);
		parent = m_tb->GetParent();
		m_tb->Destroy();
	} else {
		parent = m_mgr->GetTheApp()->GetTopWindow();
	}

	m_tb = CreateToolBar(parent);
	if (m_tb) {
		m_mgr->GetDockingManager()->AddPane(m_tb, wxAuiPaneInfo().Name(GetShortName()).LeftDockable( true ).RightDockable( true ).Caption(GetShortName()).ToolbarPane().Top() );

		// Apply changes
		m_mgr->GetDockingManager()->Update();
	}
}

bool ExternalToolsPlugin::IsRedirectedToolRunning()
{
	return (m_pipedProcess && m_pipedProcess->IsBusy());
}

void ExternalToolsPlugin::OnLaunchExternalToolUI(wxUpdateUIEvent& e)
{
	e.Enable(!IsRedirectedToolRunning());
}

void ExternalToolsPlugin::OnStopExternalTool(wxCommandEvent& e)
{
	if (m_pipedProcess) {
		m_pipedProcess->Stop();
	}
}

void ExternalToolsPlugin::OnStopExternalToolUI(wxUpdateUIEvent& e)
{
	e.Enable(this->IsRedirectedToolRunning());
}

void ExternalToolsPlugin::DoCreatePluginMenu()
{
	const int MENU_ID = 28374;
	if ( m_parentMenu ) {
		// destroy the old menu entries
		if ( m_parentMenu->FindItem(MENU_ID) ) {
			m_parentMenu->Destroy(MENU_ID);
		}

		wxMenu *menu = new wxMenu();
		wxMenuItem *item(NULL);
		item = new wxMenuItem(menu, XRCID("external_tools_settings"), _("Configure external tools..."), wxEmptyString, wxITEM_NORMAL);
		menu->Append(item);
		menu->AppendSeparator();

		// Loop and append the tools already defined
		ExternalToolsData inData;
		m_mgr->GetConfigTool()->ReadObject(wxT("ExternalTools"), &inData);

		for (size_t i=0; i<inData.GetTools().size(); i++) {
			ToolInfo ti = inData.GetTools().at(i);
			item = new wxMenuItem(menu, wxXmlResource::GetXRCID(ti.GetId().c_str()), ti.GetName(), wxEmptyString, wxITEM_NORMAL);
			menu->Append(item);
		}

		m_parentMenu->Append(MENU_ID, _("External Tools"), menu);
		topWin->Connect(XRCID("external_tools_settings"), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(ExternalToolsPlugin::OnSettings), NULL, (wxEvtHandler*)this);
	}
}
