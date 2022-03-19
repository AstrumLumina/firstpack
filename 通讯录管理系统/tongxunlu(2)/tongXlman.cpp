#define   _CRT_SECURE_NO_WARNINGS  1

#include"tonXl.h"

void loadcatalage(int *catalognum, char name[11][15]);
void changeperson(class person* tosee);

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

void del(class catalog* onecatalog) {
	int option = 5;
	do {
		cout << "***********************************************" << endl
			<< "** 1.按名字删除联系人      2.按序号删除联系人 **" << endl
			<< "** 3.按电话号码删除联系人  4.按地址删除联系人 **" << endl
			<< "**              0.退出                        **" << endl
			<< "************************************************" << endl << endl
			<< "请输入您的选择\\>:";
		option = 5;
		cin >> option;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
		class person* todel = NULL;
		switch (option) {
		case 1:
			cout << "按名字删除联系人 " << endl;
			if (!(todel = onecatalog->seekname())) {
				cout << "不存在联系人！！！\n" << endl << endl;
			}
			/*char name[15];
		labaname:
			name[0] = '\0';
			cout << "请输入姓名\\>:";
			cin >> name;
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			if (*name) {
				cout<<"不和法输入，请重新输入" << endl << endl;
				goto labaname;
			}
			todel=*/
			break;
		case 2:
			cout << "按序号删除联系人" << endl;
			if (!(todel = onecatalog->seeknum())) {
				cout << "不存在该序号！！！\n" << endl << endl;
			}
			break;
		case 3:
			cout << "按电话号码删除联系人" << endl;
			if (!(todel = onecatalog->seekphone())) {
				cout << "不存在该电话！！！\n" << endl << endl;
			}
			break;
		case 4:
			cout << "按地址删除联系人" << endl;
			if (!(todel = onecatalog->seekaddress())) {
				cout << "不存在该地址！！！\n" << endl << endl;
			}
			break;
		case 0:
			cout << "退出" << endl;
			break;
		default:
			cout << "未知输入，请重新输入" << endl << endl;
		}
		if (todel) {
			cout << endl << endl << "您确定要删除该联系人吗（1：是   其他选择：否）\\>:";
			int answer = 0;
			cin >> answer;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			if (answer==1) {
				(*onecatalog).del(todel);
			}
			else {
				cout << "以取消删除" << endl;
			}
		}
	} while (option);
}

//void newcatalog(class catalog*onecatalog)
//{
//	int option = 9;
//	do {
//		cout << "***************************************************" << endl
//			<< "***   1.添加联系人          2.删除联系人       ****" << endl
//			<< "***   3.按姓名查找联系人    4.按序号查找联系人 ****" << endl
//			<< "***   5.按电话查找联系人    6.按住址查找联系人 ****" << endl
//			<< "***   7.打印该通讯录到屏幕  8.对联系人按姓名进行排序"<<endl
//			<< "***            0.返回到上一步                 ****" << endl
//			<< "****************************************************" << endl << endl
//			<< "请输入您的选择\\>:";
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
//				cout << "未找到您要删除的信息！！！" << endl;
//			}
//			break;
//		case 4:
//			beforefind = onecatalog->seeknum();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else {
//				cout << "未找到您要删除的信息！！！" << endl;
//			}
//			break;
//		case 5:
//			beforefind = onecatalog->seekphone();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else {
//				cout << "未找到您要删除的信息！！！" << endl;
//			}
//			break;
//		case 6:
//			beforefind = onecatalog->seekaddress();
//			if (beforefind) {
//				onecatalog->del(beforefind);
//			}
//			else {
//				cout << "未找到您要删除的信息！！！" << endl;
//			}
//			break;
//		case 7:
//			onecatalog->prin();
//			break;
//		case 8:
//			onecatalog->sort();
//			break;
//		case 0:
//			cout << "返回到上一步 " << endl;
//			break;
//		default:
//			cout << "不和法输入，请重新输入!!!" << endl << endl;
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
			<< "***   1.添加联系人              2.删除联系人                ****" << endl
			<< "***   3.按姓名查找联系人        4.按序号查找联系人          ****" << endl
			<< "***   5.按电话查找联系人        6.按住址查找联系人          ****" << endl
			<< "***   7.打印该通讯录到屏幕      8.对联系人按姓名进行排序    ****" << endl
			<< "***   9.选择某序号的联系人      0.返回(自动保存该通讯录）   ****" << endl
			<< "****************************************************************" << endl << endl
			<< "请输入您的选择\\>:";
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
				cout << "未找到您查找要的信息！！！" << endl;
			}*/
			break;
		case 4:
			beforefind = onecatalog.seeknum();
			/*if (beforefind) {
				onecatalog.prin(beforefind);
			}
			else {
				cout << "未找到您查找要的信息！！！" << endl;
			}*/
			break;
		case 5:
			beforefind = onecatalog.seekphone();
			/*if (beforefind) {
				onecatalog.prin(beforefind);
			}
			else {
				cout << "未找到您查找要的信息！！！" << endl;
			}*/
			break;
		case 6:
			beforefind = onecatalog.seekaddress();
			/*if (beforefind ) {
				onecatalog.prin(beforefind);
			}
			else  {
				cout << "未找到您查找要的信息！！！" << endl;
			}*/
			break;
		case 7:
			onecatalog.prin();
			break;
		case 8:
			onecatalog.sort();
			cout << "已完成排序，请查看\\>:" << endl;
			onecatalog.prin();
			break;
		case 9:
			class person* tosee;
			cout << "选择某序号的联系人\\>:" << endl;
		labachoose:
			tosee = onecatalog.seeknum();
			if (tosee) {
				cout << "以下为该位联系人的信息\\>:" << endl;
				onecatalog.prin(tosee);
				tosee = tosee->getnext();
				changeperson(tosee);
			}
			else {
				cout << "不和法输入(该序号不存在），请重新输入!!!" << endl << endl;
				goto labachoose;
			}
			break;
		case 0:
			cout << "返回到上一步 " << endl;
			onecatalog.beifen(catalognum);
			break;
		default:
			cout << "不和法输入，请重新输入!!!" << endl << endl;
			/*++errornum;
			if (errornum % 20 == 0) {
				getchar();
				cout << "请按要求输入！！！！" << endl << endl;
			}*/
			break;
		}
		if (beforefind==0) {
			cout << "未找到您查找要的信息！！！" << endl;
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
		cout << "通讯录目录文件打开失败" << endl;
	}
	else {
		int hasread=0;
		fin >> *catalognum;
		fin.getline(directoryname[a], 16);//读取换行符
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
		cout<<"通讯录目录文件打开失败"<<endl;
	}
	else {
		fout << catalognum << endl;
		int a = 1;
		int catatoout = 1;
		//该处为死循环：
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
		cout << "此目录为系统自动而备份目录，不可更改" << endl << endl;
		return;
	}
	if (directoryname[catalognum][0]) {
		cout << endl << "请为该通讯录的重新命名（注意:名字必须全部是英文字符,且不超过 14个字符）\\>:";
	}
	else {
		cout << endl << "请为该通讯录的命名（注意:名字必须全部是英文字符，且不超过 14个字符）\\>:";
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
			cout << "新建通讯录" << endl;
			if (catalognum >= 10) {
				cout << "最多只能建10个通讯录！！！！" << endl << endl;
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
			std::cout << "加载通讯录" << endl;
			loadcatalage(&catalognum, diretoryname);
			//savedirectory(catalognum, diretoryname);
			break;
		case EXITALL:
			std::cout << "退出该程序" << endl;
			savedirectory(catalognum, diretoryname);
			break;
		default:
			std::cout << "未知输入，请重新输入" << endl << endl;
		}
	} while (option);
	return 0;
}

void loadcatalage(int* catalognumlocal,char name[11][15]) {

labafirst:
	//int catalognum = *catalognumlocal;
	while (1) {
		int catalognum = *catalognumlocal;
		std::cout << "目录（注意：第一个通讯录是系统自动保存通讯录）\\>:" << endl;
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
		std::cout << endl << "0: 返回到上一步 " << endl<<endl<<endl;
		std:: cout << "请选择你要打开的通讯录(输入对应的序号）\\>:";
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
					<< "**  1:管理通讯录        2:重命名该通讯录      3.删除该通讯录       0:返回      ****" << endl << endl
					<< "***********************************************************************************" << endl
					<< "请输入你的选择\\>:";
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
					cout << "删除通讯录" << endl;
					//cout << "该功能尚未完善，请谅解！！！" << endl;
					if (i == 0) {
						printf("无法删除系统自动备份目录！！！\\>:\n");
						printf("按任意键继续\\>:");
						getchar();
						scanf("%*[^\n]%*c");
						goto labaagain;
					}
					cout << "您确认要删除该通讯录吗（1：是     其他：否）\\>:";
					int input = 0;
					cin >> input;
					cin.clear();
					cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
					if (input == 1) {
						--(*catalognumlocal);
						//--catalognum;
						name[i][0] = '\0';
						savedirectory(*catalognumlocal, name);
						cout << "已删除该通讯录" << endl;
						goto labafirst;
					}
					else {
						cout << "已取消删除" << endl;
					}
				}
				else if (input) {
					cout << "未知输入,请重新输入！！！" << endl;
				}
			}
		}
		else if (!i) {
			cout << "返回 " << endl << endl;
			break;
		}
		else {
			cout << "未知输入,请重新输入！！！" << endl;
		}
	}
}

void changeperson(class person* tosee) {
	int serial = 5;
	char name[15] = "";
	do {
		cout << endl << endl
			<< "*************************************************************************************" << endl
		    << "****  1.更改姓名     2。更改地址      3.更改电话1      4.更改电话2      0.退出   ****" << endl<<endl
			<<"**************************************************************************************" << endl
			<< "请输入选择\\>:";
		serial = 5;
		cin >> serial;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (serial) {
		case 1:
			cout << "更改姓名\\>:" << endl;
			cout << "请输入更改后的名字\\>:";
			name[0]='\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changename(name);
			break;
		case 2:
			cout << "更改地址\\>:" << endl;
			cout << "请输入更改后的地址\\>:";
			name[0] = '\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changeaddress(name);
			break;
		case 3:
			cout << "更改电话1 \\>:" << endl;
			cout << "请输入更改后的电话1\\>:";
			name[0] = '\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changephone(name,0);
			break;
		case 4:
			cout << "更改电话2\\>:" << endl;
			cout << "请输入更改后的电话2\\>:";
			name[0] = '\0';
			cin >> name;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			tosee->changephone(name,1);
			break;
		case 0:
			cout << "退出\\>:" << endl;
			break;
		default:
			cout << "不和法输入，请重新输入!!!" << endl << endl;
		}
	} while (serial);
}
