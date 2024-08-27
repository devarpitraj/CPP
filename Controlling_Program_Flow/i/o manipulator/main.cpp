#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main() {
    vector<double> temperatures {89.5,92.3,74.8,90};
    double total{};
    double average{};

    for(auto temp:temperatures)
        total += temp;
    
    average = total / temperatures.size();

    cout << "Average is " << average << endl;

    cout << fixed << setprecision(1);
    cout << "Average is(manipulated output) = " << average << endl;

    return 0;
}