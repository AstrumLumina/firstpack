#define   _CRT_SECURE_NO_WARNINGS  1


#include"cardmanage.h"



//ȫ�ֱ���
extern struct user* head;
extern struct user* last;
extern int alluser;
extern int usersize;
extern int userid;

void cardmenu(void) {
	printf("ע�⣺��ϵͳ����ӵĿ������� int���ܱ�ʾ�Ĵ�С��������ĳЩԭ���ܴ洢�Ŀ������������ \n");
	printf("**********************************************************************\n");
	printf("** 1.��ӿ�             2.��ѯ��              3.ע����             ***\n");
	printf("** 4.�����ⶳ��       5.���������          6.�鿴����Ӷ�ȫ���� ***\n");
	printf("**                      0.�˳�                                     ***\n");
	printf("**********************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum cardmanage {
	EXITCARD,ADDCARD,INQUIRYCARD,DELCARD,FREEZECARD,CHANGEKEEY,PRINALL
};
void cardaccountmanage(void) {

	int option = -1;
	do {
		system("cls");
		cardmenu();
		option = -1;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
		case EXITCARD:
			printf("�˳� \n");
			break;
		case ADDCARD:
			printf("��ӿ� \n");
			addcard();
			break;
		case INQUIRYCARD:
			printf("��ѯ�� \n");
			findcard();
			break;
		case DELCARD:
			printf("ע����\n");
			printf("���ڰ�ȫ���ǣ��ù�����Ҫ����ԱȨ�ޣ�����������������֤���\n");
			//Ȩ�޲鿴
			if (perrmission()) {
				//ɾ����
				deletcard();
			}else{
				printf("�����֤ʧ�ܣ�����\n\n");
			}
			break;
		case FREEZECARD:
			printf("�����ⶳ�� \n");
			freezecard();
			break;
		case CHANGEKEEY:
			printf("5.���������   \n");
			printf("���ڰ�ȫ���ǣ��ù�����Ҫ����ԱȨ�ޣ�����������������֤���\n");
			//Ȩ�޲鿴
			if (perrmission()) {
				//ɾ����
				changekeey();
			}
			else {
				printf("�����֤ʧ�ܣ�����\n\n");
			}
			break;
		case PRINALL:
			printf("�鿴����Ӷ�ȫ���� \n");
			prinallcard();
			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

void addcard(void)
{
	char name[15];
	char phone[15];
	char identify[20];
	int option = 5;
	int flagname = 0;
	int flagid = 0;
	int flagphone = 0;
labainput:
	system("cls");
	printf("�쿨ʱ������Ҫ���Ĳ�����Ϣ��������ʵ��д\\>\n");
	printf("************************************************************\n");
	printf("**   1.����             2.�绰             3.���֤����  ***\n");
	printf("**   4.���沢�˳�       0�����أ������棩                ***\n\n");
	printf("************************************************************\n");
	printf("����������ѡ��\\>:");
	option = 5;
	scanf("%d", &option);
	scanf("%*[^\n]%*c");
	switch (option) {
	case 1:
		printf("��������������\\>:");
		scanf("%s", name);
		flagname = 1;
		scanf("%*[^\n]%*c");
		goto labainput;
		//break;
	case 2:
		printf("���������ĵ绰\\>:");
		scanf("%s", phone);
		flagphone = 1;
		scanf("%*[^\n]%*c");
		goto labainput;
		//break;
	case 3:
		printf("�������������֤����\\>:");
		scanf("%s", identify);
		flagid = 1;
		scanf("%*[^\n]%*c");
		{
			int old = (identify[6]-'0') * 1000 + (identify[7] - '0') * 100 + (identify[8] - '0') * 10 + (identify[9] - '0');
			if (NOWYEAR - old < 18) {
				printf("����δ���꣬δ�ﵽ������Ҫ�󣡣���\n");
				printf("�밴���������\\>:");
				getchar();
				scanf("%*[^\n]%*c");
				return;
			}
		}
		goto labainput;
		//break;
	case 4:
		printf("�����˳�\n");
		if (flagname && flagid && flagphone) {
			initialcard(name, phone, identify);
		}
		else {
			printf("������������������Ϣ������\n");
			printf("�밴���������\\>:");
			getchar();
			scanf("%*[^\n]%*c");
			goto labainput;
		}
		break;
	case 0:
		printf("�����˳�(ȡ����ӿ���\n");
		break;
	default:
		printf("���ͷ����룬�����������룡����\n\n");
		goto labainput;
	}
	
}

void  initialcard(char* name, char* phone, char* identifyid)
{
	
		char keeyword[20] = "";
	labekeeyword:
		printf("����Ϊ���Ŀ���������(����5���ַ���С��19���ַ���\\>;");
		scanf("%s", keeyword);
		scanf("%*[^\n]%*c");
		int len = strlen(keeyword);
		if (len > 18 || len < 6) {
			 printf("\n�������벻����Ҫ������������!!!\n\n");
			goto labekeeyword;	
		}
		//ϵͳ���俨�ţ�
		++userid;
		++alluser;
		printf("\n��ϲ�������ɹ������Ŀ���Ϊ: %06d\n\n", userid);
		printf("�����μ��Լ��Ŀ��ţ�����,��������ɼ���\n");
		getchar();
		scanf("%*[^\n]%*c");
		//�洢��
		if (last->next = (struct user*)malloc(usersize)) {
			last = last->next;
			last->next = NULL;
			strcpy(last->username, name);
			strcpy(last->phone, phone);
			strcpy(last->identify, identifyid);
			strcpy(last->keeyworld, keeyword);
			last->cardnum = userid;
			last->lastplaytime[0]='F';
			last->lastplaytime[1] = '\0';
			last->playfrequent = 0;
			last->palytime = .0;
			last->restfees = .0;
			last->allfees = .0;
			last->usertype = 2;
			last->isplay = 0;
			last->isfreeze = 0;
			printf("��Ϣ¼��ɹ�,�����ڿ���ʹ�����ſ��ϻ���\n");

	    }
	    else {
		    printf("�ڴ�����ʧ�ܣ����������������򣡣���\n");
	    }
}

//ɾ������
void deletcard(void) 
{
	
	int cardtodel = 0;
	printf("������Ҫɾ���Ŀ���(�����ǿ��ţ��� ����0 ���� �������֤�Ų����ҿ��ţ�\\>:");
	scanf("%d", &cardtodel);
	scanf("%*[^\n]%*c");
	if (cardtodel==0) {
		printf("����");
		return;
	}
	struct user* todel = head;
	//struct user* beforedel = head;
	while (todel->next) {
		//beforedel = todel;
		if ((todel->next)->cardnum == cardtodel) {
			break;
		}
		todel = todel->next;
	}
	if (todel->next) {
		printf("\n����ȷ����ע��ǰ�Ѿ��������˷ѵȹ������˿�һ��ע���������޷��ָ�\n\n");
		char keey[20];
		int errornum = 0;
	labainputkeey:
		printf("Ϊ�˱�֤��ȫ����������ÿ��ŵ�����(��������Ĵ��Զ��˳���\\>:");
		scanf("%s", keey);
		scanf("%*[^\n]%*c");
		if (0 == strcmp(keey, (todel->next)->keeyworld)) {
			realdelonecard(todel);
		}
		else {
			++errornum;
			if (errornum % 4) {
				printf("�������������  %d  �λ���  **********\n\n", 4 - errornum);
				goto labainputkeey;
			}
			printf("\n\n\n����������࣬Ϊ�����û���ȫ���Զ��˳�\n\n");
		}
	}
	else {
		printf("�����ڸÿ��ţ�����\n");
	}
}

void realdelonecard(struct user* beforetodel) {
	if (beforetodel->next->next==NULL) {
		last = beforetodel;
	}
	struct user* todel = beforetodel->next;
	beforetodel->next = (beforetodel->next)->next;
	free(todel);
	--alluser;
	printf("ע���ɹ���\n");
}
void findcard(void) {
	struct user* beforefind = NULL;
	int input = -1;
	//ѡ��˵�
labamenu:
	system("cls");
	{
		printf("\n*****************************************************************\n");
		printf("***  1.�����Ų�ѯ��                      2.�����֤��ѯ��     ****\n");
		printf("***  3.�����ֲ�ѯ��                      4.�鿴ȫ����         ****\n");
		printf("***                        0.����                             ****\n");
		printf("******************************************************************\n");
	}
labainput:
	printf("����������ѡ��\\>:");
	input = -1;
	scanf("%d", &input);
	scanf("%*[^\n]%*c");
	switch (input){
	case 1:
		printf("1.�����Ų�ѯ�� \n");
		beforefind = findbynum();
		break;
	case 2:
		printf(" 2.�����֤��ѯ��\n");
		beforefind = findbyidentify();
		break;
	case 3:
		printf("3.�����ֲ�ѯ�� \n");
		beforefind = findbyname();
		break;
	case 4:
		printf("4.�鿴ȫ���� \n");
		prinallcard();
		goto labamenu;
		break;
	case 0:
		printf(" 0.���� \n");
		break;
	default:
		printf("���ͷ����룬����������!!!\n");
		goto labainput;
	}
	//�жϲ���ӡ���
	if(input) {
		if (beforefind) {
			system("cls");
			putchar('\n');
			printf("1:��Ծ�û�|2�����û�|3�����û�|4������Ծ�û�|5�������û�|1;�����ϻ�|2����ҹ|3���߼�����|4.��ϻ�|1.������ \n");
			printf(" ����    �û���       �绰        �û�����|ʹ�ô���|�Ƿ����ϻ�| �ϴ�ʹ��    |�Ƿ񱻶���|�ۼ�ʹ��ʱ��  �ۼƳ�ֵ    ��� \n");
			prinonecard(beforefind);
			int choice = 1;
			printf(" ������� ��  0: �˳��鿴     �������鿴������Ϣ ��\\>:");
			scanf("%d", &choice);
			scanf("%*[^\n]%*c");
			if (choice) {
				//��ӡ��־��¼�����֤��

				//��ͣ
				{
					printf("��������˳��鿴\\>:");
					getchar();
					scanf("%*[^\n]%*c");
				}
			}
		}
		else {
			printf("���Ϸ�����򲻴�����Ҫ���ҵ�����!!!\n");
			printf("�����������\\>:");
			getchar();
			scanf("%*[^\n]%*c");
		}
	}
}


struct user* findbynum(void) {
	int cardnum = -1;
	printf("�����뿨��( 6 λ�� ,���͹涨��������ܵ��´���\\>:");
	scanf("%d", &cardnum);
	scanf("%*[^\n]%*c");
	if (cardnum < 1) {
		//printf("���Ϸ����룡����\n");
		return NULL;
	}
	struct user* toverify = head;
	//struct user* before = head;
	while (toverify->next) {
		if (toverify->next->cardnum == cardnum) {
			return toverify;
		}
		//before = toverify;
		toverify = toverify->next;
	}
	//if (toverify->cardnum == cardnum) {
	//	return before;
	//}
	return NULL;
}
struct user* findbyidentify(void) {
	char identify[20] = {};
	printf("�������֤����:\\>:");
	scanf("%s", identify);
	scanf("%*[^\n]%*c");

	struct user* toverify = head;
	//struct user* before=head;
	while (toverify->next) {
		if (strcmp(toverify->next->identify, identify) == 0) {
			return toverify;
		}
		//before = toverify;
		toverify = toverify->next;
	}
	//if (strcmp(toverify->identify, identify) == 0) {
		//return before;
	//}
	return NULL;
}
struct user* findbyname(void) {
	char identify[20] = {};
	printf("�������û���\\>:");
	scanf("%s", identify);
	scanf("%*[^\n]%*c");

	struct user* toverify = head;
	//struct user* before=head;
	while (toverify->next) {
		if (strcmp(toverify->next->username, identify) == 0) {
			return toverify;
		}
		//before = toverify;
		toverify = toverify->next;
	}
	//if (strcmp(toverify->username, identify) == 0) {
	//	return before;
	//}
	return NULL;
}

void prinallcard(void) {
	system("cls");
	putchar('\n');
	printf("1:��Ծ�û�|2�����û�|3�����û�|4������Ծ�û�|5�������û�|1;�����ϻ�|2����ҹ|3���߼�����|4.��ϻ�|1.������ \n");
	printf(" ����    �û���       �绰        �û�����|ʹ�ô���|�Ƿ����ϻ�| �ϴ�ʹ��    |�Ƿ񱻶���|�ۼ�ʹ��ʱ��  �ۼƳ�ֵ    ��� \n");
	struct user* beforprin = head;
	while (beforprin->next) {
		prinonecard(beforprin);
		beforprin = beforprin->next;
	}
	printf("��������˳��鿴\\>:");
	getchar();
	scanf("%*[^\n]%*c");
}
void prinonecard(struct user* toprin)
{
	toprin = toprin->next;
	printf(" %06d  %-11s  %-13s  %-6d  %-7d  %-7d    %-18s %-3d %-12lf  %-12lf  %-12lf\n",toprin->cardnum,toprin->username,
		toprin->phone, toprin->usertype,toprin->playfrequent, toprin->isplay, toprin->lastplaytime, toprin->isfreeze,toprin->palytime,toprin->allfees, toprin->restfees);
}

void freezecard(void) {
	printf("\n��ʾ���ò�����Ҫ��Ҫ�����Ŀ��ţ�����֪���ɷ��ز�ѯ��\\>:\n\n");
	struct user* tofreeze = findbynum();
	if (tofreeze) {
		tofreeze = tofreeze->next;
		int choice = 1;
		if (tofreeze->isfreeze) {
			printf("�Ƿ�ȷ���ⶳ�ÿ�(0:��  �������ǣ�\\>:");
		}
		else {
			printf("�Ƿ�ȷ������ÿ�(0:��  �������ǣ�\\>:");
		}
		scanf("%d", &choice);
		scanf("%*[^\n]%*c");
		if (choice) {
			tofreeze->isfreeze = !(tofreeze->isfreeze);
			printf("�����ɹ���\n");
		}
		else {
			printf("��ȡ��������\n");
		}
	}
	else {
		printf("�����ڸÿ���!!!\n");
		
	}

}
void changekeey(void) {
	int input = -1;
	struct user* tochangekeey = NULL; 
	printf("\n\nѡ��\\>:\n");
	printf(" 1: �鿴������     2�����Ŀ�����      ����������");
	scanf("%d", &input);
	scanf("%*[^\n]%*c");
	if (input == 1) {
		tochangekeey = findbyidentify();
		if (tochangekeey) {
			printf("\n�ÿ�������Ϊ\\>: %s \n", tochangekeey->next->keeyworld);
			printf("��������˳��鿴\\>:");
			getchar();
			scanf("%*[^\n]%*c");
		}
	}
	else if (input == 2) {
		tochangekeey = findbyidentify();
		if (tochangekeey) {
			tochangekeey = tochangekeey->next;
			char keey[21] = "";
		labainputkeey:
			printf("������������\\>:");
			scanf("%s", keey);
			scanf("%*[^\n]%*c");
			if (strlen(keey) > 20) {
				printf("�������벻�͹涨��������,����������!!!\n");
				goto labainputkeey;
			}
			strcpy(tochangekeey->keeyworld, keey);
			printf("��������ɹ���������\n");
		}
	}
	else {
		printf("����\\>\n");
		return;
	}
	printf("δ�ҵ�����Ϣ������ȷ����Ϣ�Ƿ��д��󣡣���\n");
	return;
}