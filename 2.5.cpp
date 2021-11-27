//в классе-предке есть конструктор и деструктор, а в классе-потомке нет ни того, ни другого
#include "pch.h"
#include<TCHAR.H>
#include<conio.h>
#include<iostream>
using namespace System;
using namespace std;

class Point
{
protected:
    int x, y;
public:
    Point()//конструктор
    {
        printf("\nPoint()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y)//конструктор с параметром 
    {
        printf("\nPoint(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p)//копирующий конструктор
    {
        printf("\nPoint(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point()//деструктор
    {
        printf("\n~Point()\n");
    }
    void Print()
    {
        printf("\nx = %d, y = %d\n", x, y);
    }
};

class ColoredPoint : public Point //класс потомков
{
protected:
    int color;
public:
    void Print()
    {
        printf("\ncolor = %d\n", color);
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    Point* p1 = new Point();
    p1->Print();
    ColoredPoint* p2 = new ColoredPoint(); //т.к. класс ColoredPoint наследуется от класса Point, конструктор будет таким же, как и в родетельском классе
    p2->Print();

    delete p1;
    delete p2;

    _getch();
    return 0;
}