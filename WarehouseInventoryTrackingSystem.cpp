#include <iostream>
using namespace std;

enum SlotStatus
{
    empty,
    occupied,
    reserved
};

class WarehouseSystem
{
    private: 
    int shelf_units[4][5];//2d array for shelf slots
    SlotStatus slot_status[4][5]; //2d array for status of each slot
    int shipped_units_per_day[7]; //1d array for how many units shipped per day
    int total_units;//total units in warehouse

    public:

    //set all shelves and variables to zero to inititalize the system
    void initialize_system()
    {
        total_units = 0;

        //nested for loops to set enums to empty and units to zero
        for(int row_index = 0; row_index < 4; row_index++)
        {
            for(int col_index = 0; col_index < 5; col_index ++)
            {
                shelf_units[row_index][col_index] = 0;
                slot_status[row_index][col_index] = empty;

            }
        }

        //set shipped units per day to 0
        for(int day_index = 0; day_index < 7; day_index++)
        {
            shipped_units_per_day[day_index] = 0;
        }
    }

    //function to display the current shelf map. E - empty, O - occupied, R - reserved
    void display_shelf_map()
    {
        for(int row_index = 0; row_index < 4; row_index++)
        {
            cout << "Row " << row_index + 1 << ": ";

            for(int col_index = 0; col_index < 5; col_index ++)
            {

                if(slot_status[row_index][col_index] == empty)
                {
                    cout << "E ";
                }
                else if(slot_status[row_index][col_index] == occupied)
                {
                    cout << "O ";
                }
                else
                {
                    cout << "R ";
                }

                
            }
            cout << endl;

        }
    }

    //for loop to reserve slot
    void reserve_slot(int row, int col)
    {
        if(row < 0 || row >= 4 || col < 0 || col >= 5)
        {
            cout << "Invalid submission! " << endl;
            return;
        }

        //only reserve slot if slot is currently empty.
        if(slot_status[row][col] == empty)
        {
            slot_status[row][col] = reserved;
            cout << "Slot successfully reserved. " << endl;
        }
        else
        {
            cout << "Can not reserve shelf space. Slot is not empty." << endl;
            return;
        }
    }

    //function to stock shelves, can only add stock if enum set to empty
    void add_stock(int row, int col, int units)
    {
        

        if(row < 0 || row >= 4 || col < 0 || col >= 5)
        {
            cout << "Invalid submission! " << endl;
            return;
        }
        if(units < 0)
        {
            cout << "Invalid amount of units." << endl;
            return;
        }

        if(slot_status[row][col] == occupied)
        {
            cout << "Cannot add stock, slot is occupied." << endl;
            return;
        }

        shelf_units[row][col] = units;
        slot_status[row][col] = occupied;
        total_units += units;

        cout << "Stock added successfully. Units added: " << units << endl;
        cout << "Total Units in Warehouse: " << total_units << endl;
    }

    void ship_stock(int row, int col, int units, int day)
    {

        if(row < 0|| row >= 4 || col < 0 || col >= 5)
        {
            cout << "Invalid slot position. " << endl;
            return;
        }

        if(day < 0 || day >= 7)
        {
            cout << "Invalid day. " << endl;
            return;
        }

        if (units <= 0)
        {
            cout << "Invalid amount of units." << endl;
            return;
        }

        if(slot_status[row][col] != occupied)
        {
            cout << "Cannot ship stock, slot is empty and stock does not exist." << endl;
            return;
        }

        if(units > shelf_units[row][col])
        {
            cout << "Cannot ship stock, not enough stock items." << endl;
            return;
        }

        int original_units = shelf_units[row][col];
        shelf_units[row][col] -= units;
        total_units -= units;
        shipped_units_per_day[day] += units;
        

        cout << "Stock shipped successfully. Units shipped: " << units << "/" << original_units << endl;

        if(shelf_units[row][col] == 0)
        {
            slot_status[row][col] = empty;
        }
    }

    void display_shipping_report()
    {
        cout << "Shipped Units Per Day: " << endl;
        int total_shipped = 0;

        for(int day_index = 0; day_index < 7; day_index++)
        {
            cout << "Day " << day_index + 1 << ": " << shipped_units_per_day[day_index] << " units" << endl;

            total_shipped += shipped_units_per_day[day_index];
        }
        cout << "Total Units Shipped: " << total_shipped << endl;
        cout << "Total Units Remaining in Warehouse: " << total_units << endl;
    }

    void find_best_shopping_day()
    {

        int best_day = 0;
        int max_shipped = shipped_units_per_day[0];

        for(int day_index = 1; day_index < 7; day_index++)
        {
            if(shipped_units_per_day[day_index] > max_shipped)
            {
                max_shipped = shipped_units_per_day[day_index];
                best_day = day_index + 1;
            }
        }

        cout << "Best shopping day is Day " << best_day << " with " << max_shipped << " units shipped." << endl;
    }

};

int main()
{
    WarehouseSystem warehouse;

    warehouse.initialize_system();
    cout << endl;
    cout << "========================================" << endl;
    warehouse.display_shelf_map();
    cout << endl;
    cout << "========================================" << endl;

    //test cases 
    warehouse.reserve_slot(1, 2);//second row, third column
    warehouse.reserve_slot(3, 3);//fourth row, fourth column
    cout << endl;
    cout << "========================================" << endl;

    warehouse.display_shelf_map();
    cout << endl;
    cout << "========================================" << endl;
    
    warehouse.add_stock(1, 2, 30);//second row, third column
    cout << endl;
    warehouse.add_stock(0, 0, 20);//first row, first column
    cout << endl;
    warehouse.add_stock(3, 4, 50); //fourth row, fifth column
    cout << endl;
    cout << "========================================" << endl;

    warehouse.display_shelf_map();
    cout << endl;
    cout << "========================================" << endl;

    warehouse.reserve_slot(0, 0); //should not be able to reserve slot since it is occupied
    cout << endl;
    warehouse.add_stock(0, 0, 40);//should not be able to add stock since slot is occupied
    cout << endl;
    cout << "========================================" << endl;
    
    warehouse.ship_stock(1, 2, 30, 2);
    cout << endl;
    warehouse.ship_stock(0, 0, 15, 4);
    cout << endl;
    warehouse.ship_stock(3, 4, 50, 1);
    cout << endl;
    cout << "========================================" << endl;

    cout << endl;

    warehouse.display_shelf_map();
    cout << endl;
    cout << "========================================" << endl;
    warehouse.display_shipping_report();
    cout << endl;
    cout << "========================================" << endl;
    warehouse.find_best_shopping_day();
    cout << endl;
    cout << "========================================" << endl;
    
    

    return 0;
}