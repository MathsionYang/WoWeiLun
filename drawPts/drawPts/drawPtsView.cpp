
// drawPtsView.cpp: CdrawPtsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "drawPts.h"
#endif

#include "drawPtsDoc.h"
#include "drawPtsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdrawPtsView

IMPLEMENT_DYNCREATE(CdrawPtsView, CView)

BEGIN_MESSAGE_MAP(CdrawPtsView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdrawPtsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CdrawPtsView::On32771)
END_MESSAGE_MAP()

// CdrawPtsView 构造/析构

CdrawPtsView::CdrawPtsView() noexcept
{
	// TODO: 在此处添加构造代码

}

CdrawPtsView::~CdrawPtsView()
{
}

BOOL CdrawPtsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CdrawPtsView 绘图

void CdrawPtsView::OnDraw(CDC* /*pDC*/)
{
	CdrawPtsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CdrawPtsView 打印


void CdrawPtsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdrawPtsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CdrawPtsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CdrawPtsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CdrawPtsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdrawPtsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CdrawPtsView 诊断

#ifdef _DEBUG
void CdrawPtsView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawPtsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawPtsDoc* CdrawPtsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawPtsDoc)));
	return (CdrawPtsDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawPtsView 消息处理程序

//绘制点
void CdrawPtsView::On32771()
{
	// TODO: 在此添加命令处理程序代码
	vector<string> V;
	vector<string>::iterator it;
	ifstream infile;
	infile.open("data1.txt");   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	string s;
	while (infile >> s)
	{
		V.push_back(s);
	}
	infile.close();             //关闭文件输入流 
	int sizeNum = V.size();
	double X[200];
	double Y[200];
	int xNum = 0;
	int yNum = 0;
	for (int j = 2; j < sizeNum; j = j + 4)//获取X
	{
		//cout << V[j] << endl;

		stringstream stream(V[j]);
		if (xNum<200)
		{
			stream >> X[xNum];
		}
		xNum++;
	}
	for (int k = 3; k < sizeNum; k = k + 4)//获取Y
	{
	
			stringstream stream(V[k]);
			if (yNum < 200)
			{
				stream >> Y[yNum];
			}
			yNum++;
		
			
	}
	for (int i = 0; i < 200; i++)
	{
		int x;
		int y;
		x = (int)X[i];
		y = (int)Y[i];
		x = x - 34400;
		y = y - 31400;
		MDrawRedArc(x, y, 10);
	}
}




//绘制点
void CdrawPtsView::MDrawRedArc(int x, int y, int mSize)
{
	// TODO: 在此处添加实现代码.
	CClientDC  dc(this);
	CPen pNewPen;
	CPen *pOldPen;
	pNewPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pOldPen = dc.SelectObject(&pNewPen);

	//定义画刷填充圆
	CBrush fillbrush;
	CBrush *oldbrush;
	fillbrush.CreateSolidBrush(RGB(255, 0, 0));
	oldbrush = dc.SelectObject(&fillbrush);

	dc.Ellipse(x, y, x + mSize, y + mSize);

	dc.SelectObject(oldbrush);
	dc.SelectObject(pOldPen);
	fillbrush.DeleteObject();
	pNewPen.DeleteObject();

}
