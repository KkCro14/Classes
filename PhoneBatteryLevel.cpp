#include <iostream>
using namespace std;

class PhoneBattery
{
    private:
    int battery_level;

    public:

    PhoneBattery()
    {
        battery_level = 50;
    }

    void charge(int amount)
    {
        if(amount > 0)
        {
            battery_level += amount;
            
            if(battery_level > 100)
            {
                battery_level = 100;
            }
        }
    }

    void use_phone(int minutes)
    {
        if(minutes > 0)
        {
            battery_level -= minutes;

            if(battery_level < 0)
            {
                battery_level = 0;
            }
        }
    }

    void display()
    {
        cout << "Battery level: " << battery_level << "% " << endl;
    }

};

int main()
{
    PhoneBattery phone_1;
    int amount;
    int minutes;

    phone_1.display();
    cout << "How many percentages would you like to charge your phone?:";
    cin >> amount;
    cout << endl;

    phone_1.charge(amount);
    phone_1.display();

    cout << "How mant minutes would you like to use your phone?: " << endl;
    cin >> minutes; 

    phone_1.use_phone(minutes);
    phone_1.display();


    return 0;
}