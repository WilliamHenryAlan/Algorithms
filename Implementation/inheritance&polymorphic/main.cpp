#include "shape.hpp"
#include <vector>
void printInfo(Shape& ref) {
    ref.getArea();
}

void printInfo(vector<Shape*>& refShape) {
    for (Shape* iter:refShape) {
        iter->getArea();
    }
}
int main() {
    //Shape S(0,0,"black"); abstract class can't be instantiation
    Circle C(0,0,2,"red");
    Rectangle R(0,0,10,20,"blue");
    Rectangle R2(1,2,100,100,"purple");

    vector<Shape*> vecPtrShape(2);  //指针数组
    vecPtrShape[0] = &C;
    vecPtrShape[1] = &R;
    Shape* ptr = &R2;
    vecPtrShape.push_back(ptr);

    printInfo(vecPtrShape);


    vector<Shape*> vs = {new Circle,new Rectangle,new Circle,new Rectangle};    //批量new
    printInfo(vs);
    for (Shape* ptr:vs) {   //防止memory leak
        delete ptr;
    }
    return 0;
}