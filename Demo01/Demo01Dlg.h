
// Demo01Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDemo01Dlg �Ի���
class CDemo01Dlg : public CDialogEx
{
// ����
public:
	CDemo01Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO01_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCalculate();
	afx_msg void OnBnClickedCalculate2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	//afx_msg void OnBnClickedCheck1();
	int m_num1;
	int m_num2;
	int m_result;
	afx_msg void OnBnClickedcalculate3();
	CButton m_checkRed;
	CButton m_checkGreen;
	CButton m_checkBlue;
	CButton m_radioRectangle;
	afx_msg void OnBnClickedaddbutton();
	CComboBox m_combobox;
	CListBox m_listCombobox;
	afx_msg void OnBnClickeddeletebutton();

	//void myScrollInit();
	void mySpinInit();
	CSpinButtonCtrl m_spin;
	CString m_editSpin;
	CProgressCtrl m_progress;
	afx_msg void OnBnClickedprogressstart();

	void myProgress();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CListCtrl m_list;
	void myListInit();
	afx_msg void OnCreateFile();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnSubCopy();
	afx_msg void OnSubClip();
	afx_msg void OnSubPaste();
};
