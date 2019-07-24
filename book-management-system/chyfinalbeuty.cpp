	
	
#include<stdio.h>
#include<string.h>
char stu_num[10];
FILE *tp; 
FILE *fp;
struct B {
	char book[10];
	char writer[10];
	char b_num[10];
	char place[10];
};struct B t[100];
 struct xinxi{
 	char book[10];
	char writer[10];
	char num[10];
 };struct xinxi s[100];
int end,end2;
//全局变量 

 
 int check_data_out()//check文件写入数组    函数 
 {	
	int r=-1;
	fp=fopen("备份.txt","r+");
	if(fp==NULL)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    打开失败    ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	}
	for(int i=0;i<=100;i++)
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
 
 int check_data_in()//s[]数组写入文件   函数 
 {
	rewind(fp);
	fp=fopen("备份.txt","w+");
	if(fp==NULL)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    打开失败    ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	}
	for(int a=0;a<100;a++)
	{	
		if(a==(end-1)/3)
		{	
			break;
		}
		fprintf(fp,"%s %s %s\n",s[a].book,s[a].writer,s[a].num);
	}
	fclose(fp);
 }



 int storage_data_out()//storage文件写入数组函数 
 {	
	int r=-1;
	tp=fopen("备份2.txt","r+");
	if(tp==NULL)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    打开失败    ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	}
	for(int i=0;i<=100;i++)
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
 
 int storage_data_in()//t[]数组写入文件   函数 
 {
	rewind(tp);
	tp=fopen("备份2.txt","w+");
	if(tp==NULL)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    打开失败    ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
	}
	for(int a=0;a<=100;a++)
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
	char bname1[10];
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆    输入书名    ☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\t\t\t");
	printf("here:");
	scanf("%s",&bname1); 
	printf("\n\n");
	for(int k=0;k<100;k++)
	{	
		if(strcmp(s[k].book,bname1)==0)
		{			
			return k;
			break;
		}
		if(k==99)
		{

			return 99;
			break;
		}
	}

	
}
int w_check()//输入作者返回——>s[]数组中的位置
{
	char writer1[10];
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆    输入作者    ☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t");
	printf("here:");
	scanf("%s",&writer1);
	printf("\n\n");
	for(int h=0;h<100;h++)
	{	
		if(strcmp(writer1,s[h].writer)==0)
		{				
			return h;	
			break;
		}
		if(h==99)
		{	
			return 99;
			break;
		}
	}		
}

int n_storage()//输入编号返回——>t[]数组中的位置 
{
	char bnumber[10];
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆    输入编号    ☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t");
	printf("here:");
	printf("\n\n");
	scanf("%s",&bnumber);
	for(int u=0;u<=100;u++)
	{
		if(strcmp(bnumber,t[u].b_num)==0)
		{	
        	return u;
			break;			
		}
		if(u==99)
		{
			return 99;
			break;
		}

	}
} 




int b_storage()//输入书名返回——>t[]数组中的位置
{	
	char bname2[10];
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆    输入书名    ☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t");
	printf("here:");	
	scanf("%s",&bname2);
	printf("\n\n");
	for(int k=0;k<=100;k++)
	{	
		if(strcmp(t[k].book,bname2)==0)
		{	

			return k;

			break;
		}
		if(k==99)
		{
			return 99;
			break;
		}
	}


	

	
}
int w_storage()//输入作者返回——>数组中的位置 
{
	char writer2[10];
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆    输入作者    ☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t");
	printf("here:");
	scanf("%s",&writer2);
	printf("\n\n");
	for(int h=0;h<100;h++)
	{
		if(strcmp(writer2,t[h].writer)==0)
		{		

			return h;
			break;
		}
		if(h==99)
		{
			return 99;
			break;
		}
	}		
}



int look()//浏览函数 

{	
	printf("\t\t\t☆☆☆☆☆☆☆☆    图书信息    ☆☆☆☆☆☆☆☆☆\n\n");
	printf("\t\t\t☆   1、书名    2、作者    3、编号    4、位置   ☆\n");
	for(int i=0;i<(end2-1)/4;i++)
	{			
		printf("\t\t\t☆     %-10s%-10s%-10s%-10s ☆\n",t[i].book,t[i].writer,t[i].b_num,t[i].place);
	}
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
}



 int b_add()//图书增加函数 
 {
 	int booknumber=(end2-1)/4-1;
	while(true)
	{	int choose;
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆   1、增书      ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆   2、查书      ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆   3、退出      ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t");
		printf("here:");
		scanf("%d",&choose);
		printf("\n\n");
		if(choose!=1&&choose!=2)
		{
			break;
		}
		if(choose==1)
		{
			booknumber=booknumber+1;
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆☆☆☆   输入信息     ☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆  1、书名    2、作者    3、编号    4、位置  ☆\n");
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\t\t\t");	
			printf("here:");
			scanf("%s%s%s%s",&t[booknumber].book,&t[booknumber].writer,&t[booknumber].b_num,&t[booknumber].place);
			strcpy(s[booknumber].book,t[booknumber].book);
			strcpy(s[booknumber].writer,t[booknumber].writer);
			strcpy(s[booknumber].num,"1");
			end2=end2+4;
			end=end+3;
		}
		if(choose==2)
		{
			look();
		}
	}
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆    退出增书    ☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
 }
 
 
 int n_b_del()//书本删除函数（编号搜索） 
{		

   	int site=n_storage();
	if(site!=99)
	{	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆    删除的书本：%-10s    ☆☆%s\n",t[site].book);
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
		strcpy(t[site].book,"\0");
		strcpy(t[site].writer,"\0");
		strcpy(t[site].b_num,"\0");
		strcpy(t[site].place,"\0");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    删除成功    ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
		
	}
	if(site==99)
	{	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    该书本不存在    ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n"); 
	}	
}

int b_b_del()//书本删除函数（书名搜索） 
{		
  	int site=b_storage();
	if(site!=99)
	{	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆   删除的书本：%-10s  ☆☆☆%s\n",t[site].book);
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		strcpy(t[site].book,"\0");
		strcpy(t[site].writer,"\0");
		strcpy(t[site].b_num,"\0");
		strcpy(t[site].place,"\0");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    删除成功    ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");	
	}
	if(site==99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    该书本不存在    ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n"); 
	}
}

int w_b_del()//书本删除函数（作者搜索） 
{		
	int site=w_storage();
	if(site!=99)
	{	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆    删除的书本：%-10s  ☆☆☆%s\n",t[site].book);
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");
		strcpy(t[site].book,"\0");
		strcpy(t[site].writer,"\0");
		strcpy(t[site].b_num,"\0");
		strcpy(t[site].place,"\0");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    删除成功    ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n");			
	}
	if(site==99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    该书本不存在    ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n"); 
		
	}	
}




int b_b_change()//图书修改函数（书名搜索） 
{	
	int b=b_storage();
	if(b!=99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    输入修改值：    ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t"); 
		printf("here:");
		scanf("%s",t[b].place);
		printf("\n\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    修改成功    ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆修改结果☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆1、书名☆☆2、作者☆☆3、编号☆☆4、位置☆☆\n");	
		printf("\t\t\t☆☆%s☆☆%s☆☆%s☆☆%s☆☆\n",t[b].book,t[b].writer,t[b].b_num,t[b].place);
			
	}
	if(b==99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  该书本不存在  ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n"); 
	}
}

int w_b_change()// 图书修改函数（作者搜索） 
{	
	int w=w_storage();
	if(w!=99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  输入修改值：  ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\t\t\t"); 
		printf("here:");
		scanf("%s",t[w].place);
		printf("\n\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆  修改成功  ☆☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆  修改结果  ☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆1、书名☆☆2、作者☆☆3、编号☆☆4、位置☆☆\n");	
		printf("\t\t\t☆☆%s☆☆%s☆☆%s☆☆%s☆☆\n\n\n",t[w].book,t[w].writer,t[w].b_num,t[w].place);
	}
	if(w==99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  该书本不存在  ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
	}
}

int n_b_change()//图书修改函数（编号搜索） 
{	
	int n=n_storage();
	if(n!=99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  输入修改值：  ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t"); 
		printf("here:");
		scanf("%s",t[n].place);
		printf("\n\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    修改成功    ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆    修改结果    ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆1、书名☆☆2、作者☆☆ 3、编号☆☆ 4、位置☆\n");	
		printf("\t\t\t☆☆%s☆☆%s☆☆%s☆☆%s☆☆\n\n\n",t[n].book,t[n].writer,t[n].b_num,t[n].place);
	}
	if(n==99)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    该书本不存在    ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
	}
}





 int b_borrow() //借书函数 
{
	int choose;
	char ONE[10];
	strcpy(ONE,"1");
	while(true)
	{
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  1、书名搜索   ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  2、作者查书   ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆   3、退出      ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");
		printf("here:");
		scanf("%d",&choose);
		printf("\n\n");	
		if(choose==1)
		{	int b=b_check();
			if(b!=99)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆    搜索结果    ☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆   %-12s   ☆☆☆☆☆☆☆\n",s[b].book);
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}
			
			if(strcmp(s[b].num,stu_num)==0)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆    您已借过该书    ☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
			}
			if(strcmp((s[b].num),"1")==0)
			{
				strcpy(s[b].num,stu_num);
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆    借阅成功    ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 				
			}
			if(b==99)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆    该书不存在    ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}
			if(b!=99&&strcmp(s[b].num,"1")!=0&&strcmp(s[b].num,stu_num)!=0)
			{	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆   该书被人先抢一步啦     ☆☆☆☆☆☆\n");			
				printf("\t\t\t☆☆☆☆☆   该借书用户：%-10s    ☆☆☆☆\n\n\n",s[b].num);
			}
		}
		if(choose==2)
		{
			int w=w_check();
			if(w!=99)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆    搜索结果    ☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆   %-12s     ☆☆☆☆☆☆☆\n",s[w].book);
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}
			if(strcmp(s[w].num,stu_num)==0)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆    您已借过该书    ☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
			}
			if(strcmp(s[w].num,"1")==0)
			{
				strcpy(s[w].num,stu_num);
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆    借阅成功    ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 	
			}
			if(w==99)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆    该书不存在    ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}		
			if(w!=99&&strcmp(s[w].num,"1")!=0&&strcmp(s[w].num,stu_num)!=0)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆     该书被人先抢一步啦     ☆☆☆☆☆\n");			
				printf("\t\t\t☆☆☆☆    该借书用户：%-10s     ☆☆☆☆\n\n\n",s[w].num);
			}
		}
		if(choose!=1&&choose!=2)
		{
			break;
		}
	}
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆    您退出借书功能    ☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
}
int b_return() //还书函数 
{		
	char ONE[10];
	strcpy(ONE,"1");
	int borrow_num=0,choose;
	printf("\t\t\t☆☆☆☆☆☆☆☆☆  借阅记录    ☆☆☆☆☆☆☆☆\n");		
	for(int i=0;i<100;i++)
	{	
		if(i==(end-1)/3)
		{
			break;
		}	 	
		if(strcmp(s[i].num,stu_num)==0)//账号不能是"1"
		{			
			printf("\t\t\t☆☆☆☆☆☆☆  %d 、%-10s   ☆☆☆☆☆☆☆\n",borrow_num+1,s[i].book);
			borrow_num++;
		}				
	}
	if(borrow_num==0)
	{
		printf("\t\t\t☆☆☆☆☆☆   您没有借阅记录   ☆☆☆☆☆☆☆☆\n");
	}
	while(borrow_num!=0)
	{	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    1、还书       ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆    2、退出     ☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");
		printf("here:");
		scanf("%d",&choose);
		printf("\n\n");
		if(choose==1)
		{	int b=b_check();		
			if(b==0)
			{
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆    该书不存在    ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}
			if(strcmp(s[b].num,"1")==0)
			{	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆    该书无借阅记录    ☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}
			if(strcmp(s[b].num,stu_num)==0)
			{	
				strcpy(s[b].num,"1");
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆     还书成功     ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}
			if(strcmp(s[b].num,ONE)!=0&&strcmp(s[b].num,stu_num)!=0&&b!=0)
			{	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆    您没有借过该书    ☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
			}															
		}
		if(choose!=1)
		{
			break;
		}
	}
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆    已退出还书功能    ☆☆☆☆☆☆☆\n");	
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
}

int b_del()//删书函数整合 
{	
	look();
	int choose;
	while(true)
	{		
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  1、书名搜索   ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆  2、作者搜索   ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  3、编号搜索   ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  4、退出       ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");
		printf("here:"); 
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
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆   您已退出删减功能    ☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
}

int b_change()//修改书函数整合 
{	look();
	int choose;
	while(true)
	{		
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  1、书名搜索   ☆☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆☆  2、作者搜索   ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  3、编号搜索   ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆  4、退出       ☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");
		printf("here:");
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
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆    您退出修改功能    ☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
}






int main()
{	
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆      请输入学号      ☆☆☆☆☆☆☆\n");
	printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t"); 
	printf("here:");
	scanf("%s",&stu_num);
	printf("\n\n");
	int choose0;
	check_data_out();
	storage_data_out();
	while(true)
	{	
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    1、学生功能     ☆☆☆☆☆☆☆\n");	
		printf("\t\t\t☆☆☆☆☆☆☆    2、管理员功能   ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆    3、退出         ☆☆☆☆☆☆☆\n");
		printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");
		printf("here:");
		scanf("%d",&choose0);
		printf("\n\n");
		if(choose0==1)
		{	while(choose0==1)
			{
				int choose99;
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  1、图书借阅     ☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆  2、归还书本     ☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  3、图书浏览     ☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  4、退出         ☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");		
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
				if(choose99!=1&&choose99!=2&&choose99!=3)
				{
					break;
				} 				
			}
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆     您已退出学生功能区     ☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 		
		}					
		if(choose0==2)
		{		
			int choose66;
			
			while(choose0==2)
			{			 
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  1、图书修改   ☆☆☆☆☆☆☆☆\n");	
				printf("\t\t\t☆☆☆☆☆☆☆☆  2、增加书本   ☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  3、删减书本   ☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  4、浏览书本   ☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆  5、 退出      ☆☆☆☆☆☆☆☆\n");
				printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n\t\t\t");	
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
				if(choose66!=1&&choose66!=2&&choose66!=3&&choose66!=4)
				{
					break;
				}			
			}
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆    您退出管理功能区    ☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 
		}
		if(choose0!=1&&choose0!=2)
		{
			break;
		}
	}
	check_data_in();
	storage_data_in();		
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆    您已退出系统      ☆☆☆☆☆☆☆\n");
			printf("\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n"); 		
}
