#define   _CRT_SECURE_NO_WARNINGS  1

#include"saolei.h"


//ȫ�ֱ��������ڼ�¼��Ϸʱ�䣩
time_t start;
time_t mid;

int main(void)
{
	//��Ϸ��һЩע���������*******************
	printf("  //����һ��ɨ����Ϸ��������ѡ��ϵͳ�Դ�����������Ϸ��Ҳ�����Զ�����Ϸ��������������С���ܳ��� ���ֵ������Դ�����и��ĺ꣩\n");
	printf(" //����ΪΪ���ù��Զ��巽�������Զ��巽��ΪϵͳĬ�Ϸ���\n");
	printf("//��������ڲ��Ϸ����룬������˳���Զ���ǰ�������Ϲ��������Ϊ����,����������Ч\n\n");
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
		printf("\n���������ѡ��\\>:");
		input = 3;
		scanf("%d", &input);
		scanf("%*[^\n]%*c");
		switch (input) {
		case 1:
			printf("��ʼ��Ϸ\\>:\n");
			if (ispropre(wid[hard], len[hard], lei[hard],leibiao,panbiao)) {
				start = time(NULL);
				mid = time(NULL);
				game(wid[hard], len[hard], lei[hard], leibiao, panbiao);
			}
			else {
				printf("\t!!!��Ϸ����������!!������ԭ��1���׵ĸ��������������ĸ����� 2�������ĳ�������������n 3.��ӡ�ķ��Ų�������ͻ ��\n");
				printf("\t������ʾ��������������ԭ����������ڸ���ϵͳ�Դ��淨�ĺ궨�岻�����»������Զ��巽�����ò���ȷ.\n");
				printf("\t          �����ĳ��Ϳ�����ֵ����Ҫ��Դ��������ĺ���ܸı�\n\n");	
				printf("���س����˳�\\>:");
				getchar();
				scanf("%*[^\n]%*c");
			}
			break;
		case 0:
			printf("�˳���Ϸ����\n");
			input = 0;
			break;
		case 2:
			printf("����\n");
			set(wid, len , lei , &hard,&leibiao,&panbiao);
			break;
		default:
			printf("���Ϸ����룡���� ���������룡����\n\n");
			break;
		}
	} while (input);
	return 0;
}
//��ӡ���˵�����
void menu()
{
	printf("\n\n\n");
	printf("**********  ѡ  ��  ��  ��  *******************\n");
	printf("* 1:������Ϸ        2������       0���˳���Ϸ *\n\n");
	printf("***********************************************\n");
}
//��Ϸ���ɺ���
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
		printf("(�����뽫�˴����Ϊ�� �����������ټ�СдӢ���ַ�'y'�ٰ��س�,����ȡ���������������'n'�ٰ��س�;����ֱ����������\n");
		printf("���������� x y:");
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
								printf("��λ�������ף�Ϊ��֪λ�ã������Ч���������������룡����\n");
							}
							else if (prinboard[x - 1][y - 1] == 2) {
								printf("��λ���Ա�ǣ��������������룡����\n");
							}
							else {
								prinboard[x - 1][y - 1] = 2;
								printboard(leiboard, prinboard, wid, len, leibiao, panbiao, lei);
								printf("��ǳɹ���\n");
							}
						}
						else if (ch == 'n') {
							if (prinboard[x - 1][y - 1] == 2) {
								prinboard[x - 1][y - 1] = 0;
								printboard(leiboard, prinboard, wid, len, leibiao, panbiao, lei);
								printf("ȡ����ǳɹ���\n");
							}
							else if (prinboard[x - 1][y - 1] == 1) {
								printf("��λ�������ף�Ϊ��֪λ�ã�ȡ�������Ч���������������룡����\n");
							}
							else {
								printf("��λ��δ��ǣ��������������룡����\n");
							}
						}
						else {
							printf("δ֪���룡�������������룡����\n");
						}
					}
				}
			}
		}
		if (dontpailei) {
			goto laba1;
		}
		if (x > wid || y > len || x == 0 || y == 0 || prinboard[x - 1][y - 1] == 1) {
			printf("���Ϸ����룡���� ���������룡����\n\n");
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
			printf("------���ȵ�����,���ֽ���------\n\n");
		}
		else {
			changeprinbosrd(leiboard, prinboard, wid, len, x - 1, y - 1);
		}
		if (changeresult) {
			if (lei == countrest(prinboard, wid, len)) {
				printf("----��ϲ���ɹ��ų������е���-------\n\n");
				changeresult = 0;//���ڽ�����Ϸ
			}
			else {
				printf("----��ϲ�����γɹ����ף���������-------\n\n");
			}
		
		}
		printboard(leiboard, prinboard, wid, len, leibiao, panbiao,lei);
		printf("\n\n\n");
	} while (changeresult);
	printf("���س�������\\>:");
	getchar();
	scanf("%*[^\n]%*c");
}
//�ж���Ϸ�����Ƿ���������ֹ�Բ��������ݿ�ʼ��Ϸ��ɴ��� 1������ 0��������
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
//���ü��ɺ���
void set(int* wid, int* len, int* lei, int* hard, char* leibiao, char* panbiao)
{
	int input = 11;
	do {
		printf("\n\n********************  ��  ��  ��  ��  *******************************************\n");
		printf("1:����Ϊ�ͼ��Ѷ��淨         2������Ϊ�м��Ѷ��淨          3������Ϊ�߼��Ѷ��淨\n");
		printf("4:����Ϊ�Զ����Ѷ��淨       5���Զ����׵ķ���              6���Զ���δ֪���ķ���\n");
		printf("7:�鿴���ڵ�����             8�����汸�����ڵ�����          9�������ϴε�����\n");
		printf("10:�Զ����Ѷ��淨��������                                   0:�˳�����\n\n");
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
			printf("�����Զ����׵ķ���Ϊ(����Ϊ�ɼ���Ӣ���ַ�)��");
			scanf(" %c", &ch);
			scanf("%*[^\n]%*c");
			if (ch == 0) {
				printf("���������Ϸ����룬���������룡����\n\n");
				goto laba2;
			}
			else if (ch == 'y') {
				printf("'y'Ϊ�׵ı�Ƿ��ţ����������룡\n");
				goto laba2;
			}
			else if (ch == *panbiao) {
				printf("�������������õ��׵ķ�����δ֪���ķ�����ͬ�����������룡����\n");
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
			printf("�����Զ���δ֪���ķ���Ϊ(����Ϊ�ɼ���Ӣ���ַ�)��");
			scanf(" %c", &ch);
			scanf("%*[^\n]%*c");
			if (ch == 0) {
				printf("���������Ϸ����룬���������룡����\n\n");
				goto laba3;
			}
			else if (ch == 'y') {
				printf("'y'Ϊ�׵ı�Ƿ��ţ����������룡\n");
				goto laba3;
			}
			else if (ch == *leibiao) {
				printf("�������������õ�δ֪���ķ��ź��׵ķ�����ͬ�����������룡����\n");
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
			printf("������Ϊ���س������ϴ����õ�����\\>:\n");
			pirnset(wid, len, hard, lei, leibiao, panbiao);
			break;
		case 10:
			setmine(&wid[3], &len[3], &lei[3]);
			break;
		case 0:
			printf("�˳�����\\>\n");
			break;
		default:
			printf("���������Ϸ����룬������ѡ�񣡣���\n\n");
			goto laba1;
		}
	} while (input);
}