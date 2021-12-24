
// FileAttributesChangerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileAttributesChanger.h"
#include "FileAttributesChangerDlg.h"
#include "afxdialogex.h"

#include <Shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CString FilePath;


TCHAR path[1024];   //The path that user chose it to change Folder attributes


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileAttributesChangerDlg dialog



CFileAttributesChangerDlg::CFileAttributesChangerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILEATTRIBUTESCHANGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileAttributesChangerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit1);
}

BEGIN_MESSAGE_MAP(CFileAttributesChangerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO2, &CFileAttributesChangerDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO4, &CFileAttributesChangerDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDOK, &CFileAttributesChangerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CFileAttributesChangerDlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CFileAttributesChangerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CFileAttributesChangerDlg message handlers

BOOL CFileAttributesChangerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CFont *m_pWelcomeFont = new CFont();
	m_pWelcomeFont->CreateFont(23, 0, 0, 0, 900, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, L"Arial");
	GetDlgItem(IDC_STATIC2)->SetFont(m_pWelcomeFont, TRUE);


	CFont *m_pPathFont = new CFont();
	m_pPathFont->CreateFont(16, 8, 0, 0, 1000, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, L"Arial");
	GetDlgItem(IDC_STATIC1)->SetFont(m_pPathFont, TRUE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileAttributesChangerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFileAttributesChangerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFileAttributesChangerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileAttributesChangerDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
}


void CFileAttributesChangerDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
}


// This is to get the name for the folder that user chose it 
CString FolderName = PathFindFileName(path);

void CFileAttributesChangerDlg::OnBnClickedOk()
{

	CString PathInTheEdit;
	GetDlgItemText(IDC_EDIT1, PathInTheEdit);
	CString FileFolderName = PathFindFileName(PathInTheEdit);

	// TODO: Add your control notification handler code here
	if (FilePath == "" && path[0] == _T('\0'))
	{
		MessageBox(L"There is no any file/folder selected yet", L"Error", MB_OK | MB_ICONEXCLAMATION);
	}
	else
	{
		int chk = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO10);
		if (chk == IDC_RADIO1)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_NORMAL);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO2)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_READONLY);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO3)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_SYSTEM);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO4)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_HIDDEN);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO5)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_VIRTUAL);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO6)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_ARCHIVE);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO7)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_ENCRYPTED);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO8)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_TEMPORARY);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO9)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_OFFLINE);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else if (chk == IDC_RADIO10)
		{
			SetFileAttributes(PathInTheEdit, FILE_ATTRIBUTE_COMPRESSED);

			MessageBox(L"Changing ( " + FileFolderName + " ) attributes done !", L"Done !", MB_OK);
		}
		else
		{
			MessageBox(L"Choose attributes to change !", L"Select", MB_OK | MB_ICONEXCLAMATION);
		}
	}
}


void CFileAttributesChangerDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	TCHAR szFilters[] = _T("All Files (*.*)|*.*||");

	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);

	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	if (fileDlg.DoModal() == IDOK)
	{
		FilePath = fileDlg.GetPathName();

		edit1.SetWindowTextW(FilePath);

		/*path = (LPWSTR)(LPCWSTR)FilePath;*/
	}
}


HBRUSH CFileAttributesChangerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_STATIC1)
	{
		pDC->SetTextColor(RGB(0, 0, 255));
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC2)
	{
		pDC->SetTextColor(RGB(0, 0, 255));
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}

void CFileAttributesChangerDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	BROWSEINFO bi = { 0 };
	bi.lpszTitle = _T("Select Folder");
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	if (pidl != 0)
	{
		// get the name of the folder
		SHGetPathFromIDList(pidl, path);
		edit1.SetWindowText(path);

		// free memory used
		IMalloc * imalloc = 0;
		if (SUCCEEDED(SHGetMalloc(&imalloc)))
		{
			imalloc->Free(pidl);
			imalloc->Release();
		}
	}
}
