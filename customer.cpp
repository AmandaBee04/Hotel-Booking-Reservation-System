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