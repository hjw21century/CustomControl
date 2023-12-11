#pragma once
#include "afxwin.h"

class CBlinkControl :
    public CWnd
{
public:
    CBlinkControl(void);
    			
    void StartBlink();			
    void StopBlink();

    void StartFill();			
    void StopFill();

public:
    ~CBlinkControl(void);

protected:
    void Blinking();
    void Filling();

    afx_msg void OnPaint();
    afx_msg void OnTimer(UINT_PTR nIDEvent);

    int m_status; // 0 ����״̬��1 blinking״̬��2 filling״̬
    int m_blinkingTag;
    int m_fillingProgress;

DECLARE_MESSAGE_MAP()
};
