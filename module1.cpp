#include "framework.h"
#include "resource1.h"

static INT_PTR CALLBACK Work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int Func_MOD1(HWND hWnd, HINSTANCE hI) {
	return DialogBox(hI, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}

INT_PTR CALLBACK Work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_NEXT:
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;

        case IDCANCEL:
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}