#pragma once

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>

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


	void  changenum(int anum) {
		num = anum;
	}
	void changephone(char* aphone, int a) {
		if (a) {
			strcpy(phone2, aphone);
		}
		else {
			strcpy(phone, aphone);
		}
	}
	void changename(char*aname) {
		strcpy(name,aname);
	}
	void changeaddress(char*aaddress) {
		strcpy(address, aaddress);
	}
	void changenext(class person* anext) {
		next = anext;
	}
	/*class person* retunext(void) {
		return next;
	}
	void returnstate(int* anum, char** aphone, char** aname) {
		*anum = num;
		*aphone = phone;
		*aname = name;
	}*/
public:
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
		class person* toprin = head->next;
		while (personnum--) {
			prin(toprin);
			toprin = toprin->next;
		}
	}
	void prin(class person* toprin) {
		cout << "序号：  " <<setw(5) << toprin->num
			<< "姓名：  " <<setw(16) <<"toprin->name"
			<< "电话1： " <<setw(16) <<"toprin->phone"
			<< "电话2： " <<setw(16) <<"toptin->phne2"
			<< "地址：  " <<setw(20) <<"toprin->address" << endl;
	}
	//均返回要查找的前一个元素
	class person* seekname() {
		char aname[12] = { 0 };
		cout << "请输入你要查找的名字\\>:";
		cin >> aname;
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
		cin >> num;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
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
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		class person* tosee = head;
		while (tosee->next) {
			if (!strcmp(phone, tosee->phone)) {
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
				if (cmp((max->next)->name, (whenj->next)->name) < 0) {
					max = whenj;
				}
				whenj = whenj->next;
			}
			if (max != wheni) {
				class person* temp = max->next;
				max->next = (max->next)->next;
				temp->next = (wheni->next)->next;
				wheni->next = temp->next;
			}
			wheni = wheni->next;
			wheni->num = i + 1;
		}
	}
	int cmp(char* name1, char* name2) {
		return strcmp(name1, name2);
	}
	void beifen() {

	}
	void load() {

	}
public:
	void add() {
		int option = 6;

		char phone[12] = {};
		char phone2[12] = {};
		char name[12] = {};
		char address[20] = {};
		int flag = 1;

		do {
			cout << "******************************************" << endl
				<< "***     1.输入姓名      2.输入电话1      ***" << endl
				<< "***     3.输入电话2     4.输入地址       ***" << endl
				<< "***     5.保存          0.退出           ***" << endl
				<< "********************************************" << endl << endl;
		laba1:
			cout << "请输入你的选择\\>:";
			option = 6;
			cin >> option;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			switch (option) {
			case NAME:
				cout << "请输入\\>:";
				cin >> name;
				flag = 0;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case PHONEONE:
				cout << "请输入\\>:";
				cin >> phone;
				flag = 0;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case PHONETWO:
				cout << "请输入\\>:";
				cin >> phone2;
				flag = 0;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case ADDERSS:
				cout << "请输入\\>:";
				cin >> address;
				flag = 0;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			case SAVE:
				if (flag) {
					cout << "您未输入任何内容，无法保存空的联系人，请您重新选择" << endl;
					goto laba1;
				}
				else {
					class person* now = new person(personnum + 1, phone, phone2, name, address);

					if (!head) {
						head = now;
						last = now;
						head->next = NULL;
					}
					else {
						last->next = now;
						now->next = NULL;
						last = now;
					}
					++personnum;
				}
				break;
			case EXIT:
				cout << "退出\\>:" << endl;
				break;
			default:
				cout << "未知输入，请重新输入！！！" << endl;
				goto laba1;
			}
		} while (option);
	}
	catalog() :personnum(0),head(NULL), last(NULL) {
		head = new(person);
		head->num = 0;
		head->next = NULL;
		last = head;
	};
	~catalog() {
		class person* pperson = (*head).next;
		do {
			delete(head);
			head = pperson;
			pperson = head->next;
		} while (head);
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