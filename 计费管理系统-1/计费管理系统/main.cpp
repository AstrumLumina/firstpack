#define   _CRT_SECURE_NO_WARNINGS  1
#define  _CRT_SECURE_NO_DEPRECATE 1


#include"mainh.h"
#include"structuser.h"

//struct user {
//	
//	char username[NAMEMAX];
//	char phone[PHONEMAX];
//	char cardnum[CARDNUM];
//	char lastplaytime[DATEMAX];
//	char identify[20];
//	//char keeyworld[20];
//
//
//	int playfrequent;
//	int palytime;
//	int restfees;
//	int allfees;
//	int isplay;
//	int usertype;//1:��Ծ�û�   2�����û�   3�����û�   4������Ծ�û�     5�������û�
//	//time_t lastplaytime;
//	time_t starttime;
//
//	struct user* next;
//};


//ȫ�ֱ���
struct user* head=NULL;
struct user* last = NULL;
int alluser = 0;//�û�����
int usersize=0;
int userisplay = 0;
int userid;
int adminiss = -1;
struct adminis* mainadministrator;//ͷָ��
struct adminis* nowadministrator;
struct adminis* lastadministrator;
//char administrators[5][30] = { "","","" };

enum mainchoice {
	MEXIT, CARDMANAGE, CHARGESTAND, TIME, EXPENSEMANAGE, FIND, ACTIVE, ADMINISTRATOR
};
int main(void) {
	{
		printf("���� �ó����������У����ֹ��ܻ������ƣ��Ҵ���һЩ��֪���⣬����ȱ�ٶ�����ļ�⣬\n\
����ʹ����Ҫ��ʹ�ø�ϵͳ���������������ַ����ȣ��Ա������\n\
�ó��������ֻ���������˳��������ǻ��Զ����汸�����ݣ�Ϊ�˷�ֹ���ݶ�ʧ������ֱ�ӹرոó���\n");
		printf("�����������\\>:");
		//getchar();
		scanf("%*[^\n]%*c");
	}
	firstinitial();
	firstaddadminid();

	int option = -1;
	do {
		system("cls");
		mainmenu();
		option = -1;
		scanf("%d", &option);
		scanf("%*[^\n]%*c");
		switch (option) {
			case MEXIT:
				printf("�˳� \n");
				if (userisplay > 0) {
					int a = 0;
					printf("Ŀǰ������������ϻ��У�����ȷȻ�Ƿ�رո�ϵͳ���ص�ֻ�����û����ݶ�ʧ��(0:��  �������ǣ�\\:");
					scanf("%d", &a);
					scanf("%*[^\n]%*c");
					if (!a) {
						option = -1;
					}
					else {
						printf("\n\n���ڰ�ȫ���ǣ�������Ҫ��֤�������\\>\n\n");
						a = perrmission();
						if (!a) {
							printf("�����֤ʧ�ܣ��޷��˳���ϵͳ\n");
							option = -1;
						}
					}
				}
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
		//loaduserdate();
	} while(option);
	//�������ݺ��˳�
	loaduserdate();
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

//�û�ʹ��������غ���
// 0.����
// 1.����
// 2.��ֵ
// 3.�˷�
// 4.��ͨ�ϻ�
// 5.��ҹ�ϻ�
// 6.��ϻ�
// 7.
// 
//��������û�ʹ�ü�¼


//��ӡ�û���ʹ�ü�¼����Ļ
void prinlog(char* cardnum) {

}
void firstinitial(void) {
	//��ʼ�����û�����
	usersize = sizeof(struct user);
	if (head = (struct user*)malloc(usersize)) {
		head->next = NULL;
		last = head;
	}
	else {
		printf("δ�ܳɹ������ڴ棬�����˳�������������!!!\n");
	}
	FILE* fp = NULL;
	if (fp = fopen("load.txt", "r")) {
		fscanf(fp, "%d %d %d ", &alluser, &userid,&adminiss);
		int num = alluser;
		while (num--) {
			if (last->next = (struct user*)malloc(usersize)) {
				last = last->next;
				fscanf(fp, "%s  %s  %s  %s  %s  %d  %d %lf  %lf  %lf  %d  %d ",
					  last->username, last->phone, last->lastplaytime, last->identify, last->keeyworld,
					  &last->cardnum, &last->playfrequent, &last->palytime, &last->restfees, &last->allfees, &last->usertype,&last->isfreeze);
				last->isplay = 0;
			}
			else {
				perror("malloc:");
				printf("������������������������������\n");
			}
		}
		last->next = NULL;
		fclose(fp);
		fp = NULL;
	}
	else {
		perror("fopen:");
	}
	
}

void loaduserdate(void) 
{
     //����Ӵ�û�����
	{
		FILE* fp = NULL;
		if (fp = fopen("load.txt", "w")) {
			fprintf(fp, "%d %d %d\n", alluser, userid, adminiss);
			struct user* toload = head->next;
			while (toload) {
				fprintf(fp, "%s  %s  %s  %s  %s  %d  %d  %lf  %lf  %lf  %d  %d\n",
					toload->username, toload->phone, toload->lastplaytime, toload->identify, toload->keeyworld,
					toload->cardnum, toload->playfrequent, toload->palytime, toload->restfees, toload->allfees, toload->usertype,toload->isfreeze);
				toload = toload->next;
			}
			fclose(fp);
			fp = NULL;
		}
		else {
			perror("fopen:");
		}
	}
	
	//���ݹ���Ա������
	if (adminiss) {
		int adminisnum = adminiss;
		FILE* fp = NULL;
		if (fp=fopen("adminis.txt", "w")) {
			struct adminis* toadd = mainadministrator;
			while (adminisnum--) {
				toadd = toadd->before;
				fprintf(fp, "%s\n", toadd->permission);
				fprintf(fp, "%s\n", toadd->id);
				fprintf(fp, "%s\n", toadd->keeyword);
				fprintf(fp, "%s\n", toadd->quesone);
				fprintf(fp, "%s\n", toadd->questwo);
			}
			toadd->before = NULL;
			fclose(fp);
			fp = NULL;
		}
		else {
			perror("fopen");
		}
	}
}

