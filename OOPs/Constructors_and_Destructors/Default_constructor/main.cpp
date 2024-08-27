#include<iostream>
#include<string>

//using namespace std;

class Player {
    private:
        std::string name;
        int health;
        int xp;

    public:
        void set_name(std::string n) { name = n; }
        std::string get_name() { return name; }
};

int main() {
    Player frank;   //default constructor is called that is compiler generated and does nothing
    frank.set_name("Frank");
    std::cout << frank.get_name() << std::endl;

    return 0;
}