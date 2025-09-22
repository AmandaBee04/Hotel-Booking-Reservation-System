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

void get_hotel_room_preferences(Customer &c, Double d[], Presidential p[], Villa v[]){
    int roomtype, numNights, numRooms, choice ;
    string roomtypeCopy, startDate;

    do{
        booking_menu(c, d, p, v);
        cout<<endl<<"\n                                                                     Please enter your choice(1-3) : ";
        cin>>roomtype;

        if(roomtype > 3 || roomtype < 1){
            re_enter();
            choice = 2;
            continue ;
        }

        cout<<"\n                                   Please enter number of rooms that you needed for this room type : ";
        cin>>numRooms;

        
        cout<<"\n                                          Please enter number of night(s) you are planning to stay : ";
        cin>>numNights;

        cout<<"\n                                                        Please enter your check-in date [DD-MM-YY] : ";
        cin>>startDate;

        switch (roomtype){
            case 1:
                roomtypeCopy = "Double Room";
                if (availableD(d) == 0)
                {
                    noRoom();
                    continue;
                }
                else if (availableD(d) < numRooms)
                {
                    noEnough();
                    continue;
                }
                else{
                    for (int i = 0; i < numRooms; ++i){
                        for (int j = 0; j < 10; ++j)
                        {
                            if (d[j].customer == "")
                            {
                                d[j].customer = c.ic;
                                d[j].nights = numNights;
                                d[j].startDate = startDate;
                                break;
                            }
                        }
                    }
                }
                break;
                
            case 2:
                roomtypeCopy = "Presidential Room";
                if (availableP(p) == 0)
                {
                    noRoom();
                    continue;
                }
                else if (availableP(p) < numRooms)
                {
                    noEnough();
                    continue;
                }
                else{
                    for (int i = 0; i < numRooms; ++i){
                        for (int j = 0; j < 10; ++j)
                        {
                            if (p[j].customer == "")
                            {
                                p[j].customer = c.ic;
                                p[j].nights = numNights;
                                p[j].startDate = startDate;
                                break;
                            }
                        }
                    }
                }
                break;

            case 3:
                roomtypeCopy = "Villa";
                if (availableV(v) == 0)
                {
                    noRoom();
                    continue;
                }
                else if (availableV(v) < numRooms)
                {
                    noEnough();
                    continue;
                }
                else{
                    for (int i = 0; i < numRooms; ++i){
                        for (int j = 0; j < 10; ++j)
                        {
                            if (v[j].customer == "")
                            {
                                v[j].customer = c.ic;
                                v[j].nights = numNights;
                                v[j].startDate = startDate;
                                break;
                            }
                        }
                    }
                }
                break;
        }
        
        printThanks();
        getChoice();
        cin>>choice;

    } while (choice == 2);

    roomBooked(c, d, p, v);
}
