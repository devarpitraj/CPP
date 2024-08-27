#include<iostream>
#include<memory>
#include<vector>

class Test {
    friend std::ostream &operator<< (std::ostream &os, const Test &obj);
    private:
        int data;
    public:
        Test(int data = 0)
            :data{data} {
                std::cout << "Test constr for " << data << std::endl;
            }
        int get_data() const { return data; }
        ~Test() { std::cout << "Test destr for " << data << std::endl; }
};

void my_deleter(Test* ptr) {
    std::cout << "using my custom deleter" << std::endl;
    delete ptr;
}

int main() {

    {
        //using fuction
        std::shared_ptr<Test> ptr1 { new Test(), my_deleter };
    }
    std::cout << std::endl;
    {
        //using a lambda expression
        std::shared_ptr<Test> ptr2 (new Test{100},
            [] (Test *ptr) {
                std::cout << "using my custom lambda deleter" << std::endl;
                delete ptr;
            });
    }

    return 0;
}