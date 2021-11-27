//определение классов наследников, порядок вызовов конструкторов & деструкторов
//помещение объектов в переменные различных типов
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
    Point()
    {
        printf("\nPoint()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y)//копирующий конструктор 
    {
        printf("\nPoint(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p)//конструктор с параметром
    {
        printf("\nPoint(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point()//деструктор
    {
        printf("\n%d, %d\n", x, y);//вывод текущего состояния объекта
        printf("~Point()\n");
    }
};

class ColoredPoint : public Point //класс потомков
{
protected:
    int color;
public:
    ColoredPoint() : Point() //конструктор
    {
        printf("\nColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x, y) //копирующий конструктор
    {
        printf("\nColoredPoint(int x, int y, int color)\n");
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p)//конструктор с параметром
    {
        printf("\nColoredPoint(const ColoredPoint &p)\n");
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint()//деструктор
    {
        printf("\n%d, %d, color = %d\n", x, y, color);//вывод текущего состояния объекта
        printf("~ColoredPoint()\n");
    }
    void change_color(int new_color)
    {
        color = new_color;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    Point* p = new ColoredPoint(1, 2, 42);//т.к. в переменной есть указатель на базовый класс, в нее можно поместить потомка
    //здесь деструктор вызывается только для базового класса

    ColoredPoint* p2 = new ColoredPoint(1, 2, 42);

    delete p;
    delete p2;

    _getch();
    return 0;
}