#include <stdio.h>
#include<string.h> 
int main(){
	char a[101],b[101];
	scanf("%s %s",a,b); 
	int f;
	f=strstr(a,b);
	printf("%s\n",strstr(a,b));
	printf("%d\n",strlen(a)+1-strlen(strstr(a,b))); 
	/* char *temp=strstr(a,b);
	printf("%s\n",temp);
	int length=strlen(a)+1-strlen(b);
	printf("%d\n",length);*/
	return 0; 

} 
