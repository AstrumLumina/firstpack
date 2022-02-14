#define   _CRT_SECURE_NO_WARNINGS  1

//设置函数还比较松散，ui体验较差，有时间重新组织一下：细分功能函数，将设置放到游戏函数前，不用每次都设置（可以将设置有关的变量设为全局变量
// 本程序的设置函数以改进，ui体验已有很大的提升
// 该程序有许多遍历棋盘（二维数组）的函数，以正方形为模型做了简化，有些不太正的矩形棋盘（例如3*9）可能会遍历出错，请找时间改正-----已优化
//该程序的某个位置算力函数还有待提高和改进
//该程序有些函数还存在输入数字时，用户输入字符而照成的死机（陷入是循环）的问题，
//该程序之前用inputerror（或error）和相应的if语句，用于解决用户在输入数字时输入字符照成的是循环问题，但是还存在有用户不小心多输入内
// 容，导致程序可能没按照操作者的意愿自动运行下去----因此现在改为每次输入后都清空输入缓冲区，故上述问题已不存在，但程序中与error有关的
//程序还留着（但在程序运行时将不起作用（清空缓冲区保证了这种问题不会产生），大家可以按需决定是否删除（注释）掉这些代码，或者注释掉
//每个正常scanf语句后的scanf("%*[^\n]%*c");语句让error有关代码生效

#include"game.h"
//引入全局变量
extern char chessman[2];
extern int wid ;
extern int len;
extern int first;//先走玩家
extern int advance ;//l游戏难度
extern int num ;//几（三）子棋

//斜向算力控制变量
#define XIEBEISHU 3;

//初始化
void initialboard(char board[WID][LEN], int wid, int len)
{
	int i ;
	int j ;
	for (i = 0; i < wid; ++i) {
		for (j = 0; j < len; ++j) {
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void prinboard(char board[WID][LEN], int wid, int len)
{
	int i;
	int j;
	//打印第一行的数字和箭头标号
	for (i = 1; i <= len; ++i) {
		printf("%-4d", i);
	}
	printf("   --->x\n");
	//打印棋盘内容
	for (i = 0; i < wid-1; ++i) {
		for (j = 0; j < len-1; ++j) {
			printf(" %c |", board[i][j]);
		}
		printf(" %c  %d\n", board[i][j],i+1);
		for (j = 0; j < len - 1; ++j) {
			printf("---|");
		}
		printf("---\n");
	}
	for (j = 0; j < len-1; ++j) {
		printf(" %c |", board[i][j]);
	}
	printf(" %c  %d\n", board[i][j],wid);
	//打印箭头标号
	for (j = 0; j < len; ++j) {
		printf("    ");
	}
	printf(" |\n");
	for (j = 0; j < len; ++j) {
		printf("    ");
	}
	printf("\\|/ y\n");
}

//设置函数*************************************************************************************************************************************
//该函数还比较松散，ui体验较差，有时间重新组织一下：细分功能函数，将设置放到游戏函数前，不用每次都设置（可以将设置有关的变量设为全局变量
void set()
{
	int choice=0;
	int inputerror = 1;
	do {
	laba1:
		setmenu();
	laba2:
		printf("对于非正常输入，只取第一个正常输入\n");
		printf("your choice:");
		choice = 0;
		scanf("%d", &choice);
		scanf("%*[^\n]%*c");
		if (choice > 0 && choice < 10) {
			;
		}
		else {
			printf("输入不符合规定！！请重新输入\n");
			++inputerror;
			if (inputerror % 20 == 0) {
				printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
				printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
				getchar();
				goto laba1;
			}
			else {
				goto laba2;
			}
			
		}
		switch (choice)
		{
		case 1:// 改变棋盘大小
			changeboard();
			break;
		case 2://选择玩法种类（现在为 %d子棋）
			changenum();
			break;
		case 3://设置棋盘符号
			changechessman();
			break;
		case 4://设置先走玩家
			changefirst();
			break;
		case 5://设置游戏难度
			changehard();
			break;
		case 6:
			load();
			printf("请查看加载出的设置数据:\n");
			prinset();
			break;
		case 7:
			beifen();
			break;
		case 8:
			prinset();
			break;
		case 9://退出设置
			printf("退出设置\\>\n");
			choice = 0;
			break;
		default:
			printf("未知操作，请重新输入！！\n");
			break;
		}
	} while (choice);
	
}
//设置菜单打印
void setmenu()
{
	printf("\n\n*********************************  设  置  菜  单  *************************************************************\n");
	printf("1: 改变棋盘大小（现在为 %2d*%2d）                 2：选择玩法种类（现在为 %d子棋）\n", wid, len, num);
	printf("3: 设置棋盘符号（现在玩家：%c 电脑：%c）          4: 设置先走玩家（若从未修改，默认玩家先走,否则为上次的设置的模式）\n", chessman[0], chessman[1]);
	printf("5: 设置游戏难度（默认傻瓜模式,该模式下玩小棋盘让电脑赢才是真本事）\n");
	printf("6: 加载使用上次保存备份的设置                   7：将现在的设置备份保存\n");
	printf("8：查看设置（将设置全部显示到屏幕)              9：退出设置,(进入主菜单）\n");
	printf("**************************************************************************************************************\n\n");
}
// 改变棋盘大小
void changeboard()
{
	int a=0;
	int error = 1;
laba1:
	//该if语句用于防止用户未输入数字造成的死机
	if (error % 20== 0) {
		printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
		printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
		getchar();
	}
	printf("对于非正常输入，只取第一个正常输入\n");
	printf("注意：棋盘的宽必须大于 1 ，且不大于 %d\n",WID);
	printf("请输入棋盘的宽(棋盘的行数）：");
	scanf(" %d", &a);
	scanf("%*[^\n]%*c");
	if (a > 1 && a < WID) {
		wid = a;
	}
	else {
		printf("输入不符合规定！！请重新输入\n");
		++error;
		goto laba1;
	}
	error = 1;
laba2:
	a = 0;
	if (error % 20 == 0) {
		printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
		printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
		getchar();
	}
	printf("对于非正常输入，只取第一个正常输入\n");
	printf("注意：棋盘的长必须大于 1 ，且不大于 %d\n", LEN);
	printf("请输入棋盘的长(棋盘的列数）：");
	scanf(" %d", &a);
	scanf("%*[^\n]%*c");
	if (a > 1 && a < LEN) {
		len = a;
	}
	else {
		++error;
		printf("输入不符合规定！！请重新输入\n");
		goto laba2;
	}
}
//选择玩法种类（现在为 %d子棋）,还未改正输入问题隐患---已改正
void changenum()
{
	int n=0;
	int error=1;
	int max = len > wid ? len : wid;
	//设置玩法（玩几子棋）
laba1:
	if (error % 20 == 0) {
		printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
		printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
		getchar();
	}
	printf("对于非正常输入，只取第一个正常输入\n");
	printf("您想玩几子棋呢（至少为2子棋，至多不超过 %d 子棋）：",max);
	scanf("%d", &n);
	scanf("%*[^\n]%*c");
	if (n > 1 && n <= max) {
		num = n;
	}
	else {
		++error;
		printf("invalid input !!!!\n");
		printf("please enter your chioce again:");
		goto laba1;
	}
}
// 设置棋盘符号
void changechessman()
{
	char ch;
	printf("注意不能用空格等特殊字符，否则输入无效！！\n");
	printf("！！！！！！！！！！只能使用---英文--字符，否则输入无效！！！！！\n");
laba1:
	printf("对于非正常输入，只取第一个正常输入\n");
	printf("your chessman:");
	//注意细节，%c前面要加空格，尤其是下面的那一个，否则对于有些输入会产生意想不到的结果---且后面不能加空格！！！！！
	scanf(" %c", &ch);
	scanf("%*[^\n]%*c");
	if (ch > 0) {
		chessman[0] = ch;
	}
	else {
		printf("！！！！！！！！！！只能使用---英文--字符，这是输入无效！！！！！！！！\n");
		getchar();//读取换行符，防止后面运行小错误（会多一次goto的循环
		goto laba1;
	}
laba2:
	printf("对于非正常输入，只取第一个正常输入\n");
	printf("computer's chessman:");
	scanf(" %c", &ch);
	scanf("%*[^\n]%*c");
	if (ch > 0) {
		chessman[1] = ch;
	}
	else {
		printf("！！！！！！！！！！只能使用---英文--字符，这是输入无效！！！！！！！！\n");
		getchar();
		goto laba2;
	}
	if (chessman[0] == chessman[1]) {
		printf("您设置了两个相同的棋子符号，请重新设置！！！！请重新设置\n");
		goto laba1;
	}
}
//设置先走玩家
void changefirst()
{
	int error = 1;
	int a=0;
laba1:
	if (error % 20 == 0) {
		printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
		printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
		getchar();
	}
	printf("对于非正常输入，只取第一个正常输入\n");
	if (first) {
		printf("现在为电脑先走（1：改变    2：不改变）：");
	}
	else {
		printf("现在为玩家先走（1：改变    2：不改变）：");
	}
	scanf("%d", &a);
	scanf("%*[^\n]%*c");
	if (a == 1) {
		a = !first;
		first = a;
	}
	else if (a == 2) {
		;
	}
	else {
		++error;
		printf("非法输入！！！！,请重新输入\n");
		goto laba1;
	}
}
//设置游戏难度
void changehard()
{
	int a=0;
	int error = 1;
laba1:
	if (error % 20 == 0) {
		printf("\n\n\n！！！！！！！  禁止  输入  非 数字 字符！！！！！！！！\n");
		printf(".....若问题未解决，请输入任意字符尝试解决问题.....\n");
		getchar();
	}
	printf("对于非正常输入，只取第一个正常输入\n");
	if (advance) {
		printf("现在为高级模式，是否降低游戏难度（1：是    2:否）：");
	}
	else {
		printf("现在为低级模式，是否提高游戏难度（1：是    2:否）：");
	}
	scanf("%d", &a);
	scanf("%*[^\n]%*c");
	if (a == 2) {
		;
	}
	else if (a == 1) {
		a = !advance;
		advance = a;
	}
	else {
		++error;
		printf("非法输入！！！！,请重新输入\n");
		goto laba1;
	}
}

//*****************************************************************************************************
//玩家走棋子
void player(char board[][LEN],int wid,int len)
{
	int x;
	int y;
	int error = 1;
	printf("玩家\\>\n");
	while (1) {
		if (error % 6 == 0) {
			printf("!!!!!! 禁止 输入 非 数字 内容 ！！！！！！\n");
			printf("如果问题未解决，请输入一个任意字符尝试解决！\n");
			getchar();
		}
		printf("请输入您要落子的坐标位置 x y：");
		x = 0;
		y = 0;
		scanf("%d %d", &x, &y);
		if (x > len || y > wid||x==0||y==0) {
			++error;
			printf("无效坐标（该坐标超出了棋盘范围或坐标不合法），请重新输入！！！\n");
		}
		else if (board[y - 1][x - 1] != ' ') {
			printf("无效坐标（该坐标已有棋子），请重新输入！！！\n");
		}
		else {
			board[y - 1][x - 1] = chessman[0];
			break;
		}
		scanf("%*[^\n]%*c");
	}
	
}

//电脑走棋子************************************************************************************************************************************************
//低级算法
void computer(char board[][LEN], int wid,int len)
{
	int x, y;
	printf("电脑\\>\n");
	while (1) {
		x = rand() % LEN;
		y = rand() % WID;
		if (board[y][x] == ' ') {
			board[y][x] = chessman[1];
			break;
		}
	}
}
//电脑走棋子的高级算法
void advcomputer(char board[WID][LEN], int wid, int len, int num)
{
	printf("电脑\\>\n");
	int i, j;
	int flag = 1;//循环条件
	//用于存放最优解
	int x = -1;//行
	int y = -1;//列
	int capability = 0;//0为初始情况，必赢直接结束，> ,-4为必堵位置，>,-3和 ,>, -2为创造必赢位置的位置，>, -1为提前必堵位置,>，>0为算力
	                   //                              -5              -4       -3                        -2 , -1              >0
	int a = 0;//用于接收函数返回值
	int afight;//接收fight函数的的返回值
	for (i = 0; i < len && flag; ++i) {
		for (j = 0; j < wid&&flag; ++j) {
			if (board[i][j] - ' ' == 0) {
				a = willwin(board, WID, LEN, num, i, j);//必赢能赢返回1 ----能创造必赢机会的返回2或3（2的位置比3更好好）----不能返回0
				if (a == 1) {
					x = i;
					y = j;
					flag = 0;
				}
				else {
					afight = fight(board, WID, LEN, num, i, j);//0为不需堵，1为必堵，2(更优先）,3为提前必堵
					if (afight == 1&&capability!=-5) {
						x = i;
						y = j;
						capability = -5;
					}
					else if (a != 0) {//创造机会
						if (a == 2 && capability > -4) {
							x = i;
							y = j;
							capability = -4;
						}
						else if (capability > -3) {
							x = i;
							y = j;
							capability = -3;
						}
					}
					else if (afight == 2) {
						if (capability > -2) {
							x = i;
							y = j;
							capability = -2;
						}
					}
					else if (afight == 3) {
						if (capability > -1) {
							x = i;
							y = j;
							capability = -1;
						}
					}
					else if (capability >= 0) {
						a = ability(board, WID, LEN, num, i, j);
						if (a > capability) {
							x = i;
							y = j;
							capability = a;
						}
					}
				}
			}
		}
	}
	board[x][y] = chessman[1];
}
//必赢位置判断-----必赢能赢返回1 ----能创造必赢机会的返回2或3（2的位置比3更好好）----不能返回0
int willwin(char board[WID][LEN], int wid, int len, int num, int x,int y)
{
	//必赢能赢返回1 ----能创造必赢机会的返回2或3（2的位置比3更好好）----不能返回0
	int i = 0;
	int j = 0;
	char ch = chessman[1];
	int count = 1;
	//判断创造机会位置的标志******************************
	int flag1 = 0;
	int flag2 = 0;

	//横向判断*****************
	count = 1;
	flag1 = 0;
	j = 1;
	while (board[x][y + j] - ch == 0 && j + y < len ) {
		++count;
		++j;
	}
	if (board[x][y + j] - ' ' == 0) {
		flag1 = 1;
	}
	j = -1;
	while (board[x][y + j] - ch == 0 && j + y >= 0) {
		++count;
		--j;
	}
	if (board[x][y + j] - ' ' == 0) {
		flag1 = 1;
	}
	if (count>= num ) {
		return 1;
	}
	else if (count >= (num - 1) && flag1) {
		++flag2;
	}
	//竖向判断****************
	count = 1;
	flag1 = 0;
	i= 1;
	while (board[x+i][y] - ch == 0 && x+i < wid ) {
		++count;
		++i;
	}
	if (board[x + i][y] - ' ' == 0) {
		flag1 = 1;
	}
	i = -1;
	while (board[x+i][y] - ch == 0 && x+i >= 0) {
		++count;
		--i;
	}
	if (board[x + i][y] - ' ' == 0) {
		flag1 = 1;
	}
	if (count >= num) {
		return 1;
	}
	else if (count >= (num - 1) && flag1) {
		++flag2;
	}
	//---'/‘：判断 x-,y+  &&  x+,y-
	count = 1;
	flag1 = 0;
	i =- 1;
	j = 1;
	while (board[x + i][y + j] - ch == 0 && x + i >= 0&&y+j<len) {
		++count;
		++j;
		--i;
	}
	if (board[x + i][y+j] - ' ' == 0) {
		flag1 = 1;
	}
	i = 1;
	j = -1;
	while (board[x + i][y + j] - ch == 0 && x + i< wid&& y + j >=0) {
		++count;
		++i;
		--j;
	}
	if (board[x + i][y + j] - ' ' == 0) {
		flag1 = 1;
	}
	if (count >= num) {
		return 1;
	}
	else if (count >= (num - 1) && flag1) {
		++flag2;
	}
	//---'\':判断  x+,y+  && x-,y-
	count = 1;
	flag1 = 0;
	i = 1;
	j = 1;
	while (board[x + i][y + j] - ch == 0 && x + i < wid && y + j < len) {
		++count;
		++j;
		++i;
	}
	if (board[x + i][y + j] - ' ' == 0) {
		flag1 = 1;
	}
	i = -1;
	j = -1;
	while (board[x + i][y + j] - ch == 0 && x + i >=0&& y + j >= 0) {
		++count;
		--i;
		--j;
	}
	if (board[x + i][y + j] - ' ' == 0) {
		flag1 = 1;
	}
	if (count >= num) {
		return 1;
	}
	else if (count >= (num - 1) && flag1) {
		++flag2;
	}
	if (flag2 >1) {
		return 2;
	}
	else if (flag2) {
		return 3;
	}
	return 0;
}

//阻止玩家胜利位置判断-----//0为不需堵，1为必堵，2(更优先）,3为提前必堵
int fight(char board[WID][LEN], int wid, int len, int num, int x,int y)//int probily[2] 
{
	//能阻止返回(1 和 2） ----不能返回0
	int i = 0;
	int j = 0;
	int flag = 0;//判断是否返回2
	//int x = probily[0];
	//int y = robily[1];
	char ch = chessman[0];
	int count = 1;
	int willcount = 0;
	int willcountsum = 0;//记录willcount的总数
	//横向判断*****************
	count = 1;
	willcount = 0;
	j = 1;
	while (board[x][y + j] - ch == 0 && j + y < len) {
		++count;
		++j;
	}
	if (board[x][y + j] - ' ' == 0) { willcount=1; }
	j = -1;
	while (board[x][y + j] - ch == 0 && j + y >= 0) {
		++count;
		--j;
	}
	if (board[x][y + j] - ' ' == 0) { willcount=1; }
	if (count >= num ) {
		return 1;
	}
	else if ( (count >= (num - 1)) && willcount ) {
		flag = 1;
	}
	if (flag) { ++willcountsum; }
	//竖向判断****************
	count = 1;
	willcount = 0;
	i = 1;
	while (board[x + i][y] - ch == 0 && x + i < wid) {
		++count;
		++i;
	}
	if (board[x+i][y ] - ' ' == 0) { willcount = 1; }
	i = -1;
	while (board[x + i][y] - ch == 0 && x + i >= 0) {
		++count;
		--i;
	}
	if (board[x + i][y] - ' ' == 0) { willcount = 1; }
	if (count >= num) {
		return 1;
	}
	else if ((count >= (num - 1)) && willcount) {
		flag = 1;
	}
	if (flag) { ++willcountsum; }
	//---'/‘：判断 x-,y+  &&  x+,y-
	count = 1;
	willcount = 0;
	i = -1;
	j = 1;
	while (board[x + i][y + j] - ch == 0 && x + i >= 0 && y + j < len) {
		++count;
		++j;
		--i;
	}
	if (board[x + i][y+j] - ' ' == 0) { willcount = 1; }
	i = 1;
	j = -1;
	while (board[x + i][y + j] - ch == 0 && x + i < wid && y + j >= 0) {
		++count;
		++i;
		--j;
	}
	if (board[x + i][y + j] - ' ' == 0) { willcount = 1; }
	if (count >= num) {
		return 1;
	}
	else if ((count >= (num - 1)) && willcount) {
		flag = 1;
	}
	if (flag) { ++willcountsum; }
	//---'\':判断  x+,y+  && x-,y-
	count = 1;
	willcount = 0;
	i = 1;
	j = 1;
	while (board[x + i][y + j] - ch == 0 && x + i < wid && y + j < len) {
		++count;
		++j;
		++i;
	}
	if (board[x + i][y + j] - ' ' == 0) { willcount = 1; }
	i = -1;
	j = -1;
	while (board[x + i][y + j] - ch== 0 && x + i >= 0 && y + j >= 0) {
		++count;
		--i;
		--j;
	}
	if (board[x + i][y + j] - ' ' == 0) { willcount = 1; }
	if (count >= num) {
		return 1;
	}
	else if ((count >= (num - 1)) && willcount) {
		flag = 1;
	}
	if (flag) { ++willcountsum; }
	//**************************************
	if (willcountsum>1) {
		return 2;
	}
	if (willcountsum ) {
		return 3;
	}
	return 0;
}

//位置算力计算
int ability(char board[WID][LEN], int wid, int len, int num, int x, int y)
{
	
	int capacity = 0;//保存该位置算力
	int i = 0;
	int j = 0;
	int geju = len > wid ? len : wid;
	int pointshuanzi = 9*(num +2*geju);//方向算子（8个方向），大于4个方向时生效
	int defshuanzi=2*num+2*geju;//敌方算子（最多有7各），
	int myshuanzi=num+geju;//己方算子
	int flag9 = 0;//判断是否增加算力--根据周围有无他人的棋子
	int flag1,flag2, flag3, flag4, flag5, flag6, flag7, flag8;//判断8个方向是否可以延伸

	char ch = chessman[1];
	int count = 1;//可以连起来的数
	int count2 = 1;
	int aready = 0;//己方已有棋子数
	//横向判断*******************************************
	count = 1;
	j = 1;
	flag1 = 0;
	while (  j + y< len) {
		if (board[x][y + j] - ch == 0) {
			++count;
			++aready;
			++j;
			flag1 = 1;
		}
		else if(board[x][y + j] - ' ' == 0) {
			++count;
			++j;
			flag1 = 1;
		}else{
			++flag9;
			break;
		}
	}
	j = -1;
	flag2 = 0;
	count2 = 1;
	while (j + y >=0) {
		if (board[x][y + j] - ch == 0) {
			++aready;
				++count2;
				--j;
				flag2 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count2;
				--j;
				flag2 = 1;
		}else{
			++flag9;
			break;
			}
	}
	if (count + count2 > num) {
		//capacity += count / num;
		capacity +=(count%num)*2;
		if (count >= num) {
			flag1 = 3;
		}
		if (count2 >= num) {
			flag2 = 3;
		}
	}
	else {
		flag1 = 0;
		flag2 = 0;
	}
	
	//竖向判断****************
	count = 1;
	i = 1;
	flag3 = 0;
	while (x + i < wid) {
		if (board[x][y + j] - ch == 0) {
			++count;
			++aready;
			++i;
			flag3 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count;
			++i;
			flag3 = 1;
		}else{
			++flag9;
			break;
		}
	}
	i = -1;
	flag4 = 0;
	count2 = 1;
	while (x + i >= 0) {
		if (board[x][y + j] - ch == 0) {
			++count2;
			++aready;
			--i;
			flag4 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count2;
			--i;
			flag4 = 1;
		}
		else {
			++flag9;
			break;
		}
	}
	if (count + count2 > num) {
		//capacity += count / num;
		capacity += (count % num) * 2;
		if (count >= num) {
			flag3 = 3;
		}
		if (count2 >= num) {
			flag4 = 3;
		}
	}
	else {
		flag3 = 0;
		flag4 = 0;
	}
	//---'/‘：判断 x-,y+  &&  x+,y-  ********************************
	count = 1;
	i = -1;
	j = 1;
	flag5 = 0;
	while (x + i >= 0 && y + j < len) {
		if (board[x][y + j] - ch == 0) {
			++count;
			++aready;
			--i;
			++j;
			flag5 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count;
			--i;
			++j;
			flag5 = 1;
		}
		else {
			++flag9;
			break;
		}
	}
	i = 1;
	j = -1;
	flag6 = 0;
	count2 = 1;
	while (x + i < wid && y + j >= 0) {
		if (board[x][y + j] - ch == 0) {
			++count2;
			++aready;
			--j;
			++i;
			flag6 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count2;
			++i;
			--j;
			flag6 = 1;
		}
		else {
			++flag9;
			break;
		}
	}
	if (count + count2 > num) {
		//capacity += count / num;
		capacity += (count % num) * 2;
		if (count >= num) {
			flag5 = 3;
		}
		if (count2 >= num) {
			flag6 = 3;
		}
	}
	else {
		flag5 = 0;
		flag6 = 0;
	}
	//---'\':判断  x+,y+  && x-,y-  *****************************************************
	count = 1;
	i = 1;
	j = 1;
	flag7 = 0;
	while (x + i >= wid && y + j < len) {
		if (board[x][y + j] - ch == 0) {
			++count;
			++aready;
			++j;
			++i;
			flag7 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count;
			++j;
			++i;
			flag7 = 1;
		}
		else {
			++flag9;
			break;
		}
	}
	i = -1;
	j = -1;
	flag8 = 0;
	count2 = 1;
	while (x + i >= 0 && y + j >= 0) {
		if (board[x][y + j] - ch == 0) {
			++count2;
			++aready;
			--i;
			--j;
			flag8 = 1;
		}
		else if (board[x][y + j] - ' ' == 0) {
			++count2;
			--i;
			--j;
			flag8 = 1;
		}
		else {
			++flag9;
			break;
		}
	}
	if (count+count2 > num) {
		//capacity += count / num;
		capacity += (count % num) * 2;
		if (count >= num) {
			flag7 = 3;
		}
		if (count2 >= num) {
			flag8 = 3;
		}
	}
	else {
		flag7 = 0;
		flag8 = 0;
	}
	//返回算力
	flag5 *= XIEBEISHU; flag6 *= XIEBEISHU; flag7 *= XIEBEISHU; flag8 *= XIEBEISHU;
	flag1 += flag2 += flag3 += flag4  += flag5  += flag6 += flag7 += flag8;
	if (flag1 > 3) {
		capacity += pointshuanzi * flag1;
	}
	if (flag9 < 4) {
		capacity += flag9 * defshuanzi;
	}
	else {
		capacity += 3 * defshuanzi;
	}
	
	capacity += (myshuanzi * aready);
	return capacity;
}


//判断输赢函数.....返回赢家的棋子符号...............................................................................................
char iswin(char board[WID][LEN], int wid, int len, int num)
{
	int i, j;
	int sum;
	int  vacant = 1;
	//各个方向之间的查找并无关联，可按注释分割分别查看某一方向的代码
	//斜向查找1 ----‘/’:len+1 wid-1  
	for (i = 0; i < wid; ++i) {
		int m = i;
		sum = 1;
		j = 0;
		if (board[m][j] - ' ' == 0) {
			vacant = 0;
		}
		while (m > 0 && j < len - 1) {
			while (board[m][j] - board[m - 1][j + 1] == 0 && m > 0 && j < len - 1) {
				--m;
				++j;
				++sum;
			}
			if (sum < num || board[m][j] - ' ' == 0) {
				--m;
				++j;
				sum = 1;
				if (board[m][j] - ' ' == 0) {
					vacant = 0;
				}
			}
			else {
				return board[m][j];
			}
		}
		
	}
	//这段代码判断不正确？？？？？？？？？？？？？？？？-----已改正
	for (i = 1; i < len; ++i) {
		int m = i;
		sum = 1;
		j = wid;
		if (board[j][m] - ' ' == 0) {
			vacant = 0;
		}
		while (m < len - 1 && j>0) {
			while (board[j][m] - board[j - 1][m + 1] == 0 && m < len - 1 && j>0) {
				--j;
				++m;
				++sum;
			}
			if (sum < num || board[j][m] - ' ' == 0) {
				--j;
				++m;
				sum = 1;
				if (board[j][m] - ' ' == 0) {
					vacant = 0;
				}
			}
			else {
				return board[j][m];
			}
		}
	}
	//斜向查找2----‘\’:  wid+1 len+1
	for (i = 0; i < wid; ++i) {
		int m = i;
		sum = 1;
		j = 0;
		if (board[m][j] - ' ' == 0) {
			vacant = 0;
		}
		while (m < wid - 1 && j < len - 1) {
			while (board[m][j] - board[m + 1][j + 1] == 0 && m < wid - 1 && j < len - 1) {
				++m;
				++j;
				++sum;
			}
			if (sum < num || board[m][j] - ' ' == 0) {
				++m;
				++j;
				sum = 1;
				if (board[m][j] - ' ' == 0) {
					vacant = 0;
				}
			}
			else {
				return board[m][j];
			}
		}
	}
	for (i = 0; i < len; ++i) {
		int m = i;
		sum = 1;
		j = 0;
		if (board[j][m] - ' ' == 0) {
			vacant = 0;
		}
		while (m < len - 1 && j < wid - 1) {
			while (board[j][m] - board[j + 1][m + 1] == 0 && m < len - 1 && j < wid - 1) {
				++j;
				++m;
				++sum;
			}
			if (sum < num || board[j][m] - ' ' == 0) {
				++j;
				++m;
				sum = 1;
				if (board[j][m] - ' ' == 0) {
					vacant = 0;
				}
			}
			else {
				return board[j][m];
			}
		}
	}
	//横向查找
	for (i = 1; i < wid; ++i) {
		sum = 1;
		j = 0;
		if (board[i][j] - ' ' == 0) {
			vacant = 0;
		}
		while (j < len - 1) {
			while (board[i][j] - board[i][j + 1] == 0 && j < len - 1) {
				++sum;
				++j;
			}
			if (sum < num || board[i][j] - ' '==0) {
				sum = 1;
				++j;
				if (board[i][j] - ' ' == 0) {
					vacant = 0;
				}
			}
			else {
				return board[i][j];
			}
		}
	}
	//竖向查找
	for (i = 0; i < wid; ++i) {
		sum = 1;
		j = 0;
		if (board[j][i] - ' ' == 0) {
			vacant = 0;
		}
		while (j < wid - 1) {
			while (board[j][i] - board[j + 1][i] == 0 && j < wid - 1) {
				++sum;
				++j;
			}
			if (sum < num || board[j][i] - ' '==0) {
				sum = 1;
				++j;
				if (board[j][i] - ' ' == 0) {
					vacant = 0;
				}
			}
			else {
				return board[j][i];
			}
		}
	}
	if (vacant) {
		return  ' ';
	}
	else {
		return  '\0';
	}
}







