#include<iostream>

class DivideByZeroException {};
class NegativeValueException {
    friend std::ostream &operator<< (std::ostream &os, const NegativeValueException &obj);
    public:
    NegativeValueException() {
        std::cerr << "Negative Value Error" << std::endl;
    }
};

std::ostream &operator<< (std::ostream &os, const NegativeValueException &obj) {
    return os;
}

double calc_avg(int sum, int num) {
    if(num == 0)
        throw DivideByZeroException(); 
    if(sum < 0 || num < 0)
        throw NegativeValueException();
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
        avg = calc_avg(sum, num);
        //avg = static_cast<double>(sum) / num;
        std::cout << "Average : " << avg << std::endl;
    }
    catch(const DivideByZeroException &ex) {
        std::cerr << "Can't divide by zero" << std::endl;
    }
    catch(const NegativeValueException &ex) {
        std::cerr << ex << std::endl;
    }

    std::cout << "Program ends" << std::endl;

    return 0;
}