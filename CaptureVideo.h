// CCaptureVideo视频捕捉类头文件
/////////////////////////////////////////////////////////////////////
#if !defined(AFX_CAPTUREVIDEO_H__F5345AA4_A39F_4B07_B843_3D87C4287AA0__INCLUDED_)
#define AFX_CAPTUREVIDEO_H__F5345AA4_A39F_4B07_B843_3D87C4287AA0__INCLUDED_
/////////////////////////////////////////////////////////////////////
// CaptureVideo.h : header file
/////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <atlbase.h>
#include <windows.h>
#include <qedit.h>
#include <dshow.h>
#ifndef SAFE_RELEASE
#define SAFE_RELEASE( x )if ( NULL != x ){x->Release();x = NULL;}//定义宏SAFE_RELEASE，便于资源的释放和回收
#endif
class CSampleGrabberCB;//对CSampleGrabberCB类的前导引用声明，将要在之后定义，实际定义位置在源文件中
class CCaptureVideo : public CWnd 
{
	friend class CSampleGrabberCB;//将CSampleGrabberCB声明为CCaptureVideo类的友元类，
								//这样类CSampleGrabberCB类中的所有函数都是类CCaptureVideo的友元函数，可以访问本类的私有成员
public:
	void GrabOneFrame(BOOL bGrab);//获得单帧图像
	void ConfigCameraPin(HWND hParent);//配置摄像头的视频格式
	void ConfigCameraFilter(HWND hParent);//配置摄像头单帧图像的图像参数
	HRESULT Init(int iDeviceID,HWND hWnd);//完成一系列初始化工作，如建立滤波图表及管理器，以及滤波器的连接，视频窗口的显示，设备的枚举
	HRESULT ReInit(int iDeviceID, HWND hWnd);
	int EnumVideoDevices(HWND hVideoList);//枚举视频系统设备名到一个组合框中
	int EnumAudioDevices(HWND hAudioList);//枚举音频设备到一个组合框中
	CCaptureVideo();
	virtual ~CCaptureVideo();
	HRESULT	CaptureImagesToAVI(CString inFileName);//捕获保存视频
private:
	IBaseFilter *pMux;//捕获视频为AVI文件

	HWND m_hWnd;
	IGraphBuilder *m_pGB;
	ICaptureGraphBuilder2* m_pCapture;
	IBaseFilter* m_pBF;
	//IBaseFilter *m_pABF;
	IMediaControl* m_pMC;
	IVideoWindow* m_pVW;
	ISampleGrabber* m_pGrabber;
protected:
	void FreeMediaType(AM_MEDIA_TYPE& mt);
	bool BindFilter(int deviceId, IBaseFilter **pFilter);//将选定的指定的设备绑定到一个滤波器上
	void ResizeVideoWindow();
	HRESULT SetupVideoWindow();
	HRESULT InitCaptureGraphBuilder();//初始化构造出滤波图表和管理器
};
#endif // !defined(AFX_CAPTUREVIDEO_H__F5345AA4_A39F_4B07_B843_3D87C4287AA0__INCLUDED_)
