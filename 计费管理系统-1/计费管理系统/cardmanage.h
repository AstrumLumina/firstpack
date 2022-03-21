#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structuser.h"

#define NOWYEAR 2022

void cardaccountmanage(void);
void cardmenu(void);
void addcard(void);
void  initialcard(char* name, char* phone, char* identifyid);
void deletcard(void);
void realdelonecard(struct user* beforetodel);
void findcard(void);
struct user* findbynum(void);
struct user* findbyidentify(void);
void prinonecard(struct user* toprin);
struct user* findbyname(void);
void prinallcard(void);
//1:允许操作   0：验证失败
int  perrmission(void);
void cangoahead(void);
void freezecard(void);
void changekeey(void);