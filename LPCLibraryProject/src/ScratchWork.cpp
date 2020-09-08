/*
 * ScratchWork.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: rogel
 */

//#include <iostream>
//#include "lpclib.h"
//using namespace std;
//
//
//struct Point
//{
//    double x;
//    double y;
//};
//
//void Triangle(GraphicsWindow * win,
//              Point a, Point b, Point c, int depth);
//
//
//Color white(255, 255, 255);
//
//
//int main()
//{
//    GraphicsWindow w(800, 800, "Wheee");
//    Point top = { 400, 0 };
//    Point bottomLeft = { 0, 799 };
//    Point bottomRight = { 799, 799 };
//    Triangle(&w, top, bottomLeft, bottomRight, 8);
//    w.Refresh();
//    w.WaitForMouseDown();
//}
//
//
//void Triangle(GraphicsWindow * win,
//              Point a, Point b, Point c, int depth)
//{
//    /// base case
//    if (depth == 0)
//    {
//        win->DrawLine(a.x, a.y, b.x, b.y, white);
//        win->DrawLine(b.x, b.y, c.x, c.y, white);
//        win->DrawLine(c.x, c.y, a.x, a.y, white);
//    }
//    else
//    {
//        Point p = { (a.x + b.x)/2, (a.y + b.y) / 2 };
//        Point q = { (b.x + c.x)/2, (b.y + c.y) / 2 };
//        Point r = { (a.x + c.x)/2, (a.y + c.y) / 2 };
//
//
//        Triangle(win, a, p, r, depth-1);
//        Triangle(win, p, b, q, depth-1);
//        Triangle(win, r, q, c, depth-1);
//
//    }
//}
//
//
//
