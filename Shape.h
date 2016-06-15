#pragma once
#include <iostream>
//#include<typeinfo>
#define _SP system("pause");
//using namespace std;
enum class colour:std::uint8_t{BLANC = 0, RED, GREEN, BLUE};
/*public:
	friend std::ostream& operator<<(std::ostream&,colour&) {};
}*/;

class Shape{
	
	protected:
	colour m_colour;
	//friend void v(int);
	
	public:
	Shape(colour col = colour::BLANC) { m_colour = col; };
	virtual ~Shape() {std::cout << "Now I am in Shape's destructor!" << std::endl; };

	virtual void Inflate(double) = 0;
	//const char* PrintCol()const { return typeid(m_colour).name(); }
	//Shape(const Shape &other) = default;
	//Shape(Shape&& other) = default;
	virtual Shape* Clone() const = 0;
	virtual Shape* CloneAdr()  = 0;
	virtual	std::ostream& osPrint(std::ostream&) const = 0;
	std::ostream& PrintColour(std::ostream& os) { return os << m_colour; }
	
	virtual void WhereAmI() = 0;
	virtual double GetArea() = 0;
	virtual double OffsetZero() = 0;
	friend std::ostream& operator<<(std::ostream& , const colour&);
	
};


//std::ostream& operator<<(std::ostream& os, color c) {
//}


