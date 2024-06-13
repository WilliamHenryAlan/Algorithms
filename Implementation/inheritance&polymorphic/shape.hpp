#pragma once
#include <iostream>
#include <string>
using namespace std;
class Shape {
private:
    string m_color;
    int m_x,m_y;
public:
    Shape();
    Shape(int x,int y,string color);
    virtual ~Shape() = 0;
    virtual void getArea() const;
};

class Rectangle : public Shape{
private:
    int m_length,m_width;
public:
    Rectangle();
    Rectangle(int x,int y,int length,int width,string color);
    ~Rectangle();
    void getArea() const override;
};

class Circle : public Shape {
private:
    double m_radius;
    double m_diameter;
public:
    Circle();
    Circle(int x,int y,int radius,string color);
    ~Circle();
    void getArea() const override;
};