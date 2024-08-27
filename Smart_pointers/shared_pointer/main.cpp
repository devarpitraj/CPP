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
        
        ~Test() { std::cout << "Test destr for " << data << std::endl; }
};

std::ostream &operator<< (std::ostream &os, const Test &obj) {
    os << obj.data;
    return os;
}


void func(std::shared_ptr<Test> ptr) {
    std::cout << "Use count: " << ptr.use_count() << std::endl;
}

int main() {
    std::shared_ptr<int> p1 {new int {100}};
    std::cout << "Use count: " << p1.use_count() << std::endl;

    std::shared_ptr<int> p2;
    p2 = p1;
    std::cout << "Use count: " << p2.use_count() << std::endl;

    p1.reset();
    std::cout << "Use count: " << p1.use_count() << std::endl;
    std::cout << "Use count: " << p2.use_count() << std::endl;

    std::cout << std::endl;

    std::shared_ptr<Test> p3 = std::make_shared<Test> ();
    func(p3);   //pass by data - copy created 
    std::cout << "Use count: " << p3.use_count() << std::endl;
    {
        std::shared_ptr<Test> p4 = p3;
        std::cout << "Use count: " << p3.use_count() << std::endl;
        {
            std::shared_ptr<Test> p5 = p3;
            std::cout << "Use count: " << p3.use_count() << std::endl;
            //p3.reset(); //calls destr
        }
        std::cout << "Use count: " << p3.use_count() << std::endl;
    }
    std::cout << "Use count: " << p3.use_count() << std::endl;

    std::shared_ptr<Test> p6 = std::make_shared<Test> (100);
    std::cout << "Use count: " << p6.use_count() << std::endl;
    //p6.reset(); //calls destr
    std::cout << "Use count: " << p6.use_count() << std::endl;

    std::cout << std::endl;

    std::vector<std::shared_ptr<Test>> vec;
    vec.push_back(p3);  //creates copy
    std::cout << "Use count: " << p3.use_count() << std::endl;
    vec.push_back(std::move(p6));   //move is used - doesn't creates copy

    for(const auto &ptr: vec) {
        std::cout << *ptr << " use count : " << ptr.use_count() << std::endl;
    }

    return 0;
}