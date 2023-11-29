//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"

// Declare the bitmap loading function
extern void wxC3F25InitBitmapResources();

namespace
{
// return the wxBORDER_SIMPLE that matches the current application theme
wxBorder get_border_simple_theme_aware_bit()
{
#if wxVERSION_NUMBER >= 3300 && defined(__WXMSW__)
    return wxSystemSettings::GetAppearance().IsDark() ? wxBORDER_SIMPLE : wxBORDER_STATIC;
#else
    return wxBORDER_DEFAULT;
#endif
} // DoGetBorderSimpleBit
bool bBitmapLoaded = false;
} // namespace

NavBarControlBaseClass::NavBarControlBaseClass(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size,
                                               long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer36 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer36);

    m_splitter =
        new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_LIVE_UPDATE);
    m_splitter->SetSashGravity(0);
    m_splitter->SetMinimumPaneSize(10);

    boxSizer36->Add(m_splitter, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_splitterPage39 =
        new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitter, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    wxBoxSizer* boxSizer42 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage39->SetSizer(boxSizer42);

    wxArrayString m_scopeArr;
    m_scope = new wxChoice(m_splitterPage39, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterPage39, wxSize(-1, -1)),
                           m_scopeArr, 0);

    boxSizer42->Add(m_scope, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_splitterPage41 =
        new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitter, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_splitter->SplitVertically(m_splitterPage39, m_splitterPage41, 200);

    wxBoxSizer* boxSizer43 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage41->SetSizer(boxSizer43);

    wxArrayString m_funcArr;
    m_func = new wxChoice(m_splitterPage41, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitterPage41, wxSize(-1, -1)),
                          m_funcArr, 0);

    boxSizer43->Add(m_func, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("NavBarControlBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    // Connect events
    m_scope->Bind(wxEVT_COMMAND_CHOICE_SELECTED, &NavBarControlBaseClass::OnScope, this);
    m_func->Bind(wxEVT_COMMAND_CHOICE_SELECTED, &NavBarControlBaseClass::OnFunction, this);
}

NavBarControlBaseClass::~NavBarControlBaseClass()
{
    m_scope->Unbind(wxEVT_COMMAND_CHOICE_SELECTED, &NavBarControlBaseClass::OnScope, this);
    m_func->Unbind(wxEVT_COMMAND_CHOICE_SELECTED, &NavBarControlBaseClass::OnFunction, this);
}

NewProjImgList::NewProjImgList()
    : wxImageList(16, 16, false)
    , m_imagesWidth(16)
    , m_imagesHeight(16)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }
}

NewProjImgList::~NewProjImgList() {}

AddFunctionsImplBaseDlg::AddFunctionsImplBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title,
                                                 const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer117 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer117);

    wxBoxSizer* boxSizer129 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer117->Add(boxSizer129, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl = new clThemedListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                        wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer129->Add(m_dvListCtrl, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl->AppendTextColumn(_("Function"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                   wxDATAVIEW_COL_RESIZABLE);
    wxBoxSizer* boxSizer131 = new wxBoxSizer(wxVERTICAL);

    boxSizer129->Add(boxSizer131, 0, wxEXPAND, WXC_FROM_DIP(5));

    m_button133 = new wxButton(this, wxID_ANY, _("Check all"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer131->Add(m_button133, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_button135 =
        new wxButton(this, wxID_ANY, _("Uncheck all"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer131->Add(m_button135, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_filePicker = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*"), wxDefaultPosition,
                                        wxDLG_UNIT(this, wxSize(-1, -1)), wxFLP_DEFAULT_STYLE);
    m_filePicker->SetToolTip(_("The functions will be placed into this file"));

    boxSizer117->Add(m_filePicker, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer119 = new wxBoxSizer(wxHORIZONTAL);

    boxSizer117->Add(boxSizer119, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button121 = new wxButton(this, wxID_OK, _("&OK"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button121->SetDefault();

    boxSizer119->Add(m_button121, 0, wxALL, WXC_FROM_DIP(5));

    m_button123 = new wxButton(this, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    boxSizer119->Add(m_button123, 0, wxALL, WXC_FROM_DIP(5));

    SetName(wxT("AddFunctionsImplBaseDlg"));
    SetMinClientSize(wxSize(500, 300));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    // Connect events
    m_button133->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &AddFunctionsImplBaseDlg::OnCheckAll, this);
    m_button135->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &AddFunctionsImplBaseDlg::OnUncheckAll, this);
    m_button121->Bind(wxEVT_UPDATE_UI, &AddFunctionsImplBaseDlg::OnOKUI, this);
}

AddFunctionsImplBaseDlg::~AddFunctionsImplBaseDlg()
{
    m_button133->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &AddFunctionsImplBaseDlg::OnCheckAll, this);
    m_button135->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &AddFunctionsImplBaseDlg::OnUncheckAll, this);
    m_button121->Unbind(wxEVT_UPDATE_UI, &AddFunctionsImplBaseDlg::OnOKUI, this);
}

WelcomePageBase::WelcomePageBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }
    this->Hide();

    wxBoxSizer* boxSizer149 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer149);

    m_mainPanel =
        new clThemedSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxSP_3D);
    m_mainPanel->SetSashGravity(0.5);
    m_mainPanel->SetMinimumPaneSize(10);

    boxSizer149->Add(m_mainPanel, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_buttonsPage =
        new wxPanel(m_mainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    wxBoxSizer* boxSizer665 = new wxBoxSizer(wxVERTICAL);
    m_buttonsPage->SetSizer(boxSizer665);

    wxFlexGridSizer* flexGridSizer658 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer658->SetFlexibleDirection(wxBOTH);
    flexGridSizer658->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer658->AddGrowableCol(0);
    flexGridSizer658->AddGrowableCol(2);

    boxSizer665->Add(flexGridSizer658, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    flexGridSizer658->Add(0, 0, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    buttons_sizer = new wxGridSizer(0, 2, 0, 0);

    flexGridSizer658->Add(buttons_sizer, 0, wxEXPAND, WXC_FROM_DIP(5));

    flexGridSizer658->Add(0, 0, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_listPage =
        new wxPanel(m_mainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_mainPanel->SplitHorizontally(m_buttonsPage, m_listPage, 0);

    wxBoxSizer* boxSizer666 = new wxBoxSizer(wxVERTICAL);
    m_listPage->SetSizer(boxSizer666);

    m_panelList =
        new wxPanel(m_listPage, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_listPage, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer666->Add(m_panelList, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer668 = new wxBoxSizer(wxVERTICAL);
    m_panelList->SetSizer(boxSizer668);

    m_staticText0 = new wxStaticText(m_panelList, wxID_ANY, _("Recently opened workspaces"), wxDefaultPosition,
                                     wxDLG_UNIT(m_panelList, wxSize(-1, -1)), 0);

    boxSizer668->Add(m_staticText0, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_dvTreeCtrlWorkspaces =
        new clThemedTreeCtrl(m_panelList, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelList, wxSize(-1, 200)),
                             wxTR_DEFAULT_STYLE | get_border_simple_theme_aware_bit());
    m_dvTreeCtrlWorkspaces->SetFocus();

    boxSizer668->Add(m_dvTreeCtrlWorkspaces, 1, wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("WelcomePageBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    // Connect events
    this->Bind(wxEVT_SIZE, &WelcomePageBase::OnSize, this);
    m_dvTreeCtrlWorkspaces->Bind(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, &WelcomePageBase::OnWorkspaceActivated, this);
}

WelcomePageBase::~WelcomePageBase()
{
    this->Unbind(wxEVT_SIZE, &WelcomePageBase::OnSize, this);
    m_dvTreeCtrlWorkspaces->Unbind(wxEVT_COMMAND_TREE_ITEM_ACTIVATED, &WelcomePageBase::OnWorkspaceActivated, this);
}

WorkspaceTabBase::WorkspaceTabBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }
    this->Hide();

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    m_simpleBook = new wxSimplebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBORDER_NONE);
    m_simpleBook->SetName(wxT("m_simpleBook"));
    m_simpleBook->SetEffect(wxSHOW_EFFECT_NONE);

    mainSizer->Add(m_simpleBook, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_panelCxx = new wxPanel(m_simpleBook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_simpleBook, wxSize(200, 200)),
                             wxTAB_TRAVERSAL);
    m_simpleBook->AddPage(m_panelCxx, _("C++ Workspace"), true);

    wxBoxSizer* boxSizer505 = new wxBoxSizer(wxVERTICAL);
    m_panelCxx->SetSizer(boxSizer505);

    m_panel625 = new wxPanel(m_panelCxx, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panelCxx, wxSize(-1, -1)),
                             wxTAB_TRAVERSAL | wxBORDER_NONE);

    boxSizer505->Add(m_panel625, 0, wxEXPAND, WXC_FROM_DIP(2));

    wxBoxSizer* boxSizer627 = new wxBoxSizer(wxVERTICAL);
    m_panel625->SetSizer(boxSizer627);

    m_toolbar580 = new clToolBar(m_panel625, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel625, wxSize(-1, -1)),
                                 wxTB_NODIVIDER | wxTB_FLAT);
    m_toolbar580->SetToolBitmapSize(wxSize(16, 16));

    boxSizer627->Add(m_toolbar580, 0, wxEXPAND, WXC_FROM_DIP(2));

    m_configChangeCtrl = new clConfigurationSelectionCtrl(m_panel625, wxID_ANY, wxDefaultPosition,
                                                          wxDLG_UNIT(m_panel625, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer627->Add(m_configChangeCtrl, 0, wxEXPAND, WXC_FROM_DIP(2));

    m_splitter = new clThemedSplitterWindow(m_panelCxx, wxID_ANY, wxDefaultPosition,
                                            wxDLG_UNIT(m_panelCxx, wxSize(-1, -1)), wxSP_LIVE_UPDATE);
    m_splitter->SetSashGravity(0);
    m_splitter->SetMinimumPaneSize(10);

    boxSizer505->Add(m_splitter, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_splitterPagePinnedProjects =
        new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitter, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    wxBoxSizer* boxSizer621 = new wxBoxSizer(wxVERTICAL);
    m_splitterPagePinnedProjects->SetSizer(boxSizer621);

    m_dvListCtrlPinnedProjects = new clThemedListCtrl(m_splitterPagePinnedProjects, wxID_ANY, wxDefaultPosition,
                                                      wxDLG_UNIT(m_splitterPagePinnedProjects, wxSize(-1, 150)),
                                                      wxDV_NO_HEADER | wxDV_ROW_LINES | wxDV_SINGLE | wxBORDER_NONE |
                                                          get_border_simple_theme_aware_bit());

    boxSizer621->Add(m_dvListCtrlPinnedProjects, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrlPinnedProjects->AppendTextColumn(_("Project"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                                 wxDATAVIEW_COL_RESIZABLE);
    m_splitterPageTreeView =
        new wxPanel(m_splitter, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_splitter, wxSize(-1, -1)), wxTAB_TRAVERSAL);
    m_splitter->SplitHorizontally(m_splitterPagePinnedProjects, m_splitterPageTreeView, 100);

    wxBoxSizer* boxSizer619 = new wxBoxSizer(wxVERTICAL);
    m_splitterPageTreeView->SetSizer(boxSizer619);

    m_fileView = new FileViewTree(m_splitterPageTreeView, wxID_ANY, wxDefaultPosition,
                                  wxDLG_UNIT(m_splitterPageTreeView, wxSize(-1, -1)),
                                  wxTR_MULTIPLE | wxTR_NO_LINES | wxTR_HAS_BUTTONS);

    boxSizer619->Add(m_fileView, 1, wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("WorkspaceTabBase"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    // Connect events
    m_dvListCtrlPinnedProjects->Bind(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU,
                                     &WorkspaceTabBase::OnPinnedCxxProjectContextMenu, this);
    m_dvListCtrlPinnedProjects->Bind(wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED,
                                     &WorkspaceTabBase::OnPinnedCxxProjectSelected, this);
}

WorkspaceTabBase::~WorkspaceTabBase()
{
    m_dvListCtrlPinnedProjects->Unbind(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU,
                                       &WorkspaceTabBase::OnPinnedCxxProjectContextMenu, this);
    m_dvListCtrlPinnedProjects->Unbind(wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED,
                                       &WorkspaceTabBase::OnPinnedCxxProjectSelected, this);
}

EditorFrameBase::EditorFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                 const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainSizer);

    m_mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    mainSizer->Add(m_mainPanel, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer324 = new wxBoxSizer(wxVERTICAL);
    m_mainPanel->SetSizer(boxSizer324);

    m_toolbar = new clToolBar(m_mainPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_mainPanel, wxSize(-1, -1)),
                              wxTB_NOALIGN | wxTB_FLAT);
    m_toolbar->SetToolBitmapSize(wxSize(24, 24));

    boxSizer324->Add(m_toolbar, 0, wxEXPAND, WXC_FROM_DIP(5));

    m_menuBar587 = new wxMenuBar(0);
    this->SetMenuBar(m_menuBar587);

    FILE = new wxMenu();
    m_menuBar587->Append(FILE, _("File"));

    m_menuItemSave = new wxMenuItem(FILE, XRCID("file-save"), _("Save\tCtrl-S"), wxT(""), wxITEM_NORMAL);
    FILE->Append(m_menuItemSave);

    m_menuItemReload = new wxMenuItem(FILE, XRCID("reload_file"), _("Reload File\tCtrl-R"), wxT(""), wxITEM_NORMAL);
    FILE->Append(m_menuItemReload);

    FILE->AppendSeparator();

    m_menuItemClose = new wxMenuItem(FILE, XRCID("file-close"), _("Close\tCtrl-W"), wxT(""), wxITEM_NORMAL);
    FILE->Append(m_menuItemClose);

    EDIT = new wxMenu();
    m_menuBar587->Append(EDIT, _("Edit"));

    m_menuItemFind = new wxMenuItem(EDIT, XRCID("show-find-bar"), _("Find\tCtrl-F"), wxT(""), wxITEM_NORMAL);
    EDIT->Append(m_menuItemFind);

    m_menuItemUndo = new wxMenuItem(EDIT, wxID_UNDO, _("Undo"), wxT(""), wxITEM_NORMAL);
    EDIT->Append(m_menuItemUndo);

    m_menuItemRedo = new wxMenuItem(EDIT, wxID_REDO, _("Redo"), wxT(""), wxITEM_NORMAL);
    EDIT->Append(m_menuItemRedo);

    SetName(wxT("EditorFrameBase"));
    SetMinClientSize(wxSize(800, 600));
    SetSize(wxDLG_UNIT(this, wxSize(800, 600)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
    // Connect events
    this->Bind(wxEVT_CLOSE_WINDOW, &EditorFrameBase::OnCloseWindow, this);
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnSave, this, m_menuItemSave->GetId());
    this->Bind(wxEVT_UPDATE_UI, &EditorFrameBase::OnSaveUI, this, m_menuItemSave->GetId());
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnReload, this, m_menuItemReload->GetId());
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnClose, this, m_menuItemClose->GetId());
    this->Bind(wxEVT_UPDATE_UI, &EditorFrameBase::OnCloseUI, this, m_menuItemClose->GetId());
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnFind, this, m_menuItemFind->GetId());
    this->Bind(wxEVT_UPDATE_UI, &EditorFrameBase::OnFindUI, this, m_menuItemFind->GetId());
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnUndo, this, m_menuItemUndo->GetId());
    this->Bind(wxEVT_UPDATE_UI, &EditorFrameBase::OnUndoUI, this, m_menuItemUndo->GetId());
    this->Bind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnRedo, this, m_menuItemRedo->GetId());
    this->Bind(wxEVT_UPDATE_UI, &EditorFrameBase::OnRedoUI, this, m_menuItemRedo->GetId());
}

EditorFrameBase::~EditorFrameBase()
{
    this->Unbind(wxEVT_CLOSE_WINDOW, &EditorFrameBase::OnCloseWindow, this);
    this->Unbind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnSave, this, m_menuItemSave->GetId());
    this->Unbind(wxEVT_UPDATE_UI, &EditorFrameBase::OnSaveUI, this, m_menuItemSave->GetId());
    this->Unbind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnReload, this, m_menuItemReload->GetId());
    this->Unbind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnClose, this, m_menuItemClose->GetId());
    this->Unbind(wxEVT_UPDATE_UI, &EditorFrameBase::OnCloseUI, this, m_menuItemClose->GetId());
    this->Unbind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnFind, this, m_menuItemFind->GetId());
    this->Unbind(wxEVT_UPDATE_UI, &EditorFrameBase::OnFindUI, this, m_menuItemFind->GetId());
    this->Unbind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnUndo, this, m_menuItemUndo->GetId());
    this->Unbind(wxEVT_UPDATE_UI, &EditorFrameBase::OnUndoUI, this, m_menuItemUndo->GetId());
    this->Unbind(wxEVT_COMMAND_MENU_SELECTED, &EditorFrameBase::OnRedo, this, m_menuItemRedo->GetId());
    this->Unbind(wxEVT_UPDATE_UI, &EditorFrameBase::OnRedoUI, this, m_menuItemRedo->GetId());
}

OpenFolderDlgBase::OpenFolderDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                     const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer471 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer471);

    wxFlexGridSizer* flexGridSizer483 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer483->SetFlexibleDirection(wxBOTH);
    flexGridSizer483->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);
    flexGridSizer483->AddGrowableCol(1);

    boxSizer471->Add(flexGridSizer483, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText479 =
        new wxStaticText(this, wxID_ANY, _("Goto Folder:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);

    flexGridSizer483->Add(m_staticText479, 0, wxALL | wxALIGN_CENTER_VERTICAL, WXC_FROM_DIP(5));

    m_textCtrlFolder = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(400, -1)), 0);
    m_textCtrlFolder->SetFocus();
#if wxVERSION_NUMBER >= 3000
    m_textCtrlFolder->SetHint(_("Type the folder path"));
#endif
    m_textCtrlFolder->AutoCompleteDirectories();

    flexGridSizer483->Add(m_textCtrlFolder, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer473 = new wxStdDialogButtonSizer();

    boxSizer471->Add(m_stdBtnSizer473, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button475 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button475->SetDefault();
    m_stdBtnSizer473->AddButton(m_button475);

    m_button477 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer473->AddButton(m_button477);
    m_stdBtnSizer473->Realize();

    SetName(wxT("OpenFolderDlgBase"));
    SetMinClientSize(wxSize(-1, 100));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
}

OpenFolderDlgBase::~OpenFolderDlgBase() {}

DefaultWorkspacePageBase::DefaultWorkspacePageBase(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                                                   const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer515 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer515);

    boxSizer515->Add(0, 0, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_staticText523 = new wxStaticText(this, wxID_ANY, _("DRAG AND DROP\nA FOLDER HERE"), wxDefaultPosition,
                                       wxDLG_UNIT(this, wxSize(-1, -1)), wxALIGN_CENTRE);
    wxFont m_staticText523Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText523Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText523->SetFont(m_staticText523Font);

    boxSizer515->Add(m_staticText523, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_staticBitmap521 = new wxStaticBitmap(this, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("target-200")),
                                           wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_staticBitmap521->Hide();

    boxSizer515->Add(m_staticBitmap521, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    boxSizer515->Add(0, 0, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("DefaultWorkspacePageBase"));
    SetMinClientSize(wxSize(400, 300));
    SetSize(wxDLG_UNIT(this, wxSize(400, 300)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
}

DefaultWorkspacePageBase::~DefaultWorkspacePageBase() {}

SelectDropTargetBaseDlg::SelectDropTargetBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title,
                                                 const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC3F25InitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer527 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer527);

    m_banner = new wxBannerWindow(this, wxID_ANY, wxTOP, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_banner->SetBitmap(wxNullBitmap);
    m_banner->SetText(_("Select View"), _("Choose the view to use for this folder from the list below"));
    m_banner->SetGradient(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION),
                          wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    m_banner->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_CAPTIONTEXT));

    boxSizer527->Add(m_banner, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(400, 200)),
                                          wxDV_NO_HEADER | wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer527->Add(m_dvListCtrl, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl->AppendTextColumn(_("View"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(400), wxALIGN_LEFT,
                                   wxDATAVIEW_COL_RESIZABLE);
    m_stdBtnSizer543 = new wxStdDialogButtonSizer();

    boxSizer527->Add(m_stdBtnSizer543, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_button545 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer543->AddButton(m_button545);

    m_button547 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_button547->SetDefault();
    m_stdBtnSizer543->AddButton(m_button547);
    m_stdBtnSizer543->Realize();

    SetName(wxT("SelectDropTargetBaseDlg"));
    SetMinClientSize(wxSize(400, 400));
    SetSize(wxDLG_UNIT(this, wxSize(400, 400)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
    // Connect events
    m_dvListCtrl->Bind(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, &SelectDropTargetBaseDlg::OnSelectionActivated, this);
    m_button547->Bind(wxEVT_UPDATE_UI, &SelectDropTargetBaseDlg::OnOKUI, this);
    m_button547->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &SelectDropTargetBaseDlg::OnOK, this);
}

SelectDropTargetBaseDlg::~SelectDropTargetBaseDlg()
{
    m_dvListCtrl->Unbind(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, &SelectDropTargetBaseDlg::OnSelectionActivated, this);
    m_button547->Unbind(wxEVT_UPDATE_UI, &SelectDropTargetBaseDlg::OnOKUI, this);
    m_button547->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &SelectDropTargetBaseDlg::OnOK, this);
}
