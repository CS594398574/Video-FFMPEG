
// MFC_FFmpegDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC_FFmpegDlg 对话框
class CMFC_FFmpegDlg : public CDialogEx
{
// 构造
public:
	CMFC_FFmpegDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_FFMPEG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit n_edit1;
	CEdit n_edit2;
	afx_msg void OnBnClickedButton3();
private:
	CEdit n_edit3;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
private:
	CEdit n_edit4;
	CEdit n_edit5;
	CEdit n_edit6;
public:
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
private:
	CEdit n_edit7;
};
