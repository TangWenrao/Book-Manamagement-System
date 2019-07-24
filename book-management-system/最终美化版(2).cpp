	
#include<stdio.h>
#include<string.h>
#include<windows.h> 
#include <stdlib.h>
#include <conio.h>
#define N 300
#define NB 4
int end,end2,R;
char stu_num[30];
FILE *tp; 
FILE *fp;

struct B {
	char book[30];
	char writer[30];
	char b_num[30];
	char place[30];
};struct B t[300];
 struct xinxi{
 	char book[30];
	char writer[30];
	char num[30];
 };struct xinxi s[300];
struct student{
	char std_id[15];
	char std_pd[10];
	int id_n;
	int pd_n;
}stdn[100];


int Signin_page();
int Homepage();
int Admin_in();
int judge_and_do();
int login_admin();
void Logout_page();
int edit_password(int std_n,int u_total);
int Register(int std_t);
int Sign_std(int i);
int Std_in(int std_t);


 int check_data_out()//借阅记录写入数组    函数 
 {	
	int r=-1;
	fp=fopen("借阅库.txt","r+");
	if(fp==NULL)
	{	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                   打开借阅库库失败                   ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	for(int i=0;i<300;i++)
	{	
		if(i%3==0)
		{
			r=r+1;
		}
		if(feof(fp)!=0)
		{	
			end=i;
			break;
		}
		if(i%3==0)
		{	
			fscanf(fp,"%s",s[r].book);
		}
		if((i-1)%3==0)
		{	 
			fscanf(fp,"%s",s[r].writer);
		}
		if((i-2)%3==0)
		{	
			fscanf(fp,"%s",s[r].num);
		}
	}
	fclose(fp);
 } 
 
 
 int check_data_in()//s[]数组写入借阅记录   函数 
 {
	rewind(fp);
	fp=fopen("借阅库.txt","w+");
	if(fp==NULL)
	{
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                   打开借阅库库失败                   ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	for(int a=0;a<300;a++)
	{	
		if(a==(end-1)/3)
		{	
			break;
		}
		fprintf(fp,"%s %s %s\n",s[a].book,s[a].writer,s[a].num);
	}
	fclose(fp);
 }
 
 int std_ip(){//账号信息导入数组 
	int i=0,j=0;
	FILE*fp_1;
	FILE*fp_2;
	fp_1=fopen("id.txt","r+");
	if(fp_1==NULL){
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                    打开id文件失败                    ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	fp_2=fopen("password.txt","r+");
	if(fp_2==NULL){
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                 打开password文件失败                 ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	fseek(fp_1,0L,SEEK_SET); 
	fseek(fp_2,0L,SEEK_SET);
	for(i=0;!feof(fp_1);i++){
		fscanf(fp_1,"%s",&stdn[i].std_id);
		stdn[i].id_n=atoi(stdn[i].std_id);
//		printf("%s\n",stdn[i].std_id);
	}
//	printf("\t%d",i);
	for(j=0;j<i;j++){
	
		fscanf(fp_2,"%s",&stdn[j].std_pd);
		stdn[j].pd_n=atoi(stdn[j].std_pd);
//		printf("%d\n",stdn[j].pd_n);
	}
	//printf("\t%d",i);
//	Sleep(4500);
	fclose(fp_1);
	fclose(fp_2);
//	u_total=i;
	return i;
}



 int storage_data_out()//书库写入数组函数 
 {	
	int r=-1;
	tp=fopen("书库.txt","r+");
	if(tp==NULL)
	{
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                    打开书库失败                      ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	for(int i=0;i<300;i++)
	{	
		if(i%4==0)
		{
			r=r+1;
		}
		if(feof(tp)!=0)
		{	
			end2=i;
			break;
		}
		if(i%4==0)
		{	
			fscanf(tp,"%s",t[r].book);
		}
		if((i-1)%4==0)
		{	 
			fscanf(tp,"%s",t[r].writer);
		}
		if((i-2)%4==0)
		{	
			fscanf(tp,"%s",t[r].b_num);
		}
		if((i-3)%4==0)
		{	
			fscanf(tp,"%s",t[r].place);
		}
	}
	fclose(tp);
 } 
 
 
 
 int storage_data_in()//t[]数组写入书库  函数 
 {
	rewind(tp);
	tp=fopen("书库.txt","w+");
	if(tp==NULL)
	{
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                    打开书库失败                      ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	for(int a=0;a<300;a++)
	{	
		if(a==(end2-1)/4)
		{	
			break;
		}
		fprintf(tp,"%s %s %s %s\n",t[a].book,t[a].writer,t[a].b_num,t[a].place);
	}
	fclose(tp);
 }
 
 
 
 
 int b_check()//输入书名返回回——>s[]数组中的位置
{	
	system("cls");
	char bname1[30];
	printf("\n\n\t\t\t☆☆☆☆☆☆              输入书名                 ☆☆☆☆☆☆\n\n");
	printf("\t\t\there:");
	scanf("%s",&bname1); 
	printf("\n\n");
	for(int k=0;k<300;k++)
	{	
		if(strstr(s[k].book,bname1)!=NULL)
		{			
			return k;
			break;
		}
		if(k==299)
		{
			return 299;
			break;
		}
	}

	
}


int w_check()//输入作者返回——>s[]数组中的位置
{
	system("cls");
	char writer1[30];
	printf("\n\n\t\t\t☆☆☆☆☆☆              输入作者                 ☆☆☆☆☆☆\n\n");
	printf("\t\t\there:");
	scanf("%s",&writer1);
	printf("\n\n");
	for(int h=0;h<300;h++)
	{	
		if(strcmp(writer1,s[h].writer)==0)
		{				
			return h;	
			break;
		}
		if(h==299)
		{	
			return 299;
			break;
		}
	}		
}



int n_storage()//输入编号返回——>t[]数组中的位置 
{
	system("cls");
	char bnumber[30];
	printf("\n\n\t\t\t☆☆☆☆☆☆              输入编号                 ☆☆☆☆☆☆\n\n");
	printf("\t\t\there:");
	scanf("%s",&bnumber);
	printf("\n\n");
	for(int u=0;u<=300;u++)
	{
		if(strcmp(bnumber,t[u].b_num)==0)
		{	
        	return u;
			break;			
		}
		if(u==299)
		{
			return 299;
			break;
		}

	}
} 




int b_storage()//输入书名返回——>t[]数组中的位置
{	system("cls");
	char bname2[30];
	printf("\n\n\t\t\t☆☆☆☆☆☆              输入书名                 ☆☆☆☆☆☆\n\n");
	printf("\t\t\there:");	
	scanf("%s",&bname2);
	printf("\n\n");
	for(int k=0;k<300;k++)
	{	
		if(strstr(t[k].book,bname2)!=NULL)
		{	

			return k;

			break;
		}
		if(k==299)
		{
			return 299;
			break;
		}
	}


	

	
}


int w_storage()//输入作者返回——>数组中的位置 
{
	system("cls");
	char writer2[30];
	printf("\n\n\t\t\t☆☆☆☆☆☆              输入作者                 ☆☆☆☆☆☆\n\n");
	printf("\t\t\there:");
	scanf("%s",&writer2);
	printf("\n\n");
	for(int h=0;h<300;h++)
	{
		if(strcmp(writer2,t[h].writer)==0)
		{		

			return h;
			break;
		}
		if(h==299)
		{
			return 299;
			break;
		}
	}		
}




int look()//浏览函数 
{	system("cls");
	int random=0;
	while(random==0)
	{
		printf("\n\n\t\t\t☆☆☆☆☆☆☆☆☆☆☆    图书信息    ☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
		printf("\t☆      %-14s☆☆☆☆☆      %-14s☆☆☆☆☆      %-6s☆  %-8s☆☆   \n","书名","作者","编号","位置");
		for(int i=0;i<(end2-1)/4;i++)
		{			
			printf("\t☆     %-30s%-30s %-10s%-10s☆   \n",t[i].book,t[i].writer,t[i].b_num,t[i].place);
		}
		printf("\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
		printf("\t\t\t◎◎                       1、退出                     ◎◎\n\t\t\t");
		
		scanf("%d",&random);
	}

}


 int b_add()//图书增加函数 
 {
 	int booknumber=(end2-1)/4-1;
	while(true)
	{
		system("cls");
		int choose;
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                       1、增书                        ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                       2、退出                        ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:");
		scanf("%d",&choose);
		printf("\n\n");
		if(choose!=1)
		{
			break;
		} 
		if(choose==1)
		{
			system("cls");
			booknumber=booknumber+1;
			printf("\n\n\t\t\t☆☆☆☆☆☆☆               输入信息            ☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆1、书名          2、作者          3、编号          4、位置 ☆\n");	
			printf("\t\t\there:");
			scanf("%s%s%s%s",&t[booknumber].book,&t[booknumber].writer,&t[booknumber].b_num,&t[booknumber].place);
			printf("\n\n\t\t\t◎◎◎◎                  增加成功                  ◎◎◎◎◎\n");
			Sleep(1250);
			strcpy(s[booknumber].book,t[booknumber].book);
			strcpy(s[booknumber].writer,t[booknumber].writer);
			strcpy(s[booknumber].num,"1");
			end2=end2+4;
			end=end+3;
		}
	}
 }
 

 
 int n_b_del()//书本删除函数（编号搜索） 
{		

   	int site=n_storage();
	if(site!=299)
	{
		system("cls");	
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                    删除的书本：                      ◎◎\n");					
		printf("\t\t\t☆☆                     %-10s                       ☆☆%s\n",t[site].book);	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\t☆☆    删除的书本：%-10s    ☆☆%s\n",t[site].book);
		strcpy(t[site].book,"\0");
		strcpy(t[site].writer,"\0");
		strcpy(t[site].b_num,"\0");
		strcpy(t[site].place,"\0");
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              删除成功                 ☆☆☆☆☆☆\n\n");
		Sleep(1250);
		
	}
	if(site==299)
	{
		system("cls");	
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
		Sleep(1250);
	}	
}



int b_b_del()//书本删除函数（书名搜索） 
{		
  	int site=b_storage();
	if(site!=299)
	{	system("cls");
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                    删除的书本：                      ◎◎\n");					
		printf("\t\t\t☆☆                     %-10s                       ☆☆%s\n",t[site].book);	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎\n\n");
		strcpy(t[site].book,"\0");
		strcpy(t[site].writer,"\0");
		strcpy(t[site].b_num,"\0");
		strcpy(t[site].place,"\0");
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              删除成功                 ☆☆☆☆☆☆\n\n");
		Sleep(1250);	
	}
	if(site==299)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
		Sleep(1250);
	}
}



int w_b_del()//书本删除函数（作者搜索） 
{		
	int site=w_storage();
	if(site!=299)
	{	system("cls");
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                    删除的书本：                      ◎◎\n");					
		printf("\t\t\t☆☆                     %-10s                       ☆☆%s\n",t[site].book);	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎8◎◎◎◎◎◎◎◎◎◎\n\n");
		strcpy(t[site].book,"\0");
		strcpy(t[site].writer,"\0");
		strcpy(t[site].b_num,"\0");
		strcpy(t[site].place,"\0");
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              删除成功                 ☆☆☆☆☆☆\n\n");	
		Sleep(1250);		
	}
	if(site==299)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
		Sleep(1250);
		
	}	
}



int b_del()//删书函数整合 
{	
	int choose;
	while(true)
	{	system("cls");	
		printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");
		printf("\t\t\t◎◎                   1、书名搜索                        ◎◎\n");	
		printf("\t\t\t◎◎                   2、作者搜索                        ◎◎\n");
		printf("\t\t\t◎◎                   3、编号搜索                        ◎◎\n");
		printf("\t\t\t◎◎                   4、退出                            ◎◎\n");			
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:"); 
		scanf("%d",&choose);
		printf("\n\n");
		if(choose!=1&&choose!=2&&choose!=3)
		{
			break;
		} 
		if(choose==1)
		{
			b_b_del();
		}
		if(choose==2)
		{
			w_b_del();
		}
		if(choose==3)
		{
			n_b_del();
		}
	}
}




int b_b_change()//图书修改函数（书名搜索） 
{	
	int b=b_storage();
	if(b!=299)
	{	system("cls");
		printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                      输入修改值                      ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:");
		scanf("%s",t[b].place);
		system("cls");
		printf("\n\n");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              修改成功                 ☆☆☆☆☆☆\n\n\n");
		printf("\t\t\t☆☆☆☆☆☆              修改结果                 ☆☆☆☆☆☆\n");
		int random=0;
		while(random==0)
		{
			printf("\n\n\t1、书名：%-20s2、作者：%-20s3、编号：%-10s4、位置：%-10s\n",t[b].book,t[b].writer,t[b].b_num,t[b].place);
			printf("\n\n\t\t\t◎◎                     1、退出                          ◎◎\n");
			scanf("%d",&random);
		} 		
			
	}
	if(b==299)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
		Sleep(1250);
	}
}



int w_b_change()// 图书修改函数（作者搜索） 
{	
	int w=w_storage();
	if(w!=299)
	{
		system("cls");
		printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                      输入修改值                      ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:");
		scanf("%s",t[w].place);
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              修改成功                 ☆☆☆☆☆☆\n\n\n");
		printf("\t\t\t☆☆☆☆☆☆              修改结果                 ☆☆☆☆☆☆\n");	
		int random=0;
		while(random==0)
		{
			printf("\n\n\t1、书名：%-20s2、作者：%-20s3、编号：%-10s4、位置：%-10s\n",t[w].book,t[w].writer,t[w].b_num,t[w].place);
			printf("\n\n\t\t\t◎◎                     1、退出                          ◎◎\n");
			scanf("%d",&random);
		} 
	}
	if(w==299)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n"); 
		Sleep(1250);
	}
}



int n_b_change()//图书修改函数（编号搜索） 
{	
	int n=n_storage();
	if(n!=299)
	{
		system("cls");
		printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                      输入修改值                      ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:");
		scanf("%s",t[n].place);
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              修改成功                 ☆☆☆☆☆☆\n\n\n");
		int random=0;
		while(random==0)
		{
			printf("\n\n\t1、书名：%-20s2、作者：%-20s3、编号：%-10s4、位置：%-10s\n",t[n].book,t[n].writer,t[n].b_num,t[n].place);
			printf("\n\n\t\t\t◎◎                     1、退出                          ◎◎\n");
			scanf("%d",&random);
		} 
	}
	if(n==299)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n"); 
		Sleep(1250);
	}
}



int b_change()//修改书函数整合 
{	
	int choose;
	while(true)
	{	
		system("cls");	
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");
		printf("\t\t\t◎◎                   1、书名搜索                        ◎◎\n");	
		printf("\t\t\t◎◎                   2、作者搜索                        ◎◎\n");
		printf("\t\t\t◎◎                   3、编号搜索                        ◎◎\n");
		printf("\t\t\t◎◎                   4、退出                            ◎◎\n");			
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:"); 
		scanf("%d",&choose);
		printf("\n\n");
		if(choose!=1&&choose!=2&&choose!=3)
		{
			break;
		} 
		if(choose==1)
		{
			b_b_change();
		}
		if(choose==2)
		{
			w_b_change();
		}
		if(choose==3)
		{
			n_b_change();
		}
	}
}


int record_check()//借阅记录 查询 
{	
	int choose;
	while(true)
	{
		system("cls");
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");
		printf("\t\t\t◎◎                   1、总览                            ◎◎\n");	
		printf("\t\t\t◎◎                   2、借阅查询                        ◎◎\n");
		printf("\t\t\t◎◎                   3、退出                            ◎◎\n");			
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:"); 
		scanf("%d",&choose);
		if(choose==1)
		{
			int random=0;
			while(random==0)
			{
				system("cls");
				int number=0;
				printf("\n\n\t\t\t☆☆☆☆☆☆             在借书本：                ☆☆☆☆☆☆\n\n"); 
				for(int i=0;i<100;i++)//总览 
				{			
					if(i==(end-1)/3)
					{
						break;
					}
					if(strcmp(s[i].num,"1")!=0)
					{
						number++;
						printf("\t\t\t借本：%-20s2、作者：%-20s借书用户：%-10s\n",number,s[i].book,s[i].writer,s[i].num);
					} 
				}
				printf("\t\t\t◎◎                   1、退出                            ◎◎\n");
				scanf("%d",&random);
			}
		}
		if(choose==2)
		{
			int choose2,number;
			while(true)
			{
				system("cls");
				printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
				printf("\t\t\t◎◎                                                      ◎◎\n");
				printf("\t\t\t◎◎                   1、书名搜索                        ◎◎\n");	
				printf("\t\t\t◎◎                   2、作者搜索                        ◎◎\n");
				printf("\t\t\t◎◎                   3、退出                            ◎◎\n");			
				printf("\t\t\t◎◎                                                      ◎◎\n");	
				printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
				printf("\t\t\there:"); 
				scanf("%d",&choose2);
				if(choose2==1)
				{
					int b=b_check();
					if(b!=299)
					{
						system("cls");
						printf("\n\n\t\t\t借本：%-20s2、作者：%-20s借书用户：%-10s\n",s[b].book,s[b].writer,s[b].num);
					}
					if(b==299)
					{
						system("cls");
						printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n"); 
						Sleep(1250);
					} 
				}
				if(choose2==2)
				{
					int w=w_check();
					if(w!=299)
					{
						system("cls");
						printf("\n\n\n\n\n\t\t\t借本：%-20s2、作者：%-20s借书用户：%-10s\n",s[w].book,s[w].writer,s[w].num);
					}
					if(w==299)
					{
						system("cls");
						printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");  
						Sleep(1250);
					} 
				}					
				if(choose2!=1&&choose2!=2) 
				{
					break;
				}
			}
		}		
		if(choose!=1&&choose!=2)
		{
			break;
		}								
	
	}
} 


int b_borrow() //借书函数 
{
	int choose;
	char ONE[10];
	strcpy(ONE,"1");
	while(true)
	{
		system("cls");
		printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");
		printf("\t\t\t◎◎                   1、书名搜索                        ◎◎\n");	
		printf("\t\t\t◎◎                   2、作者查书                        ◎◎\n");
		printf("\t\t\t◎◎                   3、退出                            ◎◎\n");			
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:"); 
		scanf("%d",&choose);
		printf("\n\n");	
		if(choose==1)
		{	int b=b_check();
			if(b!=299)
			{
				system("cls");
				printf("\n\n\t\t\t☆☆☆☆☆☆              搜索结果                 ☆☆☆☆☆☆\n");
				printf("\t\t\t                   ☆ %-20s  ☆         \n",s[b].book);
				Sleep(1250);
			}
			
			if(strcmp(s[b].num,stu_num)==0)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆           您已借过该书                ☆☆☆☆☆☆\n\n\n");
				Sleep(1250);
			}
			if(strcmp((s[b].num),"1")==0)
			{
				system("cls");
				strcpy(s[b].num,stu_num);
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              借阅成功                 ☆☆☆☆☆☆\n"); 	
				Sleep(1250);			
			}
			if(b==299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
				Sleep(1250);
			}
			if(b!=299&&strcmp(s[b].num,"1")!=0&&strcmp(s[b].num,stu_num)!=0)
			{	system("cls");
				printf("\n\n\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
				printf("\t\t\t◎◎◎◎           该书被人先抢一步啦                 ◎◎◎◎\n");		
				printf("\t\t\t☆  该借书用户：%-20s◎◎◎◎\n\n\n",s[b].num);
				Sleep(1250);
			}
		}
		if(choose==2)
		{
			int w=w_check();
			if(w!=299)
			{
				system("cls");
				printf("\n\n\t\t\t☆☆☆☆☆☆              搜索结果                 ☆☆☆☆☆☆\n");
				printf("\t\t\t                   ☆ %-20s  ☆         \n",s[w].book);
			}
			if(strcmp(s[w].num,stu_num)==0)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆           您已借过该书                ☆☆☆☆☆☆\n\n\n");
				Sleep(1250);
			}
			if(strcmp(s[w].num,"1")==0)
			{
				system("cls");
				strcpy(s[w].num,stu_num);
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              借阅成功                 ☆☆☆☆☆☆\n"); 	
				Sleep(1250);
			}
			if(w==299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
				Sleep(1250);
			}		
			if(w!=299&&strcmp(s[w].num,"1")!=0&&strcmp(s[w].num,stu_num)!=0)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
				printf("\t\t\t◎◎◎◎           该书被人先抢一步啦                 ◎◎◎◎\n");		
				printf("\t\t\t☆  该借书用户：%-20s◎◎◎◎\n\n\n",s[w].num);
				Sleep(1250);
			}
		}
		if(choose!=1&&choose!=2)
		{
			break;
		}
	}
}



int b_return() //还书函数 
{		
	char ONE[10];
	strcpy(ONE,"1");
	int borrow_num=0,choose;
	system("cls");
	printf("\n\n\n\t\t\t☆☆☆☆☆☆              借阅记录                 ☆☆☆☆☆☆\n");	
	for(int i=0;i<300;i++)
	{	
		if(i==(end-1)/3)
		{
			break;
		}	 	
		if(strcmp(s[i].num,stu_num)==0)
		{			
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆   %d 、%-10s    ☆☆☆☆☆☆☆☆☆☆\n",borrow_num+1,s[i].book);
			borrow_num++;
		}				
	}
	if(borrow_num==0)
	{
		system("cls");
		printf("\n\n\t\t\t☆☆☆☆☆☆        您没有借阅记录                 ☆☆☆☆☆☆\n");
		Sleep(1250);
	}
	while(borrow_num!=0)
	{	
		system("cls");
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");
		printf("\t\t\t◎◎                   1、还书                            ◎◎\n");	
		printf("\t\t\t◎◎                   2、退出                            ◎◎\n");			
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:");
		scanf("%d",&choose);
		printf("\n\n");
		if(choose==1)
		{	int b=b_check();		
			if(b==299)
			{
				system("cls");
				printf("\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
				Sleep(1250);
			}
			if(strcmp(s[b].num,"1")==0)
			{	system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆           该书无借阅记录              ☆☆☆☆☆☆\n\n");
				Sleep(1250);
			}
			if(strcmp(s[b].num,stu_num)==0)
			{	system("cls");
				strcpy(s[b].num,"1");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆              归还成功                 ☆☆☆☆☆☆\n\n");
				Sleep(1250);

			}
			if(strcmp(s[b].num,ONE)!=0&&strcmp(s[b].num,stu_num)!=0&&b!=299)
			{
				system("cls");	
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆          您没有借过该书               ☆☆☆☆☆☆\n\n");
				Sleep(1250);
			}															
		}
		if(choose!=1)
		{
			break;
		}
	}
}


int find_out() //找书 
 {
 	int choose;
 	while(true)
 	{	system("cls");
		printf("\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");
		printf("\t\t\t◎◎                   1、书名搜索                        ◎◎\n");	
		printf("\t\t\t◎◎                   2、作者搜索                        ◎◎\n");
		printf("\t\t\t◎◎                   3、编号搜索                        ◎◎\n");
		printf("\t\t\t◎◎                   4、退出                            ◎◎\n");			
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
		printf("\t\t\there:");
 		scanf("%d",&choose);
 		if(choose==1)
 		{
 			int b=b_storage();
			if(b!=299)
			{
				system("cls");
				printf("\n\n\n\n\n\t◎书籍信息： 书名：%-20s  作者：%-20s  编号：%-10s 位置：%-10s◎\n",t[b].book,t[b].writer,t[b].b_num,t[b].place);
				Sleep(2500);
			}
			if(b==299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n"); 
				Sleep(1250);
			}
	
		}
		if(choose==2)
 		{
			int w=w_storage();
			if(w!=299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t书籍信息： 书名：%-10s  作者：%-10s  编号：%-10s   位置：%-10s\n",t[w].book,t[w].writer,t[w].b_num,t[w].place);
			}
			if(w==299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n"); 
				Sleep(1250);
			}
		}
		if(choose==3)
 		{
			int n=n_storage();
			if(n!=299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t书籍信息： 书名：%-10s  作者：%-10s  编号：%-10s   位置：%-10s\n",t[n].book,t[n].writer,t[n].b_num,t[n].place);
			}
			if(n==299)
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆             该书不存在                ☆☆☆☆☆☆\n\n");
				Sleep(1250); 
			}
		}
		if(choose!=1&&choose!=2&&choose!=3)
		{
			break; 
		}		
	}
}





int Std_in(int std_t)//学生登陆 
{
g2:
int num,std_n;
system("cls");
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎     学生登录                                         ◎◎\n");
printf("\t\t\t◎◎   --------------------------                         ◎◎\n");
printf("\t\t\t◎◎                     1.登录                           ◎◎\n");
printf("\t\t\t◎◎                     2.注册                           ◎◎\n");
printf("\t\t\t◎◎                     0.返回上一级                     ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                              \t\t请输入数字进行选择: ");
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
		system("cls");
		printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆         输入错误，请重新选择          ☆☆☆☆☆☆\n\n"); 
		Sleep(1250);
		goto g2;
	}	 	
}


int Sign_std(int i)//学生登陆 
{
	int j,inputw,password,k=0;
	int std_t;
	char psword[10]; 
	char ch;
g1:	printf("\n\n\t\t\t☆☆账号：");
	scanf("%d",&inputw);
	for(j=0;j<i;j++)
	{
		if(inputw==stdn[j].id_n)
		{
			printf("\t\t\t☆☆密码："); 
		//	ch=getchar();
			while (1)
			{
				ch=getch();
				if(ch=='\r'){
					break;
				}else if(ch=='\b'){
					printf("\b \b");
					k=k-1;
				}else{
					psword[k] = ch;
					putchar('*');
					k++;
				}
			//	ch=getchar();
			}
		//	psword[k]='\0';
			password=atoi(psword);
			printf("\t%d",password); //
			if(password==stdn[j].pd_n)
			{
				system("cls");
				printf("\n\n\n\t\t\t                      ◎◎◎◎◎◎◎◎\n");	
				printf("\t\t\t                    ◎                ◎                         \n");		
				printf("\t\t\t◎◎◎◎◎◎◎◎◎◎      登录成功      ◎◎◎◎◎◎◎◎◎◎\n");	
				printf("\t\t\t                    ◎                ◎                   \n");				
				printf("\t\t\t                      ◎◎◎◎◎◎◎◎\n\n");
				Sleep(1250);
				itoa(inputw,stu_num,10)	;		
				while(true)
				{
					system("cls");
					int choose99;
					printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
					printf("\t\t\t◎◎                                                      ◎◎\n");
					printf("\t\t\t◎◎                   1、图书借阅                        ◎◎\n");	
					printf("\t\t\t◎◎                   2、归还书本                        ◎◎\n");
					printf("\t\t\t◎◎                   3、图书浏览                        ◎◎\n");
					printf("\t\t\t◎◎                   4、图书查找                        ◎◎\n");			
					printf("\t\t\t◎◎                   5、退出                            ◎◎\n");
					printf("\t\t\t◎◎                   0、修改密码                        ◎◎\n");	
					printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
					printf("\t\t\there:");							
					scanf("%d",&choose99);
					printf("\n\n");
					if(choose99==1)
					{					
						b_borrow();
					} 
					if(choose99==2)
					{
						b_return();
					}
					if(choose99==3)
					{
						look();
					} 
					if(choose99==4)
					{
						find_out();
					} 
					if(choose99==0)
					{
						edit_password(j,i);
					}
					if(choose99!=1&&choose99!=2&&choose99!=3&&choose99!=4&&choose99!=0)
					{
						break;
					} 				
				}
				Signin_page();				
			}
			else
			{
				system("cls");
				printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆                 密码错误              ☆☆☆☆☆☆\n\n");
				Sleep(1250);
				std_t=std_ip();
				Std_in(std_t);
					
			}
			break;
		}
	}
		if(j==i)
		{
			system("cls");
			printf("\n\n\n\n\n\t\t\t☆☆☆☆☆☆               未找到用户              ☆☆☆☆☆☆\n\n");
			Sleep(1250);
			std_t=std_ip();
			Std_in(std_t);
			
		}
}



int Register(int std_t)//注册 
{
	int i,num;
	i=std_t+1;
//	u_total=u_total+1;
	printf("\n\n\t\t\t☆☆账号：");
	scanf("%d",&stdn[i-1].id_n);
	printf("\t\t\t☆☆五位数密码：");
	scanf("%d",&stdn[i-1].pd_n);
	FILE*fp_1;
	FILE*fp_2;
	fp_1=fopen("id.txt","a+");
	if(fp_1==NULL){
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                    打开id文件失败                    ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	fp_2=fopen("password.txt","a+");
	if(fp_2==NULL){
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                 打开password文件失败                 ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	fprintf(fp_1,"%d\n",stdn[i-1].id_n);
	fclose(fp_1);
	fseek(fp_2,0,SEEK_END);
	fprintf(fp_2,"%d\n",stdn[i-1].pd_n);
	fclose(fp_2);
	itoa(stdn[i].id_n,stdn[i-1].std_id,10);
	itoa(stdn[i].pd_n,stdn[i-1].std_pd,10);
	system("cls");
	printf("\n\n\n\t\t\t                      ◎◎◎◎◎◎◎◎\n");	
	printf("\t\t\t                    ◎                ◎                         \n");		
	printf("\t\t\t◎◎◎◎◎◎◎◎◎◎      注册成功      ◎◎◎◎◎◎◎◎◎◎\n");	
	printf("\t\t\t                    ◎                ◎                   \n");				
	printf("\t\t\t                      ◎◎◎◎◎◎◎◎\n\n");
	Sleep(1250);
	Std_in(i);
}


int edit_password(int std_n,int u_total){//修改密码 
	int newpd1=0,newpd2=0,i=0,n=0,total=0;
	FILE*p2;
	printf("\n\n");
//	printf("\t%d",std_n);
p1:	printf("\t\t\t☆☆五位数新密码：");
	scanf("%d",&newpd1);
	printf("\t\t\t☆☆再次输入新密码：");
	scanf("%d",&newpd2);
	if(newpd1!=newpd2){
		system("cls");
		printf("\n\n\n\n\n\t\t\t◎◎               两次输入不一致，请重新输入             ◎◎\n");
		Sleep(1250);
		goto p1;
	}
	
	n=std_n;
	stdn[n].pd_n=newpd1;
	itoa(newpd1,stdn[n].std_pd,10);
	p2=fopen("password.txt","w+");
	for(i=0;i<u_total;i++){
		fprintf(p2,"%d\n",stdn[i].pd_n);
	}	
	fclose(p2);
	system("cls");
	printf("\n\n\n\t\t\t                      ◎◎◎◎◎◎◎◎\n");	
	printf("\t\t\t                    ◎                ◎                         \n");		
	printf("\t\t\t◎◎◎◎◎◎◎◎◎◎      修改成功      ◎◎◎◎◎◎◎◎◎◎\n");	
	printf("\t\t\t                    ◎                ◎                   \n");				
	printf("\t\t\t                      ◎◎◎◎◎◎◎◎\n\n");
	Sleep(1250);
	system("cls");
	Std_in(u_total);
	
//!!
}



int login_admin(){//管理员登陆 
	int admin_password[4];
	int input_password;
	FILE *fp;	
	fp=fopen("管理员哈哈哈哈.txt","r"); 
	if(fp==NULL){
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");		
		printf("\t\t\t◎◎                  打开管理员文件失败                  ◎◎\n");				
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎                                                      ◎◎\n");	
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");
	}
	for(int i=0;i<4;i++)
	{
		fscanf(fp,"%d",&admin_password[i]);
	}	
	fclose(fp);
	printf("\t\t\t☆☆密码：");
	scanf("%d",&input_password);
	for(int i=0;i<NB+1;i++)
	{
		if(i==NB)
		{
			return 1;
			break;
		}
		if(input_password==admin_password[i])
		{		
			return 0;
			break;
		}
	}
}

int judge_and_do()//管理员登陆 
{	
	int R=login_admin();
	if(R!=0){
		system("cls");
		printf("\n\n\n\n\n\t\t\t◎◎                   密码错误，登录失败                 ◎◎\n");
		Sleep(1250);
		Admin_in();
	}
	if(R==0)
	{	system("cls");
 		printf("\n\n\n\t\t\t                      ◎◎◎◎◎◎◎◎\n");	
		printf("\t\t\t                    ◎                ◎                         \n");		
		printf("\t\t\t◎◎◎◎◎◎◎◎◎◎      登陆成功      ◎◎◎◎◎◎◎◎◎◎\n");	
		printf("\t\t\t                    ◎                ◎                   \n");				
		printf("\t\t\t                      ◎◎◎◎◎◎◎◎\n\n");	
		Sleep(1250);					
		int choose66;			
		while(true)
		{
			system("cls");
			printf("\n\n\n\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
			printf("\t\t\t◎◎                   1、图书修改                        ◎◎\n");	
			printf("\t\t\t◎◎                   2、增加书本                        ◎◎\n");		
			printf("\t\t\t◎◎                   3、删减书本                        ◎◎\n");				
			printf("\t\t\t◎◎                   4、浏览书本                        ◎◎\n");	
			printf("\t\t\t◎◎                   5、借阅记录查询                    ◎◎\n");
			printf("\t\t\t◎◎                   6、退出                            ◎◎\n");	
			printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n\n");		 
			printf("\t\t\there:");	
			scanf("%d",&choose66);
			printf("\n\n");
			if(choose66==1)
			{	
				b_change();
			}		
			if(choose66==2)
			{		
				b_add();
			}
			if(choose66==3)
			{
				b_del();					
			}
			if(choose66==4)
			{
				look();
			}
			if(choose66==5)
			{
				record_check();
			}
			if(choose66!=1&&choose66!=2&&choose66!=3&&choose66!=4&&choose66!=5)
			{
				break;
			}							
		}
		Signin_page();	
	}
}


int Admin_in()//管理员登陆 
{
int num;
system("cls");
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎     管理员登录                                        ◎◎\n");
printf("\t\t\t◎◎   --------------------------                          ◎◎\n");
printf("\t\t\t◎◎                     1.登录                            ◎◎\n");
printf("\t\t\t◎◎                     0.返回上一级                      ◎◎\n");
printf("\t\t\t◎◎                                                       ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                              \t\t请输入数字进行选择: ");
scanf("%d",&num);
if(num==1)
	judge_and_do();//
else if(num==0)
	Signin_page();
else
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t◎◎                输入错误，请重新选择                   ◎◎\n");
		Sleep(1250);
		Admin_in();
	}	 
}


int Homepage()//主页 
{
int num;
int amount;
system("cls");
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎                 欢迎使用北京化工大学                 ◎◎\n");
printf("\t\t\t◎◎                     图书管理系统                     ◎◎\n");
printf("\t\t\t◎◎                       ____________                   ◎◎\n");
printf("\t\t\t◎◎                     1.进入登陆界面                   ◎◎\n");
printf("\t\t\t◎◎                     0.退出系统                       ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("                                             \t\t请输入数字进行选择: ");
scanf("%d",&num);
printf("\n");
if(num==0)
	Logout_page();
else if(num==1){
	Signin_page();	
	}
else
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t◎◎                输入错误，请重新选择                   ◎◎\n");
		Sleep(1250);
		Homepage();
	}
}


int Signin_page()//登陆主页 
{
int num,std_t;
system("cls");
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
		system("cls");
		printf("\n\n\n\n\n\t\t\t◎◎                输入错误，请重新选择                   ◎◎\n");
		Sleep(1250);
		Signin_page();
	}
}

void Logout_page()//退出 
{
system("cls");
printf("\n\n\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
printf("\t\t\t◎◎                                                      ◎◎\n");
printf("\t\t\t◎◎                                                      ◎◎\n");
printf("\t\t\t◎◎                       __退出成功___                  ◎◎\n");
printf("\t\t\t◎◎                                                      ◎◎\n");
printf("\t\t\t◎◎                                                      ◎◎\n");
printf("\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n");
}



int main()//主函数 
{	
	system("color 47");
	std_ip();
	check_data_out();
	storage_data_out();	
	Homepage();							
	check_data_in();
	storage_data_in();		
}
