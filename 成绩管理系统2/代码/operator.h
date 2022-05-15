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
printf("*                   �ɼ�����ϵͳ                   *\n");\
printf("*                                                  *\n");\
printf("*                                                  *\n");\
printf("*                   1.¼��ѧ����Ϣ                 *\n");\
printf("*                   2.¼��γ���Ϣ                 *\n");\
printf("*                   3.¼��ѧ���ɼ�                 *\n");\
printf("*                   4.�鿴                         *\n");\
printf("*                   5.ɾ��                         *\n");\
printf("*                   6.�޸�                         *\n");\
printf("*                   7.���ɼ���������               *\n");\
printf("*                   8.�Զ�¼����Ϣ                 *\n");\
printf("*                   0.�˳�                         *\n");\
printf("*                                                  *\n");\
printf("****************************************************\n");

#define _AGAIN_LOGIN cout << endl;\
system("color 0c"); system("cls");\
printf("\n\n�Զ���¼ʧ��,����������\n");\
printf("****************************\n\n");\
printf("1.�ֶ���¼ 2.�Զ���¼ 0. �˳�\n\n");\
printf("****************************\n");\
printf("�����룺-> ");\
_OP_SITUATION \
system("cls");

#define _CHECK_STU_NAME(name)  if (name.size() <= 0 || name.size() > 50) {PrintError();stable._stu_table.erase(stuid); return;} \
for (auto e : name)\
{\
	if (e >= '0' && e <= '9') {PrintError();stable._stu_table.erase(stuid);return;}\
}//�涨ѧ�������в��������������ֲ��ܹ���
#define  _CHECK_STU_ID(id) if (id < 10000000 || id>99999999) {PrintError();stable._stu_table.erase(stuid); return;}//�涨ѧ�ű�����8λ
#define  _CHECK_AGE(age) if (age < 0 || age >= 200) {PrintError();stable._stu_table.erase(stuid); return;}//�涨ѧ��������0-200֮��
#define _CHECK_SEX(sex) if (sex != "��" && sex != "Ů") {PrintError();stable._stu_table.erase(stuid); return;}//�涨�Ա�ֻ����Ů

#define _CHECK_COURSE_NAME(name)  if (name.size() <= 0 || name.size() > 50) {PrintError();ctable._cou_table.erase(couid); return;} \
for (auto e : name)\
{\
	if (e >= '0' && e <= '9') {PrintError();ctable._cou_table.erase(couid); return;}\
}//�涨��ʦ�����в��������������ֲ��ܹ���
#define _CHECK_COURSE_ID(id) if(id<0||id>10000)  {PrintError();ctable._cou_table.erase(couid); return;}//�涨ѧ����1-1000֮��
#define _CHECK_COURSE_NAME(name)  if (name.size() <= 0 || name.size() > 50||(name[0]>='0'&&name[0]<='9'))\
{PrintError(); ctable._cou_table.erase(couid); return;} //�涨�γ����ֲ���̫���ҵ�һ���ַ�����������

#define _CHECK_CREDIT(credit)  if(credit<0||credit>30) {PrintError();  ctable._cou_table.erase(couid); return;}//�涨ѧ����0-30֮��

#define _GIVE_TEST_STATIS(ts)  if (ts == 0)\
{\
	cousegrade._ts = NotNormal;\
	cousegrade._grade = 0;\
}\
else\
{\
	cousegrade._ts = Normal;\
}//���������ts������һ��״̬��tsΪ0��ʾ����״̬��������������ȱ����,tsΪ1��ʾ����״̬������

vector<int>op_01;
vector<int>op_012;
vector<int>op_04;
vector<int>op_05;
vector<int>op_09;
void InitOption()//��ʼ��op_xx����
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
bool CheckOp(int& op,set<int>&sop )//���sop���Ƿ����op
{
	if (sop.find(op)!=sop.end())
	{
		return true;
	}
	return false;
}
void InitSetOp(vector<int>& optional, int n, set<int>& sop)//��optional��ֵ��ʼ��sop
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
		cout << "IO������δ֪����" << endl;
		return -1;
	}
	else if (cin.fail())
	{
		SetColor(0x04);
		cout << "������������/��������,��ʹ�������" << endl;//����˵cinû�ж�������
		cin.clear();
		cin.ignore(INT_MAX,'\n');		
		return -1;
	}
	else if(CheckOp(op, sop))
	{
		char ch = getchar();				
		if (ch == '\n' || ch == ' ')//���������޶�������� ������6vybuij������
		{
			return op;
		}
		else
		{
			return -1;
		}
		/*string str;//��Ҫ��ȡ�Ƿ����ݿ��������ְ취��ǰ�����зǷ����ݣ�
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
	printf("\n\n��������,�˳���ǰ����\n\n");
	Sleep(1200);
}

void StuTable::LoadingFile_Stu()
{
	ifstream ifs("stu_info.txt");
	if (!ifs)
	{
		cout << "ѧ����Ϣ�ļ�������" << endl;
		return;
	}
	int stuid;
	char ch;
	ifs >> ch;//�ļ�Ϊ��ʱ����һ���ַ� ���Ȱ�����ַ�������  (�ļ����ǳ�ʼ��״̬������EOFϵͳ�Ż���ļ�״̬����Ϊ�ļ�β
	//eof()�Ǹ����ļ�״̬���ж��ļ��Ƿ�Ϊ��  ���Ե��ȳ��Զ�ȡһ���ַ��ı���״̬
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}
	while (!ifs.eof())//�ļ������һ�б�ӻ��� ��Ȼû����β�������һ�����ݶ�����
	{
		ifs >> stuid;
		if (Judge(stuid)==false)
		{
			//printf("��ȡ���ظ����ݣ������ظ���ȡ\n");
			//return;
			_stu_table.erase(stuid);//�еĻ���ɾ���ٲ���ʵ�ָ���
		}
		_stu_table[stuid]._id = stuid;
		ifs >> _stu_table[stuid]._name;
		ifs >> _stu_table[stuid]._age;
		ifs >> _stu_table[stuid]._sex;
	}	
	cout << "ѧ����Ϣ¼�����" << endl;
}
void StuTable::Hand_EnterInfo()
{
	ofstream ofs("stu_info.txt",ios_base::app);
	int stuid;
	printf("������ѧ�ţ�-> "); 
	cin >> stuid;	 
	if (Judge(stuid)==false)
	{
		printf("��ѧ���Ѿ����� �˴����뽫�Ḳ��ԭ����Ϣ �Ƿ������\n");
		printf("0. �˳� 1. ����\n");
		int op; 
		printf("�����룺-> ");
		vector<int>optional(op_01);
		set<int>sop;
		_OP_SITUATION
	}
	stable._stu_table.erase(stuid);
	Student& input = stable._stu_table[stuid];		_CHECK_STU_ID(stuid)
		input._id = stuid;
	printf("������������-> "); cin >> input._name;	_CHECK_STU_NAME(input._name)  
	printf("���������䣺-> "); cin >> input._age;		_CHECK_AGE(input._age) 
	printf("�������Ա�-> "); cin >> input._sex;		_CHECK_SEX(input._sex)
		ofs << '\n' << '\n' << stuid;
	ofs << " " << input._name; 
	ofs << " " << input._age;	
	ofs << " " << input._sex;
	printf("¼��ɹ�\n");
	
}
void Input_EnterStuInfo()
{
	int op;	
	printf("1.����ѧ����Ϣ�ļ�   2.�ֶ�¼��  0.�˳�\n");
	printf("�����룺-> "); 
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
			cout << "��������˳���" << endl;
			break;
		}
		printf("\n����¼����"); printf("1.����ѧ���ļ�   2.�ֶ�¼��  0.�˳�\n");
		printf("������:-> "); 
		_OP_SITUATION
	}
}

void CouTable::LoadingFile_Cou()
{
	ifstream ifs("cou_info.txt");
	FILE* pf=fopen("cou_info.txt","r");
	
	if (!ifs)
	{
		cout << "�γ���Ϣ�ļ�������" << endl;
		return;
	}
	int couid;
	char ch;
	ifs >> ch;//�ļ�Ϊ��ʱ����һ���ַ� ���Ȱ�����ַ�������
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}
	while (!ifs.eof())//�ļ������һ�б�ӻ��� ��Ȼû����β�������һ�����ݶ�����
	{
		ifs >> couid;
		if (Judge(couid) == false)
		{
			/*printf("��ȡ���ظ����ݣ������ظ���ȡ\n");
			return;*/
			_cou_table.erase(couid);//�еĻ���ɾ���ٲ���ʵ�ָ���
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
	cout << "�γ���Ϣ¼�����" << endl;
}
void CouTable::Hand_EnterInfo()
{
	ofstream ofs("cou_info.txt", ios_base::app);//׷��
	int couid;
	printf("������γ̺ţ�-> "); cin >> couid;	
	if (Judge(couid) == false)
	{
		printf("�ÿγ��Ѿ����� �˴����뽫�Ḳ��ԭ����Ϣ �Ƿ������\n");
		printf("0. �˳� 1. ����\n");
		int op;
		printf("�����룺-> ");
		vector<int>optional(op_01);
		set<int>sop;
		_OP_SITUATION
	}
	ctable._cou_table.erase(couid);
	Course& input = ctable._cou_table[couid]; _CHECK_COURSE_ID(couid)
	input._id = couid;
	printf("������γ�����-> "); cin >> input._name;	_CHECK_COURSE_NAME(input._name)
	printf("������ѧ�֣�-> "); cin >> input._credit;	_CHECK_CREDIT(input._credit)
	printf("�����������λ��ʦ�����֣��м��ÿո�������\n");
	printf("�������ڿ���ʦ���֣�->");
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
	printf("¼��ɹ�\n");
	
}
void Input_EnterCouInfo()
{
	int op;
	printf("1.���ؿγ���Ϣ�ļ�   2.�ֶ�¼��  0.�˳�\n");
	printf("�����룺-> "); 
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
			cout << "��������˳���" << endl;
			break;
		}
		printf("\n����¼����"); printf("1.���ؿγ���Ϣ�ļ�   2.�ֶ�¼��  0.�˳�\n");
		printf("������:-> "); _OP_SITUATION
	}
}

void GradeTable::LoadingFile_Grade()
{
	ifstream ifs("stu_grade.txt");
	if (!ifs)
	{
		cout << "�ɼ����ļ�������" << endl;
		return;
	}
	int stuid;
	char ch;
	ifs >> ch;//�ļ�Ϊ��ʱ����һ���ַ� ���Ȱ�����ַ�������
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}
	while (!ifs.eof())//�ļ������һ�б�ӻ��� ��Ȼû����β�������һ�����ݶ�����
	{
		ifs >> stuid;
		set<CourseGrade>& PersonGrade = _stu_grade[stuid];//���ѧ���ĸ��˳ɼ�
		CourseGrade cousegrade;
		int couid; ifs >> couid; cousegrade._cou_id = couid;
		if (Judge(stuid, couid) == false)
		{
			/*printf("��ȡ���ظ����ݣ������ظ���ȡ\n");//������Է�ֹ�ظ���ȡ�����޸ĺ�������޷�����
			return;*/
			_stu_grade[stuid].erase(cousegrade);//��ֵ��ͬ����ɾ
		}
		int grade; ifs >> grade; cousegrade._grade = grade;
		int ts; ifs >> ts;	_GIVE_TEST_STATIS(ts)	
		PersonGrade.insert(cousegrade);//��ѧ���ĸ��˳ɼ��м������ſγ̵ĳɼ�
		cgtable._cou_grade[couid].insert(stuid);//�γ̳ɼ���[�γ̺�].insert(ѧ��) �����ѧ����Ϣ����γ̳ɼ���
	}
	cout << "�ɼ�¼�����" << endl;
}
void GradeTable::Hand_EnterGrade()
{
	ofstream ofs("stu_grade.txt",ios_base::app);
	int op = 1;
	int stuid;
	printf("������ѧ�ţ�-> "); cin >> stuid;	_CHECK_STU_ID(stuid)
	set<CourseGrade>& PersonGrade = _stu_grade[stuid];
	while (op)
	{
		CourseGrade cousegrade;//����һ���γ̳ɼ�
		printf("������γ̺ţ�-> "); cin >> cousegrade._cou_id; 
		if (Judge(stuid, cousegrade._cou_id)==false)
		{
			printf("��ѧ���ɼ��Ѿ����� �˴����뽫�Ḳ��ԭ����Ϣ �Ƿ������\n");
			printf("0. �˳� 1. ����\n");
			int op;
			printf("�����룺-> "); 
			vector<int>optional(op_01);
			set<int>sop;
			_OP_SITUATION	//��������op		
		}
		printf("������ɼ���-> "); cin >> cousegrade._grade;
		printf("�����뿼��״̬��-> "); 
		int ts; cin >> ts;		_GIVE_TEST_STATIS(ts)
		if (cousegrade._grade > 100 || (ts != 0 && ts != 1))
		{
			cout << "��������,����������" << endl;
		}
		else
		{
			PersonGrade.erase(cousegrade);//����ǰ��ɾ����ͬ��ֵ�Ķ���
			PersonGrade.insert(cousegrade);
			cgtable._cou_grade[cousegrade._cou_id].insert(stuid);//�γ̳ɼ����ڷ������ѧ��
			ofs << "\n\n" << stuid << ' ' <<setw(4)<<setfill('0')<<cousegrade._cou_id << ' ' << cousegrade._grade <<' ' << cousegrade._ts;
			printf("¼��ɹ�\n");
		}
		printf("����¼���ѧ���ĳɼ��� "); printf("1.����¼��    0.�˳�\n");
		vector<int>optional(op_01);
		set<int>sop;
		_OP_SITUATION
	}
	
}
void Input_EnterStuGrade()
{
	int op;
	printf("1.����ѧ���ɼ��ļ�   2.�ֶ�¼��  0.�˳�\n");
	printf("�����룺-> "); 
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
			cout << "��������˳���" << endl;
			break;
		}
		printf("\n����¼����"); printf("1.����ѧ���ļ�   2.�ֶ�¼��  0.�˳�\n");
		printf("������:-> ");_OP_SITUATION
	}
}

ostream& operator<<(ostream& out, const CourseGrade& cou)
{
	Course& course=ctable._cou_table[cou._cou_id];//�γ̱����õ����ſε���Ϣ
	out << setw(20)<<course._name<<setw(5) << cou._grade<<setw(5)<<course._credit;
	if (cou._ts == Normal)
	{
		out << setw(20) << "����״̬������";
	}
	else
	{
		out << setw(20) << "����״̬��������";
	}
	out << endl;
	return out;
}
void Output()
{
	//AutoLoading();
	int op;
	printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
	printf("�����룺-> ");
	vector<int>optional(op_04);
	set<int>sop;
	_OP_SITUATION
	while (op)
	{
		if (op == 1)
		{
			int couid;
			bool f = 0;
			printf("������γ̺ţ�-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "�γ̲�����" << endl;
				printf("\n�����鿴��"); printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
				printf("������:-> "); _OP_SITUATION
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];//�ӿγ̳ɼ������õ����ſεļ���
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade=gtable._stu_grade[e];//ͨ��ѧ���õ����ѧ�������гɼ�
				auto it = PersonGrade.find(CourseGrade(couid));//���ѧ��ѡ�����ſ���
				if (it!=PersonGrade.end())//ѡ��
				{
					f = 1;
					Student& student = stable._stu_table[e];//�õ�ѧ���ĸ�����Ϣ
					cout << setw(10) << student._id << setw(10) << student._name << *it;//��ӡ*it���ӡ���ſε����֡��ɼ��Ϳ���״̬
				}
			}
			if (f == 0)
			{
				cout << "�ÿγ��޳ɼ�" << endl;
			}
		}
		else if (op == 2)
		{
			int stuid;
			printf("������ѧ�ţ�-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())//ѧ���������������
			{
				cout << "ѧ��������" << endl;
				printf("\n�����鿴��"); printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
				printf("������:-> "); _OP_SITUATION
				continue;
			}
			Student& student = stable._stu_table[stuid]; _CHECK_STU_ID(stuid)//���ڼ��ѧ�ź�����
			set<CourseGrade>& PersonGrade = gtable._stu_grade[stuid];//�õ�ѧ�������гɼ�
			for (auto e : PersonGrade)//�õ����ѧ��ÿһ�ŵĳɼ�
			{
				cout << setw(10) << student._id << setw(10) << student._name << "   " << e;
			}
		}
		else if (op == 3)
		{
			SetColor(0x06);
			for (auto e : gtable._stu_grade)
			{
				Student& student = stable._stu_table[e.first];//�ҵ����ѧ��
				cout << left<<setw(10) << student._id << setw(10) << student._name << endl;//�����ѧ����Ϣ
				set<CourseGrade>& grade = e.second;//�ҵ����ѧ�������гɼ�
				set<CourseGrade>::iterator it = grade.end(); it--;//���γ̺����������
				while (it != grade.begin())//���ʳ���һ��֮��ĳɼ�
				{
					Course& course = ctable._cou_table[it->_cou_id];
					printf("%04d   ", course._id);
					cout << *it << endl;
					it--;
				}
				Course& course = ctable._cou_table[it->_cou_id];//���ʵ�һ�ſγ�
				printf("%04d   ", course._id);
				cout << *it << endl;

				/*for (auto e2 : grade)
				{
				//�γ̺������ӡ
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
		printf("\n�����鿴��"); printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
		printf("������:-> "); _OP_SITUATION
	}
}

void Erase()
{
	int op;
	printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
	printf("�����룺-> "); 
	vector<int>optional(op_012);
	set<int>sop;
	_OP_SITUATION
	while (op)
	{
		if (op == 1)
		{
			int couid;
			bool f = 0;
			printf("������γ̺ţ�-> "); cin >> couid; 
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "�γ̲�����" << endl;
				printf("\n����ɾ����"); printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
				printf("������:-> "); _OP_SITUATION
				continue;
			}
			ctable._cou_table.erase(couid);//�γ���Ϣ����ɾ�����ſ�
			set<int>& stuid = cgtable._cou_grade[couid];//�ҵ����ſε�ѧ�ż��� �ٰ�����ÿ��ѧ�����ſεĳɼ�ɾ��
			for (auto e : stuid)
			{
				set<CourseGrade>& PersonGrade = gtable._stu_grade[e];//���ѧ���ĸ������п�Ŀ�ĳɼ�
				auto it = PersonGrade.find(CourseGrade(couid));//��û�����ſ�
				if (it != PersonGrade.end())
				{
					PersonGrade.erase(it);//�еĻ�ֱ��ɾ
				}//û��˵��ûѡ�Ͳ�Ҫ������
			}
			cout << "ɾ���ɹ�" << endl;
		}
		else if (op == 2)
		{
			int stuid;
			printf("������ѧ�ţ�-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())//��û�����ѧ��
			{
				cout << "ѧ��������" << endl;
				printf("\n����ɾ����"); printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
				printf("������:-> "); _OP_SITUATION
				continue;
			}
			gtable._stu_grade.erase(stuid);//�ɼ�����ֱ�Ӱ�ѧ����Ϣ����  �γ̳ɼ�������Ϣ�������ܳɼ��� �ܳɼ���û�˿γ̳ɼ���Ҳ��û��
			stable._stu_table.erase(stuid);//ѧ����Ϣ�����ѧ������
			cout << "ɾ���ɹ�" << endl;
		}
		else if (op == 0)
		{
			break;
		}
		printf("\n����ɾ����"); printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
		printf("������:-> "); _OP_SITUATION
	}
}

void Update()
{
	int op;
	printf("1.�޸�ĳ�ſ�   2.�޸�ĳѧ��  0.�˳�\n");
	printf("�����룺-> "); 
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
			printf("1. �޸�ѧ���ĳɼ�  2.�޸�ѧ������Ϣ  0.�˳�\n");  cin>> x;
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
		printf("\n�����޸���"); printf("1.�޸�ĳ�ſ�   2.�޸�ĳѧ��  0.�˳�\n");
		printf("������:-> "); _OP_SITUATION
	}
}

bool cmp_grade(const PAIR& e1,const PAIR& e2 )//�Զ���map����
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
	printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�   0.�˳�\n");
	printf("�����룺-> "); 
	vector<int>optional(op_05);
	set<int>sop;
	_OP_SITUATION
	while (op)
	{
		map<int, int>id_grade;//id�ͳɼ�
		map<int, int>id_status;//ѧ�ź����ſεĿ���״̬
		map<int, int>id_total;//ѧ�ź��ܷ�
		if (op == 1)
		{
			SetColor(0x0a);
			int couid;
			bool f = 0;//�����ſδ��ں��Ƿ����޳ɼ�
			printf("������γ̺ţ�-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())//�γ̲�����
			{
				cout << "�γ̲�����" << endl;
				printf("\n�����鿴��"); printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�   0.�˳�\n");
				printf("������:-> "); 
				vector<int>optional(op_05);
				set<int>sop;
				_OP_SITUATION
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];//�õ����ſε�ѧ�ż���	
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));//�ҵ����ſεĳɼ�
				if (it != PersonGrade.end())//*it �õ��γ̵ĳɼ�
				{
					f = 1;
					id_grade[e] = it->_grade;//ȡ�����ſεĳɼ�
					if (it->_ts == Normal)
					{
						id_status[e] = 1;//ȡ�����ſεĿ���״̬
					}
					else
					{
						id_status[e] = 0;
					}	
				}
			}
			if (f == 0)
			{
				cout << "�ÿγ��޳ɼ�" << endl;
			}
			else
			{
				Course& course = ctable._cou_table[couid];//�γ̱����õ����ſε���Ϣ
				vector<PAIR>v_grade(id_grade.begin(), id_grade.end());
				sort(v_grade.begin(), v_grade.end(), cmp_grade);//����
				for (auto e : v_grade)//�����������Ϣ
				{
					Student& student = stable._stu_table[e.first];//�õ�ѧ������Ϣ
					cout <<left<< setw(20) << course._name;
					cout <<left<< setw(10) << student._id << setw(10) << student._name << setw(5) << e.second;
					if (id_status[e.first] == 1)
					{
						cout << setw(20) << "����״̬������" << endl;
					}
					else
					{
						cout << setw(20) << "����״̬��������" << endl;
					}
				}
			}
			
		}
		else if (op == 2)
		{
			SetColor(0x03);
			Output();//Ĭ��������ǰ�ѧ�������
		}
		else if (op == 3)
		{
			SetColor(0x0b);
			for (auto e1 : gtable._stu_grade)//����
			{
				//e1��ѧ�ź͸��˳ɼ��ļ���
				int total=0;//��¼�ܷ�
				for (auto e2 : e1.second)//��������˵����гɼ�
				{
					total += e2._grade;
				}
				id_total[e1.first] = total;//���ַܷ��뼯�� ��ѧ�����Ӧ
			}
			vector<PAIR>v_total(id_total.begin(), id_total.end());//�ܷ�
			if (v_total.size() == 0)
			{
				cout << "�ɼ���Ϊ��" << endl;
				printf("\n�����鿴��"); printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�   0.�˳�\n");
				printf("������:-> "); _OP_SITUATION
				continue;
			}
			sort(v_total.begin(), v_total.end(), cmp_grade);
			for (auto e : v_total)//��������
			{
				Student& student = stable._stu_table[e.first];//�õ�ѧ������Ϣ
				cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e.second << endl;
			}
		}
		else if (op == 4)
		{
			SetColor(0x0c);
			int couid;
			bool f = 0;
			printf("������γ̺ţ�-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "�γ̲�����" << endl;
				printf("\n�����鿴��"); printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�   0.�˳�\n");
				printf("������:-> "); _OP_SITUATION
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));//�õ��������гɼ�
				if (it != PersonGrade.end())//*it �õ��γ̵ĳɼ�
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
				cout << "�ÿγ��޳ɼ�" << endl;
			}
			else
			{
				vector<PAIR>v_grade(id_grade.begin(), id_grade.end());
				sort(v_grade.begin(), v_grade.end(), cmp_grade);
				auto e = v_grade.begin();//����
				Student& student = stable._stu_table[e->first];//�õ�ѧ������Ϣ
				cout <<setw(20)<<ctable._cou_table[couid]._name;
				cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e->second;
				if (id_status[e->first] == 1)//�������״̬
				{
					cout << setw(20) << "����״̬������" << endl;
				}
				else
				{
					cout << setw(20) << "����״̬��������" << endl;
				}
				
			}			
		}
		else if (op == 0)
		{
			break;
		}
		printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�  0.�˳�\n");
		printf("������:-> "); _OP_SITUATION
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

void KeyBoardMonitor()//�������Ƿ�������
{
	char* s = new char[10];
	bool f = 0;
	printf("�밴���������:->");
	while (1)
	{
		while (_kbhit())
		{
			//cout << "�Ѿ�����" << endl;
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
		cout << "\n�˺������ļ������ڣ��޷��Զ���¼\n" << endl; KeyBoardMonitor();
		return false;
	}
	char ch;
	ifs >> ch;//����һ���ַ�  �ж��Ƿ�Ϊ���ļ�
	if (ifs.eof())
	{
		cout << "\n�ļ�Ϊ��\n" << endl; KeyBoardMonitor();
		return false;
	}

	//������˵���ļ����� ��ʼ��ȡ�ļ�����
	string id, password;
	ifs >> id >> password;
	if (id == "123456" && password == "123456")
	{
		return true;//�ɹ���½
	}
	else
	{
		cout << "\n�˺������ļ���Ϣ����\n" << endl; KeyBoardMonitor();
		return false;
	}
}
bool Login()
{
	system("color 02");
	string id,ps;
	printf("\n\n***********************\n");
	printf("*****   ��¼����   ****\n");
	printf("�˺�->: "); cin >> id;
	printf("����->: "); 
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
				ps.erase(ps.size() - 1);//BackSpace����Ŀ����ɾ���ַ� ����Ҫ����һ��ps
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			
		}
	}
	if (id == "123456" && ps == "123456")//�����˺�����
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
	printf("�����룺 "); 
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
		printf("������:-> "); _OP_SITUATION
	}
}

void Start()
{
	SetColor(0x0b);	
	int op = 1;
	printf("\n\n1.�ֶ���¼ 2.�Զ���¼ 0. �˳�");
	printf("�����룺-> ");
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