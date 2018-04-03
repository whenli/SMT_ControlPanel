// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// SMT_ControlPanelView.cpp : implementation of the CSMT_ControlPanelView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SMT_ControlPanel.h"
#endif

#include "SMT_ControlPanelDoc.h"
#include "SMT_ControlPanelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSMT_ControlPanelView

IMPLEMENT_DYNCREATE(CSMT_ControlPanelView, CFormView)

BEGIN_MESSAGE_MAP(CSMT_ControlPanelView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSMT_ControlPanelView construction/destruction

CSMT_ControlPanelView::CSMT_ControlPanelView()
	: CFormView(IDD_SMT_CONTROLPANEL_FORM)
{
	// TODO: add construction code here

}

CSMT_ControlPanelView::~CSMT_ControlPanelView()
{
}

void CSMT_ControlPanelView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CSMT_ControlPanelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSMT_ControlPanelView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CSMT_ControlPanelView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSMT_ControlPanelView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSMT_ControlPanelView diagnostics

#ifdef _DEBUG
void CSMT_ControlPanelView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSMT_ControlPanelView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSMT_ControlPanelDoc* CSMT_ControlPanelView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSMT_ControlPanelDoc)));
	return (CSMT_ControlPanelDoc*)m_pDocument;
}
#endif //_DEBUG


// CSMT_ControlPanelView message handlers
