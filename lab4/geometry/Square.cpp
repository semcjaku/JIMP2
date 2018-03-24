//
// Created by semcjaku on 20.03.18.
//

#include "Square.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

namespace geometry
{
    Point::Point():x_(0),y_(0){
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Point::Point(double x, double y){
        cout << "Konstruktor parametrowy" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point(){
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        cout << endl;
    }

    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
    }

    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const
    {
        return x_;
    };

    double Point::GetY() const
    {
        return y_;
    };

    void Point::SetX(double x)
    {
        x_=x;
    };

    void Point::SetY(double y)
    {
        y_=y;
    };



    Square::Square()
    {
        a_.SetX(0);
        a_.SetY(0);
        b_.SetX(0);
        b_.SetY(0);
        c_.SetX(0);
        c_.SetY(0);
        d_.SetX(0);
        d_.SetY(0);
        cout << "Konstruktor bezparametrowy" << endl;
    }

    Square::Square(Point a, Point b, Point c, Point d)
    {
        a_=a;
        b_=b;
        c_=c;
        d_=d;
        cout << "Konstruktor parametrowy" << endl;
    }

    Square::~Square()
    {
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    }

    bool Square::IsSquare() const
    {
        if(a_.Distance(b_) == b_.Distance(d_) && d_.Distance(c_) == c_.Distance(a_) && a_.Distance(d_) == b_.Distance(c_))
            return true;
        return false;
    }

    double Square::Circumference() const
    {
        if(!IsSquare())
            return 0;
        return a_.Distance(b_)*4;
    }

    double Square::Area() const
    {
        if(!IsSquare())
            return 0;
        return pow(a_.Distance(b_), 2);
    }
}

