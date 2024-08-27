#include<iostream>

class Shallow {
    private:
        int *data;
    public:
        int get_value() { return *data; }
        void set_value(int d) { *data = d; }
        Shallow(int d); //constructor
        Shallow(const Shallow &source); //copy constructor
        ~Shallow(); //Destructor
};

Shallow::Shallow(int d) {
    data = new int; //allocate storage
    *data = d;
}

Shallow::Shallow(const Shallow &source)
    : data(source.data)
    {
        std::cout << "Copy constr - shallow" << std::endl;
}

Shallow::~Shallow() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl;    //free storage
}

void display_shallow(Shallow s) {
    std::cout << s.get_value() << std::endl;
}

int main() {
    Shallow obj1{100};
    display_shallow(obj1);  //here copy of obj1 is created as s whose data attribute 
                            //which points to same memory location as obj1 data attribute
                            //after this func ends i.e. s goes out of scope destructors releases the 
                            //memory but still obj1 data attribute still points to that location which is invalid
                            //proper explanation in copy
    
    obj1.set_value(1000);
    Shallow obj2{obj1};

    return 0;
}

// Program will likely crash
