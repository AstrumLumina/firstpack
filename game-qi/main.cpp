#define   _CRT_SECURE_NO_WARNINGS  1
//这是一个三子棋游戏的代码
//这个游戏默认时3*3的棋盘的三子棋，若要改变玩法，可以到头文件改棋盘大小的宏

//包含文件
#include"game.h"

//主菜单选择变量  全局变量
int option;
//默认棋盘大小(3*3)	
int wid = INITIALWID;
int len = INITIALLEN;
int num = NUM;//几（三）子棋
int first = 0;//先走玩家
int advance = HARD;//l游戏难度

//棋子类型
char CHESSMAN


//游戏集成函数
void game()
{
	//二维数组存放棋盘数据
	char board[WID][LEN];

	//初始化棋盘
	initialboard(board, wid, len);
	//打印棋盘和棋子
	prinboard(board, wid, len);
	//开始下棋落子
	char win=0;//存放判断结果
	//0:代表继续  谁的符号代表谁赢  ' '=32:代表平局
	if (first) {
		goto laba1;
	}
	while (1) {
		//玩家下
		player(board, wid,len);
		prinboard(board, wid, len);
		win=iswin(board, wid, len, num);
		if (win ) { break; }
		//电脑下
		laba1:
		if (advance) {
			advcomputer(board, wid,len,num);
		}
		else {
			computer(board, wid,len);
		}
		prinboard(board, wid,len);
		win = iswin(board, wid,len , num);
		if (win) { break; }
	}
	if (win - ' ' == 0) {
		printf("----平局--------\n");
	}
	else if (win - chessman[0] == 0) {
		printf("-----你赢了----\n");
	}
	else if(win-chessman[1]==0) {
		printf("---电脑赢了----\n");
	}
	else {
		printf("未知结果（win =%c)\n", win);
		printf("#%c#%d#\n", win, win);
	}
	printf("按任意按键结束本局\\>:");
	scanf("%*[^\n]%*c");
	getchar();

}

//显示主菜单函数
void menu()
{
	static int inputerror = 1;
	int a = 0;
laba2:
	printf("\noption menue\\>:\n");
	printf("*********  选  择  菜  单  ************************\n");
	printf("1:paly \t \t 2:设置 \t \t 3:exit\n\n");
	printf("***************************************************\n\n");
laba1:
	printf("注意：对于非正常输入，只取第一个正常输入\n");
	printf("please enter your chioce\\>:");
	scanf("%d", &a);
	scanf("%*[^\n]%*c");
	if (a == 3 || a == 2 || a == 1) {
		option = a;
	}
	else  {
		printf("输入不符合规定！！请重新输入\n");
		++inputerror;
		if (inputerror % 20 == 0) {
			printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
			printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
			getchar();
			goto laba2;
		}
		else {
			goto laba1;
		}

	}
}


//主函数
int main()
{
	//游戏介绍******************************************
	printf("  //这是一个三子棋游戏的代码\n\
 //这个游戏默认时3*3的棋盘的三子棋，若要改变玩法可以到设置里面更改，也可以到头文件修改宏（可以改变棋盘最大的大小）\n\
//经过测试，该游戏 4 子棋时难度最大（推荐棋盘大小：( 9 * 13 )\n");
	//***************************************************
	do {
		menu();
		switch (option)
		{
		case 2:
			set();
			option = 1;//option在别处用到，防止改变
			break;
		case 1:
			printf("start game...\n");
			srand((unsigned int)time(0));
			game();
			option = 1;//option在别处用到，防止改变
			break;
		case 3:
			printf("game over...\n");
			option = 0;
			break;
		default:
			printf("invalid option!!!!!!!\n");
			printf("pleae enter your option again\n");
			break;
		}
	} while (option);
	return 0;
}

//游戏设置数据备份函数
void beifen()
{
	FILE* fp = NULL;
	if (fp = fopen("benfen,txt", "w")) {
		fprintf(fp, "%d %d %d %d %d %c %c", wid, len, num, first, advance,chessman[0],chessman[1]);
		if (fclose(fp)) {
			printf("备份文件关闭失败！！\n");
			fp = NULL;
		}
		else {
			printf("备份完成！\n");
			fp = NULL;
		}
	}
	else {
		printf("备份分文件打开失败！！\n");
	}
}

//游戏设置数据加载函数
void load()
{
	FILE* fp = NULL;
	if (fp = fopen("benfen,txt", "r")) {
		fscanf(fp, "%d %d %d %d %d %c %c", &wid, &len, &num, &first, &advance,&chessman[0],&chessman[1]);
		if (fclose(fp)) {
			printf("备份文件关闭失败！！\n");
			fp = NULL;
		}
		else {
			printf("加载完成！\n");
			fp = NULL;
		}
		
	}
	else {
		printf("备份分文件打开失败！！\n");
	}
}


//打印设置数据
void prinset()
{
	printf("以下为设置数据\\>\n");
	printf("*************************************************************************************************************\n");
	printf("1: 棋盘大小: %d*%d      2：玩法种类: %d子棋       3:棋盘符号:玩家：%c 电脑：%c\n\n", wid, len, num, chessman[0], chessman[1]);
	printf("4:先走玩家:");
	if (first) {
		printf("电脑%7c",' ');
	}
	else {
		printf("玩家%7c",' ');
	}
	printf("5:游戏难度：");
	if (advance) {
		printf(" 难 \n\n");
	}
	else {
		printf("傻瓜模式  \n\n");
	}
	printf("**************************************************************************************************************\n\n");
	getchar();
	printf("按回车键退出查看\\>:");
	char ch;
	while ((ch = getchar()) - '\n') { ; }
	putchar('\n');
}