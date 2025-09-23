#include <iostream> 
#include <string>
using namespace std;

class Customer;
class Presidential;
class Villa;

// This is the class of Double room, which is the parent class of Presidential and Villa.
class Double
{
    protected:
        int roomNum;
        string customer;
        int nights;
        float price;
        char choice;
        string startDate;

    public:
        Double()
        {
            price = 10000;
            nights = 0;
            customer = "";
        }

        void setRoomNum(int rn)
        {   
            roomNum = rn;
        }

        void changeDetails()
        {
            customer = "";
        }

        int get_roomNum()
        {   
            return roomNum;
        }

        void reset(){
            customer = "";
            nights = 0;
            startDate = "";
        }

        string getCustomer()
        {
            return customer;
        }

        int getNights(){
            return nights;
        }

        float getPrice(){
            return price;
        }

    
};

class Presidential : public Double
{
    
};



class Villa : public Double
{
    
};
