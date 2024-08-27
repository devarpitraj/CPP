#include<iostream>

class Test {
    
    public:
        int data;
        Test(int data = 0) : data{data} {std::cout << "constr for " << data << std::endl;}
        ~Test() {std::cout << "destr for " << data << std::endl;}
        Test(const Test &source)
            :data{source.data} {
            std::cout << "copy constr" << std::endl;
        }
        //Test& operator= (const Test &rhs);
};

/*Test& Test::operator= (const Test &rhs) {
    std::cout << "Overloaded operator" << std::endl;
    if(this == &rhs) return *this;

    this->data = rhs.data;
    return *this;
}*/

int main() {
    Test t1{100};
    Test t2;
    Test t3{500};
    std::cout << t3.data << std::endl;
    t2 = t1 = t3;
    return 0;
}