
// drawPtsView.h: CdrawPtsView 类的接口
//

#pragma once


class CdrawPtsView : public CView
{
protected: // 仅从序列化创建
	CdrawPtsView() noexcept;
	DECLARE_DYNCREATE(CdrawPtsView)

// 特性
public:
	CdrawPtsDoc* GetDocument() const;


// 操作
public:
	bool m_bClickEmpty; //判断是否点击了空白的地方，以实现拖动框选择 

	CPoint OldEmptyBegin;//点击空白开始的座标

	CPoint NowEmptyEnd;//移动时保存座标

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CdrawPtsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	void MDrawRedArc(int x, int y, int mSize);
};

#ifndef _DEBUG  // drawPtsView.cpp 中的调试版本
inline CdrawPtsDoc* CdrawPtsView::GetDocument() const
   { return reinterpret_cast<CdrawPtsDoc*>(m_pDocument); }
#endif

