#pragma once

#include <iostream>
#include "Shape.h"

//using namespace std;

//void Shape::WhereAmI(){
//	cout << "Now I am in class Shape"<<endl;
//};








//std::ostream& operator<<(std::ostream& os, const Shape& Obj) {		
//	return os << Obj.m_colour;// << "     " << &Obj.osPrint(os);
//}

std::ostream & operator<<(std::ostream& os, const colour & col)
 {
	switch (col){
	case colour::BLANC: os << "BLANC";
		break;
	case colour::BLUE: os << "BLUE";
		break;
	case colour::GREEN: os << "GREEN";
		break;
	case colour::RED: os << "RED";
		break;
	default:
		break;
	}
	return os;
	
}

double Shape::CompSize(const Shape&S1, const Shape&S2)
{
	return S1.GetArea() - S2.GetArea();
}


