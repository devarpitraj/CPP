#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>    //for std::function

class Person {
    friend std::ostream& operator<< (std::ostream &os, const Person &obj);
    std::string name;
    int age;
    public:
        Person() = default;
        Person(std::string name, int age)
            :name{name}, age{age} {}
        ~Person() = default;

        void set_name(std::string name) { this->name = name; }
        std::string get_name() const { return name; }
        void set_age(int age) { this->age = age; }
        int get_age() const { return age; }
};

std::ostream& operator<<(std::ostream &os, const Person &obj) {
    os << "[Person: " << obj.name << " : " << obj.age << "]";
    return os;
}

void test1() {
    std::cout << "\n-----Test1----------" << std::endl;

    [] () { std::cout << "Hi" << std::endl; } ();

    [] (int x) { std::cout << x << std::endl; } (100);

    [] (int x, int y) { std::cout << x+y << std::endl; } (100, 200);
}

void test2() {
    std::cout << "\n-----Test2----------" << std::endl;

    auto l1 = [] () { std::cout << "Hi" << std::endl; };
    l1();

    int num1{100};
    int num2{200};

    auto l2 = [] (int x, int y) { std::cout << x+y << std::endl; };
    l2(20, 40);
    l2(num1, num2);

    auto l3 = [] (int &x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000;
        y = 2000;
    };

    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

void test3() {
    std::cout << "\n-----Test3----------" << std::endl;

    Person stooge{"Larry", 18};
    std::cout << stooge << std::endl;

    auto l1 = [] (Person p) {
        std::cout << p << std::endl;
    };
    l1(stooge);

    auto l2 = [] (const Person &p) {
        std::cout << p << std::endl;
    };
    l2(stooge);

    auto l3 = [] (Person &p) {
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl;
    };
    l3(stooge);

    std::cout << stooge << std::endl;
}

void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func) {
                                //  can replace with auto func C++20
                                //std::function<return_type(parameter)> name_of_parameter
                                //                         predicate lambda (coz it expects one or more parameter
                                //                                           and returns a bool type)
    std::cout << "[ ";
    for(int i:vec) {
        if(func(i))
            std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test4() {
    std::cout << "\n-----Test4----------" << std::endl;

    std::vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [] (int x) { return x > 50; });

    filter_vector(nums, [] (int x) { return x <= 30; });

    filter_vector(nums, [] (int x) { return x >= 30 && x <= 60; });
}

auto make_lambda() {
    return [] () { std::cout << "This lambda was made using the make_lambda function"; };
}

void test5() {
    std::cout << "\n-----Test5----------" << std::endl;

    auto l5 = make_lambda();
    l5();
}

void test6() {
    std::cout << "\n-----Test6----------" << std::endl;

    auto l1 = [] (auto x, auto y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
    };

    l1(10, 20);
    l1(100.34, 200.576);
    l1(std::string{"Frank"}, std::string{"C++"});

    l1(200, 3.14);
    l1(std::string{"Frank"}, 23.65);

    l1(Person("Larry", 18), Person("Moe", 28));
    l1(200, Person("Curly", 67));
}

void test7() {
    std::cout << "\n-----Test7----------" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 26}
    };

    std::sort(stooges.begin(), stooges.end(), [] (const Person &p1, const Person &p2) {
                    return p1.get_name() < p2.get_name(); });

    std::for_each(stooges.begin(), stooges.end(), [] (const Person &p) {
        std::cout << p << std::endl; });

    std::cout << std::endl;

    std::sort(stooges.begin(), stooges.end(), [] (const Person &p1, const Person &p2) {
        return p1.get_age() < p2.get_age(); });

    std::for_each(stooges.begin(), stooges.end(), [] (const Person &p) { std::cout << p << std::endl; });
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}