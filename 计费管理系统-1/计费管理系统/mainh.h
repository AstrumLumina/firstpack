#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>



//�������еĺ�������****************************************************

// ��ӡ�û���ʹ�ü�¼����Ļ
void prinlog(char* cardnum);

//���˵�����
void mainmenu(void);

void loaduserdate(void);

void firstinitial(void);




//�û�ʹ��������غ���
// 0.����
// 1.����
// 2.��ֵ
// 3.�˷�
// 4.��ͨ�ϻ�
// 5.��ҹ�ϻ�
// 6.��ϻ�
// 7.
// 
//��������û�ʹ�ü�¼
void savelog(int num, char* cardnum);



//��Ҫ�Ĺ��ܺ�������********************************************************************

//7.����Ա����
void administrator(void);
void firstaddadminid(void);
int  perrmission(void);

//1.������ 
void cardaccountmanage(void);


//2.�Ʒѱ�׼���� 
void chargestand(void);

//4.���ù���                  
void expensivemanage(void);

// 5.��ѯͳ�� 
void find(void);

//3.���»�����
void timemanage(void);

// 6.�����
void active(void);


//ʱ��ת���ַ�����**************************************
void timetostr(time_t t, char* savetime);


