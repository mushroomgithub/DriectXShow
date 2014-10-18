// TestCaptureClass.h : main header file for the TESTCAPTURECLASS application
//

#if !defined(AFX_TESTCAPTURECLASS_H__0A8A25D9_8F46_4DA5_9151_8651BF06268F__INCLUDED_)
#define AFX_TESTCAPTURECLASS_H__0A8A25D9_8F46_4DA5_9151_8651BF06268F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestCaptureClassApp:
// See TestCaptureClass.cpp for the implementation of this class
//

class CTestCaptureClassApp : public CWinApp
{
public:
	CTestCaptureClassApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCaptureClassApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestCaptureClassApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCAPTURECLASS_H__0A8A25D9_8F46_4DA5_9151_8651BF06268F__INCLUDED_)
