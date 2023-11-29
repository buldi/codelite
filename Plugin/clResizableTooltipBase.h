//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: clResizableTooltipBase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CODELITE_PLUGIN_CLRESIZABLETOOLTIPBASE_BASE_CLASSES_H
#define _CODELITE_PLUGIN_CLRESIZABLETOOLTIPBASE_BASE_CLASSES_H

#include "clThemedTreeCtrl.h"
#include "wx/frame.h"

#include <wx/artprov.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/minifram.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/treectrl.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/xrc/xmlres.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/toplevel.h>
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

class WXDLLIMPEXP_SDK clResizableTooltipBase : public wxMiniFrame
{
protected:
    clThemedTreeCtrl* m_treeCtrl;

protected:
    virtual void OnItemExpanding(wxTreeEvent& event) { event.Skip(); }
    virtual void OnKeyDown(wxTreeEvent& event) { event.Skip(); }

public:
    clThemedTreeCtrl* GetTreeCtrl() { return m_treeCtrl; }
    clResizableTooltipBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Inspect Variable"),
                           const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300, 200),
                           long style = wxRESIZE_BORDER | wxFRAME_NO_TASKBAR);
    virtual ~clResizableTooltipBase();
};

#endif
