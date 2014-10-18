// TestCaptureClassDlg.h : header file
//

#if !defined(AFX_TESTCAPTURECLASSDLG_H__7EA87302_5612_4EA9_939D_92A0BDE52C71__INCLUDED_)
#define AFX_TESTCAPTURECLASSDLG_H__7EA87302_5612_4EA9_939D_92A0BDE52C71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestCaptureClassDlg dialog
#include "CaptureVideo.h"
#include "afxwin.h"
class CTestCaptureClassDlg : public CDialog
{
// Construction
public:
	CTestCaptureClassDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestCaptureClassDlg)
	enum { IDD = IDD_TESTCAPTURECLASS_DIALOG };
	CStatic	m_VideoWindow;
	CComboBox	m_VideoDevList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCaptureClassDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestCaptureClassDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPreview();
	afx_msg void OnCapture();
	afx_msg void OnGraboneframe();
	afx_msg void OnExit();
	afx_msg void OnCamerapinFormat();
	afx_msg void OnCamerafilterImage();
	afx_msg void OnInitpreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CCaptureVideo m_cap;
	BOOL m_bIsGrab;
	BOOL m_bIsHasPreview;
	CComboBox m_AudioDevList;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCAPTURECLASSDLG_H__7EA87302_5612_4EA9_939D_92A0BDE52C71__INCLUDED_)
