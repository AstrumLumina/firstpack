#pragma once

//包含系统头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//一些变量默认值设置
#define WID  25
#define LEN  45
#define HARD 0
#define INITIALWID  {10,20,23,20};
#define INITIALLEN  {10,24,45,30};
#define LEI         {15,60,120,100};
#define	LEIBIAO  'B'
#define PANBIAO  '*'
//函数声明
//打印主菜单函数
void menu();
//游戏集成函数******************************************
void game(int wid,int len,int lei, char leibiao,char panbiao);
//初始化制雷函数  //1: 遇到雷     0：继续
void initialleiboard(char leiboard[WID][LEN],int  wid,int  len,int  lei);
//初始化打印棋盘函数
void initialprinboard(int prinboard[WID][LEN], int wid, int len);
//查看指定周围位置有几个雷的函数
char countlei(char leiboard[WID][LEN], int  wid, int  len, int x, int y);
//排雷结果状态记录更新函数
void changeprinbosrd(char leiboard[WID][LEN],int prinboard[WID][LEN],int wid,int len,int x,int y);
//查看剩余未知雷区数
int countrest(int prinboard[WID][LEN], int wid, int len);
//雷区打印函数
void printboard(char leiboard[WID][LEN], int prinboard[WID][LEN], int wid, int len, char leibiao, char panbiao, int lei);
//*************************************************************************************
//设置集成函数
void set(int* wid, int* len, int* lei, int *hard,char*leibiao,char *panbiao);
//打印设置函数
void pirnset(int* wid, int* len, int* hard, int* lei, char* leibiao, char* panbiao);
//保存设置函数
void beifenset(int wid, int len, int lei, int hard, char leibiao, char panbiao);
//加载上次设置函数
void loadset(int* wid, int* len, int* lei, int* hard, char* leibiao, char* panbiao);
//自定义玩法方案设置
void setmine(int* wid, int* len, int* lei);
//判断游戏数据是否正常，防止以不正常数据开始游戏造成错误 1：正常 0：不正常
int ispropre(int wid, int len, int lei);

