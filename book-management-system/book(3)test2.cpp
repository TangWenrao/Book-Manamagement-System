
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
	struct xinxi s[100];
	char b_input[10],w_input[10],ONE[10];
	int choose1,r=-1,end;
	strcpy(ONE,"1");
	fp=fopen("备份.txt","r+");
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
				if(strcmp(s[k].num,ONE)==0)
				{
					printf("找到可借书本:    ");
					printf("%s    ",s[k].book);
					printf("作者：");
					printf("%s\n",s[k].writer);
					char bw_num[10];
					printf("输入账号：");
					scanf("%s",&s[k].num);
					printf("借书成功");
					

				}
				else
				{
					printf("该书书本已借出\n");
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
					char bw_num[10];
					printf("输入账号：");
					scanf("%s",&s[h].num);
					printf("借书成功\n"); 


				} 	
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
		if(a==(end-1)/3)
		{	
			break;
		}
		fprintf(fp,"%s %s %s\n",s[a].book,s[a].writer,s[a].num);
	}
	fclose(fp);
}







int b_return() //还书函数 
{
	FILE *fp;
	struct xinxi s[100];
	char b_input[10],ONE[2],input_num[10];
	int r=-1,end;
	strcpy(ONE,"1");
	fp=fopen("备份.txt","r");
	if(fp==NULL)
	{
		printf("打开失败\n");
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
	}//文本信息读入 
	printf("输入学号：");
	scanf("%s",&input_num);
	printf("输入归还的书本:");
	scanf("%s",&b_input);
	for(int g=0;g<100;g++)
	{
		if(g==(end-1)/3+1)
		{

			break;
		}
		if(strcmp(s[g].book,b_input)==0)
		{
			printf("找到该书,");
			if(strcmp(s[g].num,ONE)==0)
			{
				printf("该书没有借阅记录"); 
			}
			else
			{

				if(strcmp(s[g].num,input_num)!=0)
				{
					printf("您没有借过该书\n");
				}
				else
				{
					printf("好的您已归还\n");
					strcpy(s[g].num,"1");

				}
			}
			break;
		}
		
	}
	fclose(fp);
	//保存到文件 
	rewind(fp);

	fopen("备份.txt","w+");
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


int main()
{	
	int book_operate=0;
	int choose3;

	while(book_operate==0)
	{
		
		printf("请选择  1、借书     2、还书    3、退出\n") ;
		scanf("%d",&choose3);
	
		if(choose3==1)
		{
			b_borrow();
	
		}
		if(choose3==2)
		{
			b_return();
		}
		if(choose3!=1&&choose3!=2) 
		{	
			book_operate=1;
			printf("你已退出\n");
		}
		
	}
	 
}


