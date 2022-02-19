#define   _CRT_SECURE_NO_WARNINGS  1

#include"saolei.h"


//全局变量（用于记录游戏时间）
time_t start;
time_t mid;

int main(void)
{
	//游戏和一些注意事项介绍*******************
	printf("  //这是一个扫雷游戏，您可以选择系统自带方案进行游戏，也可以自定义游戏方案，但雷区大小不能超过 最大值（可在源程序中更改宏）\n");
	printf(" //若您为为设置过自定义方案，则自定义方案为系统默认方案\n");
	printf("//本程序对于不合法输入，则按输入顺序自动将前面连续合规的输入作为输入,否则输入无效\n\n");
	//*******************************************************
	int input = 3;
	int hard = HARD;
	int len[4] = INITIALLEN
	int wid[4] = INITIALWID
	int lei[4] = LEI
	char leibiao = LEIBIAO;
	char panbiao = PANBIAO;
	do {
		menu();
		printf("\n请输入你的选择\\>:");
		input = 3;
		scanf("%d", &input);
		scanf("%*[^\n]%*c");
		switch (input) {
		case 1:
			printf("开始游戏\\>:\n");
			if (ispropre(wid[hard], len[hard], lei[hard],leibiao,panbiao)) {
				start = time(NULL);
				mid = time(NULL);
				game(wid[hard], len[hard], lei[hard], leibiao, panbiao);
			}
			else {
				printf("\t!!!游戏数据有问题!!（可能原因：1：雷的个数超过了雷区的格子数 2：雷区的长，宽超过了限制n 3.打印的符号不合理或冲突 ）\n");
				printf("\t友情提示：以上问题的深层原因可能是由于更改系统自带玩法的宏定义不合理导致或者是自定义方案设置不正确.\n");
				printf("\t          雷区的长和宽的最大值必须要到源代码里更改宏才能改变\n\n");	
				printf("按回车键退出\\>:");
				getchar();
				scanf("%*[^\n]%*c");
			}
			break;
		case 0:
			printf("退出游戏！！\n");
			input = 0;
			break;
		case 2:
			printf("设置\n");
			set(wid, len , lei , &hard,&leibiao,&panbiao);
			break;
		default:
			printf("不合法输入！！！ 请重新输入！！！\n\n");
			break;
		}
	} while (input);
	return 0;
}
//打印主菜单函数
void menu()
{
	printf("\n\n\n");
	printf("**********  选  择  菜  单  *******************\n");
	printf("* 1:进入游戏        2：设置       0：退出游戏 *\n\n");
	printf("***********************************************\n");
}
//游戏集成函数
void game(int wid, int len, int lei,char leibiao,char panbiao)
{
	char leiboard[WID][LEN];
	int  prinboard[WID][LEN];
	int x = 0;
	int y = 0;
	initialleiboard(leiboard, wid, len, lei);
	initialprinboard(prinboard, wid, len);
	printboard(leiboard,prinboard, wid, len,leibiao,panbiao,lei);
	int changeresult = 1;
	do{
		char ch = 0;
	laba1:
		x = 0;
		y = 0;
		ch = 0;
		printf("(若您想将此处标记为雷 请输入坐标再加小写英文字符'y'再按回车,若想取消标记则在坐标后加'n'再按回车;否则直接输入坐标\n");
		printf("请输入坐标 x y:");
		scanf("%d %d", &y, &x);
		
		int dontpailei = 0;
		{
			int flag =1 ;
			while ((ch = getchar()) != '\n') {
				if (flag) {
					if (ch != ' ' && ch != '	') {
						dontpailei = 1;
						flag = 0;
						if (ch == 'y') {
							if (prinboard[x - 1][y - 1]==1) {
								printf("该位置以排雷，为已知位置，标记无效！！！请重新输入！！！\n");
							}
							else if (prinboard[x - 1][y - 1] == 2) {
								printf("该位置以标记！！！请重新输入！！！\n");
							}
							else {
								prinboard[x - 1][y - 1] = 2;
								printboard(leiboard, prinboard, wid, len, leibiao, panbiao, lei);
								printf("标记成功！\n");
							}
						}
						else if (ch == 'n') {
							if (prinboard[x - 1][y - 1] == 2) {
								prinboard[x - 1][y - 1] = 0;
								printboard(leiboard, prinboard, wid, len, leibiao, panbiao, lei);
								printf("取消标记成功！\n");
							}
							else if (prinboard[x - 1][y - 1] == 1) {
								printf("该位置以排雷，为已知位置，取消标记无效！！！请重新输入！！！\n");
							}
							else {
								printf("该位置未标记！！！请重新输入！！！\n");
							}
						}
						else {
							printf("未知输入！！！请重新输入！！！\n");
						}
					}
				}
			}
		}
		if (dontpailei) {
			goto laba1;
		}
		if (x > wid || y > len || x == 0 || y == 0 || prinboard[x - 1][y - 1] == 1) {
			printf("不合法输入！！！ 请重新输入！！！\n\n");
			goto laba1;
		}
		if (leiboard[x - 1][y-1] - '0' == 0) {
			for (x = 0; x < wid; ++x) {
				for (y = 0; y < len; ++y) {
					if (leiboard[x][y] - '0' == 0) {
						prinboard[x][y] = 1;
					}
				}
			}
			changeresult = 0;
			printf("------您踩到雷了,本局结束------\n\n");
		}
		else {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y - 1);
		}
		if (changeresult) {
			if (lei == countrest(prinboard, wid, len)) {
				printf("----恭喜您成功排除了所有的雷-------\n\n");
				changeresult = 0;//用于结束游戏
			}
			else {
				printf("----恭喜您本次成功排雷，继续加油-------\n\n");
			}
		
		}
		printboard(leiboard, prinboard, wid, len, leibiao, panbiao,lei);
		printf("\n\n\n");
	} while (changeresult);
	printf("按回车键结束\\>:");
	getchar();
	scanf("%*[^\n]%*c");
}
//判断游戏数据是否正常，防止以不正常数据开始游戏造成错误 1：正常 0：不正常
int ispropre(int wid, int len,int lei,char leibiao,char panbiao)
{
	int a = wid * len;
	if ( lei >= a||  wid <= 0 || wid > WID || len <= 0 || len > LEN||lei<=0) {
		return 0;
	}
	if (panbiao - leibiao == 0 || panbiao - 'y' == 0 || leibiao - 'y' == 0) {
		return 0;
	}
	if (panbiao - ' ' == 0 || leibiao - ' ' == 0 || panbiao - '		'==0 || leibiao - '	' == 0) {
		return 0;
	}
	
	return 1;
}
//设置集成函数
void set(int* wid, int* len, int* lei, int* hard, char* leibiao, char* panbiao)
{
	int input = 11;
	do {
		printf("\n\n********************  设  置  菜  单  *******************************************\n");
		printf("1:设置为低级难度玩法         2：设置为中级难度玩法          3：设置为高级难度玩法\n");
		printf("4:设置为自定义难度玩法       5：自定义雷的符号              6：自定义未知处的符号\n");
		printf("7:查看现在的设置             8：保存备份现在的设置          9：加载上次的设置\n");
		printf("10:自定义难度玩法方案设置                                   0:退出设置\n\n");
		printf("*********************************************************************************\n\n");
	laba1:
		input = 11;
		printf("Your option\\>:");
		scanf("%d", &input);
		scanf("%*[^\n]%*c");
		switch (input) {
		case 1:
			*hard = 0;
			break;
		case 2:
			*hard = 1;
			break;
		case 3:
			*hard = 2;
			break;
		case 4:
			*hard = 3;
			break;
		case 5:
		{
			char ch = 0;
		laba2:
			ch = 0;
			printf("您想自定义雷的符号为(必须为可见的英文字符)：");
			scanf(" %c", &ch);
			scanf("%*[^\n]%*c");
			if (ch == 0) {
				printf("！！！不合法输入，请重新输入！！！\n\n");
				goto laba2;
			}
			else if (ch == 'y') {
				printf("'y'为雷的标记符号，请重新输入！\n");
				goto laba2;
			}
			else if (ch == *panbiao) {
				printf("！！！你设设置的雷的符号与未知处的符号相同，请重新输入！！！\n");
				goto laba2;
			}
			*leibiao = ch;
		}
		break;
		case 6:
		{
			char ch = 0;
		laba3:
			ch = 0;
			printf("您想自定义未知处的符号为(必须为可见的英文字符)：");
			scanf(" %c", &ch);
			scanf("%*[^\n]%*c");
			if (ch == 0) {
				printf("！！！不合法输入，请重新输入！！！\n\n");
				goto laba3;
			}
			else if (ch == 'y') {
				printf("'y'为雷的标记符号，请重新输入！\n");
				goto laba3;
			}
			else if (ch == *leibiao) {
				printf("！！！你设设置的未知处的符号和雷的符号相同，请重新输入！！！\n");
				goto laba3;
			}
			*panbiao = ch;
		}
		break;
		case 7:
			pirnset(wid, len, hard, lei, leibiao, panbiao);
			break;
		case 8:
			beifenset(*(wid + 3), *(len + 3), *(lei + 3), *hard, *leibiao, *panbiao);
			break;
		case 9:
			loadset(wid + 3, len + 3, lei + 3, hard, leibiao, panbiao);
			printf("以下下为加载出来的上次设置的内容\\>:\n");
			pirnset(wid, len, hard, lei, leibiao, panbiao);
			break;
		case 10:
			setmine(&wid[3], &len[3], &lei[3]);
			break;
		case 0:
			printf("退出设置\\>\n");
			break;
		default:
			printf("！！！不合法输入，请重新选择！！！\n\n");
			goto laba1;
		}
	} while (input);
}