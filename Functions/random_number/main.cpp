#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    int random_number {};
    size_t count {10};
    int min {1};    //inclusive
    int max {6};    //inclusive

    cout << "RAND_MAX on my system is:" << RAND_MAX << endl;
    srand(time(nullptr));   //seed the generator
    //if u don't seed the generator same sequence will be generated each time

    for(size_t i{1}; i<=count; i++) {
        random_number = rand() % max + min;
        cout << random_number << endl;
    }

    return 0;
}