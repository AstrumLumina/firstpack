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
	printf("1:�½��ɼ���\n2:����ԭ�ɼ���\n3���������β���ѧ��\n4:�޸�ѧ����Ϣ\n5:�鿴�Լ��ĳɼ�������\n6:ͳ���йҿƵ�ͬѧ\n7�����������ɼ�����\n8:�������Ļ\n0���˳�\n");
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
/*�½��ɼ���*/
void newstus(stu*pstu,int turn[])
{
	printf("ѧ��������");
	scanf("%d",&n);
	printf("ѧ�� ���� ��һ�ɼ� �ƶ� ���� ���� ����\n");
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
	printf("�ǣ�1����0�����ո�����ĳɼ�����ӡ���ļ���");
	scanf("%d",&j);
	if(j){
		prinstus(pstu,turn,0,n);
	} 
 } 
/*��ӡ*/
void prinstus(stu*pstu,int turn[],int in,int out)
{
	FILE*fp;
	int i;
    char ch[10]; 
	printf("��Ϊ��ӡ�ļ�ȡһ���ļ�����");
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
	printf("��ӡ��ɣ�\n");
}
/*���������ɼ�����*/
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
	printf("�ǣ�1����0����������ĳɼ���Ϣ��ӡ���ļ��У�");
	scanf("%d",&j);
	if(j){
		prinstus(pstu,turn,0,n);
	} 
	paixu=0;
}
/*�鿴�Լ��ĳɼ�������*/
void find(stu*pstu,int turn[])
{
	int choice;
	int i;
	if(paixu){
		printf("���������У����Ժ�鿴����------\n");
		rant(pstu,turn);
	}
	printf("0�������ֲ�ѯ 1����ѧ�Ų�ѯ:");
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
	printf("�������Ϊ�� %d \n",i+1);
	printf("�ǣ�1����0������ĳɼ���Ϣ��ӡ���ļ��У�");
	scanf("%d",&choice);
	if(choice){
		prinstus(pstu,turn,i,i+1);
	} 
	return ;
}
/*�޸�ѧ����Ϣ*/
void change(stu*pstu,int turn[])
{
	int choice;
	int j,i,score;
	printf("���������� Ҫ�޸ĵĿ�Ŀ�� Ҫ��Ϊ��ֵ\n");
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
	printf("�ǣ�1����0�������ĺ�ĳɼ�����ӡ���ļ���(��Ҫ����������ٴ�ӡ����˳������)��");
	scanf("%d",&choice);
	if(choice){
		prinstus(pstu,turn,0,n);
	} 
}
/*��׼����������δ��������󣬸��ĺ��Լ�ͳ�Ƴ���������*/ 
void screen(stu*pstu,int turn[],int n)
{
	int i;
	printf("��Ż����� ѧ�� ���� ƽ���� �ܷ� ��һ �ƶ� ���� ���� ����\n");
	for(i=0;i<n;i++){
		printf("%-3d%-4d%-10s%-7.2f%-4d%-4d%-4d%-4d%-4d%-4d%\n",i+1,(pstu+turn[i])->num,
		(pstu+turn[i])->name,(float)(pstu+turn[i])->sum/5,(pstu+turn[i])->sum,(pstu+turn[i])->sub[0],
		(pstu+turn[i])->sub[1],(pstu+turn[i])->sub[2],(pstu+turn[i])->sub[3],(pstu+turn[i])->sub[4]);
	}
}
/*����*/
void beifen(stu*pstu,int turn[])
{
	FILE*fp;
	int i;
	if( (fp=fopen("����.txt","w"))==NULL ){
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
 /*���ر���*/
void jiazai(stu*pstu)
{
	FILE*fp;
	int i=0;
	if( (fp=fopen("����.txt","r+"))==NULL ){
		perror("fopen:");
		return ;
	}
	while( !feof(fp) ){
		                   /*�˴��ո񲻿�ʡ,���������һЩδ֪Ԫ��*/
		fscanf(fp,"%d%d%s%lf%d%d%d%d%d%d ",&((pstu+i)->rant),&((pstu+i)->num),(pstu+i)->name,&((pstu+i)->ave),
		&((pstu+i)->sum),(pstu+i)->sub,(pstu+i)->sub+1,(pstu+i)->sub+2,(pstu+i)->sub+3,(pstu+i)->sub+4 );
		++i;
	}
	n=i;
	if( fclose(fp) ){
		perror("fclose:");
	}	
	printf("������ɣ�\n");
}
/*����༶ƽ����*/ 
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
/*�ֶβ��Һ���*/ 
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
/*ͳ�ƹҿ���*/
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
/*���ܶ�ʵ��*/ 
void function2(stu*pstu,stu* p)
{
	int choice;
	printf("0:�ֶβ���  1:����༶ƽ���� :"); 
	scanf("%d",&choice);
	if(choice){
		double avera=classave(pstu);
		printf("classave= %.3lf\n",avera);
	}else{
		printf("�����밴��������(min max)���������ݣ�0:ƽ���� 1����һ 2���ƶ� 3������ 4������ 5�����壩\n");
		printf("80 100 1 -----�����Ϳ��Բ��ҿ�һ��80�����ϵ�ͬѧ\n");
		int min,max;
		scanf("%d%d%d",&min,&max,&choice);
		int count;
		count=fenduan(pstu,p,min,max,choice);
		int a[N]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
		screen(p,a,count);
		printf("�ǣ�1����0����Щ��Ϣ��ӡ���ļ��У�");
		scanf("%d",&choice);
		if(choice){
			prinstus(p,a,0,count);
		} 
	}
}
/*������ʵ��*/
void function6(stu*pstu,stu*p)
{
	int count=fail(pstu,p);
	int a[N]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; 
	screen(p,a,count);
	int choice;
	printf("�ǣ�1����0����Щ��Ϣ��ӡ���ļ��У�");
	scanf("%d",&choice);
	if(choice){
		prinstus(p,a,0,count);
	} 
}
/*
* ѧ���ɼ��������������ʵ��
��1����ѧ�������������Ƴɼ�����������޸ģ�
��2����ʦ���ԶԳɼ��������������в�ѯ��ͳ�ơ�������
��3���԰�Ϊ��λ��ӡ�ɼ�����
��4��ѧ�����Լ��ĳɼ����������в�ѯ��
   ��5������2��-��4���Ľ��д���ļ��С�

*/
/*����*/
/*
1
4 
1    gfdh   56     66    55   45   69
2    abc    90     99    89   88   97
3    def    22     33    22   23   45
4    hiu    34     45    46   42   48
1
*/

