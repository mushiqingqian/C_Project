/*��ϵͳ��ѧ����¼�ʺ�����ͳһΪ��123456
          ��ʦ��¼�ʺ�����ͳһΪ��admin */
/*�ı��ļ�ͳһ�����*.c��Ŀ¼��*/
#include "stdio.h"
#include "conio.h"
#include "windows.h"
void HideCursor()//������ 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
struct information//����ѧ����Ϣ�ṹ��
{
	long int num,age;
	char name[200], Class[200],department[200];
};
struct information s[100];
struct information d;
struct Achievement//����ѧ���ɼ��ṹ��
{
	char name[100];
	long int num, chinese, english, math, synthesize, sum;
};
struct Achievement c[100];
struct Achievement a;
int InfoLoad()//����ȫ��ѧ����Ϣ
{
	FILE * fp;
	int i;
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڡ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %15s %10s %5ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			printf("\n %10ld %10s %15s %10s %5ld", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
		}
	}
	fclose(fp);
}
int AchieveLoad()//����ȫ��ѧ���ɼ�
{
	FILE * fp;
	int i;
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڡ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
		}
	}
	fclose(fp);
}
int SearchInformation()//��������ѧ����Ϣ
{
	FILE *fp;
	int num, i, j, flag=0;
	char ch;
	system("cls");//�����Ļ
	printf("��������Ҫ������ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			if (num == s[i].num)//���Ҵ�ѧ����Ϣ
			{
				flag = 1;//�ж��Ƿ����,������Ϊ1
				system("cls");
				printf("���������Ľ��Ϊ��\n");
				printf("    ѧ��        ����          ϵ��        �༶     ����");
				printf("\n%10ld %10s %15s %10s %5ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
				break;
			}
		}
		if (flag==0)//�ж��Ƿ����,������Ϊ0
		{
			printf("\n�Բ���û���ҵ���ѧ���������Ϣ��\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         �Ƿ����������1������    0���������˵�");
		ch = _getch();//ѡ��
		if (ch == '1')
		{
			system("cls");
			SearchInformation();//����
		}
		else if (ch == '0')
		{
			system("cls");
			TMenu();
		}
	}
}
int STDInformation()
{
	FILE *fp;
	int num, i, j, flag = 0;
	char ch;
	system("cls");//�����Ļ
	printf("��������Ҫ��ѯ��ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			if (num == s[i].num)//���Ҵ�ѧ����Ϣ
			{
				flag = 1;//�ж��Ƿ����,������Ϊ1
				system("cls");
				printf("���������Ľ��Ϊ��\n");
				printf("    ѧ��        ����          ϵ��        �༶     ����");
				printf("\n%10ld %10s %15s %10s %5ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
				break;
			}
		}
		if (flag == 0)//�ж��Ƿ����,������Ϊ0
		{
			printf("\n�Բ���û���ҵ�����������Ϣ��\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         �Ƿ����������1������    0���������˵�");
		ch = _getch();//ѡ��
		if (ch == '1')
		{
			system("cls");
			STDInformation();//����
		}
		else if (ch == '0')
		{
			system("cls");
			SMenu();
		}
	}
}
int SearchAchieve()//��������ѧ���ɼ�
{
	FILE *fp;
	int num, i, j, flag = 0;
	char ch;
	system("cls");
	printf("��������Ҫ������ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num)//����ѧ���Ƿ�ƥ��
			{
				flag = 1;
				system("cls");
				printf("���������Ľ��Ϊ��\n");
				printf("    ѧ��    ����     ����   ��ѧ   Ӣ��   �ۺ� �ܳɼ�");
				printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
				break;
			}
		}
		if (flag == 0)
		{
			printf("\n�Բ���û���ҵ���ѧ���������Ϣ��\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         �Ƿ����������1������    0���������˵�");
		ch = _getch();
		if (ch == '1')
		{
			system("cls");
			SearchAchieve();
		}
		else if (ch == '0')
		{
			system("cls");
			TMenu();
		}
	}
}
int STDAchieve()
{
	FILE *fp;
	int num, i, j, flag = 0;
	char ch;
	system("cls");
	printf("��������Ҫ������ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num)//����ѧ���Ƿ�ƥ��
			{
				flag = 1;
				system("cls");
				printf("���������Ľ��Ϊ��\n");
				printf("    ѧ��    ����     ����   ��ѧ   Ӣ��   �ۺ� �ܳɼ�");
				printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
				break;
			}
		}
		if (flag == 0)
		{
			printf("\n�Բ���û���ҵ���ѧ���������Ϣ��\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         �Ƿ����������1������    0���������˵�");
		ch = _getch();
		if (ch == '1')
		{
			system("cls");
			STDAchieve();
		}
		else if (ch == '0')
		{
			system("cls");
			SMenu();
		}
	}
}
int VisitorSearch()
{
	FILE *fp;
	int num, i, j, flag = 0;
	char ch;
	system("cls");
	printf("��������Ҫ������ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		i = 0;
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			if (num == s[i].num)//���Ҵ�ѧ����Ϣ
			{
				system("cls");
				flag = 1;//�ж��Ƿ����,������Ϊ1
				printf("���������Ľ�����£�\n\n\n\n");
				printf("����ѧ���Ļ�����ϢΪ��\n\n");
				printf("    ѧ��        ����          ϵ��        �༶     ����");
				printf("\n%10ld %10s %15s %10s %5ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
				break;
			}
		}
	}
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num)//����ѧ���Ƿ�ƥ��
			{
				flag = 1;
				printf("\n\n\n\n����ѧ������ĩ�ɼ����£�\n\n");
				printf("    ѧ��    ����     ����   ��ѧ   Ӣ��   �ۺ� �ܳɼ�");
				printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
				break;
			}
		}	
	}
	if (flag == 0)//�ж��Ƿ����,������Ϊ0
	{
		printf("\n�Բ���û���ҵ���ѧ���������Ϣ��\n");
	}
	printf("\n\n\n\n\n\n\n\n\n\n                                         �Ƿ����������1������    0���������˵�");
	ch = _getch();//ѡ��
	if (ch == '1')
	{
		system("cls");
		VisitorSearch();//����
	}
	else if (ch == '0')
	{
		system("cls");
		Visitor();
	}
}
int ReviseInformation()//�޸�ѧ����Ϣ
{
	FILE *fp;
	int num, i, n, flag = 0;
	char ch;
	printf("��������Ҫ������ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)//����ȫ������
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, &s[i].name, &s[i].department, &s[i].Class, &s[i].age);//��������ȡ���ڴ��б���
			if (num == s[i].num && flag == 0)//����ѧ��
			{
				system("cls");
				printf("���������Ľ��Ϊ��\n");
				printf("                            \n   ѧ��    ����     ϵ��      �༶  ����\n");
				printf("\n%ld %s %s %s %ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);//��ʾ�޸�ǰ����Ϣ
				printf("\n\n\n\n\n\n\n\n\n\n                                  �Ƿ�����޸�������Ϣ��     1���޸�    2������\n");
				ch = _getch();
				if (ch == '1')
				{
					system("cls");
					printf("������������Ҫ�޸ĵ�ѧ����Ϣ��\n ����     ϵ��      �༶  ����\n");
					scanf("%s %s %s %ld", &s[i].name, &s[i].department, &s[i].Class, &s[i].age);
					printf("\n\n\n\n\n���������ĸ���Ϣ������ϢΪ��\n");
					printf("                            \n  ѧ��     ����     ϵ��      �༶  ����\n");
					printf("\n%ld %s %s %s %ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
					printf("\n\n\n\n\n\n\n\n\n\n                                  �Ƿ�ȷ���޸�������Ϣ��     1���޸�    0������\n");
					ch = _getch();//�ж��Ƿ��޸���Ϣ
					if (ch == '1')
					{
						flag = 1;
					}
					else if (ch == '0')
					{
						system("cls");
						fclose(fp);
						SearchMenu();
					}
				}
				else if (ch == '2')
				{
					system("cls");
					fclose(fp);
					SearchMenu();
				}
			}
		}
		fclose(fp);
		if ((fp = fopen("student information.txt", "w")) == NULL)//д��׼��
		{
			printf("\n�Բ��𣬴��ļ������ڣ�\n");
		}
		else
		{
			for (n = 0; n < i; n++)//�Զ�ȡʱ�õ�������(i)Ϊѭ�����ս����ѭ��
			{
				fprintf(fp, "%10ld %10s %15s %10s %5ld", s[n].num, s[n].name, s[n].department, s[n].Class, s[n].age);//����ǰ�ڴ��б���ĺ��޸ĺ��ȫ��ѧ����Ϣ���и���д��
			}
			system("cls");
			printf("\nϵͳ���Զ����������桭������\n");
			Sleep(1500);//ʱ��ͣ������,�����ڵ�λΪ:����
			TMenu();
		}
	}
	fclose(fp);
}
int ReviseAchievement()//�޸�ѧ���ɼ�
{
	FILE *fp;
	int num, i, n, flag = 0;
	char ch;
	printf("��������Ҫ������ѧ��:");
	scanf("%d", &num);
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڣ�\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)//����ȫ������
		{
			fscanf(fp, "%ld %s %ld %ld %ld %ld", &c[i].num, &c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num && flag == 0)//����ѧ��
			{
				system("cls");
				printf("���������Ľ��Ϊ��\n");
				printf("   ѧ��     ����    ���� ��ѧ  Ӣ��  �ۺ�");
				printf("\n %5ld %5s %5ld %5ld %5ld %5ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize);
				printf("\n\n\n\n\n\n\n\n\n\n                                  �Ƿ�����޸�������Ϣ��     1���޸�    2������\n");
				ch = _getch();
				if (ch == '1')
				{
					system("cls");
					printf("������������Ҫ�޸ĵ�ѧ���ɼ���\n���� ��ѧ Ӣ�� �ۺ�\n");
					scanf("%ld %ld %ld %ld", &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
					printf("\n\n\n\n\n���������ĸ���Ϣ������ϢΪ��\n");
					printf("\n  ѧ��      ����   ����   ��ѧ  Ӣ��  �ۺ� \n");
					printf("\n %ld %5s %5ld %5ld %5ld %5ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize);
					printf("\n\n\n\n\n\n\n\n\n\n                                  �Ƿ�ȷ���޸�������Ϣ��     1���޸�    0������\n");
					ch = _getch();//�ж��Ƿ��޸���Ϣ
					if (ch == '1')
					{
						flag = 1;
					}
					else if (ch == '0')
					{
						system("cls");
						fclose(fp);
						AchieveMenu();
					}
				}
				else if (ch == '2')
				{
					system("cls");
					fclose(fp);
					AchieveMenu();
				}
			}
		}
		if ((fp = fopen("student achievement.txt", "w")) == NULL)//д��׼��
		{
			printf("\n�Բ��𣬴��ļ������ڣ�\n");
		}
		else
		{
			for (n = 0; n < i; n++)//�Զ�ȡʱ�õ�������(i)Ϊѭ�����ս����ѭ��
			{
				fprintf(fp, "%ld %s %ld %ld %ld %ld",c[n].num,c[n].name,c[n].chinese,c[n].math,c[n].english,c[n].synthesize);
			}
			system("cls");
			printf("\nϵͳ���Զ����������桭������\n");
			Sleep(1500);//ʱ��ͣ������,�����ڵ�λΪ:����
			TMenu();
		}
	}
	fclose(fp);
}
int AddInformation()//���ѧ����Ϣ
{
	char ch;
	FILE *fp;
	printf("����������ѧ���ģ�\n\n   ѧ��    ����     ϵ��      �༶  ���� \n");
	scanf("\n%10ld %10s %15s %10s %5ld", &d.num, d.name, d.department, d.Class, &d.age);//Ԥ������Ϣ����
	if ((fp = fopen("student information.txt", "ab")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڡ�\n");
	}
	else
	{
		printf("\n\n\n������¼������Ϣ��\n");
		printf("\n                       \n\n    ѧ��        ����          ϵ��        �༶     ���� \n");
		printf("\n%10ld %10s %15s %10s %5ld", d.num, d.name, d.department, d.Class, d.age);
		printf("\n\n\n\n\n\n\n                                                    1��ȷ�� 2��ȡ�����������˵�\n");
		ch = _getch();//�ж��Ƿ�¼��
		if (ch == '1')
		{
			fprintf(fp, "\n %10ld %10s %15s %10s %5ld", d.num, d.name, d.department, d.Class, d.age);//¼��
			fclose(fp);
			system("cls");
			printf("��Ϣ¼��ɹ���ϵͳ���Զ��������˵���������");
			Sleep(1300);
			system("cls");
			TMenu();
		}
		else if (ch == '2')
		{
			fclose(fp);
			system("cls");
			TMenu();
		}
	}
}
int AddAchievement()
{
	char ch;
	FILE *fp;
	printf("����������ѧ������Ϣ����Ӧ�ɼ���\n\n   ѧ��    ���� ���� ��ѧ Ӣ�� �ۺ�\n");
	scanf("\n%ld %s %ld %ld %ld %ld", &a.num,a.name,&a.chinese,&a.math,&a.english,&a.synthesize);//Ԥ������Ϣ����
	if ((fp = fopen("student achievement.txt", "ab")) == NULL)
	{
		printf("\n�Բ��𣬴��ļ������ڡ�\n");
	}
	else
	{
		printf("\n\n\n������¼���³ɼ���\n");
		printf("\n\n\n  ѧ��     ����  ���� ��ѧ  Ӣ��  �ۺ�\n");
		printf("\n%ld %s %-5ld %-5ld %-5ld %-5ld", a.num, a.name, a.chinese, a.math, a.english, a.synthesize);
		printf("\n\n\n\n\n\n\n                                                    1��ȷ�� 2��ȡ�����������˵�\n");
		ch = _getch();//�ж��Ƿ�¼��
		if (ch == '1')
		{
			fprintf(fp, "\n %ld %s %ld %ld %ld %ld", a.num, a.name, a.chinese, a.math, a.english, a.synthesize);//¼��
			fclose(fp);
			system("cls");
			printf("��Ϣ¼��ɹ���ϵͳ���Զ��������˵���������");
			Sleep(1300);
			system("cls");
			TMenu();
		}
		else if (ch == '2')
		{
			fclose(fp);
			system("cls");
			TMenu();
		}
	}
}
int AchieveMenu()//ѧ���ɼ���ѯ�Ӱ��
{
	char ch;
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                        ѧ���ɼ���ѯ                       *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    1����ѯ����ѧ���ɼ�                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    2���޸ĵ���ѧ���ɼ�                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    3����ѯȫ��ѧ���ɼ�                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("�밴���ּ�ѡ�����˵���                                    0�������ϼ�����");
	ch = _getch();
	if (ch == '1')
	{
		SearchAchieve();
	}
	else if (ch == '2')
	{
		system("cls");
		ReviseAchievement();
	}
	else if (ch == '3')
	{
		system("cls");
		printf("    ѧ��    ����     ����   ��ѧ   Ӣ��   �ۺ� �ܳɼ�");
		AchieveLoad();
		printf("\n\n\n\n\n\n0������");
		ch = _getch();
		if (ch == '0')
		{
			system("cls");
			SearchMenu();
		}
		else
		{
			system("cls");
			Exit();
		}
	}
	else if (ch == '0')
	{
		system("cls");
		TMenu();
	}
}
int SearchMenu()//ѧ����Ϣ��ѯ�Ӱ��
{
	char ch;
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                        ѧ����Ϣ��ѯ                       *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    1����ѯ����ѧ����Ϣ                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    2���޸ĵ���ѧ����Ϣ                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    3����ѯȫ��ѧ����Ϣ                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("�밴���ּ�ѡ�����˵���                                    0�������ϼ�����");
	ch = _getch();
	if (ch == '1')
	{
		SearchInformation();
	}
	else if (ch == '2')
	{
		system("cls");
		ReviseInformation();
	}
	else if (ch == '3')
	{
		system("cls");
		printf("     ѧ��        ����          ϵ��        �༶     ����");
		InfoLoad();
		printf("\n\n\n\n\n\n0������");
		ch = _getch();
		if (ch == '0')
		{
			system("cls");
			SearchMenu();
		}
		else
		{
			system("cls");
			Exit();
		}
	}
	else if (ch == '0')
	{
		system("cls");
		TMenu();
	}
}
int Teacher()//��ʦ��¼��֤
{
	char password[100], user[100], t;
	char ch;
	int i, l, n;
	printf("    \n\n\n\n\n\n\n\n                        ����ǰ�����������ѧ������ϵͳ\n\n\n");
	printf("                        �������¼�û�����");
	for (i = 0; (t = _getch()) != '\r'; i++)//_getch()��¼���������ַ�,�����뵽������
	{
		printf("*");
		user[i] = t;
	}
	user[i] = '\0';

	if (user[0] == 'a' && user[1] == 'd' && user[2] == 'm' && user[3] == 'i' && user[4] == 'n' && user[5] == '\0')//�������뷶Χ,��ֹ����adminasda����������ͨ����֤
	{
		printf("\n                        ���������¼���룺");
		for (i = 0; (t = _getch()) != '\r'; i++)
		{
			printf("*");
			password[i] = t;
		}
		password[i] = '\0';
		system("cls");
		if (password[0] == 'a' && password[1] == 'd' && password[2] == 'm' && password[3] == 'i' && password[4] == 'n' && password[5] == '\0')//�ж�������ַ���Ԥ���ַ��Ƿ�ƥ��
		{
			printf("����������ȷ��ϵͳ���ڵ�¼��\n");
			Sleep(900);
			system("cls");
			for (l = 0; l < 100;)
			{
				printf("�������ڼ����У����Ժ󡭡���������");
				l = l + 10;
				printf("%d%%", l);
				Sleep(100);
				system("cls");
			}
			TMenu();
		}
		else
		{
			system("cls");
			printf("�Բ��������������������������룺\n");
			Teacher();
		}
	}
	else
	{
		system("cls");
		printf("�Բ��𣬲����ڴ��û��������������룺\n");
		Teacher();
	}
}
int Student()//ѧ���˵�¼
{
	char password[100], user[100], t;
	char ch;
	int i, l, n;
	printf("    \n\n\n\n\n\n\n\n                        ����ǰ�����������ѧ������ϵͳ\n\n\n");
	printf("                        ����������ѧ�ţ�");
	for (i = 0; (t = _getch()) != '\r'; i++)
	{
		printf("*");
		user[i] = t;
	}
	user[i] = '\0';

	if (user[0] == '1' && user[1] == '2' && user[2] == '3' && user[3] == '4' && user[4] == '5' && user[5] == '6' && user[6] == '\0')
	{
		printf("\n                        �������������룺");
		for (i = 0; (t = _getch()) != '\r'; i++)
		{
			printf("*");
			password[i] = t;
		}
		password[i] = '\0';
		system("cls");
		if (password[0] == '1' && password[1] == '2' && password[2] == '3' && password[3] == '4' && password[4] == '5' && password[5] == '6' && password[6] == '\0')
		{
			printf("����������ȷ��ϵͳ���ڵ�¼��\n");
			Sleep(900);
			system("cls");
			for (l = 0; l < 100;)
			{
				printf("�������ڼ����У����Ժ󡭡���������");
				l = l + 5;
				printf("%d%%", l);
				Sleep(80);
				system("cls");
			}
			SMenu();
		}
		else
		{
			system("cls");
			printf("�Բ��������������������������룺\n");
			Student();
		}
	}
	else
	{
		system("cls");
		printf("�Բ��𣬲����ڴ��û������������룺\n");
		Student();
	}
}
int Visitor()//�ÿ�ϵͳ
{
	char ch;
	system("color d");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                     ��ӭʹ��  ϵͳ�ÿ�ģʽ                *          \n");
	printf("          *                                                           *          \n");
	printf("          *          1����ѯѧ����Ϣ            2�����ڷÿ�ģʽ       *          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("�밴���ּ�ѡ�����˵���                                      0���˳�ϵͳ");
	ch = _getch();
	if (ch == '1')
	{
		VisitorSearch();
	}
	else if (ch == '2')
	{
		AboutVisitor();
	}
	else if (ch == '0')
	{
		Exit();
	}
}
int TMenu()//��ʦϵͳ������
{
	char ch;
	system("color e");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                 ��ӭʹ��  ѧ������ϵͳ                    *          \n");
	printf("          *                    1��ѧ����Ϣ��ѯ                        *          \n");
	printf("          *                    2��ѧ���ɼ���ѯ                        *          \n");
	printf("          *                    3��ѧ����Ϣ¼��                        *          \n");
	printf("          *                    4��ѧ���ɼ�¼��                        *          \n");
	printf("          *                    5������ѧ������ϵͳ                    *          \n");
	printf("          *                    0���˳�ѧ������ϵͳ                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	ch = _getch();//�˵�ѡ��
	if (ch == '1')
	{
		SearchMenu();
	}
	if (ch == '2')
	{
		system("cls");
		AchieveMenu();
	}
	else if (ch == '3')
	{
		system("cls");
		AddInformation();
	}
	else if (ch == '4')
	{
		system("cls");
		AddAchievement();
	}
	else if (ch == '5')
	{
		About();
		ch = _getch();
		if (ch == '0')
		{
			system("cls");
			TMenu();
		}
	}
	else if (ch == '0')
	{		
		Exit();
	}
}
int SMenu()//ѧ���˵�������
{
	char ch;
	system("color e");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *                 ��ӭʹ��  ѧ������ϵͳ                    *          \n");
	printf("          *                    1����Ϣ��ѯ                            *          \n");
	printf("          *                    2���ɼ���ѯ                            *          \n");
	printf("          *                    3������ѧ������ϵͳ                    *          \n");
	printf("          *                    0���˳�ѧ������ϵͳ                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	ch = _getch();
	if (ch == '1')
	{
		STDInformation();
	}
	else if (ch == '2')
	{
		STDAchieve();
	}
	else if (ch == '3')
	{
		About();
		ch = _getch();
		if (ch == '0')
		{
			system("cls");
			SMenu();
		}
	}
	else if (ch == '0')
	{
		Exit();
	}
}
int About()//����������Ա������
{
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                   ����ѧ������ϵͳ                        *          \n");
	printf("          *          ������Ա��                                       *          \n");
	printf("          *                         �� X X                            *          \n");
	printf("          *                         ��   X                            *          \n");
	printf("          *                         �� X X                            *          \n");
	printf("          *                         �� X X                            *          \n");
	printf("          *                         �� X X                            *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("0������");
}
int AboutVisitor()
{
	char ch;
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *    ��ӭ�����ÿ�ģʽ����ģʽ������Ϊ���ҳ������ṩ��ѯ   *          \n");
	printf("          *ƽ̨����ֻ��������Ҫ��ѯ��ѧ�����룬���ɲ�ѯ����ѧ������� *          \n");
	printf("          *��У��Ϣ�����а����������ϼ���ĩ�ɼ��ȡ�                   *          \n");
	printf("          *    ��ģʽ�Խ��������ƣ���ҳ������ṩ���෽���ݵķ����� *          \n");
	printf("          *���������ҳ��Ǽ�ʱ�˽�ѧ������У��̬��                     *          \n");
	printf("          *                                                           *          \n");
	printf("          *                          ��ʵ��������͵����Ľ�ڶ��ѡ�_��*          \n");
	printf("          *************************************************************          \n");
	printf("�밴���ּ�ѡ�����˵���                                    0�������ϼ�����");
	ch = _getch();
	if (ch == '0')
	{
		system("cls");
		Visitor();
	}
}
int Exit()//�����˳�����
{
	system("cls");
	system("color 7");
	printf("��л����ʹ�ã��ټ���\n");
	_getch();
}
int main()//����������
{
	char ch;
	HideCursor();//�������ع��
	system("color 9");//��ɫ����
    printf("    \n\n\n\n\n\n\n\n                        ����ǰ�����������ѧ������ϵͳ\n\n");
	printf("                        ��ѡ�����ĵ�¼��ʽ��\n\n");
	printf("                                 1��ѧ����¼\n                                 2����ʦ��¼\n                                 3���ÿ͵�¼");
	printf("\n\n\n\n\n\n\n\n\n0���˳�ѧ������ϵͳ");
	ch = _getch();
	if (ch == '1')
	{
		system("cls");
		system("color a");
		Student();
	}
	if (ch == '2')
	{
		system("cls");
		system("color c");
		Teacher();
	}
	if (ch == '3')
	{
		system("cls");
		Visitor();
	}
	if (ch == '0')
	{
		Exit();
	}
}





/*��������:
 system("cls")�����Ļ����ʾ����������
 Sleep(400)����ͣ��ʱ��,������Ϊ���뵥λ
 system("color xx")��ɫ����,������xx����Ϊ������ɫ����ͱ�����ɫ���룬��16����ɫ����
 */
