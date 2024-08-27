#include<iostream>
#include<string>

using namespace std;

int main() {
    int scores[] {95, 68, 90, -1};
    int *score_ptr {scores};

    cout << "Printing array elemets:" << endl;
    while (*score_ptr != -1)
        cout << *score_ptr++ << endl;

    cout << "\n----------------" << endl;
    string s1 {"Frank"};
    string s2 {"Frank"};

    string *p1 {&s1};
    string *p2 {&s2};
    string *p3 {&s1};

    cout << boolalpha;
    cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl;
    cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl;
    cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl;
    cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

    cout << "\n------------------" << endl;
    char name[] {"Frank"};
    char *ptr1 {&name[1]};
    char *ptr2 {&name[4]};

    cout << "In the string " << name << ", " << *ptr2 << " is " << (ptr2 - ptr1) << " characters away from " << *ptr1 << endl;

    return 0;
}