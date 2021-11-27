//композиция объектов
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
        printf("\nPoint()\n");//конструктор
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
};

class Section //класс для отрезка
{
protected:
    Point* p1;
    Point* p2;
public:
    Section()
    {
        printf("\nSection()\n");
        p1 = new Point; //создание по умолчанию
        p2 = new Point; //отрезка с нулевыми координатами
    }
    Section(int x1, int x2, int y1, int y2)//конструктор с параметрами - координатами двух точек
    {
        printf("\nSection(int x1, int x2, int y1, int y2)\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Section(const Section& s)//создание копии существующего отрезка
    {
        printf("\nPoint(const Section &s)\n");
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }
    ~Section()//деструктор
    {
        delete p1;
        delete p2;
        printf("\n~Section()\n");
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    Section* s1 = new Section;
    Section* s2 = new Section(*s1);

    delete s1;
    delete s2;

    _getch();
    return 0;
}