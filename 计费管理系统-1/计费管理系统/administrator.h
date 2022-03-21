#pragma once

#include<stdio.h>
#include<string.h>
#include"mainh.h"
#include"structuser.h"
#include<conio.h>


void adminismenu(void);
void administrator(void);

void firstaddadminis(void);
int  prinadminis(struct adminis* firsttoprin);
void addoneadminis(void);
int  perrmission(void);
void cangoahead(void);
void getkeey(char keey[]);
void changeadminis(void);
int canchange(void);
void deladminis(void);
void deloneadminis(struct adminis* todel);