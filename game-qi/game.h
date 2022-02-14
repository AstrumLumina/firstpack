#pragma once

//包含系统头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


//棋盘最大的大小...........................................................
#define WID 13
#define LEN 25
//棋子玩法....默认为三子棋
#define NUM 3
#define INITIALWID 3
#define INITIALLEN 3
#define HARD 1//默认难度

//电脑棋子类型......................................................
//chessman[0]为玩家的，chessman[1]为电脑的
//在此处定义可以代码上更改棋子的默认类型
#define CHESSMAN  chessman[2] = { '*','#' };


//游戏函数*......................................................................................

//设置函数.......................................
void set();
//设置菜单打印
void setmenu();
// 改变棋盘大小
void changeboard();
//选择玩法种类（现在为 %d子棋）
void changenum();
// 设置棋盘符号
void changechessman();
//设置先走玩家
void  changefirst();
// 设置游戏难度
void changehard();
//.............................................................


//初始化函数
void initialboard(char board[WID][LEN],int wid ,int len);
//打印棋盘和棋子
void prinboard(char board[WID][LEN], int wid, int len);

//落子.................................................................................................

//电脑随机走棋子的函数
void computer(char board[WID][LEN], int wid,int len);


//电脑非随机走棋子的函数（高级玩法，难度较高）****************************************************
void advcomputer(char board[WID][LEN], int wid, int len, int num);

//阻止玩家胜利位置判断
int fight(char board[WID][LEN], int wid, int len, int num, int x,int y);
// 必赢位置判断
int willwin(char board[WID][LEN], int wid, int len, int num, int x,int y);
//位置算力判断
int ability(char board[WID][LEN], int wid, int len, int num, int x, int y);


//玩家走棋子******************************************************
void player(char board[][LEN], int wid,int len);

//判断输赢函数.............................................................................................
char iswin(char board[WID][LEN], int wid, int len, int num);


//........................................

//游戏设置数据备份函数
void beifen();
//游戏设置数据加载函数
void load();
//打印设置数据
void prinset();