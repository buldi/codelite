//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CODELITE_DOCKER_UI_BASE_CLASSES_H
#define _CODELITE_DOCKER_UI_BASE_CLASSES_H

// clang-format off
#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include "Notebook.h"
#include <wx/imaglist.h>
#include <wx/stc/stc.h>
#include <wx/toolbar.h>
#include "clToolBar.h"
#include <wx/dataview.h>
#include "clThemedListCtrl.h"
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

// clang-format on

class NewDockerWorkspaceDlgBase : public wxDialog
{
protected:
    wxStaticText* m_staticText16;
    wxTextCtrl* m_textCtrlName;
    wxStaticText* m_workspacePath;
    wxDirPickerCtrl* m_dirPicker14;
    wxStdDialogButtonSizer* m_stdBtnSizer4;
    wxButton* m_button6;
    wxButton* m_button8;

protected:
    virtual void OnOkUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText16() { return m_staticText16; }
    wxTextCtrl* GetTextCtrlName() { return m_textCtrlName; }
    wxStaticText* GetWorkspacePath() { return m_workspacePath; }
    wxDirPickerCtrl* GetDirPicker14() { return m_dirPicker14; }
    NewDockerWorkspaceDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY,
                              const wxString& title = _("New Docker Workspace"), const wxPoint& pos = wxDefaultPosition,
                              const wxSize& size = wxSize(-1, -1),
                              long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~NewDockerWorkspaceDlgBase();
};

class DockerSettingsBaseDlg : public wxDialog
{
protected:
    wxStaticText* m_staticText32;
    wxFilePickerCtrl* m_filePickerDocker;
    wxStaticText* m_staticText36;
    wxFilePickerCtrl* m_filePickerDockerCompose;
    wxStdDialogButtonSizer* m_stdBtnSizer24;
    wxButton* m_button26;
    wxButton* m_button28;

protected:
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText32() { return m_staticText32; }
    wxFilePickerCtrl* GetFilePickerDocker() { return m_filePickerDocker; }
    wxStaticText* GetStaticText36() { return m_staticText36; }
    wxFilePickerCtrl* GetFilePickerDockerCompose() { return m_filePickerDockerCompose; }
    DockerSettingsBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Docker Settings"),
                          const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1),
                          long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DockerSettingsBaseDlg();
};

class DockerfileSettingsDlgBase : public wxDialog
{
protected:
    wxPanel* m_panel114;
    Notebook* m_notebook96;
    wxPanel* m_panel98;
    wxStaticText* m_staticText106;
    wxStyledTextCtrl* m_stcBuild;
    wxPanel* m_panel100;
    wxStaticText* m_staticText110;
    wxStyledTextCtrl* m_stcRun;
    wxStdDialogButtonSizer* m_stdBtnSizer44;
    wxButton* m_button46;
    wxButton* m_button48;

protected:
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText106() { return m_staticText106; }
    wxStyledTextCtrl* GetStcBuild() { return m_stcBuild; }
    wxPanel* GetPanel98() { return m_panel98; }
    wxStaticText* GetStaticText110() { return m_staticText110; }
    wxStyledTextCtrl* GetStcRun() { return m_stcRun; }
    wxPanel* GetPanel100() { return m_panel100; }
    Notebook* GetNotebook96() { return m_notebook96; }
    wxPanel* GetPanel114() { return m_panel114; }
    DockerfileSettingsDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY,
                              const wxString& title = _("Dockerfile Settings"), const wxPoint& pos = wxDefaultPosition,
                              const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~DockerfileSettingsDlgBase();
};

class DockerOutputPaneBase : public wxPanel
{
protected:
    Notebook* m_notebook;
    wxPanel* m_outputPage;
    clToolBar* m_toolbar;
    wxStyledTextCtrl* m_stc;
    wxPanel* m_containersPage;
    clToolBar* m_toolbarContainers;
    clThemedListCtrl* m_dvListCtrlContainers;
    wxPanel* m_imagesPage;
    clToolBar* m_toolbarImages;
    clThemedListCtrl* m_dvListCtrlImages;

protected:
    virtual void OnContainerContextMenu(wxDataViewEvent& event) { event.Skip(); }

public:
    clToolBar* GetToolbar() { return m_toolbar; }
    wxStyledTextCtrl* GetStc() { return m_stc; }
    wxPanel* GetOutputPage() { return m_outputPage; }
    clToolBar* GetToolbarContainers() { return m_toolbarContainers; }
    clThemedListCtrl* GetDvListCtrlContainers() { return m_dvListCtrlContainers; }
    wxPanel* GetContainersPage() { return m_containersPage; }
    clToolBar* GetToolbarImages() { return m_toolbarImages; }
    clThemedListCtrl* GetDvListCtrlImages() { return m_dvListCtrlImages; }
    wxPanel* GetImagesPage() { return m_imagesPage; }
    Notebook* GetNotebook() { return m_notebook; }
    DockerOutputPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                         const wxSize& size = wxSize(500, 300), long style = wxTAB_TRAVERSAL);
    virtual ~DockerOutputPaneBase();
};

#endif
