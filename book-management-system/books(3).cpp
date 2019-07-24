#include <stdio.h>
struct books{
	char book_name[20];
	char book_num[10];
	char writer[15];
	char place[15];
}book[300];
int book_input(){
	FILE *p;
	p=fopen("bookstorage.txt","a+");
	if(p==NULL){
		printf("ERROR\n");
	}
	printf("请输入书名\n");
	scanf("%s",&book[0].book_name);
	fprintf(p,"%s ",book[0].book_name);
	printf("请输入作者\n");
	scanf("%s",&book[0].writer);
	fprintf(p,"%s ",book[0].writer);
	printf("请输入书号\n");
	scanf("%s",&book[0].book_num);
	fprintf(p,"%s ",book[0].book_num);
	printf("请输入位置\n");
	scanf("%s",&book[0].place);
	fprintf(p,"%s\n",book[0].place);
	fclose(p);
	return 0;
}
int book_through(){
	int i=0;
	char s[20];
	FILE *p;
	p=fopen("bookstorage.txt","r+");
	if(p==NULL){
		printf("ERROR\n");
	}
	for(i=0;(fscanf(p,"s",s))!=EOF;i++){
		fscanf(p,"%s",book[i].book_name);
		printf("%s ",book[i].book_name);
		fscanf(p,"%s",book[i].writer);
		printf("%s ",book[i].writer);
		fscanf(p,"%s",book[i].book_num);
		printf("%s ",book[i].book_num);
		fscanf(p,"%s",book[i].place);
		printf("%s\n",book[i].place);
	}
	fclose(p);
	
}
int main(){
	//book_input();
	book_through();
	return 0;
}
