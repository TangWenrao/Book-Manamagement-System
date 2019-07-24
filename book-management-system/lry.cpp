// lry.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>

#define N 300


void Homepage();//主界面
void Signin_page();//学生与管理员公用登录缓冲界面
void Std_in();//学生登录界面
void Logout_page();//登出界面
void Sign_std();//实现学生登录的功能
void Register();//实现学生注册的功能
void Admin_in();//管理员登录界面


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

void Std_in()
{
int num;
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
if(num==1)
	Sign_std();
else if(num==2)
	Register();
else if(num==0)
	Signin_page();
else
	{
		printf("\t\t\t输入错误，请重新选择\n");
		Std_in();
	}	 
}

void Signin_page()
{
int num;
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
if(num==1)
	Std_in();
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
void Homepage()
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

void Sign_std()
{
	int i,j,inputw,password;
	int std[N],pass[5];
	printf("\t\t\t请输入账号");
	scanf("%d",&inputw);
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
	printf("%d\n",std[i]);
	for(i=0;std[i]==NULL;i++){
		fscanf(fp_1,"%d",&std[i]);
		printf("%d\n",std[i]);
	}
	for(j=0;j<i;j++)
		fscanf(fp_2,"%d",&pass[j]);
	printf("%d",i);
	for(j=0;j<=i;j++)
	{
		if(inputw==std[j])
		{
			printf("\t\t\t请输入密码");
			scanf("%d",&password);
			if(password==pass[j])
			{
				printf("登录成功");
				break;
			}else{
				printf("\t\t\t密码错误\n");
				Sign_std();
			}
			break;
		}
	}
		if(j==i+1)
		{
			printf("\t\t\t未找到用户\n");
			printf("\t\t\t请先注册\n");
			Register();
		}
	fclose(fp_1);
	fclose(fp_2);
}


void Register()
{
	int id,password,num;
	printf("\t\t\t请输入你的学号");
	scanf("%d",&id);
	printf("\t\t\t请输入你的5位数密码");
	scanf("%d",&password);
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
	fprintf(fp_1,"%d\n",id);
	fprintf(fp_2,"%d\n",password);
	fclose(fp_1);
	fclose(fp_2);
	printf("\t\t\t你已完成注册");
	printf("\t\t\t\t0.退出");
	scanf("%d",&num);
	if(num==0)
		Std_in();
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
void Admin_in()
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
	
	Homepage();
	getchar();
	return 0;
}

