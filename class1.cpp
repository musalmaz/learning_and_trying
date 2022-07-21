// #include<iostream>

// class Rectangle{
//     int width;      //private
//     float heigth; // private
//     public:
//     void set_value(int, float);
//     int area(){return width * heigth;}
// };
// void Rectangle::set_value(int a, float b){
//     width = a;
//     heigth = b;
// }
// int main(int argc, char **argv){
//     std::cout<<"start\n";
//     Rectangle rect;
//     rect.set_value(3, 4.0);
//     std::cout<<"area: "<<rect.area()<<std::endl;
    
// }
/* ******** contructor **** */

// #include<iostream>

// class Rectangle{
//     float width, heigth;
//     public:
//     Rectangle();
//     Rectangle(float, float);
//     float area(){return width * heigth;}

// };
// Rectangle::Rectangle(){
//     width = 5.2;
//     heigth = 3.5;
// }
// Rectangle::Rectangle(float t1, float t2){
//     width = t1;
//     heigth = t2;
// }

// int main(int argc, char **argv){
//     Rectangle rect(3,5);
//     Rectangle rect_overloading; // default contructor
//     std::cout<<rect_overloading.area()<<std::endl;
//     std::cout<<rect.area()<<"\n";
// }

/* ******* uniform initialization **** */

// #include<iostream>

// class Circle{
//     float radius;
//     public:
//         // Circle(float r){radius = r;}
//         Circle(float);
//         float circum(){ return 2* 3.14 * radius;}
// };
// Circle::Circle(float r){
//     radius = r;
// }
// int main(int argc, char **argv){
//     Circle circle {4};
//     std::cout<<circle.circum()<<std::endl;

// }

/* ******* Member initialization ****** */

// #include<iostream>

// class Circle{
//     float radius;
//     public:
//         Circle(float r) : radius(r) {}
//         float area(){return 3,14 * radius * radius;}
// };

// class Cylinder{
//     Circle base;
//     float heigth;
//     public:
//         Cylinder(float r, float h) : base(r), heigth(h) {}
//         float volume();
// };
// float Cylinder::volume(){
//     return base.area() * heigth;
// }
// int main(int argc, char **argv){
//     Cylinder test{3,5};
//     std::cout<<test.volume()<<std::endl;

// }

/* ******** pointers in class ******* */

#include<iostream>

class Rectangle{
    float width, heigth;
    public:
        Rectangle(float w, float h) : width(w), heigth(h) {}
        float area(){return width * heigth;}
};
int main(int argc, char **argv){
    Rectangle obj{3,4};
    std::cout<<obj.area()<<std::endl;

    Rectangle * rect;
    rect = &obj;
    std::cout<<rect->area()<<std::endl;

    // Rectangle *rect2(5,6);
    // std::cout<<rect2->area()<<std::endl;  ///  HATA

    Rectangle * rect3;
    rect3 = new Rectangle(5, 6);
    std::cout<<rect3->area()<<std::endl;
    delete rect3;

    Rectangle * test;
    test = new Rectangle[2] {{3,5}, {4,8}};
    std::cout<<test[1].area()<<std::endl;
    delete[] test;
}
