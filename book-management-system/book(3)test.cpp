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
/*	FILE *p;
	p=fopen("bookstorage.txt","r+");
	if(p==NULL){
		printf("ERROR\n");
	}*/
/*	for(i=0;(fscanf(p,"s",s))!=EOF;i++){
//		fscanf(p,"%s",book[i].book_name);
		printf("%s ",book[i].book_name);
//		fscanf(p,"%s",book[i].writer);
		printf("%s ",book[i].writer);
//		fscanf(p,"%s",book[i].book_num);
		printf("%s ",book[i].book_num);
//		fscanf(p,"%s",book[i].place);
		printf("%s\n",book[i].place);
	}*/
//	fclose(p);
	for()
	
}
int book_struct2(FILE*p2,int amount){//书库书籍导入结构体
	int i=0; 
	for(i=0;i<amount;i++){
		fscanf(p2,"%s",book[i].book_name);
	//	fscanf(p,"s",book_ck[i].book_name);
		fscanf(p2,"%s",book[i].writer);
	//	fscanf(p,"s",book_ck[i].writer);
		fscanf(p2,"%s",book[i].book_num);
		fscanf(p2,"%s",book[i].place);
	//	fscanf(p,"d",book_ck[i].state);
	}
}
int book_print(int i){//图书输出函数 
//	fscanf(p,"%s",book[i].book_name);
	printf("%-12s ",book[i].book_name);
//	fscanf(p,"%s",book[i].writer);
	printf("%-12s ",book[i].writer);
//	fscanf(p,"%s",book[i].book_num);
	printf("%-5s ",book[i].book_num);
//	fscanf(p,"%s",book[i].place);
	printf("%-5s\n",book[i].place);
	return 0;
} 
/*int book_print(FILE*p,int i){//图书输出函数 
	fscanf(p,"%s",&book[i].book_name);
	printf("%-12s ",book[i].book_name);
	fscanf(p,"%s",book[i].writer);
	printf("%-12s ",book[i].writer);
	fscanf(p,"%s",book[i].book_num);
	printf("%-5s ",book[i].book_num);
	fscanf(p,"%s",book[i].place);
	printf("%-5s\n",book[i].place);
	return 0;
} */
int test(){
	FILE*p;
	p=fopen("bookstorage.txt","r+");
	book_struct2(p,13);
	for(int i=0;i<13;i++){
		book_print(i);
	}
	
}
int main(){
	//book_input();
	book_through();
	test();
	return 0;
}
