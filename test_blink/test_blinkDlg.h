// test_blinkDlg.h : 头文件
//
#include "BlinkControl.h"

#pragma once


// Ctest_blinkDlg 对话框
class Ctest_blinkDlg : public CDialog
{
// 构造
public:
	Ctest_blinkDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST_BLINK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
    virtual void OnOK();
    virtual BOOL PreTranslateMessage(MSG* pMsg);

// 实现
protected:
	HICON m_hIcon;
    CBlinkControl m_blinkControl;
    BOOL m_bBlinking;
    BOOL m_bFilling;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
