
// MFC_FFmpeg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_FFmpegApp: 
// �йش����ʵ�֣������ MFC_FFmpeg.cpp
//

class CMFC_FFmpegApp : public CWinApp
{
public:
	CMFC_FFmpegApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_FFmpegApp theApp;