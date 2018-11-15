/*该系统的学生登录帐号密码统一为：123456
          教师登录帐号密码统一为：admin */
/*文本文件统一存放在*.c根目录下*/
#include "stdio.h"
#include "conio.h"
#include "windows.h"
void HideCursor()//清除光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
struct information//定义学生信息结构体
{
	long int num,age;
	char name[200], Class[200],department[200];
};
struct information s[100];
struct information d;
struct Achievement//定义学生成绩结构体
{
	char name[100];
	long int num, chinese, english, math, synthesize, sum;
};
struct Achievement c[100];
struct Achievement a;
int InfoLoad()//载入全部学生信息
{
	FILE * fp;
	int i;
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在。\n");
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
int AchieveLoad()//载入全部学生成绩
{
	FILE * fp;
	int i;
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在。\n");
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
int SearchInformation()//搜索单个学生信息
{
	FILE *fp;
	int num, i, j, flag=0;
	char ch;
	system("cls");//清空屏幕
	printf("请输入需要搜索的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			if (num == s[i].num)//查找此学生信息
			{
				flag = 1;//判断是否存在,存在则为1
				system("cls");
				printf("您所搜索的结果为：\n");
				printf("    学号        姓名          系部        班级     年龄");
				printf("\n%10ld %10s %15s %10s %5ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
				break;
			}
		}
		if (flag==0)//判断是否存在,不存在为0
		{
			printf("\n对不起，没有找到该学生的相关信息！\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         是否继续搜索：1、继续    0、返回主菜单");
		ch = _getch();//选择
		if (ch == '1')
		{
			system("cls");
			SearchInformation();//返回
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
	system("cls");//清空屏幕
	printf("请输入需要查询的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			if (num == s[i].num)//查找此学生信息
			{
				flag = 1;//判断是否存在,存在则为1
				system("cls");
				printf("您所搜索的结果为：\n");
				printf("    学号        姓名          系部        班级     年龄");
				printf("\n%10ld %10s %15s %10s %5ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
				break;
			}
		}
		if (flag == 0)//判断是否存在,不存在为0
		{
			printf("\n对不起，没有找到输入的相关信息！\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         是否继续搜索：1、继续    0、返回主菜单");
		ch = _getch();//选择
		if (ch == '1')
		{
			system("cls");
			STDInformation();//返回
		}
		else if (ch == '0')
		{
			system("cls");
			SMenu();
		}
	}
}
int SearchAchieve()//搜索单个学生成绩
{
	FILE *fp;
	int num, i, j, flag = 0;
	char ch;
	system("cls");
	printf("请输入需要搜索的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num)//搜索学号是否匹配
			{
				flag = 1;
				system("cls");
				printf("您所搜索的结果为：\n");
				printf("    学号    姓名     语文   数学   英语   综合 总成绩");
				printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
				break;
			}
		}
		if (flag == 0)
		{
			printf("\n对不起，没有找到该学生的相关信息！\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         是否继续搜索：1、继续    0、返回主菜单");
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
	printf("请输入需要搜索的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num)//搜索学号是否匹配
			{
				flag = 1;
				system("cls");
				printf("您所搜索的结果为：\n");
				printf("    学号    姓名     语文   数学   英语   综合 总成绩");
				printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
				break;
			}
		}
		if (flag == 0)
		{
			printf("\n对不起，没有找到该学生的相关信息！\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n                                         是否继续搜索：1、继续    0、返回主菜单");
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
	printf("请输入需要搜索的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		i = 0;
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, s[i].name, s[i].department, s[i].Class, &s[i].age);
			if (num == s[i].num)//查找此学生信息
			{
				system("cls");
				flag = 1;//判断是否存在,存在则为1
				printf("您所搜索的结果如下：\n\n\n\n");
				printf("该名学生的基本信息为：\n\n");
				printf("    学号        姓名          系部        班级     年龄");
				printf("\n%10ld %10s %15s %10s %5ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
				break;
			}
		}
	}
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)
		{
			fscanf(fp, "%10ld %10s %10ld %10ld %10ld %10ld", &c[i].num, c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num)//搜索学号是否匹配
			{
				flag = 1;
				printf("\n\n\n\n该名学生的期末成绩如下：\n\n");
				printf("    学号    姓名     语文   数学   英语   综合 总成绩");
				printf("\n %5ld %5s %6ld %6ld %6ld %6ld %6ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize, c[i].sum = c[i].chinese + c[i].math + c[i].english + c[i].synthesize);
				break;
			}
		}	
	}
	if (flag == 0)//判断是否存在,不存在为0
	{
		printf("\n对不起，没有找到该学生的相关信息！\n");
	}
	printf("\n\n\n\n\n\n\n\n\n\n                                         是否继续搜索：1、继续    0、返回主菜单");
	ch = _getch();//选择
	if (ch == '1')
	{
		system("cls");
		VisitorSearch();//返回
	}
	else if (ch == '0')
	{
		system("cls");
		Visitor();
	}
}
int ReviseInformation()//修改学生信息
{
	FILE *fp;
	int num, i, n, flag = 0;
	char ch;
	printf("请输入需要搜索的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student information.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)//搜索全部内容
		{
			fscanf(fp, "%ld %s %s %s %ld", &s[i].num, &s[i].name, &s[i].department, &s[i].Class, &s[i].age);//将内容提取到内存中保存
			if (num == s[i].num && flag == 0)//查找学生
			{
				system("cls");
				printf("您所搜索的结果为：\n");
				printf("                            \n   学号    姓名     系部      班级  年龄\n");
				printf("\n%ld %s %s %s %ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);//显示修改前的信息
				printf("\n\n\n\n\n\n\n\n\n\n                                  是否继续修改以上信息？     1、修改    2、返回\n");
				ch = _getch();
				if (ch == '1')
				{
					system("cls");
					printf("请依次输入需要修改的学生信息：\n 姓名     系部      班级  年龄\n");
					scanf("%s %s %s %ld", &s[i].name, &s[i].department, &s[i].Class, &s[i].age);
					printf("\n\n\n\n\n您即将更改该信息，新信息为：\n");
					printf("                            \n  学号     姓名     系部      班级  年龄\n");
					printf("\n%ld %s %s %s %ld\n", s[i].num, s[i].name, s[i].department, s[i].Class, s[i].age);
					printf("\n\n\n\n\n\n\n\n\n\n                                  是否确认修改以上信息？     1、修改    0、返回\n");
					ch = _getch();//判断是否修改信息
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
		if ((fp = fopen("student information.txt", "w")) == NULL)//写入准备
		{
			printf("\n对不起，此文件不存在！\n");
		}
		else
		{
			for (n = 0; n < i; n++)//以读取时得到的人数(i)为循环的终结进行循环
			{
				fprintf(fp, "%10ld %10s %15s %10s %5ld", s[n].num, s[n].name, s[n].department, s[n].Class, s[n].age);//将先前内存中保存的和修改后的全部学生信息进行覆盖写入
			}
			system("cls");
			printf("\n系统将自动返回主界面…………\n");
			Sleep(1500);//时间停留代码,括号内单位为:毫秒
			TMenu();
		}
	}
	fclose(fp);
}
int ReviseAchievement()//修改学生成绩
{
	FILE *fp;
	int num, i, n, flag = 0;
	char ch;
	printf("请输入需要搜索的学号:");
	scanf("%d", &num);
	if ((fp = fopen("student achievement.txt", "r")) == NULL)
	{
		printf("\n对不起，此文件不存在！\n");
	}
	else
	{
		for (i = 0; !feof(fp); i++)//搜索全部内容
		{
			fscanf(fp, "%ld %s %ld %ld %ld %ld", &c[i].num, &c[i].name, &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
			if (num == c[i].num && flag == 0)//查找学生
			{
				system("cls");
				printf("您所搜索的结果为：\n");
				printf("   学号     姓名    语文 数学  英语  综合");
				printf("\n %5ld %5s %5ld %5ld %5ld %5ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize);
				printf("\n\n\n\n\n\n\n\n\n\n                                  是否继续修改以上信息？     1、修改    2、返回\n");
				ch = _getch();
				if (ch == '1')
				{
					system("cls");
					printf("请依次输入需要修改的学生成绩：\n语文 数学 英语 综合\n");
					scanf("%ld %ld %ld %ld", &c[i].chinese, &c[i].math, &c[i].english, &c[i].synthesize);
					printf("\n\n\n\n\n您即将更改该信息，新信息为：\n");
					printf("\n  学号      姓名   语文   数学  英语  综合 \n");
					printf("\n %ld %5s %5ld %5ld %5ld %5ld", c[i].num, c[i].name, c[i].chinese, c[i].math, c[i].english, c[i].synthesize);
					printf("\n\n\n\n\n\n\n\n\n\n                                  是否确认修改以上信息？     1、修改    0、返回\n");
					ch = _getch();//判断是否修改信息
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
		if ((fp = fopen("student achievement.txt", "w")) == NULL)//写入准备
		{
			printf("\n对不起，此文件不存在！\n");
		}
		else
		{
			for (n = 0; n < i; n++)//以读取时得到的人数(i)为循环的终结进行循环
			{
				fprintf(fp, "%ld %s %ld %ld %ld %ld",c[n].num,c[n].name,c[n].chinese,c[n].math,c[n].english,c[n].synthesize);
			}
			system("cls");
			printf("\n系统将自动返回主界面…………\n");
			Sleep(1500);//时间停留代码,括号内单位为:毫秒
			TMenu();
		}
	}
	fclose(fp);
}
int AddInformation()//添加学生信息
{
	char ch;
	FILE *fp;
	printf("请依次输入学生的：\n\n   学号    姓名     系部      班级  年龄 \n");
	scanf("\n%10ld %10s %15s %10s %5ld", &d.num, d.name, d.department, d.Class, &d.age);//预存新信息内容
	if ((fp = fopen("student information.txt", "ab")) == NULL)
	{
		printf("\n对不起，此文件不存在。\n");
	}
	else
	{
		printf("\n\n\n您即将录入新信息：\n");
		printf("\n                       \n\n    学号        姓名          系部        班级     年龄 \n");
		printf("\n%10ld %10s %15s %10s %5ld", d.num, d.name, d.department, d.Class, d.age);
		printf("\n\n\n\n\n\n\n                                                    1、确认 2、取消并返回主菜单\n");
		ch = _getch();//判断是否录入
		if (ch == '1')
		{
			fprintf(fp, "\n %10ld %10s %15s %10s %5ld", d.num, d.name, d.department, d.Class, d.age);//录入
			fclose(fp);
			system("cls");
			printf("信息录入成功！系统将自动返回主菜单…………");
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
	printf("请依次输入学生的信息及对应成绩：\n\n   学号    姓名 语文 数学 英语 综合\n");
	scanf("\n%ld %s %ld %ld %ld %ld", &a.num,a.name,&a.chinese,&a.math,&a.english,&a.synthesize);//预存新信息内容
	if ((fp = fopen("student achievement.txt", "ab")) == NULL)
	{
		printf("\n对不起，此文件不存在。\n");
	}
	else
	{
		printf("\n\n\n您即将录入新成绩：\n");
		printf("\n\n\n  学号     姓名  语文 数学  英语  综合\n");
		printf("\n%ld %s %-5ld %-5ld %-5ld %-5ld", a.num, a.name, a.chinese, a.math, a.english, a.synthesize);
		printf("\n\n\n\n\n\n\n                                                    1、确认 2、取消并返回主菜单\n");
		ch = _getch();//判断是否录入
		if (ch == '1')
		{
			fprintf(fp, "\n %ld %s %ld %ld %ld %ld", a.num, a.name, a.chinese, a.math, a.english, a.synthesize);//录入
			fclose(fp);
			system("cls");
			printf("信息录入成功！系统将自动返回主菜单…………");
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
int AchieveMenu()//学生成绩查询子版块
{
	char ch;
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                        学生成绩查询                       *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    1、查询单个学生成绩                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    2、修改单个学生成绩                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    3、查询全部学生成绩                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("请按数字键选择进入菜单：                                    0、返回上级界面");
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
		printf("    学号    姓名     语文   数学   英语   综合 总成绩");
		AchieveLoad();
		printf("\n\n\n\n\n\n0、返回");
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
int SearchMenu()//学生信息查询子版块
{
	char ch;
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                        学生信息查询                       *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    1、查询单个学生信息                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    2、修改单个学生信息                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *                    3、查询全部学生信息                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("请按数字键选择进入菜单：                                    0、返回上级界面");
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
		printf("     学号        姓名          系部        班级     年龄");
		InfoLoad();
		printf("\n\n\n\n\n\n0、返回");
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
int Teacher()//教师登录验证
{
	char password[100], user[100], t;
	char ch;
	int i, l, n;
	printf("    \n\n\n\n\n\n\n\n                        您当前正在请求访问学籍管理系统\n\n\n");
	printf("                        请输入登录用户名：");
	for (i = 0; (t = _getch()) != '\r'; i++)//_getch()记录键盘输入字符,并载入到数组中
	{
		printf("*");
		user[i] = t;
	}
	user[i] = '\0';

	if (user[0] == 'a' && user[1] == 'd' && user[2] == 'm' && user[3] == 'i' && user[4] == 'n' && user[5] == '\0')//限制输入范围,防止类似adminasda这样的输入通过验证
	{
		printf("\n                        请您输入登录密码：");
		for (i = 0; (t = _getch()) != '\r'; i++)
		{
			printf("*");
			password[i] = t;
		}
		password[i] = '\0';
		system("cls");
		if (password[0] == 'a' && password[1] == 'd' && password[2] == 'm' && password[3] == 'i' && password[4] == 'n' && password[5] == '\0')//判断输入的字符和预存字符是否匹配
		{
			printf("密码输入正确，系统正在登录。\n");
			Sleep(900);
			system("cls");
			for (l = 0; l < 100;)
			{
				printf("程序正在加载中，请稍后………………");
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
			printf("对不起，您输入的密码错误！请重新输入：\n");
			Teacher();
		}
	}
	else
	{
		system("cls");
		printf("对不起，不存在此用户名，请重新输入：\n");
		Teacher();
	}
}
int Student()//学生端登录
{
	char password[100], user[100], t;
	char ch;
	int i, l, n;
	printf("    \n\n\n\n\n\n\n\n                        您当前正在请求访问学籍管理系统\n\n\n");
	printf("                        请输入您的学号：");
	for (i = 0; (t = _getch()) != '\r'; i++)
	{
		printf("*");
		user[i] = t;
	}
	user[i] = '\0';

	if (user[0] == '1' && user[1] == '2' && user[2] == '3' && user[3] == '4' && user[4] == '5' && user[5] == '6' && user[6] == '\0')
	{
		printf("\n                        请输入您的密码：");
		for (i = 0; (t = _getch()) != '\r'; i++)
		{
			printf("*");
			password[i] = t;
		}
		password[i] = '\0';
		system("cls");
		if (password[0] == '1' && password[1] == '2' && password[2] == '3' && password[3] == '4' && password[4] == '5' && password[5] == '6' && password[6] == '\0')
		{
			printf("密码输入正确，系统正在登录。\n");
			Sleep(900);
			system("cls");
			for (l = 0; l < 100;)
			{
				printf("程序正在加载中，请稍后………………");
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
			printf("对不起，您输入的密码错误！请重新输入：\n");
			Student();
		}
	}
	else
	{
		system("cls");
		printf("对不起，不存在此用户，请重新输入：\n");
		Student();
	}
}
int Visitor()//访客系统
{
	char ch;
	system("color d");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                     欢迎使用  系统访客模式                *          \n");
	printf("          *                                                           *          \n");
	printf("          *          1、查询学生信息            2、关于访客模式       *          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("请按数字键选择进入菜单：                                      0、退出系统");
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
int TMenu()//教师系统主界面
{
	char ch;
	system("color e");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                 欢迎使用  学籍管理系统                    *          \n");
	printf("          *                    1、学生信息查询                        *          \n");
	printf("          *                    2、学生成绩查询                        *          \n");
	printf("          *                    3、学生信息录入                        *          \n");
	printf("          *                    4、学生成绩录入                        *          \n");
	printf("          *                    5、关于学籍管理系统                    *          \n");
	printf("          *                    0、退出学籍管理系统                    *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	ch = _getch();//菜单选择
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
int SMenu()//学生菜单主界面
{
	char ch;
	system("color e");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *                 欢迎使用  学籍管理系统                    *          \n");
	printf("          *                    1、信息查询                            *          \n");
	printf("          *                    2、成绩查询                            *          \n");
	printf("          *                    3、关于学籍管理系统                    *          \n");
	printf("          *                    0、退出学籍管理系统                    *          \n");
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
int About()//关于制作人员主界面
{
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                   关于学籍管理系统                        *          \n");
	printf("          *          制作人员：                                       *          \n");
	printf("          *                         于 X X                            *          \n");
	printf("          *                         邓   X                            *          \n");
	printf("          *                         颜 X X                            *          \n");
	printf("          *                         甘 X X                            *          \n");
	printf("          *                         张 X X                            *          \n");
	printf("          *                                                           *          \n");
	printf("          *************************************************************          \n");
	printf("0、返回");
}
int AboutVisitor()
{
	char ch;
	system("cls");
	printf("\n\n          *************************************************************          \n");
	printf("          *                                                           *          \n");
	printf("          *                                                           *          \n");
	printf("          *    欢迎来到访客模式，本模式致力于为广大家长朋友提供查询   *          \n");
	printf("          *平台，您只需输入所要查询的学生编码，即可查询该名学生的相关 *          \n");
	printf("          *在校信息。其中包括基本资料及期末成绩等。                   *          \n");
	printf("          *    本模式仍将不断完善，向家长朋友提供更多方便快捷的服务渠 *          \n");
	printf("          *道，帮助家长们及时了解学生的在校动态。                     *          \n");
	printf("          *                                                           *          \n");
	printf("          *                          其实就是作者偷懒编的借口而已←_←*          \n");
	printf("          *************************************************************          \n");
	printf("请按数字键选择进入菜单：                                    0、返回上级界面");
	ch = _getch();
	if (ch == '0')
	{
		system("cls");
		Visitor();
	}
}
int Exit()//程序退出界面
{
	system("cls");
	system("color 7");
	printf("感谢您的使用，再见！\n");
	_getch();
}
int main()//主函数调用
{
	char ch;
	HideCursor();//引用隐藏光标
	system("color 9");//颜色代码
    printf("    \n\n\n\n\n\n\n\n                        您当前正在请求访问学籍管理系统\n\n");
	printf("                        请选择您的登录方式：\n\n");
	printf("                                 1、学生登录\n                                 2、教师登录\n                                 3、访客登录");
	printf("\n\n\n\n\n\n\n\n\n0、退出学籍管理系统");
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





/*常见代码:
 system("cls")清空屏幕中显示的所有内容
 Sleep(400)程序停留时间,括号内为毫秒单位
 system("color xx")颜色代码,括号内xx依次为字体颜色代码和背景颜色代码，有16种颜色类型
 */
