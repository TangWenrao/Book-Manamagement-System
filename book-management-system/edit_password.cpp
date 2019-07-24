#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int edit_password(int id){
	int newpd1=0,newpd2=0,i=0,n=0,total=0;
	char std[100];
	char pd[100][10];
	int istd;
	FILE*p;
	FILE*p2;
	p=fopen("id.txt","r+");
	p2=fopen("password.txt","r+");
	if(p==NULL){
		printf("???\n");
	}
	if(p2==NULL){
		printf("???\n");
	}
p1:	printf("请输入新密码\n");
	scanf("%d",&newpd1);
	printf("再次输入新密码\n");
	scanf("%d",&newpd2);
	if(newpd1!=newpd2){
		printf("两次输入密码不一致，请重新输入\n");
		goto p1;
	}
//	printf("1\n");
	for(total=0;!feof(p);total++){
		fgets(std,10,p);
	}
//	printf("\t%d\n",total);
	for(n=0;!feof(p);n++){
		fscanf(p,"%s",std);
		istd=atoi(std);
//		printf("%d\n",istd);
		if(istd==id)
			break;
	}
//	printf("\t%d\n",n);
	for(i=0;!feof(p2);i++){
		fscanf(p2,"%s",pd[i]);
//		printf("%s\n",pd[i]);
	}
	itoa(newpd1,std,10);
	strcpy(pd[n+1],std);
//	pd[n]=newpd1;
	fclose(p2);
	fclose(p);
	p2=fopen("password.txt","w");
	for(i=0;i<total;i++){
		fprintf(p2,"%s\n",pd[i]);
	}
	
	fclose(p2);
	printf("修改密码成功\n");
}
int main(){
	edit_password(2018);
	return 0;
}
