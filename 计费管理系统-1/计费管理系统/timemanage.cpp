#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"

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
	EXITTIME, START,END,ALLNIGHT,ADVACE,KILL,KILLALL
};
void timemanage(void)
{
	int option = 7;
	do {
		system("cls");
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
