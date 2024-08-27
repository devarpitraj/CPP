#include<iostream>
#include<vector>
#include<memory>

class Test {
    friend std::ostream& operator<<(std::ostream &os, const Test &obj);
    private:
        int data;
    public:
        Test(int data = 0)
            :data{data} {
                std::cout << "Test constr (" << data << ")" << std::endl;
            }
        ~Test() { std::cout << "Test destr (" << data << ")" << std::endl; }
        //int get_data() { return data; }
};

std::ostream& operator<<(std::ostream &os, const Test &obj) {
    os << obj.data;
    return os;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {    //or auto make()
    return (std::make_unique<std::vector<std::shared_ptr<Test>>> ());
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int x;
    for(int i = 1; i <= num; i++) {
        std::cout << "Enter data point [" << i << "] : ";
        std::cin >> x;

        auto temp = std::make_shared<Test> (x);
        vec.push_back(temp);
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "=========Displaying Vector========" << std::endl;
    for(const auto &temp:vec)
        std::cout << *temp << std::endl;
    std::cout << "==================================" << std::endl;
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}