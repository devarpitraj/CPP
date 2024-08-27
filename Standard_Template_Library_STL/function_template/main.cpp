#include<iostream>
#include<string>

template <typename T>
T mini(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T1, typename T2>
void display(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class Person {
    friend std::ostream& operator<<(std::ostream &os, const Person &obj);
    private:
        std::string name;
        int age;
    public:
        Person(std::string name = "Unnamed", int age = 0) 
            :name{name}, age{age} {}

        std::string get_name() { return name; }

        bool operator<(const Person &rhs) const {   //overloaded operator< is req 
                                                    //for comparing user defined types
            return age < rhs.age;
        }
};

std::ostream& operator<<(std::ostream &os, const Person &obj) { 
    os << obj.name << " : " << obj.age << std::endl;
    return os;
}

int main() {

    std::cout << mini<int>(10, 20) << std::endl;
    std::cout << mini(10.19, 20.63) << std::endl;
    std::cout << mini('A', 'C') << std::endl;
    std::cout << mini('A', 'd') << std::endl;
    std::cout << mini("Arpit", "Raj") << std::endl;  //C-string
    std::cout << mini(std::string{"Arpit"}, std::string{"Raj"}) << std::endl; //C++ strings

    Person p1{"Arpit", 50};
    Person p2{"Raj", 30};

    Person p3 = mini(p1, p2);    //overloaded operator< is needed
    std::cout << p3.get_name() << " is younger" << std::endl;

    display(p1, p2);   //overloaded operator<< is needed
    display(10, p1);   //overloaded operator<< is needed
    display(std::string{"Testing"}, p2);   //overloaded operator<< is needed

    display<int, int>(10, 20);
    display(10.12, 20.46);
    display(10.29, "Test");
    display('A', std::string{"Testing"});
    display(" ", " ");

    int a{20}, b{10};
    display(a, b);
    swap(a, b);
    display(a, b);

    std::string str1{"Hello"}, str2{"World"};
    display(str1, str2);
    swap(str1, str2);
    display(str1, str2);

    return 0;
}