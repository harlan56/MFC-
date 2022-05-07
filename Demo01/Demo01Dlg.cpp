
// Demo01Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo01.h"
#include "Demo01Dlg.h"
#include "afxdialogex.h"
#include "editor1.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

editor1 e1;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemo01Dlg �Ի���



CDemo01Dlg::CDemo01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DEMO01_DIALOG, pParent)
	, m_num1(0)
	, m_num2(0)
	, m_result(0)
	, m_editSpin(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemo01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_number1, m_num1);
	DDX_Text(pDX, IDC_number2, m_num2);
	DDX_Text(pDX, IDC_result, m_result);
	DDX_Control(pDX, IDC_CHECK1, m_checkRed);
	DDX_Control(pDX, IDC_CHECK2, m_checkGreen);
	DDX_Control(pDX, IDC_CHECK3, m_checkBlue);
	DDX_Control(pDX, IDC_BUTTON3, m_radioRectangle);
	DDX_Control(pDX, IDC_myCombox, m_combobox);
	DDX_Control(pDX, IDC_myListCombox, m_listCombobox);
	DDX_Control(pDX, IDC_SPIN_DEC, m_spin);
	DDX_Text(pDX, IDC_EDIT_DEC, m_editSpin);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_myList, m_list);
}

BEGIN_MESSAGE_MAP(CDemo01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_calculate, &CDemo01Dlg::OnBnClickedCalculate)
	ON_BN_CLICKED(IDC_calculate2, &CDemo01Dlg::OnBnClickedCalculate2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDemo01Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDemo01Dlg::OnBnClickedButton4)
	//ON_BN_CLICKED(IDC_CHECK1, &CDemo01Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_calculate3, &CDemo01Dlg::OnBnClickedcalculate3)
	ON_BN_CLICKED(IDC_addButton, &CDemo01Dlg::OnBnClickedaddbutton)
	ON_BN_CLICKED(IDC_deleteButton, &CDemo01Dlg::OnBnClickeddeletebutton)
	ON_BN_CLICKED(IDC_progressStart, &CDemo01Dlg::OnBnClickedprogressstart)
	ON_WM_TIMER()
	ON_COMMAND(ID_createFile, &CDemo01Dlg::OnCreateFile)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_subCopy, &CDemo01Dlg::OnSubCopy)
	ON_COMMAND(ID_subClip, &CDemo01Dlg::OnSubClip)
	ON_COMMAND(ID_subPaste, &CDemo01Dlg::OnSubPaste)
END_MESSAGE_MAP()


// CDemo01Dlg ��Ϣ�������

BOOL CDemo01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	mySpinInit();
	myProgress();
	myListInit();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDemo01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDemo01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDemo01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDemo01Dlg::OnBnClickedCalculate()
{
	int num1, num2, result;
	TCHAR chNum1[12], chNum2[12], chResult[12];
	GetDlgItem(IDC_number1)->GetWindowText(chNum1, 12);
	GetDlgItem(IDC_number2)->GetWindowText(chNum2, 12);
	num1 = _ttoi(chNum1);
	num2 = _ttoi(chNum2);
	result = num1 + num2;
	_itot_s(result, chResult, 12);
	GetDlgItem(IDC_result)->SetWindowText(chResult);
}

void CDemo01Dlg::OnBnClickedCalculate2()
{
	int num1, num2, result;
	num1 = GetDlgItemInt(IDC_number1);
	num2 = GetDlgItemInt(IDC_number2);
	if (num1 < 100||num2<100) {
		AfxMessageBox(L"������>100������");
		return;
	}
	else {
		result = num1 + num2;
		SetDlgItemInt(IDC_result, result);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDemo01Dlg::OnBnClickedButton3()
{
	MessageBox(L"faiaifa");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDemo01Dlg::OnBnClickedButton4()
{
	CString ch;
	GetDlgItemText(IDC_randomInput,ch);
	SetDlgItemText(IDC_randomShow, ch);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void CDemo01Dlg::OnBnClickedcalculate3()
{
	UpdateData(TRUE);
	m_result = m_num1 + m_num2;
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDemo01Dlg::OnBnClickedaddbutton()//���combobox item
{
	CString strTxt;
	GetDlgItemText(IDC_itemInput, strTxt);
	m_combobox.AddString(strTxt);
	m_combobox.SetCurSel(m_combobox.GetCount() - 1);

	m_listCombobox.AddString(strTxt);
	m_listCombobox.SetCurSel(m_listCombobox.GetCount() - 1);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDemo01Dlg::OnBnClickeddeletebutton()
{
	int index;
	index = m_combobox.GetCurSel();
	//printf("%d", index);
	if (index > -1) {
		m_combobox.DeleteString(index);
		if (index < m_combobox.GetCount()) {
			m_combobox.SetCurSel(index);
		}
		else {
			m_combobox.SetCurSel(0);
		}
	}
	else {
		return;
	}
	if (index > -1) {
		m_listCombobox.DeleteString(index);
		if (index < m_listCombobox.GetCount()) {
			m_listCombobox.SetCurSel(index);
		}
		else {
			m_listCombobox.SetCurSel(0);
		}
	}
	else {
		return;
	}
}

void CDemo01Dlg::mySpinInit()
{
	m_spin.SetBuddy(GetDlgItem(IDC_EDIT_DEC));
	m_spin.SetRange(0, 100);
}



void CDemo01Dlg::OnBnClickedprogressstart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1, 100, NULL);
	GetDlgItem(IDC_progressStart)->EnableWindow(FALSE);

}

void CDemo01Dlg::myProgress()
{
	m_progress.SetRange(0, 100);
}


void CDemo01Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int pos;
	pos = m_progress.GetPos();
	pos++;
	if (pos >= 100) {
		KillTimer(1);
		GetDlgItem(IDC_progressStart)->EnableWindow(TRUE);
#if 1
		m_progress.SetPos(0);
#endif
	}
	else {
		;
	}
	m_progress.SetPos(pos);

	CDialogEx::OnTimer(nIDEvent);
}

void CDemo01Dlg::myListInit()
{
	m_list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	m_list.InsertColumn(0, _T("��1��"));
	m_list.InsertColumn(1, _T("��2��"));
}


void CDemo01Dlg::OnCreateFile()
{
	AfxMessageBox(_T("File->New"));
	// TODO: �ڴ���������������
}


void CDemo01Dlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: �ڴ˴������Ϣ����������
	CMenu menu;
	if (!menu.LoadMenu(IDR_rightClickMenu)) {
		return;
	}
	CMenu *pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, pWnd);
}


void CDemo01Dlg::OnSubCopy()
{
	AfxMessageBox(_T("����"));
	// TODO: �ڴ���������������
}


void CDemo01Dlg::OnSubClip()
{
	AfxMessageBox(_T("����"));
	// TODO: �ڴ���������������
}


void CDemo01Dlg::OnSubPaste()
{
	AfxMessageBox(_T("ճ��"));
	// TODO: �ڴ���������������
}
