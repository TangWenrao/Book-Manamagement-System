#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
#define MAX 100
class kecheng           //课程表类 模块一
{
public:                //公有数据
	void setvalue();      //输入函数
	void showke();//处理、输出函数
	void showke1();
	string ming[16];     //课程名
	string jiao[16];      //教师名
	string di[16];       //教室地点
	int qi[16];         //课程起始周
	int jie[16];         //课程结束周
	int xing[16];       //星期
	int tang[16];       //第几堂
}; 


void Evaluate();//阶段性学习评价 
int evaluate(int Smath,int Sphysics,int Scplusplus,int Spe,float GPA);//阶段性学习评价子函数 
class Student
{
private:
	string Name;
	string Number;
	string Sex;
	int Math;
	int Physics;
	int CPlusPlus;
	int PE;
public:
	void SetName();
	void SetNumber();
	void SetSex();
	void SetScore();
	void ShowName();
	void ShowNumber();
	void ShowSex();
	void ShowMScore();
	void ShowPScore();
	void ShowCScore();
	void ShowPEScore();
	void ChangeName();
	void ChangeNumber();
	void ChangeSex();
	void ChangeMScore();
	void ChangePScore();
	void ChangeCScore();
	void ChangePEScore();
	void load();
	string name();
	string number();
	int math();
	int physics();
	int cplusplus();
	int pe(); 
	kecheng ke; 
	float count_GPA();
}student2[MAX];      //对象数组，可增加个数 
int m,n,o;             //外界选择操作时输入的序号,可重复使用 
string a,b,c,d;        //外界输入姓名和学号）
int i,x=0;             //for循环和数组中所用变量，可重复使用 
int q;                 //确定对象位置时所用的变量，可重复使用 
void set();//基本信息录入 
void xiugai(); //基本信息修改子函数 
void change();//基本信息修改 
void chaxun();//基本信息查询子函数 
void query();//基本信息查询 
void kecheng_input();//课程表输入
void kecheng_output();//课程表输出
void kecheng_outputfile();//课程表输出到文件 
class Student1{
	private:
		string student_name;
	    int student_number;
	    int morality_score; //思想政治与道德素养分 
	    int volunteer_score; //社会实践与志愿服务分 
	    int academic_score; //科技学术与创新创业分 
	    int physics_score; //文体艺术与身心发展分 
	    int club_score; //社团活动与社会工作分 
	    int skill_score; //技能培训及其他分 
	    int SecondScore; //第二课堂总分 
	public:
		void get_name(string name); //修改私有数据姓名
		void get_number(int number); //修改私有数据学号 
		void get_morality(int morality); //修改私有数据思想政治与道德素养分 
		void get_volunteer(int volunteer); //修改私有数据社会实践与志愿服务分 
		void get_academic(int academic); //修改私有数据科技学术与创新创业分 
		void get_physics(int physics); //修改私有数据文体艺术与身心发展分 
		void get_club(int club); //修改私有数据社团活动与社会工作分 
		void get_skill(int skill); //修改私有数据技能培训及其他分 
		void count(); //计算并修改德育分总分 
		string back_name(); //返回姓名
		int back_number(); //返回学号
		int back_SecondScore(); //返回第二课堂总分
		int display_SecondScore(); //显示第二课堂分数 
};
Student1 student[MAX];
int MoralityScore(int a,int b,int c, int d,int e); //计算思想政治与道德素养分
int VolunteerScore(int a,int b,int c,int d); //计算社会实践与志愿服务分 
int AcademicScore(int a,int b,int c,int d); //计算科技学术与创新创业分 
int PhysicsScore(int a,int b, int c,int d,int e,int f); //计算文体艺术与身心发展分 
int ClubScore(int a,int b,int c); //计算社团活动与社会工作分  
int SkillScore(int a,int b,int c,int d); //计算技能培训及其他分 
int Input_SecondScore(int x);  //修改德育分
void Input_SecondScore_void(int y);  //输入德育分
void Input_MoralityScore(int x);  //输入思想政治与道德素养部分
void Input_VolunteerScore(int x);  //输入社会实践与志愿服务部分
void Input_AcademicScore(int x);  //输入科技学术与创新创业部分
void Input_PhysicsScore(int x);  //输入文体艺术与身心发展部分
void Input_ClubScore(int x);  //输入社团活动与社会工作部分
void Input_SkillScore(int x); //输入技能培训及其他部分
void load(); //德育分数据初始化 
int delect_student(int x); //删除学生信息 
void alter_SecondScore(); //德育分主菜单次选菜单，选择查找对象方式，修改德育分 
void log_SecondScore(); //德育分主菜单录入选项，录入德育分 
void Delect(); //德育分主菜单删除选项
void output(); //德育分主菜单输出选项 
void Student1::get_name(string name) //修改私有数据姓名
{
	student_name=name;
}
void Student1::get_number(int number) //修改私有数据学号 
{
	student_number=number;
}
void Student1::get_morality(int morality) //修改私有数据思想政治与道德素养分
{
	morality_score=morality;
}  
void Student1::get_volunteer(int volunteer) //修改私有数据社会实践与志愿服务分
{
	volunteer_score=volunteer;
}
void Student1::get_academic(int academic) //修改私有数据科技学术与创新创业分 
{
	academic_score=academic;
}
void Student1::get_physics(int physics) //修改私有数据文体艺术与身心发展分 
{
	physics_score=physics;
}
void Student1::get_club(int club) //修改私有数据社团活动与社会工作分
{
	club_score=club;
}
void Student1::get_skill(int skill) //修改私有数据技能培训及其他分
{
	skill_score=skill;
}
void Student1::count() //计算并修改德育分总分 
{
	SecondScore=3*morality_score+2*volunteer_score+3*academic_score+2*physics_score+2*club_score+skill_score;
}
string Student1::back_name() //返回姓名
{
	return student_name;
}
int Student1::back_number() //返回学号
{
	return student_number;
}
int Student1::back_SecondScore() //返回第二课堂总分
{
	return SecondScore;
} 
int Student1::display_SecondScore() //显示第二课堂分数
{
	cout<<endl<<"您要查找的学生信息如下"<<endl;
	cout<<"姓名："<<student_name<<endl;
	cout<<"学号："<<student_number<<endl;
	cout<<"***第二课堂德育分部分***"<<endl;
	cout<<"思想政治与道德素养得分： "<<morality_score<<endl;
	cout<<"社会实践与志愿服务得分："<<volunteer_score<<endl;
	cout<<"科技学术与创新创业得分："<<academic_score<<endl;
	cout<<"文体艺术与身心发展得分："<<physics_score<<endl;
	cout<<"社团活动与社会工作得分："<<club_score<<endl;
	cout<<"技能培训及其他得分：    "<<skill_score<<endl;
	cout<<"第二课堂总分：          "<<SecondScore<<endl;
	cout<<endl<<"德育分信息输出完毕"<<endl;
	int a;
	for(;1;)
	{
		cout<<endl<<"1.返回上级菜单"<<endl;
	    cout<<"0.返回主菜单"<<endl;
	    cin>>a;
	    if(a==1||a==0) break;
	    else cout<<"选择错误，请重新选择"<<endl; 
	}
	return a; 
} 
int MoralityScore(int a,int b,int c, int d,int e) //计算思想政治与道德素养部分 
{
	int score=0;
	if(a) score=10;
	if(!b) score+=30;
	score+=5*(4-c);
	if(d) score+=15;
	score+=5*e;
	return score;
}
int VolunteerScore(int a,int b,int c,int d) //计算社会实践与志愿服务部分 
{
	int score=0;
	if(a) score=15;
	else score=20;
	if(b) score+=10;
	switch(c)
	{
		case 1:score+=30;break;
		case 2:score+=25;break;
		case 3:score+=0;break;
	}
	score+=2*d;
	return score;
}
int AcademicScore(int a,int b,int c,int d) //计算科技学术与创新创业部分 
{
	int score;
	score=5*a+10*b+5*c+5*d;
	return score;
}
int PhysicsScore(int a,int b, int c,int d,int e,int f) //计算文体艺术与身心发展部分 
{
	int score=0;
	score+=5*a;
	if(b==1) score+=15;
	else if(b==2) score+=10;
	     else score+=0; 
	if(c==1) score+=15;
	else if(c==2) score+=10;
	     else score+=0;
	if(d==1) score+=20;
	else if(d==2) score+=15;
	     else score+=0; 
	switch(e)
	{
		case 1:score+=20;break;
		case 2:score+=18;break;
		case 3:score+=10;break;
		case 4:score+=5;break;
	} 
	switch(f)
	{
		case 1:score+=15;break;
		case 2:score+=10;break;
		case 3:score+=8;break;
		case 4:score+=5;break;
		case 5:score+=0;break;	
	}
	return score;
}
int ClubScore(int a,int b,int c) //计算社团活动与社会工作部分 
{
	int score=0;
	if(a) score=35;
	switch(b)
	{
		case 1:score+=40;break;
		case 2:score+=30;break;
		case 3:score+=20;break;
		case 4:score+=15;break;
		case 5:score+=0;break;
	}
	switch(c)
	{
		case 1:score+=20;break;
		case 2:score+=15;break;
		case 3:score+=10;break;
		case 4:score+=5; break;
		case 5:score+=0;break; 
	}
	return score;
}
int SkillScore(int a,int b,int c,int d) //计算技能培训及其他部分 
{
	int score=0;
	if(a) score=30;
	if(b) score+=30;
	if(c) score+=30;
	if(d) score+=30;
	if(score<100) return score;
	else return(100);
}
void alter_SecondScore() //主菜单次选菜单，选择查找对象方式 ，修改德育分 
{
	int a=1,b,i,c=1,f=1;
	string d; 
	for(;a;)
	{
		cout<<endl<<"***请选择查找对象的方式***"<<endl;
		cout<<"1：按学号查找"<<endl;
		cout<<"2：按姓名查找"<<endl;
		cout<<"0：返回德育分主菜单"<<endl;
		c=1,f=1;
		cin>>a;
		switch(a)
		{
			case 1:{
				for(;c;)
				{
					cout<<"请输入学号：";
				    cin>>b;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_number()==b) 
					    {
						    cout<<"您查找的学号为："<<student[i].back_number()<<endl;
						    cout<<"学生姓名为：    "<<student[i].back_name() <<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认，按0重新输入"<<endl;
						        cin>>c;
						        if(c==1)
						        {
						    	    cout<<"*下面载入德育分系统*"<<endl;
						    	    break;
							    }
							    else if(c==0)
							    {
							    	c=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入学号，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) c=0;
						else if(g==3)
						{
							c=0;
							a=0;
						}	 
					}
				    if(c==1)
				    {
				    	int judge;
						judge=Input_SecondScore(i);
				    	if(judge==1) c=0;
				    	else if(judge==0)
				    	{
				    		c=0;
				    		a=0;
						}
					}
				} 
				break;
			}
			case 2:{
				for(;f;)
				{
					cout<<"请输入学生姓名：";
				    cin>>d;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_name()==d) 
					    {
						    cout<<"您查找的学生姓名为："<<student[i].back_name()<<endl;
						    cout<<"学号为：            "<<student[i].back_number()<<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认，按0重新输入"<<endl;
						        cin>>f;
						        if(f==1)
						        {
						    	    cout<<"*下面载入德育分系统*"<<endl;
						    	    break;
							    }
							    else if(f==0)
							    {
							    	f=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入姓名，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) f=0;
						else if(g==3)
						{
							f=0;
							a=0;
						}	 
					} 
				    if(f==1)
				    {
				    	int judge;
						judge=Input_SecondScore(i);
				    	if(judge==1) f=0;
				    	else if(judge==0)
				    	{
				    		f=0;
				    		a=0;
						}
					}
				} 
				break;
			}
			case 0:break;
			default:cout<<"菜单选择错误，请重新选择"<<endl;break;
		}
	} 
} 
int Input_SecondScore(int x) //修改德育分 
{
	int a=1,b;
	for(;a!=0;)
	{
		cout<<endl<<"***请选择并输入菜单前的序号***"<<endl;
		cout<<"1：输入思想政治与道德素养部分"<<endl;
		cout<<"2：输入社会实践与志愿服务部分"<<endl;
		cout<<"3：输入科技学术与创新创业部分"<<endl;
		cout<<"4：输入文体艺术与身心发展部分"<<endl;
		cout<<"5：输入社团活动与社会工作部分" <<endl;
		cout<<"6：输入技能培训及其他部分"<<endl;
		cout<<"7：返回上级菜单"<<endl; 
		cout<<"0：返回主菜单"<<endl;
		cin>>a;
		switch(a)
		{
			case 1:{
				Input_MoralityScore(x);
				cout<<endl<<"***思想政治与道德素养部分录入完成***"<<endl; 	
				break;
			}
			case 2:{
				Input_VolunteerScore(x);
				cout<<endl<<"***社会实践与志愿服务部分录入完成***"<<endl;
				break;
			}
			case 3:{
				Input_AcademicScore(x);
				cout<<endl<<"***科技学术与创新创业部分录入完成***"<<endl;
				break;
			}
			case 4:{
				Input_PhysicsScore(x);
				cout<<endl<<"***文体艺术与身心发展部分录入完成***"<<endl;
				break;
			}
			case 5:{
				Input_ClubScore(x);
				cout<<endl<<"***社团活动与社会工作部分录入完成***"<<endl;
				break;
			}
			case 6:{
				Input_SkillScore(x);
				cout<<endl<<"***技能培训及其他部分录入完成***"<<endl;
				break;
			}
			case 7:{
				b=1;
				a=0;
				break;
			}
			case 0:b=0;break;                                                   //加主菜单显示函数 
			default:cout<<"菜单选择错误，请重新选择"<<endl;
		}
	}
	return b;
}
void Input_SecondScore_void(int y) //修改德育分 
{
	int a=1;
	for(;a!=0;)
	{
		cout<<endl<<"***请选择并输入菜单前的序号***"<<endl;
		cout<<"1：输入思想政治与道德素养部分"<<endl;
		cout<<"2：输入社会实践与志愿服务部分"<<endl;
		cout<<"3：输入科技学术与创新创业部分"<<endl;
		cout<<"4：输入文体艺术与身心发展部分"<<endl;
		cout<<"5：输入社团活动与社会工作部分" <<endl;
		cout<<"6：输入技能培训及其他部分"<<endl;
		cout<<"0：返回主菜单"<<endl;
		cin>>a;
		switch(a)
		{
			case 1:{
				Input_MoralityScore(y);
				cout<<endl<<"***思想政治与道德素养部分录入完成***"<<endl; 	
				break;
			}
			case 2:{
				Input_VolunteerScore(y);
				cout<<endl<<"***社会实践与志愿服务部分录入完成***"<<endl;
				break;
			}
			case 3:{
				Input_AcademicScore(y);
				cout<<endl<<"***科技学术与创新创业部分录入完成***"<<endl;
				break;
			}
			case 4:{
				Input_PhysicsScore(y);
				cout<<endl<<"***文体艺术与身心发展部分录入完成***"<<endl;
				break;
			}
			case 5:{
				Input_ClubScore(y);
				cout<<endl<<"***社团活动与社会工作部分录入完成***"<<endl;
				break;
			}
			case 6:{
				Input_SkillScore(y);
				cout<<endl<<"***技能培训及其他部分录入完成***"<<endl;
				break;
			}
			case 0:break;                                                   //加主菜单显示函数 
			default:cout<<"菜单选择错误，请重新选择"<<endl;
		}
	}
}
void Input_MoralityScore(int x) //输入思想政治与道德素养部分
{
	int a,b,c,d,e,morality_score;
	cout<<endl<<"思想政治与道德素养部分（3学分，满分100分）"<<endl;
	for(;1;)
	{
		cout<<"是否参与党课学习，且通过考试，10分（是按1，否按0）" <<endl;
	    cin>>a;
	    if(a==1||a==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"有无学校纪律处分，30分（有按1，否按0）"<<endl;
	    cin>>b;
	    if(b==1||b==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"参加活动的出勤情况，满分20分（请输入缺勤次数，最多为4次）" <<endl;
	    cin>>c;
	    if(c==0||c==1||c==2||c==3||c==4) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"是否参加党校、团校或学生干部学习培训等活动，15分（是按1，否按0）"<<endl;
	    cin>>d;
	    if(d==1||d==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"参加各类形势政策讲座，满分25分（请输入参加次数，最多5次）" <<endl;
	    cin>>e;
	    if(e==0||e==1||e==2||e==3||e==4||e==5) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	morality_score=MoralityScore(a,b,c,d,e);
	student[x].get_morality(morality_score); 
	student[x].count() ;
}
void Input_VolunteerScore(int x)  //输入社会实践与志愿服务部分
{
	int a,b,c,d,volunteer_score;
	cout<<endl<<"社会实践与志愿服务部分（2学分，满分100分）"<<endl;
	for(;1;)
	{
		cout<<"参加暑期社会实践，满分20分（个人请按1，团体请按0）" <<endl;
	    cin>>a;
	    if(a==1||a==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"是否参与无偿献血、捐献骨髓样本，10分（是按1，否按0）" <<endl;
	    cin>>b;
	    if(b==1||b==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"宿舍学长，满分30分（负责人按1，成员按2，没有参与按3）"<<endl;
	    cin>>c;
	    if(c==1||c==2||c==3) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
	    cout<<"请输入参加志愿服务时长,满分40分（最多20小时)"<<endl;
	    cin>>d;
	    if(d>=0&&d<=20) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	volunteer_score=VolunteerScore(a,b,c,d);
	student[x].get_volunteer(volunteer_score); 
	student[x].count() ;
}
void Input_AcademicScore(int x)  //输入科技学术与创新创业部分
{
	int a,b,c,d,academic_score;
	cout<<endl<<"科技学术与创新创业部分（3学分，满分100分）"<<endl;
	for(;1;)
	{
		cout<<"参与学科竞赛，如萌芽杯比赛、编程比赛、学科比赛，满分30分（请输入参加次数，最多6次）"<<endl;
	    cin>>a;
	    if(a>=0&&a<=6) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"学术论文的发表,满分20分（请输入发表篇数，最多2篇）"<<endl;
	    cin>>b;
	    if(b==1||b==0||b==2) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"非学术论文的发表,满分10分（请输入发表篇数，最多2篇）" <<endl;
	    cin>>c;
	    if(c==1||c==2||c==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
	    cout<<"参加科技学术讲座，如萌芽杯分享会暨启动仪式，满分40分(请输入参加次数，最多8次）"<<endl;
	    cin>>d;
	    if(d>=0&&d<=8) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	academic_score=AcademicScore(a,b,c,d);
	student[x].get_academic(academic_score); 
	student[x].count() ;
} 
void Input_PhysicsScore(int x)  //输入文体艺术与身心发展部分
{
	int a,b,c,d,e,f,physics_score;
	cout<<endl<<"文体艺术与身心发展部分(2学分，满分100分)"<<endl;
	for(;1;)
	{
		cout<<"参与智能小车大赛/二极管/创业榜样在身边/对话价值观演讲比赛/名师励志大讲堂/院周晚会演员(请输入参与的个数，最多3个，满分15分)" <<endl;
	    cin>>a;
	    if(a>=0&&a<=3) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"参与校运动会竞赛类项目，满分15分（参与并获奖按1，参与按2，没有参与按3）"<<endl;
	    cin>>b;
	    if(b==1||b==3||b==2) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"是否参与校运动会趣味类项目，满分15分（参与并获奖按1，参与按2，没有参与按3）"<<endl;
	    cin>>c;
	    if(c==1||c==2||c==3) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
	    cout<<"参与运动队或艺术团，满分20分（校级按1，院级按2,没有参与按3）"<<endl;
	    cin>>d;
	    if(d==1||d==2||d==3) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"军训，满分20分：军训标兵（按1），参加合唱、定向越野、拔河、板报（按2），完成军训（按3），见习超过3天（按4）"<<endl;
	    cin>>e;
	    if(e==1||e==2||e==3||e==4) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"宿舍卫生，满分15分：优（按1），良（按2），中等（按3），及格（按4），差（按5）"<<endl;
	    cin>>f;
	    if(f==1||f==2||f==3||f==4||f==5) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	physics_score=PhysicsScore(a,b,c,d,e,f);
	student[x].get_physics(physics_score);
	student[x].count() ;
}
void Input_ClubScore(int x)  //输入社团活动与社会工作部分
{
	int a,b,c,club_score;
	cout<<endl<<"社团活动与社会工作部分（2学分，满分100分）"<<endl;
	for(;1;)
	{
	    cout<<"是否为学生组织干部或班委成员，40分（是按1，否按0）"<<endl;
	    cin>>a;
	    if(a==0||a==1) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 	 
	for(;1;)
	{
		cout<<"在大学期间获国家级、市级、校级和院级荣誉奖励，满分40分，如三好学生、优秀学生干部、优秀团员、优秀团干部、优秀学生党员等(国家级按1，市级按2，校级按3，院级按4，没有获奖按5）"<<endl;
	    cin>>b;
	    if(b==1||b==3||b==2||b==3||b==4||b==5) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"参加社团,满分20分（五星级按1，四星级按2，三星级按3，参加其他社团按4，没有参加按5）"<<endl;
	    cin>>c;
	    if(c==1||c==2||c==3||c==4||c==5) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	club_score=ClubScore(a,b,c);
	student[x].get_club(club_score);
	student[x].count() ;
}
void Input_SkillScore(int x) //输入技能培训及其他部分
{
	int a,b,c,d,skill_score;
	cout<<endl<<"技能培训及其他部分（1学分，满分100分）"<<endl;
	for(;1;)
	{
	    cout<<"是否通过英语四、六级，30分(是按1，否按0）"<<endl;
	    cin>>a;
	    if(a==0||a==1) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 	 
	for(;1;)
	{
		cout<<"是否通过计算机二、三级考试，30分（是按1，否按0）" <<endl;
	    cin>>b;
	    if(b==1||b==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
		cout<<"是否参加微软认证、Cisco 认证、Oracle认证、sun认证、计算机类认证培训并得到最终证书，30分（是按1，否按0）"<<endl;
	    cin>>c;
	    if(c==1||c==0) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 
	for(;1;)
	{
	    cout<<"是否通过剑桥商务英语中级，GRE，雅思，托福等英语类培训考试，并获得证书，30分（是按1，否按0）"<<endl;
	    cin>>d;
	    if(d==0||d==1) break;
	    else cout<<"输入错误，请重新输入"<<endl; 
	} 	 
	skill_score=SkillScore(a,b,c,d);
	student[x].get_skill(skill_score);
	student[x].count() ;
}
void load() //数据初始化
{
	int i;
	for(i=0;i<MAX;i++) 
	{
		student[i].get_number(0);
		student[i].get_academic(0);
		student[i].get_club(0);
		student[i].get_morality(0);
		student[i].get_physics(0);
		student[i].get_skill(0);
		student[i].get_volunteer(0);
		student[i].count();       
	}
 } 
void log_SecondScore() //录入德育分 
{
	static int a=0;
	string b;
	int c,d=1,i;
	for(;d;)
	{
		cout<<endl<<"请输入学生姓名：";
	    cin>>b;
	    for(i=0;i<a;i++)
	    {
	    	if(b==student[i].back_name())
	    	{
	    		cout<<"学生姓名错误或学生姓名重复，请重新输入"<<endl;
	    		break;
			}
		}
		if(i==a) d=0;
	}
	student[a].get_name(b);
	d=1;
	for(;d;)
	{
		cout<<endl<<"请输入学号：";
	    cin>>c;
	    for(i=0;i<a;i++)
	    {
	    	if(c==student[i].back_number()) 
	    	{
	    		cout<<"学号错误或学号重复，请重新输入"<<endl;
	    		break;
			}
		}
		if(i==a) d=0;
	}
	student[a].get_number(c);
	Input_SecondScore_void(a);
	a+=1;
}
int delect_student(int x) //删除学生信息 
{
	student[x].get_number(0);
	student[x].get_academic(0);
	student[x].get_club(0);
	student[x].get_morality(0);
	student[x].get_physics(0);
	student[x].get_skill(0);
	student[x].get_volunteer(0);
	student[x].count(); 
	cout<<"学生信息删除成功"<<endl;
	int a;
	for(;1;)
	{
		cout<<endl<<"1.返回上级菜单"<<endl;
	    cout<<"0.返回主菜单"<<endl;
	    cin>>a;
	    if(a==1||a==0) break;
	    else cout<<"选择错误，请重新选择"<<endl; 
	}
	return a; 
} 
void Delect() //主菜单删除选项 
{
	int a=1,b,i,c=1,f=1;
	string d; 
	for(;a;)
	{
		cout<<endl<<"***请选择查找对象的方式***"<<endl;
		cout<<"1：按学号查找"<<endl;
		cout<<"2：按姓名查找"<<endl;
		cout<<"0：返回德育分主菜单"<<endl;
		c=1,f=1;
		cin>>a;
		switch(a)
		{
			case 1:{
				for(;c;)
				{
					cout<<"请输入学号：";
				    cin>>b;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_number()==b) 
					    {
						    cout<<"您查找的学号为："<<student[i].back_number()<<endl;
						    cout<<"学生姓名为：    "<<student[i].back_name() <<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认删除，按0重新输入"<<endl;
						        cin>>c;
						        if(c==1) break; 
							    else if(c==0)
							    {
							    	c=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入学号，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) c=0;
						else if(g==3)
						{
							c=0;
							a=0;
						}	 
					}
				    if(c==1)
				    {
				    	int judge;
						judge=delect_student(i);
				    	if(judge==1) c=0;
				    	else if(judge==0)
				    	{
				    		c=0;
				    		a=0;
				    	}
					}
				} 
				break;
			}
			case 2:{
				for(;f;)
				{
					cout<<"请输入学生姓名：";
				    cin>>d;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_name()==d) 
					    {
						    cout<<"您查找的学生姓名为："<<student[i].back_name()<<endl;
						    cout<<"学号为：            "<<student[i].back_number()<<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认删除，按0重新输入"<<endl;
						        cin>>f;
						        if(f==1) break;
							    else if(f==0)
							    {
							    	f=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入姓名，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) f=0;
						else if(g==3)
						{
							f=0;
							a=0;
						}	 
					} 
				    if(f==1)
				    {
				    	int judge;
						judge=delect_student(i);
				    	if(judge==1) f=0;
				    	else if(judge==0)
				    	{
				    		f=0;
				    		a=0;
						}
					}
				} 
				break;
			}
			case 0:break;
			default:cout<<"菜单选择错误，请重新选择"<<endl;break;
		}
	}
}
void output() //主菜单输出选项 
{
	int a=1,b,i,c=1,f=1;
	string d; 
	for(;a;)
	{
		cout<<endl<<"***请选择查找对象的方式***"<<endl;
		cout<<"1：按学号查找"<<endl;
		cout<<"2：按姓名查找"<<endl;
		cout<<"0：返回德育分主菜单"<<endl;
		c=1,f=1;
		cin>>a;
		switch(a)
		{
			case 1:{
				for(;c;)
				{
					cout<<"请输入学号：";
				    cin>>b;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_number()==b) 
					    {
						    cout<<"您查找的学号为："<<student[i].back_number()<<endl;
						    cout<<"学生姓名为：    "<<student[i].back_name() <<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认，按0重新输入"<<endl;
						        cin>>c;
						        if(c==1) break;
							    else if(c==0)
							    {
							    	c=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入学号，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) c=0;
						else if(g==3)
						{
							c=0;
							a=0;
						}	 
					}
				    if(c==1)
				    {
				    	int judge;
						judge=student[i].display_SecondScore();
				    	if(judge==1) c=0;
				    	else if(judge==0)
				    	{
				    		c=0;
				    		a=0;
				    	}
					}
				} 
				break;
			}
			case 2:{
				for(;f;)
				{
					cout<<"请输入学生姓名：";
				    cin>>d;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_name()==d) 
					    {
						    cout<<"您查找的学生姓名为："<<student[i].back_name()<<endl;
						    cout<<"学号为：            "<<student[i].back_number()<<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认，按0重新输入"<<endl;
						        cin>>f;
						        if(f==1)
						        {
						    	    cout<<"*下面载入德育分系统*"<<endl;
						    	    break;
							    }
							    else if(f==0)
							    {
							    	f=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入姓名，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) f=0;
						else if(g==3)
						{
							f=0;
							a=0;
						}	 
					} 
				    if(f==1)
				    {
				    	
				    	int judge;
						judge=student[i].display_SecondScore();
				    	if(judge==1) f=0;
				    	else if(judge==0)
				    	{
				    		f=0;
				    		a=0;
						}
					}
				} 
				break;
			}
			case 0:break;
			default:cout<<"菜单选择错误，请重新选择"<<endl;break;
		}
	} 
 } 
class Score
{	public:
	float HuanSuan(int a);
	Score(int,int,int,int,int);
	double GPA();
	float M,P,E,S,C;	
};
Score::Score(int m,int p,int e,int s,int c)
{
	M=HuanSuan(m);
	P=HuanSuan(p);
	E=HuanSuan(e);
    S=HuanSuan(s);
    C=HuanSuan(c);
}
float Score::HuanSuan(int a)
{
    if(a>=95) return(4.33);
    else if(a>=90) return(4.00);
    else if(a>=85) return(3.67);
    else if(a>=82) return(3.33);
    else if(a>=78) return(3.00);
    else if(a>=75) return(2.67);
    else if(a>=72) return(2.33);
    else if(a>=68) return(2.00);
    else if(a>=64) return(1.67);
    else if(a>=61) return(1.33);
    else if(a=60) return(1.00);
    else return(0);
}
double Score::GPA()
{
	float a,b,c,d,e,z;
	a=M*5.5;
	b=P*4;
	c=E*4;
	d=S*3;
	e=C*3;
	z=(a+b+c+d+e)/(5.5+4+4+3+3);
	return(z);
}
void zybiankuang()
{
 int i;
 cout<<"*";
 for(i=0;i<117;i++)
 {
  cout<<" ";
 }
 cout<<"*";
}
void ybiankuang(int j)
{
 int i;
 for(i=0;i<j;i++)
 {
  cout<<" ";
 }
 cout<<"*";
}
void zimu()
{
 cout<<"*                **********             **          **              *********           ************                  *"<<endl;
 cout<<"*                **********             **          **             **********           ************                  *"<<endl;
 cout<<"*                **       **            **          **            **                         **                       *"<<endl;
 cout<<"*                **        **           **          **            **                         **                       *"<<endl;
 cout<<"*                **        **           **          **           **                          **                       *"<<endl;
 cout<<"*                **       **            **          **           **                          **                       *"<<endl;
 cout<<"*                **********             **          **           **                          **                       *"<<endl;
 cout<<"*                **********             **          **           **                          **                       *"<<endl;
 cout<<"*                **       **            **          **           **                          **                       *"<<endl;
 cout<<"*                **        **           **          **           **                          **                       *"<<endl;
 cout<<"*                **        **           **          **            **                         **                       *"<<endl;
 cout<<"*                **       **             **        **             **                         **                       *"<<endl;
 cout<<"*                **********               **********               **********                **                       *"<<endl;
 cout<<"*                **********                ********                 *********                **                       *"<<endl;
}
void kongge(int j=48)
{
 int i;
 cout<<"*";
 for(i=0;i<j;i++)
 {
  cout<<" ";
 }
}
void xinghao()
{
 int i;
 for(i=0;i<120;i++)
 {
  cout<<"*";
 }
}
int main()
{   
    int first;
    int i;
    load();
	for(i=0;i<MAX;i++) student2[i].load();
    for(;1;)
	{
	xinghao();
    zybiankuang();
    cout<<endl;
    zimu();
    zybiankuang();
    cout<<endl;
    kongge(44);
    cout<<"欢迎使用学生信息管理系统" ;
    ybiankuang(49);
    cout<<endl;
    kongge();
    cout<<"您要选择的部分是:";
    ybiankuang(52);
    cout<<endl; 
    kongge();
    cout<<"1 学生基本信息";
    ybiankuang(55);
    cout<<endl;
    kongge();
    cout<<"2 GPA计算"; 
    ybiankuang(60);
    cout<<endl;
    kongge();
    cout<<"3 德育分统计";
    ybiankuang(57);
    cout<<endl;
    kongge();
    cout<<"4 学生课表功能";
    ybiankuang(55);
    cout<<endl;
    kongge();
    cout<<"5 阶段性学习评价";
    ybiankuang(53);
    cout<<endl;
    kongge();
    cout<<"0 退出系统";
    ybiankuang(59);
    cout<<endl;
    zybiankuang();
    cout<<endl;
    xinghao();	
    cout<<endl;
	cin>>first;
	if (first==1) 
	{
		while(1)
        {
			  xinghao() ;
 			  zybiankuang();
			  cout<<endl;
			  kongge();
 			  cout<<"请输入所要进行的操作的编号:";
			  ybiankuang(42);
 			  cout<<endl; 
 			  kongge();
 			  cout<<"输入新的学生信息(1);";
			  ybiankuang(49);
 			  cout<<endl; 
			  kongge();
 			  cout<<"修改已有学生的信息(2);";
 			  ybiankuang(47);
 			  cout<<endl; 
 			  kongge();
 			  cout<<"查询已有学生信息(3);";
 			  ybiankuang(49);
 			  cout<<endl; 
 			  kongge();
 			  cout<<"返回主菜单(0);";
 			  ybiankuang(55);
 			  cout<<endl;    
 			  zybiankuang();
 			  cout<<endl; 
 			  xinghao();
              cin>>m;
              if(m==1) set();
              if(m==2) change();
              if(m==3) query();	
              if(m==0) break;
              if((m!=0)&(m!=1)&(m!=2)&(m!=3)) 
			  {
			   cout<<endl<<"请输入正确的指令。"<<endl<<endl;
			   xinghao();
			   } 
        }
	}
	if (first==2) 
    {
      int a,b,c,d,e,f=1; 
      xinghao();
      cout<<"请输入高数成绩（5.5学分）：";
      cin>>a;
      cout<<endl<<"请输入大物成绩（4学分）：";
	  cin>>b;
	  cout<<endl<<"请输入英语成绩（4学分）：";
	  cin>>c;
	  cout<<endl<<"请输入思修成绩（3学分）：";
	  cin>>d;
	  cout<<endl<<"请输入c++成绩（3学分）：";
	  cin>>e; 
	  xinghao();
  	  Score score1(a,b,c,d,e);	
	  cout<<endl<<"GPA为："<<score1.GPA()<<endl;
	  xinghao();
	  for(;f;)
	  {
	  	 cout<<"按0返回主菜单"<<endl;
	     cin>>f;
	     xinghao();
	     if(f!=0) cout<<"输入错误，请重新输入"<<endl;
		 xinghao(); 
	  } 
    }
    if (first==3)
    {
	  int a=1;
	  for(;a;)
	  {
	      xinghao() ;
 	       zybiankuang();
 	       cout<<endl;
 	       kongge();
  	       cout<<"主菜单（德育分部分）:";
 	       ybiankuang(48);
 	       cout<<endl; 
 	       kongge();
 	       cout<<"1.录入德育分信息;";
 	       ybiankuang(52);
 	       cout<<endl; 
 	       kongge();
 	       cout<<"2.查询德育分信;";
 	       ybiankuang(54);
 	       cout<<endl; 
 	       kongge();
 	       cout<<"3.修改德育分信息;";
 	       ybiankuang(52);
 	       cout<<endl; 
 	       kongge();
 	       cout<<"4.删除德育分信息;";
 	       ybiankuang(52);
 	       cout<<endl; 
 	       kongge();
 	       cout<<"5.返回主菜单;";
 	       ybiankuang(56);
 	       cout<<endl;       
 	       zybiankuang();
 	       cout<<endl; 
 	       xinghao();
	       cin>>a;
	       switch(a)
	       {
		        case 1:log_SecondScore();break;
		        case 2:output();break;
		        case 3:alter_SecondScore();break;
		        case 4:Delect();break;
		        case 5:a=0;break;
		        default:cout<<"菜单选择错误，请重新选择"<<endl;break;
		        xinghao();
	       }
	  }
    }
    if(first==4)
    {
    	int a=1;
		for(;a;)
		{
			xinghao() ;
 			zybiankuang();
 			cout<<endl;
 			kongge();
  			cout<<"1.录入课表信息;";
 			ybiankuang(54);
 			cout<<endl; 
 			kongge();
 			cout<<"2.查询课表信息;";
 			ybiankuang(54);
 			cout<<endl; 
 			kongge();
 			cout<<"3.输出课表信息到文件;";
 			ybiankuang(48);
 			cout<<endl; 
 			kongge();
 			cout<<"0.返回主菜单;";
 			ybiankuang(56);
 	    	cout<<endl;
 	    	zybiankuang();
            cout<<endl; 
            xinghao();
			cin>>a;
			if(a==1) kecheng_input();
			if(a==2) kecheng_output();
			if(a==3) 
			{
				kecheng_outputfile();
				cout<<"课程表信息输出完毕"<<endl;
				xinghao();
			}
			if(a!=1&&a!=2&&a!=3&&a!=0) 
			{
			 cout<<"菜单选择错误，请重新输入"<<endl;
			 xinghao;
			}	 
		 } 
	}
	if(first==5)
	{
		Evaluate(); 
	}
	if(first==0) break;
	if(first!=1&&first!=2&&first!=3&&first!=4&&first!=5&&first!=0) 
	{
	 cout<<"菜单选择错误，请重新输入";
	 xinghao();
	}
	 } 
}
void set()
{
 cout<<endl;
 student2[x].SetName();
 student2[x].SetNumber();
 student2[x].SetSex();
 student2[x].SetScore();
 cout<<endl<<endl;
 x++; 
}
void xiugai()
{
 cout<<"所有信息(1);"<<endl<<"姓名(2);"<<endl<<"学号(3);"<<endl<<"性别(4);"<<endl<<"成绩(5)"<<endl<<endl;
 cin>>o;
 if(o==1)
 {
   cout<<endl;
   student2[q].ChangeName();
   student2[q].ChangeNumber();
   student2[q].ChangeSex();
   student2[q].ChangeMScore();
   student2[q].ChangePScore();
   student2[q].ChangeCScore();
   student2[q].ChangePEScore();
   cout<<endl;
 }
 if(o==2)
 {
   cout<<endl;
   student2[q].ChangeName();
 }
 if(o==3)
 {
   cout<<endl;
   student2[q].ChangeNumber();
 }
 if(o==4)
 {
   cout<<endl;
   student2[q].ChangeSex();
 }
 if(o==5)
 {
   cout<<endl<<"请输入要修改的科目的名称:"<<endl;
   cout<<"所有科目(1)"<<endl<<"高等数学(2);"<<endl<<"大学物理(3);"<<endl<<"C++(4);"<<endl<<"体育(5);"<<endl;
   cin>>m;
   if(m==1)
   {
     cout<<endl;
	 student2[q].ChangeMScore();
     student2[q].ChangePScore();
     student2[q].ChangeCScore();
     student2[q].ChangePEScore();
     cout<<endl;
   } 
   if(m==2) 
   {
	 cout<<endl;
	 student2[q].ChangeMScore();
   } 
   if(m==3)
   {
	 cout<<endl;
	 student2[q].ChangePScore();
   }
   if(m==4)
   {
	 cout<<endl;
	 student2[q].ChangeCScore();
   }
   if(m==5)
   {
	 cout<<endl;
	 student2[q].ChangePEScore();
   } 
 }
 if((o!=1)&(o!=2)%(o!=3)&(o!=4)&(o!=5)) cout<<"请输入正确选项"<<endl<<endl;
} 


void change()
{
 cout<<endl<<"请输入确定学生身份的方式的编号：";
 cout<<endl<<"姓名(1);"<<endl<<"学号(2);"<<endl<<endl;
 cin>>n;
 if(n==1)
 {
   cout<<endl<<"请输入姓名:"; 
   cin>>a;
   q=-1;
   for(i=0;i<MAX;i++)
   {
      b=student2[i].name();
      if(a==b) 
        {
   	      q=i;
	      xiugai();
        }
   } 
   if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
 }
  if(n==2)
  {
    cout<<endl<<"请输入学号"<<endl;
    cin>>c; 
    q=-1;
    for(i=0;i<MAX;i++)
    {
      d=student2[i].number();
   	  if(c==d) 
      {
        q=i;
        xiugai();
      }
   
    }
    if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
   }
}


void chaxun()
{
 cout<<endl<<"请输入所要查询的信息的编号:"<<endl;
 cout<<"所有信息(1);"<<endl<<"姓名(2);"<<endl<<"学号(3);"<<endl<<"性别(4);"<<endl<<"成绩(5)"<<endl<<endl;
 cin>>o;
 if(o==1)
 {
   cout<<endl;
   student2[q].ShowName();
   student2[q].ShowNumber();
   student2[q].ShowSex();
   student2[q].ShowMScore();
   student2[q].ShowPScore();
   student2[q].ShowCScore();
   student2[q].ShowPEScore();
   cout<<endl;
 }
 if(o==2)
 {
   cout<<endl;
   student2[q].ShowName();
 }
 if(o==3)
 {
   cout<<endl;
   student2[q].ShowNumber();
 }
 if(o==4)
 {
   cout<<endl;
   student2[q].ShowSex();
 }
 if(o==5)
 {
   cout<<endl<<"请输入要查询的科目的名称:"<<endl<<endl;
   cout<<"所有科目(1)"<<endl<<"高等数学(2);"<<endl<<"大学物理(3);"<<endl<<"C++(4);"<<endl<<"体育(5);"<<endl<<"GPA(6)"<<endl;
   cin>>m;
   if(m==1)
   {
     cout<<endl;
	 student2[q].ShowMScore();
     student2[q].ShowPScore();
     student2[q].ShowCScore();
     student2[q].ShowPEScore();
     cout<<endl;
   } 
   if(m==2) 
   {
	 cout<<endl;
	 student2[q].ShowMScore();
   } 
   if(m==3)
   {
	 cout<<endl;
	 student2[q].ShowPScore();
   }
   if(m==4)
   {
	 cout<<endl;
	 student2[q].ShowCScore();
   }
   if(m==5)
   {
	 cout<<endl;
	 student2[q].ShowPEScore();
   } 
   if(m==6)
   {
   	cout<<endl<<"GPA为："<<student2[q].count_GPA(); 
   }
 }
 if((o!=1)&(o!=2)%(o!=3)&(o!=4)&(o!=5)) cout<<"请输入正确选项"<<endl<<endl; 
}


void query()
{
 cout<<endl<<"请输入确定学生身份的方式的编号：";
 cout<<endl<<"姓名(1);"<<endl<<"学号(2);"<<endl<<endl;
 cin>>n;
 if(n==1)
 {
   cout<<endl<<"请输入姓名:"; 
   cin>>a;
   q=-1;
   for(i=0;i<MAX;i++)
  {
    b=student2[i].name();
    if(a==b) 
   {
   	 q=i;
	 chaxun();
   }
  } 
 if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
 }
  if(n==2)
  {
    cout<<endl<<"请输入学号"<<endl;
    cin>>c; 
    q=-1;
    for(i=0;i<MAX;i++)
   {
     d=student2[i].number();
   	 if(c==d) 
    {
      q=i;
      chaxun();
    }
   }
  if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
  } 
}
void kecheng_input()
{
 cout<<endl<<"请输入确定学生身份的方式的编号：";
 cout<<endl<<"姓名(1);"<<endl<<"学号(2);"<<endl<<endl;
 cin>>n;
 if(n==1)
 {
   cout<<endl<<"请输入姓名:"; 
   cin>>a;
   q=-1;
   for(i=0;i<MAX;i++)
   {
      b=student2[i].name();
      if(a==b) 
        {
   	      q=i;
	      student2[i].ke.setvalue();
        }
   } 
   if(q==-1) cout<<endl<<"未找到该学生信息，请先完成学生基本信息的填写"<<endl; 
 }
  if(n==2)
  {
    cout<<endl<<"请输入学号"<<endl;
    cin>>c; 
    q=-1;
    for(i=0;i<MAX;i++)
    {
      d=student2[i].number();
   	  if(c==d) 
      {
        q=i;
        student2[i].ke.setvalue();
      }
   
    }
    if(q==-1) cout<<endl<<"未找到该学生信息，请先完成学生基本信息的填写"<<endl; 
   }
}
void kecheng_output()
{
	cout<<endl<<"请输入确定学生身份的方式的编号：";
 cout<<endl<<"姓名(1);"<<endl<<"学号(2);"<<endl<<endl;
 cin>>n;
 if(n==1)
 {
   cout<<endl<<"请输入姓名:"; 
   cin>>a;
   q=-1;
   for(i=0;i<MAX;i++)
   {
      b=student2[i].name();
      if(a==b) 
        {
   	      q=i;
	      student2[i].ke.showke1();
        }
   } 
   if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
 }
  if(n==2)
  {
    cout<<endl<<"请输入学号"<<endl;
    cin>>c; 
    q=-1;
    for(i=0;i<MAX;i++)
    {
      d=student2[i].number();
   	  if(c==d) 
      {
        q=i;
        student2[i].ke.showke1();
      }
   
    }
    if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
   }
}
void kecheng_outputfile()
{
	cout<<endl<<"请输入确定学生身份的方式的编号：";
 cout<<endl<<"姓名(1);"<<endl<<"学号(2);"<<endl<<endl;
 cin>>n;
 if(n==1)
 {
   cout<<endl<<"请输入姓名:"; 
   cin>>a;
   q=-1;
   for(i=0;i<MAX;i++)
   {
      b=student2[i].name();
      if(a==b) 
        {
   	      q=i;
	      student2[i].ke.showke();
        }
   } 
   if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
 }
  if(n==2)
  {
    cout<<endl<<"请输入学号"<<endl;
    cin>>c; 
    q=-1;
    for(i=0;i<MAX;i++)
    {
      d=student2[i].number();
   	  if(c==d) 
      {
        q=i;
        student2[i].ke.showke();
      }
   
    }
    if(q==-1) cout<<endl<<"未找到该学生信息"<<endl; 
   }
}
void Evaluate()
{
	int a=1,i,c=1,f=1;
	string b,d; 
	for(;a;)
	{
		cout<<endl<<"***请选择查找对象的方式***"<<endl;
		cout<<"1：按学号查找"<<endl;
		cout<<"2：按姓名查找"<<endl;
		cout<<"0：返回主菜单"<<endl;
		c=1,f=1;
		cin>>a;
		switch(a)
		{
			case 1:{
				for(;c;)
				{
					cout<<"请输入学号：";
				    cin>>b;
				    for(i=0;i<MAX;i++)
				    {
					    if(student2[i].number()==b) 
					    {
						    cout<<"您查找的学号为："<<student2[i].number()<<endl;
						    cout<<"学生姓名为：    "<<student2[i].name() <<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认，按0重新输入"<<endl;
						        cin>>c;
						        if(c==1) break;
							    else if(c==0)
							    {
							    	c=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入学号，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) c=0;
						else if(g==3)
						{
							c=0;
							a=0;
						}	 
					}
				    if(c==1)
				    {
				    	int judge;
						judge=evaluate(student2[i].math(),student2[i].physics(),student2[i].cplusplus(),student2[i].pe(),student2[i].count_GPA());
				    	if(judge==1) c=0;
				    	else if(judge==0)
				    	{
				    		c=0;
				    		a=0;
						}
					}
				} 
				break;
			}
			case 2:{
				for(;f;)
				{
					cout<<"请输入学生姓名：";
				    cin>>d;
				    for(i=0;i<MAX;i++)
				    {
					    if(student[i].back_name()==d) 
					    {
						    cout<<"您查找的学生姓名为："<<student[i].back_name()<<endl;
						    cout<<"学号为：            "<<student[i].back_number()<<endl;
						    for(;1;)
						    {
						    	cout<<"按1确认，按0重新输入"<<endl;
						        cin>>f;
						        if(f==1)
						        {
						    	    cout<<"*下面载入德育分系统*"<<endl;
						    	    break;
							    }
							    else if(f==0)
							    {
							    	f=2;
							    	break;
								}
								else cout<<"选择错误，请重新选择"<<endl;
							}
						    break;
					    } 
				    } 
				    int g;
				    if(i==MAX) 
					{
						cout<<"无此人信息"<<endl;
						int e;
						for(;1;)
						{
							cout<<"按1重新输入姓名，按2返回上一级菜单，按3返回主菜单"<<endl;
							cin>>e;
							if(e==1)
							{
								g=1;
								break;
							}
							else if(e==2)
							{
								g=2;
								break;
							}
							else if(e==3)
							{
								g=3;
								break;
							}
							else cout<<"选择错误，请重新输入"<<endl; 
						}
						if(g==1) continue;
						else if(g==2) f=0;
						else if(g==3)
						{
							f=0;
							a=0;
						}	 
					} 
				    if(f==1)
				    {
				    	int judge;
						judge=evaluate(student2[i].math(),student2[i].physics(),student2[i].cplusplus(),student2[i].pe(),student2[i].count_GPA());
				    	if(judge==1) f=0;
				    	else if(judge==0)
				    	{
				    		f=0;
				    		a=0;
						}
					}
				} 
				break;
			}
			case 0:break;
			default:cout<<"菜单选择错误，请重新选择"<<endl;break;
		}
	} 
 } 
 int evaluate(int Smath,int Sphysics,int Scplusplus,int Spe,float GPA)
{
	cout<<"你的高数成绩为："<<Smath<<endl;
	cout<<"本课程评价：";
	if(Smath>90)cout<<"这门课学得很好，继续加油！"<<endl;
	else if(Smath>75)cout<<"基础知识基本掌握，题目要多加练习，做题再认真点，注意解题的灵活性，好好努力，向更高分进军！"<<endl; 
	else if(Smath>60)cout<<"这门课学的有些不尽如人意，基础知识有较多漏洞，上课多加听讲，领会老师的思路，要下功夫了！"<<endl;
	else cout<<"再不努力就没有机会啦！把时间放在高数上吧！"<<endl; 
	cout<<endl<<"你的大物成绩为："<<Sphysics<<endl;
	cout<<"本课程评价：";
	if(Sphysics>90)cout<<"这门课学得很好，继续加油！"<<endl;
	else if(Sphysics>75)cout<<"基础知识和概念基本掌握，练习公式的灵活运用，梳理解题思路，更上一层楼！"<<endl; 
	else if(Sphysics>60)cout<<"这门课学的有些不尽如人意，上课要认真听讲了，可以进行笔记和知识点的梳理，同类型题找出相似的解题方法，下下功夫吧！"<<endl;
	else cout<<"再不努力就没有机会啦！大物4学分也很重要哦！"<<endl; 
	cout<<endl<<"你的c++成绩为："<<Scplusplus<<endl;
	cout<<"本课程评价：";
	if(Scplusplus>90)cout<<"这门课学得很好，继续加油！c++没问题的，类似的课一定也可以拿下！"<<endl;
	else if(Scplusplus>75)cout<<"光学是不行的，要多加练习，就像学英语一样，一定要实战！希望你在以后的其他课程里学会把知识付诸实践，在实践中进步！"<<endl; 
	else if(Scplusplus>60)cout<<"c++是结束了，但是类似的程序语言课还是有的，都是语言，学习方法类似，希望你能好好听讲，多加练习，弥补这门课的过失。"<<endl;
	else cout<<"信息学院的学生连个c++都学不会？不行啊，还有一次改过自新的机会，一定要好好学习了！"<<endl; 
	cout<<endl<<"你的体育成绩为："<<Spe<<endl;
	cout<<"本课程评价：";
	if(Spe>100)cout<<"输入有误，请重新输入！"<<endl;
	else if(Spe>90)cout<<"身体素质不错，不要忘了天天锻炼哦！"<<endl;
	else if(Spe>75)cout<<"是有好好的努力了，再加把劲吧，多发展体育爱好是很好的提分手段！"<<endl; 
	else if(Spe>60)cout<<"学习固然重要，身体可是第一位的啊，要多锻炼了！晨练和晚跑都是可以的！"<<endl;
	else cout<<"不是死宅还能是什么？再不锻炼就没人要了。这样下去毁的是自己。"<<endl; 
	cout<<endl<<"你的GPA为："<<GPA<<endl;
	cout<<"综合评价：";
	if(GPA>=3.50)cout<<"知识掌握的很不错，继续加油，保持好学习的劲头（^-^）"<<endl;
	else if(GPA>=3.00)cout<<"继续努力，一定可以获得更好的成绩（*-*）"<<endl; 
	else if(GPA>=2.50)cout<<"要加把劲了呀，不要被人赶超了（——）"<<endl; 
	else if(GPA>=2.00)cout<<"最近学习上是不是懒惰了呢，这可不行，要好好努力了0.0"<<endl; 
	else cout<<"再不好好学习的话可就要被淘汰了，快点努力吧（~-~）"<<endl; 
	int a;
	for(;1;)
	{
		cout<<"1.返回上一级"<<endl<<"0.返回主菜单"<<endl;
	    cin>>a; 
	    if(a==1||a==0) break;
	    else cout<<"菜单选择错误，请重新输入"<<endl;
	}
	return a;
}
void Student::SetName()
  {
   cout<<"请输入姓名:";
   cin>>Name;
  }
void Student::SetNumber()
  {
   cout<<"请输入学号:"; 
   cin>>Number;
  }
void Student::SetSex()
  {
   cout<<"请输入性别:";
   cin>>Sex;
  }
void Student::SetScore()
  {
   cout<<"请输入高等数学的成绩:";
   cin>>Math;
   cout<<"请输入大学物理的成绩:";
   cin>>Physics;
   cout<<"请输入C++的成绩:";
   cin>>CPlusPlus;
   cout<<"请输入体育的成绩:"; 
   cin>>PE;
  }
void Student::ShowName()
  {
   cout<<"姓名:"<<Name<<";"<<endl; 
  }
void Student::ShowNumber()
  {
   cout<<"学号:"<<Number<<";"<<endl; 
  }
void Student::ShowSex()
  {
   cout<<"性别:"<<Sex<<";"<<endl;
  }
void Student::ShowMScore()
  {
   cout<<"高等数学成绩:"<<Math<<endl;
  }
void Student::ShowPScore()
  {
   cout<<"大学物理成绩:"<<Physics<<endl;
  }
void Student::ShowCScore()
  {
   cout<<"C++成绩:"<<CPlusPlus<<endl;
  }
void Student::ShowPEScore()
  {
   cout<<"体育成绩:"<<PE<<endl;
  }
void Student::ChangeName()
  {
   cout<<"您要将姓名修改为:";
   cin>>Name;
  } 
void Student::ChangeNumber()
  {
   cout<<"您要将学号修改为:";
   cin>>Number;
  } 
void Student::ChangeSex()
  {
   cout<<"您要性别修改为:";
   cin>>Sex;
  } 
void Student::ChangeMScore() 
  {
   cout<<"您要将高等数学成绩修改为:";
   cin>>Math;
  }
void Student::ChangePScore() 
  {
   cout<<"您要将大学物理成绩修改为:";
   cin>>Physics;
  } 
void Student::ChangeCScore() 
  {
   cout<<"您要将C++成绩修改为:";
   cin>>CPlusPlus;
  } 
void Student::ChangePEScore() 
  {
   cout<<"您要将体育成绩修改为:";
   cin>>PE;
  }  
void Student::load()
{
	Math=0;
	Physics=0;
	CPlusPlus=0;
	PE=0;
}
string Student::name()
  {
   return Name;
  }
string Student::number()
  {
   return Number;
  }
int Student::math()
{
	return Math;
}
int Student::physics() 
{
	return Physics;
}
int Student::cplusplus() 
{
	return CPlusPlus;
}
int Student::pe() 
{
	return PE;
}
float Student::count_GPA()
{
	float a,b,c,d,e;
	if(Math>=95) a=4.33;
	else if(Math>=90) a=4.00;
	else if(Math>=85) a=3.67;
	else if(Math>=82) a=3.33;
	else if(Math>=78) a=3.00;
	else if(Math>=75) a=2.67;
	else if(Math>=72) a=2.33;
	else if(Math>=68) a=2.00;
	else if(Math>=64) a=1.67;
	else if(Math>=61) a=1.33;
	else if(Math>=60) a=1.00;
	else a=0;
	if(Physics>=95) b=4.33;
	else if(Physics>=90) b=4.00;
	else if(Physics>=85) b=3.67;
	else if(Physics>=82) b=3.33;
	else if(Physics>=78) b=3.00;
	else if(Physics>=75) b=2.67;
	else if(Physics>=72) b=2.33;
	else if(Physics>=68) b=2.00;
	else if(Physics>=64) b=1.67;
	else if(Physics>=61) b=1.33;
	else if(Physics>=60) b=1.00;
	else b=0;
	if(CPlusPlus>=95) c=4.33;
	else if(CPlusPlus>=90) c=4.00;
	else if(CPlusPlus>=85) c=3.67;
	else if(CPlusPlus>=82) c=3.33;
	else if(CPlusPlus>=78) c=3.00;
	else if(CPlusPlus>=75) c=2.67;
	else if(CPlusPlus>=72) c=2.33;
	else if(CPlusPlus>=68) c=2.00;
	else if(CPlusPlus>=64) c=1.67;
	else if(CPlusPlus>=61) c=1.33;
	else if(CPlusPlus>=60) c=1.00;
	else c=0;
	if(PE>=95) d=4.33;
	else if(PE>=90) d=4.00;
	else if(PE>=85) d=3.67;
	else if(PE>=82) d=3.33;
	else if(PE>=78) d=3.00;
	else if(PE>=75) d=2.67;
	else if(PE>=72) d=2.33;
	else if(PE>=68) d=2.00;
	else if(PE>=64) d=1.67;
	else if(PE>=61) d=1.33;
	else if(PE>=60) d=1.00;
	else d=0;
	e=(a*5.5+b*4+c*3+d)/(5.5+4+3+1);
	return e;
}
void kecheng::setvalue()  //模块二
{
	for(int i=0;i<16;i++)  //for循环控制输入
	{
		cout<<"*请输入课程名称(请简写 不要超过6个字)"<<endl;
		cin>>ming[i];
		cout<<"*请输入课程教师"<<endl;
		cin>>jiao[i];
		cout<<"*请输入教室"<<endl;
		cin>>di[i];
		cout<<"*请输入课程的起始周"<<endl;
		cin>>qi[i];
		if(qi[i]>20)            
		{
			cout<<"输入错误!  请重新输入"<<endl;   //错误判断
			cin>>qi[i];                            //重新输入
		}  
		cout<<"*请输入课程的结束周"<<endl;
		cin>>jie[i];
		if(jie[i]>20)                           //错误判断
		{
			cout<<"输入错误!  请重新输入"<<endl;
			cin>>jie[i];                        //重新输入
		} 
		cout<<"*请输入课程一周有几天有"<<endl; //一门课一周几节的处理
		int s;
		cin>>s;                               //输入节数
		{
			for(int u=0;u<s;u++)                 //for循环控制多节输入
			{
				ming[i+u]=ming[i];
				jiao[i+u]=jiao[i];
				di[i+u]=di[i];
				qi[i+u]=qi[i];
				jie[i+u]=jie[i];
				cout<<"*请输入第"<<u+1<<"次课是星期几"<<endl;
		        cin>>xing[i+u];
		        if(xing[i+u]>7)
				{
					cout<<"输入错误!  请重新输入"<<endl;
			        cin>>xing[i+u];
				}
		        cout<<"*请输入课程是第几堂"<<endl;
		        cin>>tang[i+u];
		        if(tang[i+u]>5)
				{
				    cout<<"输入错误!  请重新输入"<<endl;
			        cin>>tang[i+u];
				}
			}
		}
		i=i+s;
		cout<<"*请问是否继续下一个课程？(Y/N)"<<endl;  //是否继续输入
		char num;
		cin>>num;
		if(num=='Y'||num=='y') continue;                  //继续下一个
		else break;                                    //结束输入
	}
}
void kecheng::showke()                                //模块三 输出到文件 
{
	ofstream fout("kebiao.txt");
	fout<<student2[i].name()<<"的课表"<<endl; 
	fout<<"                                            ////////////////////////////////"<<endl;                              //课表的页眉
	fout<<"                                            //课           程           表//"<<endl;
	fout<<"                                            ////////////////////////////////"<<endl;
	fout<<"_____________________________________________________________________________________________________"<<endl;
	fout<<"         |     一     |     二     |     三     |     四     |     五     |     六     |     日     |   "<<endl;
   	fout<<"_____________________________________________________________________________________________________"<<endl;
	for(int i=1;i<6;i++)
	{
		int l;                          //用l来检测此项是否有内容输出
		switch(i)                       //课表的一天节数 输出
		{
			case 1:fout<<"一(1-2)  |";break;
		    case 2:fout<<"二(3-4)  |";break;
		    case 3:fout<<"三(5-6)  |";break;
		    case 4:fout<<"四(7-8)  |";break;
		    case 5:fout<<"五(9-10) |";break;
		}
		
		for(int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					fout<<setw(12)<<ming[n]<<"|";  //课名输出
					l=1;
				}
			}
			if(l==0)
			{
			    fout<<"            |";           //若没有则输出空格
			}
		}
		fout<<endl;
		fout<<"         | ";
		for( int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					fout<<setw(10)<<jiao[n]<<" | ";  //教师输出
					l=1;
				}
			}
			if(l==0)
			{
			    fout<<"           | ";           //若没有则输出空格
			}
		}
		fout<<endl;
		fout<<"         | ";                     
		for( int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					fout<<setw(11)<<di[n]<<"| ";    //地点输出
					l=1;
				}
			}
			if(l==0)
			{
			    fout<<"           | ";          //若没有则输出空格
			}
		}
		fout<<endl;
		fout<<"         |";
		for( int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					fout<<" ("<<setw(2)<<qi[n]<<" -"<<setw(2)<<jie[n]<<")周 ";  //总周数输出
					fout<<"|";
					l=1;
				}
			}
			if(l==0)
			{
			    fout<<setw(12)<<"          ";     //若没有则输出空格
				fout<<"|";
			}
		}
		fout<<endl;
        	fout<<"_____________________________________________________________________________________________________"<<endl;
	}
}
void kecheng::showke1()                                //模块三 输出课表 
{
	cout<<"                                   ////////////////////////////////"<<endl;                              //课表的页眉
	cout<<"                                   //课           程           表//"<<endl;
	cout<<"                                   ////////////////////////////////"<<endl;
	cout<<"_____________________________________________________________________________________________________"<<endl;
	cout<<"         |     一     |     二     |     三     |     四     |     五     |     六     |     日     |   "<<endl;
   	cout<<"_____________________________________________________________________________________________________"<<endl;
	for(int i=1;i<6;i++)
	{
		int l;                          //用l来检测此项是否有内容输出
		switch(i)                       //课表的一天节数 输出
		{
			case 1:cout<<"一(1-2)  |";break;
		    case 2:cout<<"二(3-4)  |";break;
		    case 3:cout<<"三(5-6)  |";break;
		    case 4:cout<<"四(7-8)  |";break;
		    case 5:cout<<"五(9-10) |";break;
		}
		for(int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					cout<<setw(12)<<ming[n]<<"|";  //课名输出
					l=1;
				}
			}
			if(l==0)
			{
			    cout<<"            |";           //若没有则输出空格
			}
		}
		cout<<endl;
		cout<<"         | ";
		for( int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					cout<<setw(10)<<jiao[n]<<" | ";  //教师输出
					l=1;
				}
			}
			if(l==0)
			{
			    cout<<"           | ";           //若没有则输出空格
			}
		}
		cout<<endl;
		cout<<"         | ";                     
		for( int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					cout<<setw(11)<<di[n]<<"| ";    //地点输出
					l=1;
				}
			}
			if(l==0)
			{
			    cout<<"           | ";          //若没有则输出空格
			}
		}
		cout<<endl;
		cout<<"         |";
		for( int j=1;j<8;j++)
		{
			l=0;
			for(int n=0;n<16;n++)
			{
				if(tang[n]==i&&xing[n]==j)
				{
					cout<<" ("<<setw(2)<<qi[n]<<" -"<<setw(2)<<jie[n]<<")周 ";  //总周数输出
					cout<<"|";
					l=1;
				}
			}
			if(l==0)
			{
			    cout<<setw(12)<<"          ";     //若没有则输出空格
				cout<<"|";
			}
		}
		cout<<endl;
        	cout<<"_____________________________________________________________________________________________________"<<endl;
	}
}

