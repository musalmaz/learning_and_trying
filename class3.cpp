/* *********** default constructor ********** */

/*
#include<iostream>
#include<string>
class Example{
    public:
        int total;
        void accumulation (int x){total += x;}

};

class Example2{
    public:
        int total;
        Example2 (int val) : total(val) {}
        void func(int x) {total += x;};
};

class Example3{
    std::string data;
    public:
        Example3 (const std::string& str) : data(str) {}
        Example3(){}
        const std::string& content() const {return data;}
};
int main(int argc, char **argv){
    Example ex; // default contructor
    Example2 obj(100); // constructor
    // Example2 o; // no default contructor

    Example3 foo();
    Example3 bar("test");
    std::cout<< bar.content()<< std::endl;
}

*/

/* ********** destructor ****** */


#include<iostream>
#include<string>
class Example{
    std::string* ptr;
    public:
        Example() : ptr(new std::string) {}
        Example (const std::string str) : ptr(new std::string(str)) {}

        ~Example () {delete ptr;}
        const std::string content() {return *ptr;}
};

class Test{
    std::string data;
    public:
        Test() {}
        Test (std::string temp) : data(temp) {}
        ~Test() {std::cout<< "deleting\n";}
        std::string content() {return data;}
};

/* ****** copy constructor ******* */
class myCopy{
    std::string* ptr;
    int* alfa;
    public:
        myCopy& operator= (const myCopy&);
        myCopy (const std::string& str, const int& temp) : ptr(new std::string(str)), alfa(new int(temp)) {}
        ~myCopy() {delete ptr;}

        myCopy (const myCopy& x) : ptr(new std::string(x.content())), alfa(new int(x.include())) {}
        const std::string& content() const {return *ptr;}
        const int& include() const {return *alfa;}
        // myCopy& operator= (const myCopy& x){
        //     delete ptr;
        //     ptr = new std::string (x.content());
        //     return *this;
        // }
};
/* ********* move contructıor, assignment  ****** */
class Example6{
    std::string* ptr;
    public:
        Example6 (const std::string& str) : ptr(new std::string(str)) {}
        ~Example6 () {delete ptr;}
        //move contructor
        Example6 (Example6&& x) : ptr(x.ptr) {x.ptr = nullptr;}
        //move assignment
        Example6& operator= (Example6&& x){
            delete ptr;
            ptr = x.ptr;
            x.ptr = nullptr;
            return *this;
        }
        const std::string& content() const {return *ptr;}
        Example6 operator+(const Example6& temp){
            return Example6(content() + temp.content());
        }
};
int main(int argc, char **argv){
    Example6 o1 {"Examp"};
    Example6 o2 = Example6("ple");
    o1 = o1 + o2;
    std::cout<< o1.content() << std::endl;
    myCopy obj1("test", 34);
    myCopy obj2 = obj1;
    std::cout<< obj2.content() << std::endl;
    std::cout<< obj2.include() << std::endl;
    Example foo;
    Example test {"selam"};
    // std::cout<< test.content() << std::endl;

    Test * obj;
    obj = new Test("ok");
    // std::cout<< obj->content() << std::endl;
    delete obj;
    // std::cout<< obj->content() ;

}