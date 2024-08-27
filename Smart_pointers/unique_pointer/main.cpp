#include<iostream>
#include<memory>
#include<vector>

class Test {
    friend std::ostream &operator<< (std::ostream &os, const Test &obj);
    int data;
    public:
        Test() 
            : data{0} {
                std::cout << "Test constr for " << data << std::endl;
            }

        Test(int data)
            : data{data} {
                std::cout << "Test constr for " << data << std::endl;
            }
        
        ~Test() {
            std::cout << "Test destr for " << data << std::endl;
        }
};

std::ostream &operator<< (std::ostream &os, const Test &obj) {
    os << obj.data;
    return os;
}

int main() {
    //Test* t1 = new Test(100);
    //delete t1;

    std::unique_ptr<Test> t1 {new Test{100}};
    std::unique_ptr<Test> t2 = std::make_unique<Test> (1000);   //more efficient

    std::unique_ptr<Test> t3;
    //t3 = t1;    //smart pointers can't be assigned
    t3 = std::move(t1); //but can be moved
                        //now t3 owns the object and t1 is nullptr
    /* Also here the t3 is constructed later so it will be destroyed first */
    if(!t1)
        std::cout << "*t3 = " << *t3 << std::endl << "*t1 = nullptr" << std::endl;
    
    auto t4 = std::make_unique<Test> (500);

    std::vector<std::unique_ptr<Test>> vec;
    vec.push_back(std::make_unique<Test> (1000));
    vec.push_back(std::move(t2));
    vec.push_back(std::move(t3));
    vec.push_back(std::move(t4));


    for(const auto &i: vec) {
        std::cout << *i << std::endl; 
    }


    return 0;
}   //smart pointers automatically  deletes

