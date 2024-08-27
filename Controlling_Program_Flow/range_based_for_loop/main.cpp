#include<iostream>
using namespace std;

int main() {
    int scores[] {10,20,30};
    
    for(auto score:scores)
        cout << score << endl;
    cout << endl;
    for (auto val:{1,2,3})
        cout << val << endl;
    return 0;
}