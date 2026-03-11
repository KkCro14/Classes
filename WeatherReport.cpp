#include <iostream>
using namespace std;

//class for weather report
class WeatherReport
{
    private: 
    float temp[7][2]; //[days][temps taken per day]

    public:

    //function to input temps
    void input_temp()
    {
        cout << "Input weekly temperatures below: " << endl;
        cout << endl;

        //for loop to input temperatures
        for(int day_index = 0; day_index < 7; day_index++)
        {
            cout << "Day " << (day_index +1) << ": " << endl;

            for(int time_index = 0; time_index < 2; time_index++)
            {
                cout << "\tTemp at time " << (time_index + 1) << ": ";
                cin >> temp[day_index][time_index];
            }

        }

    }

    //function to display temperatures
    void display_temperature()
    {
        cout << endl;
        cout << "===Weather Table 7 x 2:===" << endl;

        for(int day_index = 0; day_index < 7; day_index++)
        {
            for(int time_index = 0; time_index < 2; time_index++)
            {
                
                cout << temp[day_index][time_index] << "\t";
            }

            cout << endl;

        }
        cout << endl;
    }

    //function to calculate average of each day, then find day with highest average and display it as hottest day
    void display_hottest_day()
    {
        float highest_average = 0;
        int hottest_day;
        
        for(int day_index = 0; day_index < 7; day_index++)
        {
            float sum = 0;
            for(int time_index = 0; time_index < 2; time_index++)
            {
                sum += temp[day_index][time_index];
            }

            float average = sum/2;
            cout << "Average for day " << day_index + 1 << ": " << average << endl;

            if(average > highest_average)
            {
                highest_average = average;
                hottest_day = day_index + 1;
                
            }
        }

        cout << endl;
        cout << "Hottest day: Day " << hottest_day << endl;
        
    }

};

int main()
{
    WeatherReport report;

    //function calls
    report.input_temp();
    report.display_temperature();
    report.display_hottest_day();

    return 0;
}