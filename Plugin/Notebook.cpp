#include "Notebook.h"

wxDEFINE_EVENT(wxEVT_BOOK_PAGE_CHANGING, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_PAGE_CHANGED, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_PAGE_CLOSING, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_PAGE_CLOSED, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_PAGE_CLOSE_BUTTON, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_TAB_DCLICKED, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_NEW_PAGE, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_TAB_CONTEXT_MENU, wxBookCtrlEvent);
wxDEFINE_EVENT(wxEVT_BOOK_FILELIST_BUTTON_CLICKED, clContextMenuEvent);