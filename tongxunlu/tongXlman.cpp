#define   _CRT_SECURE_NO_WARNINGS  1

#include"tonXl.h"

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

void del(void) {
	int option = 5;
	cout << "*********************************************" << endl
		<< "** 1.������ɾ����ϵ��      2.�����ɾ����ϵ�� **" << endl
		<< "** 3.���绰����ɾ����ϵ��  4.����ַɾ����ϵ�� **" << endl
		<< "**              0.�˳�                        **" << endl
		<< "************************************************" << endl << endl
		<< "����������ѡ��\\>:";
	cin >> option;

}

void newcatalog(void)
{
	class catalog onecatalog;
	int option = 9;
	do {
		cout << "***************************************************" << endl
			<< "***   1.�����ϵ��          2.ɾ����ϵ��       ****" << endl
			<< "***   3.������������ϵ��    4.����Ų�����ϵ�� ****" << endl
			<< "***   5.���绰������ϵ��    6.��סַ������ϵ�� ****" << endl
			<< "***   7.��ӡ��ͨѶ¼����Ļ  8.����ϵ�˰�������������"<<endl
			<< "***            0.���ص���һ��                 ****" << endl
			<< "****************************************************" << endl << endl
			<< "����������ѡ��\\>:";
		option = 9;
		cin >> option;
		cin.ignore(std::numeric_limits<streamsize>max(), '\n');
		switch (option) {
		case 1:
			onecatalog.add();
			break;
		case 2:
			del();
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 0:

			break;
		default:
			;
		}
	} while (option);

}






int main() {
	int option = 3;
	int catalognum = 0;
	do {
		mainmenu();
		option = 3;
		cin >> option;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (option) {
		case NEWCONTACT:
			cout << "�½�ͨѶ¼" << endl;
			newcatalog();
			break;
		case LOADCONTACT:
			cout << "����ͨѶ¼" << endl;

			break;
		case EXITALL:

			cout << "�˳��ó���" << endl;
			break;
		default:
			cout << "δ֪���룬����������" << endl << endl;
		}
	}while(option);
	
	
	return 0;
}
