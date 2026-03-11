#include <iostream>
using namespace std;

// declare class for student
class student
{
    private: //student name and marks are private

    string student_name;
    int marks;

    public:
//access private data through functions in public
   void set_student_data(string name, int grade)
    {
        marks = grade;

        //if marks < 0 set to 0
        if(grade < 0)
        {
            marks = 0;
        }    
        // of marks > 100 set to 100
        if(grade > 100)
        {
            marks = 100;
        }

        student_name = name; //set student name in private using public variable
    }

    bool pass()
    {
        return marks >= 50; //if true, bool is true and pass. else false and fail
    }

    //fucntion to display results
    void display_result()
    {
        cout << endl << "===== Results: =====" << endl;
        cout << "Student Name: " << student_name << endl;
        cout << "Marks: " << marks << endl;
        cout << "Result: " << (pass()? "PASS" : "FAIL") << endl; //display pass if bool was true, fail if false
    }
};


int main()
{
    student student_1;
    string name;
    int grade;

    //user inputs
    cout << endl;
    cout << "Input student first name: ";
    cin >> name;

    cout << "Input marks: ";
    cin >> grade;

    //call functions located in public section of class
    student_1.set_student_data(name, grade); 
    student_1.display_result();


    return 0;
}





