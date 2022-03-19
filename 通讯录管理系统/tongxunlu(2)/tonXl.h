#pragma once

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<assert.h>
using namespace std;



enum maxlimit {
	MAXCATALOG = 10,
	MAXNUM = 500,
};

class person {
	friend class catalog;
private:
	int num;
	char phone[12];
	char phone2[12];
	char name[12];
	char address[20];
	class person* next;

	/*void  changenum(int anum) {
		num = anum;
	}*/
public:
	void changephone(char* aphone, int a) {
		if (a) {
			strcpy(phone2, aphone);
		}
		else {
			strcpy(phone, aphone);
		}
	}
	void changename(char* aname) {
		strcpy(name, aname);
	}
	void changeaddress(char* aaddress) {
		strcpy(address, aaddress);
	}
	void changenext(class person* anext) {
		next = anext;
	}
	person* getnext(void) {
		return next;
	}
	person() :num(0), phone(""),phone2(""), name(""),address(""),next(NULL) {};
	person(int anum, char* aphone, char* aphone2, char* aname, char* aaddress) :num(anum),next(NULL) {
		strcpy(phone, aphone);
		strcpy(phone2, aphone2);
		strcpy(name, aname);
		strcpy(address, aaddress);

	};
	~person(){};
};

enum catchoic {
	EXIT,NAME,PHONEONE,PHONETWO,ADDERSS,SAVE
};
class catalog  {
private:
	int personnum;
	class person* head ;
	class person* last;

public:	
	void del(class person* befortodel) {
		class person* todel = befortodel->next;
		befortodel->next = todel->next;
		delete(todel);

		todel = befortodel->next;
		int num = befortodel->num;
		while (++num < personnum) {
			todel->num = num;
			todel = todel->next;
		}
		--personnum;
	}
	void prin() {
		class person* toprin = head;
		int prinnum = personnum;
		while (prinnum--) {
			prin(toprin);
			toprin = toprin->next;
		}
	}
	void prin(class person* toprin) {
		toprin = toprin->next;
		cout << "  序号： " <<setw(5) <<std::left<<toprin->num
			<< "  姓名： " <<setw(16) << std::left <<toprin->name
			<< "  电话1：" <<setw(16) << std::left <<toprin->phone
			<< "  电话2：" <<setw(16) << std::left <<toprin->phone2
			<< "  地址： " <<setw(20) << std::left <<toprin->address << endl;
	}
	//均返回要查找的前一个元素
	class person* seekname() {
		char aname[12] = { 0 };
		cout << "请输入你要查找的名字\\>:";
		cin >> aname;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		class person* tosee = head;
		while (tosee->next) {
			if (! strcmp(aname, (tosee->next)->name)) {
				return tosee;
			}
			tosee = tosee->next;
		}
		return NULL;
	}
	class person* seeknum() {
		int num = 0;
		cout << "请输入您要查找的序号\\>:";
		num = 0;
		cin >> num;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		if (num > personnum||num==0) {
			//cout << "没有该序号，请重新输入！！！" << endl << endl;
			return NULL;
		}
		class person* tosee = head;
		while(--num) {
			tosee = tosee->next;
		} 
		return tosee;
	}
	class person* seekphone() {
		char phone[12] = { 0 };
		cout << "请输入你要查找的电话\\>:";
		cin >> phone;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		class person* tosee = head;
		while (tosee->next) {
			if (!strcmp(phone, (tosee->next)->phone)) {
				return tosee;
			}else if (!strcmp(phone, (tosee->next)->phone2)) {
				return tosee;
			}
			tosee = tosee->next;
		}
		return NULL;
	}
	class person* seekaddress() {
		char address[20] = { 0 };
		cout << "请输入你要查找的地址\\>:";
		cin >> address;
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		class person* tosee = head;
		while (tosee->next) {
			if (!strcmp(address, (tosee->next)->address)) {
				return tosee;
			}
			tosee = tosee->next;
		}
		return NULL;
	}
	void sort() {
		int i;
		int j;
		class person* max ;
		class person* wheni=head;//会前移一个，以方便交换
		class person* whenj;
		for (i = 0; i < personnum-1; ++i) {
			max = wheni;
			whenj = wheni->next;
			for (j = i; j < personnum - 1; ++j) {
				if (cmp((max->next)->name, (whenj->next)->name) > 0) {
					max = whenj;
				}
				whenj = whenj->next;
			}
			if (max != wheni) {
				class person* temp = max->next;
				max->next = temp->next;
				temp->next = wheni->next;
				wheni->next = temp;
			}
			wheni = wheni->next;
			wheni->num = i + 1;
		}
		last = wheni->next;
		last->num = i + 1;
		
	}
	int cmp(char* name1, char* name2) {
		return strcmp(name1, name2);
	}
	void beifen(int directorynum) {
		ofstream fout;
		char name[11][12] = { "autonom.txt","first.txt","second.txt","third.txt","forth.txt","fifth.txt","sixth.txt","seventh.txt",\
			"eigth.txt","nith.txt","tenth.txt"};
		fout.open(name[directorynum], ios::out);
		if (!fout.is_open()) {
			cout << "通讯录文件打开失败，无法保存" << endl;
		}
		else {
			int num =0;
			fout << personnum << endl;
			class person* tosave = head->next;
			while (num++ <personnum) {
				fout <<num<<endl
					<<tosave->name<<endl
					<<tosave->phone<<endl
					<<tosave->phone2<<endl
					<<tosave->address<< endl;
				tosave = tosave->next;
			}
		}
		fout.close();
	}
	void load(int directorynum) {
		ifstream fin;
		char name[11][12] = { "autonom.txt","first.txt","second.txt","third.txt","forth.txt","fifth.txt","sixth.txt","seventh.txt",\
			"eigth.txt","nith.txt","tenth.txt" };
		fin.open(name[directorynum], ios::in);
		if (!fin.is_open()) {
			cout << "通讯录目录文件打开失败,无法加载联系人信息" << endl;
		}
		else {
			fin >> personnum;
			int num = personnum;
			class person* toload = head;
			assert(num >= 0);
			while (num--) {
				(toload->next) = new person();
				if (toload->next) {
					char ch = '\n';
					toload = toload->next;
					fin >> toload->num;
					fin.getline(toload->name, 15);
					fin.getline(toload->name, 15);
					fin.getline(toload->phone, 15);
					fin.getline(toload->phone2, 15);
					fin.getline(toload->address, 15);
					/*fin>> toload->name;
					fin>> toload->phone;
					fin>> toload->phone2;
					fin>> toload->address;*/
				}
				else {
					cout << "内存申请出错！！！" << endl;
				}
				
			}
			toload->next = NULL;
			last = toload;
		}
		fin.close();
	}
	void add() {
		int option = 6;

		char phone[12] = "";
		char phone2[12] = "";
		char name[12] = "";
		char address[20] = "";
		int flag = 1;
		do {
			//EXIT, NAME, PHONEONE, PHONETWO, ADDERSS, SAVE
			cout << "*******************************************" << endl
				<< "***     1.输入姓名      2.输入电话1      ***" << endl
				<< "***     3.输入电话2     4.输入地址       ***" << endl
				<< "***     5.保存          0.退出           ***" << endl
				<< "********************************************" << endl << endl;
			//int errornum = 1;
		laba1:
			cout << "请输入你的选择\\>:";
			option = 6;
			cin >> option;
			//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			cin.ignore(1024, '\n');
			switch (option) {
			case NAME:
				cout << "请输入\\>:";
				cin >> name;
				flag = 0;
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case PHONEONE:
				cout << "请输入\\>:";
				cin >> phone;
				flag = 0;
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case PHONETWO:
				cout << "请输入\\>:";
				cin >> phone2;
				flag = 0;
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case ADDERSS:
				cout << "请输入\\>:";
				cin >> address;
				flag = 0;
				cin.clear();
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case SAVE:
				if (flag) {
					cout << "您未输入任何内容，无法保存空的联系人，请您重新选择" << endl;
					goto laba1;
				}
				else {
					class person* now = new person(personnum + 1, phone, phone2, name, address);
					if (now) {
						last->next = now;
						now->next = NULL;
						last = now;
						++personnum;
					}
					else {
						cout << "内存申请失败！！！" << endl << endl;
					}
				}
				break;
			case EXIT:
				cout << "退出\\>:" << endl;
				break;
			default:
				cout << "未知输入，请重新输入！！！" << endl;
				/*++errornum;
				if (errornum % 2 == 0) {
					cout << "请按要求输入！！！！" << endl << endl;
					getchar();
				}*/
				goto laba1;
			}
		} while (option);
	}
	catalog() :personnum(0),head(NULL), last(NULL) {
		head = new person();
		if (head) {
			head->num = 0;
			head->next = NULL;
			last = head;
		}
		else {
			cout << "申请内存失败！！！" << endl << endl;
		}
	};
	~catalog() {
		beifen(0);
		class person* pperson = (*head).next;
		while (1) {
			delete(head);
			head = pperson;
			if (pperson) {
				pperson = head->next;
			}
			else {
				break;
			}
			
		}
	}
};



#if 0
laba1:
cout << "**************************************" << endl
<< "** 1.修改电话1        2. 修改电话2 ****" << endl
<< "** 3.修改名字         4.修改住址   ****" << endl
<< "**       0.退出                    ****" << endl
<< "****************************************" << endl
<< "请输入你的选择\\>:";

#endif