#define   _CRT_SECURE_NO_WARNINGS  1

#include"saolei.h"


//ȫ�ֱ��������ڼ�¼��Ϸʱ�䣩
extern time_t start;
extern time_t mid;

//*************************************************************************************
//��ʼ�����׺���
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
//��ʼ����ӡ���̺���
void initialprinboard(int prinboard[WID][LEN], int wid, int len)
{
	int i, j;
	for (i = 0; i < wid; ++i) {
		for (j = 0; j < len; ++j) {
			prinboard[i][j] = 0;
		}
	}
}
//�鿴ʣ��δ֪������
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
//�鿴ָ����Χλ���м����׵ĺ���
char countlei(char leiboard[WID][LEN], int  wid, int  len, int x, int y)
{
	int count = 0;
	//��
	if (y - 1>=0) {
		if (leiboard[x][y-1] - '0'==0) {
			++count;
		}
	}
	//��
	if (y + 1 < len) {
		if (leiboard[x][y+1] - '0'==0) {
			++count;
		}
	}
	//��
	if (x - 1 >=0) {
		if (leiboard[x-1][y] - '0'==0) {
			++count;
		}
	}
	//��
	if (x + 1 < wid) {
		if (leiboard[x+1][y] - '0'==0) {
			++count;
		}
	}
	//����
	if (y + 1 < len&&x-1>=0) {
		if (leiboard[x-1][y+1] - '0'==0) {
			++count;
		}
	}
	//����
	if (y + 1 < len&&x+1<wid) {
		if (leiboard[x+1][y+1] - '0'==0) {
			++count;
		}
	}
	//����
	if (y - 1 >=0&&x-1>=0) {
		if (leiboard[x-1][y-1] - '0'==0) {
			++count;
		}
	}
	//����
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
//���׽��״̬��¼���º���  
void changeprinbosrd(char leiboard[WID][LEN], int prinboard[WID][LEN], int wid, int len, int x, int y)
{
	prinboard[x][y] = 1;
	if (leiboard[x][y] - ' ') {
		return;
	}
	else {
		//��
		if (y - 1 >= 0&&!prinboard[x][y-1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x, y - 1);
		}
		//��
		if (y + 1 < len && !prinboard[x][y + 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x, y + 1);
		}
		//��
		if (x - 1 >= 0 && !prinboard[x-1][y ]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y);
		}
		//��
		if (x + 1 < wid && !prinboard[x+1][y]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x + 1, y);
		}
		//����
		if (y + 1 < len && x - 1 >= 0 && !prinboard[x-1][y + 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y + 1);
		}
		//����
		if (y + 1 < len && x + 1 < wid && !prinboard[x+1][y + 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x + 1, y + 1);
		}
		//����
		if (y - 1 >= 0 && x - 1 >= 0 && !prinboard[x-1][y - 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y - 1);
		}
		//����
		if (y - 1 >= 0 && x + 1 < wid && !prinboard[x+1][y - 1]) {
			changeprinbosrd(leiboard, prinboard, wid, len, x + 1, y - 1);
		}
	}
}
//���̴�ӡ����
void printboard(char leiboard[WID][LEN], int prinboard[WID][LEN], int wid, int len, char leibiao,char panbiao,int lei)
{
	int i, j;
	int flag = 0;
	if (leibiao - ' ') {
		flag = 1;
	}
	//��ӡ��źͷ���
	for (j = 1; j <= len; ++j) {
		printf("%2d",j/10);
	}
	putchar('\n');
	for (j = 1; j <= len; ++j) {
		printf("%2d", j %10);
	}
	printf("----> X\n");
	//��ӡ�߿������
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
	//��ӡ����
	for (j = 0; j < len; ++j) {
		printf("  ");
	}
	printf("\\|/ Y\n");
	//��ӡʱ�������
	time_t  end = time(NULL);
	printf("���ֹ��� %d ����       ���ϴ�������ʱ %.3lf ��;         �����ܹ����� %.0lf ��;\n",lei,difftime(end,mid),difftime(end,start));
	mid = end;
}
//**********************************************************************

//������غ���*************************************************************************

//��ӡ���ú���
void pirnset(int *wid,int *len,int *hard,int *lei,char *leibiao,char *panbiao)
{
	printf("********************   ��  ��  ��  ��  ��  ��  ��   *******************************************\n");
	printf("1:�ͼ��Ѷ��淨������: %d  ��ȣ�%d  ������%d ��",*len,*wid,*lei);
	if (*hard == 0) { printf("( �������ڵ��淨)"); }
	putchar('\n');
	printf("2:�м��Ѷ��淨������: %d  ��ȣ�%d  ������%d ��", *(len+1), *(wid+1), *(lei+1));
	if (*hard == 1) { printf("( �������ڵ��淨)"); }
	putchar('\n');
	printf("3:�߼��Ѷ��淨������: %d  ��ȣ�%d  ������%d ��", *(len + 2), *(wid + 2), *(lei + 2));
	if (*hard == 2) { printf("( �������ڵ��淨)"); }
	putchar('\n');
	printf("4:�Զ����Ѷ��淨������: %d  ��ȣ�%d  ������%d ��", *(len + 3), *(wid + 3), *(lei + 3));
	if (*hard == 3) { printf("( �������ڵ��淨)"); }
	putchar('\n');
	printf("5.�����׵ķ���Ϊ��%c \n", *leibiao);
	printf("6.����δ֪���ķ���Ϊ��%c\n", *panbiao);
	printf("7.������󳤶�Ϊ %d ,�����󳤶�Ϊ %d (ֻ�ɵ�Դ�������޸ĺ꣩\n", LEN, WID);
	printf("*********************************************************************************\n\n");
	printf("���س����˳��鿴\\>:");
	getchar();
	scanf("%*[^\n]%*c");
}
//�������ú���
void beifenset(int wid, int len, int lei, int hard, char leibiao, char panbiao)
{
	FILE *fp = NULL;
	if ( fp = (fopen("set.txt", "w") ) ){
		fprintf(fp, "%d %d %d %d %c %c", wid, len, lei, hard, leibiao, panbiao);
		if (fclose(fp)) {
			printf("�������õ��ļ��ر�ʧ�ܣ�����\n");
		}
		fp = NULL;
		printf("�������!\n\n");
	}
	else {
		printf("�������õ��ļ���ʧ�ܣ�����\n");
		fp = NULL;
	}
}
//�����ϴ����ú���
void loadset(int* wid, int* len, int* lei, int* hard, char* leibiao, char* panbiao)
{
	FILE* fp = NULL;
	if (fp = (fopen("set.txt", "r"))) {
		fscanf(fp, "%d %d %d %d %c %c", wid, len, lei, hard, leibiao, panbiao);
		if (fclose(fp)) {
			printf("�������õ��ļ��ر�ʧ�ܣ�����\n");
		}
		fp = NULL;
		printf("�������!\n\n");
	}
	else {
		printf("�������õ��ļ���ʧ�ܣ�����\n\n\n");
		fp = NULL;
	}
}
//�Զ����淨��������
void setmine(int* wid, int* len, int* lei)
{
	int option = 4;
	int input = 0;
	do {
		printf("\n\n*************************  ��  ��  ��  ѡ  ��  **********************************************\n");
		printf("1:�Զ��������Ŀ�   2���Զ��������ĳ�    3���Զ����������׵ĸ���     0:�˳��Զ��巽������\n\n");
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
			printf("�����Զ��������Ŀ�Ϊ(�������1���Ҳ����� %d)��", WID);
			scanf(" %d", &input);
			scanf("%*[^\n]%*c");
			if (input <= 0 || input > WID) {
				printf("���������Ϸ����룬���������룡����\n\n");
				goto laba2;
			}
			*(wid + 3) = input;
			printf("������ʾ���뼰ʱ�����Զ����׵ĸ������Է�ֹ�����׵ĸ�����������Ĵ��󣡣�\n");
			break;
		case 2:
		laba3:
			input = 0;
			printf("�����Զ��������ĳ�Ϊ(�������1���Ҳ����� %d)��", LEN);
			scanf(" %d", &input);
			scanf("%*[^\n]%*c");
			if (input <= 0 || input > LEN) {
				printf("���������Ϸ����룬���������룡����\n\n");
				goto laba3;
			}
			*(len + 3) = input;
			printf("������ʾ���뼰ʱ�����Զ����׵ĸ������Է�ֹ�����׵ĸ�����������Ĵ��󣡣�\n");
			break;
		case 3:
		laba4:
			option = (*(wid + 3)) * (*(len + 3));//���ñ���
			printf("�����Զ����׵ĸ���Ϊ(�������1����С�� %d)��", option);
			scanf(" %d", &input);
			scanf("%*[^\n]%*c");
			if (input <1 || input >= option) {
				printf("���������Ϸ����룬���������룡����\n\n");
				goto laba4;
			}
			*(lei + 3) = input;
			option = 1;//��ԭ����,��ֹΪ0ʱͻȻ�˳�����
			break;
		case 0:
			printf("�˳��Զ��巽������\n");
			break;
		default:
			printf("���������Ϸ����룬������ѡ�񣡣���\n\n");
			goto laba1;
		}
	} while (option);
}