#define _CRT_SECURE_NO_WARNINGS 1

#include "GradeManagement.h"
#include "operator.h"


int main()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.FontWeight = 5000;
	cfi.dwFontSize.Y = 20;
	cfi.dwFontSize.X = 0;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), true, &cfi);

	SetConsoleTitle(LPCTSTR(L"成绩管理系统"));
	InitOption();

	Start();
	return 0;
}