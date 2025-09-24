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

void editRoom(Customer &c, Double d[], Presidential p[], Villa v[]){
    int choice, roomtype, numNights, numRooms, curRoom;
    string date;
    do{
        editMenu();
        cout << endl << "                                                                            Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            roomBooked(c, d, p, v);
            editMenu2();
            cout << endl << "                                                                             Enter your choice : ";
            cin >> roomtype;
            switch (roomtype)
            {
                case 1:
                    cout << "\n                                                                   Enter new number of room(s) : ";
                    cin >> numRooms;
                    cout << "\n                                                                      Enter number of night(s) : ";
                    cin >> numNights;
                    cout << "\n                                                          Enter start check-in date [DD-MM-YY] : ";
                    cin >> date;
                    cout << endl;
                    curRoom = calcD(c, d);
                    if (curRoom < numRooms){
                        if (availableD(d) == 0)
                        {
                            noRoom();
                            continue;
                        }
                        else if (availableD(d) < numRooms - curRoom)
                        {
                            noEnough();
                            continue;
                        }
                        else{
                            for (int i = 0; i < numRooms - curRoom; ++i){
                                for (int j = 0; j < 10; ++j)
                                {
                                    if (d[j].customer == "")
                                    {
                                        d[j].customer = c.ic;
                                        d[j].nights = numNights;
                                        break;
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    else if (curRoom > numRooms){
                        for (int i = 0; i < curRoom - numRooms; ++i){
                            for (int j = 0; j < 10; ++j)
                            {
                                if (d[j].customer == c.ic)
                                {
                                    d[j].reset();
                                    break;
                                }
                            }
                        }
                    }
                    break;
                    
                case 2:
                    cout << "\n                                                                   Enter new number of room(s) : ";
                    cin >> numRooms;
                    cout << "\n                                                                      Enter number of night(s) : ";
                    cin >> numNights;
                    cout << "\n                                                          Enter start check-in date [DD-MM-YY] : ";
                    cin >> date;
                    cout << endl;
                    curRoom = calcP(c, p);
                    if (curRoom < numRooms){
                        if (availableP(p) == 0)
                        {
                            noRoom();
                            continue;
                        }
                        else if (availableP(p) < numRooms - curRoom)
                        {
                            noEnough();
                            continue;
                        }
                        else{
                            for (int i = 0; i < numRooms - curRoom; ++i){
                                for (int j = 0; j < 10; ++j)
                                {
                                    if (p[j].customer == "")
                                    {
                                        p[j].customer = c.ic;
                                        p[j].nights = numNights;
                                        break;
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    else if (curRoom > numRooms){
                        for (int i = 0; i < curRoom - numRooms; ++i){
                            for (int j = 0; j < 10; ++j)
                            {
                                if (p[j].customer == c.ic)
                                {
                                    p[j].reset();
                                    break;
                                }
                            }
                        }
                    }
                    break;

                case 3:
                    cout << "\n                                                                   Enter new number of room(s) : ";
                    cin >> numRooms;
                    cout << "\n                                                                      Enter number of night(s) : ";
                    cin >> numNights;
                    cout << "\n                                                          Enter start check-in date [DD-MM-YY] : ";
                    cin >> date;
                    cout << endl;
                    curRoom = calcV(c, v);
                    if (curRoom < numRooms){
                        if (availableV(v) == 0)
                        {
                            noRoom();
                            continue;
                        }
                        else if (availableV(v) < numRooms - curRoom)
                        {
                            noEnough();
                            continue;
                        }
                        else{
                            for (int i = 0; i < numRooms - curRoom; ++i){
                                for (int j = 0; j < 10; ++j)
                                {
                                    if (v[j].customer == "")
                                    {
                                        v[j].customer = c.ic;
                                        v[j].nights = numNights;
                                        break;
                                    }
                                }
                            }
                        }
                        continue;
                    }
                    else if (curRoom > numRooms){
                        for (int i = 0; i < curRoom - numRooms; ++i){
                            for (int j = 0; j < 10; ++j)
                            {
                                if (v[j].customer == c.ic)
                                {
                                    v[j].reset();
                                    break;
                                }
                            }
                        }
                    }
            }
            break;
        
        case 2:
            roomBooked(c, d, p, v);
            editMenu2();
            cout << endl << "                                                                          Enter your choice : ";
            cin >> roomtype;
            cout << "\n                                                               Enter new number of night(s) : ";
            cin >> numNights;
            switch (roomtype)
            {
            case 1:
                for (int i = 0; i < 10; ++i){
                    if (d[i].customer == c.ic){
                        d[i].nights = numNights;
                    }
                }
                break;
            
            case 2:
                for (int i = 0; i < 10; ++i){
                    if (p[i].customer == c.ic){
                        p[i].nights = numNights;
                    }
                }
                break;
            
            case 3:
                for (int i = 0; i < 10; ++i){
                    if (v[i].customer == c.ic){
                        v[i].nights = numNights;
                    }
                }
                break;
            }
            break;
        case 3:
            editCustomer(&c, d, p, v);
            break;
        }
    }while (choice != 4);
}

void editCustomer(Customer *c, Double d[], Presidential p[], Villa v[]){
    int choice;
    string ic;
    cout << "\n                                                Enter 1 to change IC Number, 2 to change Name : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\n                                                                          Enter new IC Number : ";    
        cin >> ic;
        for (int i = 0; i < 10; ++i){
            if (d[i].customer == c->ic){
                d[i].customer = ic;
            }
            if (p[i].getCustomer() == c->ic){
                p[i].customer = ic;
            }
            if (v[i].getCustomer() == c->ic){
                v[i].customer = ic;
            }
        }
        c->ic = ic;
        break;
    case 2:
        string name;
        cout << "\n                                                                               Enter new Name : ";
        cin.ignore();
        getline(cin, name);
        c->name = name;
        break;
    }
}

void roomBooked(Customer &c, Double d[], Presidential p[], Villa v[]){

    cout << "\n\n";
    cout << "                                                                              ,---.          ,---." << endl;
    cout << "                                                                             / /\"`\\.--\"\"\"--./,'\"\\ \\" << endl;
    cout << "                                                                             \\ \\    _       _   / /" << endl;
    cout << "                                                                              `./  / __   __ \\  \\,'" << endl;
    cout << "                                                                               /    /_O)_(_O\\    \\" << endl;
    cout << "                                                                               |  .-'  ___  `-.  |" << endl;
    cout << "                                                                            .--|       \\_/       |--." << endl;
    cout << "                                                                          ,'    \\   \\   |   /   /    `." << endl;
    cout << "                                                                         /       `. `--^--'  ,'       \\" << endl;
    cout << "                                                                      .-\"\"\"\"\"\"-.    `--.___.--'    .-\"\"\"\"\"\"-." << endl;
    cout << "                                                      .--------------/         \\------------------/         \\--------------." << endl;
    cout << "                                                      | .------------\\         /------------------\\         /------------. |" << endl;
    cout << "                                                      | |             `-`--`--'                    `--'--'-'             | |" << endl;
    cout << "                                                      | |                    + ===================== +                   | |" << endl;
    cout << "                                                      | |                    | Rooms that you booked |                   | |" << endl;
    cout << "                                                      | |                    + ===================== +                   | |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                        Double Room : " << calcD(c, d) << "                         | |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                  Presidential Room : " << calcP(c, p) << "                         | |" << endl;
    cout << "                                                      | |                                                                | |" << endl;
    cout << "                                                      | |                              Villa : " << calcV(c, v) << "                         | |" << endl;
    cout << "                                                      | |________________________________________________________________| |" << endl;
    cout << "                                                      |____________________________________________________________________|" << endl;
    cout << "                                                                            )__________|__|__________(" << endl;
    cout << "                                                                           |            ||            |" << endl;
    cout << "                                                                           |____________||____________|" << endl;
    cout << "                                                                             ),-----.(      ),-----.(  " << endl;
    cout << "                                                                           ,'   ==.   \\    /  .==    `." << endl;
    cout << "                                                                          /            )  (            \\" << endl;
    cout << "                                                                          `==========='    `==========='\n" << endl;
    cout << endl;
}
