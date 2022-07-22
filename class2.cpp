// #include<iostream>

// class Vector{
//     public:
//         int x, y;
//         Vector() {};
//         Vector(int a, int b) : x(a), y(b) {}
//         Vector operator + (const Vector&);
//         Vector operator - (const Vector&);
// };
// Vector Vector::operator+ (const Vector& param){
//     Vector temp;
//     temp.x = x + param.x;
//     temp.y = y + param.y;
//     return temp;
// }
// Vector Vector::operator- (const Vector& sub){
//     Vector ret;
//     ret.x = x - sub.x;
//     ret.y = y - sub.y;
//     return ret;
// }
// int main(int argc, char **argv){
//     Vector t1 {3,2};
//     Vector t2 {2,6};
//     Vector result;
//     result = t1 + t2;
//     std::cout<<result.x << " " << result.y <<std::endl;

//     Vector test;
//     test = t1 - t2;
//     std::cout<<test.x << " " << test.y <<std::endl;

// }

/* ******** non-member operator overloads ***** */

// #include<iostream>

// class Vector{
//     public:
//         int x, y;
//         Vector () {}
//         Vector (int a, int b) : x(a), y(b) {}

// };
// Vector operator+ (const Vector& p1, const Vector& p2){
//     Vector temp;
//     temp.x = p1.x + p2.x;
//     temp.y = p1.y + p2.y;
//     return temp;
// }
// int main(int argc, char **argv){
//     Vector foo {3,5};
//     Vector bar {5,9};
//     Vector result;
//     result = foo + bar;
//     std::cout<<result.x << " " << result.y << std::endl;

// }

/* ******** static members ********** */


// #include<iostream>

// class Test{
//     public:
//         static int n;
//         Test () {n++;};
// };
// int Test::n = 0;
// int main(int argc, char **argv){

//     Test T1;
//     std::cout<< T1.n << std::endl;
//     Test T2[5];
//     std::cout<< T1.n << std::endl;
//     Test * t3 = new Test;
//     std::cout<< t3->n << std::endl;
//     std::cout<< Test::n << std::endl;
//     delete t3;

// }

/* ********** const member functions *********** */

// #include<iostream>
// class MyClass{
//     public:
//         int x;
//         MyClass (int val) : x(val) {}
//         int get(){return x;}
// };

// int main(int argc, char **argv){
//     const MyClass test(10);
//     //test.x = 20;
//     std::cout<< test.x << std::endl;
// }


// #include<iostream>
// class MyClass{
//     int x;
//     public:
//         MyClass (int val) : x(val) {}
//         const int& get() const {return x;}

// };
// void print (const MyClass& arg){
//     std::cout<< arg.get() << std::endl;
// }
// int main(int argc, char **argv){
//     MyClass test{10};
//     print(test);
//     std::cout<< test.get() << std::endl;
// }

#include<iostream>
class MyClass{
    int x;
    public:
        MyClass (int val) : x(val) {}
        const int& get() const {return x;}
        int& get() {return x;}
};

int main(int argc, char **argv){
    MyClass foo (10);
    const MyClass bar {30};
    std::cout<< foo.get() << std::endl;
    foo.get() = 16;
    std::cout<< foo.get() << std::endl;
    std::cout<< bar.get() <<std::endl;
    //bar.get() = 45;


}