#pragma once
#include <iostream>
//#include<typeinfo>
#define _SP system("pause");
//using namespace std;
enum class colour:std::uint8_t{BLANC = 0, RED, GREEN, BLUE};
/*public:
	friend std::ostream& operator<<(std::ostream&,colour&) {};
}*/

//template<typename M>const M& MinPred(const M& a, const M& b, double(*pred)(const  Shape&, const  Shape&)) {
//	if (pred(a, b) <= 0)
//	{
//		return a;
//	}
//	else { return b; }
//}

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
	virtual Shape* CloneAdr() const = 0;
	virtual	std::ostream& osPrint(std::ostream&) const = 0;
	std::ostream& PrintColour(std::ostream& os)const { return os << m_colour; }
	
	virtual void WhereAmI() = 0;
	virtual double GetArea()const = 0;
	virtual double OffsetZero()const = 0;
	template<typename V, typename M> 
		static V Comparator(const M&, const M&,  V(M::* )()const);
		

	static double CompSize(const Shape&, const Shape&);
	const Shape* operator->() { return this; }
	virtual bool operator==(const Shape&)const = 0;
	//virtual Shape& operator=(const Shape&) = 0;
	friend std::ostream& operator<<(std::ostream& , const colour&);
	

};


//std::ostream& operator<<(std::ostream& os, color c) {
//}

//template<typename V, typename M>
// V Shape::Comparator(const M& m1, const M& m2, V (M::* pred)(const M&)const)
//{
//	return V = m1(pred) - m2(pred);
//}

 template<typename V, typename M>
  V Shape::Comparator(const M& m1, const M& m2, V( M::*pred )() const)
 {
	 double x = 0;
	 return x = m1*pred();
	 //return  (m1.*pred()) - (m2.*pred());
 }
