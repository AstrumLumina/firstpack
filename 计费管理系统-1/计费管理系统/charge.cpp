#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"



void chargestandmenu(void)
{
	printf("**********************************************************************************\n");
	printf("** 1.��ѯȫ���Ʒѱ�׼              2.�����Ʒѱ�׼             3.ɾ����׼       ***\n");
	printf("** 4.ѡ�����ñ�׼���������ˣ�    5.��ĳ��ʵ�������׼       6.��ѯĳ�˵ı�׼ ***\n"); 
	printf("**                                 0.�˳�                                      ***\n");
	printf("**********************************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum chargechoice {
	EXITCHARGE,FINDSTAND,ADDSTANGE,DELSTANGE,ENABLESTAND,SPECILASTAND,PERSONSSTAND
};
void chargestand(void)
{
	int option = 7;
	do {
		system("cls");
		chargestandmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITCHARGE:
			printf("�˳� \n");
			break;
		case FINDSTAND:
			printf("��ѯȫ���Ʒѱ�׼  \n");

			break;
		case ADDSTANGE:
			printf("�����Ʒѱ�׼ \n");

			break;
		case DELSTANGE:
			printf("ѡ�����ñ�׼���������ˣ�\n");

			break;
		case SPECILASTAND:
			printf("��ĳ��ʵ�������׼ \n");

			break;
		case PERSONSSTAND:
			printf("��ѯĳ�˵ı�׼\n");

			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}