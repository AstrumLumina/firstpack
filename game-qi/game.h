#pragma once

//����ϵͳͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


//�������Ĵ�С...........................................................
#define WID 13
#define LEN 25
//�����淨....Ĭ��Ϊ������
#define NUM 3
#define INITIALWID 3
#define INITIALLEN 3
#define HARD 1//Ĭ���Ѷ�

//������������......................................................
//chessman[0]Ϊ��ҵģ�chessman[1]Ϊ���Ե�
//�ڴ˴�������Դ����ϸ������ӵ�Ĭ������
#define CHESSMAN  chessman[2] = { '*','#' };


//��Ϸ����*......................................................................................

//���ú���.......................................
void set();
//���ò˵���ӡ
void setmenu();
// �ı����̴�С
void changeboard();
//ѡ���淨���ࣨ����Ϊ %d���壩
void changenum();
// �������̷���
void changechessman();
//�����������
void  changefirst();
// ������Ϸ�Ѷ�
void changehard();
//.............................................................


//��ʼ������
void initialboard(char board[WID][LEN],int wid ,int len);
//��ӡ���̺�����
void prinboard(char board[WID][LEN], int wid, int len);

//����.................................................................................................

//������������ӵĺ���
void computer(char board[WID][LEN], int wid,int len);


//���Է���������ӵĺ������߼��淨���ѶȽϸߣ�****************************************************
void advcomputer(char board[WID][LEN], int wid, int len, int num);

//��ֹ���ʤ��λ���ж�
int fight(char board[WID][LEN], int wid, int len, int num, int x,int y);
// ��Ӯλ���ж�
int willwin(char board[WID][LEN], int wid, int len, int num, int x,int y);
//λ�������ж�
int ability(char board[WID][LEN], int wid, int len, int num, int x, int y);


//���������******************************************************
void player(char board[][LEN], int wid,int len);

//�ж���Ӯ����.............................................................................................
char iswin(char board[WID][LEN], int wid, int len, int num);


//........................................

//��Ϸ�������ݱ��ݺ���
void beifen();
//��Ϸ�������ݼ��غ���
void load();
//��ӡ��������
void prinset();