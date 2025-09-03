#include "framework.h"
#include "resource3.h"


static INT_PTR CALLBACK Work3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int Func_MOD3(HWND hWnd, HINSTANCE hI) {
    return DialogBox(hI, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, Work3);
}

INT_PTR CALLBACK Work3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-41");
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-42");
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-43");
        SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)L"IM-44");
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK:
            int indx;
            indx = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
            //SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, indx, (LPARAM)user_choice);

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