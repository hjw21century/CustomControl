// test_blinkDlg.h : ͷ�ļ�
//
#include "BlinkControl.h"

#pragma once


// Ctest_blinkDlg �Ի���
class Ctest_blinkDlg : public CDialog
{
// ����
public:
	Ctest_blinkDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST_BLINK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
    virtual void OnOK();
    virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��
protected:
	HICON m_hIcon;
    CBlinkControl m_blinkControl;
    BOOL m_bBlinking;
    BOOL m_bFilling;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
