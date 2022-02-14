#define   _CRT_SECURE_NO_WARNINGS  1

//���ú������Ƚ���ɢ��ui����ϲ��ʱ��������֯һ�£�ϸ�ֹ��ܺ����������÷ŵ���Ϸ����ǰ������ÿ�ζ����ã����Խ������йصı�����Ϊȫ�ֱ���
// ����������ú����ԸĽ���ui�������кܴ������
// �ó��������������̣���ά���飩�ĺ�������������Ϊģ�����˼򻯣���Щ��̫���ľ������̣�����3*9�����ܻ������������ʱ�����-----���Ż�
//�ó����ĳ��λ�������������д���ߺ͸Ľ�
//�ó�����Щ������������������ʱ���û������ַ����ճɵ�������������ѭ���������⣬
//�ó���֮ǰ��inputerror����error������Ӧ��if��䣬���ڽ���û�����������ʱ�����ַ��ճɵ���ѭ�����⣬���ǻ��������û���С�Ķ�������
// �ݣ����³������û���ղ����ߵ���Ը�Զ�������ȥ----������ڸ�Ϊÿ�������������뻺�����������������Ѳ����ڣ�����������error�йص�
//�������ţ����ڳ�������ʱ���������ã���ջ�������֤���������ⲻ�����������ҿ��԰�������Ƿ�ɾ����ע�ͣ�����Щ���룬����ע�͵�
//ÿ������scanf�����scanf("%*[^\n]%*c");�����error�йش�����Ч

#include"game.h"
//����ȫ�ֱ���
extern char chessman[2];
extern int wid ;
extern int len;
extern int first;//�������
extern int advance ;//l��Ϸ�Ѷ�
extern int num ;//������������

//б���������Ʊ���
#define XIEBEISHU 3;

//��ʼ��
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
//��ӡ����
void prinboard(char board[WID][LEN], int wid, int len)
{
	int i;
	int j;
	//��ӡ��һ�е����ֺͼ�ͷ���
	for (i = 1; i <= len; ++i) {
		printf("%-4d", i);
	}
	printf("   --->x\n");
	//��ӡ��������
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
	//��ӡ��ͷ���
	for (j = 0; j < len; ++j) {
		printf("    ");
	}
	printf(" |\n");
	for (j = 0; j < len; ++j) {
		printf("    ");
	}
	printf("\\|/ y\n");
}

//���ú���*************************************************************************************************************************************
//�ú������Ƚ���ɢ��ui����ϲ��ʱ��������֯һ�£�ϸ�ֹ��ܺ����������÷ŵ���Ϸ����ǰ������ÿ�ζ����ã����Խ������йصı�����Ϊȫ�ֱ���
void set()
{
	int choice=0;
	int inputerror = 1;
	do {
	laba1:
		setmenu();
	laba2:
		printf("���ڷ��������룬ֻȡ��һ����������\n");
		printf("your choice:");
		choice = 0;
		scanf("%d", &choice);
		scanf("%*[^\n]%*c");
		if (choice > 0 && choice < 10) {
			;
		}
		else {
			printf("���벻���Ϲ涨��������������\n");
			++inputerror;
			if (inputerror % 20 == 0) {
				printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
				printf(".....������δ����������������ַ����Խ������.....\n");
				getchar();
				goto laba1;
			}
			else {
				goto laba2;
			}
			
		}
		switch (choice)
		{
		case 1:// �ı����̴�С
			changeboard();
			break;
		case 2://ѡ���淨���ࣨ����Ϊ %d���壩
			changenum();
			break;
		case 3://�������̷���
			changechessman();
			break;
		case 4://�����������
			changefirst();
			break;
		case 5://������Ϸ�Ѷ�
			changehard();
			break;
		case 6:
			load();
			printf("��鿴���س�����������:\n");
			prinset();
			break;
		case 7:
			beifen();
			break;
		case 8:
			prinset();
			break;
		case 9://�˳�����
			printf("�˳�����\\>\n");
			choice = 0;
			break;
		default:
			printf("δ֪���������������룡��\n");
			break;
		}
	} while (choice);
	
}
//���ò˵���ӡ
void setmenu()
{
	printf("\n\n*********************************  ��  ��  ��  ��  *************************************************************\n");
	printf("1: �ı����̴�С������Ϊ %2d*%2d��                 2��ѡ���淨���ࣨ����Ϊ %d���壩\n", wid, len, num);
	printf("3: �������̷��ţ�������ң�%c ���ԣ�%c��          4: ����������ң�����δ�޸ģ�Ĭ���������,����Ϊ�ϴε����õ�ģʽ��\n", chessman[0], chessman[1]);
	printf("5: ������Ϸ�Ѷȣ�Ĭ��ɵ��ģʽ,��ģʽ����С�����õ���Ӯ�����汾�£�\n");
	printf("6: ����ʹ���ϴα��汸�ݵ�����                   7�������ڵ����ñ��ݱ���\n");
	printf("8���鿴���ã�������ȫ����ʾ����Ļ)              9���˳�����,(�������˵���\n");
	printf("**************************************************************************************************************\n\n");
}
// �ı����̴�С
void changeboard()
{
	int a=0;
	int error = 1;
laba1:
	//��if������ڷ�ֹ�û�δ����������ɵ�����
	if (error % 20== 0) {
		printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
		printf(".....������δ����������������ַ����Խ������.....\n");
		getchar();
	}
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	printf("ע�⣺���̵Ŀ������� 1 ���Ҳ����� %d\n",WID);
	printf("���������̵Ŀ�(���̵���������");
	scanf(" %d", &a);
	scanf("%*[^\n]%*c");
	if (a > 1 && a < WID) {
		wid = a;
	}
	else {
		printf("���벻���Ϲ涨��������������\n");
		++error;
		goto laba1;
	}
	error = 1;
laba2:
	a = 0;
	if (error % 20 == 0) {
		printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
		printf(".....������δ����������������ַ����Խ������.....\n");
		getchar();
	}
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	printf("ע�⣺���̵ĳ�������� 1 ���Ҳ����� %d\n", LEN);
	printf("���������̵ĳ�(���̵���������");
	scanf(" %d", &a);
	scanf("%*[^\n]%*c");
	if (a > 1 && a < LEN) {
		len = a;
	}
	else {
		++error;
		printf("���벻���Ϲ涨��������������\n");
		goto laba2;
	}
}
//ѡ���淨���ࣨ����Ϊ %d���壩,��δ����������������---�Ѹ���
void changenum()
{
	int n=0;
	int error=1;
	int max = len > wid ? len : wid;
	//�����淨���漸���壩
laba1:
	if (error % 20 == 0) {
		printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
		printf(".....������δ����������������ַ����Խ������.....\n");
		getchar();
	}
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	printf("�����漸�����أ�����Ϊ2���壬���಻���� %d ���壩��",max);
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
// �������̷���
void changechessman()
{
	char ch;
	printf("ע�ⲻ���ÿո�������ַ�������������Ч����\n");
	printf("��������������������ֻ��ʹ��---Ӣ��--�ַ�������������Ч����������\n");
laba1:
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	printf("your chessman:");
	//ע��ϸ�ڣ�%cǰ��Ҫ�ӿո��������������һ�������������Щ�����������벻���Ľ��---�Һ��治�ܼӿո񣡣�������
	scanf(" %c", &ch);
	scanf("%*[^\n]%*c");
	if (ch > 0) {
		chessman[0] = ch;
	}
	else {
		printf("��������������������ֻ��ʹ��---Ӣ��--�ַ�������������Ч����������������\n");
		getchar();//��ȡ���з�����ֹ��������С���󣨻��һ��goto��ѭ��
		goto laba1;
	}
laba2:
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	printf("computer's chessman:");
	scanf(" %c", &ch);
	scanf("%*[^\n]%*c");
	if (ch > 0) {
		chessman[1] = ch;
	}
	else {
		printf("��������������������ֻ��ʹ��---Ӣ��--�ַ�������������Ч����������������\n");
		getchar();
		goto laba2;
	}
	if (chessman[0] == chessman[1]) {
		printf("��������������ͬ�����ӷ��ţ����������ã�����������������\n");
		goto laba1;
	}
}
//�����������
void changefirst()
{
	int error = 1;
	int a=0;
laba1:
	if (error % 20 == 0) {
		printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
		printf(".....������δ����������������ַ����Խ������.....\n");
		getchar();
	}
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	if (first) {
		printf("����Ϊ�������ߣ�1���ı�    2�����ı䣩��");
	}
	else {
		printf("����Ϊ������ߣ�1���ı�    2�����ı䣩��");
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
		printf("�Ƿ����룡������,����������\n");
		goto laba1;
	}
}
//������Ϸ�Ѷ�
void changehard()
{
	int a=0;
	int error = 1;
laba1:
	if (error % 20 == 0) {
		printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
		printf(".....������δ����������������ַ����Խ������.....\n");
		getchar();
	}
	printf("���ڷ��������룬ֻȡ��һ����������\n");
	if (advance) {
		printf("����Ϊ�߼�ģʽ���Ƿ񽵵���Ϸ�Ѷȣ�1����    2:�񣩣�");
	}
	else {
		printf("����Ϊ�ͼ�ģʽ���Ƿ������Ϸ�Ѷȣ�1����    2:�񣩣�");
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
		printf("�Ƿ����룡������,����������\n");
		goto laba1;
	}
}

//*****************************************************************************************************
//���������
void player(char board[][LEN],int wid,int len)
{
	int x;
	int y;
	int error = 1;
	printf("���\\>\n");
	while (1) {
		if (error % 6 == 0) {
			printf("!!!!!! ��ֹ ���� �� ���� ���� ������������\n");
			printf("�������δ�����������һ�������ַ����Խ����\n");
			getchar();
		}
		printf("��������Ҫ���ӵ�����λ�� x y��");
		x = 0;
		y = 0;
		scanf("%d %d", &x, &y);
		if (x > len || y > wid||x==0||y==0) {
			++error;
			printf("��Ч���꣨�����곬�������̷�Χ�����겻�Ϸ��������������룡����\n");
		}
		else if (board[y - 1][x - 1] != ' ') {
			printf("��Ч���꣨�������������ӣ������������룡����\n");
		}
		else {
			board[y - 1][x - 1] = chessman[0];
			break;
		}
		scanf("%*[^\n]%*c");
	}
	
}

//����������************************************************************************************************************************************************
//�ͼ��㷨
void computer(char board[][LEN], int wid,int len)
{
	int x, y;
	printf("����\\>\n");
	while (1) {
		x = rand() % LEN;
		y = rand() % WID;
		if (board[y][x] == ' ') {
			board[y][x] = chessman[1];
			break;
		}
	}
}
//���������ӵĸ߼��㷨
void advcomputer(char board[WID][LEN], int wid, int len, int num)
{
	printf("����\\>\n");
	int i, j;
	int flag = 1;//ѭ������
	//���ڴ�����Ž�
	int x = -1;//��
	int y = -1;//��
	int capability = 0;//0Ϊ��ʼ�������Ӯֱ�ӽ�����> ,-4Ϊ�ض�λ�ã�>,-3�� ,>, -2Ϊ�����Ӯλ�õ�λ�ã�>, -1Ϊ��ǰ�ض�λ��,>��>0Ϊ����
	                   //                              -5              -4       -3                        -2 , -1              >0
	int a = 0;//���ڽ��պ�������ֵ
	int afight;//����fight�����ĵķ���ֵ
	for (i = 0; i < len && flag; ++i) {
		for (j = 0; j < wid&&flag; ++j) {
			if (board[i][j] - ' ' == 0) {
				a = willwin(board, WID, LEN, num, i, j);//��Ӯ��Ӯ����1 ----�ܴ����Ӯ����ķ���2��3��2��λ�ñ�3���úã�----���ܷ���0
				if (a == 1) {
					x = i;
					y = j;
					flag = 0;
				}
				else {
					afight = fight(board, WID, LEN, num, i, j);//0Ϊ����£�1Ϊ�ض£�2(�����ȣ�,3Ϊ��ǰ�ض�
					if (afight == 1&&capability!=-5) {
						x = i;
						y = j;
						capability = -5;
					}
					else if (a != 0) {//�������
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
//��Ӯλ���ж�-----��Ӯ��Ӯ����1 ----�ܴ����Ӯ����ķ���2��3��2��λ�ñ�3���úã�----���ܷ���0
int willwin(char board[WID][LEN], int wid, int len, int num, int x,int y)
{
	//��Ӯ��Ӯ����1 ----�ܴ����Ӯ����ķ���2��3��2��λ�ñ�3���úã�----���ܷ���0
	int i = 0;
	int j = 0;
	char ch = chessman[1];
	int count = 1;
	//�жϴ������λ�õı�־******************************
	int flag1 = 0;
	int flag2 = 0;

	//�����ж�*****************
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
	//�����ж�****************
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
	//---'/�����ж� x-,y+  &&  x+,y-
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
	//---'\':�ж�  x+,y+  && x-,y-
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

//��ֹ���ʤ��λ���ж�-----//0Ϊ����£�1Ϊ�ض£�2(�����ȣ�,3Ϊ��ǰ�ض�
int fight(char board[WID][LEN], int wid, int len, int num, int x,int y)//int probily[2] 
{
	//����ֹ����(1 �� 2�� ----���ܷ���0
	int i = 0;
	int j = 0;
	int flag = 0;//�ж��Ƿ񷵻�2
	//int x = probily[0];
	//int y = robily[1];
	char ch = chessman[0];
	int count = 1;
	int willcount = 0;
	int willcountsum = 0;//��¼willcount������
	//�����ж�*****************
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
	//�����ж�****************
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
	//---'/�����ж� x-,y+  &&  x+,y-
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
	//---'\':�ж�  x+,y+  && x-,y-
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

//λ����������
int ability(char board[WID][LEN], int wid, int len, int num, int x, int y)
{
	
	int capacity = 0;//�����λ������
	int i = 0;
	int j = 0;
	int geju = len > wid ? len : wid;
	int pointshuanzi = 9*(num +2*geju);//�������ӣ�8�����򣩣�����4������ʱ��Ч
	int defshuanzi=2*num+2*geju;//�з����ӣ������7������
	int myshuanzi=num+geju;//��������
	int flag9 = 0;//�ж��Ƿ���������--������Χ�������˵�����
	int flag1,flag2, flag3, flag4, flag5, flag6, flag7, flag8;//�ж�8�������Ƿ��������

	char ch = chessman[1];
	int count = 1;//��������������
	int count2 = 1;
	int aready = 0;//��������������
	//�����ж�*******************************************
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
	
	//�����ж�****************
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
	//---'/�����ж� x-,y+  &&  x+,y-  ********************************
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
	//---'\':�ж�  x+,y+  && x-,y-  *****************************************************
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
	//��������
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


//�ж���Ӯ����.....����Ӯ�ҵ����ӷ���...............................................................................................
char iswin(char board[WID][LEN], int wid, int len, int num)
{
	int i, j;
	int sum;
	int  vacant = 1;
	//��������֮��Ĳ��Ҳ��޹������ɰ�ע�ͷָ�ֱ�鿴ĳһ����Ĵ���
	//б�����1 ----��/��:len+1 wid-1  
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
	//��δ����жϲ���ȷ��������������������������������-----�Ѹ���
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
	//б�����2----��\��:  wid+1 len+1
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
	//�������
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
	//�������
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







