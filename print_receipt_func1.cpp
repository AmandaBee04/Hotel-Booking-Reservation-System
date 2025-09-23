#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

class Double;
class Presidential;
class Villa;
class Customer;

int calcD(Customer &c, Double d[]);
int calcP(Customer &c, Presidential p[]);
int calcV(Customer &c, Villa v[]);

void roomBookedForReceipt(Customer *c, Double d[], Presidential p[], Villa v[]);



// This is the function to print the receipt. It is broken down into multiple small parts to make it easier to read.
void print_receipt_func(Customer *c, Double d[], Presidential p[], Villa v[]){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(10000, 99999);
    int invoiceNum = dis(gen);

    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;


    cout << "                                                       Invoice Number : " << invoiceNum << "                                                       " << endl;
    cout << "                                                      Date           : " << day << "/" << month << "/" << year << "                                                  | " << endl;
    cout << "                                                       BILL TO        : " << setw(30) << left << c -> getName() << "                              " << endl;
    cout << "                                                       IC             : " << setw(30) << left << c -> getIC() << "                              " << endl;
    cout << "                                                                                                                                  " << endl;
  


    cout << "                                                     " << "   Total Payment : RM " << setw(53) << right << totalAmount(c, d, p, v) << "    " << endl;


    cout << endl;
}

