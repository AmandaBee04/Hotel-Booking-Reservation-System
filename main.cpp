#include<iostream>
#include<iomanip>

#include"staff.cpp"
#include"ui.cpp"
#include"classRoom.cpp"

using namespace std;

void printWelcome();
int availableD(Double room[]);
int availableP(Presidential room[]);
int availableV(Villa room[]);

int main(){
	Customer *head = NULL;
	int choice;
	// Declaring 3 types of rooms, each with 10 space to represent 10 rooms for storing customer.
	Double dRoom[10];
	Presidential pRoom[10];
	Villa vRoom[10];
	// Initialize the Staff members in the system (3 staffs)
	Staff s[3] = {Staff("Amanda", 1234, 18, "BOSS", "imBoss"), Staff("Abu", 2345, 35, "Manager", "imManager"), Staff("Ahmad", 3456, 25, "Receptionist", "imReceptionist")};
}

// Function to check how many double rooms are available
int availableD(Double room[]){
	int avai = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (room[i].getCustomer() == "")
		{
			avai ++;
		}
	}
	return avai;
}

// Functions to check how many presidential rooms are available
int availableP(Presidential room[]){
	int avai = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (room[i].getCustomer() == "")
		{
			avai ++;
		}
	}
	return avai;
}

// Function to check how many villas are available
int availableV(Villa room[]){
	int avai = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (room[i].getCustomer() == "")
		{
			avai ++;
		}
	}
	return avai;
}