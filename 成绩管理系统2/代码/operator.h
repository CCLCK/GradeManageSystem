#pragma once

#include <stdio.h>
#include "GradeManagement.h"

StuTable stable;
GradeTable gtable;
CouTable ctable;
CouseGradeTable cgtable;


#define _OP_SITUATION op = InputOp(op, optional, sop);\
switch (op)\
{\
case -1:\
	PrintError();\
	return;\
case 0:\
	return;\
case 1:\
	break;\
}	


#define MENU printf("****************************************************\n");\
printf("*                                                  *\n");\
printf("*                   成绩管理系统                   *\n");\
printf("*                                                  *\n");\
printf("*                                                  *\n");\
printf("*                   1.录入学生信息                 *\n");\
printf("*                   2.录入课程信息                 *\n");\
printf("*                   3.录入学生成绩                 *\n");\
printf("*                   4.查看                         *\n");\
printf("*                   5.删除                         *\n");\
printf("*                   6.修改                         *\n");\
printf("*                   7.按成绩进行排序               *\n");\
printf("*                   8.自动录入信息                 *\n");\
printf("*                   0.退出                         *\n");\
printf("*                                                  *\n");\
printf("****************************************************\n");

#define _AGAIN_LOGIN cout << endl;\
system("color 0c"); system("cls");\
printf("\n\n自动登录失败,请重新输入\n");\
printf("****************************\n\n");\
printf("1.手动登录 2.自动登录 0. 退出\n\n");\
printf("****************************\n");\
printf("请输入：-> ");\
_OP_SITUATION \
system("cls");

#define _CHECK_STU_NAME(name)  if (name.size() <= 0 || name.size() > 50) {PrintError();stable._stu_table.erase(stuid); return;} \
for (auto e : name)\
{\
	if (e >= '0' && e <= '9') {PrintError();stable._stu_table.erase(stuid);return;}\
}//规定学生姓名中不能有数字且名字不能过长
#define  _CHECK_STU_ID(id) if (id < 10000000 || id>99999999) {PrintError();stable._stu_table.erase(stuid); return;}//规定学号必须是8位
#define  _CHECK_AGE(age) if (age < 0 || age >= 200) {PrintError();stable._stu_table.erase(stuid); return;}//规定学生年龄在0-200之间
#define _CHECK_SEX(sex) if (sex != "男" && sex != "女") {PrintError();stable._stu_table.erase(stuid); return;}//规定性别只有男女

#define _CHECK_COURSE_NAME(name)  if (name.size() <= 0 || name.size() > 50) {PrintError();ctable._cou_table.erase(couid); return;} \
for (auto e : name)\
{\
	if (e >= '0' && e <= '9') {PrintError();ctable._cou_table.erase(couid); return;}\
}//规定老师姓名中不能有数字且名字不能过长
#define _CHECK_COURSE_ID(id) if(id<0||id>10000)  {PrintError();ctable._cou_table.erase(couid); return;}//规定学号在1-1000之间
#define _CHECK_COURSE_NAME(name)  if (name.size() <= 0 || name.size() > 50||(name[0]>='0'&&name[0]<='9'))\
{PrintError(); ctable._cou_table.erase(couid); return;} //规定课程名字不能太长且第一个字符不能是数字

#define _CHECK_CREDIT(credit)  if(credit<0||credit>30) {PrintError();  ctable._cou_table.erase(couid); return;}//规定学分在0-30之间

#define _GIVE_TEST_STATIS(ts)  if (ts == 0)\
{\
	cousegrade._ts = NotNormal;\
	cousegrade._grade = 0;\
}\
else\
{\
	cousegrade._ts = Normal;\
}//根据输入的ts给考试一个状态（ts为0表示考试状态不正常，如作弊缺考等,ts为1表示考试状态正常）

vector<int>op_01;
vector<int>op_012;
vector<int>op_04;
vector<int>op_05;
vector<int>op_09;
void InitOption()//初始化op_xx数组
{
	for (int i = 0; i <= 1; i++)
	{
		op_01.push_back(i);
	}
	for (int i = 0; i <= 2; i++)
	{
		op_012.push_back(i);
	}
	for (int i = 0; i < 4; i++)
	{
		op_04.push_back(i);
	}
	for (int i = 0; i < 5; i++)
	{
		op_05.push_back(i);
	}
	for (int i = 0; i < 9; i++)
	{
		op_09.push_back(i);
	}
}
void SetColor(int hex );
bool CheckOp(int& op,set<int>&sop )//检查sop里是否存在op
{
	if (sop.find(op)!=sop.end())
	{
		return true;
	}
	return false;
}
void InitSetOp(vector<int>& optional, int n, set<int>& sop)//用optional的值初始化sop
{
	for (int i = 0; i < n; i++)
	{
		sop.insert(optional[i]);
	}
}
int InputOp(int& op,vector<int>& optional, set<int>& sop)
{
	InitSetOp(optional,optional.size() , sop);
	cin >> op; 
	if (cin.bad())
	{
		SetColor(0x04);
		cout << "IO流出现未知错误" << endl;
		return -1;
	}
	else if (cin.fail())
	{
		SetColor(0x04);
		cout << "缓冲区出现脏/残留数据,致使输入错误" << endl;//简单来说cin没有读到数据
		cin.clear();
		cin.ignore(INT_MAX,'\n');		
		return -1;
	}
	else if(CheckOp(op, sop))
	{
		char ch = getchar();				
		if (ch == '\n' || ch == ' ')//看后面有无多余的数据 处理如6vybuij的数据
		{
			return op;
		}
		else
		{
			return -1;
		}
		/*string str;//若要提取非法数据可以用这种办法（前提是有非法数据）
		getline(cin, str);
		if (str.empty())
		{
			return op;
		}*/	
	}
	else
	{
		cin.ignore(INT_MAX, '\n');
		return -1;
	}
	
}
void PrintError()
{
	SetColor(0x04);
	printf("\n\n输入有误,退出当前界面\n\n");
	Sleep(1200);
}

void StuTable::LoadingFile_Stu()
{
	ifstream ifs("stu_info.txt");
	if (!ifs)
	{
		cout << "学生信息文件不存在" << endl;
		return;
	}
	int stuid;
	char ch;
	ifs >> ch;//文件为空时会有一个字符 得先把这个字符读出来  (文件打开是初始化状态，读到EOF系统才会把文件状态更改为文件尾
	//eof()是根据文件状态来判断文件是否为空  所以得先尝试读取一个字符改变其状态
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
			//printf("读取到重复数据，请勿重复读取\n");
			//return;
			_stu_table.erase(stuid);//有的话就删掉再插入实现覆盖
		}
		_stu_table[stuid]._id = stuid;
		ifs >> _stu_table[stuid]._name;
		ifs >> _stu_table[stuid]._age;
		ifs >> _stu_table[stuid]._sex;
	}	
	cout << "学生信息录入完毕" << endl;
}
void StuTable::Hand_EnterInfo()
{
	ofstream ofs("stu_info.txt",ios_base::app);
	int stuid;
	printf("请输入学号：-> "); 
	cin >> stuid;	 
	if (Judge(stuid)==false)
	{
		printf("该学生已经存在 此次输入将会覆盖原本信息 是否继续？\n");
		printf("0. 退出 1. 继续\n");
		int op; 
		printf("请输入：-> ");
		vector<int>optional(op_01);
		set<int>sop;
		_OP_SITUATION
	}
	stable._stu_table.erase(stuid);
	Student& input = stable._stu_table[stuid];		_CHECK_STU_ID(stuid)
		input._id = stuid;
	printf("请输入姓名：-> "); cin >> input._name;	_CHECK_STU_NAME(input._name)  
	printf("请输入年龄：-> "); cin >> input._age;		_CHECK_AGE(input._age) 
	printf("请输入性别：-> "); cin >> input._sex;		_CHECK_SEX(input._sex)
		ofs << '\n' << '\n' << stuid;
	ofs << " " << input._name; 
	ofs << " " << input._age;	
	ofs << " " << input._sex;
	printf("录入成功\n");
	
}
void Input_EnterStuInfo()
{
	int op;	
	printf("1.加载学生信息文件   2.手动录入  0.退出\n");
	printf("请输入：-> "); 
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
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
		printf("请输入:-> "); 
		_OP_SITUATION
	}
}

void CouTable::LoadingFile_Cou()
{
	ifstream ifs("cou_info.txt");
	FILE* pf=fopen("cou_info.txt","r");
	
	if (!ifs)
	{
		cout << "课程信息文件不存在" << endl;
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
			/*printf("读取到重复数据，请勿重复读取\n");
			return;*/
			_cou_table.erase(couid);//有的话就删掉再插入实现覆盖
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
	cout << "课程信息录入完毕" << endl;
}
void CouTable::Hand_EnterInfo()
{
	ofstream ofs("cou_info.txt", ios_base::app);//追加
	int couid;
	printf("请输入课程号：-> "); cin >> couid;	
	if (Judge(couid) == false)
	{
		printf("该课程已经存在 此次输入将会覆盖原本信息 是否继续？\n");
		printf("0. 退出 1. 继续\n");
		int op;
		printf("请输入：-> ");
		vector<int>optional(op_01);
		set<int>sop;
		_OP_SITUATION
	}
	ctable._cou_table.erase(couid);
	Course& input = ctable._cou_table[couid]; _CHECK_COURSE_ID(couid)
	input._id = couid;
	printf("请输入课程名：-> "); cin >> input._name;	_CHECK_COURSE_NAME(input._name)
	printf("请输入学分：-> "); cin >> input._credit;	_CHECK_CREDIT(input._credit)
	printf("您可以输入多位老师的名字，中间用空格间隔即可\n");
	printf("请输入授课老师名字：->");
	string str; getchar();
	getline(cin, str);  _CHECK_COURSE_NAME(str)
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
	ofs << "\n\n" <<setw(4)<<setfill('0')<< couid << ' ' << input._name << ' ' << input._credit << ' ' << str;
	printf("录入成功\n");
	
}
void Input_EnterCouInfo()
{
	int op;
	printf("1.加载课程信息文件   2.手动录入  0.退出\n");
	printf("请输入：-> "); 
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
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
		printf("请输入:-> "); _OP_SITUATION
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
		set<CourseGrade>& PersonGrade = _stu_grade[stuid];//这个学生的个人成绩
		CourseGrade cousegrade;
		int couid; ifs >> couid; cousegrade._cou_id = couid;
		if (Judge(stuid, couid) == false)
		{
			/*printf("读取到重复数据，请勿重复读取\n");//这个可以防止重复读取但是修改后的数据无法保存
			return;*/
			_stu_grade[stuid].erase(cousegrade);//键值相同就能删
		}
		int grade; ifs >> grade; cousegrade._grade = grade;
		int ts; ifs >> ts;	_GIVE_TEST_STATIS(ts)	
		PersonGrade.insert(cousegrade);//在学生的个人成绩中加入这门课程的成绩
		cgtable._cou_grade[couid].insert(stuid);//课程成绩表[课程号].insert(学号) 把这个学生信息加入课程成绩单
	}
	cout << "成绩录入完毕" << endl;
}
void GradeTable::Hand_EnterGrade()
{
	ofstream ofs("stu_grade.txt",ios_base::app);
	int op = 1;
	int stuid;
	printf("请输入学号：-> "); cin >> stuid;	_CHECK_STU_ID(stuid)
	set<CourseGrade>& PersonGrade = _stu_grade[stuid];
	while (op)
	{
		CourseGrade cousegrade;//定义一个课程成绩
		printf("请输入课程号：-> "); cin >> cousegrade._cou_id; 
		if (Judge(stuid, cousegrade._cou_id)==false)
		{
			printf("该学生成绩已经存在 此次输入将会覆盖原本信息 是否继续？\n");
			printf("0. 退出 1. 继续\n");
			int op;
			printf("请输入：-> "); 
			vector<int>optional(op_01);
			set<int>sop;
			_OP_SITUATION	//这里输入op		
		}
		printf("请输入成绩：-> "); cin >> cousegrade._grade;
		printf("请输入考试状态：-> "); 
		int ts; cin >> ts;		_GIVE_TEST_STATIS(ts)
		if (cousegrade._grade > 100 || (ts != 0 && ts != 1))
		{
			cout << "输入有误,请重新输入" << endl;
		}
		else
		{
			PersonGrade.erase(cousegrade);//覆盖前先删掉相同键值的对象
			PersonGrade.insert(cousegrade);
			cgtable._cou_grade[cousegrade._cou_id].insert(stuid);//课程成绩表内放入这个学号
			ofs << "\n\n" << stuid << ' ' <<setw(4)<<setfill('0')<<cousegrade._cou_id << ' ' << cousegrade._grade <<' ' << cousegrade._ts;
			printf("录入成功\n");
		}
		printf("继续录入此学生的成绩吗？ "); printf("1.继续录入    0.退出\n");
		vector<int>optional(op_01);
		set<int>sop;
		_OP_SITUATION
	}
	
}
void Input_EnterStuGrade()
{
	int op;
	printf("1.加载学生成绩文件   2.手动录入  0.退出\n");
	printf("请输入：-> "); 
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
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
		printf("请输入:-> ");_OP_SITUATION
	}
}

ostream& operator<<(ostream& out, const CourseGrade& cou)
{
	Course& course=ctable._cou_table[cou._cou_id];//课程表里拿到这门课的信息
	out << setw(20)<<course._name<<setw(5) << cou._grade<<setw(5)<<course._credit;
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
	//AutoLoading();
	int op;
	printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
	printf("请输入：-> ");
	vector<int>optional(op_04);
	set<int>sop;
	_OP_SITUATION
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
				printf("请输入:-> "); _OP_SITUATION
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];//从课程成绩表中拿到这门课的集合
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade=gtable._stu_grade[e];//通过学号拿到这个学生的所有成绩
				auto it = PersonGrade.find(CourseGrade(couid));//这个学生选了这门课吗？
				if (it!=PersonGrade.end())//选了
				{
					f = 1;
					Student& student = stable._stu_table[e];//拿到学生的个人信息
					cout << setw(10) << student._id << setw(10) << student._name << *it;//打印*it会打印这门课的名字、成绩和考试状态
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
			if (stable._stu_table.find(stuid) == stable._stu_table.end())//学生表里有这个人吗？
			{
				cout << "学生不存在" << endl;
				printf("\n继续查看吗？"); printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
				printf("请输入:-> "); _OP_SITUATION
				continue;
			}
			Student& student = stable._stu_table[stuid]; _CHECK_STU_ID(stuid)//存在检查学号合理性
			set<CourseGrade>& PersonGrade = gtable._stu_grade[stuid];//拿到学生的所有成绩
			for (auto e : PersonGrade)//拿到这个学生每一门的成绩
			{
				cout << setw(10) << student._id << setw(10) << student._name << "   " << e;
			}
		}
		else if (op == 3)
		{
			SetColor(0x06);
			for (auto e : gtable._stu_grade)
			{
				Student& student = stable._stu_table[e.first];//找到这个学生
				cout << left<<setw(10) << student._id << setw(10) << student._name << endl;//输出下学生信息
				set<CourseGrade>& grade = e.second;//找到这个学生的所有成绩
				set<CourseGrade>::iterator it = grade.end(); it--;//按课程号升序来输出
				while (it != grade.begin())//访问除第一门之外的成绩
				{
					Course& course = ctable._cou_table[it->_cou_id];
					printf("%04d   ", course._id);
					cout << *it << endl;
					it--;
				}
				Course& course = ctable._cou_table[it->_cou_id];//访问第一门课程
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
		printf("\n继续查看吗？"); printf("1.查看某门课的成绩   2.查看某学生的所有成绩  3.查看所有人的所有成绩  0.退出\n");
		printf("请输入:-> "); _OP_SITUATION
	}
}

void Erase()
{
	int op;
	printf("1.删除某门课   2.删除某学生  0.退出\n");
	printf("请输入：-> "); 
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
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
				printf("请输入:-> "); _OP_SITUATION
				continue;
			}
			ctable._cou_table.erase(couid);//课程信息表里删掉这门课
			set<int>& stuid = cgtable._cou_grade[couid];//找到这门课的学号集合 再把里面每个学生这门课的成绩删掉
			for (auto e : stuid)
			{
				set<CourseGrade>& PersonGrade = gtable._stu_grade[e];//这个学生的个人所有科目的成绩
				auto it = PersonGrade.find(CourseGrade(couid));//有没有这门课
				if (it != PersonGrade.end())
				{
					PersonGrade.erase(it);//有的话直接删
				}//没有说明没选就不要操作了
			}
			cout << "删除成功" << endl;
		}
		else if (op == 2)
		{
			int stuid;
			printf("请输入学号：-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())//有没有这个学生
			{
				cout << "学生不存在" << endl;
				printf("\n继续删除吗？"); printf("1.删除某门课   2.删除某学生  0.退出\n");
				printf("请输入:-> "); _OP_SITUATION
				continue;
			}
			gtable._stu_grade.erase(stuid);//成绩表里直接把学生信息拿走  课程成绩单的信息来自于总成绩单 总成绩单没了课程成绩单也就没了
			stable._stu_table.erase(stuid);//学生信息表里把学生拿走
			cout << "删除成功" << endl;
		}
		else if (op == 0)
		{
			break;
		}
		printf("\n继续删除吗？"); printf("1.删除某门课   2.删除某学生  0.退出\n");
		printf("请输入:-> "); _OP_SITUATION
	}
}

void Update()
{
	int op;
	printf("1.修改某门课   2.修改某学生  0.退出\n");
	printf("请输入：-> "); 
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
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
		printf("\n继续修改吗？"); printf("1.修改某门课   2.修改某学生  0.退出\n");
		printf("请输入:-> "); _OP_SITUATION
	}
}

bool cmp_grade(const PAIR& e1,const PAIR& e2 )//自定义map排序
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
	printf("请输入：-> "); 
	vector<int>optional(op_05);
	set<int>sop;
	_OP_SITUATION
	while (op)
	{
		map<int, int>id_grade;//id和成绩
		map<int, int>id_status;//学号和这门课的考试状态
		map<int, int>id_total;//学号和总分
		if (op == 1)
		{
			SetColor(0x0a);
			int couid;
			bool f = 0;//看这门课存在后是否有无成绩
			printf("请输入课程号：-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())//课程不存在
			{
				cout << "课程不存在" << endl;
				printf("\n继续查看吗？"); printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分   0.退出\n");
				printf("请输入:-> "); 
				vector<int>optional(op_05);
				set<int>sop;
				_OP_SITUATION
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];//拿到这门课的学号集合	
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));//找到这门课的成绩
				if (it != PersonGrade.end())//*it 得到课程的成绩
				{
					f = 1;
					id_grade[e] = it->_grade;//取出这门课的成绩
					if (it->_ts == Normal)
					{
						id_status[e] = 1;//取出这门课的考试状态
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
				Course& course = ctable._cou_table[couid];//课程表里拿到这门课的信息
				vector<PAIR>v_grade(id_grade.begin(), id_grade.end());
				sort(v_grade.begin(), v_grade.end(), cmp_grade);//排序
				for (auto e : v_grade)//输出排序后的信息
				{
					Student& student = stable._stu_table[e.first];//得到学生的信息
					cout <<left<< setw(20) << course._name;
					cout <<left<< setw(10) << student._id << setw(10) << student._name << setw(5) << e.second;
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
			Output();//默认输出就是按学号排序的
		}
		else if (op == 3)
		{
			SetColor(0x0b);
			for (auto e1 : gtable._stu_grade)//遍历
			{
				//e1是学号和个人成绩的集合
				int total=0;//记录总分
				for (auto e2 : e1.second)//遍历这个人的所有成绩
				{
					total += e2._grade;
				}
				id_total[e1.first] = total;//把总分放入集合 与学号相对应
			}
			vector<PAIR>v_total(id_total.begin(), id_total.end());//总分
			if (v_total.size() == 0)
			{
				cout << "成绩表为空" << endl;
				printf("\n继续查看吗？"); printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分   0.退出\n");
				printf("请输入:-> "); _OP_SITUATION
				continue;
			}
			sort(v_total.begin(), v_total.end(), cmp_grade);
			for (auto e : v_total)//排序后输出
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
				printf("请输入:-> "); _OP_SITUATION
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));//拿到个人所有成绩
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
				auto e = v_grade.begin();//排序
				Student& student = stable._stu_table[e->first];//得到学生的信息
				cout <<setw(20)<<ctable._cou_table[couid]._name;
				cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e->second;
				if (id_status[e->first] == 1)//输出考试状态
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
		printf("1.按单科成绩排序   2.按学号排序  3.按总分排序  4.得到单科最高分  0.退出\n");
		printf("请输入:-> "); _OP_SITUATION
	}
}

void SetColor(int hex = 07)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), hex);
}

void AutoLoading()
{
	stable.LoadingFile_Stu();
	ctable.LoadingFile_Cou();
	gtable.LoadingFile_Grade();
}

void KeyBoardMonitor()//监测键盘是否有输入
{
	char* s = new char[10];
	bool f = 0;
	printf("请按任意键继续:->");
	while (1)
	{
		while (_kbhit())
		{
			//cout << "已经按键" << endl;
			f = 1;
			return;
		}
	}
}
bool AutoLogin()
{
	SetColor(0x0b);
	ifstream ifs("account.txt");
	if (!ifs)
	{
		cout << "\n账号密码文件不存在，无法自动登录\n" << endl; KeyBoardMonitor();
		return false;
	}
	char ch;
	ifs >> ch;//读出一个字符  判断是否为空文件
	if (ifs.eof())
	{
		cout << "\n文件为空\n" << endl; KeyBoardMonitor();
		return false;
	}

	//到这里说明文件存在 开始读取文件内容
	string id, password;
	ifs >> id >> password;
	if (id == "123456" && password == "123456")
	{
		return true;//成功登陆
	}
	else
	{
		cout << "\n账号密码文件信息错误\n" << endl; KeyBoardMonitor();
		return false;
	}
}
bool Login()
{
	system("color 02");
	string id,ps;
	printf("\n\n***********************\n");
	printf("*****   登录界面   ****\n");
	printf("账号->: "); cin >> id;
	printf("密码->: "); 
	char ch;
	while (ps.size()<20&&(ch = _getch()) != '\r')
	{
		if (ch != '\b')
		{
			ps += ch;
			putchar('*');
		}
		else
		{
			if (ps.size() >= 1)
			{
				ps.erase(ps.size() - 1);//BackSpace键的目的是删除字符 所以要更新一下ps
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			
		}
	}
	if (id == "123456" && ps == "123456")//设置账号密码
	{
		return true;
	}
	return false;
}

void menu()
{
	SetColor(0x0A);
	
	MENU
	int op;
	printf("请输入： "); 
	vector<int>optional(op_09);
	set<int>sop;
	_OP_SITUATION
	while (op!=0)
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
		case 8:
			SetColor(0x0b);
			AutoLoading();
			break;
		}
		printf("\n\n");
		system("cls");
		SetColor(0x0A);
		MENU
		printf("请输入:-> "); _OP_SITUATION
	}
}

void Start()
{
	SetColor(0x0b);	
	int op = 1;
	printf("\n\n1.手动登录 2.自动登录 0. 退出");
	printf("请输入：-> ");
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
	while (op)
	{	
		if(op==1)
		{
			if (Login())
			{
				system("cls");
				menu();
				break;
			}
			else
			{
				_AGAIN_LOGIN
			}
		}
		else if (op == 2)
		{
			if (AutoLogin())
			{
				system("cls");
				menu();
				break;
			}
			else
			{
				_AGAIN_LOGIN
			}
		}		
	}	
}