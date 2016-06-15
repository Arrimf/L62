#include "circle.h"
#include "Rect.h"
//#include "Point.h"

Rect::Rect(double l, double r, double t, double b, colour col):m_LTop(l, t),m_RBottom(r,b), Shape(col) {
	normolize();
};
//Rect::Rect(const Circle& cir):m_LTop(cir.m_centr - cir.m_rad), m_RBottom(cir.m_centr + cir.m_rad),Shape(cir) {
//	normolize();
//}

void Rect::normolize() {
	if (m_LTop.m_x > m_RBottom.m_x) {
		double tmp = m_LTop.m_x;
		m_LTop.m_x = m_RBottom.m_x;
		m_RBottom.m_x = tmp;
	}
	if (m_LTop.m_y > m_RBottom.m_y) {
		double tmp = m_LTop.m_y;
		m_LTop.m_y = m_RBottom.m_y;
		m_RBottom.m_y = tmp;
	}
};


void Rect::Inflate(double dl, double dr, double dt, double db) {
	m_LTop.m_x -= dl;
	m_RBottom.m_x += dr;
	m_LTop.m_y -= dt;
	m_RBottom.m_y += db;
	normolize();
};
void Rect::Inflate(double gor, double vert) {
	Inflate(gor, gor, vert, vert);
}
void Rect::Inflate(double delta) {
	Inflate(delta, delta);
};
void Rect::SetAll(double l, double r, double t, double b) {
	m_LTop.m_x = l;
	m_RBottom.m_x = r;
	m_LTop.m_y = t;
	m_RBottom.m_y = b;
	normolize();
};
void Rect::GetAll(double& l, double& r, double& t, double& b)const {
	l = m_LTop.m_x;
	r = m_RBottom.m_x;
	t = m_LTop.m_y;
	b = m_RBottom.m_y;
}
double Rect::GetArea()const{
	return (m_RBottom.m_x - m_LTop.m_x)* (m_RBottom.m_y - m_LTop.m_y);
}
;
void Rect::GetAll(double *coord)const {
	coord[0] = m_LTop.m_x;
	coord[1] = m_RBottom.m_x;
	coord[2] = m_RBottom.m_y;
	coord[3] = m_LTop.m_y;
}
Rect BoundingRect(Rect R1, Rect R2) {
	double c1[4], c2[4];
	R1.GetAll(c1);
	R2.GetAll(c2);
	for (int i = 0; i < 4; i++) {
		if (i | 0x1) { c1[i] = (c1[i] > c2[i] ? c1[i] : c2[i]); }
		else c1[i] = (c1[i] < c2[i] ? c1[i] : c2[i]);
	}
	return Rect(c1[0], c1[1], c1[3], c1[2]);
};
Rect BoundingRect2(const Rect& R1, const Rect& R2) {
	double c1[4], c2[4];
	R1.GetAll(c1);
	R2.GetAll(c2);
	for (int i = 0; i < 4; i++) {
		if (i & 0x1) { c1[i] = (c1[i] > c2[i] ? c1[i] : c2[i]); }
		else { c1[i] = (c1[i] < c2[i] ? c1[i] : c2[i]); }
	}
	Rect ret(c1[0], c1[1], c1[3], c1[2]);
	return ret;
}
std::ostream& operator<<(std::ostream&os, const Rect& R){
	return os << "Rect: LeftTop-(" << R.m_LTop << "), RightBottom-(" << R.m_RBottom << ")";
}

void Rect::WhereAmI() {
	std::cout << "Now I am in class Rect" << std::endl;
}
bool Rect::operator==(const Rect& other)const{
	return ((m_LTop==other.m_LTop)&&(m_RBottom==other.m_RBottom));
}

bool Rect::operator==(const Shape& other) const{
	try {
		return dynamic_cast<const Rect&>(other) == *this;
	}
	catch(std::bad_alloc){
		return false;
	}
}

