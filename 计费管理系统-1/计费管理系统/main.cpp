#define   _CRT_SECURE_NO_WARNINGS  1
#define  _CRT_SECURE_NO_DEPRECATE 1


#include"mainh.h"
#include"structuser.h"

//struct user {
//	
//	char username[NAMEMAX];
//	char phone[PHONEMAX];
//	char cardnum[CARDNUM];
//	char lastplaytime[DATEMAX];
//	char identify[20];
//	//char keeyworld[20];
//
//
//	int playfrequent;
//	int palytime;
//	int restfees;
//	int allfees;
//	int isplay;
//	int usertype;//1:活跃用户   2：新用户   3：老用户   4：不活跃用户     5：正常用户
//	//time_t lastplaytime;
//	time_t starttime;
//
//	struct user* next;
//};


//全局变量
struct user* head=NULL;
struct user* last = NULL;
int alluser = 0;//用户总数
int usersize=0;
int userisplay = 0;
int userid;
int adminiss = -1;
struct adminis* mainadministrator;//头指针
struct adminis* nowadministrator;
struct adminis* lastadministrator;
//char administrators[5][30] = { "","","" };

enum mainchoice {
	MEXIT, CARDMANAGE, CHARGESTAND, TIME, EXPENSEMANAGE, FIND, ACTIVE, ADMINISTRATOR
};
int main(void) {
	{
		printf("由于 该程序还在完善中，部分功能还不完善，且存在一些已知问题，例如缺少对输入的检测，\n\
还请使用者要求使用该系统，尽量减少输入字符长度，以避免错误\n\
该程序的数据只有在主动退出与运行是会自动保存备份数据，为了防止数据丢失，请勿直接关闭该程序\n");
		printf("按任意键继续\\>:");
		//getchar();
		scanf("%*[^\n]%*c");
	}
	firstinitial();
	firstaddadminid();

	int option = -1;
	do {
		system("cls");
		mainmenu();
		option = -1;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
			case MEXIT:
				printf("退出 \n");
				if (userisplay > 0) {
					int a = 0;
					printf("目前还有玩家正在上机中，请您确然是否关闭该系统（回到只部分用户数据丢失）(0:否  其他：是）\\:");
					scanf("%d", &a);
					scanf("%*[^\n]%*c");
					if (!a) {
						option = -1;
					}
					else {
						printf("\n\n出于安全考虑，我们需要验证您的身份\\>\n\n");
						a = perrmission();
						if (!a) {
							printf("身份验证失败，无法退出该系统\n");
							option = -1;
						}
					}
				}
				break;
			case CARDMANAGE:
				printf("卡管理 \n");
				cardaccountmanage();
				break;
			case CHARGESTAND:
				printf("计费标准管理 \n");
				chargestand();
				break;
			case TIME:
				printf("上下机管理\n");
				timemanage();
				break;
			case EXPENSEMANAGE:
				printf("费用管理 \n");
				expensivemanage();
				break;
			case FIND:
				printf("查询统计\n");
				find();
				break;
			case ACTIVE:
				printf("活动管理\n");
				active();
				break;
			case ADMINISTRATOR:
				printf("管理员管理\n");
				administrator();
				break;
			default:
				printf("不合法输入，请重新输入！！！\n");
				printf("输入任意字符继续：");
				getchar();
				scanf("%*[^\n]%*c");
		}
		//loaduserdate();
	} while(option);
	//保存数据后退出
	loaduserdate();
}

void mainmenu(void) {
	printf("\n\n");
	printf("******************************************************************\n");
	printf("**   1.卡管理           2.计费标准管理        3.上下机管理      **\n");
	printf("**   4.费用管理         5.查询统计            6.活动管理        **\n");
	printf("**   7.管理员管理                             0.退出            **\n");
	printf("******************************************************************\n\n");
	printf("请输入您的选择\\>:");
}

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


//打印用户的使用记录到屏幕
void prinlog(char* cardnum) {

}
void firstinitial(void) {
	//初始化卡用户数据
	usersize = sizeof(struct user);
	if (head = (struct user*)malloc(usersize)) {
		head->next = NULL;
		last = head;
	}
	else {
		printf("未能成功申请内存，请您退出程序重新启动!!!\n");
	}
	FILE* fp = NULL;
	if (fp = fopen("load.txt", "r")) {
		fscanf(fp, "%d %d %d ", &alluser, &userid,&adminiss);
		int num = alluser;
		while (num--) {
			if (last->next = (struct user*)malloc(usersize)) {
				last = last->next;
				fscanf(fp, "%s  %s  %s  %s  %s  %d  %d %lf  %lf  %lf  %d  %d ",
					  last->username, last->phone, last->lastplaytime, last->identify, last->keeyworld,
					  &last->cardnum, &last->playfrequent, &last->palytime, &last->restfees, &last->allfees, &last->usertype,&last->isfreeze);
				last->isplay = 0;
			}
			else {
				perror("malloc:");
				printf("程序遇到错误，请您重新启动！！！\n");
			}
		}
		last->next = NULL;
		fclose(fp);
		fp = NULL;
	}
	else {
		perror("fopen:");
	}
	
}

void loaduserdate(void) 
{
     //备份哟用户数据
	{
		FILE* fp = NULL;
		if (fp = fopen("load.txt", "w")) {
			fprintf(fp, "%d %d %d\n", alluser, userid, adminiss);
			struct user* toload = head->next;
			while (toload) {
				fprintf(fp, "%s  %s  %s  %s  %s  %d  %d  %lf  %lf  %lf  %d  %d\n",
					toload->username, toload->phone, toload->lastplaytime, toload->identify, toload->keeyworld,
					toload->cardnum, toload->playfrequent, toload->palytime, toload->restfees, toload->allfees, toload->usertype,toload->isfreeze);
				toload = toload->next;
			}
			fclose(fp);
			fp = NULL;
		}
		else {
			perror("fopen:");
		}
	}
	
	//备份管理员的数据
	if (adminiss) {
		int adminisnum = adminiss;
		FILE* fp = NULL;
		if (fp=fopen("adminis.txt", "w")) {
			struct adminis* toadd = mainadministrator;
			while (adminisnum--) {
				toadd = toadd->before;
				fprintf(fp, "%s\n", toadd->permission);
				fprintf(fp, "%s\n", toadd->id);
				fprintf(fp, "%s\n", toadd->keeyword);
				fprintf(fp, "%s\n", toadd->quesone);
				fprintf(fp, "%s\n", toadd->questwo);
			}
			toadd->before = NULL;
			fclose(fp);
			fp = NULL;
		}
		else {
			perror("fopen");
		}
	}
}

