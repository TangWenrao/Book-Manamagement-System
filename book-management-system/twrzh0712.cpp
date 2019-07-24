// lry.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include<windows.h> 
#include <stdlib.h>
#include <string.h>
#define N 300


int Homepage();//主界面
int Signin_page();//学生与管理员公用登录缓冲界面
int Std_in(int std_t);//学生登录界面
void Logout_page();//登出界面
int Sign_std(int i);//实现学生登录的功能
int Register(int std_t);//实现学生注册的功能
int Admin_in();//管理员登录界面
int std_ip();//用户信息导入 
int user_page(int std_n,int u_total);//用户操作界面 

struct student{
	char std_id[15];
	char std_pd[10];
	int id_n;
	int pd_n;
}stdn[100];

struct books{
	char book_name[20];
	char book_num[10];
	char writer[15];
	char place[15];
	char state[10];
}book[300];
void Logout_page()
{
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎                                                        ◎◎\n");
printf("\t\t\t◎◎                                                        ◎◎\n");
printf("\t\t\t◎◎                       __退出成功___                    ◎◎\n");
printf("\t\t\t◎◎                                                        ◎◎\n");
printf("\t\t\t◎◎                                                        ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
}
int std_ip(){
	int i=0,j=0;
	FILE*fp_1;
	FILE*fp_2;
	fp_1=fopen("id.txt","r+");
	if(fp_1==NULL){
		printf("打开id文件失败\n");
	}
	fp_2=fopen("password.txt","r+");
	if(fp_2==NULL){
		printf("打开password文件失败\n");
	}
	fseek(fp_1,0L,SEEK_SET); 
	fseek(fp_2,0L,SEEK_SET);
	for(i=0;!feof(fp_1);i++){
		fscanf(fp_1,"%s",stdn[i].std_id);
		stdn[i].id_n=atoi(stdn[i].std_id);
	//	printf("%s\n",stdn[i].std_id);
	}
//	printf("\t%d",i);
	for(j=0;j<i;j++){
	
		fscanf(fp_2,"%s",stdn[j].std_pd);
		stdn[j].pd_n=atoi(stdn[j].std_pd);
	}
//	printf("\t%d",i);
	fclose(fp_1);
	fclose(fp_2);
//	u_total=i;
	return i;
}
int Std_in(int std_t)
{
	g2:
int num,std_n;
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎     学生登录                                           ◎◎\n");
printf("\t\t\t◎◎   --------------------------                           ◎◎\n");
printf("\t\t\t◎◎                     1.登录                             ◎◎\n");
printf("\t\t\t◎◎                     2.注册                             ◎◎\n");
printf("\t\t\t◎◎                     0.返回上一级                       ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                                \t\t请输入数字进行选择: ");
scanf("%d",&num);
if(num==1){

	std_n=Sign_std(std_t);
	return std_n;
	}
else if(num==2)
	Register(std_t);
else if(num==0)
	Signin_page();
else
	{
		printf("\t\t\t输入错误，请重新选择\n");
		goto g2;
	}	 
	
}

int Signin_page()
{
int num,std_t;
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎                        登录                            ◎◎\n");
printf("\t\t\t◎◎                   ————————                     ◎◎\n");
printf("\t\t\t◎◎                   1.进入学生登陆界面                   ◎◎\n");
printf("\t\t\t◎◎                   2.进入管理员登陆界面                 ◎◎\n");
printf("\t\t\t◎◎                   0.退出系统                           ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                                \t\t请输入数字进行选择: ");
scanf("%d",&num);
if(num==1){

	std_t=std_ip();
	Std_in(std_t);
	}
else if(num==2)
	Admin_in();
else if(num==0)
	Logout_page();
else
	{
		printf("\t\t\t输入错误，请重新选择\n");
		Signin_page();
	}
}
int Homepage()
{
int num;
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎                   欢迎使用北京化工大学                 ◎◎\n");
printf("\t\t\t◎◎                       图书管理系统                     ◎◎\n");
printf("\t\t\t◎◎                       ____________                     ◎◎\n");
printf("\t\t\t◎◎                     1.进入登陆界面                     ◎◎\n");
printf("\t\t\t◎◎                     0.退出系统                         ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                               \t\t请输入数字进行选择: ");
scanf("%d",&num);
printf("\n");
if(num==0)
	Logout_page();
else if(num==1)
	Signin_page();
else
	{
		printf("\t\t\t输入错误，请重新选择\n");
		Homepage();
	}
}

int Sign_std(int i)
{
	int j,inputw,password;
g1:	printf("\t\t\t请输入账号");
	scanf("%d",&inputw);
	for(j=0;j<i;j++)
	{
		if(inputw==stdn[j].id_n)
		{
			printf("\t\t\t请输入密码");
			scanf("%d",&password);
			if(password==stdn[j].pd_n)
			{
				printf("\t\t\t登录成功");
				user_page(j,i);
				return j;
			}else{
				printf("\t\t\t密码错误\n\n");
				goto g1;
			}
			break;
		}
	}
		if(j==i)
		{
			printf("\t\t\t未找到用户\n\n");
			printf("\t\t\t请先注册\n\n");
			Register(i);
		}
}


int Register(int std_t)
{
	int i,num;
	i=std_t+1;
//	u_total=u_total+1;
	printf("\t\t\t请输入你的学号\n");
	scanf("%d",&stdn[i-1].id_n);
	printf("\t\t\t请输入你的5位数密码\n");
	scanf("%d",&stdn[i-1].pd_n);
	FILE*fp_1;
	FILE*fp_2;
	fp_1=fopen("id.txt","a+");
	if(fp_1==NULL){
		printf("打开id文件失败\n");
	}
	fp_2=fopen("password.txt","a+");
	if(fp_2==NULL){
		printf("打开password文件失败\n");
	}
	fprintf(fp_1,"%d\n",stdn[i].id_n);
	fprintf(fp_2,"%d\n",stdn[i].pd_n);
	fclose(fp_1);
	fclose(fp_2);
	itoa(stdn[i].id_n,stdn[i].std_id,10);
	itoa(stdn[i].pd_n,stdn[i].std_pd,10);
	printf("\t\t\t你已完成注册\n\n");
	printf("\t\t\t\t0.退出");
	scanf("%d",&num);
	if(num==0)
		Std_in(i);
}
int edit_password(int std_n,int u_total){
	int newpd1=0,newpd2=0,i=0,n=0,total=0;
	FILE*p2;
	printf("\n\n\n");
	printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("\n\n\n");
p1:	printf("\t\t\t请输入新密码\n");
	scanf("%d",&newpd1);
	printf("\t\t\t再次输入新密码\n");
	scanf("%d",&newpd2);
	if(newpd1!=newpd2){
		printf("\t\t\t两次输入密码不一致，请重新输入\n");
		goto p1;
	}
	n=std_n;
	stdn[n].pd_n=newpd1;
	itoa(newpd1,stdn[n].std_pd,10);
	p2=fopen("password.txt","w");
	for(i=0;i<u_total;i++){
		fprintf(p2,"%s\n",stdn[i].std_pd);
	}
	
	fclose(p2);
	printf("\t\t\t修改密码成功\n");
	printf("\n\n\n");
	printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	user_page(std_n,u_total);
}
int user_page(int std_n,int u_total){
	int num;
	printf("\n\n\n");
	printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("\t\t\t◎◎     学生操作界面                                       ◎◎\n");
	printf("\t\t\t◎◎   --------------------------                           ◎◎\n");
	printf("\t\t\t◎◎                     1.浏览                             ◎◎\n");
	printf("\t\t\t◎◎                     2.查询                             ◎◎\n");
	printf("\t\t\t◎◎                     3.借阅                             ◎◎\n");
	printf("\t\t\t◎◎                     4.还书                             ◎◎\n");
	printf("\t\t\t◎◎                     5.修改密码                         ◎◎\n");
	printf("\t\t\t◎◎                     0.返回上一级                       ◎◎\n");
	printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
	printf("                                                \t\t请输入数字进行选择: ");
	scanf("%d",&num);
	if(num==5){
		edit_password(std_n,u_total);
	}else if(num==1){
		
	}
}
int book_amount(FILE*p){//现有图书数量 //没有问题 
	int i=0;
	char a[20];
	for(i=0;(fgets(a,30,p))!=NULL;i++){
		//printf("%d\n",i);
	}
	return i;
}
int book_input(){//图书录入//没有问题 
	FILE *p,*p2;
	p=fopen("bookstorage.txt","a+");
	if(p==NULL){
		printf("ERROR\n");
	} 
	p2=fopen("bookcheck.txt","a+");
	printf("请输入书名\n");
	scanf("%s",&book[0].book_name);
	fprintf(p,"%s ",book[0].book_name);
	fprintf(p2,"%s ",book[0].book_name);
	printf("请输入作者\n");
	scanf("%s",&book[0].writer);
	fprintf(p,"%s ",book[0].writer);
	fprintf(p2,"%s ",book[0].writer);
	printf("请输入书号\n");
	scanf("%s",&book[0].book_num);
	fprintf(p,"%s ",book[0].book_num);
	printf("请输入位置\n");
	scanf("%s",&book[0].place);
	fprintf(p,"%s\n",book[0].place);
	fprintf(p2,"1\n");
	fclose(p);
	return 0;
}
int login_admin(){
	int admin_password;
	int input_password;
	FILE *fp;
	if((fp=fopen("admin.txt","r"))==NULL){
		printf("打开文件失败\n");
	}
	fscanf(fp,"%d",&admin_password);
	fclose(fp);
	printf("\t\t\t请输入密码\n");
	scanf("%d",&input_password);
	if(input_password==admin_password){
		return 1;
	}else{
		return 0;
	}
}
int check(int n){
	if(n==0){
		printf("\t\t\t密码错误，登录失败"); 
		Signin_page();
		return 0;
	}else{
		printf("\t\t\t登录成功"); 
		return 1;
	}
}
int admin_checkin(){
	int a=0;
	a=login_admin();
	a=check(a);
	return a;
}
int Admin_in()
{
	int num;
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎     管理员登录                                         ◎◎\n");
printf("\t\t\t◎◎   --------------------------                           ◎◎\n");
printf("\t\t\t◎◎                     1.登录                             ◎◎\n");
printf("\t\t\t◎◎                     0.返回上一级                       ◎◎\n");
printf("\t\t\t◎◎                                                        ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                                \t\t请输入数字进行选择: ");
scanf("%d",&num);
if(num==1)
	admin_checkin();//
else if(num==0)
	Signin_page();
else
	{
		printf("\t\t\t输入错误，请重新选择\n");
		Admin_in();
	}	 
}


int main()
{
	int u_total=0;
	system("color 30");
	Homepage();
	getchar();
	return 0;
}

