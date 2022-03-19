#define   _CRT_SECURE_NO_WARNINGS  1

#include"tonXl.h"

void loadcatalage(int *catalognum, char name[11][15]);
void changeperson(class person* tosee);

enum chioce {
	EXITALL,NEWCONTACT,LOADCONTACT,
};


void mainmenu(void)
{
	cout << "ע�⣬�ó�����ཨ��" << MAXCATALOG << "��ͨѶ¼��ÿ��ͨѶ¼��ౣ��" << MAXNUM << "���˵���Ϣ" << endl
		<< "******************************************************" << endl
		<< "****  1.�½�ͨѶ¼             2.����ͨѶ¼ ****" << endl
		<< "****              0.�˳�ϵͳ                ****" << endl << endl
		<< "*******************************************************" << endl
		<< "���������ѡ��\\>:";
}

void del(class catalog* onecatalog) {
	int option = 5;
	do {
		cout << "***********************************************" << endl
			<< "** 1.������ɾ����ϵ��      2.�����ɾ����ϵ�� **" << endl
			<< "** 3.���绰����ɾ����ϵ��  4.����ַɾ����ϵ�� **" << endl
			<< "**              0.�˳�                        **" << endl
			<< "************************************************" << endl << endl
			<< "����������ѡ��\\>:";
		option = 5;
		cin >> option;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		class person* todel = NULL;
		switch (option) {
		case 1:
			cout << "������ɾ����ϵ�� " << endl;
			if (!(todel = onecatalog->seekname())) {
				cout << "��������ϵ�ˣ�����\n" << endl << endl;
			}
			/*char name[15];
		labaname:
			name[0] = '\0';
			cout << "����������\\>:";
			cin >> name;
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			if (*name) {
				cout<<"���ͷ����룬����������" << endl << endl;
				goto labaname;
			}
			todel=*/
			break;
		case 2:
			cout << "�����ɾ����ϵ��" << endl;
			if (!(todel = onecatalog->seeknum())) {
				cout << "�����ڸ���ţ�����\n" << endl << endl;
			}
			break;
		case 3:
			cout << "���绰����ɾ����ϵ��" << endl;
			if (!(todel = onecatalog->seekphone())) {
				cout << "�����ڸõ绰������\n" << endl << endl;
			}
			break;
		case 4:
			cout << "����ַɾ����ϵ��" << endl;
			if (!(todel = onecatalog->seekaddress())) {
				cout << "�����ڸõ�ַ������\n" << endl << endl;
			}
			break;
		case 0:
			cout << "�˳�" << endl;
			break;
		default:
			cout << "δ֪���룬����������" << endl << endl;
		}
		if (todel) {
			cout << endl << endl << "��ȷ��Ҫɾ������ϵ����1����   ����ѡ�񣺷�\\>:";
			int answer = 0;
			cin >> answer;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			if (answer==1) {
				(*onecatalog).del(todel);
			}
			else {
				cout << "��ȡ��ɾ��" << endl;
			}
		}
	} while (option);
}

//void newcatalog(class catalog*onecatalog)
//{
//	int option = 9;
//	do {
//		cout << "***************************************************" << endl
//			<< "***   1.�����ϵ��          2.ɾ����ϵ��       ****" << endl
//			<< "***   3.������������ϵ��    4.����Ų�����ϵ�� ****" << endl
//			<< "***   5.���绰������ϵ��    6.��סַ������ϵ�� ****" << endl
//			<< "***   7.��ӡ��ͨѶ¼����Ļ  8.����ϵ�˰�������������"<<endl
//			<< "***            0.���ص���һ��                 ****" << endl
//			<< "****************************************************" << endl << endl
//			<< "����������ѡ��\\>:";
//		option = 9;
//		cin >> option;
//		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
//		class person* beforefind = NULL;
//		switch (option) {
//		case 1:
//			onecatalog->add();
//			break;
//		case 2:
//			del(onecatalog);
//			break;
//		case 3:
//			beforefind = onecatalog->seekname();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else  {
//				cout << "δ�ҵ���Ҫɾ������Ϣ������" << endl;
//			}
//			break;
//		case 4:
//			beforefind = onecatalog->seeknum();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else {
//				cout << "δ�ҵ���Ҫɾ������Ϣ������" << endl;
//			}
//			break;
//		case 5:
//			beforefind = onecatalog->seekphone();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else {
//				cout << "δ�ҵ���Ҫɾ������Ϣ������" << endl;
//			}
//			break;
//		case 6:
//			beforefind = onecatalog->seekaddress();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else {
//				cout << "δ�ҵ���Ҫɾ������Ϣ������" << endl;
//			}
//			break;
//		case 7:
//			onecatalog->prin();
//			break;
//		case 8:
//			onecatalog->sort();
//			break;
//		case 0:
//			cout << "���ص���һ�� " << endl;
//			break;
//		default:
//			cout << "���ͷ����룬����������!!!" << endl << endl;
//			break;
//		}
//		
//	} while (option);
//
//}

void newcatalog(int catalognum, int notrealnew)
{
	class catalog onecatalog;
	if (notrealnew) {
		onecatalog.load(catalognum);
	}
	int option = 10;
	//int errornum = 1;
	do {
		cout << "****************************************************************" << endl
			<< "***   1.�����ϵ��              2.ɾ����ϵ��                ****" << endl
			<< "***   3.������������ϵ��        4.����Ų�����ϵ��          ****" << endl
			<< "***   5.���绰������ϵ��        6.��סַ������ϵ��          ****" << endl
			<< "***   7.��ӡ��ͨѶ¼����Ļ      8.����ϵ�˰�������������    ****" << endl
			<< "***   9.ѡ��ĳ��ŵ���ϵ��      0.����(�Զ������ͨѶ¼��   ****" << endl
			<< "****************************************************************" << endl << endl
			<< "����������ѡ��\\>:";
		option = 10;
		cin >> option;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		//class person* beforefind = NULL;
		class person* beforefind = (person*)1;
		switch (option) {
		case 1:
			onecatalog.add();
			break;
		case 2:
			del(&onecatalog);
			break;
		case 3:
			beforefind = onecatalog.seekname();
			/*if (beforefind) {
				onecatalog.prin(beforefind);
			}
			else {
				cout << "δ�ҵ�������Ҫ����Ϣ������" << endl;
			}*/
			break;
		case 4:
			beforefind = onecatalog.seeknum();
			/*if (beforefind) {
				onecatalog.prin(beforefind);
			}
			else {
				cout << "δ�ҵ�������Ҫ����Ϣ������" << endl;
			}*/
			break;
		case 5:
			beforefind = onecatalog.seekphone();
			/*if (beforefind) {
				onecatalog.prin(beforefind);
			}
			else {
				cout << "δ�ҵ�������Ҫ����Ϣ������" << endl;
			}*/
			break;
		case 6:
			beforefind = onecatalog.seekaddress();
			/*if (beforefind ) {
				onecatalog.prin(beforefind);
			}
			else  {
				cout << "δ�ҵ�������Ҫ����Ϣ������" << endl;
			}*/
			break;
		case 7:
			onecatalog.prin();
			break;
		case 8:
			onecatalog.sort();
			cout << "�����������鿴\\>:" << endl;
			onecatalog.prin();
			break;
		case 9:
			class person* tosee;
			cout << "ѡ��ĳ��ŵ���ϵ��\\>:" << endl;
		labachoose:
			tosee = onecatalog.seeknum();
			if (tosee) {
				cout << "����Ϊ��λ��ϵ�˵���Ϣ\\>:" << endl;
				onecatalog.prin(tosee);
				tosee = tosee->getnext();
				changeperson(tosee);
			}
			else {
				cout << "���ͷ�����(����Ų����ڣ�������������!!!" << endl << endl;
				goto labachoose;
			}
			break;
		case 0:
			cout << "���ص���һ�� " << endl;
			onecatalog.beifen(catalognum);
			break;
		default:
			cout << "���ͷ����룬����������!!!" << endl << endl;
			/*++errornum;
			if (errornum % 20 == 0) {
				getchar();
				cout << "�밴Ҫ�����룡������" << endl << endl;
			}*/
			break;
		}
		if (beforefind==0) {
			cout << "δ�ҵ�������Ҫ����Ϣ������" << endl;
		}
		else if(beforefind-(class person*)1) {
			onecatalog.prin(beforefind);
		}
	} while (option);

}
int  loaddirecotory(int* catalognum, char directoryname[11][15]) {
	int returnlocal = 0;
	int a = 1;
	ifstream fin;
	fin.open("directory.txt", ios::in);
	if (!fin.is_open()) {
		cout << "ͨѶ¼Ŀ¼�ļ���ʧ��" << endl;
	}
	else {
		int hasread=0;
		fin >> *catalognum;
		fin.getline(directoryname[a], 16);//��ȡ���з�
		while (hasread<*catalognum) {
			fin.getline(directoryname[a],16);
			if (directoryname[a][0]-'\0') {
				++hasread;
			}
			else {
				if (!returnlocal) {
					returnlocal = a;
				}
			}
			++a;
		}
	}
	fin.close();
	if (returnlocal) {
		return returnlocal;
	}
	else {
		return a;
	}
	
}
void savedirectory(int catalognum, char directoryname[11][15]) {
	ofstream fout;
	fout.open("directory.txt", ios::out);
	if (!fout.is_open()) {
		cout<<"ͨѶ¼Ŀ¼�ļ���ʧ��"<<endl;
	}
	else {
		fout << catalognum << endl;
		int a = 1;
		int catatoout = 1;
		//�ô�Ϊ��ѭ����
		while (a<=catalognum){
			fout << directoryname[catatoout] << endl;
			if (directoryname[catatoout][0]) {
				++a;
			}
			++catatoout;
		}
	}
	fout.close();
}
void getname(int catalognum, char directoryname[11][15]) {
	if (!catalognum) {
		cout << "��Ŀ¼Ϊϵͳ�Զ�������Ŀ¼�����ɸ���" << endl << endl;
		return;
	}
	if (directoryname[catalognum][0]) {
		cout << endl << "��Ϊ��ͨѶ¼������������ע��:���ֱ���ȫ����Ӣ���ַ�,�Ҳ����� 14���ַ���\\>:";
	}
	else {
		cout << endl << "��Ϊ��ͨѶ¼��������ע��:���ֱ���ȫ����Ӣ���ַ����Ҳ����� 14���ַ���\\>:";
	}
	directoryname[catalognum][0] = catalognum+'0';
	cin >> directoryname[catalognum]+1;
	cin.clear();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

int main() {
	//class catalog onecatalog;
	int option = 3;
	int catalognum = 0;
	char diretoryname[11][15] = {"automo.txt","","",""};
	do {
		mainmenu();
		int vacant = loaddirecotory(&catalognum, diretoryname);
		option = 3;
		cin >> option;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (option) {
		case NEWCONTACT:
			cout << "�½�ͨѶ¼" << endl;
			if (catalognum >= 10) {
				cout << "���ֻ�ܽ�10��ͨѶ¼��������" << endl << endl;
			}
			else {
				++catalognum;
				getname(vacant, diretoryname);
				//newcatalog(&onecatalog);
				newcatalog(vacant, 0);
				savedirectory(vacant, diretoryname);
			}
			break;
		case LOADCONTACT:
			std::cout << "����ͨѶ¼" << endl;
			loadcatalage(&catalognum, diretoryname);
			//savedirectory(catalognum, diretoryname);
			break;
		case EXITALL:
			std::cout << "�˳��ó���" << endl;
			savedirectory(catalognum, diretoryname);
			break;
		default:
			std::cout << "δ֪���룬����������" << endl << endl;
		}
	} while (option);
	return 0;
}

void loadcatalage(int* catalognumlocal,char name[11][15]) {

labafirst:
	//int catalognum = *catalognumlocal;
	while (1) {
		int catalognum = *catalognumlocal;
		std::cout << "Ŀ¼��ע�⣺��һ��ͨѶ¼��ϵͳ�Զ�����ͨѶ¼��\\>:" << endl;
		std::cout << 1 << ": " << name[0] << endl;
		int i = 1;
		int toprinname = 1;
		int realcatalognum[12] = { 0 ,0};
		while (i <= catalognum) {
			if (name[toprinname][0]) {
				std::cout << ++i << ": " << &name[toprinname][1] << endl;
				realcatalognum[i] = name[toprinname][0]-'0';
			}
			++toprinname;
		}
		std::cout << endl << "0: ���ص���һ�� " << endl<<endl<<endl;
		std:: cout << "��ѡ����Ҫ�򿪵�ͨѶ¼(�����Ӧ����ţ�\\>:";
		i = 12;
		std::cin >> i;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		
		if (i >0 && i <  catalognum+2) {
			i = realcatalognum[i];
			int input = 4;
			while (input) {
			labaagain:
				cout << "***********************************************************************************" << endl
					<< "**  1:����ͨѶ¼        2:��������ͨѶ¼      3.ɾ����ͨѶ¼       0:����      ****" << endl << endl
					<< "***********************************************************************************" << endl
					<< "���������ѡ��\\>:";
				input = 4;
				cin >> input;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				if (input == 1) {
					newcatalog(i , 1);
				}
				else if (input == 2) {
					getname(i , name);
				}
				else if (input == 3) {
					cout << "ɾ��ͨѶ¼" << endl;
					//cout << "�ù�����δ���ƣ����½⣡����" << endl;
					if (i == 0) {
						printf("�޷�ɾ��ϵͳ�Զ�����Ŀ¼������\\>:\n");
						printf("�����������\\>:");
						getchar();
						scanf("%*[^\n]%*c");
						goto labaagain;
					}
					cout << "��ȷ��Ҫɾ����ͨѶ¼��1����     ��������\\>:";
					int input = 0;
					cin >> input;
					cin.clear();
					cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
					if (input == 1) {
						--(*catalognumlocal);
						//--catalognum;
						name[i][0] = '\0';
						savedirectory(*catalognumlocal, name);
						cout << "��ɾ����ͨѶ¼" << endl;
						goto labafirst;
					}
					else {
						cout << "��ȡ��ɾ��" << endl;
					}
				}
				else if (input) {
					cout << "δ֪����,���������룡����" << endl;
				}
			}
		}
		else if (!i) {
			cout << "���� " << endl << endl;
			break;
		}
		else {
			cout << "δ֪����,���������룡����" << endl;
		}
	}
}

void changeperson(class person* tosee) {
	int serial = 5;
	char name[15] = "";
	do {
		cout << endl << endl
			<< "*************************************************************************************" << endl
		    << "****  1.��������     2�����ĵ�ַ      3.���ĵ绰1      4.���ĵ绰2      0.�˳�   ****" << endl<<endl
			<<"**************************************************************************************" << endl
			<< "������ѡ��\\>:";
		serial = 5;
		cin >> serial;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (serial) {
		case 1:
			cout << "��������\\>:" << endl;
			cout << "��������ĺ������\\>:";
			name[0]='\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changename(name);
			break;
		case 2:
			cout << "���ĵ�ַ\\>:" << endl;
			cout << "��������ĺ�ĵ�ַ\\>:";
			name[0] = '\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changeaddress(name);
			break;
		case 3:
			cout << "���ĵ绰1 \\>:" << endl;
			cout << "��������ĺ�ĵ绰1\\>:";
			name[0] = '\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changephone(name,0);
			break;
		case 4:
			cout << "���ĵ绰2\\>:" << endl;
			cout << "��������ĺ�ĵ绰2\\>:";
			name[0] = '\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changephone(name,1);
			break;
		case 0:
			cout << "�˳�\\>:" << endl;
			break;
		default:
			cout << "���ͷ����룬����������!!!" << endl << endl;
		}
	} while (serial);
}
