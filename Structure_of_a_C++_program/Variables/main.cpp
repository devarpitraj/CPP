#include <iostream>

using namespace std;

int main()
{
    long int num{56890276892478397}; // C++ style iniialization throws error during overflow
    // long int num = 56890276892478397;   //C style initialization throws no error during overflow
    //  only gives warning (shows garbahe value)
    cout << num;

    return 0;
}