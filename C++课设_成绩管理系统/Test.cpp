#define _CRT_SECURE_NO_WARNINGS 1

#include "GradeManagement.h"
#include "operator.h"


void SetSize(int col=120, int line=40)
{
	char ans[64];
	sprintf(ans, "mode con cols=%d lines=%d", col, line);
	system(ans);
}
void ShowStyle()
{
	
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = 5000;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, &cfi);
	SetConsoleTitle(LPCTSTR(L"�ɼ�����ϵͳ"));
	//system("color F1");
	SetColor(0x0a | 0x0b);

	cout << "���Ƿ��Ĳ�������" << endl;
}

int main()
{
	//ShowStyle();//����������ܺ�SetColor��SetSizeһ���� ԭ��δ֪
	
	SetSize();
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.FontWeight = 5000;
	cfi.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, &cfi);
	SetColor(0x0C);
	SetConsoleTitle(LPCTSTR(L"�ɼ�����ϵͳ"));
	

	menu();


	return 0;
}


int main1_test()
{

	//cout << A << endl;
	////printf("2456789\b\b\b");

	char c;
	while ((c = _getch()) != '\r')
	{
		if (c == '\b')
		{
			printf("\b \b");
		}
		else
		{
			printf("*");
		}
		
		//putchar(c);
	}


	/*float f = 0;
	printf("%f\n", f);*/

	/*string s = "123456";
	size_t sz = s.size();
	s += "789";
	string ans;
	ans += s.substr(sz);
	cout << ans<<endl;*/

	/*_wsystem(L"color 0a");
	_wsystem(L"color 0b");
	printf("hello world\n");
	printf("hello world\n");*/

	//system("color 07");

	/*for (int i = 1; i < 1000; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		cout << " " << i << "  ccl is a good man!" << endl;
	}*/

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a | 0x0b);//���ɫ
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xa0 | 0xb0);//a��ʾ����

	//CONSOLE_FONT_INFOEX cfi;
	//cfi.cbSize = sizeof cfi;
	//cfi.nFont = 0;
	//cfi.dwFontSize.X = 0;
	//cfi.dwFontSize.Y = 20;
	//cfi.FontFamily = FF_DONTCARE;
	//cfi.FontWeight = 5000;
	//wcscpy(cfi.FaceName,(WCHAR*)("����"));
	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),true,&cfi);
	//SetConsoleTitle(LPCTSTR(L"�ɼ�����ϵͳ"));
	//cout << "  ccl is a good man!" << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	//cout << "  ccl is a good man!" << endl;
	return 0;
}









