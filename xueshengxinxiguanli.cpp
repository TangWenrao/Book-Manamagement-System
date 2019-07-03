#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

void zhuyemian();
void denglu();
void guanli();
void jiaoshi();
void xuesheng();
void tuichu();
void chengjiluru();
void chengjichaxun();
void mimagenggai();
void zhanghaotianjia();
void zhanghaoshanchu();
void zhanghaogenggai();
void xinxitianjia();
void xinxichaxun();
void chaxunmima();
void chaxunchengji();
void miwenshuru(char *miwen);
int sf;
char zh[11];
char mm[19];

typedef struct canshub
{
	int shenfen;
	char zhanghao[11];
	char mima[19];
}canshuc;
canshuc yanzheng[1000];

typedef struct canshud
{
	char xuehao[11];
	char kemu1[10];int fenshu1;
	char kemu2[10];int fenshu2;
	char kemu3[10];int fenshu3;
	char kemu4[10];int fenshu4;
	char kemu5[10];int fenshu5;
	char kemu6[10];int fenshu6;
	char kemu7[10];int fenshu7;
	char kemu8[10];int fenshu8;

}canshue;

typedef struct canshuf
{
	char xuehao[11];
	char xingming[10];
	char xueyuan[10];
	char banji[10];
}canshug;


int main()
{
    system("cls");
	zhuyemian();
	denglu();
    switch(sf)
	{
		case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
} 


void zhuyemian()
{
    system("cls");
	printf("\n\n\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t\t  ★                           教务管理系统                         ★\n");
	printf("\t\t\t  ★                       -------------------                      ★\n");
	printf("\t\t\t  ★                           1.管理登录                           ★\n");
	printf("\t\t\t  ★                           2.教师登录                           ★\n");
	printf("\t\t\t  ★                           3.学生登录                           ★\n");
	printf("\t\t\t  ★                           0.退出系统                           ★\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("                                                      请输入选择: ");
	scanf("%d",&sf);
	printf("\n");
	if(sf==0)
    	tuichu();
    else if(sf!=1&&sf!=2&&sf!=3)
		zhuyemian();
	else
	{
		printf("                                                      请输入账号: ");
        scanf("%s",&zh);
        printf("\n"); 
        printf("                                                      请输入密码: ");
         
		miwenshuru(mm);
     	printf("\n");
    	printf("\t\t\t                                 ");
	}
}

void denglu()
{
	int i;
	int canshua=0;
	FILE *fp;
	if((fp=fopen("zhanghaomima.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;i<1000;i++)
	         fscanf(fp,"%d%s%s",&yanzheng[i].shenfen,yanzheng[i].zhanghao,yanzheng[i].mima);
	fclose(fp);
	for(i=0;i<1000;i++)
		 if(strcmp(zh,yanzheng[i].zhanghao)==0&&strcmp(mm,yanzheng[i].mima)==0&&sf==yanzheng[i].shenfen)
			 {       	
				 canshua=1;
		         break;
			 }	      	 
    if(canshua!=1)
    main();
}

void xuesheng()
{ 
	system("cls");
    printf("\n\n\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t\t  ★                       教务管理系统学生页面                     ★\n");
	printf("\t\t\t  ★                       -------------------                      ★\n");
	printf("\t\t\t  ★                           1.查询成绩                           ★\n");
	printf("\t\t\t  ★                           2.查询信息                           ★\n");
	printf("\t\t\t  ★                           3.更改密码                           ★\n");
	printf("\t\t\t  ★                           0.返回上一级                         ★\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");   
    printf("\n");
	int a;
	printf("                                                      请输入选择: ");
	scanf("%d",&a);
	switch(a)
	{
	case 1:chengjichaxun();break;
	case 2:xinxichaxun();break;
	case 3:mimagenggai();break;
	case 0:main();
	default:xuesheng();
	}
}

void guanli()
{
	system("cls");
    printf("\n\n\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t\t  ★                       教务管理系统管理页面                     ★\n");
	printf("\t\t\t  ★                       -------------------                      ★\n");
	printf("\t\t\t  ★                           1.添加账号                           ★\n");
	printf("\t\t\t  ★                           2.查询密码                           ★\n");
    printf("\t\t\t  ★                           3.删除账号                           ★\n");
	printf("\t\t\t  ★                           4.信息添加                           ★\n");
	printf("\t\t\t  ★                           0.返回上一级                         ★\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");   
    printf("\n");
    int a;
	printf("                                                      请输入选择: ");
	scanf("%d",&a);
	switch(a)
	{
	case 1:zhanghaotianjia();break;
	case 2:chaxunmima();break;
	case 3:zhanghaoshanchu();break;
    case 4:xinxitianjia();break;
	case 0:main();
	default:guanli();
	}
}

void jiaoshi()
{
	system("cls");
    printf("\n\n\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t\t  ★                       教务管理系统教师页面                     ★\n");
	printf("\t\t\t  ★                       -------------------                      ★\n");
	printf("\t\t\t  ★                           1.成绩录入                           ★\n");
	printf("\t\t\t  ★                           2.成绩查询                           ★\n");
	printf("\t\t\t  ★                           3.更改密码                           ★\n");
	printf("\t\t\t  ★                           0.返回上一级                         ★\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");   
    printf("\n");
	int a;
	printf("                                                      请输入选择: ");
	scanf("%d",&a);
	switch(a)
	{
	case 1:chengjiluru();break;
	case 2:chaxunchengji();break;
	case 3:mimagenggai();break;;
	case 0:main();
	default:jiaoshi();
	}
}
void tuichu()
{
    system("cls");
	printf("\n\n\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t\t  ★                                                                ★\n");
	printf("\t\t\t  ★                         您已退出系统!!!                        ★\n");
	printf("\t\t\t  ★                                                                ★\n"); 
	printf("\t\t\t  ★                       Goodbye! My friend!                      ★\n");
	printf("\t\t\t  ★                                                                ★\n");
	printf("\t\t\t  ★                                                                ★\n");
	printf("\t\t\t  ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");   
    printf("\n\n\n");
	exit(0);
}

void mimagenggai()
{
    system("cls");
	int i,b;
	int canshua=0;
	char yuanmima[19];
	FILE *fp;
	if((fp=fopen("zhanghaomima.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;yanzheng[i].shenfen!='\0';i++)
	fscanf(fp,"%d%s%s",&yanzheng[i].shenfen,yanzheng[i].zhanghao,yanzheng[i].mima);
	fclose(fp);
	printf("\n\n\n\n\n                                         请输入选择(当输入1继续,输入0返回):");
	scanf("%d",&b);
	if(b==0)
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
	printf("                                         请输入原密码:");
	miwenshuru(yuanmima);
	for(i=0;yanzheng[i].shenfen!='\0';i++)
		 if(strcmp(zh,yanzheng[i].zhanghao)==0&&strcmp(yuanmima,yanzheng[i].mima)==0)
			 {   
			     
			     printf("                                         请输入新密码:");
                 miwenshuru(yanzheng[i].mima);
                 
				 printf("\t\t\t              ▲是否保存(当输入1保存，输入0不保存):");
                 scanf("%d",&b);
                 if(b==1)
				 {
                 if((fp=fopen("zhanghaomima.txt","w"))==NULL)
					{ 
		            printf("can not");
	             	exit(0);
					}
				 for(i=0;yanzheng[i].shenfen!='\0';i++)
                 fprintf(fp,"%d %s %s \n",yanzheng[i].shenfen,yanzheng[i].zhanghao,yanzheng[i].mima);
				 fclose(fp);
				 printf("                                                 (更改成功)\n");
	             printf("                                         输入任意数字返回上一级:");
	             scanf("%d",&b);
	             switch(sf)
				 {
	            	case 1:guanli();break;
	            	case 2:jiaoshi();break;
	            	case 3:xuesheng();break;
				 }
				 canshua=1;
		         break;
				 }
				 else
                 switch(sf)
				 {
	            	case 1:guanli();break;
	            	case 2:jiaoshi();break;
	            	case 3:xuesheng();break;
				 }
			 }	      	 
    if(canshua!=1)
    mimagenggai();
}
void chengjiluru()
{
	system("cls");
	int i;
	int canshua=0;
	int b;
    canshue luru;
	FILE *fp;
	if((fp=fopen("chengji.txt","a"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	printf("\n\n\n\n\n");
    printf("                                         请输入学号:");
    scanf("%s",luru.xuehao) ;
	printf("\n");
    printf("                                         请输入科目和成绩:");
    scanf("%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d",
		   luru.kemu1 ,&luru.fenshu1,luru.kemu2 ,&luru.fenshu2,luru.kemu3 ,&luru.fenshu3,
		   luru.kemu4 ,&luru.fenshu4,luru.kemu5 ,&luru.fenshu5,luru.kemu6 ,&luru.fenshu6,
		   luru.kemu7 ,&luru.fenshu7,luru.kemu8 ,&luru.fenshu8);
	printf("\n");
    printf("\t\t\t              ▲是否保存(当输入1保存，输入0不保存):");
	scanf("%d",&b);
	if(b==1)
    {
		fprintf(fp,"%s %s %d %s %d %s %d %s %d %s %d %s %d %s %d %s %d \n",luru.xuehao ,
		luru.kemu1 ,luru.fenshu1,luru.kemu2 ,luru.fenshu2,luru.kemu3 ,luru.fenshu3,luru.kemu4 ,luru.fenshu4,
		luru.kemu5 ,luru.fenshu5,luru.kemu6 ,luru.fenshu6,luru.kemu7 ,luru.fenshu7,luru.kemu8 ,luru.fenshu8);
        fclose(fp);
        printf("\n"); 
		printf("                                                 (保存成功)\n");
		printf("\n");
	    printf("                                         输入任意数字返回上一级:");
	    scanf("%d",&b);
	    switch(sf)
		{
	     	case 1:guanli();break;
	    	case 2:jiaoshi();break;
	    	case 3:xuesheng();break;
		}
	}
	else
    switch(sf)
		{
	     	case 1:guanli();break;
	    	case 2:jiaoshi();break;
	    	case 3:xuesheng();break;
		}

}

void zhanghaotianjia()
{
	system("cls");
	printf("\n\n\n");
	int i;
	int b;
    canshuc tianjia;
	FILE *fp;
	if((fp=fopen("zhanghaomima.txt","a"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	printf("\n\n\n");
    printf("                                         请输入要添加的身份：");
    scanf("%d",&tianjia.shenfen );	
	printf("\n");
	printf("                                         请输入要添加的学号：");
    scanf("%s",tianjia.zhanghao );
    printf("\n");
	printf("                                         请输入要添加的密码：");
    scanf("%s",tianjia.mima );
    printf("\n");  

    printf("\t\t\t              ▲是否保存(当输入1保存，输入0不保存) :");
	scanf("%d",&b);
	printf("\n");
	if(b==1)
    {
		fprintf(fp,"%d %s %s \n",tianjia.shenfen ,tianjia.zhanghao ,tianjia.mima );
       	fclose(fp);
		printf("                                                 (添加成功)\n");
		printf("\n");
	    printf("                                         输入任意数字返回上一级:");
	    scanf("%d",&b);
	    switch(sf)
		{
	     	case 1:guanli();break;
	    	case 2:jiaoshi();break;
	    	case 3:xuesheng();break;
		}
	}
	else
    switch(sf)
		{
	     	case 1:guanli();break;
	    	case 2:jiaoshi();break;
	    	case 3:xuesheng();break;
		}

}
void chengjichaxun()
{
    system("cls");
	int i,b;
	FILE *fp;
    canshue chengji[1000];
	if((fp=fopen("chengji.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;i<1000;i++)
	   fscanf(fp,"%s%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d",chengji[i].xuehao ,
	          chengji[i].kemu1 ,&chengji[i].fenshu1,chengji[i].kemu2 ,&chengji[i].fenshu2,
	          chengji[i].kemu3 ,&chengji[i].fenshu3,chengji[i].kemu4 ,&chengji[i].fenshu4,
	          chengji[i].kemu5 ,&chengji[i].fenshu5,chengji[i].kemu6 ,&chengji[i].fenshu6,
	          chengji[i].kemu7 ,&chengji[i].fenshu7,chengji[i].kemu8 ,&chengji[i].fenshu8);
   	fclose(fp);
	for(i=0;i<1000;i++)
	if(strcmp(zh,chengji[i].xuehao)==0)
			 {       	
				 printf("\n\n\n\n\n                                              %s\n\n",chengji[i].xuehao );				     	
				 printf("                                              %s:%d\n",chengji[i].kemu1 ,chengji[i].fenshu1);		     	
				 printf("                                              %s:%d\n",chengji[i].kemu2 ,chengji[i].fenshu2);
				 printf("                                              %s:%d\n",chengji[i].kemu3 ,chengji[i].fenshu3);
				 printf("                                              %s:%d\n",chengji[i].kemu4 ,chengji[i].fenshu4);
				 printf("                                              %s:%d\n",chengji[i].kemu5 ,chengji[i].fenshu5);
				 printf("                                              %s:%d\n",chengji[i].kemu6 ,chengji[i].fenshu6);
				 printf("                                              %s:%d\n",chengji[i].kemu7 ,chengji[i].fenshu7);
				 printf("                                              %s:%d\n\n",chengji[i].kemu8 ,chengji[i].fenshu8);
		         break;
			 }	   
    printf("                                        输入任意数字返回上一级:");
	scanf("%d",&b);
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
}
void zhanghaoshanchu()
{
    system("cls");
	int i,j,k,b;
	int canshua=0;
	char zhanghao[11];
	FILE *fp;
	if((fp=fopen("zhanghaomima.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;yanzheng[i].shenfen!='\0';i++)
	fscanf(fp,"%d%s%s",&yanzheng[i].shenfen,yanzheng[i].zhanghao,yanzheng[i].mima);
	fclose(fp);
	printf("\n\n\n\n\n");
	printf("                                         请输入选择(当输入1继续,输入0返回):");
	scanf("%d",&b);
	if(b==0)
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
	printf("\n");
	printf("                                         请输入要删除的账号:");
	scanf("%s",&zhanghao);
	printf("\n");
	for(i=0;i<1000;i++)
		 if(strcmp(zhanghao,yanzheng[i].zhanghao)==0)
			 {   
			      canshug xinxi[1000];
	              if((fp=fopen("xinxi.txt","r"))==NULL)
				  { 
		              printf("can not");
		              exit(0);
				  }
             	 for(k=0;k<1000;k++)
	             fscanf(fp,"%s%s%s%s",xinxi[k].xuehao,xinxi[k].xingming ,xinxi[k].xueyuan ,xinxi[k].banji);
                 for(k=0;k<1000;k++)
	             if(strcmp(zhanghao,xinxi[k].xuehao)==0)
				 {       	
				     printf("                                         学号：%s\n                                         姓名：%s\n                                         学院：%s\n                                         班级：%s\n\n", 
					    xinxi[k].xuehao,xinxi[k].xingming ,xinxi[k].xueyuan ,xinxi[k].banji); 
		             break;
				 }
				 fclose(fp);
			     printf("                                         是否删除（输入1删除，输入0不删除）：");
				 scanf("%d",&b);
                 if(b==1)
				 {
			     for(j=i;yanzheng[j].shenfen!='\0';j++)
				 {
				    yanzheng[j].shenfen=yanzheng[j+1].shenfen;
				    strcpy(yanzheng[j].zhanghao,yanzheng[j+1].zhanghao);			    
				    strcpy(yanzheng[j].mima,yanzheng[j+1].mima);
				 }
			     if((fp=fopen("zhanghaomima.txt","w"))==NULL)
					{ 
		            printf("can not");
	             	exit(0);
					}
                 for(i=0;yanzheng[i].shenfen!='\0';i++)
                 fprintf(fp,"%d %s %s \n",yanzheng[i].shenfen,yanzheng[i].zhanghao,yanzheng[i].mima);
				 fclose(fp);
				 canshua=1;
		         break;
				 }
				 else
                 switch(sf)
				 {
	            	case 1:guanli();break;
	            	case 2:jiaoshi();break;
	            	case 3:xuesheng();break;
				 }
			 }	      	 
    if(canshua!=1)
    zhanghaoshanchu();
    printf("                                               (删除成功)\n");
    printf("                                         输入任意数字返回上一级\n");
	scanf("%d",&b);
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
}

void xinxitianjia()
{
	system("cls");
	int i;
	int canshua=0;
	int b;
    canshug xinxi;
	FILE *fp;
	if((fp=fopen("xinxi.txt","a"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	printf("\n\n\n\n\n");
    printf("                                                 请输入学号:");
    scanf("%s",xinxi.xuehao);
    printf("\n");
    printf("                                                 请输入姓名:");
    scanf("%s",xinxi.xingming);
    printf("\n");
    printf("                                                 请输入学院:");
    scanf("%s",xinxi.xueyuan);
    printf("\n");
    printf("                                                 请输入班级:");
    scanf("%s",xinxi.banji);	
	printf("\n");
	
	 printf("\t\t\t              ▲是否保存(当输入1保存，输入0不保存) :");
	scanf("%d",&b);	
	if(b==1)
    {
		fprintf(fp,"%s %s %s %s \n",xinxi.xuehao,xinxi.xingming,xinxi.xueyuan,xinxi.banji);
    fclose(fp);
    printf("\n");
	printf("                                                 (保存成功)\n");
	printf("\n");
	printf("                                           输入任意数字返回上一级:");
	scanf("%d",&b);
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
	}
	else
    switch(sf)
		{
	     	case 1:guanli();break;
	    	case 2:jiaoshi();break;
	    	case 3:xuesheng();break;
		}
	

}

void xinxichaxun()
{
    system("cls");
	int i,b;
	FILE *fp;
    canshug xinxi[1000];
	if((fp=fopen("xinxi.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;i<1000;i++)
	   fscanf(fp,"%s%s%s%s",xinxi[i].xuehao,xinxi[i].xingming ,xinxi[i].xueyuan ,xinxi[i].banji);
   	for(i=0;i<1000;i++)
	if(strcmp(zh,xinxi[i].xuehao)==0)
			 {   
			 	printf("\n\n\n\n\n");    	
				printf("                                                 学号：%s\n", 
					    xinxi[i].xuehao); 
				printf("                                                 姓名：%s\n", 
					    xinxi[i].xingming);
				printf("                                                 学院：%s\n", 
					    xinxi[i].xueyuan );
				printf("                                                 班级：%s\n", 
					    xinxi[i].banji);
		         break;
			 }	   
   	fclose(fp);
	printf("\n\n");
	printf("                                           输入任意数字返回上一级:");
	scanf("%d",&b);
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
}

void chaxunmima()
{
    system("cls");
	int i,b;
	int canshua=0;
	char chaxunmima[19];
	FILE *fp;
	if((fp=fopen("zhanghaomima.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;yanzheng[i].shenfen!='\0';i++)
	fscanf(fp,"%d%s%s",&yanzheng[i].shenfen,yanzheng[i].zhanghao,yanzheng[i].mima);
	fclose(fp);
	printf("\n\n\n\n\n                                         请输入选择(当输入1继续,输入0返回):");
	scanf("%d",&b);
	if(b==0)
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
	printf("                                         账号:");
	scanf("%s",&chaxunmima);
    for(i=0;i<1000;i++)
	if(strcmp(chaxunmima,yanzheng[i].zhanghao)==0)
	{
		printf("                                         密码:%s\n",yanzheng[i].mima);
        canshua=1;
		break;
	}
  
	printf("                                         输入任意数字返回上一级:");
	scanf("%d",&b);
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}

}
void chaxunchengji()
{
    system("cls");
	int i,b;
	FILE *fp;
	char chaxunxuehao[11];
    canshue chengji[1000];
	if((fp=fopen("chengji.txt","r"))==NULL)
	{ 
		 printf("can not");
		 exit(0);
	}
	for(i=0;i<1000;i++)
	   fscanf(fp,"%s%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d",chengji[i].xuehao ,
	          chengji[i].kemu1 ,&chengji[i].fenshu1,chengji[i].kemu2 ,&chengji[i].fenshu2,
	          chengji[i].kemu3 ,&chengji[i].fenshu3,chengji[i].kemu4 ,&chengji[i].fenshu4,
	          chengji[i].kemu5 ,&chengji[i].fenshu5,chengji[i].kemu6 ,&chengji[i].fenshu6,
	          chengji[i].kemu7 ,&chengji[i].fenshu7,chengji[i].kemu8 ,&chengji[i].fenshu8);
   	fclose(fp);
	printf("\n\n\n\n\n                                        请输入查询学号");
    scanf("%s",&chaxunxuehao);
	for(i=0;i<1000;i++)
	if(strcmp(chaxunxuehao,chengji[i].xuehao)==0)
			 {       	
				 printf("                                              %s\n\n",chengji[i].xuehao );				     	
				 printf("                                              %s:%d\n",chengji[i].kemu1 ,chengji[i].fenshu1);		     	
				 printf("                                              %s:%d\n",chengji[i].kemu2 ,chengji[i].fenshu2);
				 printf("                                              %s:%d\n",chengji[i].kemu3 ,chengji[i].fenshu3);
				 printf("                                              %s:%d\n",chengji[i].kemu4 ,chengji[i].fenshu4);
				 printf("                                              %s:%d\n",chengji[i].kemu5 ,chengji[i].fenshu5);
				 printf("                                              %s:%d\n",chengji[i].kemu6 ,chengji[i].fenshu6);
				 printf("                                              %s:%d\n",chengji[i].kemu7 ,chengji[i].fenshu7);
				 printf("                                              %s:%d\n\n",chengji[i].kemu8 ,chengji[i].fenshu8);
		         break;
			 }	   
    printf("                                        输入任意数字返回上一级:");
	scanf("%d",&b);
	switch(sf)
	{
	   	case 1:guanli();break;
		case 2:jiaoshi();break;
		case 3:xuesheng();break;
	}
}

void miwenshuru(char *miwen)
{
char ch = 0;
int i = 0;
while(i<18)
{
ch = getch();

if(ch == '\r')
{ 
printf("\n");
break;
}
if(ch=='\b' && i>0)
{ 
i--;
printf("\b \b");
}
else
{ 
printf("%c",ch);
Sleep(500);
printf("\b");
miwen[i] = ch;
printf("*");
i++;
}
}
miwen[i] = 0;
}

