#include<iostream>
#include<iomanip>

using namespace std;

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