#include <Windows.h>
#include <tchar.h>
#include "resource.h" 

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hB;
short correctAnswer = NULL; short maxAnswer = 8;
TCHAR str[50];
TCHAR percent[] = TEXT("%");

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, NULL);
		return(TRUE);
	case WM_INITDIALOG:
		hB = GetDlgItem(hWnd, IDC_BUTTON1);
		SendDlgItemMessage(hWnd, IDC_RADIO1, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO2, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO3, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO4, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO5, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_RADIO6, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		SendDlgItemMessage(hWnd, IDC_CHECK2, BM_SETCHECK, WPARAM(BST_UNCHECKED), NULL);
		return(TRUE);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_RADIO1)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO1, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO2)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO2, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO3)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO3, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO4)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO4, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO5)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO5, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_RADIO6)
		{
			SendDlgItemMessage(hWnd, IDC_RADIO6, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_CHECK1)
		{
			SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_CHECK2)
		{
			SendDlgItemMessage(hWnd, IDC_CHECK2, BM_SETCHECK, WPARAM(BST_CHECKED), NULL);
			correctAnswer++;
		}
		else if (LOWORD(wParam) == IDC_CHECK3 || LOWORD(wParam) == IDC_CHECK4)
		{
			correctAnswer--;
		}
		else
		{
			return(TRUE);
		}
		// - - -
		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			correctAnswer = (double(correctAnswer) / maxAnswer) * 100;
			wsprintf(str, TEXT("%d %hs"), correctAnswer, percent);
			MessageBox(hWnd, str, TEXT("Box"), MB_OK);
			EndDialog(hWnd, NULL);
			return(TRUE);
		}
		else
		{
			return(TRUE);
		}
		return(TRUE);
	}
	return(FALSE);
}