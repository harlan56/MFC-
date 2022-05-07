#include "stdafx.h"
#include "editor1.h"

#define DOUBLE_EDIT_PROP_NAME _T("Double_Edit_Prop_Name")

editor1::editor1()
{
}


editor1::~editor1()
{
}

BOOL editor1::Attach(HWND hWnd)
{
	if (m_hWnd != NULL) {
		DebugBreak();
		return FALSE;
	}
	m_hWnd = hWnd;
	SetProp(hWnd, DOUBLE_EDIT_PROP_NAME,this);
	m_101dProc = SetWindowLong(hWnd, GWL_WNDPROC, (long)NewEditProc);
	if (m_101dProc == 0) {
		m_101dProc = NULL;
		return FALSE;
	}
	else {
		return TRUE;
	}
}

LRESULT editor1::NewEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	editor1 *pEdit = (editor1*)GetProp(hWnd, DOUBLE_EDIT_PROP_NAME);
	BOOL bCanceled = FALSE;
	if (uMsg == WM_CHAR) { 
		switch (wParam) {
		default:
			if ((wParam > '9' || wParam < '0')) {
				bCanceled = TRUE;
			}
			break;
		}
		if (bCanceled) {
			MessageBeep(-1);
			return 0;
		}
	}
	
	return CallWindowProc((WNDPROC)pEdit->m_101dProc,hWnd,uMsg,wParam,lParam);
}


