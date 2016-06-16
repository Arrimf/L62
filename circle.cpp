//#include"Shape.h"
#include "Rect.h"
#include "circle.h"



#define _USE_MATH_DEFINES
#include <math.h>





Circle::Circle(double x, double y, double rad, colour col):m_centr(x, y),Shape(col) {
	m_rad = rad;
}
Circle::Circle(const Point& centr, const Point& dot, colour col): m_centr(centr), Shape(col) {
	m_rad = sqrt((dot.m_x - centr.m_x)*(dot.m_x - centr.m_x) + (dot.m_y - centr.m_y)*(dot.m_y - centr.m_y));
}
Circle::Circle(const Point& centr, double rad, colour col) : m_centr(centr), Shape(col) {
	m_rad = rad;
}

Circle::Circle(const Rect& R):Shape(R) {
	double tmp[4];
	R.GetAll(tmp);
	tmp[1] -= tmp[0];
	m_centr.m_x = tmp[0] + (tmp[1] * .5);
	tmp[3] -= tmp[2];
	m_centr.m_y = tmp[3] + (tmp[2] * .5);
	m_rad = (tmp[1] > tmp[3]) ? tmp[1] : tmp[3];
}




//std::ostream & Circle::osPrint(std::ostream & os)const{
//	return os<< m_colour<<"    " << *this;
//}

void Circle::WhereAmI() {
	std::cout << "Now I am in class Circle" << std::endl;
};
void Circle::Inflate(double delta) {
	m_rad += delta;
}





std::ostream& operator<<(std::ostream& os, const Circle& cir) {
	return os << "Circle: centr - (" << cir.m_centr << "), rad - " << cir.m_rad;
}

double Circle::GetArea()const {
	return m_rad*m_rad* M_PI;
}

double Circle::OffsetZero()const {
	return m_centr.OffsetZ();
}

bool Circle::operator==(const Circle& other)const{
	return ((m_centr==other.m_centr)&&(m_rad==other.m_rad));
}
bool Circle::operator==(const Shape& other) const {
	try {
		return dynamic_cast<const Circle&>(other) == *this;
	}
	catch (std::bad_alloc) {
		return false;
	}
}





////////////////////////////////
//
//bool Circle::operator==(const Circle& other) {
//	return ((m_rad == other.m_rad) && (m_centr == other.m_centr));
//}
//std::ostream& operator<<(std::ostream& os, const Circle& cir) {
//	return os << "Circle: centr - (" << cir.m_centr << "), rad - " << cir.m_rad << std::endl;
//}
//std::ofstream& operator<<(std::ofstream& os, const Circle& cir) {
//	os << cir.m_centr << " " << cir.m_rad;
//	return os;
//}