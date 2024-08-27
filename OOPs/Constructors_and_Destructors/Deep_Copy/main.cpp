#include<iostream>

class Deep {
    private:
        int *data;
    public:
        int get_value() { return *data; }
        void set_value(int d) { *data = d; }
        Deep(int d); //constructor
        Deep(const Deep &source); //copy constructor
        ~Deep(); //Destructor
};

Deep::Deep(int d) {
    data = new int; //allocate storage
    *data = d;
}

Deep::Deep(const Deep &source)
    : Deep(*source.data)
    {
        std::cout << "Copy constr - Deep" << std::endl;
}

Deep::~Deep() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl;    //free storage
}

void display_Deep(Deep s) {
    std::cout << s.get_value() << std::endl;
}

int main() {
    Deep obj1{100};
    display_Deep(obj1); //copy of obj1 is created 's' and it points to a different memory location
                        //and after destr is called for s that newly created space is freed and
                        // obj1's data still points to a valid location
    
    Deep obj2{obj1};    //obj2's data points to a different location
    obj1.set_value(1000);   // obj2's data value is only changed
    
    return 0;
}

