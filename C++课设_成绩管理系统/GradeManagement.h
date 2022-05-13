#pragma once



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>
#include <algorithm>
#include <corecrt_wstring.h>
#include <conio.h>
#include <assert.h>
#include <iomanip>
#include <set>
#include <fstream>
#include <vector>
#include <unordered_set>//排序不好搞 底层是哈希
using namespace std;


enum TestStatus//考试状态
{
	NotNormal,
	Normal
};
struct CourseGrade
{
	friend void Output();
	CourseGrade(){}
	CourseGrade(int couid)
		:_cou_id(couid)
	{}
	int _cou_id;
	int _grade;
	TestStatus _ts;
	//这里必须重载小于
	bool operator<(const CourseGrade& course_grade) const
	{
		if (course_grade._cou_id < _cou_id)
		{
			return true;
		}
		return false;		
	}
	bool operator==(const int& couid) const
	{
		if (couid == _cou_id)
		{
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& out, const CourseGrade& cou);
};


struct Student
{
	friend void Output();
	int _id;//默认学号八位 对非法输入进行处理
	size_t _age = 0;
	string _sex = "男";
	string _name = "张三";
	bool operator<(const Student& stu)
	{
		if (_id < stu._id)
		{
			return true;
		}
		return false;
	}
};
struct Course
{
	friend void Output();
	int _id;
	string _name;
	size_t _credit;
	set<string> _teacher_name;
};
//typedef CourseGrade CouGrd;//一门课的成绩
//typedef set<CouGrd> OneStuGradeTable;//一个学生所有的课程成绩
//typedef OneStuGradeTable OSGT;
//typedef long long ll;
//OSGT stu_grd_table;//学生所有课程的成绩
set<int>stu_id;//学号集合

class StuTable//学生信息表
{
public:
	friend void Erase();
	friend void Update();
	friend void Sort();
	friend void Output();
	void LoadingFile_Stu();
	void Hand_EnterInfo();
private:
	map<int, Student> _stu_table;//学号与学生信息对应
	bool Judge(int stuid)//学号存在返回false 不存在返回true
	{
		pair<map<int, Student>::iterator, bool>judge = _stu_table.insert(make_pair(stuid, Student()));
		return judge.second;
	}
};

class CouTable//课程信息表
{
public:
	friend ostream& operator<<(ostream& out, const CourseGrade& cou);
	friend void Erase();
	friend void Update();
	friend void Sort();
	friend void Output();
	void LoadingFile_Cou();
	void Hand_EnterInfo();
private:
	map<int, Course> _cou_table;//课程号和课程
	bool Judge(int couid)
	{
		pair<map<int, Course>::iterator, bool>judge = _cou_table.insert(make_pair(couid, Course()));
		return judge.second;
	}
};
class GradeTable
{
public:
	friend void Erase();
	friend void Output();
	friend void Update();
	friend void Sort();
	void LoadingFile_Grade();
	void Hand_EnterGrade();
	//这里就是输出成绩单  对成绩进行排序等操作 找出成绩最好的成绩等
private:
	map<int, set<CourseGrade>> _stu_grade;//学号--成绩  关联学号和自己的成绩  成绩单
	bool Judge(int stuid,int couid)//课程成绩已经存在返回false 不存在返回true
	{
		set<CourseGrade>& PersonGrade = _stu_grade[stuid];
		for (auto e : PersonGrade)
		{
			if (e._cou_id == couid)
			{
				return false;
			}
		}
		return true;
		
	}
};

class CouseGradeTable//对课程成绩单进行操作 
{
public:
	friend void Erase();
	friend void Output();
	friend void Update();
	friend void Sort();
	friend void GradeTable::LoadingFile_Grade();
	friend void GradeTable::Hand_EnterGrade();
private:
	map<int, set<int>>_cou_grade;//课程号--学号集合  课程成绩单要成绩从成绩单里去拿
};

typedef StuTable STable;//学生表
typedef CouTable CTable;//课程表
typedef GradeTable GTable;//成绩单
typedef CouseGradeTable CouGTable;//课程成绩单
typedef pair<int, int> PAIR;






