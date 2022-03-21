#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"

void findmenu(void) {
	printf("******************************************************************************\n");
	printf("** 1.统计该月的收入             2.统计累计收入       3.统计分析用户数据    ***\n");
	printf("** 4.查看某一用户的使用数据     5.统计该天的营收     6.统计用户充值总数    ***\n");
	printf("**                              0.退出                                     ***\n");
	printf("******************************************************************************\n\n");
	printf("请输入您的选择\\>:");
}

enum cardmanage {
	MOTH=1,ALL,ANALYSE,ONEANALYSE,DAY,CHARGE
};
void find(void) {
	int option = 7;
	do {
		system("cls");
		findmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case 0:
			printf("退出 \n");
			break;
		case MOTH:
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
