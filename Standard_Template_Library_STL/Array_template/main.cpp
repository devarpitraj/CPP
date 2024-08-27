#include<iostream>
#include<array>

template<typename T, int N>
class Array {
    friend std::ostream& operator<< (std::ostream &os, const Array<T, N> &obj) {
        os << "[ ";
        for(const auto &i:obj.values)
        os << i << " ";
        os << "]" << std::endl;
        return os;
    }

    T values[N];
    int size{N};

    public:
        Array() = default;

        Array(T init_val) {
            for(auto &i:values)
                i = init_val;
        }

        void fill(T val) {
            for(auto &i:values)
                i = val;
        }

        T& operator[](int index) {  //overloaded subscript[] operator
            return values[index];
        }

        int get_size() const { return size; }
};

int main() {
    Array<int, 5> nums;
    std::cout << "Size of nums: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    Array<double, 6> doubs{1.24};
    std::cout << "Size of doubs: " << nums.get_size() << std::endl;
    std::cout << doubs << std::endl;

    doubs.fill(78.20);
    std::cout << doubs << std::endl;

    doubs[3] = 3.14;
    doubs[1] = 1000.100;
    std::cout << doubs << std::endl;

    Array<std::string, 4> strings{std::string{"None"}};
    std::cout << "Size of strings: " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;

    strings.fill(std::string{"Frank"});
    std::cout << strings << std::endl;

    strings[0] = std::string{"Larry"};
    std::cout << strings << std::endl;

    //Since C++11 the STL has std::array which is a template based array class
    //Use std::array instead of raw arrays whenever possible

    std::array<int, 5> arr{1,2,3,4,5};
    for(const auto &i:arr)
        std::cout << i << std::endl;
    
    arr.at(3) = 1000;
    for(const auto &i:arr)
        std::cout << i << std::endl;

    return 0;
}