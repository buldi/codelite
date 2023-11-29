//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxcrafter.h"

// Declare the bitmap loading function
extern void wxC682BInitBitmapResources();

static bool bBitmapLoaded = false;

OutlineTabBaseClass::OutlineTabBaseClass(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size,
                                         long style)
    : wxPanel(parent, id, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC682BInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);

    m_dvListCtrl = new clTerminalViewCtrl(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)),
                                          wxDV_NO_HEADER | wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer1->Add(m_dvListCtrl, 1, wxEXPAND, WXC_FROM_DIP(5));

    SetName(wxT("OutlineTabBaseClass"));
    SetSize(wxDLG_UNIT(this, wxSize(-1, -1)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    // Connect events
    m_dvListCtrl->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                          wxDataViewEventHandler(OutlineTabBaseClass::OnItemSelected), NULL, this);
}

OutlineTabBaseClass::~OutlineTabBaseClass()
{
    m_dvListCtrl->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                             wxDataViewEventHandler(OutlineTabBaseClass::OnItemSelected), NULL, this);
}
