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
		cout << "ѧ����Ϣ�ļ�������" << endl;
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
		if (Judge(stuid)==false)
		{
			printf("��ȡ���ظ����ݣ������ظ���ȡ\n");
			return;
		}
		_stu_table[stuid]._id = stuid;
		ifs >> _stu_table[stuid]._name;
		ifs >> _stu_table[stuid]._age;
		ifs >> _stu_table[stuid]._sex;
	}	
	cout << "¼�����" << endl;
}
void STable::Hand_EnterInfo()
{
	int stuid;
	printf("������ѧ�ţ�-> "); cin >> stuid;
	if (Judge(stuid)==false)
	{
		printf("��ѧ���Ѿ����� �˴����뽫�Ḳ��ԭ����Ϣ �Ƿ������\n");
		printf("0. �˳� 1. ����\n");
		int op; 
		printf("�����룺-> ");cin >> op;
		if (op == 0)
		{
			return;
		}
	
	}
	Student& input=stable._stu_table[stuid];
	printf("������������-> "); cin >> input._name;
	printf("���������䣺-> "); cin >> input._age;
	printf("�������Ա�-> "); cin >> input._sex;
	if (input._id < 0||input._name.size() >= 20 || input._age >= 150 || (input._sex != "��" && input._sex != "Ů"))
	{
		cout << "��������,����������" << endl;
		stable._stu_table.erase(stuid);
	}
	else
	{
		printf("¼��ɹ�\n");
	}
}
void Input_EnterStuInfo()
{
	int op;	
	printf("1.����ѧ����Ϣ�ļ�   2.�ֶ�¼��  0.�˳�\n");
	printf("�����룺-> "); cin >> op;
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
		printf("������:-> "); cin >> op;
	}
}


void CouTable::LoadingFile_Cou()
{
	ifstream ifs("cou_info.txt");
	FILE* pf=fopen("cou_info.txt","r");
	
	if (!ifs)
	{
		cout << "ѧ����Ϣ�ļ�������" << endl;
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
			printf("��ȡ���ظ����ݣ������ظ���ȡ\n");
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
	cout << "¼�����" << endl;
}
void CouTable::Hand_EnterInfo()
{
	int couid;
	printf("������γ̺ţ�-> "); cin >> couid;
	if (Judge(couid) == false)
	{
		printf("�ÿγ��Ѿ����� �˴����뽫�Ḳ��ԭ����Ϣ �Ƿ������\n");
		printf("0. �˳� 1. ����\n");
		int op;
		printf("�����룺-> "); cin >> op;
		if (op == 0)
		{
			return;
		}
		
	}
	Course& input = ctable._cou_table[couid];
	input._id = couid;
	printf("������γ�����-> "); cin >> input._name;
	printf("������ѧ�֣�-> "); cin >> input._credit;
	printf("�����������λ��ʦ�����֣��м��ÿո�������\n");
	printf("�������ڿ���ʦ���֣�->");
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
		cout << "��������,����������" << endl;
		ctable._cou_table.erase(couid);
	}
	else
	{
		printf("¼��ɹ�\n");
	}
}
void Input_EnterCouInfo()
{
	int op;
	printf("1.���ؿγ���Ϣ�ļ�   2.�ֶ�¼��  0.�˳�\n");
	printf("�����룺-> "); cin >> op;
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
		printf("������:-> "); cin >> op;
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
		set<CourseGrade>& PersonGrade = _stu_grade[stuid];
		CourseGrade cousegrade;
		int couid; ifs >> couid; cousegrade._cou_id = couid;
		if (Judge(stuid, couid) == false)
		{
			printf("��ȡ���ظ����ݣ������ظ���ȡ\n");
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
	cout << "¼�����" << endl;
}
void GradeTable::Hand_EnterGrade()
{
	int op = 1;
	int stuid;
	printf("������ѧ�ţ�-> "); cin >> stuid;
	set<CourseGrade>& PersonGrade = _stu_grade[stuid];
	while (op)
	{
		CourseGrade cousegrade;
		printf("������γ̺ţ�-> "); cin >> cousegrade._cou_id;
		if (Judge(stuid, cousegrade._cou_id)==false)
		{
			printf("��ѧ���ɼ��Ѿ����� �˴����뽫�Ḳ��ԭ����Ϣ �Ƿ������\n");
			printf("0. �˳� 1. ����\n");
			int op;
			printf("�����룺-> "); cin >> op;
			if (op == 0)
			{
				return;
			}
			
		}
		printf("������ɼ���-> "); cin >> cousegrade._grade;
		printf("�����뿼��״̬��-> "); int ts; cin >> ts;
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
			cout << "��������,����������" << endl;
		}
		else
		{
			PersonGrade.insert(cousegrade);
			cgtable._cou_grade[cousegrade._cou_id].insert(stuid);
			printf("¼��ɹ�\n");
		}
		printf("����¼���ѧ���ĳɼ��� "); printf("1.����¼��    0.�˳�\n");
		cin >> op;
	}
	
}
void Input_EnterStuGrade()
{
	int op;
	printf("1.����ѧ���ɼ��ļ�   2.�ֶ�¼��  0.�˳�\n");
	printf("�����룺-> "); cin >> op;
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
		printf("������:-> "); cin >> op;
	}
}

ostream& operator<<(ostream& out, const CourseGrade& cou)
{
	Course& course=ctable._cou_table[cou._cou_id];
	out << setw(20)<<course._name<<setw(5) << cou._grade;
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
	int op;
	printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
	printf("�����룺-> "); cin >> op;
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
				printf("������:-> "); cin >> op;
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
				cout << "�ÿγ��޳ɼ�" << endl;
			}
		}
		else if (op == 2)
		{
			int stuid;
			printf("������ѧ�ţ�-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())
			{
				cout << "ѧ��������" << endl;
				printf("\n�����鿴��"); printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
				printf("������:-> "); cin >> op;
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
		else
		{
			cout << "��������˳���" << endl;
			break;
		}
		printf("\n�����鿴��"); printf("1.�鿴ĳ�ſεĳɼ�   2.�鿴ĳѧ�������гɼ�  3.�鿴�����˵����гɼ�  0.�˳�\n");
		printf("������:-> "); cin >> op;
	}
}
void Erase()
{
	int op;
	printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
	printf("�����룺-> "); cin >> op;
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
				printf("������:-> "); cin >> op;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else if (op == 2)
		{
			int stuid;
			printf("������ѧ�ţ�-> "); cin >> stuid;
			if (stable._stu_table.find(stuid) == stable._stu_table.end())
			{
				cout << "ѧ��������" << endl;
				printf("\n����ɾ����"); printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
				printf("������:-> "); cin >> op;
				continue;
			}
			gtable._stu_grade.erase(stuid);
			stable._stu_table.erase(stuid);
			cout << "ɾ���ɹ�" << endl;
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
		printf("\n����ɾ����"); printf("1.ɾ��ĳ�ſ�   2.ɾ��ĳѧ��  0.�˳�\n");
		printf("������:-> "); cin >> op;
	}
}
void Update()
{
	int op;
	printf("1.�޸�ĳ�ſ�   2.�޸�ĳѧ��  0.�˳�\n");
	printf("�����룺-> "); cin >> op;
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
		else
		{
			cout << "��������˳���" << endl;
			break;
		}
		printf("\n�����޸���"); printf("1.�޸�ĳ�ſ�   2.�޸�ĳѧ��  0.�˳�\n");
		printf("������:-> "); cin >> op;
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
	printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�   0.�˳�\n");
	printf("�����룺-> "); cin >> op;
	while (op)
	{
		map<int, int>id_grade;//id�ͳɼ�
		map<int, int>id_status;//ѧ�ź����ſεĿ���״̬
		map<int, int>id_total;//ѧ�ź��ܷ�
		vector<PAIR>v_total(id_total.begin(), id_total.end());//�ܷ�
		if (op == 1)
		{
			SetColor(0x0a);
			int couid;
			bool f = 0;
			printf("������γ̺ţ�-> "); cin >> couid;
			if (ctable._cou_table.find(couid) == ctable._cou_table.end())
			{
				cout << "�γ̲�����" << endl;
				printf("\n�����鿴��"); printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�   0.�˳�\n");
				printf("������:-> "); cin >> op;
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));
				
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
				for (auto e : v_grade)
				{
					Student& student = stable._stu_table[e.first];//�õ�ѧ������Ϣ
					cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e.second;
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
			Output();
		}
		else if (op == 3)
		{
			SetColor(0x0b);
			for (auto e1 : gtable._stu_grade)//����ѧ��
			{
				int total=0;
				for (auto e2 : e1.second)//�����ɼ�
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
				printf("������:-> "); cin >> op;
				continue;
			}
			set<int>& stuid = cgtable._cou_grade[couid];
			for (auto e : stuid)
			{
				set<CourseGrade>PersonGrade = gtable._stu_grade[e];
				auto it = PersonGrade.find(CourseGrade(couid));
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
				auto e = v_grade.begin();
				Student& student = stable._stu_table[e->first];//�õ�ѧ������Ϣ
				cout <<setw(20)<<ctable._cou_table[couid]._name;
				cout << setw(10) << student._id << setw(10) << student._name << setw(5) << e->second;
				if (id_status[e->first] == 1)
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
		else
		{
			cout << "��������˳���" << endl;
			break;
		}
		printf("1.�����Ƴɼ�����   2.��ѧ������  3.���ܷ�����  4.�õ�������߷�  0.�˳�\n");
		printf("������:-> "); cin >> op;
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
	printf("*                   �ɼ�����ϵͳ                   *\n");
	printf("*                                                  *\n");
	printf("*                                                  *\n");
	printf("*                   1.¼��ѧ����Ϣ                 *\n");
	printf("*                   2.¼��γ���Ϣ                 *\n");
	printf("*                   3.¼��ѧ���ɼ�                 *\n");
	printf("*                   4.�鿴                         *\n");
	printf("*                   5.ɾ��                         *\n");
	printf("*                   6.�޸�ѧ���ɼ�                 *\n");
	printf("*                   7.���ɼ���������               *\n");
	printf("*                   0.�˳�                         *\n");
	printf("*                                                  *\n");
	printf("****************************************************\n");

	int op;
	printf("�����룺 "); cin >> op;
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
		printf("*                   �ɼ�����ϵͳ                   *\n");
		printf("*                                                  *\n");
		printf("*                                                  *\n");
		printf("*                   1.¼��ѧ����Ϣ                 *\n");
		printf("*                   2.¼��γ���Ϣ                 *\n");
		printf("*                   3.¼��ѧ���ɼ�                 *\n");
		printf("*                   4.�鿴                         *\n");
		printf("*                   5.ɾ��                         *\n");
		printf("*                   6.�޸�ѧ���ɼ�                 *\n");
		printf("*                   7.���ɼ���������               *\n");
		printf("*                   0.�˳�                         *\n");
		printf("*                                                  *\n");
		printf("****************************************************\n");
		printf("������:-> "); cin >> op;
	}



}
