#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"



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
	EXITCHARGE,FINDSTAND,ADDSTANGE,DELSTANGE,ENABLESTAND,SPECILASTAND,PERSONSSTAND
};
void chargestand(void)
{
	int option = 7;
	do {
		system("cls");
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