#define   _CRT_SECURE_NO_WARNINGS  1

#include"tonXl.h"

enum chioce {
	EXITALL,NEWCONTACT,LOADCONTACT,
};


void mainmenu(void)
{
	cout << "注意，该程序最多建立" << MAXCATALOG << "个通讯录，每个通讯录最多保存" << MAXNUM << "个人的信息" << endl
		<< "******************************************************" << endl
		<< "****  1.新建通讯录             2.加载通讯录 ****" << endl
		<< "****              0.退出系统                ****" << endl << endl
		<< "*******************************************************" << endl
		<< "请输入你的选择\\>:";
}

void del(void) {
	int option = 5;
	cout << "*********************************************" << endl
		<< "** 1.按名字删除联系人      2.按序号删除联系人 **" << endl
		<< "** 3.按电话号码删除联系人  4.按地址删除联系人 **" << endl
		<< "**              0.退出                        **" << endl
		<< "************************************************" << endl << endl
		<< "请输入您的选择\\>:";
	cin >> option;

}

void newcatalog(void)
{
	class catalog onecatalog;
	int option = 9;
	do {
		cout << "***************************************************" << endl
			<< "***   1.添加联系人          2.删除联系人       ****" << endl
			<< "***   3.按姓名查找联系人    4.按序号查找联系人 ****" << endl
			<< "***   5.按电话查找联系人    6.按住址查找联系人 ****" << endl
			<< "***   7.打印该通讯录到屏幕  8.对联系人按姓名进行排序"<<endl
			<< "***            0.返回到上一步                 ****" << endl
			<< "****************************************************" << endl << endl
			<< "请输入您的选择\\>:";
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
			cout << "新建通讯录" << endl;
			newcatalog();
			break;
		case LOADCONTACT:
			cout << "加载通讯录" << endl;

			break;
		case EXITALL:

			cout << "退出该程序" << endl;
			break;
		default:
			cout << "未知输入，请重新输入" << endl << endl;
		}
	}while(option);
	
	
	return 0;
}
