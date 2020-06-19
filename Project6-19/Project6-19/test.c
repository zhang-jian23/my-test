#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define LEN sizeof(struct financial)
#define FFORMAT "%-8d%-15s%-10d%-10d%-12.2f%-12.2f%-12.2f\n"
#define DATA member[i].num,member[i].name,member[i].year,member[i].month,member[i].income,member[i].output,member[i].total
struct financial                                     //定义家庭成员信息
{
	int num;                                    //编号
	char name[15];                              //家庭成员姓名
	int year;                                   //年份
	int month;                                //月份
	float income;                             //收入	                       
	float output;                            //支出
	float total;                             //总金额
};
struct financial member[50];                      //定义结构体数组
void menu();                                 //主界面
void in();                                  //录入家庭成员收支信息
void show();                               //显示家庭成员收支信息
void del();                               //删除家庭成员收支信息
void modify();                           //修改家庭成员收支信息                            
void total();                           //计算家庭成员总收入
void search();                         //查找家庭成员收支信息
/*****************
功能描述：主界面
参数描述：
参数1：n
返回值：0
调用关系：
该函数会调用in()、search()、del()、modify()、total()函数
作者：孙培瑶
修改日期：2020.6.18
**************/
int main()
{
	int n;
	menu();
	scanf("%d", &n);                      //输入数字选择功能
	while (n)
	{
		switch (n)
		{
		case 1:
			in();                     //调用录入家庭成员信息函数
			break;
		case 2:
			search();                //查找家庭成员信息函数
			break;
		case 3:
			del();                  //调用删除家庭成员信息函数
			break;
		case 4:
			modify();              //调用修改家庭成员信息函数
			break;
		case 5:
			total();                      //调用汇总函数
			break;
		default:break;
		}
		printf("按任意键返回主菜单:\n");
		getch();
		menu();                          //执行完功能再次显示菜单界面
		scanf("%d", &n);
	}
	return 0;
}
void menu()
{
	system("cls");
	printf("|-------------------------------------------------|\n");
	printf("|--------------------家庭财务信息系统-------------|\n");
	printf("|                    0. 退出                      |\n");
	printf("|                    1. 录入信息                  |\n");
	printf("|                    2. 查找信息                  |\n");
	printf("|                    3. 删除信息                  |\n");
	printf("|                    4. 修改信息                  |\n");
	printf("|                    5. 统计信息                  |\n");
	printf("|-------------------------------------------------|\n");
	printf("选择(0-5):");
}
/*****************
功能描述：录入家庭成员收支信息
参数描述：
参数1：i-变量
参数2：m-已录入的家庭成员编号
返回值：xxx
调用关系：
该函数被menu()函数调用，该函数会调用show()、system()函数
作者：孙培瑶
修改日期：2020.6.18
**************/
void in()                        //录入家庭成员信息
{
	int i, m = 0;
	char ch[2];
	FILE *fp;
	if ((fp = fopen("家庭财务管理系统", "ab+")) == NULL)
	{
		printf("不能打开文件!\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&member[m], LEN, 1, fp) == 1)
			m++;                                 //统计当前记录条数
	}
	fclose(fp);
	if (m == 0)
		printf("没有找到!\n");
	else
	{
		//system("cls");
		show();                                 //调用show函数，显示原有信息
	}
	if ((fp = fopen("家庭财务管理系统", "wb")) == NULL)
	{
		printf("不能打开文件!\n");
		return;
	}
	for (i = 0; i<m; i++)
		fwrite(&member[i], LEN, 1, fp);         //向指定的磁盘文件写入信息
	printf("是否输入?(y/n):");
	scanf("%s", ch);
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)   //判断是否要录入新信息
	{
		printf("编号:");
		scanf("%d", &member[m].num);                   //输入家庭成员编号
		for (i = 0; i<m; i++)
		if (member[i].num == member[m].num)
		{
			printf("该记录已经存在，按任意键继续!");
			getch();
			fclose(fp);
			return;
		}
		printf("家庭成员姓名:");
		scanf("%s", member[m].name);                          //输入家庭成员姓名

		printf("请输入年份:");
		scanf("%d", &member[m].year);                        //输入年份
		printf("请输入月份:");
		scanf("%d", &member[m].month);                    //输入月份
		printf("请输入收入:");
		scanf("%f", &member[m].income);                   //输入收入
		printf("请输入支出:");
		scanf("%f", &member[m].output);                  //输入支出

		member[m].total = member[m].income - member[m].output;                   //汇总


		if (fwrite(&member[m], LEN, 1, fp) != 1)                                  //将新录入的信息写入指定的磁盘文件
		{
			printf("不能保存!");
			getch();
		}
		else
		{
			printf("%s 已经保存!\n", member[m].name);
			m++;
		}
		printf("是否继续?(y/n):");
		scanf("%s", ch);
	}
	fclose(fp);
	printf("OK!\n");
}
/*****************
功能描述：显示信息
参数描述：
参数1：i
参数2：m
...
返回值：输出信息
调用关系：
该函数被in()函数调用
作者：孙培瑶
修改日期：2020.6.18
**************/
void show()
{
	FILE *fp;
	int i, m = 0;
	fp = fopen("家庭财务管理系统", "ab+");
	while (!feof(fp))
	{
		if (fread(&member[m], LEN, 1, fp) == 1)
			m++;
	}
	fclose(fp);
	printf("编号    成员         年份         月份       收入      支出      总金额 \t\n");

	for (i = 0; i<m; i++)
	{
		printf(FFORMAT, DATA);
	}
}
/*****************
功能描述：删除家庭成员收支信息
参数描述：
参数1：i-变量
参数2：j-记录的条数
参数3：m-编号数
参数4：snum-变量
返回值：将更改后的记录重新写入指定的磁盘文件中
调用关系：
该函数被menu()函数调用
作者：
修改日期：
**************/
void del()
{
	FILE *fp;
	int snum, i, j, m = 0;
	char ch[2];
	if ((fp = fopen("家庭财务管理系统", "ab+")) == NULL)
	{
		printf("不能打开文件\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;
	fclose(fp);
	if (m == 0)
	{
		printf("没有记录!\n");
		return;
	}
	printf("请输入编号:");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
	if (snum == member[i].num)
		break;
	if (i == m)
	{
		printf("没有找到!");

		return;
	}
	printf("已经找到该记录，是否删除?(y/n)");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)                           //判断是否要进行删除
	{
		for (j = i; j<m; j++)
			member[j] = member[j + 1];                                 //将后一个记录移到前一个记录的位置
		m--;                                                        //记录的总个数减1
		printf("成功删除!\n");
	}
	if ((fp = fopen("家庭财务管理系统", "wb")) == NULL)
	{
		printf("不能打开!\n");
		return;
	}
	for (j = 0; j<m; j++)                                         //将更改后的记录重新写入指定的磁盘文件中
	if (fwrite(&member[j], LEN, 1, fp) != 1)
	{
		printf("不能保存!\n");
		getch();
	}
	fclose(fp);
}
/*****************
功能描述：查找家庭成员收支信息
参数描述：
参数1：i
参数2：m-编号个数
参数3：snum
返回值：显示信息或"没有找到相应的记录!"
调用关系：
该函数被menu()函数调用
作者：
修改日期：2020.6.18
**************/
void search()
{
	FILE *fp;
	int snum, i, m = 0;
	char ch[2];
	if ((fp = fopen("家庭财务管理系统", "ab+")) == NULL)
	{
		printf("不能打开文件\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;
	fclose(fp);
	if (m == 0)
	{
		printf("没有记录!\n");
		return;
	}
	printf("请输入编号:");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
	if (snum == member[i].num)
	{
		printf("已经找到该记录，是否显示?(y/n)");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
		{
			printf("编号    成员       年份      月份      收入        支出        总金额\t\n");
			printf(FFORMAT, DATA);
			break;
		}
		else
			return;
	}
	if (i == m)
		printf("没有找到相应的记录!\n");
}
/*****************
功能描述：修改家庭成员收支信息
参数描述：
参数1：i-变量
参数2：j-记录的条数
参数3：m-编号数
参数4：snum-变量
返回值：“保存成功”或“不能保存”
调用关系：
该函数被menu()函数调用
作者：
修改日期：2020.6.18
**************/
void modify()
{
	FILE *fp;
	int i, j, m = 0, snum;
	char ch[2];

	if ((fp = fopen("家庭财务管理系统", "ab+")) == NULL)
	{
		printf("不能打开文件!\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;
	if (m == 0)
	{
		printf("没有记录!\n");
		fclose(fp);
		return;
	}
	printf("请输入要修改的记录信息的编号!\n");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
	if (snum == member[i].num)                   //检索记录中是否有要修改的信息                         
	{
		printf("已经找到该记录，是否修改?(y/n)\n");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)

		{
			printf("家庭成员姓名:");
			scanf("%s", member[i].name);                         //输入家庭成员姓名
			printf("请输入年份:");
			scanf("%d", &member[i].year);                        //输入年份
			printf("请输入月份:");
			scanf("%d", &member[i].month);                     //输入月份

			printf("请输入收入:");
			scanf("%f", &member[i].income);                  //输入收入
			printf("请输入支出:");
			scanf("%f", &member[i].output);                //输入支出
			member[i].total = member[i].income - member[i].output;                //汇总

			printf("保存成功!");
		}
		else
			return;

	}
	else
	{
		printf("没有找到!");
		return;
	}
	if ((fp = fopen("家庭财务管理系统", "wb")) == NULL)
	{
		printf("不能打开文件!\n");
		return;
	}
	for (j = 0; j<m; j++)                        //将新修改的信息写入指定的磁盘文件中
	if (fwrite(&member[j], LEN, 1, fp) != 1)
	{
		printf("不能保存!");
	}
	fclose(fp);
}
/*****************
功能描述：查找家庭成员收支信息
参数描述：
参数1：m
参数2：xxx
返回值：信息个数以及信息内容
调用关系：
该函数被menu()函数调用，该函数会调用show()函数
作者：
修改日期：2020.6.18
**************/
void total()                                    // 统计
{
	FILE *fp;
	int m = 0;
	if ((fp = fopen("家庭财务管理系统", "ab+")) == NULL)
	{
		printf("不能打开记录!\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;                               //统计记录个数
	if (m == 0)
	{
		printf("没有记录!\n");
		fclose(fp);
		return;
	}
	printf("一共有 %d 条记录!\n", m);             //将统计的个数输出
	show();
	fclose(fp);
}
