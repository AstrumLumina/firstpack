#define   _CRT_SECURE_NO_WARNINGS  1

#include"saolei.h"


//全局变量（用于记录游戏时间）
extern time_t start;
extern time_t mid;

//*************************************************************************************
//初始化制雷函数
void initialleiboard(char leiboard[WID][LEN], int  wid, int  len, int  lei)
{
	srand((unsigned)time(0));
	int x = 0;
	int y = 0;
	for (x = 0; x < wid; ++x) {
		for (y = 0; y < len; ++y) {
			leiboard[x][y] = ' ';
		}
	}
	while (lei) {
		x = rand() % wid;
		y = rand() % len;
		if (leiboard[x][y] - '0') {
			leiboard[x][y] = '0';
			--lei;
		}
	}
	for (x = 0; x < wid; ++x) {
		for (y = 0; y < len; ++y) {
			if (leiboard[x][y] == ' ') {
				leiboard[x][y] = countlei(leiboard, wid, len, x, y);
			}
		}
	}
}
//初始化打印棋盘函数
void initialprinboard(int prinboard[WID][LEN], int wid, int len)
{
	int i, j;
	for (i = 0; i < wid; ++i) {
		for (j = 0; j < len; ++j) {
			prinboard[i][j] = 0;
		}
	}
}
//查看剩余未知雷区数
int countrest(int prinboard[WID][LEN], int wid, int len) {
	int i, j;
	int count = 0;
	for (i = 0; i < wid; ++i) {
		for (j = 0; j < len; ++j) {
			if (!prinboard[i][j]) {
				++count;
			}
		}
	}
	return count;
}
//查看指定周围位置有几个雷的函数
char countlei(char leiboard[WID][LEN], int  wid, int  len, int x, int y)
{
	int count = 0;
	//左
	if (y - 1>=0) {
		if (leiboard[x][y-1] - '0'==0) {
			++count;
		}
	}
	//右
	if (y + 1 < len) {
		if (leiboard[x][y+1] - '0'==0) {
			++count;
		}
	}
	//上
	if (x - 1 >=0) {
		if (leiboard[x-1][y] - '0'==0) {
			++count;
		}
	}
	//下
	if (x + 1 < wid) {
		if (leiboard[x+1][y] - '0'==0) {
			++count;
		}
	}
	//右上
	if (y + 1 < len&&x-1>=0) {
		if (leiboard[x-1][y+1] - '0'==0) {
			++count;
		}
	}
	//右下
	if (y + 1 < len&&x+1<wid) {
		if (leiboard[x+1][y+1] - '0'==0) {
			++count;
		}
	}
	//左上
	if (y - 1 >=0&&x-1>=0) {
		if (leiboard[x-1][y-1] - '0'==0) {
			++count;
		}
	}
	//左下
	if (y - 1 >=0&&x+1<wid) {
		if (leiboard[x+1][y-1] - '0'==0) {
			++count;
		}
	}
	if (count) {
		return count+'0';
	}
	else {
		return ' ';
	}
}
//排雷结果状态记录更新函数  
void changeprinbosrd(char leiboard[WID][LEN], int prinboard[WID][LEN], int wid, int len, int x, int y)
{
	prinboard[x][y] = 1;
	if (leiboard[x][y] - ' ') {
		return;
	}
	else {
		//左
		if (y - 1 >= 0&&!prinboard[x][y-1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x, y - 1);
		}
		//右
		if (y + 1 < len && !prinboard[x][y + 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x, y + 1);
		}
		//上
		if (x - 1 >= 0 && !prinboard[x-1][y ]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y);
		}
		//下
		if (x + 1 < wid && !prinboard[x+1][y]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x + 1, y);
		}
		//右上
		if (y + 1 < len && x - 1 >= 0 && !prinboard[x-1][y + 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y + 1);
		}
		//右下
		if (y + 1 < len && x + 1 < wid && !prinboard[x+1][y + 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x + 1, y + 1);
		}
		//左上
		if (y - 1 >= 0 && x - 1 >= 0 && !prinboard[x-1][y - 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y - 1);
		}
		//左下
		if (y - 1 >= 0 && x + 1 < wid && !prinboard[x+1][y - 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x + 1, y - 1);
		}
	}
}
//雷盘打印函数
void printboard(char leiboard[WID][LEN], int prinboard[WID][LEN], int wid, int len, char leibiao,char panbiao,int lei)
{
	int i, j;
	int flag = 0;
	if (leibiao - ' ') {
		flag = 1;
	}
	//打印序号和方向
	for (j = 1; j <= len; ++j) {
		printf("%2d",j/10);
	}
	putchar('\n');
	for (j = 1; j <= len; ++j) {
		printf("%2d", j %10);
	}
	printf("----> X\n");
	//打印边框和内容
	for (j = 0; j < len; ++j) {
		printf("__");
	}
	printf("_\n");
	for (i = 0; i < wid; ++i) {
		putchar('|');
		for (j = 0; j < len-1; ++j) {
			if (flag) {
				if (prinboard[i][j]) {
					if (leiboard[i][j] - '0') {
						printf("%c ", leiboard[i][j]);
					}
					else {
						printf("%c ", leibiao);
					}
				}
				else {
					printf("%c ", panbiao);
				}
			}
			else {
				if (prinboard[i][j]) {
					printf("%c ", leiboard[i][j]);
				}
				else {
					printf("%c ", panbiao);
				}
			}
		}
		if (flag) {
			if (prinboard[i][j]) {
				if (leiboard[i][j] - '0') {
					printf("%c", leiboard[i][j]);
				}
				else {
					printf("%c", leibiao);
				}
			}
			else {
				printf("%c", panbiao);
			}
		}
		else {
			if (prinboard[i][j]) {
				printf("%c", leiboard[i][j]);
			}
			else {
				printf("%c", panbiao);
			}
		}
		printf(" |%-3d\n", i + 1);
	}
	printf("|");
	for (j = 0; j < len; ++j) {
		printf("--");
	}
	printf("|\n");
	//打印方向
	for (j = 0; j < len; ++j) {
		printf("  ");
	}
	printf("\\|/ Y\n");
	//打印时间和雷数
	time_t  end = time(NULL);
	printf("本局共有 %d 个雷       您上次排雷用时 %.3lf 秒;         您已总共排雷 %.0lf 秒;\n",lei,difftime(end,mid),difftime(end,start));
	mid = end;
}
//**********************************************************************

//设置相关函数*************************************************************************

//打印设置函数
void pirnset(int *wid,int *len,int *hard,int *lei,char *leibiao,char *panbiao)
{
	printf("********************   现  在  的  设  置  内  容   *******************************************\n");
	printf("1:低级难度玩法（长度: %d  宽度：%d  雷数：%d ）",*len,*wid,*lei);
	if (*hard == 0) { printf("( 这是现在的玩法)"); }
	putchar('\n');
	printf("2:中级难度玩法（长度: %d  宽度：%d  雷数：%d ）", *(len+1), *(wid+1), *(lei+1));
	if (*hard == 1) { printf("( 这是现在的玩法)"); }
	putchar('\n');
	printf("3:高级难度玩法（长度: %d  宽度：%d  雷数：%d ）", *(len + 2), *(wid + 2), *(lei + 2));
	if (*hard == 2) { printf("( 这是现在的玩法)"); }
	putchar('\n');
	printf("4:自定义难度玩法（长度: %d  宽度：%d  雷数：%d ）", *(len + 3), *(wid + 3), *(lei + 3));
	if (*hard == 3) { printf("( 这是现在的玩法)"); }
	putchar('\n');
	printf("5.现在雷的符号为：%c \n", *leibiao);
	printf("6.现在未知处的符号为：%c\n", *panbiao);
	printf("7.长的最大长度为 %d ,宽的最大长度为 %d (只可到源程序中修改宏）\n", LEN, WID);
	printf("*********************************************************************************\n\n");
	printf("按回车键退出查看\\>:");
	getchar();
	scanf("%*[^\n]%*c");
}
//保存设置函数
void beifenset(int wid, int len, int lei, int hard, char leibiao, char panbiao)
{
	FILE *fp = NULL;
	if ( fp = (fopen("set.txt", "w") ) ){
		fprintf(fp, "%d %d %d %d %c %c", wid, len, lei, hard, leibiao, panbiao);
		if (fclose(fp)) {
			printf("保存设置的文件关闭失败！！！\n");
		}
		fp = NULL;
		printf("备份完成!\n\n");
	}
	else {
		printf("保存设置的文件打开失败！！！\n");
		fp = NULL;
	}
}
//加载上次设置函数
void loadset(int* wid, int* len, int* lei, int* hard, char* leibiao, char* panbiao)
{
	FILE* fp = NULL;
	if (fp = (fopen("set.txt", "r"))) {
		fscanf(fp, "%d %d %d %d %c %c", wid, len, lei, hard, leibiao, panbiao);
		if (fclose(fp)) {
			printf("保存设置的文件关闭失败！！！\n");
		}
		fp = NULL;
		printf("加载完成!\n\n");
	}
	else {
		printf("保存设置的文件打开失败！！！\n\n\n");
		fp = NULL;
	}
}
//自定义玩法方案设置
void setmine(int* wid, int* len, int* lei)
{
	int option = 4;
	int input = 0;
	do {
		printf("\n\n*************************  自  定  义  选  项  **********************************************\n");
		printf("1:自定义雷区的宽   2：自定义雷区的长    3：自定义雷区中雷的个数     0:退出自定义方案设置\n\n");
		printf("*********************************************************************************************\n\n");
	laba1:
		printf("You option\\>:");
		option = 4;
		scanf(" %d", &option);
		scanf("%*[^\n]%*c");
		switch (option)
		{
		case 1:
		laba2:
			input = 0;
			printf("您想自定义雷区的宽为(必须大于1，且不大于 %d)：", WID);
			scanf(" %d", &input);
			scanf("%*[^\n]%*c");
			if (input <= 0 || input > WID) {
				printf("！！！不合法输入，请重新输入！！！\n\n");
				goto laba2;
			}
			*(wid + 3) = input;
			printf("友情提示：请及时更改自定义雷的个数，以防止出现雷的个数比雷区大的错误！！\n");
			break;
		case 2:
		laba3:
			input = 0;
			printf("您想自定义雷区的长为(必须大于1，且不大于 %d)：", LEN);
			scanf(" %d", &input);
			scanf("%*[^\n]%*c");
			if (input <= 0 || input > LEN) {
				printf("！！！不合法输入，请重新输入！！！\n\n");
				goto laba3;
			}
			*(len + 3) = input;
			printf("友情提示：请及时更改自定义雷的个数，以防止出现雷的个数比雷区大的错误！！\n");
			break;
		case 3:
		laba4:
			option = (*(wid + 3)) * (*(len + 3));//借用变量
			printf("您想自定义雷的个数为(必须大于1，且小于 %d)：", option);
			scanf(" %d", &input);
			scanf("%*[^\n]%*c");
			if (input <1 || input >= option) {
				printf("！！！不合法输入，请重新输入！！！\n\n");
				goto laba4;
			}
			*(lei + 3) = input;
			option = 1;//还原变量,防止为0时突然退出设置
			break;
		case 0:
			printf("退出自定义方案设置\n");
			break;
		default:
			printf("！！！不合法输入，请重新选择！！！\n\n");
			goto laba1;
		}
	} while (option);
}