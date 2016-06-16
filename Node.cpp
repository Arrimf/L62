#include "List.h"



List::Node::Node(const Shape* Obj, Node* prev, Node* next) {
	m_Prev_p = prev;
	if (prev) { prev->m_Next_p = this; }
	m_Next_p = next;
	if (next) { next->m_Prev_p = this; }
	if (Obj) {
		m_Shape = Obj->Clone();
	}
	else { m_Shape = nullptr; }
}
List::Node::Node(Shape&& Obj, Node* prev, Node* next) {
	m_Prev_p = prev;
	if (prev) { prev->m_Next_p = this; }
	m_Next_p = next;
	if (next) { next->m_Prev_p = this; }
	m_Shape = Obj.CloneAdr();
}

List::Node::Node(const Node& other, Node* prev, Node* next) {
	m_Prev_p = prev;
	if (prev) { prev->m_Next_p = this; }
	m_Next_p = next;
	if (next) { next->m_Prev_p = this; }
	if (other.m_Shape) {
		m_Shape = other.m_Shape->Clone();
	}
	else { m_Shape = nullptr; }
}
List::Node::Node(Node&& other, Node* prev, Node* next) {
	m_Prev_p = prev;
	if (prev) { prev->m_Next_p = this; }
	m_Next_p = next;
	if (next) { next->m_Prev_p = this; }
	if (other.m_Shape) {m_Shape = other.m_Shape;}
	else { m_Shape = nullptr; }
	other.m_Shape = nullptr;
}
void List::Node::operator=(Node& other){
	if (typeid(*m_Shape) == typeid(*other.m_Shape)) {
		*m_Shape = *other.m_Shape;
	}
	else {
		delete m_Shape;
		m_Shape = other.m_Shape->Clone();
	}
}
//void operator++(List::Node old){
//	(&old) = old.m_Next_p;
//}







//List::Node& List::Node::operator++()
//{
//	&this = m_Next_p;
//	return const_cast<Node&>( this )= m_Next_p;
//}
std::ostream& operator<<(std::ostream& os, const List::Node& N) {
	N.m_Shape->osPrint(os) << " Col: ";
	return N.m_Shape->PrintColour(os);// << N->m_Shape->PrintCol();
}




void List::Node::Swap(Node& other){
	Shape* tmp = this->m_Shape;
	m_Shape = other.m_Shape;
	other.m_Shape = tmp;
}

List::Node::~Node() {
	//if (this) {
	if (m_Prev_p) {
		m_Prev_p->m_Next_p = m_Next_p;
	}
	if (m_Next_p) {
		m_Next_p->m_Prev_p = m_Prev_p;
	}
	delete m_Shape;
	//}

	//List::m_size--;
}