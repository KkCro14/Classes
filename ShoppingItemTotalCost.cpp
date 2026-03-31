#include <iostream>
using namespace std;

class ShoppingItem
{
    private:
    string item_name;
    float item_price;
    int item_quantity;

    public: 

    void set_item(string name, float price, int quantity)
    {   
       item_name = name;

       if(price > 0)
       {
        item_price = price;
       }

       if(quantity > 0)
       {
        item_quantity = quantity;
       }
       else
       {
        quantity = 1;
       }
    }

    float get_total()
    {
        return item_price * item_quantity;
    }

    void display_bill()
    {
        cout << "==========Bill:==========" << endl;
        cout << "Item name: " << item_name << endl;
        cout << "Item cost: $" << item_price << endl;
        cout << "Quantity of items: " << item_quantity << endl;
        cout << "Total cost: $" << get_total() << endl;
    }



};

int main()
{
    ShoppingItem item;
    string name;
    float price;
    int quantity;
   
    cout << endl;
    cout << "Enter item name: ";
    cin >> name;
    
    cout << "Enter item price: $";
    cin >> price;

    cout << "Enter item quantity: ";
    cin >> quantity;
    cout << endl;

    item.set_item(name, price, quantity);
    item.get_total();
    item.display_bill();
    
    cout << endl;

    return 0;
}
