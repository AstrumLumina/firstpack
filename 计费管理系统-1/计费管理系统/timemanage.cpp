#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"

void timemanagemenu(void)
{
	printf("**************************************************************\n");
	printf("** 1.��ͨ�ϻ�              2.�»�          3.��ҹ          ***\n");
	printf("** 4.�߼�����              5.ǿ���»�      6.ȫ��ǿ���»�  ***\n");
	printf("**                         0.�˳�                          ***\n");
	printf("**************************************************************\n\n");
	printf("����������ѡ��\\>:");
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
			printf("�˳� \n");

			break;
		case START:
			printf("��ʼ�ϻ� \n");

			break;
		case END:
			printf("�»� \n");

			break;
		case ALLNIGHT:
			printf("��ҹ \n");

			break;
		case ADVACE:
			printf(".�߼�����  \n");

			break;
		case KILL:
			printf("ǿ���»� \n");

			break;
		case KILLALL:
			printf("ȫ��ǿ���»� \n");

			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);

}
