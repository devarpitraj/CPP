#include<iostream>

using namespace std;   //uses all identifiers in std library  (naming conflicts still may occur)
/* specific identifiers can also be used
using std::cout;
using std::cin;
using std::endl;
*/

int main() {
    int num;
    cout << "Enter a number:";
    cin >> num;
    cout << "The number is :" << num << endl;
    return 0;
}