#pragma once
#include <iostream>
#include"Shape.h"
#include"Point.h"



class Circle : public Shape {
	Point m_centr;
	double m_rad;
	
protected:
	friend class Rect;
public:
	Circle(double x = 0, double y = 0, double r = 0, colour col = colour::BLANC);
	
	Circle(const Point&, const Point&, colour col = colour::BLANC);
	Circle(const Point&, const double, colour col = colour::BLANC);
	Circle(const Circle&) = default;
	Circle(Circle&&) = default;
	Circle(const Rect&);
	//Circle(Rect&&);
	virtual ~Circle() { std::cout << "Now I am in Circle's destructor!" << std::endl; };

	//inline virtual  Shape* Clone() { return new Circle(*this); };
	inline virtual   Shape* Clone() const { return new Circle(*this); }
	inline virtual Shape* CloneAdr() { return new/*std::move*/Circle(std::move(*this)); }
	inline virtual	 std::ostream& osPrint(std::ostream& os) const {return os << *this;}//<< typeid(this->m_colour).raw_name(); }
	void Circle::WhereAmI();
	void Inflate(double = 1);
	virtual double GetArea();
	//double GetArea2();
	friend std::ostream& operator<<(std::ostream&, const  Circle&);


};


