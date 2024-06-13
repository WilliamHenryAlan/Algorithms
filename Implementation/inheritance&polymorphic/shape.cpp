#include "shape.hpp"

const double PI = 3.1415926;

Shape::Shape():m_color("write"),m_x(1),m_y(1) {
    //cout << "Shape class parameterless constructor.\n";
}
Shape::Shape(int x,int y,string color) : m_x(x),m_y(y) {
    //cout << "Shape class parametical constructor.\n";
}

Rectangle::Rectangle():Shape(),m_length(10),m_width(5) {
    //cout << "Rectangle class parameterless constructor.\n";
}

Rectangle::Rectangle(int x,int y,int length,int width,string color)
:Shape(x,y,color),m_length(length),m_width(width) {
    //cout << "Rectangle class parametical constructor.\n";
}

Circle::Circle() : Shape(),m_diameter(10) {
    m_radius = m_diameter / 2;
    //cout << "Circle class parameterless constructor.\n";
}
Circle::Circle(int x,int y,int radius,string color)
: Shape(x,y,color),m_radius(radius),m_diameter(2 * radius){
    //cout << "Circle class parametical constructor.\n";
}

Shape::~Shape() {
    //cout << "Shape class destructor.\n";
}

Circle::~Circle() {
    //cout << "Circle class destructor.\n";
}

Rectangle::~Rectangle() {
    //cout << "Rectangle class destructor.\n";
}

void Shape::getArea() const {
    cout << "Shape Area = 0.\n";
}

void Rectangle::getArea() const {
    cout << "Rectangle area = " << m_length * m_width << endl;
}

void Circle::getArea() const {
    cout << "Circle area = " << PI * m_radius * m_radius << endl;
}