//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CODELITE_PLUGIN_WXCRAFTER_BASE_CLASSES_H
#define _CODELITE_PLUGIN_WXCRAFTER_BASE_CLASSES_H

// clang-format off
#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stc/stc.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include "clThemedSplitterWindow.h"
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/treectrl.h>
#include "clFileViwerTreeCtrl.h"
#include <wx/dataview.h>
#include "clThemedListCtrl.h"
#include <wx/scrolwin.h>
#include <wx/statbmp.h>
#include "clThemedButton.h"
#include <wx/frame.h>
#include <wx/listbox.h>
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

#include "codelite_exports.h"
// clang-format on

class WXDLLIMPEXP_SDK EditDlgBase : public wxDialog
{
protected:
    wxStyledTextCtrl* m_stc10;
    wxButton* m_button6;
    wxButton* m_button8;

protected:
public:
    wxStyledTextCtrl* GetStc10() { return m_stc10; }
    wxButton* GetButton6() { return m_button6; }
    wxButton* GetButton8() { return m_button8; }
    EditDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Edit Text"),
                const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300, 300),
                long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~EditDlgBase();
};

class WXDLLIMPEXP_SDK DiffSideBySidePanelBase : public wxControl
{
protected:
    clThemedSplitterWindow* m_splitter;
    wxPanel* m_splitterPageLeft;
    wxTextCtrl* m_textCtrlLeftFile;
    wxButton* m_button290;
    wxStyledTextCtrl* m_stcLeft;
    wxPanel* m_panelOverviewL;
    wxStaticText* m_staticTextLeft;
    wxPanel* m_splitterPageRight;
    wxTextCtrl* m_textCtrlRightFile;
    wxButton* m_button294;
    wxStyledTextCtrl* m_stcRight;
    wxPanel* m_panelOverviewR;
    wxStaticText* m_staticTextRight;
    wxPanel* m_panelOverviewFull;

protected:
    virtual void OnLeftPickerUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnBrowseLeftFile(wxCommandEvent& event) { event.Skip(); }
    virtual void OnLeftStcPainted(wxStyledTextEvent& event) { event.Skip(); }
    virtual void OnMouseWheel(wxMouseEvent& event) { event.Skip(); }
    virtual void OnPaneloverviewEraseBackground(wxEraseEvent& event) { event.Skip(); }
    virtual void OnPaneloverviewLeftDown(wxMouseEvent& event) { event.Skip(); }
    virtual void OnRightPickerUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnBrowseRightFile(wxCommandEvent& event) { event.Skip(); }
    virtual void OnRightStcPainted(wxStyledTextEvent& event) { event.Skip(); }

public:
    wxTextCtrl* GetTextCtrlLeftFile() { return m_textCtrlLeftFile; }
    wxButton* GetButton290() { return m_button290; }
    wxStyledTextCtrl* GetStcLeft() { return m_stcLeft; }
    wxPanel* GetPanelOverviewL() { return m_panelOverviewL; }
    wxStaticText* GetStaticTextLeft() { return m_staticTextLeft; }
    wxPanel* GetSplitterPageLeft() { return m_splitterPageLeft; }
    wxTextCtrl* GetTextCtrlRightFile() { return m_textCtrlRightFile; }
    wxButton* GetButton294() { return m_button294; }
    wxStyledTextCtrl* GetStcRight() { return m_stcRight; }
    wxPanel* GetPanelOverviewR() { return m_panelOverviewR; }
    wxStaticText* GetStaticTextRight() { return m_staticTextRight; }
    wxPanel* GetSplitterPageRight() { return m_splitterPageRight; }
    clThemedSplitterWindow* GetSplitter() { return m_splitter; }
    wxPanel* GetPanelOverviewFull() { return m_panelOverviewFull; }
    DiffSideBySidePanelBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                            const wxSize& size = wxSize(-1, -1), long style = wxTAB_TRAVERSAL | wxBORDER_NONE);
    virtual ~DiffSideBySidePanelBase();
};

class WXDLLIMPEXP_SDK clGetTextFromUserBaseDialog : public wxDialog
{
protected:
    wxStaticText* m_staticTextCaption;
    wxTextCtrl* m_textCtrl;
    wxStdDialogButtonSizer* m_stdBtnSizer137;
    wxButton* m_buttonCancel;
    wxButton* m_buttonOK;

protected:
public:
    wxStaticText* GetStaticTextCaption() { return m_staticTextCaption; }
    wxTextCtrl* GetTextCtrl() { return m_textCtrl; }
    clGetTextFromUserBaseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT(""),
                                const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1),
                                long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~clGetTextFromUserBaseDialog();
};

class WXDLLIMPEXP_SDK clTreeCtrlPanelBase : public wxControl
{
protected:
    clFileViewerTreeCtrl* m_treeCtrl;

protected:
    virtual void OnItemExpanding(wxTreeEvent& event) { event.Skip(); }
    virtual void OnItemActivated(wxTreeEvent& event) { event.Skip(); }
    virtual void OnContextMenu(wxTreeEvent& event) { event.Skip(); }

public:
    clFileViewerTreeCtrl* GetTreeCtrl() { return m_treeCtrl; }
    clTreeCtrlPanelBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxSize(-1, -1), long style = wxTAB_TRAVERSAL | wxBORDER_NONE);
    virtual ~clTreeCtrlPanelBase();
};

class NotebookNavigationDlgBase : public wxDialog
{
protected:
    wxPanel* m_panel161;
    clThemedListCtrl* m_dvListCtrl;

protected:
    virtual void OnKeyDown(wxKeyEvent& event) { event.Skip(); }
    virtual void OnKeyUp(wxKeyEvent& event) { event.Skip(); }
    virtual void OnItemActivated(wxDataViewEvent& event) { event.Skip(); }

public:
    clThemedListCtrl* GetDvListCtrl() { return m_dvListCtrl; }
    wxPanel* GetPanel161() { return m_panel161; }
    NotebookNavigationDlgBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select Tab"),
                              const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(400, 200),
                              long style = wxCAPTION | wxRESIZE_BORDER | wxCLOSE_BOX);
    virtual ~NotebookNavigationDlgBase();
};

class clTreeCtrlPanelDefaultPageBase : public wxControl
{
protected:
    wxPanel* m_panel169;
    wxStaticText* m_staticText177;

protected:
    virtual void OnDefaultPageContextMenu(wxContextMenuEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText177() { return m_staticText177; }
    wxPanel* GetPanel169() { return m_panel169; }
    clTreeCtrlPanelDefaultPageBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                                   const wxSize& size = wxSize(500, 300), long style = wxTAB_TRAVERSAL | wxBORDER_NONE);
    virtual ~clTreeCtrlPanelDefaultPageBase();
};

class clSingleChoiceDialogBase : public wxDialog
{
protected:
    clThemedListCtrl* m_dvListCtrl;
    wxStdDialogButtonSizer* m_stdBtnSizer183;
    wxButton* m_button185;
    wxButton* m_button187;

protected:
    virtual void OnActivated(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    clThemedListCtrl* GetDvListCtrl() { return m_dvListCtrl; }
    clSingleChoiceDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT(""),
                             const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(400, 300),
                             long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~clSingleChoiceDialogBase();
};

class WXDLLIMPEXP_SDK clImageViewerBase : public wxPanel
{
protected:
    wxScrolledWindow* m_scrollWin196;
    wxStaticBitmap* m_staticBitmap;

protected:
public:
    wxStaticBitmap* GetStaticBitmap() { return m_staticBitmap; }
    wxScrolledWindow* GetScrollWin196() { return m_scrollWin196; }
    clImageViewerBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxSize(500, 300), long style = wxTAB_TRAVERSAL);
    virtual ~clImageViewerBase();
};

class WXDLLIMPEXP_SDK clEditorBarBase : public wxControl
{
protected:
    clThemedButton* m_buttonScope;
    clThemedButton* m_buttonFilePath;
    clThemedButton* m_buttonBookmarks;
    wxStaticText* m_labelText;

protected:
    virtual void OnButtonScope(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonActions(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButtonBookmarks(wxCommandEvent& event) { event.Skip(); }

public:
    clThemedButton* GetButtonScope() { return m_buttonScope; }
    clThemedButton* GetButtonFilePath() { return m_buttonFilePath; }
    clThemedButton* GetButtonBookmarks() { return m_buttonBookmarks; }
    wxStaticText* GetLabelText() { return m_labelText; }
    clEditorBarBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxSize(-1, -1), long style = wxTAB_TRAVERSAL | wxBORDER_NONE);
    virtual ~clEditorBarBase();
};

class clTableLineEditorBaseDlg : public wxFrame
{
protected:
    wxPanel* m_panel344;
    wxListBox* m_listBoxColumns;
    wxStyledTextCtrl* m_stc;

protected:
    virtual void OnColumnSelected(wxCommandEvent& event) { event.Skip(); }

public:
    wxListBox* GetListBoxColumns() { return m_listBoxColumns; }
    wxStyledTextCtrl* GetStc() { return m_stc; }
    wxPanel* GetPanel344() { return m_panel344; }
    clTableLineEditorBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Text Viewer"),
                             const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1),
                             long style = wxDEFAULT_FRAME_STYLE | wxFRAME_FLOAT_ON_PARENT);
    virtual ~clTableLineEditorBaseDlg();
};

#endif
