#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h> 
#include<stdio.h>//
#include<stdlib.h>//
#include<string.h>
#include<time.h>
#include<Windows.h>//颜色需求
//#define FilePath "couen.txt"
void guihuan(struct book *head);
struct d
{
char name[100];
char mima[100];
};
d p, q, m;
typedef struct enter
{
d xx;
struct enter *next;
}E;
char root[] = "root";
char roo[] = "123";
void en()
{


FILE *fp;
d bookinfo[20];
d l;
int n = 1, x = 1;
int g = 0;
int booknumber = 0;
if ((fp = fopen("couen.txt", "rb")) == NULL)
printf("失败");


while (!feof(fp))
{
fread(&bookinfo[booknumber], sizeof(d), 1, fp);
booknumber++;
}
booknumber--;
fclose(fp);
while (n)
{
char a[100], b[100];
printf(" 请输入你的用户名           \n");
scanf("%s", a);
printf(" 请输入你的密码           \n");
scanf("%s", b);
system("cls");
/*booknumber--;使用feof()函数会多读一行，因此需要booknumber自减一次，使书目的数量正确*/
strcpy(l.name, a);
strcpy(l.mima, b);
system("pause");
for (g = 0; g <= booknumber; g++)
{


if (strcmp(l.name, bookinfo[g].name) == 0 && strcmp(l.mima, bookinfo[g].mima) == 0)
{
printf("验证正确\n");
system("cls");
printf("正在进入系统请稍后.\n");
_sleep(500);
system("cls");
printf("正在进入系统请稍后..\n");
_sleep(500);
system("cls");
printf("正在进入系统请稍后...\n");
_sleep(500);
system("cls");
printf("正在进入系统请稍后.\n");
_sleep(500);
system("cls");
printf("正在进入系统请稍后..\n");
_sleep(500);
system("cls");
printf("正在进入系统请稍后...\n");
n = 0;
x = 2;
break;
system("cls");
}
}
if (x == 1)
{
printf("请检查账户或密码是否正确\n");
printf("然后重新输入\n");
system("pause");
}
}
}
void zc()
{
int t = 1;
E *hea;
char a[100], b[100], c[] = "123";
FILE* fp;
if ((fp = fopen("couen.txt", "ab")) == NULL)
{
printf("无法创建计数器文件！\n");
return;
}
fp = fopen("couen.txt", "ab");
printf(" 请输入你想要的的用户名      \n");
scanf("%s", a);
printf(" 请输入你想要的密码           \n");
scanf("%s", b);
strcpy(p.name, a);
strcpy(p.mima, b);
fwrite(&p, sizeof(d), 1, fp);
fclose(fp);
}
struct book {
int num;
char bname[50];
char wname[20];
char press[50];
char sort[50];
int time;
float price;
int islended;
int counter;
struct book *next;
};
int gotoxy(int x, int y)
{
HANDLE hout;
COORD coord;
coord.X = x;
coord.Y = y;
hout = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hout, coord);
return 0;
}
void jieshu(struct book *head);
void paixu();
struct book *creatbook();                          //创建链表
struct book *addbook(struct book *head);           //添加图书
int yanzheng(struct book *head, int m);             //验证新添加的图书编码是否已存在
void deletebook(struct book *head);                //删除图书
void fprint(struct book *head);                    //将链表写入文件
struct book *load();                               //从文件中读取信息并建成链表
void print_book(struct book *head);                //将链表信息输出
void chaxun(struct book *head);                    //查询图书信息
void num_chaxun(struct book *head);                //按图书编号查询图书
void wname_chaxun(struct book *head);              //按作者名查询图书
void sort_chaxun(struct book *head);               //按类别查询图书
void time_chaxun(struct book *head);               //按出版时间查询图书
void bname_chaxun(struct book *head);              //按图书名查询图书
void xiugai(struct book *head);                    //修改图书信息
int main()
{
int m, cv = 1;
system("color 4a");
printf("\n\n\n\n\n");
printf(" \t\t\t             登录界面           \n\n");
printf(" \t\t\t|----------------------------|\n");
printf(" \t\t\t| 有账户可登录，（没有请注册 | \n");
printf(" \t\t\t|           按 1进入登录     | \n");
printf(" \t\t\t|           按 2进入注册     | \n");
printf(" \t\t\t|           按 3第三方登录   |\n");
printf(" \t\t\t|----------------------------|\n");


while (cv)
{
scanf("%d", &m);
switch (m)
{
case 1:
en();
cv = 0;
break;
case 2:zc();
cv = 0;
printf("注册成功将自动退出请重新登录\n");
system("pause");
exit(1);
break;;
case 3:
printf("按1 微信登录\n");
printf("按2 qq登录\n");
printf("按3 微博登录\n");
system("pause");
printf("当然是骗你的了\n");
system("pause");
cv = 0;
exit(1);
break;
default:
printf("输入错误请重新输入\n");
break;
}
}
char key, z;
int o = 40, p = 4;
int choice, x;
char a, d, b[10], b1[10], c1[10], c[10];
struct book *head = NULL;
while (1)
{
system("cls");
system("color 4a");
printf("\n");
system("cls");
system("color 4a");


printf(" ----------------------图书管理系统-----------------------\n");
printf(" ---------------------------------------------------------\n");


printf("       |\t\t   1 添加图书\t\t\t\t|\n");
printf("       |\t\t   2 删除图书\t\t\t\t|\n");
printf("       |\t\t   3 图书列表\t\t\t\t|\n");
printf("       |\t\t   4 查询图书\t\t\t\t|\n");
printf("       |\t\t   5 修改图书\t\t\t\t|\n");
printf("       |\t\t   6 录入数据\t\t\t\t|\n");
printf("       |\t\t   7 借阅图书\t\t\t\t|\n");
printf("       |\t\t   8 归还图书\t\t\t\t|\n");
printf("       |\t\t   9 借阅排行\t\t\t\t|\n");
printf("       |\t\t   0 退出系统\t\t\t\t|\n");
printf(" ---------------------------------------------------------\n");
printf("\t\t\t\t请输入所选择的序号:");
scanf("%d", &choice);
getchar();
system("cls");
switch (choice)
{
case 7:
head = load();
jieshu(head);
fprint(head);
getchar();
break;
case 8:
head = load();
guihuan(head);
fprint(head);
system("pause");
break;
case 9:
head = load();
paixu();
fprint(head);
getchar();
break;
case 0:
x = 0; break;
case 1:
head = load();
if (head == NULL) {
printf("文件为空,请先录入数据!\n");
getchar();
break;
}
else {
head = addbook(head);
printf("添加成功!\n");
printf("是否将新信息保存到文件?(e/n)\n");
scanf("%c", &a);
getchar();
switch (a) {
case 'n':
break;
case 'e':
fprint(head);
printf("保存成功!\n");
getchar();
break;
}
break;
}


case 2:
head = load();
if (head == NULL) {
printf("文件为空,请先录入数据!\n");
getchar();
break;
}


else {
deletebook(head);
getchar();
break;
}
break;
case 3:
head = load();
if (head == NULL) {
printf("文件为空,请先录入数据!\n");
getchar();
break;
}
else {
print_book(head);
getchar();
break;
}


case 4:
head = load();
if (head == NULL) {
printf("文件为空,请先录入数据!\n");
getchar();
break;
}
else {
chaxun(head);
getchar();
}
break;
case 5:
head = load();
if (head == NULL) {
printf("文件为空,请先录入数据!\n");
getchar();
break;
}
else {
xiugai(head);
getchar();
break;
}
break;
case 6:
printf("注意:输入图书编码为0时结束!\n");
head = creatbook();
printf("是否将输入的信息保存到文件以覆盖文件中已存在的信息?(e/n)\n");
getchar();
scanf("%c", &a);
getchar();
switch (a) {
case 'n':
break;
case 'e':
fprint(head);
printf("保存成功!\n");
getchar();
break;
}
break;
default:
printf("您的输入有误,请重新输入!\n");
getchar();
break;
}
}
}
//录入数据并形成链表


void paixu()
{
struct book *ptr;
struct book *list;
list = load();
struct book *p, *q;


int t;
int num;
char bname2[50];
for (p = list; p != NULL; p = p->next)


{


for (q = p->next; q != NULL; q = q->next)


{


if (p->counter<q->counter)//降序 


{


t = q->counter;


q->counter = p->counter;


p->counter = t;


t = q->num;
q->num = p->num;
p->num = t;


strcpy(bname2, p->bname);
strcpy(p->bname, q->bname);
strcpy(q->bname, bname2);






}


}


}
ptr = list;
while (ptr)
{
printf(" 编号\t图书名\t次数\n");
printf(" %d\t%s\t%d\n", ptr->num, ptr->bname, ptr->counter);
ptr = ptr->next;
}




}
struct book *creatbook()
{
char r[50];
char ro[50];
printf("需要管理员权限\n请登录\n");
printf("账户\n");
scanf("%s", r);
printf("密码\n");
scanf("%s", ro);
if (strcmp(r, root) != 0 && strcmp(roo, ro) != 0)
{
printf("你不是管理员\n系统将自动退出");
system("pause");
exit(1);
}
struct book *head, *tail, *p;
int num, time, n;
char bname[50], wname[20], press[50], sort[50];
float price;
int size = sizeof(struct book);
head = tail = NULL;
printf("请输入图书编号:");
scanf("%d", &num);
printf("请输入图书名:");
scanf("%s", bname);
getchar();
printf("请输入作者名:");
scanf("%s", wname);
getchar();
printf("请输入出版社:");
scanf("%s", press);
getchar();
printf("请输入类别:");
scanf("%s", sort);
getchar();
printf("请输入出版时间:");
scanf("%d", &time);
getchar();
printf("请输入价格:");
scanf("%f", &price);


getchar();
while (1) {
p = (struct book *)malloc(size);
p->num = num;
strcpy(p->bname, bname);
strcpy(p->wname, wname);
strcpy(p->press, press);
strcpy(p->sort, sort);
p->time = time;
p->price = price;
p->counter = 0;
p->next = NULL;
if (head == NULL)
head = p;
else
tail->next = p;
tail = p;
do {
printf("请输入图书编号:");
scanf("%d", &num);
n = yanzheng(head, num);
if (n == 0)
break;
else
printf("您输入的编号已存在,请重新输入!\n");
} while (1);
if (num == 0)
break;
else
{
printf("请输入图书名:");
scanf("%s", bname);
getchar();
printf("请输入作者名:");
scanf("%s", wname);
getchar();
printf("请输入出版社:");
scanf("%s", press);
getchar();
printf("请输入类别:");
scanf("%s", sort);
getchar();
printf("请输入出版时间:");
scanf("%d", &time);
getchar();
printf("请输入价格:");
scanf("%f", &price);
getchar();
}
}
return head;
}


//插入节点，并且插入后仍按一定顺序
struct book *addbook(struct book *head)
{
char r[50];
char ro[50];
printf("需要管理员权限\n请登录\n");
printf("账户\n");
scanf("%s", r);
printf("密码\n");
scanf("%s", ro);
if (strcmp(r, root) != 0 && strcmp(roo, ro) != 0)
{
printf("你不是管理员\n系统将自动退出");
system("pause");
exit(1);
}
struct book *ptr, *p1, *p2, *p;
char bname[50], wname[20], press[50], sort[50];
int size = sizeof(struct book);
int num, time, n = 1;
float price;
do {
printf("请输入图书编号:");
scanf("%d", &num);
n = yanzheng(head, num);
if (n == 0)
break;
else
printf("您输入的编号已存在,请重新输入!\n");
} while (1);
printf("请输入图书名:");
scanf("%s", bname);
getchar();
printf("请输入作者名:");
scanf("%s", wname);
getchar();
printf("请输入出版社:");
scanf("%s", press);
getchar();
printf("请输入类别:");
scanf("%s", sort);
getchar();
printf("请输入出版时间:");
scanf("%d", &time);
getchar();
printf("请输入价格:");
scanf("%f", &price);
getchar();
p = (struct book *)malloc(size);
p->num = num;
strcpy(p->bname, bname);
strcpy(p->wname, wname);
strcpy(p->press, press);
strcpy(p->sort, sort);
p->time = time;
p->price = price;
p->counter = 0;
p2 = head;
ptr = p;
while ((ptr->num>p2->num) && (p2->next != NULL)) {
p1 = p2;
p2 = p2->next;
}
if (ptr->num <= p2->num) {
if (head == p2)
head = ptr;
else {
p1->next = ptr;
p->next = p2;
}
}
else {
p2->next = ptr;
p->next = NULL;
}
return head;
}
//验证添加的图书编号是否已存在
int yanzheng(struct book *head, int m)
{
struct book *p;
p = head;
while (p != NULL)
{
if (p->num == m)
break;
p = p->next;
}
if (p == NULL)
return 0;
else
return 1;
}




//从文件中读取图书信息
struct book *load()
{
FILE *fp;
char ch;
struct book *head, *tail, *p1;
head = tail = NULL;
if ((fp = fopen("f1.txt", "r")) == NULL) {
printf("File open error!\n");
exit(0);
}
ch = fgetc(fp);
if (ch == '1') {


while (!feof(fp)) {
p1 = (struct book *)malloc(sizeof(struct book));
fscanf(fp, "%d%s%s%s%s%d%f%d\n", &p1->num, p1->bname, p1->wname, p1->press, p1->sort, &p1->time, &p1->price, &p1->counter);
if (head == NULL)
head = p1;
else
tail->next = p1;
tail = p1;
}
tail->next = NULL;
fclose(fp);
return head;
}
else
return NULL;


}
//将整个链表的信息输出
void print_book(struct book *head)
{
struct book *ptr;
if (head == NULL) {
printf("\n没有信息!\n");
return;
}
printf("                                 图书信息如下\n");
printf(" ==========================================================\n");
printf(" 编号\t图书名\t作者名\t出版社\t类别\t出版时间\t价格\n");
for (ptr = head; ptr; ptr = ptr->next)
printf(" %d\t%s\t%s\t%s\t%s\t%d\t\t%.2f\n", ptr->num, ptr->bname, ptr->wname, ptr->press, ptr->sort, ptr->time, ptr->price);
printf(" ==========================================================\n");
}
//删除图书信息
void deletebook(struct book *head)
{
char r[50];
char ro[50];
printf("需要管理员权限\n请登录\n");
printf("账户\n");
scanf("%s", r);
printf("密码\n");
scanf("%s", ro);
if (strcmp(r, root) != 0 && strcmp(roo, ro) != 0)
{
printf("你不是管理员\n系统将自动退出");
system("pause");
exit(1);
}
int a;
char b, ch = '1';
struct book *p1, *p2;
FILE *fp;
printf("请输入要删除的图书编号:");
scanf("%d", &a);
p1 = head;
if (p1->num == a&&p1->next == NULL) {          //对于文件中只有一组数据
printf("是否清空文件!(y/n)\n");
getchar();
scanf("%c", &b);
getchar();
switch (b) {
case 'n':
break;
case 'y':


if ((fp = fopen("f1.txt", "w")) == NULL) {
printf("File open error!\n");
exit(0);
}
fclose(fp);
printf("文件已清空!\n");
}
}
else {
while (p1->num != a&&p1->next != NULL) {
p2 = p1;
p1 = p1->next;
}


if (p1->next == NULL) {
if (p1->num == a) {
p2->next = NULL;
printf("是否确定从文件中彻底删除该图书?(y/n)\n");
getchar();
scanf("%c", &b);


switch (b) {
case 'n':
break;
case 'y':
fprint(head);
printf("删除成功!\n");
getchar();
break;
}
}


else {
printf("没有找到要删除的数据!\n");
getchar();
}
}
else if (p1 == head) {
head = p1->next;
printf("是否确定从文件中彻底删除该图书?(y/n)\n");
getchar();
scanf("%c", &b);


switch (b) {
case 'n':
break;
case 'y':
fprint(head);
printf("删除成功!\n");
getchar();
break;
}


}
else {
p2->next = p1->next;
printf("是否确定从文件中彻底删除该图书?(y/n)\n");
getchar();
scanf("%c", &b);


switch (b) {
case 'n':
break;
case 'y':
fprint(head);
printf("删除成功!\n");
getchar();
break;
}
}
}


}
//图书查询
void chaxun(struct book *head)
{
int a;
printf("               ==========================================================\n");
printf("               |       1-按图书编号查询        2-按图书名查询           | \n");
printf("               |       3-按图书类别查询        4-按作者名查询           | \n");
printf("               |       5-按出版时间查询        0-退出查询               | \n");
printf("               ==========================================================\n");
printf("请输入所选择的编号:");
scanf("%d", &a);
getchar();
switch (a) {
case 0:
break;
case 1:
num_chaxun(head);
break;
case 2:
bname_chaxun(head);
break;
case 3:
sort_chaxun(head);
break;
case 4:
wname_chaxun(head);
break;
case 5:
time_chaxun(head);
break;
default:
printf("您的输入有误!\n");
break;
}
}
//按编号查询图书信息
void num_chaxun(struct book *head)
{
int a;
struct book *p;
printf("请选择您要查询的图书编号:");
scanf("%d", &a);
getchar();
p = head;
while (p != NULL) {
if (p->num == a)
break;
p = p->next;
}


if (p == NULL) {
printf("没有找到该编号的图书!\n");
}
else {
printf("                        你所查询的图书信息如下\n");
printf(" =========================================================================\n");
printf("   编号    图书名    作者名    出版社    类别    出版时间     价格   \n");
printf("     %d        %s         %s         %s        %s        %d       %.2f  \n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
printf(" =========================================================================\n");
}
}


void jieshu(struct book *head)
{
int choice;
char a[50];
int flag = 0;
struct book *p;
printf("请选择您要查询的图书名:");
scanf("%s", a);
p = head;


while (p != NULL) {
if (strcmp(p->bname, a) == 0) {
flag = 1;
break;
}
p = p->next;
}
if (flag == 0) {
printf("没有找到该图书名的图书!\n");


}
else {
printf("                        你所查询的图书信息如下\n");
printf(" =========================================================================\n");
printf(" **   编号    图书名    作者名    出版社    类别    出版时间     价格   **\n");
while (p != NULL) {
if (strcmp(p->bname, a) == 0) {
printf(" **    %d        %s         %s        %s         %s       %d        %.2f  **\n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
printf("是否借阅书籍？\n");
printf("1 是   2否\n");
scanf("%d", &choice);


switch (choice)


{
case 1:p->islended = 1;
printf("%d", p->counter);
p->counter++;
printf("%d", p->counter);
printf("借阅成功\n");
break;
}
}
p = p->next;
}
printf(" =========================================================================\n");
}


}


//将新链表写入文件中
void fprint(struct book *head)
{
FILE *fp;
char ch = '1';
struct book *p1;
if ((fp = fopen("f1.txt", "wb")) == NULL) {
printf("File open error!\n");
exit(0);
}
fputc(ch, fp);
for (p1 = head; p1; p1 = p1->next) {
fprintf(fp, "%d %s %s %s %s %d %f %d\n", p1->num, p1->bname, p1->wname, p1->press, p1->sort, p1->time, p1->price, p1->counter);
}
fclose(fp);
}
//按图书名查询图书信息
void bname_chaxun(struct book *head)
{
char a[50];
int flag = 0;
struct book *p;
printf("请选择您要查询的图书名:");
scanf("%s", a);
p = head;
while (p != NULL) {
if (strcmp(p->bname, a) == 0) {
flag = 1;
break;
}
p = p->next;
}
if (flag == 0) {
printf("没有找到该图书名的图书!\n");


}
else {
printf("                        你所查询的图书信息如下\n");
printf(" =========================================================================\n");
printf(" **   编号    图书名    作者名    出版社    类别    出版时间     价格   **\n");
while (p != NULL) {
if (strcmp(p->bname, a) == 0) {
printf(" **    %d        %s         %s        %s         %s       %d        %.2f  **\n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
}
p = p->next;
}
printf(" =========================================================================\n");
}


}
//按作者名查询图书信息
void wname_chaxun(struct book *head)
{
char a[50];
int flag = 0;
struct book *p;
printf("请选择您要查询的图书作者名:");
scanf("%s", a);
p = head;
while (p != NULL) {
if (strcmp(p->wname, a) == 0) {
flag = 1;
break;
}
p = p->next;
}
if (flag == 0) {
printf("没有找到该图书名的图书!\n");


}
else {
printf("                        你所查询的图书信息如下\n");
printf(" =========================================================================\n");
printf(" **   编号    图书名    作者名    出版社    类别    出版时间     价格   **\n");
while (p != NULL) {
if (strcmp(p->wname, a) == 0) {
printf(" **    %d        %s         %s        %s         %s       %d        %.2f  **\n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
flag = 1;
}
p = p->next;
}
printf(" =========================================================================\n");
}


}
//按图书类别查询图书信息
void sort_chaxun(struct book *head)
{
char a[50];
int flag = 0;
struct book *p;
printf("请选择您要查询的图书类别:");
scanf("%s", a);
p = head;
while (p != NULL) {
if (strcmp(p->sort, a) == 0) {
flag = 1;
break;
}
p = p->next;
}
if (flag == 0) {
printf("没有找到该图书名的图书!\n");


}
else {
printf("                        你所查询的图书信息如下\n");
printf(" =========================================================================\n");
printf(" **   编号    图书名    作者名    出版社    类别    出版时间     价格   **\n");
while (p != NULL) {
if (strcmp(p->sort, a) == 0) {
printf(" **    %d        %s         %s        %s         %s       %d        %.2f  **\n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
flag = 1;
}
p = p->next;
}
printf(" =========================================================================\n");
}
}
//按图书出版时间查询图书信息
void time_chaxun(struct book *head)
{
int a, flag = 0;
struct book *p;
printf("请选择您要查询的图书出版时间:");
scanf("%d", &a);
getchar();
p = head;
while (p != NULL) {
if (p->time == a) {
flag = 1;
break;
}
p = p->next;
}
if (flag == 0) {
printf("没有找到该图书名的图书!\n");


}
else {
printf("                        你所查询的图书信息如下\n");
printf(" =========================================================================\n");
printf(" **   编号    图书名    作者名    出版社    类别    出版时间     价格   **\n");
while (p != NULL) {
if (p->time == a) {
printf(" **    %d        %s         %s        %s         %s       %d        %.2f  **\n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
flag = 1;
}
p = p->next;
}
printf(" =========================================================================\n");
}
}
//修改图书信息
void xiugai(struct book *head)
{
int a, b;
char c;
struct book *p;
printf("请输入要修改的图书编号:");
scanf("%d", &a);
p = head;
while (p != NULL) {
if (p->num == a)
break;
p = p->next;
}
if (p == NULL) {
printf("没有找到该编号的图书!\n");
getchar();
}
else {
printf("              ============================================================\n");
printf("              |  1-编号               2-图书名              3-作者名     |\n");
printf("              |  4-出版社             5-类别                6-出版时间   |\n");
printf("              |  7-价格               8-修改全部            0-放弃修改   |\n");
printf("              ============================================================\n");
printf("请选择你要修改的信息编号:");
scanf("%d", &b);
getchar();
switch (b) {
case 1:
printf("请输入新编号:");
scanf("%d", &p->num);
printf("修改成功!\n");
getchar();
break;
case 2:
printf("请输入新图书名:");
scanf("%s", p->bname);
printf("修改成功!\n");
break;
case 3:
printf("请输入新作者名:");
scanf("%s", p->wname);
printf("修改成功!\n");
break;
case 4:
printf("请输入新出版社:");
scanf("%s", p->press);
printf("修改成功!\n");
break;
case 5:
printf("请输入新类别:");
scanf("%s", p->sort);
printf("修改成功!\n");
break;
case 6:
printf("请输入新出版时间:");
scanf("%d", &p->time);
printf("修改成功!\n");
getchar();
break;
case 7:
printf("请输入新价格:");
scanf("%f", &p->price);
printf("修改成功!\n");
getchar();
break;
case 8:
printf("请输入新图书编号:");
scanf("%d", &p->num);
printf("请输入新图书名:");
scanf("%s", p->bname);
getchar();
printf("请输入新作者名:");
scanf("%s", p->wname);
getchar();
printf("请输入新出版社:");
scanf("%s", p->press);
getchar();
printf("请输入新类别:");
scanf("%s", p->sort);
getchar();
printf("请输入新出版时间:");
scanf("%d", &p->time);
getchar();
printf("请输入新价格:");
scanf("%f", &p->price);
getchar();
printf("修改成功!\n");
getchar();
break;
case 0:
break;
default:
printf("您的输入有误!\n");
break;
}
printf("是否将修改后的信息保存到文件中?(y/n)\n");
scanf("%c", &c);
getchar();
switch (c) {
case 'n':
break;
case 'y':
fprint(head);
printf("保存成功!\n");
getchar();
break;
}


}
}


void guihuan(struct book *head)    //归还图书
{
int cunzai = 0;
int choice;
char a[50];
int flag = 0;
struct book *p;
printf("请输入您要归还的图书名:");
scanf("%s", a);
p = head;


while (p != NULL)
{
if (strcmp(p->bname, a) == 0)
{
flag = 1;
break;
}
p = p->next;
}
if (flag == 0) {
printf("没有找到该图书名的图书!\n");


}
else {
printf("                        你所要归还的图书信息如下\n");
printf(" =========================================================================\n");
printf(" **   编号    图书名    作者名    出版社    类别    出版时间     价格   **\n");
while (p != NULL) {
if (strcmp(p->bname, a) == 0) {
printf(" **    %d        %s         %s        %s         %s       %d        %.2f  **\n", p->num, p->bname, p->wname, p->press, p->sort, p->time, p->price);
printf("是否归还书籍？\n");
printf("1 是   2否\n");
scanf("%d", &choice);
switch (choice)
{
case 1:p->islended = 0;


printf("归还成功\n");
break;
}
}
p = p->next;
}
}
} 

