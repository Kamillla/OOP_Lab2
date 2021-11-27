//создание и удаление динамических объектов, создание объектов при помощи конструкторов
//проверка доступности атрибутов и методов, реализация методов (сразу в определении класса/после определения)
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
        printf("\n%d, %d\n", x, y);//вывод текущего состояния объекта
        printf("~Point()\n");
    }
    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }
    void reset();
};

void Point::reset()//реализация метода класса после объявления в классе
{
    x = 0;
    y = 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Point* p = new Point;
    Point* p2 = new Point(10, 20);
    Point* p3 = new Point(*p2);//с помощью конструктора копирования
    Point* p4 = new Point(1, 2);
    Point* p5 = new Point(*p4);

    p4->move(10, 10);
    p5->reset();
    p5->move(10, 10);

    delete p;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    _getch();
    return 0;
}