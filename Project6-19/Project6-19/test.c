#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define LEN sizeof(struct financial)
#define FFORMAT "%-8d%-15s%-10d%-10d%-12.2f%-12.2f%-12.2f\n"
#define DATA member[i].num,member[i].name,member[i].year,member[i].month,member[i].income,member[i].output,member[i].total
struct financial                                     //�����ͥ��Ա��Ϣ
{
	int num;                                    //���
	char name[15];                              //��ͥ��Ա����
	int year;                                   //���
	int month;                                //�·�
	float income;                             //����	                       
	float output;                            //֧��
	float total;                             //�ܽ��
};
struct financial member[50];                      //����ṹ������
void menu();                                 //������
void in();                                  //¼���ͥ��Ա��֧��Ϣ
void show();                               //��ʾ��ͥ��Ա��֧��Ϣ
void del();                               //ɾ����ͥ��Ա��֧��Ϣ
void modify();                           //�޸ļ�ͥ��Ա��֧��Ϣ                            
void total();                           //�����ͥ��Ա������
void search();                         //���Ҽ�ͥ��Ա��֧��Ϣ
/*****************
����������������
����������
����1��n
����ֵ��0
���ù�ϵ��
�ú��������in()��search()��del()��modify()��total()����
���ߣ�������
�޸����ڣ�2020.6.18
**************/
int main()
{
	int n;
	menu();
	scanf("%d", &n);                      //��������ѡ����
	while (n)
	{
		switch (n)
		{
		case 1:
			in();                     //����¼���ͥ��Ա��Ϣ����
			break;
		case 2:
			search();                //���Ҽ�ͥ��Ա��Ϣ����
			break;
		case 3:
			del();                  //����ɾ����ͥ��Ա��Ϣ����
			break;
		case 4:
			modify();              //�����޸ļ�ͥ��Ա��Ϣ����
			break;
		case 5:
			total();                      //���û��ܺ���
			break;
		default:break;
		}
		printf("��������������˵�:\n");
		getch();
		menu();                          //ִ���깦���ٴ���ʾ�˵�����
		scanf("%d", &n);
	}
	return 0;
}
void menu()
{
	system("cls");
	printf("|-------------------------------------------------|\n");
	printf("|--------------------��ͥ������Ϣϵͳ-------------|\n");
	printf("|                    0. �˳�                      |\n");
	printf("|                    1. ¼����Ϣ                  |\n");
	printf("|                    2. ������Ϣ                  |\n");
	printf("|                    3. ɾ����Ϣ                  |\n");
	printf("|                    4. �޸���Ϣ                  |\n");
	printf("|                    5. ͳ����Ϣ                  |\n");
	printf("|-------------------------------------------------|\n");
	printf("ѡ��(0-5):");
}
/*****************
����������¼���ͥ��Ա��֧��Ϣ
����������
����1��i-����
����2��m-��¼��ļ�ͥ��Ա���
����ֵ��xxx
���ù�ϵ��
�ú�����menu()�������ã��ú��������show()��system()����
���ߣ�������
�޸����ڣ�2020.6.18
**************/
void in()                        //¼���ͥ��Ա��Ϣ
{
	int i, m = 0;
	char ch[2];
	FILE *fp;
	if ((fp = fopen("��ͥ�������ϵͳ", "ab+")) == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&member[m], LEN, 1, fp) == 1)
			m++;                                 //ͳ�Ƶ�ǰ��¼����
	}
	fclose(fp);
	if (m == 0)
		printf("û���ҵ�!\n");
	else
	{
		//system("cls");
		show();                                 //����show��������ʾԭ����Ϣ
	}
	if ((fp = fopen("��ͥ�������ϵͳ", "wb")) == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	for (i = 0; i<m; i++)
		fwrite(&member[i], LEN, 1, fp);         //��ָ���Ĵ����ļ�д����Ϣ
	printf("�Ƿ�����?(y/n):");
	scanf("%s", ch);
	while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)   //�ж��Ƿ�Ҫ¼������Ϣ
	{
		printf("���:");
		scanf("%d", &member[m].num);                   //�����ͥ��Ա���
		for (i = 0; i<m; i++)
		if (member[i].num == member[m].num)
		{
			printf("�ü�¼�Ѿ����ڣ������������!");
			getch();
			fclose(fp);
			return;
		}
		printf("��ͥ��Ա����:");
		scanf("%s", member[m].name);                          //�����ͥ��Ա����

		printf("���������:");
		scanf("%d", &member[m].year);                        //�������
		printf("�������·�:");
		scanf("%d", &member[m].month);                    //�����·�
		printf("����������:");
		scanf("%f", &member[m].income);                   //��������
		printf("������֧��:");
		scanf("%f", &member[m].output);                  //����֧��

		member[m].total = member[m].income - member[m].output;                   //����


		if (fwrite(&member[m], LEN, 1, fp) != 1)                                  //����¼�����Ϣд��ָ���Ĵ����ļ�
		{
			printf("���ܱ���!");
			getch();
		}
		else
		{
			printf("%s �Ѿ�����!\n", member[m].name);
			m++;
		}
		printf("�Ƿ����?(y/n):");
		scanf("%s", ch);
	}
	fclose(fp);
	printf("OK!\n");
}
/*****************
������������ʾ��Ϣ
����������
����1��i
����2��m
...
����ֵ�������Ϣ
���ù�ϵ��
�ú�����in()��������
���ߣ�������
�޸����ڣ�2020.6.18
**************/
void show()
{
	FILE *fp;
	int i, m = 0;
	fp = fopen("��ͥ�������ϵͳ", "ab+");
	while (!feof(fp))
	{
		if (fread(&member[m], LEN, 1, fp) == 1)
			m++;
	}
	fclose(fp);
	printf("���    ��Ա         ���         �·�       ����      ֧��      �ܽ�� \t\n");

	for (i = 0; i<m; i++)
	{
		printf(FFORMAT, DATA);
	}
}
/*****************
����������ɾ����ͥ��Ա��֧��Ϣ
����������
����1��i-����
����2��j-��¼������
����3��m-�����
����4��snum-����
����ֵ�������ĺ�ļ�¼����д��ָ���Ĵ����ļ���
���ù�ϵ��
�ú�����menu()��������
���ߣ�
�޸����ڣ�
**************/
void del()
{
	FILE *fp;
	int snum, i, j, m = 0;
	char ch[2];
	if ((fp = fopen("��ͥ�������ϵͳ", "ab+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;
	fclose(fp);
	if (m == 0)
	{
		printf("û�м�¼!\n");
		return;
	}
	printf("��������:");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
	if (snum == member[i].num)
		break;
	if (i == m)
	{
		printf("û���ҵ�!");

		return;
	}
	printf("�Ѿ��ҵ��ü�¼���Ƿ�ɾ��?(y/n)");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)                           //�ж��Ƿ�Ҫ����ɾ��
	{
		for (j = i; j<m; j++)
			member[j] = member[j + 1];                                 //����һ����¼�Ƶ�ǰһ����¼��λ��
		m--;                                                        //��¼���ܸ�����1
		printf("�ɹ�ɾ��!\n");
	}
	if ((fp = fopen("��ͥ�������ϵͳ", "wb")) == NULL)
	{
		printf("���ܴ�!\n");
		return;
	}
	for (j = 0; j<m; j++)                                         //�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���
	if (fwrite(&member[j], LEN, 1, fp) != 1)
	{
		printf("���ܱ���!\n");
		getch();
	}
	fclose(fp);
}
/*****************
�������������Ҽ�ͥ��Ա��֧��Ϣ
����������
����1��i
����2��m-��Ÿ���
����3��snum
����ֵ����ʾ��Ϣ��"û���ҵ���Ӧ�ļ�¼!"
���ù�ϵ��
�ú�����menu()��������
���ߣ�
�޸����ڣ�2020.6.18
**************/
void search()
{
	FILE *fp;
	int snum, i, m = 0;
	char ch[2];
	if ((fp = fopen("��ͥ�������ϵͳ", "ab+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;
	fclose(fp);
	if (m == 0)
	{
		printf("û�м�¼!\n");
		return;
	}
	printf("��������:");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
	if (snum == member[i].num)
	{
		printf("�Ѿ��ҵ��ü�¼���Ƿ���ʾ?(y/n)");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
		{
			printf("���    ��Ա       ���      �·�      ����        ֧��        �ܽ��\t\n");
			printf(FFORMAT, DATA);
			break;
		}
		else
			return;
	}
	if (i == m)
		printf("û���ҵ���Ӧ�ļ�¼!\n");
}
/*****************
�����������޸ļ�ͥ��Ա��֧��Ϣ
����������
����1��i-����
����2��j-��¼������
����3��m-�����
����4��snum-����
����ֵ��������ɹ����򡰲��ܱ��桱
���ù�ϵ��
�ú�����menu()��������
���ߣ�
�޸����ڣ�2020.6.18
**************/
void modify()
{
	FILE *fp;
	int i, j, m = 0, snum;
	char ch[2];

	if ((fp = fopen("��ͥ�������ϵͳ", "ab+")) == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;
	if (m == 0)
	{
		printf("û�м�¼!\n");
		fclose(fp);
		return;
	}
	printf("������Ҫ�޸ĵļ�¼��Ϣ�ı��!\n");
	scanf("%d", &snum);
	for (i = 0; i<m; i++)
	if (snum == member[i].num)                   //������¼���Ƿ���Ҫ�޸ĵ���Ϣ                         
	{
		printf("�Ѿ��ҵ��ü�¼���Ƿ��޸�?(y/n)\n");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)

		{
			printf("��ͥ��Ա����:");
			scanf("%s", member[i].name);                         //�����ͥ��Ա����
			printf("���������:");
			scanf("%d", &member[i].year);                        //�������
			printf("�������·�:");
			scanf("%d", &member[i].month);                     //�����·�

			printf("����������:");
			scanf("%f", &member[i].income);                  //��������
			printf("������֧��:");
			scanf("%f", &member[i].output);                //����֧��
			member[i].total = member[i].income - member[i].output;                //����

			printf("����ɹ�!");
		}
		else
			return;

	}
	else
	{
		printf("û���ҵ�!");
		return;
	}
	if ((fp = fopen("��ͥ�������ϵͳ", "wb")) == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	for (j = 0; j<m; j++)                        //�����޸ĵ���Ϣд��ָ���Ĵ����ļ���
	if (fwrite(&member[j], LEN, 1, fp) != 1)
	{
		printf("���ܱ���!");
	}
	fclose(fp);
}
/*****************
�������������Ҽ�ͥ��Ա��֧��Ϣ
����������
����1��m
����2��xxx
����ֵ����Ϣ�����Լ���Ϣ����
���ù�ϵ��
�ú�����menu()�������ã��ú��������show()����
���ߣ�
�޸����ڣ�2020.6.18
**************/
void total()                                    // ͳ��
{
	FILE *fp;
	int m = 0;
	if ((fp = fopen("��ͥ�������ϵͳ", "ab+")) == NULL)
	{
		printf("���ܴ򿪼�¼!\n");
		return;
	}
	while (!feof(fp))
	if (fread(&member[m], LEN, 1, fp) == 1)
		m++;                               //ͳ�Ƽ�¼����
	if (m == 0)
	{
		printf("û�м�¼!\n");
		fclose(fp);
		return;
	}
	printf("һ���� %d ����¼!\n", m);             //��ͳ�Ƶĸ������
	show();
	fclose(fp);
}
