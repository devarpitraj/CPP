#include<iostream>
#include<vector>

using namespace std;

class Move {
    private:
        int *data;
    public:
        int get_value() { return *data; }
        void set_value(int d) { *data = d; }
        Move(int d); //constructor
        Move(const Move &source); //copy constructor
        Move(Move &&source) noexcept; //Move constructor
        ~Move(); //Destructor
};

Move::Move(int d) {
    data = new int; //allocate storage
    *data = d;
    cout << "Constructor for " << d << endl;
}

Move::Move(const Move &source)
    : Move(*source.data)
    {
        std::cout << "Copy constr - Deep copy for " << *data << std::endl;
}

Move::Move(Move &&source) noexcept
        :data{source.data} {
            source.data = nullptr;
            cout << "Move constructor : Moving resource for " << *data << endl;
        }

Move::~Move() {
    if(data != nullptr) cout << "Destructor freeing data for " << *data << endl;
    else cout << "Destructor freeing data for nullptr" << endl;
    delete data;
}

int main() {
    vector<Move> vec;

    vec.push_back(Move{10});

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    
    return 0;
}

/*output without move constr

Constructor for 10
Constructor for 10
Copy constr - Deep copy for 10
Destructor freeing data for 10
Constructor for 20
Constructor for 20
Copy constr - Deep copy for 20
Constructor for 10
Copy constr - Deep copy for 10
Destructor freeing data for 10
Destructor freeing data for 20
Constructor for 30
Constructor for 30
Copy constr - Deep copy for 30
Constructor for 10
Copy constr - Deep copy for 10
Constructor for 20
Copy constr - Deep copy for 20
Destructor freeing data for 10
Destructor freeing data for 20
Destructor freeing data for 30
Constructor for 40
Constructor for 40
Copy constr - Deep copy for 40
Destructor freeing data for 40
Constructor for 50
Constructor for 50
Copy constr - Deep copy for 50
Constructor for 10
Copy constr - Deep copy for 10
Constructor for 20
Copy constr - Deep copy for 20
Constructor for 30
Copy constr - Deep copy for 30
Constructor for 40
Copy constr - Deep copy for 40
Destructor freeing data for 10
Destructor freeing data for 20
Destructor freeing data for 30
Destructor freeing data for 40
Destructor freeing data for 50
Destructor freeing data for 10
Destructor freeing data for 20
Destructor freeing data for 30
Destructor freeing data for 40
Destructor freeing data for 50

Several deep copying is done which is inefficient

*/

/* output with move constructor

Constructor for 10
Move constructor : Moving resource for 10
Destructor freeing data for nullptr
Constructor for 20
Move constructor : Moving resource for 20
Move constructor : Moving resource for 10
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Constructor for 30
Move constructor : Moving resource for 30
Move constructor : Moving resource for 10
Move constructor : Moving resource for 20
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Constructor for 40
Move constructor : Moving resource for 40
Destructor freeing data for nullptr
Constructor for 50
Move constructor : Moving resource for 50
Move constructor : Moving resource for 10
Move constructor : Moving resource for 20
Move constructor : Moving resource for 30
Move constructor : Moving resource for 40
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Destructor freeing data for nullptr
Destructor freeing data for 10
Destructor freeing data for 20
Destructor freeing data for 30
Destructor freeing data for 40
Destructor freeing data for 50

NO deep copying is done 
move constr moves the resources and nulls out the source pointer (like cut and paste)
thus it is efficient

*/
