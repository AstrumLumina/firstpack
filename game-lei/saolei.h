#pragma once

//����ϵͳͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//һЩ����Ĭ��ֵ����
#define WID  25
#define LEN  45
#define HARD 0
#define INITIALWID  {10,20,23,20};
#define INITIALLEN  {10,24,45,30};
#define LEI         {15,60,120,100};
#define	LEIBIAO  'B'
#define PANBIAO  '*'
//��������
//��ӡ���˵�����
void menu();
//��Ϸ���ɺ���******************************************
void game(int wid,int len,int lei, char leibiao,char panbiao);
//��ʼ�����׺���  //1: ������     0������
void initialleiboard(char leiboard[WID][LEN],int  wid,int  len,int  lei);
//��ʼ����ӡ���̺���
void initialprinboard(int prinboard[WID][LEN], int wid, int len);
//�鿴ָ����Χλ���м����׵ĺ���
char countlei(char leiboard[WID][LEN], int  wid, int  len, int x, int y);
//���׽��״̬��¼���º���
void changeprinbosrd(char leiboard[WID][LEN],int prinboard[WID][LEN],int wid,int len,int x,int y);
//�鿴ʣ��δ֪������
int countrest(int prinboard[WID][LEN], int wid, int len);
//������ӡ����
void printboard(char leiboard[WID][LEN], int prinboard[WID][LEN], int wid, int len, char leibiao, char panbiao, int lei);
//*************************************************************************************
//���ü��ɺ���
void set(int* wid, int* len, int* lei, int *hard,char*leibiao,char *panbiao);
//��ӡ���ú���
void pirnset(int* wid, int* len, int* hard, int* lei, char* leibiao, char* panbiao);
//�������ú���
void beifenset(int wid, int len, int lei, int hard, char leibiao, char panbiao);
//�����ϴ����ú���
void loadset(int* wid, int* len, int* lei, int* hard, char* leibiao, char* panbiao);
//�Զ����淨��������
void setmine(int* wid, int* len, int* lei);
//�ж���Ϸ�����Ƿ���������ֹ�Բ��������ݿ�ʼ��Ϸ��ɴ��� 1������ 0��������
int ispropre(int wid, int len, int lei);

