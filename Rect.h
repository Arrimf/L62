#pragma once
 
#include <iostream>
#include"Shape.h"
#include"Point.h"
#include"circle.h"

class Rect : public Shape {
	Point m_LTop, m_RBottom;
	//int m_left, m_right, m_top, m_bottom;
	void normolize();
protected:
	void GetAll(double *coord)const;
	friend Rect BoundingRect(Rect, Rect);
	friend Rect BoundingRect2(const Rect&, const Rect&);
	friend class Circle;
public:
	explicit Rect(double l = 0, double r = 0, double t = 0, double b = 0, colour col = colour::BLANC);
	Rect(Point& LT, Point& RB, colour col = colour::BLANC) :m_LTop(LT), m_RBottom(RB) { m_colour = col; };
	Rect(const Rect&) = default;
	Rect(Rect&&) = default;
	//Rect(const Rect& R) :m_LTop(R.m_LTop), m_RBottom(R.m_RBottom), Shape(R) {};
	//Rect(const Circle&);
	Rect(const Circle& cir):m_LTop(cir.m_centr - cir.m_rad), m_RBottom(cir.m_centr + cir.m_rad), Shape(cir) {};

	virtual ~Rect() { std::cout << "Now I am in Rect's destructor!" << std::endl; };

	inline virtual  Shape* Clone()const { return new Rect(*this); }
	inline virtual Shape* CloneAdr() { return new/*std::move*/Rect(std::move(*this));}
	//inline virtual  const Shape* Clone() const { return this; };
	inline virtual	std::ostream& osPrint(std::ostream& os) const { return os <<*this ; }

	void Inflate(double  dl, double  dr, double  dt, double  db);
	void Inflate(double dx = 1, double dy = 1);
	void Inflate(double delta = 1);
	void SetAll(double l = 0, double r = 0, double t = 0, double b = 0);
	void GetAll(double& l, double& r, double& t, double& b)const;
	virtual double GetArea();

	void Rect::WhereAmI();
	
	friend std::ostream& operator<<(std::ostream&, const  Rect&);
	//Shape* operator*(Rect&) { return static_cast<Shape*>(this); };
};

