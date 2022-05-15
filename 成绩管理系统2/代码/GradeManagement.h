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
#include <sstream>
#include <typeinfo>
#include <vector>
#include <unordered_set>//���򲻺ø� �ײ��ǹ�ϣ
using namespace std;


enum TestStatus//����״̬
{
	NotNormal,
	Normal
};
struct CourseGrade
{
	friend class GradeTable;
	friend void Output();
	CourseGrade(){}
	CourseGrade(int couid)
		:_cou_id(couid)
	{}
	int _cou_id;
	int _grade;
	TestStatus _ts;
	//�����������С��
	bool operator<(const CourseGrade& course_grade) const
	{
		if (course_grade._cou_id < _cou_id)
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
	int _id;//Ĭ��ѧ�Ű�λ �ԷǷ�������д���
	size_t _age = 0;
	string _sex = "��";
	string _name = "����";
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
	double _credit;
	set<string> _teacher_name;
};


class StuTable//ѧ����Ϣ��
{
public:
	friend void Erase();
	friend void Update();
	friend void Sort();
	friend void Output();
	friend class GradeTable;
	void LoadingFile_Stu();
	void Hand_EnterInfo();
private:
	map<int, Student> _stu_table;//ѧ����ѧ����Ϣ��Ӧ
	bool Judge(int stuid)//ѧ�Ŵ��ڷ���false �����ڷ���true
	{
		pair<map<int, Student>::iterator, bool>judge = _stu_table.insert(make_pair(stuid, Student()));
		return judge.second;
	}
};

class CouTable//�γ���Ϣ��
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
	map<int, Course> _cou_table;//�γ̺źͿγ�
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
	//�����������ɼ���  �Գɼ���������Ȳ��� �ҳ��ɼ���õĳɼ���
private:
	map<int, set<CourseGrade>> _stu_grade;//ѧ��--�ɼ�  ����ѧ�ź��Լ��ĳɼ�  �ɼ���
	bool Judge(int stuid,int couid)//�γ̳ɼ��Ѿ����ڷ���false �����ڷ���true
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

class CouseGradeTable//�Կγ̳ɼ������в��� 
{
public:
	friend void Erase();
	friend void Output();
	friend void Update();
	friend void Sort();
	friend void GradeTable::LoadingFile_Grade();
	friend void GradeTable::Hand_EnterGrade();
private:
	map<int, set<int>>_cou_grade;//�γ̺�--ѧ�ż���  �γ̳ɼ���Ҫ�ɼ��ӳɼ�����ȥ��

};

typedef pair<int, int> PAIR;






