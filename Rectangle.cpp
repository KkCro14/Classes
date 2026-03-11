#include <iostream>
using namespace std;

class rectangle
{
    private:
    float length;
    float width;

    public:
    void set_dimensions(float rect_length, float rect_width)
    {
        length = rect_length;
        width = rect_width;
    }

    float get_area()
    {
        return (length * width);
    }

    float get_perimeter()
    {
        return (length * 2) + (width * 2);
    }

    void display_details()
    {
        cout << endl;
        cout << "=================================" << endl;
        cout << "Rectangle length: " << length << endl;
        cout << "Rectangle width: " << width << endl;
        cout << "Rectangle area: " << get_area() << endl;
        cout << "Rectangle perimeter: " << get_perimeter() << endl;

    }
};

int main()
{
    rectangle rect_1;
    float rect_length;
    float rect_width;

    cout << "Enter rectangle length: ";
    cin >> rect_length;

    cout << "Enter rectangle width: ";
    cin >> rect_width;
    

    rect_1.set_dimensions(rect_length, rect_width);
    rect_1.display_details();


    return 0;
}