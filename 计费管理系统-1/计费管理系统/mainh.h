#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>



//主函数中的函数声明****************************************************

// 打印用户的使用记录到屏幕
void prinlog(char* cardnum);

//主菜单函数
void mainmenu(void);

void loaduserdate(void);

void firstinitial(void);




//用户使用数据相关函数
// 0.销卡
// 1.开卡
// 2.充值
// 3.退费
// 4.普通上机
// 5.包夜上机
// 6.活动上机
// 7.
// 
//保存添加用户使用记录
void savelog(int num, char* cardnum);



//主要的功能函数申明********************************************************************

//7.管理员管理
void administrator(void);
void firstaddadminid(void);
int  perrmission(void);

//1.卡管理 
void cardaccountmanage(void);


//2.计费标准管理 
void chargestand(void);

//4.费用管理                  
void expensivemanage(void);

// 5.查询统计 
void find(void);

//3.上下机管理
void timemanage(void);

// 6.活动管理
void active(void);


//时间转换字符函数**************************************
void timetostr(time_t t, char* savetime);


