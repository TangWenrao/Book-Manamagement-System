 #include<stdio.h>
 #include<string.h>
 struct xinxi{
 	char book[10];
	char writer[10];
	char num[10];
 };
 
	 	


int main()
{
	FILE *fp;
	struct xinxi s[100],*p;
	char b_input[10],w_input[10],ONE[10],ONE1[10];
	int choose,r=-1;
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
	scanf("%d",&choose);
	if(choose==1)
	{	printf("输入书名：");
		scanf("%s",&b_input);
		for(int k=0;k<100;k++)
		{
			if(strcmp(s[k].book,b_input)==0)
			{
				if(strcmp(s[k].num,ONE)!=0)
				{
					printf("找到可借书本:    ");
					printf("%s\n",s[k].book);
					printf("作者：");
					printf("%s",s[k].writer);
				}
				else
				{
					printf("该书书本已借出");
				}
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
				{	printf("%s\n",s[h].book);
					printf("找到可借书本:    ");
					printf("%s\n",s[h].book);
				} 
				else
				{
					printf("该书本已借出");
				}
			}
		}
	}
	fclose(fp);

}
