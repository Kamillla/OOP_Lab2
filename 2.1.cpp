//классы, атрибуты, реализация конструкторов и деструкторов, создание и уничтожение статичесикх объектов
#include "pch.h"
#include<TCHAR.H>
#include<conio.h>
#include<iostream>
using namespace System;
using namespace std;

class Point
{
public:
    int x, y;
    Point()//конструктор
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

int _tmain(int argc, _TCHAR* argv[])
{
    {
        Point p;//с помощью обычного конструктора
        Point p2(10, 20); //с помощью конструктора копирования
        Point p3(p2);//с помощью конструктора с параметром 
    }//удаление объектов

    _getch();
    return 0;
}