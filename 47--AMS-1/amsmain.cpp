#define   _CRT_SECURE_NO_WARNINGS  1

#include"amsmain.h"


//������*********************************************************
enum mainchoice {
	MEXIT, CARDMANAGE, CHARGESTAND, TIME, EXPENSEMANAGE, FIND, ACTIVE, ADMINISTRATOR
};
int main(void) {

	int option = 9;
	do {
		mainmenu();
		option = 9;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case MEXIT:
			printf("�˳� \n");
			break;
		case CARDMANAGE:
			printf("������ \n");
			cardaccountmanage();
			break;
		case CHARGESTAND:
			printf("�Ʒѱ�׼���� \n");
			chargestand();
			break;
		case TIME:
			printf("���»�����\n");
			timemanage();
			break;
		case EXPENSEMANAGE:
			printf("���ù��� \n");
			expensivemanage();
			break;
		case FIND:
			printf("��ѯͳ��\n");
			find();
			break;
		case ACTIVE:
			printf("�����\n");
			active();
			break;
		case ADMINISTRATOR:
			printf("����Ա����\n");
			administrator();
			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);

}
void mainmenu(void) {
	printf("\n\n");
	printf("******************************************************************\n");
	printf("**   1.������           2.�Ʒѱ�׼����        3.���»�����      **\n");
	printf("**   4.���ù���         5.��ѯͳ��            6.�����        **\n");
	printf("**   7.����Ա����                             0.�˳�            **\n");
	printf("******************************************************************\n\n");
	printf("����������ѡ��\\>:");
}

//����1  1.������  ****************************************************
void cardmenu(void) {
	printf("*********************************************************************\n");
	printf("** 1.��ӿ�             2.��ѯ��               3.ע����           ***\n");
	printf("** 4.���Ῠ                                    0.�˳�             ***\n");
	printf("**********************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum cardmanage {
	EXITCARD, ADDCARD, INQUIRYCARD, DELCARD, FREEZECARD
};
void cardaccountmanage(void) {
	int option = 7;
	do {
		cardmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITCARD:
			printf("�˳� \n");
			break;
		case ADDCARD:
			printf("��ӿ� \n");

			break;
		case INQUIRYCARD:
			printf("��ѯ�� \n");

			break;
		case DELCARD:
			printf("ע����\n");

			break;
		case FREEZECARD:
			printf("���Ῠ \n");

			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}


//����2  2.�Ʒѱ�׼���� ****************************************************
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
	EXITCHARGE, FINDSTAND, ADDSTANGE, DELSTANGE, ENABLESTAND, SPECILASTAND, PERSONSSTAND
};
void chargestand(void)
{
	int option = 7;
	do {
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


//����3  3.���»����� ****************************************************
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
	EXITTIME, START, END, ALLNIGHT, ADVACE, KILL, KILLALL
};
void timemanage(void)
{
	int option = 7;
	do {
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

//����4   4.���ù���****************************************************
void expensivemenu(void)
{
	printf("****************************************************************\n");
	printf("** 1.��ֵ              2.�����Ա            3.�˷�         ***\n");
	printf("**                     0.�˳�                               ***\n");
	printf("***************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum expensivechoice {
	EXITEXPENAIVE, ADDEXPENSIVE, BEMEMBER, RETURNEXPENSIVE
};
void  expensivemanage(void)
{
	int option = 7;
	do {
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

//����5  5.��ѯͳ�� ****************************************************
void findmenu(void) {
	printf("******************************************************************************\n");
	printf("** 1.ͳ�Ƹ��µ�����             2.ͳ���ۼ�����       3.ͳ�Ʒ����û�����    ***\n");
	printf("** 4.�鿴ĳһ�û���ʹ������     5.ͳ�Ƹ����Ӫ��     6.ͳ���û���ֵ����    ***\n");
	printf("**                              0.�˳�                                     ***\n");
	printf("******************************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum fincardmanage {
	MONTH=1 , ALL, ANALYSE, ONEANALYSE, DAY, CHARGE
};
void find(void) {
	int option = 7;
	do {
		findmenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case 0:
			printf("�˳� \n");
			break;
		case MONTH:
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

//����6   6.�����    ****************************************************
void active(void) {
	printf("�ù�����δ�����������½⣡\n");
}


//����7  7.����Ա����  ********************************************************
void adminismenu(void)
{

	printf("*********************************************************************************\n");
	printf("** 1.��������Ա            2.ɾ������Ա             3.������ͨ����Ա��Ϣ      ***\n");
	printf("** 4.�޸�������Ա��Ϣ      5.���ù���ԱȨ��         6.��ѯ����Ա              ***\n");
	printf("**                                 0.�˳�                                     ***\n");
	printf("**********************************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum adminichoice {
	EXITADMINIS, ADDADMINIS, DELADMINIS, CHANGADMINIS, MAINADMINIS, PERMISSION, SEEADMINIS
};
void administrator(void)
{
	int option = 7;
	do {
		adminismenu();
		option = 7;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITADMINIS:
			printf("�˳� \n");
			break;
		case ADDADMINIS:
			printf("��������Ա  \n");

			break;
		case DELADMINIS:
			printf("ɾ������Ա   \n");

			break;
		case  CHANGADMINIS:
			printf("������ͨ����Ա��Ϣ\n");

			break;

		case  MAINADMINIS:
			printf("�޸�������Ա��Ϣ \n");

			break;
		case PERMISSION:
			printf("���ù���ԱȨ��\n");

			break;
		case  SEEADMINIS:
			printf("��ѯ����Ա\n");

			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

