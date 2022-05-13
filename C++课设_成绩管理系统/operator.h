#pragma once

#include <stdio.h>
#include "GradeManagement.h"

STable stable;
GTable gtable;
CTable ctable;
CouGTable cgtable;

void SetColor(int hex );
void STable::LoadingFile_Stu()
{
	ifstream ifs("stu_info.txt");
	if (!ifs)
	{
		cout << "学生信息文件不存在" << endl;
		return;
	}
	int stuid;
	char ch;
	ifs >> ch;//文件为空时会有一个字符 得先把这个字符读出来
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		return;
	}
	while (!ifs.eof())//文件的最后一行别加换行 不然没读到尾导致最后一行数据读两次
	{
		ifs >> stuid;
		if (Judge(stuid)==false)
		{
			printf("读取到重复数据，请勿重复读取\n");
			return;
		}
		_stu_table[stuid]._id = stuid;
		ifs >> _stu_table[stuid]._name;
		ifs >> _stu_table[stuid]._age;
		ifs >> _stu_table[stuid]._sex;
	}	
	cout << "录入完毕" << endl;
}
void STable::Hand_EnterInfo()
{
	int stuid;
	printf("请输入学号：-> "); cin >> stuid;
	if (Judge(stuid)==false)
	{
		printf("该学生已经存在 此次输入将会覆盖原本信息 是否继续？\n");
		printf("0. 退出 1. 继续\n");
		int op; 
		printf("请输入：-> ");cin >> op;
		if (op == 0)
		{
			return;
		}
	
	}
	Student& input=stable._stu_table[stuid];
	printf("请输入姓名：-> "); cin >> input._name;
	printf("请输入年龄：-> "); cin >> input._age;
	printf("请输入性别：-> "); cin >> input._sex;
	if (input._id < 0||input._name.size() >= 20 || input._age >= 150 || (input._sex != "男" && input._sex != "女"))
	{
		cout << "输入有误,请重新输入" << endl;
		stable._stu_table.erase(stuid);
	}
	else
	{
		printf("录入成功\n");
	}
}
void Input_EnterStuInfo()
{
	int op;	
	printf("1.加载学生信息文件   2.手动录入  0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		if (op == 1)
		{
			stable.LoadingFile_Stu();
		}
		else if (op == 2)
		{
			stable.Hand_EnterInfo();
			 
		}
		else if(op==0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("\n继续录入吗？"); printf("1.加载学生文件   2.手动录入  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}


void CouTable::LoadingFile_Cou()
{
	ifstream ifs("cou_info.txt");
	FILE* pf=fopen("cou_info.txt","r");
	
	if (!ifs)
	{
		cout << "学生信息文件不存在" << endl;
		return;
	}
	int couid;
	char ch;
	ifs >> ch;//文件为空时会有一个字符 得先把这个字符读出来
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		return;
	}
	while (!ifs.eof())//文件的最后一行别加换行 不然没读到尾导致最后一行数据读两次
	{
		ifs >> couid;
		if (Judge(couid) == false)
		{
			printf("读取到重复数据，请勿重复读取\n");
			return;
		}
		_cou_table[couid]._id = couid;
		ifs >> _cou_table[couid]._name;
		ifs >> _cou_table[couid]._credit;
		ch = ' '; string teacher_name;
		while (ch != '\n'&&ch!=EOF)
		{
			ifs >> teacher_name;
			_cou_table[couid]._teacher_name .insert(teacher_name);
			ch = ifs.get();			
		}
	}
	cout << "录入完毕" << endl;
}
void CouTable::Hand_EnterInfo()
{
	int couid;
	printf("请输入课程号：-> "); cin >> couid;
	if (Judge(couid) == false)
	{
		printf("该课程已经存在 此次输入将会覆盖原本信息 是否继续？\n");
		printf("0. 退出 1. 继续\n");
		int op;
		printf("请输入：-> "); cin >> op;
		if (op == 0)
		{
			return;
		}
		
	}
	Course& input = ctable._cou_table[couid];
	input._id = couid;
	printf("请输入课程名：-> "); cin >> input._name;
	printf("请输入学分：-> "); cin >> input._credit;
	printf("您可以输入多位老师的名字，中间用空格间隔即可\n");
	printf("请输入授课老师名字：->");
	string str; getchar();
	getline(cin, str);
	for (int i = 0; i < str.size(); )
	{
		int left = i;
		int right = left + 1;
		while (right < str.size() && str[right] != '\0')
		{
			if (str[right] == ' ')
			{
				 break;
			}
			else
			{
				right++;
			}
		}
		i = right;
		string ans = str.substr(left, right);
		ans += '\0';
		_cou_table[couid]._teacher_name.insert(ans);
	}
	if (input._id<0||input._name.size() >= 20 || input._credit >= 30 )
	{
		cout << "输入有误,请重新输入" << endl;
		ctable._cou_table.erase(couid);
	}
	else
	{
		printf("录入成功\n");
	}
}
void Input_EnterCouInfo()
{
	int op;
	printf("1.加载课程信息文件   2.手动录入  0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		if (op == 1)
		{
			ctable.LoadingFile_Cou();
		}
		else if (op == 2)
		{
			ctable.Hand_EnterInfo();
		}
		else if (op == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("\n继续录入吗？"); printf("1.加载课程信息文件   2.手动录入  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}

void GradeTable::LoadingFile_Grade()
{
	ifstream ifs("stu_grade.txt");
	if (!ifs)
	{
		cout << "成绩单文件不存在" << endl;
		return;
	}
	int stuid;
	char ch;
	ifs >> ch;//文件为空时会有一个字符 得先把这个字符读出来
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		return;
	}
	while (!ifs.eof())//文件的最后一行别加换行 不然没读到尾导致最后一行数据读两次
	{
		ifs >> stuid;
		set<CourseGrade>& PersonGrade = _stu_grade[stuid];
		CourseGrade cousegrade;
		int couid; ifs >> couid; cousegrade._cou_id = couid;
		if (Judge(stuid, couid) == false)
		{
			printf("读取到重复数据，请勿重复读取\n");
			return;
		}
		int grade; ifs >> grade; cousegrade._grade = grade;
		int ts; ifs >> ts; 
		if (ts == 0)
		{
			cousegrade._ts = NotNormal;
			cousegrade._grade = 0;
		}
		else
		{
			cousegrade._ts = Normal;
		}
		PersonGrade.insert(cousegrade);
		cgtable._cou_grade[couid].insert(stuid);
	}
	cout << "录入完毕" << endl;
}
void GradeTable::Hand_EnterGrade()
{
	int op = 1;
	int stuid;
	printf("请输入学号：-> "); cin >> stuid;
	set<CourseGrade>& PersonGrade = _stu_grade[stuid];
	while (op)
	{
		CourseGrade cousegrade;
		printf("请输入课程号：-> "); cin >> cousegrade._cou_id;
		if (Judge(stuid, cousegrade._cou_id)==false)
		{
			printf("该学生成绩已经存在 此次输入将会覆盖原本信息 是否继续？\n");
			printf("0. 退出 1. 继续\n");
			int op;
			printf("请输入：-> "); cin >> op;
			if (op == 0)
			{
				return;
			}
			
		}
		printf("请输入成绩：-> "); cin >> cousegrade._grade;
		printf("请输入考试状态：-> "); int ts; cin >> ts;
		if (ts == 0)
		{
			cousegrade._ts = NotNormal;
			cousegrade._grade = 0;
		}
		else
		{
			cousegrade._ts = Normal;
		}
		if (cousegrade._grade > 100 || (ts != 0 && ts != 1))
		{
			cout << "输入有误,请重新输入" << endl;
		}
		else
		{
			PersonGrade.insert(cousegrade);
			cgtable._cou_grade[cousegrade._cou_id].insert(stuid);
			printf("录入成功\n");
		}
		printf("继续录入此学生的成绩吗？ "); printf("1.继续录入    0.退出\n");
		cin >> op;
	}
	
}
void Input_EnterStuGrade()
{
	int op;
	printf("1.加载学生成绩文件   2.手动录入  0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		if (op == 1)
		{
			gtable.LoadingFile_Grade();
		}
		else if (op == 2)
		{
			gtable.Hand_EnterGrade();
		}
		else if (op == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("\n继续录入吗？"); printf("1.加载学生文件   2.手动录入  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}

ostream& operator<<(ostream& out, const CourseGrade& cou)
{
	Course& course=ctable._cou_table[cou._cou_id];
	out << setw(20)<<course._name<<setw(5) << cou._grade;
	if (cou._ts == Normal)
	{
		out << setw(20) << "考试状态：正常";
	}
	else
	{
		out << setw(20) << "考试状态：不正常";
	}
	out << endl;
	return out;
}
void Output()
{
	int op;
	printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		if (op == 1)
		{
			int couid;
			bool f = 0;
			printf("请输入课程号：-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "课程不存在" << endl;
				printf("\n继续查看吗？"); printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
				printf("请输入:-> "); cin >> op;
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade=gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));
				if (it!=PersonGrade.end())
				{
					f = 1;
					Student& student = stable._stu_table[e];
					cout << setw(10) << student._id << setw(10) << student._name << *it;
					
				}
			}
			if (f == 0)
			{
				cout << "该课程无成绩" << endl;
			}
		}
		else if (op == 2)
		{
			int stuid;
			printf("请输入学号：-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())
			{
				cout << "学生不存在" << endl;
				printf("\n继续查看吗？"); printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
				printf("请输入:-> "); cin >> op;
				continue;
			}
			Student& student = stable._stu_table[stuid];
			set<CourseGrade>& PersonGrade = gtable._stu_grade[stuid];
			for (auto e : PersonGrade)
			{
				cout << setw(10) << student._id << setw(10) << student._name << "   " << e;
			}
		}
		else if (op == 3)
		{
			system("cls");
			SetColor(0x06);
			for (auto e : gtable._stu_grade)
			{
				Student& student = stable._stu_table[e.first];
				cout << left<<setw(10) << student._id << setw(10) << student._name << endl;
				set<CourseGrade>& grade = e.second;
				set<CourseGrade>::iterator it = grade.end(); it--;
				while (it != grade.begin())
				{
					Course& course = ctable._cou_table[it->_cou_id];
					printf("%04d   ", course._id);
					cout << *it << endl;
					it--;
				}
				Course& course = ctable._cou_table[it->_cou_id];
				printf("%04d   ", course._id);
				cout << *it << endl;
				
				/*for (auto e2 : grade)
				{
				//课程号逆序打印
					Course& course = ctable._cou_table[e2._cou_id];
					printf("%04d   ", course._id);
					cout << e2 << endl;
				}*/
			}
		}
		else if (op == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("\n继续查看吗？"); printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}
void Erase()
{
	int op;
	printf("1.删除某门课   2.删除某学生  0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		if (op == 1)
		{
			int couid;
			bool f = 0;
			printf("请输入课程号：-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "课程不存在" << endl;
				printf("\n继续删除吗？"); printf("1.删除某门课   2.删除某学生  0.退出\n");
				printf("请输入:-> "); cin >> op;
				continue;
			}
			ctable._cou_table.erase(couid);
			set<int>& stuid = cgtable._cou_grade[couid];
			for (auto e : stuid)
			{
				set<CourseGrade>& PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));
				if (it != PersonGrade.end())
				{
					PersonGrade.erase(it);
					
				}
			}
			cout << "删除成功" << endl;
		}
		else if (op == 2)
		{
			int stuid;
			printf("请输入学号：-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())
			{
				cout << "学生不存在" << endl;
				printf("\n继续删除吗？"); printf("1.删除某门课   2.删除某学生  0.退出\n");
				printf("请输入:-> "); cin >> op;
				continue;
			}
			gtable._stu_grade.erase(stuid);
			stable._stu_table.erase(stuid);
			cout << "删除成功" << endl;
		}
		else if (op == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("\n继续删除吗？"); printf("1.删除某门课   2.删除某学生  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}
void Update()
{
	int op;
	printf("1.修改某门课   2.修改某学生  0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		if (op == 1)
		{
			
			ctable.Hand_EnterInfo();
			
		}
		else if (op == 2)
		{
			int x;
			printf("1. 修改学生的成绩  2.修改学生的信息  0.退出\n");  cin>> x;
			if (x == 2)
			{
				stable.Hand_EnterInfo();
			}
			else if(x==1)
			{
				gtable.Hand_EnterGrade();
			}
			else
			{
				;
			}
		}
		else if (op == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("\n继续修改吗？"); printf("1.修改某门课   2.修改某学生  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}
bool cmp_grade(const PAIR& e1,const PAIR& e2 )
{
	if (e1.second < e2.second)
	{
		return false;
	}
	else if (e1.second == e2.second)
	{
		if (e1.first < e2.first)
		{
			return false;
		}
	}
}
void Sort()
{
	int op;
	printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分   0.退出\n");
	printf("请输入：-> "); cin >> op;
	while (op)
	{
		map<int, int>id_grade;//id和成绩
		map<int, int>id_status;//学号和这门课的考试状态
		map<int, int>id_total;//学号和总分
		vector<PAIR>v_total(id_total.begin(), id_total.end());//总分
		if (op == 1)
		{
			SetColor(0x0a);
			int couid;
			bool f = 0;
			printf("请输入课程号：-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "课程不存在" << endl;
				printf("\n继续查看吗？"); printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分   0.退出\n");
				printf("请输入:-> "); cin >> op;
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));
				
				if (it != PersonGrade.end())//*it 得到课程的成绩
				{
					f = 1;
					id_grade[e] = it->_grade;
					if (it->_ts == Normal)
					{
						id_status[e] = 1;
					}
					else
					{
						id_status[e] = 0;
					}
					
				}
			}
			if (f == 0)
			{
				cout << "该课程无成绩" << endl;
			}
			else
			{
				vector<PAIR>v_grade(id_grade.begin(), id_grade.end());
				sort(v_grade.begin(), v_grade.end(), cmp_grade);
				for (auto e : v_grade)
				{
					Student& student = stable._stu_table[e.first];//得到学生的信息
					cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e.second;
					if (id_status[e.first] == 1)
					{
						cout << setw(20) << "考试状态：正常" << endl;
					}
					else
					{
						cout << setw(20) << "考试状态：不正常" << endl;
					}
				}
			}
			
		}
		else if (op == 2)
		{
			SetColor(0x03);
			Output();
		}
		else if (op == 3)
		{
			SetColor(0x0b);
			for (auto e1 : gtable._stu_grade)//遍历学号
			{
				int total=0;
				for (auto e2 : e1.second)//遍历成绩
				{
					total += e2._grade;
				}
				id_total[e1.first] = total;
			}
			vector<PAIR>v_total2(id_total.begin(), id_total.end());
			v_total.swap(v_total2);
			sort(v_total.begin(), v_total.end(), cmp_grade);
			for (auto e : v_total)
			{
				Student& student = stable._stu_table[e.first];//得到学生的信息
				cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e.second << endl;
			}
		}
		else if (op == 4)
		{
			SetColor(0x0c);
			int couid;
			bool f = 0;
			printf("请输入课程号：-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "课程不存在" << endl;
				printf("\n继续查看吗？"); printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分   0.退出\n");
				printf("请输入:-> "); cin >> op;
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));
				if (it != PersonGrade.end())//*it 得到课程的成绩
				{
					f = 1;
					id_grade[e] = it->_grade;
					if (it->_ts == Normal)
					{
						id_status[e] = 1;
					}
					else
					{
						id_status[e] = 0;
					}

				}
			}
			if (f == 0)
			{
				cout << "该课程无成绩" << endl;
			}
			else
			{
				vector<PAIR>v_grade(id_grade.begin(), id_grade.end());
				sort(v_grade.begin(), v_grade.end(), cmp_grade);
				auto e = v_grade.begin();
				Student& student = stable._stu_table[e->first];//得到学生的信息
				cout <<setw(20)<<ctable._cou_table[couid]._name;
				cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e->second;
				if (id_status[e->first] == 1)
				{
					cout << setw(20) << "考试状态：正常" << endl;
				}
				else
				{
					cout << setw(20) << "考试状态：不正常" << endl;
				}
				
			}			
		}
		else if (op == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误，退出。" << endl;
			break;
		}
		printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分  0.退出\n");
		printf("请输入:-> "); cin >> op;
	}
}
void SetColor(int hex = 07)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), hex);
}
void menu()
{

	printf("****************************************************\n");
	printf("*                                                  *\n");
	printf("*                   成绩管理系统                   *\n");
	printf("*                                                  *\n");
	printf("*                                                  *\n");
	printf("*                   1.录入学生信息                 *\n");
	printf("*                   2.录入课程信息                 *\n");
	printf("*                   3.录入学生成绩                 *\n");
	printf("*                   4.查看                         *\n");
	printf("*                   5.删除                         *\n");
	printf("*                   6.修改学生成绩                 *\n");
	printf("*                   7.按成绩进行排序               *\n");
	printf("*                   0.退出                         *\n");
	printf("*                                                  *\n");
	printf("****************************************************\n");

	int op;
	printf("请输入： "); cin >> op;
	while (op)
	{
		switch (op)
		{
		case 0:
			break;
		case 1:
			SetColor(0x0a);
			Input_EnterStuInfo();
			break;
		case 2:
			SetColor(0x0b);
			Input_EnterCouInfo();
			break;
		case 3:
			SetColor(0x0c);
			Input_EnterStuGrade();
			break;
		case 4:
			SetColor(0x03);
			Output();
			break;
		case 5:
			SetColor(0x0a);
			Erase();
			break;
		case 6:
			SetColor(0x0b);
			Update();
			break;
		case 7:
			SetColor(0x0c);
			Sort();
			break;
		}
		printf("\n\n");
		system("cls");
		printf("****************************************************\n");
		printf("*                                                  *\n");
		printf("*                   成绩管理系统                   *\n");
		printf("*                                                  *\n");
		printf("*                                                  *\n");
		printf("*                   1.录入学生信息                 *\n");
		printf("*                   2.录入课程信息                 *\n");
		printf("*                   3.录入学生成绩                 *\n");
		printf("*                   4.查看                         *\n");
		printf("*                   5.删除                         *\n");
		printf("*                   6.修改学生成绩                 *\n");
		printf("*                   7.按成绩进行排序               *\n");
		printf("*                   0.退出                         *\n");
		printf("*                                                  *\n");
		printf("****************************************************\n");
		printf("请输入:-> "); cin >> op;
	}



}
