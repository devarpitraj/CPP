#include<iostream>
#include<climits>  //<climits> is for integer types
                   //<cfloat> is for floating type
using namespace std;

int main()  {
    cout << "Size information::\n" ;
    cout << "Char:" << sizeof(char) << " Bytes" << endl;
    cout << "Int:" << sizeof(int) << " Bytes" << endl;
    cout << "Double:" << sizeof(double) << " Bytes" << endl;


    //values defined in <climits>
    cout << "Minimum Values::" << endl;
    cout << "Char:" << CHAR_MIN << endl;
    cout << "Int:" << INT_MIN << endl;
    cout << "Short:" << SHRT_MIN << endl;

    //CHAR_MAX, INT_MAX, SHRT_MAX, LONG_MAX, etc.

    //sizeof variables
    int age {21};
    cout << "age is " << sizeof(age) << " bytes" << endl;
    //or
    cout << "age is " << sizeof age << " bytes" << endl;

    double wage {765.836};
    cout << "wage is " << sizeof wage  << " bytes" << endl;
    //or
    cout << "wage is " << sizeof(wage) << " bytes" << endl;

    return 0;
}