#include<iostream>
#include<iomanip>

using namespace std;

double calc_cost (double base_cost, double tax_rate = 0.06, double shipping = 3.50);

double calc_cost (double base_cost, double tax_rate, double shipping) {
    return base_cost += (base_cost * tax_rate) + shipping;
}

int main() {
    double cost {0};
    cost = calc_cost(100, 0.08, 5.50);  //use no defaults
    
    cout << fixed << setprecision(2);
    cout << "1. No defaults " << cost << endl;

    cost = calc_cost(200,0.09); //only use shipping default value
    cout << "1. One defaults " << cost << endl;

    cost = calc_cost(100);  //use all default arguments values
    cout << "1. All defaults " << cost << endl;

    return 0;
}