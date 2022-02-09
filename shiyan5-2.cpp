#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 15

struct student{
	int num;
	char name[10];
	int sub[5];
	int sum;
	double ave;
	int rant;
	
};
typedef struct student stu;

void change(stu*pstu,int turn[]);
void rant(stu*pstu,int turn[]);
void find(stu*pstu,int turn[]);
void newstus(stu*pstu,int turn[]);
void prinstus(stu*pstu,int turn[],int in,int out);
void beifen(stu*pstu,int turn[]);
void jiazai(stu*pstu);
void screen(stu*pstu,int turn[],int n);
int fenduan(stu*pstu,stu* p,int min,int max,int choice);
double classave(stu*pstu);
void function6(stu*pstu,stu*p);
void function2(stu*pstu,stu*p);
int fail(stu*pstu,stu*p);

int n=0;
int paixu=1; 

int main(void)
{
	stu stus[N],*pstu=stus;
	stu stu2[N],*p=stu2;
	int option;
	int turn[N]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; 
	printf("1:新建成绩单\n2:加载原成绩单\n3：按分数段查找学生\n4:修改学生信息\n5:查看自己的成绩与排名\n6:统计有挂科的同学\n7：排名即按成绩排序\n8:输出到屏幕\n0：退出\n");
	printf("YOU CHOICE:");
	scanf("%d",&option);
	while(option){
		switch(option){
		case 1: newstus(pstu,turn);break;
		case 2: jiazai(pstu); break;
		case 3: function2(pstu,p);break;
		case 4: change(pstu,turn); break;
		case 5: find(pstu,turn);break;
		case 6: function6(pstu,p);break;
		case 7: rant(pstu,turn);break;
		case 8: screen(pstu,turn,n);break;
		default:printf("Unkonw chioce\n");break;
	    }
	    printf("YOU CHOICE:");
	    scanf("%d",&option);
   }
   beifen(pstu,turn);
}
/*新建成绩单*/
void newstus(stu*pstu,int turn[])
{
	printf("学生个数：");
	scanf("%d",&n);
	printf("学号 姓名 科一成绩 科二 科三 科四 科五\n");
	int i=0;
	int j=0;
	do{
		scanf("%d %s",&((pstu+i)->num),(pstu+i)->name);
		(pstu+i)->sum=0;
		for(j=0;j<5;j++){
			scanf("%d",&((pstu+i)->sub[j]));
			(pstu+i)->sum+=(pstu+i)->sub[j];
		}
		++i;
	}while(i<n);
	printf("是（1）否（0）将刚刚输入的成绩单打印至文件：");
	scanf("%d",&j);
	if(j){
		prinstus(pstu,turn,0,n);
	} 
 } 
/*打印*/
void prinstus(stu*pstu,int turn[],int in,int out)
{
	FILE*fp;
	int i;
    char ch[10]; 
	printf("请为打印文件取一个文件名：");
	scanf(" %s",ch); 
	if( (fp=fopen(ch,"w"))==NULL ){
		perror("fopen:");
		return ;
	}
	for(i=in;i<out;i++){
		fprintf(fp,"%-3d%-4d%-10s%-7.2f%-4d%-4d%-4d%-4d%-4d%-4d%\n",i,(pstu+turn[i])->num,
		(pstu+turn[i])->name,(float)(pstu+turn[i])->sum/5,(pstu+turn[i])->sum,(pstu+turn[i])->sub[0],
		(pstu+turn[i])->sub[1],(pstu+turn[i])->sub[2],(pstu+turn[i])->sub[3],(pstu+turn[i])->sub[4]);
	}
	if( fclose(fp) ){
		perror("fclose:");
	}
	printf("打印完成！\n");
}
/*排名即按成绩排序*/
void rant(stu*pstu,int turn[])
{
	int temp;
 	int max;
 	int j,i;
 	int flag;
	for(i=0;i<n-1;++i){
	  	max=i;
	 	for(j=i+1;j<n;++j){
	 		flag=(pstu+turn[max])->sum-(pstu+turn[j])->sum;
	 		if( flag<0 ){
	 			max=j;
			}
		}
	 	if(max!=i){
		 	temp=turn[max];
			turn[max]=turn[i];
			turn[i]=temp;	
		}
	}
    for(i=0;i<n;++i){
	 	(pstu+turn[i])->rant=i+1;
	}
	screen(pstu, turn,n);
	printf("是（1）否（0）将排名后的成绩信息打印到文件中：");
	scanf("%d",&j);
	if(j){
		prinstus(pstu,turn,0,n);
	} 
	paixu=0;
}
/*查看自己的成绩与排名*/
void find(stu*pstu,int turn[])
{
	int choice;
	int i;
	if(paixu){
		printf("正在排序中，请稍后查看排名------\n");
		rant(pstu,turn);
	}
	printf("0：按名字查询 1：按学号查询:");
	scanf("%d",&choice);

	if(choice){
		int number;
		printf("num:");
		scanf("%d",&number);
		for(i=0;i<n;i++){
			if( (pstu+turn[i])->num==number ){
					break;
			}
		}
	}else{
		char ch[10];
		printf("name:");
		scanf("%s",ch);
		for(i=0;i<n;i++){
			if( (strcmp( ch,(pstu+turn[i])->name ) ) ==0 ){
					break;
			}
		}
	}
	printf("你的排名为： %d \n",i+1);
	printf("是（1）否（0）将你的成绩信息打印到文件中：");
	scanf("%d",&choice);
	if(choice){
		prinstus(pstu,turn,i,i+1);
	} 
	return ;
}
/*修改学生信息*/
void change(stu*pstu,int turn[])
{
	int choice;
	int j,i,score;
	printf("请输入姓名 要修改的科目号 要改为的值\n");
	char ch[10];
	printf("name:");
	scanf("%s %d %d",ch,&j,&score);
	for(i=0;i<n;i++){
		if( ( strcmp(ch,(pstu+i)->name) )==0 ){
			break;
		}
	}
	(pstu+i)->sum-=(pstu+i)->sub[j-1];
	(pstu+i)->sub[j-1]=score;
	(pstu+i)->sum+=score;
	paixu=1;
	printf("是（1）否（0）将更改后的成绩单打印到文件中(若要重新排序后再打印请可退出后操作)：");
	scanf("%d",&choice);
	if(choice){
		prinstus(pstu,turn,0,n);
	} 
}
/*标准输出，可输出未排序，排序后，更改后，以及统计出来的数据*/ 
void screen(stu*pstu,int turn[],int n)
{
	int i;
	printf("序号或排名 学号 姓名 平均分 总分 科一 科二 科三 科四 科五\n");
	for(i=0;i<n;i++){
		printf("%-3d%-4d%-10s%-7.2f%-4d%-4d%-4d%-4d%-4d%-4d%\n",i+1,(pstu+turn[i])->num,
		(pstu+turn[i])->name,(float)(pstu+turn[i])->sum/5,(pstu+turn[i])->sum,(pstu+turn[i])->sub[0],
		(pstu+turn[i])->sub[1],(pstu+turn[i])->sub[2],(pstu+turn[i])->sub[3],(pstu+turn[i])->sub[4]);
	}
}
/*备份*/
void beifen(stu*pstu,int turn[])
{
	FILE*fp;
	int i;
	if( (fp=fopen("备份.txt","w"))==NULL ){
		perror("fopen:");
		return ;
	}
	for(i=0;i<n;i++){
		fprintf(fp,"%-3d%-4d%-10s%-7.2f%-4d%-4d%-4d%-4d%-4d%-4d%\n",i,(pstu+turn[i])->num,
		(pstu+turn[i])->name,(float)(pstu+turn[i])->sum/5,(pstu+turn[i])->sum,(pstu+turn[i])->sub[0],
		(pstu+turn[i])->sub[1],(pstu+turn[i])->sub[2],(pstu+turn[i])->sub[3],(pstu+turn[i])->sub[4]);
	}
	if( fclose(fp) ){
		perror("fclose:");
	}	
} 
 /*加载备份*/
void jiazai(stu*pstu)
{
	FILE*fp;
	int i=0;
	if( (fp=fopen("备份.txt","r+"))==NULL ){
		perror("fopen:");
		return ;
	}
	while( !feof(fp) ){
		                   /*此处空格不可省,否则会多读入一些未知元素*/
		fscanf(fp,"%d%d%s%lf%d%d%d%d%d%d ",&((pstu+i)->rant),&((pstu+i)->num),(pstu+i)->name,&((pstu+i)->ave),
		&((pstu+i)->sum),(pstu+i)->sub,(pstu+i)->sub+1,(pstu+i)->sub+2,(pstu+i)->sub+3,(pstu+i)->sub+4 );
		++i;
	}
	n=i;
	if( fclose(fp) ){
		perror("fclose:");
	}	
	printf("加载完成！\n");
}
/*计算班级平均分*/ 
double classave(stu*pstu)
{
	int i;
	double all=0;
	for(i=0;i<n;i++){
		all+=(pstu+i)->sum;
	}
	all/=(n*5);
	return all;
}
/*分段查找函数*/ 
int fenduan(stu*pstu,stu* p,int min,int max,int choice)
{
	int i;
	int count=0;
	if(choice=0){
		min*=n;
		max*=n;
		for(i=0;i<n;i++){
			if( (pstu+i)->sum>=min&&(pstu+i)->sum<=max ){
				*(p+count)=*(pstu+i);
				++count;
			}
		}
	}else{
		for(i=0;i<n;i++){
			if( (pstu+i)->sub[i-1]>=min&&(pstu+i)->sub[i-1]<=max ){
				*(p+count)=*(pstu+i);
				++count;
			}
		}	
	}
	return count;
}
/*统计挂科数*/
int fail(stu*pstu,stu*p)
{
	int i;
	int j;
	int fall=0;
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			if( (pstu+i)->sub[j]<60 ){
				*(p+fall)=*(pstu+i);
				++fall;
				break;
			}
		}
	}
	return fall;
}
/*功能二实现*/ 
void function2(stu*pstu,stu* p)
{
	int choice;
	printf("0:分段查找  1:计算班级平均分 :"); 
	scanf("%d",&choice);
	if(choice){
		double avera=classave(pstu);
		printf("classave= %.3lf\n",avera);
	}else{
		printf("输入请按查找区间(min max)，查找内容（0:平均分 1：科一 2：科二 3：科三 4：科四 5：科五）\n");
		printf("80 100 1 -----这样就可以查找科一在80分以上的同学\n");
		int min,max;
		scanf("%d%d%d",&min,&max,&choice);
		int count;
		count=fenduan(pstu,p,min,max,choice);
		int a[N]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
		screen(p,a,count);
		printf("是（1）否（0）这些信息打印到文件中：");
		scanf("%d",&choice);
		if(choice){
			prinstus(p,a,0,count);
		} 
	}
}
/*功能六实现*/
void function6(stu*pstu,stu*p)
{
	int count=fail(pstu,p);
	int a[N]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; 
	screen(p,a,count);
	int choice;
	printf("是（1）否（0）这些信息打印到文件中：");
	scanf("%d",&choice);
	if(choice){
		prinstus(p,a,0,count);
	} 
}
/*
* 学生成绩管理程序的设计与实现
（1）对学生的姓名、各科成绩进行输入和修改；
（2）老师可以对成绩按各种条件进行查询、统计、排名；
（3）以班为单位打印成绩单；
（4）学生对自己的成绩和排名进行查询；
   （5）将（2）-（4）的结果写入文件中。

*/
/*用例*/
/*
1
4 
1    gfdh   56     66    55   45   69
2    abc    90     99    89   88   97
3    def    22     33    22   23   45
4    hiu    34     45    46   42   48
1
*/

