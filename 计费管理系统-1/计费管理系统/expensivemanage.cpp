#define   _CRT_SECURE_NO_WARNINGS  1

#include"mainh.h"



void expensivemenu(void)
{
	printf("****************************************************************\n");
	printf("** 1.��ֵ              2.�����Ա            3.�˷�         ***\n");
	printf("**                     0.�˳�                               ***\n");
	printf("***************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum expensivechoice {
	EXITEXPENAIVE, ADDEXPENSIVE,BEMEMBER, RETURNEXPENSIVE
};
void  expensivemanage(void)
{
	int option = 7;
	do {
		system("cls");
		expensivemenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITEXPENAIVE:
			printf("�˳� \n");
			break;
		case ADDEXPENSIVE:
			printf("��ֵ  \n");

			break;
		case BEMEMBER:
			printf("�����Ա \n");

			break;
		case  RETURNEXPENSIVE:
			printf("�˷�\n");

			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);

}
