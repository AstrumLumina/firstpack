#define   _CRT_SECURE_NO_WARNINGS  1
#define  _CRT_SECURE_NO_DEPRECATE 1


#include"administrator.h"



extern  int  adminiss;
extern struct adminis* mainadministrator;
extern struct adminis* nowadministrator;
extern struct adminis* lastadministrator;
//extern char administrators[5][30];


void adminismenu(void)
{
	printf("\n\nע��: Խ����ӵĹ���ԱȨ��Խ�ߣ��߼�����Ա����ɾ���ͼ�����Ԫ���˺�,���ֻ����5������Ա������\n\n");
	printf("***************************************************************************************\n");
	printf("** 1.��������Ա            2.ɾ������Ա             3.������������Ա��Ϣ           ***\n");
	printf("** 4.�޸ĵ�ǰ����Ա��Ϣ    5.���ù���ԱȨ��         6.�鿴��������¼����Ա�˺�     ***\n");
	printf("**                         0.�˳�                                                  ***\n");
	printf("**************************************************************************************\n\n");
	printf("����������ѡ��\\>:");
}
enum adminichoice {
	EXITADMINIS,ADDADMINIS,DELADMINIS,CHANGADMINIS,MAINADMINIS,PERMISSION,SEEADMINIS
};
void administrator(void)
{
	int option = 7;
	do {
		system("cls");
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
			addoneadminis();
			break;
		case DELADMINIS:
			printf("ɾ������Ա   \n");
			deladminis();
			break;
		case  CHANGADMINIS:
			printf("������������Ա��Ϣ \n");

			break;
		case  MAINADMINIS:
			printf("�޸ĵ�ǰ����Ա��Ϣ \n");

			break;
		case PERMISSION:
			printf("���ù���ԱȨ��\n");

			break;
		case  SEEADMINIS:
			printf("�鿴��������¼����Ա�˺�\n");
			changeadminis();
			break;
		default:
			printf("���Ϸ����룬���������룡����\n");
			printf("���������ַ�������");
			getchar();
			scanf("%*[^\n]%*c");
		}
	} while (option);
}

//1:�������   0����֤ʧ��
int  perrmission(void) {

	if (adminiss) {
		//����Ա�����ѡ��
		if (nowadministrator==0) {
			printf("\n\n���¼��Ĺ���Ա�˺�����֤���\\>:\n\n");
			int move = -1;
			int max = 0;
			max = prinadminis(mainadministrator->before);
		labachoice:
			printf("��������Ҫ��¼���˺ţ������˺�ǰ����ţ�\\>:");
			scanf("%d", &move);
			scanf("%*[^\n]%*c");
		    if (move > max || move < 1) {
				printf("���ͷ����룬���������룡����\n");
				goto labachoice;
			}
			struct adminis* toverify = mainadministrator;
			while (move--) {
				toverify = toverify->before;
			}
			nowadministrator = toverify;
		}
		//������֤
		
		char keey[21] = {};
		int errornum = 0;
	labeinputkeey:
		printf("�뵱ǰ�˺���������\\>:");
		getkeey(keey);
		system("cls");
		/*keey[0] = '\0';
		scanf("%s", keey);
		scanf("%*[^\n]%*c");*/
		if (strcmp(nowadministrator->keeyword, keey) == 0) {
			//nowadministrator = toverify;
			return 1;
		}
		else {
			++errornum;
			printf("����������������룡����\n\n");
			if (errornum ==4) {
				printf("\n���Ĵ���������࣬Ϊ��֤��ȫ���˳�\n\n\n");
				//nowadministrator = NULL;
				return 0;
			}
			goto labeinputkeey;
		}
		
	}
	else {
		return 1;
	}
}

void firstaddadminid(void) {
	//��ʼ������Ա����
	nowadministrator = NULL;
	if (mainadministrator =(struct adminis*) malloc(sizeof(struct adminis))) {
		lastadministrator = mainadministrator;
		mainadministrator->before=NULL;
		if (adminiss>0) {
			FILE* fp = NULL;
			if (fp=fopen("adminis.txt", "r")) {
				int a = adminiss;
				struct adminis* toadd = mainadministrator;
				while (a--) {
					if (toadd->before = (struct adminis*)malloc(sizeof(struct adminis))) {
						toadd = toadd->before;
						//fgets(toadd->permission, 25, fp);//��ѻ��з�һ����ȡ���ַ�����
						//fgets(toadd->id, 25, fp);
						//fgets(toadd->keeyword, 25, fp);
						//fgets(toadd->quesone, 25, fp);
						//fgets(toadd->questwo, 25, fp);
						fscanf(fp, "%s", toadd->permission);
						fscanf(fp, "%s", toadd->id);
						fscanf(fp, "%s", toadd->keeyword);
						fscanf(fp, "%s", toadd->quesone);
						fscanf(fp, "%s", toadd->questwo);
					}
					else {
						perror("malloc:");
					}
				}
				lastadministrator = toadd;
				toadd->before = NULL;
				fclose(fp);
				fp = NULL;
				//��֤����Ա���
				cangoahead();
			/*labaverifyagain:
				a=perrmission();
				if (a == 0) {
					printf("��¼ʧ�ܣ�������\n\n");
					printf("�Ƿ��˳���0����  �������ǣ�\\>:");
					a = 1;
					scanf("%d", &a);
					scanf("%[^\n]%*c");
					if (a) {
						exit(0);
					}
					else {
						nowadministrator = NULL;
						goto labaverifyagain;
					}
				}*/
			}
			else {
				perror("fopen");
			}
			return;
		//����Ƿ��ǳ���ʹ��
		}else if(adminiss==0) {
			return;
		}
		//����ʹ�òŻ����е��˲�
		{
			printf("ϵͳ��⵽����������ʹ�ø�ϵͳ�������Ƿ���ӹ���Ա������ϵͳ�İ�ȫ��0:��  ����ѡ���ǣ�\\>:");
			adminiss = 0;
			int choice = 1;
			scanf("%d", &choice);
			scanf("%*[^\n]%*c");
			if (choice) {
				//��ӹ���Ա
				addoneadminis();//�˺����Ѿ�ʹadminiss++
				//adminiss = 1;
				nowadministrator = lastadministrator;
			}
			else {
				printf("\n\n      ��ӭ����ʹ��  �Ʒѹ���ϵͳ  \n\n\n");
			}
		}
	}
	else {
		perror("malloc:");
	}
	

	////����Ƿ��ǳ���ʹ��
	//if (adminiss-(-1) ){
	//	return ;
	//}
	//printf("ϵͳ��⵽����������ʹ�ø�ϵͳ�������Ƿ���ӹ���Ա������ϵͳ�İ�ȫ��0:��  ����ѡ���ǣ�\\>:");
	//int choice = 1;
	//scanf("%d", &choice);
	//scanf("%*[^\n]%*c");
	//if (choice) {
	//	//��ӹ���Ա


	//	adminiss = 1;
	//}
	//else {
	//	adminiss = 0;
	//}
}
int   prinadminis(struct adminis*firsttoprin) {
	system("cls");
	printf("\n\n***************  ��  ��   Ա  ��  ��  **************\n");
	int num = 0;
	while (firsttoprin) {
		printf(" %d : %s\n", ++num, firsttoprin->id);
		firsttoprin = firsttoprin->before;
	}
	return num;
}

//��ӹ���Ա
void addoneadminis(void) {
	int choice = -1;
	char id[15]={};
	int  idoready = 0;
	char keeyword[20]={};
	int  keeyoready = 0;
	char questionone[20]="F";
	int  quesoready = 0;
	char questwo[20]="F";
	int  questwooready = 0;
labastart:
	system("cls");
	//��ӡ�˵�
	{
		printf("��ӹ���Ա\\>:\n");
		printf("\n*************************************************************\n");
		printf("**     1�������˺�                2����������              ***\n");
		printf("**     3: ��ȫ����1               4����ȫ����2             ***\n");
		printf("**     5�������˳�                0:���أ�ȡ����ӹ���Ա�� ***\n");
		printf("**************************************************************\n");
	}
labainput:
	printf("����������ѡ��\\>:");
	choice = -1;
	scanf("%d", &choice);
	scanf("%*[^\n]%*c");
	switch (choice) {
	case 1:
		printf("�����˺�  \n");
		while(1) {
			printf("�������˺�����(���ö��� 14 ���ַ�\\>:");
			scanf("%s", id);
			scanf("%*[^\n]%*c");
			//����˺��Ƿ����
			{
				if (strlen(id) > 14) {
					printf("���벻�ͷ�������������!!!\n\n");
				}
				else {
					struct adminis* toverify = mainadministrator->before;
					while (toverify) {
						if (0 == strcmp(toverify->id, id)) {
							printf("���벻�ͷ�(����ĳЩԭ����˺���ʱ�����ã������½⣩������������!!!\n\n");
							goto labastart;
						}
						toverify = toverify->before;
					}
					idoready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 2:
		printf("��������\n");
		{
			while (1) {
				printf("����������(���ö��� 19 ���ַ�\\>:");
				scanf("%s", keeyword);
				scanf("%*[^\n]%*c");
				if (strlen(keeyword) > 19 ) {
					printf("���벻�ͷ�������������!!!\n\n");
				}
				else {
					keeyoready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 3:
		printf("��ȫ����1  \n");
		{
			printf("����1 : ��ĵ�һֻ������ʲô?\n");
			while (1) {
				printf("��������Ĵ�(�����������ģ����ö��� 19 ���ַ�)\\>:");
				scanf("%s", questionone);
				scanf("%*[^\n]%*c");
				if (strlen(questionone) > 19) {
					printf("���벻�ͷ�������������!!!\n");
				}
				else {
					quesoready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 4:
		printf("��ȫ����2  \n");
		{
			printf("����2 : ��Сʱ����������ʲô?\n");
			while (1) {
				printf("��������Ĵ�(�����������ģ����ö��� 19 ���ַ�)\\>:");
				scanf("%s", questwo);
				scanf("%*[^\n]%*c");
				if (strlen(questwo) > 19) {
					printf("���벻�ͷ�������������!!!\n");
				}
				else {
					questwooready = 1;
					break;
				}
			}
		}
		goto labastart;
		//break;
	case 5:
		printf("�����˳�   \n");
		{
			if (idoready && keeyoready) {
				//���
				if (quesoready +questwooready==1) {
					printf("��ȫ�������ͬʱ���ã�����ֻ����һ��������: �������ð�ȫ����    0: ȡ�����ð�ȫ����������棩\\>:");
					int cancel = 1;
					scanf("%d", &cancel);
					scanf("%*[^\n]%*c");
					if (cancel) {
						goto labastart;
					}
					else {
						strcpy(questionone, "F");
						strcpy(questwo, "F");
						//questionone[0] = '\0';
						//questwo[0] = '\0';
					}
				}
				else if(quesoready + questwooready == 0) {
					printf("ϵͳ��⵽����Ϊ���ð�ȫ���⣬�Ƿ����ð�ȫ�����Է��������루0����  ����ѡ���ǣ�\\>:");
					int addquestion = 1;
					scanf("%d", &addquestion);
					scanf("%*[^\n]%*c");
					if (addquestion) {
						goto labastart;
					}
				}
				//����
				if (lastadministrator->before=(struct adminis*)malloc(sizeof(struct adminis))) {
					lastadministrator = lastadministrator->before;
					lastadministrator->before = NULL;
					++adminiss;

					strcpy(lastadministrator->id, id);
					strcpy(lastadministrator->permission, "F");
					strcpy(lastadministrator->keeyword, keeyword);
					strcpy(lastadministrator->quesone, questionone);
					strcpy(lastadministrator->questwo, questwo);
					
					printf("��ӹ���Ա�ɹ�!\n");
				}
				else {
					perror("malloc:");
				}

			}
			else {
				printf("������д������Ҫ����Ϣ������\n\n");
				goto labastart;
			}
		}

		break;
	case 0:
		printf("���أ�ȡ����ӹ���Ա��\n");
		break;
	default:
		printf("���Ϸ����룬���������룡����  \n");
		goto  labainput;
	}
	
}

void cangoahead(void)
{
	int a = 0;
labaverifyagain:
	a = perrmission();
	if (a == 0) {
		printf("��¼ʧ�ܣ�������\n\n");
		printf("�Ƿ��˳���0����  �������ǣ�\\>:");
		a = 1;
		scanf("%d", &a);
		scanf("%*[^\n]%*c");
		if (a) {
			exit(0);
		}
		else {
			nowadministrator = NULL;
			goto labaverifyagain;
		}
	}
}

void getkeey(char keey[]) {
	int i = 0;
	scanf("%*[^\n]%*c");
	while ((keey[i] = _getch() )-'\r') {
		++i;
		putchar('*');
	}
	keey[i] = '\0';
	putchar('\n');
}

void changeadminis(void)
{
	int choice = -1;
	do {
		printf("\nѡ��˵�\\>:\n");
		printf("1:�鿴��������Ա���˺�          2����¼��������Ա�˺�       0���˳�\n");
		printf("����������ѡ��\\>:");
		choice = -1;
		scanf("%d", &choice);
		scanf("%*[^\n]%*c");
		if (choice == 1) {
			prinadminis(mainadministrator->before);
		}
		else if (choice == 2) {
			printf("\nΪ�˱��ϰ�ȫ����Ҫȷ���������!!!!!\n\n");
			if (canchange()) {
				nowadministrator = NULL;
				printf("�ɹ��˳���¼\n\n");
				cangoahead();
				printf("���µ�¼�ɹ�\n\n�����������\\>:");
				getchar();
				scanf("%*[^\n]%**c");
				return;
			}
		}
		else {
			printf("���Ϸ����룬����������!!!\n");
		}
	} while (choice);
}

int canchange(void) 
{
	int a = 0;
labaverifyagain:
	a = perrmission();
	if (a) return 1;
	{
		printf("�����֤ʧ��ʧ�ܣ�������\n\n");
		printf("�Ƿ��˳���0����  �������ǣ�\\>:");
		a = 1;
		scanf("%d", &a);
		scanf("%*[^\n]%*c");
		if (a) {
			printf("����ʹ�õ�ǰ�ʺţ�����\n");
			return 0;
		}
		else {
			goto labaverifyagain;
		}
	}
}

void deladminis(void) {
	printf("\nΪ�˱��ϰ�ȫ����Ҫȷ������������˳���ǰ�˺�!!\n\n");
	if (canchange()) {
		printf("һ��Ϊ����Ȩ�޲����Ĺ���Ա�˻�\\>:\n");
		int max=prinadminis(nowadministrator);
		int move = -1;
		//********************************************
	labachoice:
		printf("��������ɾ�����˺ţ������˺�ǰ����ţ�\\>:");
		move = -1;
		scanf("%d", &move);
		scanf("%*[^\n]%*c");
		if (move > max || move < 1) {
			printf("���ͷ����룬���������룡����\n");
			goto labachoice;
		}
		struct adminis* toverify = nowadministrator;
		if (move == 1) {
			toverify = mainadministrator;
			while (toverify->before!=nowadministrator) {
				toverify = toverify->before;
			}
		}
		else {
			--move;
			while (--move) {
				toverify = toverify->before;
			}
		}
		deloneadminis(toverify);
	}
	else {
		printf("\n�����֤ʧ�ܣ����˳�������\n\n");
	}
}

void deloneadminis(struct adminis* beforetodel) {
	if (beforetodel->before->before == NULL) {
		lastadministrator = beforetodel;
	}
	struct adminis* todel = beforetodel->before;
	beforetodel->before = (beforetodel->before)->before;
	free(todel);
	--adminiss;
	printf("ע���ɹ���\n");
}