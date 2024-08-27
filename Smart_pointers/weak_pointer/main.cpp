#include<iostream>
#include<memory>

class B;    //forward declaration - just like fuction prototype

class A  {
    std::shared_ptr<B> b_ptr;
    public:
        void set_B(std::shared_ptr<B> &b) { b_ptr = b; }
        A() { std::cout << "A constr" << std::endl; }
        ~A() { std::cout << "A destr" << std::endl; }
};

class B {
    //std::shared_ptr<A> a_ptr;   //make weak to break the circular ref
    std::weak_ptr<A> a_ptr;
    public:
        void set_A(std::shared_ptr<A> &a) { a_ptr = a; }
        B() { std::cout << "B constr" << std::endl; }
        ~B() { std::cout << "B destr" << std::endl; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A> ();
    std::shared_ptr<B> b = std::make_shared<B> ();

    b->set_A(a);   
    a->set_B(b);
    //establishes cyclic or circular reference
    //when they goes out of scope A keeps B alive and B keeps A alive
    //thus destr never gets called and thus memory leaks

    /*
    OUTPUT
    A constr
    B constr
    */

   //solution :- make a weak pointer to break the circular ref

   /*
   OUTPUT
   A constr
   B constr
   A destr
   B destr
   */

    return 0;
}