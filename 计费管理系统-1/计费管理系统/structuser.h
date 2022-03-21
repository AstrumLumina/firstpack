#pragma once


//与保存用户数据有关的的宏定义
#define NAMEMAX  11
#define PHONEMAX  13
#define CARDNUM   15
#define DATEMAX   18 //4年-2月-2日-2时-2分 共17个

//保存用户数据的结构体
struct user {

	char username[NAMEMAX];//11
	char phone[PHONEMAX];//13
	//char cardnum[CARDNUM];
	char lastplaytime[DATEMAX];//18
	char identify[21];
	char keeyworld[21];

	int cardnum;

	int playfrequent;
	double palytime;//总计游戏时间
	double restfees;
	double allfees;
	int usertype; //1:活跃用户   2：新用户   3：老用户   4：不活跃用户     5：正常用户  
	int isfreeze; //被冻结
	//不保存的数据
	int isplay;//1;正常上机   2；包夜    3；高级包厢  4.活动上机  5.被冻结
	//time_t lastplaytime;
	time_t starttime;

	struct user* next;
};

//管理员信息的结构体
struct adminis {
	char permission[2];
	char id[15];
	char keeyword[21];
	char quesone[21];
	char questwo[21];
	struct adminis* before;
};
