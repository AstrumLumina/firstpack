#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"



void expensivemenu(void)
{
	printf("****************************************************************\n");
	printf("** 1.充值              2.办理会员            3.退费         ***\n");
	printf("**                     0.退出                               ***\n");
	printf("***************************************************************\n\n");
	printf("请输入您的选择\\>:");
}
enum expensivechoice {
	EXITEXPENAIVE, ADDEXPENSIVE,BEMEMBER, RETURNEXPENSIVE
};
void  expensivemanage(void)
{
	int option = 7;
	do {
		system("cls");
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
