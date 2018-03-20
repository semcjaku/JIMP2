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
}

