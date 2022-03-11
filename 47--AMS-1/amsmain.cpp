#define   _CRT_SECURE_NO_WARNINGS  1

#include"amsmain.h"


//主函数*********************************************************
enum mainchoice {
	MEXIT, CARDMANAGE, CHARGESTAND, TIME, EXPENSEMANAGE, FIND, ACTIVE, ADMINISTRATOR
};
int main(void) {

	int option = 9;
	do {
		mainmenu();
		option = 9;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case MEXIT:
			printf("退出 \n");
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
	} while (option);

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

//功能1  1.卡管理  ****************************************************
void cardmenu(void) {
	printf("*********************************************************************\n");
	printf("** 1.添加卡             2.查询卡               3.注销卡           ***\n");
	printf("** 4.冻结卡                                    0.退出             ***\n");
	printf("**********************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum cardmanage {
	EXITCARD, ADDCARD, INQUIRYCARD, DELCARD, FREEZECARD
};
void cardaccountmanage(void) {
	int option = 7;
	do {
		cardmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITCARD:
			printf("退出 \n");
			break;
		case ADDCARD:
			printf("添加卡 \n");

			break;
		case INQUIRYCARD:
			printf("查询卡 \n");

			break;
		case DELCARD:
			printf("注销卡\n");

			break;
		case FREEZECARD:
			printf("冻结卡 \n");

			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}


//功能2  2.计费标准管理 ****************************************************
void chargestandmenu(void)
{
	printf("**********************************************************************************\n");
	printf("** 1.查询全部计费标准              2.新增计费标准             3.删除标准       ***\n");
	printf("** 4.选择并启用标准（对所有人）    5.对某人实行特殊标准       6.查询某人的标准 ***\n");
	printf("**                                 0.退出                                      ***\n");
	printf("**********************************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum chargechoice {
	EXITCHARGE, FINDSTAND, ADDSTANGE, DELSTANGE, ENABLESTAND, SPECILASTAND, PERSONSSTAND
};
void chargestand(void)
{
	int option = 7;
	do {
		chargestandmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITCHARGE:
			printf("退出 \n");
			break;
		case FINDSTAND:
			printf("查询全部计费标准  \n");

			break;
		case ADDSTANGE:
			printf("新增计费标准 \n");

			break;
		case DELSTANGE:
			printf("选择并启用标准（对所有人）\n");

			break;
		case SPECILASTAND:
			printf("对某人实行特殊标准 \n");

			break;
		case PERSONSSTAND:
			printf("查询某人的标准\n");

			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}


//功能3  3.上下机管理 ****************************************************
void timemanagemenu(void)
{
	printf("**************************************************************\n");
	printf("** 1.普通上机              2.下机          3.包夜          ***\n");
	printf("** 4.高级包厢              5.强制下机      6.全部强制下机  ***\n");
	printf("**                         0.退出                          ***\n");
	printf("**************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum timechoice {
	EXITTIME, START, END, ALLNIGHT, ADVACE, KILL, KILLALL
};
void timemanage(void)
{
	int option = 7;
	do {
		timemanagemenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITTIME:
			printf("退出 \n");
			break;
		case START:
			printf("开始上机 \n");

			break;
		case END:
			printf("下机 \n");

			break;
		case ALLNIGHT:
			printf("包夜 \n");

			break;
		case ADVACE:
			printf(".高级包厢  \n");

			break;
		case KILL:
			printf("强制下机 \n");

			break;
		case KILLALL:
			printf("全部强制下机 \n");

			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);

}

//功能4   4.费用管理****************************************************
void expensivemenu(void)
{
	printf("****************************************************************\n");
	printf("** 1.充值              2.办理会员            3.退费         ***\n");
	printf("**                     0.退出                               ***\n");
	printf("***************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum expensivechoice {
	EXITEXPENAIVE, ADDEXPENSIVE, BEMEMBER, RETURNEXPENSIVE
};
void  expensivemanage(void)
{
	int option = 7;
	do {
		expensivemenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITEXPENAIVE:
			printf("退出 \n");
			break;
		case ADDEXPENSIVE:
			printf("充值  \n");

			break;
		case BEMEMBER:
			printf("办理会员 \n");

			break;
		case  RETURNEXPENSIVE:
			printf("退费\n");

			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);

}

//功能5  5.查询统计 ****************************************************
void findmenu(void) {
	printf("******************************************************************************\n");
	printf("** 1.统计该月的收入             2.统计累计收入       3.统计分析用户数据    ***\n");
	printf("** 4.查看某一用户的使用数据     5.统计该天的营收     6.统计用户充值总数    ***\n");
	printf("**                              0.退出                                     ***\n");
	printf("******************************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum fincardmanage {
	MONTH=1 , ALL, ANALYSE, ONEANALYSE, DAY, CHARGE
};
void find(void) {
	int option = 7;
	do {
		findmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case 0:
			printf("退出 \n");
			break;
		case MONTH:
			printf("统计该月的收入 \n");

			break;
		case ALL:
			printf("统计累计收入 \n");

			break;
		case ANALYSE:
			printf("统计分析用户数据\n");

			break;
		case ONEANALYSE:
			printf("查看某一用户的使用数据  \n");

			break;
		case DAY:
			printf("统计该天的营收 \n");

			break;
		case CHARGE:
			printf("统计用户充值总数 \n");

			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

//功能6   6.活动管理    ****************************************************
void active(void) {
	printf("该功能暂未开饭，请您谅解！\n");
}


//功能7  7.管理员管理  ********************************************************
void adminismenu(void)
{

	printf("*********************************************************************************\n");
	printf("** 1.新增管理员            2.删除管理员             3.更改普通管理员信息      ***\n");
	printf("** 4.修改主管理员信息      5.设置管理员权限         6.查询管理员              ***\n");
	printf("**                                 0.退出                                     ***\n");
	printf("**********************************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum adminichoice {
	EXITADMINIS, ADDADMINIS, DELADMINIS, CHANGADMINIS, MAINADMINIS, PERMISSION, SEEADMINIS
};
void administrator(void)
{
	int option = 7;
	do {
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

			break;
		case DELADMINIS:
			printf("删除管理员   \n");

			break;
		case  CHANGADMINIS:
			printf("更改普通管理员信息\n");

			break;

		case  MAINADMINIS:
			printf("修改主管理员信息 \n");

			break;
		case PERMISSION:
			printf("设置管理员权限\n");

			break;
		case  SEEADMINIS:
			printf("查询管理员\n");

			break;
		default:
			printf("不合法输入，请重新输入！！！\n");
			printf("输入任意字符继续：");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

