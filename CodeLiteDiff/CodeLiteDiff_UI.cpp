//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: CodeLiteDiff_UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "CodeLiteDiff_UI.h"


// Declare the bitmap loading function
extern void wxC847InitBitmapResources();

static bool bBitmapLoaded = false;


NewFileComparisonBase::NewFileComparisonBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC847InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer6 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer6);
    
    wxFlexGridSizer* flexGridSizer23 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer23->SetFlexibleDirection( wxBOTH );
    flexGridSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer23->AddGrowableCol(1);
    
    boxSizer6->Add(flexGridSizer23, 0, wxEXPAND, 5);
    
    m_staticText27 = new wxStaticText(this, wxID_ANY, _("Left File:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer23->Add(m_staticText27, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlLeftFile = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlLeftFile->Enable(false);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlLeftFile->SetHint(wxT(""));
    #endif
    
    flexGridSizer23->Add(m_textCtrlLeftFile, 0, wxALL|wxEXPAND, 5);
    
    flexGridSizer23->Add(0, 0, 1, wxALL, 5);
    
    m_staticText25 = new wxStaticText(this, wxID_ANY, _("Right File:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer23->Add(m_staticText25, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFileName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlFileName->SetFocus();
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFileName->SetHint(wxT(""));
    #endif
    m_textCtrlFileName->AutoCompleteFileNames();
    
    flexGridSizer23->Add(m_textCtrlFileName, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_button22 = new wxButton(this, wxID_ANY, _("..."), wxDefaultPosition, wxSize(-1,-1), wxBU_EXACTFIT);
    m_button22->SetToolTip(_("Choose a file..."));
    
    flexGridSizer23->Add(m_button22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_staticText33 = new wxStaticText(this, wxID_ANY, _("Opened files:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer6->Add(m_staticText33, 0, wxALL|wxALIGN_LEFT, 5);
    
    wxArrayString m_listBox16Arr;
    m_listBox16 = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_listBox16Arr, wxLB_SINGLE);
    
    boxSizer6->Add(m_listBox16, 1, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer8 = new wxStdDialogButtonSizer();
    
    boxSizer6->Add(m_stdBtnSizer8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
    
    m_button10 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button10->SetDefault();
    m_stdBtnSizer8->AddButton(m_button10);
    
    m_button12 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer8->AddButton(m_button12);
    m_stdBtnSizer8->Realize();
    
    SetName(wxT("NewFileComparisonBase"));
    SetMinClientSize(wxSize(500,300));
    SetSize(-1,-1);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_button22->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NewFileComparisonBase::OnBrowse), NULL, this);
    m_listBox16->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(NewFileComparisonBase::OnFileSelected), NULL, this);
    m_button10->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(NewFileComparisonBase::OnOKUI), NULL, this);
    
}

NewFileComparisonBase::~NewFileComparisonBase()
{
    m_button22->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(NewFileComparisonBase::OnBrowse), NULL, this);
    m_listBox16->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(NewFileComparisonBase::OnFileSelected), NULL, this);
    m_button10->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(NewFileComparisonBase::OnOKUI), NULL, this);
    
}
