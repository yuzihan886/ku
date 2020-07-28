#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include"tch_tools.h"
#include<getch.h>
static int stu_count=0;
static char stu_name[100][20];
static char stu_sex[100];
static char stu_num[100][10];
static int stu_chi[100];
static int stu_math[100];
static int stu_eng[100];
void stu_add(void)
{
	if(stu_count>=100)
		{
			printf("超出学生人数限制。");
			return;
		}	

	int i=0;
	while(stu_sex[i]) i++;
	printf("请输入学生姓名 性别：");
	scanf("%s %c",stu_name[i],stu_sex+i);
	stu_num[i]=stu_count+1;	
	stu_count++;
	/* 


		批量添加学生
	

	*/
}
void stu_del(void)
{
	char i=0;
	char key[20]={};
	printf("请输入要删除的学生信息：");
	scanf("%s",key);
do
	{
		if (stu_sex[i])
		{
			if(isdigit(key[0]))
			{
				if(0==strcmp(stu_num[i],key))
				{
					break;
				}
			}
			else
			{
				if(0==strcmp(stu_name[i],key))
				{
					break;
				}
			}
			
		}
	}while(++i<100);
	if(i<100)
	{
		char key1[20]={};
		printf("请再输入一遍，确认要删除的学生信息：");
		scanf("%s",key1);
		if(key==key1)
		{		
			printf("删除%s的信息成功。\n",stu_name[i]);
			stu_sex[i]=0;
			stu_count--;			
			FILE *fp=fopen("tuixue.txt","a");
			fprintf(fp,"%s ",stu_name[i]);
			int fclose(fp);

 
		}
	}
	else
	{
		printf("没有此学生。");
	}
}
void stu_find(void)
{
	char key[20]={};
	printf("请输入查询关键字：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu_sex[i]&&(strstr(stu_name[i],key)||strstr(stu_num[i],key)))
		{
			printf("%s %s %s %d %d %d\n",stu_name[i],'w'==stu_sex[i]?"女":"男",stu_num[i],stu_chi[i],stu_math[i],stu_eng[i]);	
		}	
	}
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	puts("任意键继续。");
	getch();
}
void stu_modify(void)
{
	char key[20]={};
	printf("输入修改的学生姓名：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu_sex[i]&&0==strcmp(stu_name[i],key))
		{
			printf("输入修改后的信息：");
			scanf("%s %c %s %d %d %d",stu_name[i],stu_sex+i,stu_num[i],stu_chi[i],stu_math[i],stu_eng[i]);
			printf("修改成功。\n");
			return;
		}
	}
	printf("未找到此学生。\n");
}
void stu_score(void)
{
	char key[20]={};
	printf("输入录入成绩的学生姓名：");
	scanf("%s",key);
	int i;
	for(i=0;i<100;i++)
	{
		if(stu_sex[i]&&0==strcmp(stu_name[i],key))
		{
			printf("输入需要录入的成绩：");
			scanf("%s %d %d %d",stu_name[i],stu_chi[i],stu_math[i],stu_eng[i]);
			printf("录入%s成绩成功。\n",stu_name[i]);
			return;
		}
	}
	printf("未找到此学生。\n");
	/*批量录入*/
}
