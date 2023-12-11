// test_blinkDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test_blink.h"
#include "test_blinkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Ctest_blinkDlg 对话框




Ctest_blinkDlg::Ctest_blinkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Ctest_blinkDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    m_bBlinking = FALSE;
    m_bFilling = FALSE;
}

void Ctest_blinkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STATIC_BLINK, m_blinkControl);  
}

void Ctest_blinkDlg::OnOK()
{
    return;
}

BEGIN_MESSAGE_MAP(Ctest_blinkDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// Ctest_blinkDlg 消息处理程序

BOOL Ctest_blinkDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest_blinkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest_blinkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

BOOL Ctest_blinkDlg::PreTranslateMessage(MSG* pMsg)
{
   if(pMsg->message == WM_KEYDOWN)  
   {
      if(pMsg->wParam == VK_SPACE)
      {
            if (m_bBlinking) {
                m_blinkControl.StopBlink();
            } else {
                m_blinkControl.StartBlink();
            }
            m_bBlinking = !m_bBlinking;
            return TRUE;
      }
      else if(pMsg->wParam == VK_RETURN)
      {
            if (m_bFilling) {
                m_blinkControl.StopFill();
            } else {
                m_blinkControl.StartFill();
            }
            m_bFilling = !m_bFilling;
            return TRUE;
      }
   }

   return CDialog::PreTranslateMessage(pMsg);  
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR Ctest_blinkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

