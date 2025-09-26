#include<iostream>
#include<iomanip>

using namespace std;

class Presidential;
class Villa;
class Double;

void noCustomer();
void icNotFound();

class Customer{
	string ic;
	string name;
	Customer *next;

	public:
		Customer(){
			cout << "\n                                                                                 Enter name : ";
			getline(cin, name);
			cout << "\n                                                                            Enter IC number : ";
			getline(cin, ic);
			next = NULL;
		}
		void setData(){
			cout << "\n                                                                                 Enter name : ";
			getline(cin, name);
			cout << "\n                                                                            Enter IC number : ";
			getline(cin, ic);
			
		}

		void setNext(Customer * n){
			next = n;
		}

		string getName(){
			return name;
		}

		string getIC(){
			return ic;
		}

		Customer * getNext(){
			return next;
		}

		~Customer(){
			cout << endl;
			cout << "                                                                                 " << name << " is deleted!! " << endl;		
		}
		
		// friend void addCustomer(Customer &c, Double d[], Presidential p[], Villa v[]); // friend function
		friend void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]);
		friend void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]);
		friend void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]);
};

void printList(Customer *head){
	if (head == NULL)
	{
		noCustomer();
	}
	
	while (head->getNext() != NULL){
		cout << "\n                                                                                       " << head->getName() << endl;
		head = head->getNext();
	}
	cout << "\n                                                                                       " << head->getName() << endl;
}

void freeList(Customer *head){
	if (head == NULL)
	{
		return;
	}
	while(head->getNext() != NULL){
		Customer *tmp = head;
		head = head->getNext();
		delete tmp;
	}
	delete head;
	return;
}

void checkNull(Customer *head, Customer *n){
	while(head->getNext() != NULL){
		head = head->getNext();
	}
	head->setNext(n);
}

void delCus(Customer *head, Customer **head2, Double d[], Presidential p[], Villa v[]){
	if (head == NULL){
		noCustomer();
		return;
	}
		string ic;
		cout << "\n                                     Enter customer IC number that you would like to delete : ";
		cin >> ic;
		for(int i = 0; i < 10; i++){
			if(d[i].getCustomer() == ic){
				d[i].reset();
			}
			if(p[i].getCustomer() == ic){
				p[i].reset();
			}
			if(v[i].getCustomer() == ic){
				v[i].reset();
			}
		}
		if (head->getIC() == ic){
			if(head->getNext() == NULL){
				head->setNext(NULL);
				delete head;
				*head2 = NULL;
				return;
			}
			Customer *tmp = head->getNext();
			delete head;
			*head2 = tmp;
			return;
		}
		if(head->getNext() == NULL){
				icNotFound();
				return;
			}
		while(head->getNext()->getIC() != ic){
			head = head->getNext();
			if(head->getNext() == NULL){
				icNotFound();
				return;
			}
		}
		Customer *tmp = head->getNext();
		head->setNext(head->getNext()->getNext());
		delete tmp;
}

void noCustomer()
{
	cout << "                                                                     _______________________________________ " << endl;
    cout << "                                                                    !                                       !" << endl;
    cout << "                                                                    !           No customer yet!!           !" << endl;
    cout << "                                                                    !_______________________________________!" << endl;
}

void icNotFound()
{
	cout << endl;
	cout << "                                                                     _______________________________________ " << endl;
    cout << "                                                                    !                                       !" << endl;
    cout << "                                                                    !   No customer with that IC number!!   !" << endl;
    cout << "                                                                    !_______________________________________!" << endl;
}