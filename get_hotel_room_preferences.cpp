#include <iostream>
#include <iomanip>
using namespace std;

class Double;
class Presidential;
class Villa;
class Customer;

//ui function 
void booking_menu(Customer &c, Double d[], Presidential p[], Villa v[]);
void printThanks();
void getChoice();
void editMenu();
void editMenu2();
void noRoom();
void noEnough();
void re_enter();

int availableD(Double room[]);
int availableP(Presidential room[]);
int availableV(Villa room[]);
void roomBooked(Customer &c, Double d[], Presidential p[], Villa v[]);

int calcD(Customer &c, Double d[]);
int calcP(Customer &c, Presidential p[]);
int calcV(Customer &c, Villa v[]);
