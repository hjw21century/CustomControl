// test_blink.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ctest_blinkApp:
// �йش����ʵ�֣������ test_blink.cpp
//

class Ctest_blinkApp : public CWinApp
{
public:
	Ctest_blinkApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ctest_blinkApp theApp;