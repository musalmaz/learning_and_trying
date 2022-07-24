#include<iostream>

class Rectangle{
    int height, width;
    public:
        Rectangle() {};
        Rectangle(int x, int y) : height(x), width(y) {}
        int area() {return width * height;}
        friend Rectangle duplicate( const Rectangle&); //friend function

};
Rectangle duplicate(const Rectangle& param){
    Rectangle rec;
    rec.width = param.width * 2;
    rec.height = param.height * 2;
    return rec;
}

/* ************ friend class ************ */
class Square;
class Rect{
    int height, width;
    public:
        int area() {return width * height;}
        void convert (Square a);
};
class Square{
    friend class Rect;
    private:
        int side;
    public:
        Square (int a) : side(a) {}
};
void Rect::convert (Square a){
    width = a.side;
    height = a.side;
}

/* ********* inhertitance ********* */

class Polygon{
    protected: // cannot acces members of derived classes if private
        int height, width;
    public:
        void set_values(int a, int b){width = a; height = b;}        
};

class Rectangle_ : public Polygon{
    public:
        int area(){return width * height;}
};

class Triangle_ : public Polygon{
    public:
        int area(){return width * height / 2;}
};

class Mother{
    public:
    Mother() {std::cout << "Mother : no parameter" << std::endl;}
    Mother(int a) {std::cout << "Mother : int parameter" << std::endl;}
};
class Daughter : public Mother {
    public:
        Daughter (int a) {std::cout<<"Daughter : int parameter\n";}
};
class Son : public Mother {
    public:
        Son (int a) : Mother(a) {std::cout<<"Son : int parameter\n";}
};

/* ********** multiple inheritance ************* */

class Polygonn{
    protected:
        int h, w;
    public:
        Polygonn(int a, int b) : h(a), w(b) {}
};
class Output{
    public:
        static void print(int i);
};
void Output::print(int i){std::cout << i << "\n";}

class Rectanglee : public Polygonn, public Output {
    public:
        Rectanglee(int a, int b) : Polygonn(a, b) {}
        int area(){return h * w;}
};

class Trianglee : public Polygonn, public Output {
    public:
        Trianglee(int a, int b) : Polygonn(a, b) {}
        int area(){return h * w / 2;}
};

int main(int argc, char **argv){
    Rectangle test;
    Rectangle obj(3, 5);
    test = duplicate(obj);
    std::cout<< test.area() << std::endl;

    Rect temp;
    Square sqr {4};
    temp.convert(sqr);
    std::cout<< temp.area() << std::endl;

    Rectangle_ rect_;
    Triangle_ tri_;
    rect_.set_values(4, 6);
    tri_.set_values(8, 7);
    std::cout<< rect_.area() << std::endl;
    std::cout<< tri_.area() << std::endl;

    Daughter d1(0);
    Son s1(0);

    Rectanglee rec(4,5);
    Trianglee tr(4,5);
    rec.print(rec.area());
    tr.print(tr.area());

}