#include<iostream>
#include<string>
#include<vector>
#include<utility>


//Template classes are typically completely contained in header files
//So, we would have the template class in Item.h and no Item.cpp file would be used
template<typename T>
class Item {
    private:
        std::string name;
        T value;
    public:
        Item(std::string name = "Unnamed", T value = 0)
            :name{name}, value{value} {}
        
        std::string get_name() const { return name; }
        T get_value() const { return value; }
};

template<typename T1, typename T2>
struct My_Pair {    //struct are used where we just want a relationship between data types
                    //it's handy because here we don't need to overload constructors
    T1 first;
    T2 second;
};

int main() {
    Item<int> item1{"Frank", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2{"Moe", "Curly"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    Item<Item<std::string>> item3{"Joe", {"Row", "Arpit"}};
    std::cout << item3.get_name() << " " 
                << item3.get_value().get_name() << " " 
                << item3.get_value().get_value() << std::endl;

    std::cout << "\n===================" << std::endl;

    std::vector<Item<double>> vec;
    vec.push_back(Item<double> {"Frank", 100.1});
    vec.push_back(Item<double> {"Moe", 200.2});
    vec.push_back(Item<double> {"Curly", 300.3});

    for(const auto &i:vec)
        std::cout << i.get_name() << " " << i.get_value() << std::endl;


    My_Pair<std::string, int> p1{"Frank", 200};
    My_Pair<int, char> p2{300, 'F'};

    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;
    std::cout << p2.first << std::endl;
    std::cout << p2.second << std::endl;

    return 0;
}