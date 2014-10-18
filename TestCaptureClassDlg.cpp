// TestCaptureClassDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestCaptureClass.h"
#include "TestCaptureClassDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCaptureClassDlg dialog

CTestCaptureClassDlg::CTestCaptureClassDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestCaptureClassDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestCaptureClassDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bIsGrab=FALSE;//初始化表示不进行单帧捕获，与类CSampleGrabberCB中定义的全局变量bOneShot初始值一致，这样当我们需要获得单帧图像时，只需要传递TURE就可以了
	m_bIsHasPreview=FALSE;
}

void CTestCaptureClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestCaptureClassDlg)
	DDX_Control(pDX, IDC_VIDEO_WINDOW, m_VideoWindow);
	DDX_Control(pDX, IDC_COMBO_DEVLIST, m_VideoDevList);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_COMBO_AUDIO_DEVLIST, m_AudioDevList);
}

BEGIN_MESSAGE_MAP(CTestCaptureClassDlg, CDialog)
	//{{AFX_MSG_MAP(CTestCaptureClassDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_PREVIEW, OnPreview)
	ON_BN_CLICKED(IDC_CAPTURE, OnCapture)
	ON_BN_CLICKED(IDC_GRABONEFRAME, OnGraboneframe)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_CAMERAPIN_FORMAT, OnCamerapinFormat)
	ON_BN_CLICKED(IDC_CAMERAFILTER_IMAGE, OnCamerafilterImage)
	ON_BN_CLICKED(IDC_INITPREVIEW, OnInitpreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCaptureClassDlg message handlers

BOOL CTestCaptureClassDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	m_cap.EnumVideoDevices(m_VideoDevList.GetSafeHwnd());
	m_VideoDevList.SetCurSel(0);
	m_cap.EnumAudioDevices(m_AudioDevList.GetSafeHwnd());
	m_AudioDevList.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestCaptureClassDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestCaptureClassDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestCaptureClassDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestCaptureClassDlg::OnPreview() 
{
	// TODO: Add your control notification handler code here
	if(!m_bIsHasPreview)
	{
		int DevID=m_VideoDevList.GetCurSel();
		m_cap.Init(DevID,m_VideoWindow.GetSafeHwnd());
		m_bIsHasPreview=TRUE;
	}
	else
		MessageBox("你已经开始预览,如需重新预览,\n\n请选择重新初始化预览!","Preview",MB_ICONWARNING|MB_YESNO);
}

void CTestCaptureClassDlg::OnCapture() 
{
	// TODO: Add your control notification handler code here
	CString strFilters="AVI(*.avi)|*.avi|";
	strFilters+="Rmvb(*.rmvb)|*.rmvb|";
	strFilters+="ALL FILES(*.*)|*.*||";
	CFileDialog dlg(TRUE,".avi",NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,strFilters,this);
	if(IDOK==dlg.DoModal())
	{
		CString strName=dlg.GetPathName();
		m_cap.CaptureImagesToAVI(strName);
	}
}
 
void CTestCaptureClassDlg::OnGraboneframe() 
{
	// TODO: Add your control notification handler code here
	m_bIsGrab=TRUE;
	m_cap.GrabOneFrame(m_bIsGrab);
}

void CTestCaptureClassDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CTestCaptureClassDlg::OnCamerapinFormat() 
{
	// TODO: Add your control notification handler code here
	m_cap.ConfigCameraPin(this->m_hWnd);
}

void CTestCaptureClassDlg::OnCamerafilterImage() 
{
	// TODO: Add your control notification handler code here
	m_cap.ConfigCameraFilter(this->m_hWnd);
}

void CTestCaptureClassDlg::OnInitpreview() //重新初始化预览
{
	// TODO: Add your control notification handler code here
	if(m_bIsHasPreview==TRUE)
	{
		int DevID=m_VideoDevList.GetCurSel();
		HRESULT hr;
		hr=m_cap.ReInit(DevID,m_VideoWindow.GetSafeHwnd());
		if(SUCCEEDED(hr))
		MessageBox("重新初始化预览成功!");
	}	
}
