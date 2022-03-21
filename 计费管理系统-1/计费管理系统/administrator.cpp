#define   _CRT_SECURE_NO_WARNINGS  1
#define  _CRT_SECURE_NO_DEPRECATE 1


#include"administrator.h"



extern  int  adminiss;
extern struct adminis* mainadministrator;
extern struct adminis* nowadministrator;
extern struct adminis* lastadministrator;
//extern char administrators[5][30];


void adminismenu(void)
{
	printf("\n\n注意: 越早添加的管理员权限越高，高级管理员可以删除低级管理元的账号,最多只能有5个管理员！！！\n\n");
	printf("***************************************************************************************\n");
	printf("** 1.新增管理员            2.删除管理员             3.更改其他管理员信息           ***\n");
	printf("** 4.修改当前管理员信息    5.设置管理员权限         6.查看或其他登录管理员账号     ***\n");
	printf("**                         0.退出                                                  ***\n");
	printf("**************************************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum adminichoice {
	EXITADMINIS,ADDADMINIS,DELADMINIS,CHANGADMINIS,MAINADMINIS,PERMISSION,SEEADMINIS
};
void administrator(void)
{
	int option = 7;
	do {
		system("cls");
		adminismenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITADMINIS:
			printf("退出 \n");
			break;
		case ADDADMINIS:
			printf("新增管理员  \n");
			addoneadminis();
			break;
		case DELADMINIS:
			printf("删除管理员   \n");
			deladminis();
			break;
		case  CHANGADMINIS:
			printf("更改其他管理员信息 \n");

			break;
		case  MAINADMINIS:
			printf("修改当前管理员信息 \n");

			break;
		case PERMISSION:
			printf("设置管理员权限\n");

			break;
		case  SEEADMINIS:
			printf("查看或其他登录管理员账号\n");
			changeadminis();
			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

//1:允许操作   0：验证失败
int  perrmission(void) {

	if (adminiss) {
		//管理员工身份选择
		if (nowadministrator==0) {
			printf("\n\n请登录你的管理员账号以验证身份\\>:\n\n");
			int move = -1;
			int max = 0;
			max = prinadminis(mainadministrator->before);
		labachoice:
			printf("请输入您要登录的账号（输入账号前的序号）\\>:");
			scanf("%d", &move);
			scanf("%*[^\n]%*c");
		    if (move > max || move < 1) {
				printf("不和法输入，请重新输入！！！\n");
				goto labachoice;
			}
			struct adminis* toverify = mainadministrator;
			while (move--) {
				toverify = toverify->before;
			}
			nowadministrator = toverify;
		}
		//密码验证
		
		char keey[21] = {};
		int errornum = 0;
	labeinputkeey:
		printf("请当前账号输入密码\\>:");
		getkeey(keey);
		system("cls");
		/*keey[0] = '\0';
		scanf("%s", keey);
		scanf("%*[^\n]%*c");*/
		if (strcmp(nowadministrator->keeyword, keey) == 0) {
			//nowadministrator = toverify;
			return 1;
		}
		else {
			++errornum;
			printf("密码错误，请重新输入！！！\n\n");
			if (errornum ==4) {
				printf("\n您的错误次数过多，为保证安全已退出\n\n\n");
				//nowadministrator = NULL;
				return 0;
			}
			goto labeinputkeey;
		}
		
	}
	else {
		return 1;
	}
}

void firstaddadminid(void) {
	//初始化管理员数据
	nowadministrator = NULL;
	if (mainadministrator =(struct adminis*) malloc(sizeof(struct adminis))) {
		lastadministrator = mainadministrator;
		mainadministrator->before=NULL;
		if (adminiss>0) {
			FILE* fp = NULL;
			if (fp=fopen("adminis.txt", "r")) {
				int a = adminiss;
				struct adminis* toadd = mainadministrator;
				while (a--) {
					if (toadd->before = (struct adminis*)malloc(sizeof(struct adminis))) {
						toadd = toadd->before;
						//fgets(toadd->permission, 25, fp);//会把换行符一并读取到字符串中
						//fgets(toadd->id, 25, fp);
						//fgets(toadd->keeyword, 25, fp);
						//fgets(toadd->quesone, 25, fp);
						//fgets(toadd->questwo, 25, fp);
						fscanf(fp, "%s", toadd->permission);
						fscanf(fp, "%s", toadd->id);
						fscanf(fp, "%s", toadd->keeyword);
						fscanf(fp, "%s", toadd->quesone);
						fscanf(fp, "%s", toadd->questwo);
					}
					else {
						perror("malloc:");
					}
				}
				lastadministrator = toadd;
				toadd->before = NULL;
				fclose(fp);
				fp = NULL;
				//验证管理员身份
				cangoahead();
			/*labaverifyagain:
				a=perrmission();
				if (a == 0) {
					printf("登录失败！！！！\n\n");
					printf("是否退出（0：否  其他：是）\\>:");
					a = 1;
					scanf("%d", &a);
					scanf("%[^\n]%*c");
					if (a) {
						exit(0);
					}
					else {
						nowadministrator = NULL;
						goto labaverifyagain;
					}
				}*/
			}
			else {
				perror("fopen");
			}
			return;
		//检测是否是初次使用
		}else if(adminiss==0) {
			return;
		}
		//初次使用才会运行到此步
		{
			printf("系统检测到这是您初次使用该系统，请问是否添加管理员来保障系统的安全（0:否  其他选择：是）\\>:");
			adminiss = 0;
			int choice = 1;
			scanf("%d", &choice);
			scanf("%*[^\n]%*c");
			if (choice) {
				//添加管理员
				addoneadminis();//此函数已经使adminiss++
				//adminiss = 1;
				nowadministrator = lastadministrator;
			}
			else {
				printf("\n\n      欢迎进入使用  计费管理系统  \n\n\n");
			}
		}
	}
	else {
		perror("malloc:");
	}
	

	////检测是否是初次使用
	//if (adminiss-(-1) ){
	//	return ;
	//}
	//printf("系统检测到这是您初次使用该系统，请问是否添加管理员来保障系统的安全（0:否  其他选择：是）\\>:");
	//int choice = 1;
	//scanf("%d", &choice);
	//scanf("%*[^\n]%*c");
	//if (choice) {
	//	//添加管理员


	//	adminiss = 1;
	//}
	//else {
	//	adminiss = 0;
	//}
}
int   prinadminis(struct adminis*firsttoprin) {
	system("cls");
	printf("\n\n***************  管  理   员  账  号  **************\n");
	int num = 0;
	while (firsttoprin) {
		printf(" %d : %s\n", ++num, firsttoprin->id);
		firsttoprin = firsttoprin->before;
	}
	return num;
}

//添加管理员
void addoneadminis(void) {
	int choice = -1;
	char id[15]={};
	int  idoready = 0;
	char keeyword[20]={};
	int  keeyoready = 0;
	char questionone[20]="F";
	int  quesoready = 0;
	char questwo[20]="F";
	int  questwooready = 0;
labastart:
	system("cls");
	//打印菜单
	{
		printf("添加管理员\\>:\n");
		printf("\n*************************************************************\n");
		printf("**     1：设置账号                2：设置密码              ***\n");
		printf("**     3: 安全问题1               4：安全问题2             ***\n");
		printf("**     5：保存退出                0:返回（取消添加管理员） ***\n");
		printf("**************************************************************\n");
	}
labainput:
	printf("请输入您的选择\\>:");
	choice = -1;
	scanf("%d", &choice);
	scanf("%*[^\n]%*c");
	switch (choice) {
	case 1:
		printf("设置账号  \n");
		while(1) {
			printf("请输入账号名称(不得多余 14 个字符\\>:");
			scanf("%s", id);
			scanf("%*[^\n]%*c");
			//检查账号是否合理
			{
				if (strlen(id) > 14) {
					printf("输入不和法，请重新输入!!!\n\n");
				}
				else {
					struct adminis* toverify = mainadministrator->before;
					while (toverify) {
						if (0 == strcmp(toverify->id, id)) {
							printf("输入不和法(由于某些原因该账号暂时不可用，还请谅解），请重新输入!!!\n\n");
							goto labastart;
						}
						toverify = toverify->before;
					}
					idoready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 2:
		printf("设置密码\n");
		{
			while (1) {
				printf("请输入密码(不得多余 19 个字符\\>:");
				scanf("%s", keeyword);
				scanf("%*[^\n]%*c");
				if (strlen(keeyword) > 19 ) {
					printf("输入不和法，请重新输入!!!\n\n");
				}
				else {
					keeyoready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 3:
		printf("安全问题1  \n");
		{
			printf("问题1 : 你的第一只宠物是什么?\n");
			while (1) {
				printf("请输入你的答案(切勿输入中文，不得多余 19 个字符)\\>:");
				scanf("%s", questionone);
				scanf("%*[^\n]%*c");
				if (strlen(questionone) > 19) {
					printf("输入不和法，请重新输入!!!\n");
				}
				else {
					quesoready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 4:
		printf("安全问题2  \n");
		{
			printf("问题2 : 你小时后的外号是是什么?\n");
			while (1) {
				printf("请输入你的答案(切勿输入中文，不得多余 19 个字符)\\>:");
				scanf("%s", questwo);
				scanf("%*[^\n]%*c");
				if (strlen(questwo) > 19) {
					printf("输入不和法，请重新输入!!!\n");
				}
				else {
					questwooready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 5:
		printf("保存退出   \n");
		{
			if (idoready && keeyoready) {
				//检查
				if (quesoready +questwooready==1) {
					printf("安全问题必须同时设置，不可只设置一个（其他: 返回设置安全问题    0: 取消设置安全问题继续保存）\\>:");
					int cancel = 1;
					scanf("%d", &cancel);
					scanf("%*[^\n]%*c");
					if (cancel) {
						goto labastart;
					}
					else {
						strcpy(questionone, "F");
						strcpy(questwo, "F");
						//questionone[0] = '\0';
						//questwo[0] = '\0';
					}
				}
				else if(quesoready + questwooready == 0) {
					printf("系统检测到您还为设置安全问题，是否设置安全问题以防忘记密码（0：否  其他选择：是）\\>:");
					int addquestion = 1;
					scanf("%d", &addquestion);
					scanf("%*[^\n]%*c");
					if (addquestion) {
						goto labastart;
					}
				}
				//保存
				if (lastadministrator->before=(struct adminis*)malloc(sizeof(struct adminis))) {
					lastadministrator = lastadministrator->before;
					lastadministrator->before = NULL;
					++adminiss;

					strcpy(lastadministrator->id, id);
					strcpy(lastadministrator->permission, "F");
					strcpy(lastadministrator->keeyword, keeyword);
					strcpy(lastadministrator->quesone, questionone);
					strcpy(lastadministrator->questwo, questwo);
					
					printf("添加管理员成功!\n");
				}
				else {
					perror("malloc:");
				}

			}
			else {
				printf("请先填写完整必要的信息！！！\n\n");
				goto labastart;
			}
		}

		break;
	case 0:
		printf("返回（取消添加管理员）\n");
		break;
	default:
		printf("不合法输入，请重新输入！！！  \n");
		goto  labainput;
	}
	
}

void cangoahead(void)
{
	int a = 0;
labaverifyagain:
	a = perrmission();
	if (a == 0) {
		printf("登录失败！！！！\n\n");
		printf("是否退出（0：否  其他：是）\\>:");
		a = 1;
		scanf("%d", &a);
		scanf("%*[^\n]%*c");
		if (a) {
			exit(0);
		}
		else {
			nowadministrator = NULL;
			goto labaverifyagain;
		}
	}
}

void getkeey(char keey[]) {
	int i = 0;
	scanf("%*[^\n]%*c");
	while ((keey[i] = _getch() )-'\r') {
		++i;
		putchar('*');
	}
	keey[i] = '\0';
	putchar('\n');
}

void changeadminis(void)
{
	int choice = -1;
	do {
		printf("\n选择菜单\\>:\n");
		printf("1:查看其他管理员的账号          2，登录其他管理员账号       0；退出\n");
		printf("请输入您的选择\\>:");
		choice = -1;
		scanf("%d", &choice);
		scanf("%*[^\n]%*c");
		if (choice == 1) {
			prinadminis(mainadministrator->before);
		}
		else if (choice == 2) {
			printf("\n为了保障安全，需要确认您的身份!!!!!\n\n");
			if (canchange()) {
				nowadministrator = NULL;
				printf("成功退出登录\n\n");
				cangoahead();
				printf("重新登录成功\n\n按任意键继续\\>:");
				getchar();
				scanf("%*[^\n]%**c");
				return;
			}
		}
		else {
			printf("不合法输入，请重新输入!!!\n");
		}
	} while (choice);
}

int canchange(void) 
{
	int a = 0;
labaverifyagain:
	a = perrmission();
	if (a) return 1;
	{
		printf("身份验证失败失败！！！！\n\n");
		printf("是否退出（0：否  其他：是）\\>:");
		a = 1;
		scanf("%d", &a);
		scanf("%*[^\n]%*c");
		if (a) {
			printf("继续使用当前帐号！！！\n");
			return 0;
		}
		else {
			goto labaverifyagain;
		}
	}
}

void deladminis(void) {
	printf("\n为了保障安全，需要确认您的身份已退出当前账号!!\n\n");
	if (canchange()) {
		printf("一下为您有权限操作的管理员账户\\>:\n");
		int max=prinadminis(nowadministrator);
		int move = -1;
		//********************************************
	labachoice:
		printf("请输入您删除的账号（输入账号前的序号）\\>:");
		move = -1;
		scanf("%d", &move);
		scanf("%*[^\n]%*c");
		if (move > max || move < 1) {
			printf("不和法输入，请重新输入！！！\n");
			goto labachoice;
		}
		struct adminis* toverify = nowadministrator;
		if (move == 1) {
			toverify = mainadministrator;
			while (toverify->before!=nowadministrator) {
				toverify = toverify->before;
			}
		}
		else {
			--move;
			while (--move) {
				toverify = toverify->before;
			}
		}
		deloneadminis(toverify);
	}
	else {
		printf("\n身份验证失败，已退出！！！\n\n");
	}
}

void deloneadminis(struct adminis* beforetodel) {
	if (beforetodel->before->before == NULL) {
		lastadministrator = beforetodel;
	}
	struct adminis* todel = beforetodel->before;
	beforetodel->before = (beforetodel->before)->before;
	free(todel);
	--adminiss;
	printf("注销成功！\n");
}