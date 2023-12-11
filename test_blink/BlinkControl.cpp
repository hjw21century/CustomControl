#include "StdAfx.h"
#include "BlinkControl.h"

CBlinkControl::CBlinkControl(void)
{
}

CBlinkControl::~CBlinkControl(void)
{
}

BEGIN_MESSAGE_MAP(CBlinkControl, CWnd)
ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()

void CBlinkControl::Blinking()
{
    CPaintDC dc(this); // �豸�����ģ����ڻ���
    CRect rect;
    GetClientRect(&rect);
    if (m_blinkingTag) {
        // ʹ�ø����ӵĻ����߼�
        // ������ѡ��һ���ʺͻ�ˢ
        CPen pen(PS_SOLID, 1, RGB(60, 60, 60));
        CBrush brush(RGB(135, 206, 250)); // ǳ��ɫ����
        CPen* pOldPen = dc.SelectObject(&pen);
        CBrush* pOldBrush = dc.SelectObject(&brush);
        // ���ƴ��߿�ľ���
        dc.Rectangle(&rect);
        // �����ı�
        CString strText = _T("");
        dc.SetBkMode(TRANSPARENT);
        dc.SetTextColor(RGB(255, 255, 255)); // ��ɫ�ı�
        dc.DrawText(strText, &rect, DT_CENTER | DT_VCENTER |
        DT_SINGLELINE);
        // �ָ��ɵıʺͻ�ˢ
        dc.SelectObject(pOldPen);
        dc.SelectObject(pOldBrush);
    } else {
        // ����һ���հ�����
        CBrush brush(RGB(240, 240, 240)); // ǳ��ɫ����
        dc.FillRect(&rect, &brush);
    }
}

void CBlinkControl::Filling()
{
    CPaintDC dc(this);
    CRect rect;
    GetClientRect(&rect);
    
    // ���ƴ��߿�ľ���
    dc.Rectangle(&rect);
    int borderWidth = 1;
    CRect rectInerRegin(rect.left + borderWidth, rect.top + borderWidth, rect.right - borderWidth, rect.bottom - borderWidth);

    CBrush brush(RGB(240, 240, 240)); // ǳ��ɫ����
    dc.FillRect(&rectInerRegin, &brush);

    // ���� m_nFillProgress ���ƾ���
    CRect fillRect = rectInerRegin;
    fillRect.right = fillRect.left + (fillRect.Width() * m_fillingProgress / 14);
    dc.FillSolidRect(&fillRect, RGB(135, 206, 250)); // ��䲿��
}

void CBlinkControl::OnPaint()
{
    if (m_status == 0) {
    } else if (m_status == 1) {
        Blinking();
    } else if (m_status == 2) {
        Filling();
    }
}

void CBlinkControl::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == 1) {
        m_blinkingTag = !m_blinkingTag;
    } else if (nIDEvent == 2) {
        m_fillingProgress++;
        if (m_fillingProgress == 14) {
            KillTimer(2);
        }
    }
    Invalidate();

    CWnd::OnTimer(nIDEvent);
}

void CBlinkControl::StartBlink()
{
    m_status = 1;
    m_blinkingTag = 0;
    SetTimer(1, 500, NULL);
}

void CBlinkControl::StopBlink()
{
    KillTimer(1);
    Invalidate();
    // �ָ�������״̬
    m_status = 0;
}

void CBlinkControl::StartFill()
{
    m_status = 2;
    m_fillingProgress = 0;
    SetTimer(2, 500, NULL);
}

void CBlinkControl::StopFill()
{
    KillTimer(2);
    Invalidate();
    // �ָ���Blinking״̬
    m_status = 1;
}
