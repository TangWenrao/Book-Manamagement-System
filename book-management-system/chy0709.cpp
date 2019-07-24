
 #include<stdio.h>
 #include<string.h>
 struct xinxi{
 	char book[10];
	char writer[10];
	char num[10];
 };
int b_borrow() //借书函数 
{
	FILE *fp;
	struct xinxi s[100],*p;
	char b_input[10],w_input[10],ONE[10];
	int choose1,r=-1,end;
	fp=fopen("bookcheck.txt","r+");
	if(fp==NULL)
	{
		printf("打开失败");
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
	printf("1、书名搜索       2、作者搜索\n");
	scanf("%d",&choose1);
	if(choose1==1)
	{	printf("输入书名：");
		scanf("%s",&b_input);
		for(int k=0;k<100;k++)
		{
			if(strcmp(s[k].book,b_input)==0)
			{
				if(strcmp(s[k].num,ONE)!=0)
				{
					printf("找到可借书本:    ");
					printf("%s    ",s[k].book);
					printf("作者：");
					printf("%s\n",s[k].writer);
					printf("请选择：1、借阅       2、退出\n");
					int choose2;
					scanf("%d",&choose2);
					if(choose2==1)
					{	
						char bw_num[10];
						printf("输入账号：");
						scanf("%s",&s[k].num);
						printf("借书成功");
						
					}
					else
					{
						printf("已退出");
					}
				}
				else
				{
					printf("该书书本已借出");
				}
				break;
			}
			
		}
	}
	else
	{	
		printf("输入作者：");
		scanf("%s",&w_input);
		for(int h=0;h<100;h++)
		{	
			if(strcmp(w_input,s[h].writer)==0)
			{	
				if(strcmp(s[h].num,ONE)!=0)
				{	
					printf("找到可借书本:    ");
					printf("%s\n",s[h].book);
					printf("请选择：1、借阅       2、退出\n");
					int choose2;
					scanf("%d",&choose2);
					if(choose2==1)
					{	
						char bw_num[10];
						printf("输入账号：");
						scanf("%s",&s[h].num);
						printf("借书成功"); 
					}
					else
					{
						printf("已退出");
				} 	}
				else
				{
					printf("该书本已借出");
				}
				break;
			}
		}
	}
	fclose(fp);
	//借书  改数字
	//保存到文件 
	rewind(fp);
	fopen("备份.txt","w+");
	for(int a=0;a<100;a++)
	{	
		if(a==end-27)
		{	
			printf("hahahaah");
			break;
			
		}
		fprintf(fp,"%s %s %s\n",s[a].book,s[a].writer,s[a].num);
	}
	fclose(fp);

}




int main()
{
	b_borrow();
} 
