#include<iostream>

double calc_avg(int sum, int num) {
    if(num == 0)
        throw 0; 
    if(sum < 0 || num < 0)
        throw std::string{"Negative value error"};
    return static_cast<double>(sum) / num;
}

int main() {
    int sum {};
    int num {};
    double avg {};

    std::cout << "Enter sum : ";
    std::cin >> sum;
    std::cout << "Enter num : ";
    std::cin >> num;
    //avg = static_cast<double>(sum) / num;
    //std::cout << avg << std::endl;

    try {
        if(num == 0)
            throw 0;
        avg = calc_avg(sum, num);
        //avg = static_cast<double>(sum) / num;
        std::cout << "Average : " << avg << std::endl;
    }
    catch(int &ex) {
        std::cerr << "Can't divide by zero" << std::endl;
    }
    catch(std::string &ex) {
        std::cerr << ex << std::endl;
    }

    std::cout << "Program ends" << std::endl;

    return 0;
}