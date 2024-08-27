#include<iostream>

using namespace std;

int main() {
    int num{100};
    int num1{200};

    cout << "Local num is " << num << " in the main block" << endl;

    {
        int num{300};
        cout << "Local num is " << num << " in the inner block in main" << endl;
        cout << "Inner block in main can see out, num1 is " << num1 << endl;
    }

    cout << "cannot see inside block, local num is " << num << " in main" << endl;

    return 0;
}