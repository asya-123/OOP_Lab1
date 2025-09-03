#include "framework.h"
#include "resource2.h"

static INT_PTR CALLBACK Work2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int Func_MOD2(HWND hWnd, HINSTANCE hI) {
    return DialogBox(hI, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Work2);
}

INT_PTR CALLBACK Work2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_BACK:
            EndDialog(hDlg, -1);
            return (INT_PTR)TRUE;

        case IDCANCEL:
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}