#pragma once


//�뱣���û������йصĵĺ궨��
#define NAMEMAX  11
#define PHONEMAX  13
#define CARDNUM   15
#define DATEMAX   18 //4��-2��-2��-2ʱ-2�� ��17��

//�����û����ݵĽṹ��
struct user {

	char username[NAMEMAX];//11
	char phone[PHONEMAX];//13
	//char cardnum[CARDNUM];
	char lastplaytime[DATEMAX];//18
	char identify[21];
	char keeyworld[21];

	int cardnum;

	int playfrequent;
	double palytime;//�ܼ���Ϸʱ��
	double restfees;
	double allfees;
	int usertype; //1:��Ծ�û�   2�����û�   3�����û�   4������Ծ�û�     5�������û�  
	int isfreeze; //������
	//�����������
	int isplay;//1;�����ϻ�   2����ҹ    3���߼�����  4.��ϻ�  5.������
	//time_t lastplaytime;
	time_t starttime;

	struct user* next;
};

//����Ա��Ϣ�Ľṹ��
struct adminis {
	char permission[2];
	char id[15];
	char keeyword[21];
	char quesone[21];
	char questwo[21];
	struct adminis* before;
};
