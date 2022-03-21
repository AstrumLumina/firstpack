#define   _CRT_SECURE_NO_WARNINGS  1


#include"cardmanage.h"



//全局变量
extern struct user* head;
extern struct user* last;
extern int alluser;
extern int usersize;
extern int userid;

void cardmenu(void) {
	printf("注意：该系统能添加的卡不超过 int所能表示的大小，且由于某些原因，能存储的卡的数量会减少 \n");
	printf("**********************************************************************\n");
	printf("** 1.添加卡             2.查询卡              3.注销卡             ***\n");
	printf("** 4.冻结或解冻卡       5.卡密码管理          6.查看已添加对全部卡 ***\n");
	printf("**                      0.退出                                     ***\n");
	printf("**********************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum cardmanage {
	EXITCARD,ADDCARD,INQUIRYCARD,DELCARD,FREEZECARD,CHANGEKEEY,PRINALL
};
void cardaccountmanage(void) {

	int option = -1;
	do {
		system("cls");
		cardmenu();
		option = -1;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITCARD:
			printf("退出 \n");
			break;
		case ADDCARD:
			printf("添加卡 \n");
			addcard();
			break;
		case INQUIRYCARD:
			printf("查询卡 \n");
			findcard();
			break;
		case DELCARD:
			printf("注销卡\n");
			printf("出于安全考虑，该功能需要管理员权限，请您输入密码以验证身份\n");
			//权限查看
			if (perrmission()) {
				//删除卡
				deletcard();
			}else{
				printf("身份验证失败！！！\n\n");
			}
			break;
		case FREEZECARD:
			printf("冻结或解冻卡 \n");
			freezecard();
			break;
		case CHANGEKEEY:
			printf("5.卡密码管理   \n");
			printf("出于安全考虑，该功能需要管理员权限，请您输入密码以验证身份\n");
			//权限查看
			if (perrmission()) {
				//删除卡
				changekeey();
			}
			else {
				printf("身份验证失败！！！\n\n");
			}
			break;
		case PRINALL:
			printf("查看已添加对全部卡 \n");
			prinallcard();
			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

void addcard(void)
{
	char name[15];
	char phone[15];
	char identify[20];
	int option = 5;
	int flagname = 0;
	int flagid = 0;
	int flagphone = 0;
labainput:
	system("cls");
	printf("办卡时我们需要您的部分信息，请您如实填写\\>\n");
	printf("************************************************************\n");
	printf("**   1.姓名             2.电话             3.身份证号码  ***\n");
	printf("**   4.保存并退出       0：返回（不保存）                ***\n\n");
	printf("************************************************************\n");
	printf("请输入您的选择\\>:");
	option = 5;
	scanf("%d", &option);
	scanf("%*[^\n]%*c");
	switch (option) {
	case 1:
		printf("请输入您的姓名\\>:");
		scanf("%s", name);
		flagname = 1;
		scanf("%*[^\n]%*c");
		goto labainput;
		//break;
	case 2:
		printf("请输入您的电话\\>:");
		scanf("%s", phone);
		flagphone = 1;
		scanf("%*[^\n]%*c");
		goto labainput;
		//break;
	case 3:
		printf("请输入您的身份证号码\\>:");
		scanf("%s", identify);
		flagid = 1;
		scanf("%*[^\n]%*c");
		{
			int old = (identify[6]-'0') * 1000 + (identify[7] - '0') * 100 + (identify[8] - '0') * 10 + (identify[9] - '0');
			if (NOWYEAR - old < 18) {
				printf("您还未成年，未达到开卡的要求！！！\n");
				printf("请按任意键继续\\>:");
				getchar();
				scanf("%*[^\n]%*c");
				return;
			}
		}
		goto labainput;
		//break;
	case 4:
		printf("保存退出\n");
		if (flagname && flagid && flagphone) {
			initialcard(name, phone, identify);
		}
		else {
			printf("请您先输入完整的信息！！！\n");
			printf("请按任意键继续\\>:");
			getchar();
			scanf("%*[^\n]%*c");
			goto labainput;
		}
		break;
	case 0:
		printf("返回退出(取消添加卡）\n");
		break;
	default:
		printf("不和法输入，请您重新输入！！！\n\n");
		goto labainput;
	}
	
}

void  initialcard(char* name, char* phone, char* identifyid)
{
	
		char keeyword[20] = "";
	labekeeyword:
		printf("请您为您的卡设置密码(大于5个字符，小于19个字符）\\>;");
		scanf("%s", keeyword);
		scanf("%*[^\n]%*c");
		int len = strlen(keeyword);
		if (len > 18 || len < 6) {
			 printf("\n您的密码不符合要求，请重新输入!!!\n\n");
			goto labekeeyword;	
		}
		//系统分配卡号：
		++userid;
		++alluser;
		printf("\n恭喜您开卡成功，您的卡号为: %06d\n\n", userid);
		printf("请您牢记自己的卡号！！！,按任意键可继续\n");
		getchar();
		scanf("%*[^\n]%*c");
		//存储卡
		if (last->next = (struct user*)malloc(usersize)) {
			last = last->next;
			last->next = NULL;
			strcpy(last->username, name);
			strcpy(last->phone, phone);
			strcpy(last->identify, identifyid);
			strcpy(last->keeyworld, keeyword);
			last->cardnum = userid;
			last->lastplaytime[0]='F';
			last->lastplaytime[1] = '\0';
			last->playfrequent = 0;
			last->palytime = .0;
			last->restfees = .0;
			last->allfees = .0;
			last->usertype = 2;
			last->isplay = 0;
			last->isfreeze = 0;
			printf("信息录入成功,您现在可以使用这张卡上机了\n");

	    }
	    else {
		    printf("内存申请失败，请您重新启动程序！！！\n");
	    }
}

//删除函数
void deletcard(void) 
{
	
	int cardtodel = 0;
	printf("请输入要删除的卡号(若忘记卡号，可 输入0 返回 后用身份证号查找找卡号）\\>:");
	scanf("%d", &cardtodel);
	scanf("%*[^\n]%*c");
	if (cardtodel==0) {
		printf("返回");
		return;
	}
	struct user* todel = head;
	//struct user* beforedel = head;
	while (todel->next) {
		//beforedel = todel;
		if ((todel->next)->cardnum == cardtodel) {
			break;
		}
		todel = todel->next;
	}
	if (todel->next) {
		printf("\n请您确保在注销前已经做好了退费等工作，此卡一旦注销，数据无法恢复\n\n");
		char keey[20];
		int errornum = 0;
	labainputkeey:
		printf("为了保证安全，请您输入该卡号的密码(密码错误四次自动退出）\\>:");
		scanf("%s", keey);
		scanf("%*[^\n]%*c");
		if (0 == strcmp(keey, (todel->next)->keeyworld)) {
			realdelonecard(todel);
		}
		else {
			++errornum;
			if (errornum % 4) {
				printf("密码错误，您还有  %d  次机会  **********\n\n", 4 - errornum);
				goto labainputkeey;
			}
			printf("\n\n\n错误次数过多，为保障用户安全以自动退出\n\n");
		}
	}
	else {
		printf("不存在该卡号！！！\n");
	}
}

void realdelonecard(struct user* beforetodel) {
	if (beforetodel->next->next==NULL) {
		last = beforetodel;
	}
	struct user* todel = beforetodel->next;
	beforetodel->next = (beforetodel->next)->next;
	free(todel);
	--alluser;
	printf("注销成功！\n");
}
void findcard(void) {
	struct user* beforefind = NULL;
	int input = -1;
	//选择菜单
labamenu:
	system("cls");
	{
		printf("\n*****************************************************************\n");
		printf("***  1.按卡号查询卡                      2.按身份证查询卡     ****\n");
		printf("***  3.按名字查询卡                      4.查看全部卡         ****\n");
		printf("***                        0.返回                             ****\n");
		printf("******************************************************************\n");
	}
labainput:
	printf("请输入您的选择\\>:");
	input = -1;
	scanf("%d", &input);
	scanf("%*[^\n]%*c");
	switch (input){
	case 1:
		printf("1.按卡号查询卡 \n");
		beforefind = findbynum();
		break;
	case 2:
		printf(" 2.按身份证查询卡\n");
		beforefind = findbyidentify();
		break;
	case 3:
		printf("3.按名字查询卡 \n");
		beforefind = findbyname();
		break;
	case 4:
		printf("4.查看全部卡 \n");
		prinallcard();
		goto labamenu;
		break;
	case 0:
		printf(" 0.返回 \n");
		break;
	default:
		printf("不和法输入，请重新输入!!!\n");
		goto labainput;
	}
	//判断并打印结果
	if(input) {
		if (beforefind) {
			system("cls");
			putchar('\n');
			printf("1:活跃用户|2：新用户|3：老用户|4：不活跃用户|5：正常用户|1;正常上机|2；包夜|3；高级包厢|4.活动上机|1.被冻结 \n");
			printf(" 卡号    用户名       电话        用户类型|使用次数|是否在上机| 上次使用    |是否被冻结|累计使用时长  累计充值    余额 \n");
			prinonecard(beforefind);
			int choice = 1;
			printf(" 更多操作 （  0: 退出查看     其他：查看更多信息 ）\\>:");
			scanf("%d", &choice);
			scanf("%*[^\n]%*c");
			if (choice) {
				//打印日志记录和身份证号

				//暂停
				{
					printf("按任意键退出查看\\>:");
					getchar();
					scanf("%*[^\n]%*c");
				}
			}
		}
		else {
			printf("不合法输入或不存在您要查找的内容!!!\n");
			printf("按任意键继续\\>:");
			getchar();
			scanf("%*[^\n]%*c");
		}
	}
}


struct user* findbynum(void) {
	int cardnum = -1;
	printf("请输入卡号( 6 位数 ,不和规定的输入可能导致错误）\\>:");
	scanf("%d", &cardnum);
	scanf("%*[^\n]%*c");
	if (cardnum < 1) {
		//printf("不合法输入！！！\n");
		return NULL;
	}
	struct user* toverify = head;
	//struct user* before = head;
	while (toverify->next) {
		if (toverify->next->cardnum == cardnum) {
			return toverify;
		}
		//before = toverify;
		toverify = toverify->next;
	}
	//if (toverify->cardnum == cardnum) {
	//	return before;
	//}
	return NULL;
}
struct user* findbyidentify(void) {
	char identify[20] = {};
	printf("请输身份证号码:\\>:");
	scanf("%s", identify);
	scanf("%*[^\n]%*c");

	struct user* toverify = head;
	//struct user* before=head;
	while (toverify->next) {
		if (strcmp(toverify->next->identify, identify) == 0) {
			return toverify;
		}
		//before = toverify;
		toverify = toverify->next;
	}
	//if (strcmp(toverify->identify, identify) == 0) {
		//return before;
	//}
	return NULL;
}
struct user* findbyname(void) {
	char identify[20] = {};
	printf("请输入用户名\\>:");
	scanf("%s", identify);
	scanf("%*[^\n]%*c");

	struct user* toverify = head;
	//struct user* before=head;
	while (toverify->next) {
		if (strcmp(toverify->next->username, identify) == 0) {
			return toverify;
		}
		//before = toverify;
		toverify = toverify->next;
	}
	//if (strcmp(toverify->username, identify) == 0) {
	//	return before;
	//}
	return NULL;
}

void prinallcard(void) {
	system("cls");
	putchar('\n');
	printf("1:活跃用户|2：新用户|3：老用户|4：不活跃用户|5：正常用户|1;正常上机|2；包夜|3；高级包厢|4.活动上机|1.被冻结 \n");
	printf(" 卡号    用户名       电话        用户类型|使用次数|是否在上机| 上次使用    |是否被冻结|累计使用时长  累计充值    余额 \n");
	struct user* beforprin = head;
	while (beforprin->next) {
		prinonecard(beforprin);
		beforprin = beforprin->next;
	}
	printf("按任意键退出查看\\>:");
	getchar();
	scanf("%*[^\n]%*c");
}
void prinonecard(struct user* toprin)
{
	toprin = toprin->next;
	printf(" %06d  %-11s  %-13s  %-6d  %-7d  %-7d    %-18s %-3d %-12lf  %-12lf  %-12lf\n",toprin->cardnum,toprin->username,
		toprin->phone, toprin->usertype,toprin->playfrequent, toprin->isplay, toprin->lastplaytime, toprin->isfreeze,toprin->palytime,toprin->allfees, toprin->restfees);
}

void freezecard(void) {
	printf("\n提示：该操作需要您要操作的卡号（若不知道可返回查询）\\>:\n\n");
	struct user* tofreeze = findbynum();
	if (tofreeze) {
		tofreeze = tofreeze->next;
		int choice = 1;
		if (tofreeze->isfreeze) {
			printf("是否确定解冻该卡(0:否  其他：是）\\>:");
		}
		else {
			printf("是否确定冻结该卡(0:否  其他：是）\\>:");
		}
		scanf("%d", &choice);
		scanf("%*[^\n]%*c");
		if (choice) {
			tofreeze->isfreeze = !(tofreeze->isfreeze);
			printf("操作成功！\n");
		}
		else {
			printf("已取消操作！\n");
		}
	}
	else {
		printf("不存在该卡号!!!\n");
		
	}

}
void changekeey(void) {
	int input = -1;
	struct user* tochangekeey = NULL; 
	printf("\n\n选择\\>:\n");
	printf(" 1: 查看卡密码     2：更改卡密码      其他：返回");
	scanf("%d", &input);
	scanf("%*[^\n]%*c");
	if (input == 1) {
		tochangekeey = findbyidentify();
		if (tochangekeey) {
			printf("\n该卡的密码为\\>: %s \n", tochangekeey->next->keeyworld);
			printf("按任意键退出查看\\>:");
			getchar();
			scanf("%*[^\n]%*c");
		}
	}
	else if (input == 2) {
		tochangekeey = findbyidentify();
		if (tochangekeey) {
			tochangekeey = tochangekeey->next;
			char keey[21] = "";
		labainputkeey:
			printf("请输入新密码\\>:");
			scanf("%s", keey);
			scanf("%*[^\n]%*c");
			if (strlen(keey) > 20) {
				printf("输入密码不和规定（过长）,请重新输入!!!\n");
				goto labainputkeey;
			}
			strcpy(tochangekeey->keeyworld, keey);
			printf("更改密码成功！！！！\n");
		}
	}
	else {
		printf("返回\\>\n");
		return;
	}
	printf("未找到该信息，请你确认信息是否有错误！！！\n");
	return;
}