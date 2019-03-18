
// MFC_FFmpegDlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC_FFmpegDlg 对话框



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
	ON_BN_CLICKED(IDC_BUTTON12, &CMFC_FFmpegDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFC_FFmpegDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDCANCEL, &CMFC_FFmpegDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFC_FFmpegDlg::OnBnClickedButton14)
END_MESSAGE_MAP()


// CMFC_FFmpegDlg 消息处理程序

BOOL CMFC_FFmpegDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	n_edit4.SetWindowTextW(_T("PI/2"));
	n_edit5.SetWindowTextW(_T("1080"));
	n_edit6.SetWindowTextW(_T("1920"));
	n_edit7.SetWindowTextW(_T("1"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_FFmpegDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_FFmpegDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_FFmpegDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("全部|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//弹出一个对话框
	
	if (dlg.DoModal() == IDOK)
	{
		strFilePath = dlg.GetPathName();//获得文件路径		
	}
}


void CMFC_FFmpegDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
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

CString CombinePath;
void CMFC_FFmpegDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("全部|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//弹出一个对话框

	if (dlg.DoModal() == IDOK)
	{
		CombinePath = dlg.GetPathName();//获得文件路径
		string strpath = CW2A(CombinePath);
		filetxt <<"file"<< " '"<<strpath<<"'"<<endl;
	}

}


void CMFC_FFmpegDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	char output[200];
	string strfilesave = CW2A(CombinePath);
	string strfiledeal = strfilesave + "Concat.mp4";
	string cmdline = "ffmpeg -f concat -safe 0 -i " + f + " -c copy " +strfiledeal ;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	fstream file(f, ios::out);
}

CString crop;
void CMFC_FFmpegDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("全部|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//弹出一个对话框

	if (dlg.DoModal() == IDOK)
	{
		crop = dlg.GetPathName();//获得文件路径		
	}
}


void CMFC_FFmpegDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	n_edit3.GetWindowText(str);  //获得参数W:H:X:Y
	char output[200];
	string strfilesave = CW2A(crop);
	string strtrans = CW2A(str);
	string strfiledeal = strfilesave + "clips.mp4"; //得到输出视频路径
	string cmdline = "ffmpeg -i " + strfilesave + " -strict -2 -vf crop=" + strtrans+" "+strfiledeal;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
	
}

CString RotatePath;
void CMFC_FFmpegDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("全部|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//弹出一个对话框

	if (dlg.DoModal() == IDOK)
	{
		RotatePath = dlg.GetPathName();//获得文件路径		
	}
}


void CMFC_FFmpegDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString n_str4, n_str5, n_str6;
	n_edit4.GetWindowText(n_str4);
	n_edit5.GetWindowText(n_str5);
	n_edit6.GetWindowText(n_str6);

	string angle = (CW2A(n_str4.GetString()));
	string widthvideo = (CW2A(n_str5.GetString()));
	string heightvideo = CW2A(n_str6.GetString());
	string strfilesave = CW2A(RotatePath.GetString());
	string strfiledeal = strfilesave + "Rotate.mp4";
	char output[200];
	string cmdline = "ffmpeg -i " + strfilesave + " -vf rotate=" + angle + ":ow=" + widthvideo + ":oh=" + heightvideo + " "+strfiledeal;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
}

CString ClipsPath;
void CMFC_FFmpegDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("全部|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//弹出一个对话框

	if (dlg.DoModal() == IDOK)
	{
		ClipsPath = dlg.GetPathName();//获得文件路径		
	}
	golabl_folder = CW2A(ClipsPath.GetString());
	golabl_folder = golabl_folder + "img";
	string command = "mkdir -p " + golabl_folder;
	char output[100];
	strcpy_s(output, command.c_str());
	system(output);
}


void CMFC_FFmpegDlg::OnBnClickedButton11()
{
	string videopath = CW2A(ClipsPath.GetString());
	VideoCapture cap(videopath);
	double totalframenumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
	Mat frame;
	bool flags = true;
	long currentFrame = 0;
	cvNamedWindow("裁剪", 0);
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
			imshow("裁剪", frame);
			waitKey(1);
			imwrite(golabl_folder +"\\"+ str.str(), frame);
		}
		if (currentFrame >= totalframenumber - 1) {
			flags = false;
		}
		if (cv::waitKey(1) == VK_ESCAPE) {
			break;
		}
		currentFrame++;
	}
	destroyAllWindows();
}

CString singleframe;
string videopathframe;
bool flag = false;
Mat image_show,ROI;
Point pt,cur_pt;
Mat frameread;
int width = 0;
int height = 0;
char temp[16];
char temp1[16];
char temp_width[16];


void mouse_callback(int event, int x, int y, int, void *) {
	switch (event)
{
	case CV_EVENT_LBUTTONDOWN:
		flag = true;
		pt.x = x;
		pt.y = y;
		sprintf(temp, "%d,%d", x, y);		
		break;

	case CV_EVENT_MOUSEMOVE:
		if (flag) {
			image_show.copyTo(frameread);
			rectangle(frameread, pt, Point(x, y), Scalar(255, 0, 0), 2, 8);
		}
		break;

	case CV_EVENT_LBUTTONUP:
		flag = false;
		cur_pt.x = x;
		cur_pt.y = y;
		sprintf(temp1, "%d,%d", x, y);
		rectangle(frameread, pt, Point(x, y), Scalar(255, 0, 0), 2, 8);
		putText(frameread, temp, pt, CV_FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 1, 8);
		putText(frameread, temp1, cur_pt, CV_FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 1, 8);
		width = cur_pt.x - pt.x;
	    height = cur_pt.y - pt.y;
		if (width > 0 && height > 0) {
			sprintf(temp_width, "%d,%d", width, height);
			putText(frameread, temp_width, Point(cur_pt.x - 100, cur_pt.y - 100), CV_FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 1, 8);
			imshow("坐标", frameread);
			ROI = image_show(Rect(pt.x, pt.y, x - pt.x, y - pt.y));
			imshow("ROI", ROI);
		}		
		break;
	default:
		break;
	}	
}

void CMFC_FFmpegDlg::OnBnClickedButton12()
{

		CFileDialog dlg(TRUE, _T("*.BMP|*.JPG"), NULL, NULL, _T("全部|*.mp4;*.MP4;*.avi|*.MP4|*.mp4;*.MP4|*avi|*.avi||"));//弹出一个对话框
		if (dlg.DoModal() == IDOK)
		{
			singleframe = dlg.GetPathName();//获得文件路径		
		}
		else {
			return;
		}
		videopathframe = CW2A(singleframe.GetString());  //得到文件路径
		VideoCapture cap(videopathframe);		
		cap.read(frameread);
		image_show = frameread.clone();
		imshow("坐标",frameread);
		waitKey(1);
		setMouseCallback("坐标", mouse_callback);	
}

void CMFC_FFmpegDlg::OnBnClickedButton13()
{
	
	string savefile = "F:\\videoresort\\save_clip_info.txt";
	std::ofstream file(savefile, std::ios::app);
	file << videopathframe << '\t';
	file << pt.x << '\t';
	file << pt.y << '\t';
	file << width << '\t';
	file << height << '\t';
	file << endl;
	file.close();
}

void CMFC_FFmpegDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
	CDialogEx::OnCancel();
}

vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}






void CMFC_FFmpegDlg::OnBnClickedButton14()
{
	CString str;
	n_edit3.GetWindowText(str);  //获得参数W:H:X:Y
	char output[200];
	
	string strtrans = CW2A(str);
	
	
	string filename = "F:\\videoresort\\save_clip_info.txt";
	ifstream infile(filename.c_str());
	string temp;
	while (getline(infile, temp))
	{
		cout << temp << endl;
		vector<string> v = split(temp, "\t"); //可按多个字符来分隔;
	/*	for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
		cout << endl;*/
		string strfilesave = v[0];
		string x_set =v[1] ;
		string y_set =v[2] ;
		string width_set = v[3];
		string heigth_set = v[4];		
		string strfiledeal = strfilesave + "clips.mp4"; //得到输出视频路径
		string strparm = width_set + ":" + heigth_set + ":" + x_set + ":" + y_set;
		string cmdline = "ffmpeg -i " + strfilesave + " -strict -2 -vf crop=" + strparm + " " + strfiledeal;
	string cmdlines = cmdline;
	strcpy_s(output, cmdlines.c_str());
	system(output);
	}








	
}
