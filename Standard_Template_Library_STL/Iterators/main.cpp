#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>

void test1() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    std::vector<int>::iterator it = vec.begin();
    std::cout << *it << std::endl;  //1

    it++;
    std::cout << *it << std::endl;  //2

    it += 2;
    std::cout << *it << std::endl;  //4

    it -= 3;
    std::cout << *it << std::endl;  //1

    it = vec.end() - 1; //vec.end() points to location after last element
    std::cout << *it << std::endl;  //5

    it = vec.begin();
    while(it != vec.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    for(auto it = vec.begin(); it != vec.end(); it++) 
        std::cout << *it << std::endl;

}

void test2() {
    //constant iterators :- cannot change the value it is pointing to
    std::cout << "\n=====================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it = vec.begin();
    // auto it = vec.cbegin();

    std::cout << *it << std::endl;
    // *it = 6;    // error: assignment of read-only location

    while(it != vec.end()) {
        std::cout << *it << " ";
        it++;
    }    
}

void test3() {
    std::cout << "\n================" << std::endl;

    //reverse iterator
    std::vector<int> vec{6, 7, 8, 9};
    auto it1 = vec.rbegin();
    // std::vector<int>::reverse_iterator it1 = vec.begin();

    while(it1 != vec.rend()) {
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << std::endl;

    //const reverse iterator over a list
    std::list<std::string> name {"Frank", "Moe", "Curly"};
    auto it2 = name.crbegin();
    // std::list<std::string>::const_reverse_iterator it2 = vec.begin();

    std::cout << *it2 << std::endl; //Curly
    it2++;
    std::cout << *it2 << std::endl; //Moe

    // iterator over a map
    std::map<std::string, std::string> favourites {
        {"Frank", "C++"},
        {"Moe", "Java"},
        {"Curly", "Python"}
    };

    auto it3 = favourites.begin();  //iterator over string, string pair
    while(it3 != favourites.end()) {
        std::cout << it3->first << " " << it3->second << std::endl;
        it3++;
    }
}

void test4() {
    //iterate over a subset of container

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while(start != finish) {
        std::cout << *start << std::endl;
        start ++;
    }
}

int main() {
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}