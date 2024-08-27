#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<list>

class Person {
    private:
        std::string name;
        int age;
    public:
        Person() = default;
        Person(std::string name, int age)
            :name{name}, age{age} {}

        bool operator<(const Person &rhs) const {
            return age < rhs.age;
        }

        bool operator==(const Person &rhs) const {
            return (this->age == rhs.age && name == rhs.name);
        }
};

void find_test() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    auto found = std::find(vec.begin(), vec.end(), 9);
                // where to start, where to end, what to find
    if(found != vec.end())
        std::cout << "Found it " << *found << std::endl;
    else std::cout << "Cannot find the element " << std::endl;

    std::list<Person> guest {
        {"Frank", 20},
        {"Moe", 30},
        {"Curly", 32}
    };

    auto loc = std::find(guest.begin(), guest.end(), Person{"Moe", 32});
    if(loc != guest.end()) std::cout << "Found" << std::endl;
    else std::cout << "Cannot find" << std::endl;
}

void count_test() {
    //std::count - count the no. of occurences of an element in a container
    //based on a predicate using a lambda expression

    std::vector<int> vec{1, 2, 3, 5, 1, 1, 2, 5};
    int find = 7;
    int num = std::count(vec.begin(), vec.end(), find);
    std::cout << find << " occured " << num << " times" << std::endl;
}

void count_if_test() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int num = std::count_if(vec.begin(), vec.end(), [] (int x) { return x % 2 == 0; }); 
                                                        //using lambda expressions
    std::cout << num << " even no. found" << std::endl;
    
    int num1 = std::count_if(vec.begin(), vec.end(), [] (int x) { return x % 2 != 0; });
    std::cout << num1 << " odd no. found" << std::endl;

    int num2 = std::count_if(vec.begin(), vec.end(), [] (int x) {return x >= 5; });
    std::cout << num2 << " numbers are greater than or equal to 5" << std::endl;
} 

void replace_test() {
    std::vector<int> vec {1, 2, 3, 4, 1, 5, 1, 1};

    for(auto i:vec)
        std::cout << i << " ";
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
                                    // replace, replace with
    for(auto i:vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void all_of_test() {    
    std::vector<int> vec {1, 2, 3, 4, 1, 5, 1, 1};

    if(std::all_of(vec.begin(), vec.end(), [] (int x) { return x > 5; }))
        std::cout << "All the elements are > 5" << std::endl;
    else 
        std::cout << "All the elements are not > 5" << std::endl;

    if(std::all_of(vec.begin(), vec.end(), [] (int x) { return x > 0; }))
        std::cout << "All the elements are > 0" << std::endl;
    else 
        std::cout << "All the elements are not > 0" << std::endl;
}

void string_transform_test() {
    std::string str{"This is a test"};

    std::cout << "Before transform : " << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
                                //where to start putting, what to put
    std::cout << "After transform : " << str << std::endl;

}

int main() {
    // find_test();
    // count_test();
    // count_if_test();
    // replace_test();
    // all_of_test();   //std::any_of check if any
    string_transform_test();
    return 0;
}