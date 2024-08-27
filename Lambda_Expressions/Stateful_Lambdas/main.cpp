#include<iostream>
#include<vector>
#include<algorithm>

int global_x{1000};
// the global variable cannot be captured coz it is not within the reaching scope
// of the lambda. It can however still be accessed from within the lambda
// using normal name lookup rules

void test1() {  //capture by value - immutable 
    std::cout << "\n-----Test1----------" << std::endl;

    int local_x{100};

    auto l = [local_x] () { //x is const(immutable)
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

void test2() {  //capture by value - mutable
    std::cout << "\n-----Test2----------" << std::endl;

    int x{100};

    auto l = [x] () mutable {   //x is non-const(mutable)
        x += 100;
        std::cout << x << std::endl;
    };
    l();    //x = 200

    std::cout << x << std::endl;

    l();    //x= 300 // capture occurs only the first time and x remains the same
    std::cout << x << std::endl;
}

void test3() {  //capture by reference
    std::cout << "\n-----Test3----------" << std::endl;

    int x{100};

    auto l = [&x] () mutable {
        x += 100; 
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;

    l();
    std::cout << x << std::endl;
}

void test4() {  //default capture by value - mutable
    std::cout << "\n-----Test4----------" << std::endl;

    int x{100};
    int y{200};
    int z{300}; // z is not captured in the lambda since it is not used.
                // This should produce an 'unused variable' warning when compiling

    auto l = [=] () mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << std::endl;
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

void test5() {  // Default capture by reference
    std::cout << "\n-----Test5----------" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&] () {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test6() {  // Default capture by value, capture y by reference 
    std::cout << "\n-----Test6----------" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [=, &y] () mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test7() {  //capture by reference, capture x, z by value
    std::cout << "\n-----Test7----------" << std::endl;

    int x{100};
    int y{200};
    int z{300};

    auto l = [&, x, z] () mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();

    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

class Person {
    friend std::ostream& operator<<(std::ostream &os, const Person &obj);
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

        //all 3 versions are equivalent
        auto change_person1() {
            return [this] (std::string new_name, int new_age) {
                name = new_name;
                age = new_age;
            };
        }   //always use this

        auto change_person2() {
            return [=] (std::string new_name, int new_age) {
                name = new_name;
                age = new_age;
            };
        }

        auto change_person3() {
            return [&] (std::string new_name, int new_age) {
                name = new_name;
                age = new_age;
            };
        }
};

std::ostream& operator<<(std::ostream &os, const Person &obj) {
    os << "[Person: " << obj.name << " : " << obj.age << "]";
    return os;
}

void test8() {
    // Default capture by ref of the current obj using [this]
    // [=], [&], [this] are equivalent when capturing an obj's member variables - all are captured by ref 
    // [=] has been deprecated in C++20
    // Also, C++20 allows [*this], which captures by value
    std::cout << "\n-----Test8----------" << std::endl;

    Person person{"Larry", 18};
    std::cout << person << std::endl;

    //defalult capture[this]
    //this is the preferred way
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    //default capture[=]
    //this has been deprecated in C++20
    auto change_person2 = person.change_person2();
    change_person2("Curly", 27);
    std::cout << person << std::endl;

    //default capture[&]
    auto change_person3 = person.change_person3();
    change_person3("Frank", 50);
    std::cout << person << std::endl;
}

class Lambda {
    private:
        int y;
    public:
        Lambda(int y ) : y{y} {}

        void operator() (int x) const {
            std::cout << x + y << std::endl;
        }
};

//Lambda class equivalence example
void test9() {
    std::cout << "\n-----Test9----------" << std::endl;

    int y{100};

    Lambda lambda1(y);
    auto lambda2 = [y] (int x) { std::cout << x+y << std::endl; };

    lambda1(200);
    lambda2(200);
}

class People {
    std::vector<Person> people;
    int max_people;
    public:
        People(int max = 10) : max_people{max} {}
        People(const People &p) = default;

        void add(std::string name, int age) {
            people.emplace_back(name, age);
        }

        void set_max_people(int max) {
            max_people = max;
        }

        int get_max_people() const { return max_people; }

        // This method returns a vector of Person objects in
        // people whose age > max_age AND it limits the number of 
        // persons returned to be <= the member variable max_people.
        // Note that the lambda in this example captures this, by reference, and by value
        std::vector<Person> get_people(int max_age) {
            std::vector<Person> result;
            int count{0};
            std::copy_if(people.begin(), people.end(), 
                            std::back_inserter(result),
                            [this, &count, max_age] (const Person &p) { return p.get_age() > max_age && ++count <= max_people; });
            return result;
        }
};

void test10() {
    std::cout << "\n-----Test9----------" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);
    
    auto result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
        
    friends.set_max_people(3);
    
    result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
        
    result = friends.get_people(50);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;

}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}