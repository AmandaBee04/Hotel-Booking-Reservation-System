#include <iostream>
#include <iomanip>

using namespace std;

class Presidential;
class Villa;
class Double;

float getPrice();

// The class of staff
class Staff
{
	private : 
		int id , age;
		string name, pw;
		string position;
	
	public : 
		Staff(string name, int id, int age, string position, string pass)
		{
			this->name = name;
			this->id = id;
			this->age = age;
			this->position = position;
			this->pw = pass;
		}
		
		void setName(string n)
		{
			name = n;
		}
		
		void setID(int id)
		{
			id = id;
		}
		
		void setAge(int a)
		{
			age = a;
		}
		
		void setPosition(string p)
		{
			position = p;
		}
		
		string getName()
		{
			return name;
		}
		
		int getID()
		{
			return id;
		}
		
		int getAge()
		{
			return age;
		}
		
		string getPosition()
		{
			return position;
		}

		string getPassword()
		{
			return pw;
		}
		
};


int main(){

}