#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"

void findmenu(void) {
	printf("******************************************************************************\n");
	printf("** 1.ͳ�Ƹ��µ�����             2.ͳ���ۼ�����       3.ͳ�Ʒ����û�����    ***\n");
	printf("** 4.�鿴ĳһ�û���ʹ������     5.ͳ�Ƹ����Ӫ��     6.ͳ���û���ֵ����    ***\n");
	printf("**                              0.�˳�                                     ***\n");
	printf("******************************************************************************\n\n");
	printf("����������ѡ��\\>:");
}

enum cardmanage {
	MOTH=1,ALL,ANALYSE,ONEANALYSE,DAY,CHARGE
};
void find(void) {
	int option = 7;
	do {
		system("cls");
		findmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case 0:
			printf("�˳� \n");
			break;
		case MOTH:
			printf("ͳ�Ƹ��µ����� \n");

			break;
		case ALL:
			printf("ͳ���ۼ����� \n");

			break;
		case ANALYSE:
			printf("ͳ�Ʒ����û�����\n");

			break;
		case ONEANALYSE:
			printf("�鿴ĳһ�û���ʹ������  \n");

			break;
		case DAY:
			printf("ͳ�Ƹ����Ӫ�� \n");

			break;
		case CHARGE:
			printf("ͳ���û���ֵ���� \n");

			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}
