
// MFC_FFmpegDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_FFmpeg.h"
#include "MFC_FFmpegDlg.h"
#include "afxdialogex.h"
#include<string>
#include<fstream>
#include<opencv\cv.h>
#include<opencv2\opencv.hpp>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
using namespace cv;

CString  strtemp, strTemp;
CString strFilePath;
string f = "F:\\Recording.txt";
ofstream  filetxt(f, ios::app);
string golabl_folder;
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


// CMFC_FFmpegDlg �Ի���



CMFC_FFmpegDlg::CMFC_FFmpegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_FFMPEG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_FFmpegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, n_edit1);
	DDX_Control(pDX, IDC_EDIT3, n_edit2);
	DDX_Control(pDX, IDC_EDIT2, n_edit3);
	DDX_Control(pDX, IDC_EDIT4, n_edit4);
	DDX_Control(pDX, IDC_EDIT5, n_edit5);
	DDX_Control(pDX, IDC_EDIT6, n_edit6);
	DDX_Control(pDX, IDC_EDIT7, n_edit7);
}

BEGIN_MESSAGE_MAP(CMFC_FFmpegDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_FFmpegDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_FFmpegDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_FFmpegDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_FFmpegDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_FFmpegDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_FFmpegDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_FFmpegDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_FFmpegDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC_FFmpegDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFC_FFmpegDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFC_FFmpegDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CMFC_FFmpegDlg ��Ϣ�������

BOOL CMFC_FFmpegDlg::OnInitDialog()
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
	n_edit4.SetWindowTextW(_T("PI/2"));
	n_edit5.SetWindowTextW(_T("1080"));
	n_edit6.SetWindowTextW(_T("1920"));
	n_edit7.SetWindowTextW(_T("1"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_FFmpegDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_FFmpegDlg::OnPaint()
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
HCURSOR CMFC_FFmpegDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_FFmpegDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("ȫ��|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//����һ���Ի���
	
	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();//����ļ�·��		
	}
}


void CMFC_FFmpegDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	n_edit1.GetWindowText(strTemp);
	n_edit2.GetWindowText(strtemp);
	string starttime= (CW2A(strTemp.GetString()));
	string intervaltime=(CW2A(strtemp.GetString()));
	string strfilesave = CW2A(strFilePath);
	string strfiledeal =  strfilesave + "Out.mp4";
	char output[200];
	string cmdline = "ffmpeg -ss "+starttime+" -t "+intervaltime +" -i "+strfilesave+" -vcodec copy -acodec copy "+ strfiledeal+" ";
	string cmdlines = cmdline;											
	strcpy_s(output, cmdlines.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("ȫ��|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//����һ���Ի���

	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();//����ļ�·��
		string strpath = CW2A(strFilePath);
		filetxt <<"file"<< " '"<<strpath<<"'"<<endl;
	}

}


void CMFC_FFmpegDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char output[200];
	string strfilesave = CW2A(strFilePath);
	string strfiledeal = strfilesave + "Concat.mp4";
	string cmdline = "ffmpeg -f concat -safe 0 -i " + f + " -c copy " +strfiledeal ;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fstream file(f, ios::out);
}


void CMFC_FFmpegDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("ȫ��|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//����һ���Ի���

	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();//����ļ�·��		
	}
}


void CMFC_FFmpegDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	n_edit3.GetWindowText(str);  //��ò���W:H:X:Y
	char output[200];
	string strfilesave = CW2A(strFilePath);
	string strtrans = CW2A(str);
	string strfiledeal = strfilesave + "clips.mp4"; //�õ������Ƶ·��
	string cmdline = "ffmpeg -i " + strfilesave + " -strict -2 -vf crop=" + strtrans+" "+strfiledeal;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("ȫ��|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//����һ���Ի���

	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();//����ļ�·��		
	}
}


void CMFC_FFmpegDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString n_str4, n_str5, n_str6;
	n_edit4.GetWindowText(n_str4);
	n_edit5.GetWindowText(n_str5);
	n_edit6.GetWindowText(n_str6);

	string angle = (CW2A(n_str4.GetString()));
	string widthvideo = (CW2A(n_str5.GetString()));
	string heightvideo = CW2A(n_str6.GetString());
	string strfilesave = CW2A(strFilePath.GetString());
	string strfiledeal = strfilesave + "Rotate.mp4";
	char output[200];
	string cmdline = "ffmpeg -i " + strfilesave + " -vf rotate=" + angle + ":ow=" + widthvideo + ":oh=" + heightvideo + " "+strfiledeal;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("ȫ��|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//����һ���Ի���

	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();//����ļ�·��		
	}
	golabl_folder = CW2A(strFilePath.GetString());
	golabl_folder = golabl_folder + "img";
	string command = "mkdir -p " + golabl_folder;
	char output[100];
	strcpy_s(output, command.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton11()
{
	
	//strFilePath ��Ƶ·��
	string videopath = CW2A(strFilePath.GetString());
	VideoCapture cap(videopath);
	double totalframenumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
	Mat frame;
	bool flags = true;
	long currentFrame = 0;
	cvNamedWindow("�ü�", (720, 920));
	CString frame_interval;
	n_edit7.GetWindowText(frame_interval);
	int n_interval = _ttoi(frame_interval);
	while (flags) {		
		cap.read(frame);
		stringstream str;
		str << currentFrame << ".jpg";
		if (currentFrame % n_interval != 0) {
			continue;
		}
		if (currentFrame % n_interval == 0) {
			imshow("�ü�", frame);
			waitKey(1);
			imwrite(golabl_folder +"\\"+ str.str(), frame);
		}
		if (currentFrame >= totalframenumber) {
			flags = false;
		}
		if (cv::waitKey(30) == VK_ESCAPE) {
			break;
		}
		currentFrame++;
	}
	destroyAllWindows();
}
