#define   _CRT_SECURE_NO_WARNINGS  1
//����һ����������Ϸ�Ĵ���
//�����ϷĬ��ʱ3*3�����̵������壬��Ҫ�ı��淨�����Ե�ͷ�ļ������̴�С�ĺ�

//�����ļ�
#include"game.h"

//���˵�ѡ�����  ȫ�ֱ���
int option;
//Ĭ�����̴�С(3*3)	
int wid = INITIALWID;
int len = INITIALLEN;
int num = NUM;//������������
int first = 0;//�������
int advance = HARD;//l��Ϸ�Ѷ�

//��������
char CHESSMAN


//��Ϸ���ɺ���
void game()
{
	//��ά��������������
	char board[WID][LEN];

	//��ʼ������
	initialboard(board, wid, len);
	//��ӡ���̺�����
	prinboard(board, wid, len);
	//��ʼ��������
	char win=0;//����жϽ��
	//0:�������  ˭�ķ��Ŵ���˭Ӯ  ' '=32:����ƽ��
	if (first) {
		goto laba1;
	}
	while (1) {
		//�����
		player(board, wid,len);
		prinboard(board, wid, len);
		win=iswin(board, wid, len, num);
		if (win ) { break; }
		//������
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
		printf("----ƽ��--------\n");
	}
	else if (win - chessman[0] == 0) {
		printf("-----��Ӯ��----\n");
	}
	else if(win-chessman[1]==0) {
		printf("---����Ӯ��----\n");
	}
	else {
		printf("δ֪�����win =%c)\n", win);
		printf("#%c#%d#\n", win, win);
	}
	printf("�����ⰴ����������\\>:");
	scanf("%*[^\n]%*c");
	getchar();

}

//��ʾ���˵�����
void menu()
{
	static int inputerror = 1;
	int a = 0;
laba2:
	printf("\noption menue\\>:\n");
	printf("*********  ѡ  ��  ��  ��  ************************\n");
	printf("1:paly \t \t 2:���� \t \t 3:exit\n\n");
	printf("***************************************************\n\n");
laba1:
	printf("ע�⣺���ڷ��������룬ֻȡ��һ����������\n");
	printf("please enter your chioce\\>:");
	scanf("%d", &a);
	scanf("%*[^\n]%*c");
	if (a == 3 || a == 2 || a == 1) {
		option = a;
	}
	else  {
		printf("���벻���Ϲ涨��������������\n");
		++inputerror;
		if (inputerror % 20 == 0) {
			printf("\n\n\n��������������  ��ֹ  ����  �� ���� �ַ�����������������\n");
			printf(".....������δ����������������ַ����Խ������.....\n");
			getchar();
			goto laba2;
		}
		else {
			goto laba1;
		}

	}
}


//������
int main()
{
	//��Ϸ����******************************************
	printf("  //����һ����������Ϸ�Ĵ���\n\
 //�����ϷĬ��ʱ3*3�����̵������壬��Ҫ�ı��淨���Ե�����������ģ�Ҳ���Ե�ͷ�ļ��޸ĺ꣨���Ըı��������Ĵ�С��\n\
//�������ԣ�����Ϸ 4 ����ʱ�Ѷ�����Ƽ����̴�С��( 9 * 13 )\n");
	//***************************************************
	do {
		menu();
		switch (option)
		{
		case 2:
			set();
			option = 1;//option�ڱ��õ�����ֹ�ı�
			break;
		case 1:
			printf("start game...\n");
			srand((unsigned int)time(0));
			game();
			option = 1;//option�ڱ��õ�����ֹ�ı�
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

//��Ϸ�������ݱ��ݺ���
void beifen()
{
	FILE* fp = NULL;
	if (fp = fopen("benfen,txt", "w")) {
		fprintf(fp, "%d %d %d %d %d %c %c", wid, len, num, first, advance,chessman[0],chessman[1]);
		if (fclose(fp)) {
			printf("�����ļ��ر�ʧ�ܣ���\n");
			fp = NULL;
		}
		else {
			printf("������ɣ�\n");
			fp = NULL;
		}
	}
	else {
		printf("���ݷ��ļ���ʧ�ܣ���\n");
	}
}

//��Ϸ�������ݼ��غ���
void load()
{
	FILE* fp = NULL;
	if (fp = fopen("benfen,txt", "r")) {
		fscanf(fp, "%d %d %d %d %d %c %c", &wid, &len, &num, &first, &advance,&chessman[0],&chessman[1]);
		if (fclose(fp)) {
			printf("�����ļ��ر�ʧ�ܣ���\n");
			fp = NULL;
		}
		else {
			printf("������ɣ�\n");
			fp = NULL;
		}
		
	}
	else {
		printf("���ݷ��ļ���ʧ�ܣ���\n");
	}
}


//��ӡ��������
void prinset()
{
	printf("����Ϊ��������\\>\n");
	printf("*************************************************************************************************************\n");
	printf("1: ���̴�С: %d*%d      2���淨����: %d����       3:���̷���:��ң�%c ���ԣ�%c\n\n", wid, len, num, chessman[0], chessman[1]);
	printf("4:�������:");
	if (first) {
		printf("����%7c",' ');
	}
	else {
		printf("���%7c",' ');
	}
	printf("5:��Ϸ�Ѷȣ�");
	if (advance) {
		printf(" �� \n\n");
	}
	else {
		printf("ɵ��ģʽ  \n\n");
	}
	printf("**************************************************************************************************************\n\n");
	getchar();
	printf("���س����˳��鿴\\>:");
	char ch;
	while ((ch = getchar()) - '\n') { ; }
	putchar('\n');
}