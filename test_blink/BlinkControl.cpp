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
    CPaintDC dc(this); // 设备上下文，用于绘制
    CRect rect;
    GetClientRect(&rect);
    if (m_blinkingTag) {
        // 使用更复杂的绘制逻辑
        // 创建并选择一个笔和画刷
        CPen pen(PS_SOLID, 1, RGB(60, 60, 60));
        CBrush brush(RGB(135, 206, 250)); // 浅蓝色背景
        CPen* pOldPen = dc.SelectObject(&pen);
        CBrush* pOldBrush = dc.SelectObject(&brush);
        // 绘制带边框的矩形
        dc.Rectangle(&rect);
        // 绘制文本
        CString strText = _T("");
        dc.SetBkMode(TRANSPARENT);
        dc.SetTextColor(RGB(255, 255, 255)); // 白色文本
        dc.DrawText(strText, &rect, DT_CENTER | DT_VCENTER |
        DT_SINGLELINE);
        // 恢复旧的笔和画刷
        dc.SelectObject(pOldPen);
        dc.SelectObject(pOldBrush);
    } else {
        // 绘制一个空白区域
        CBrush brush(RGB(240, 240, 240)); // 浅灰色背景
        dc.FillRect(&rect, &brush);
    }
}

void CBlinkControl::Filling()
{
    CPaintDC dc(this);
    CRect rect;
    GetClientRect(&rect);
    
    // 绘制带边框的矩形
    dc.Rectangle(&rect);
    int borderWidth = 1;
    CRect rectInerRegin(rect.left + borderWidth, rect.top + borderWidth, rect.right - borderWidth, rect.bottom - borderWidth);

    CBrush brush(RGB(240, 240, 240)); // 浅灰色背景
    dc.FillRect(&rectInerRegin, &brush);

    // 根据 m_nFillProgress 绘制矩形
    CRect fillRect = rectInerRegin;
    fillRect.right = fillRect.left + (fillRect.Width() * m_fillingProgress / 14);
    dc.FillSolidRect(&fillRect, RGB(135, 206, 250)); // 填充部分
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
    // 恢复到闲置状态
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
    // 恢复到Blinking状态
    m_status = 1;
}
