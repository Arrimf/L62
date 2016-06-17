#include "List.h"
#include <iostream>
//#include <fstream>
//#include <conio.h>



List::List():Tail(),Head(){
	Tail.m_Prev_p = &Head;
	Head.m_Next_p = &Tail;
	m_size = 0; 
}


List::List(const List& other) {
	Tail.m_Prev_p = &Head;
	Head.m_Next_p = &Tail;
	List::Node* curNodeSource = other.Head.m_Next_p;
	while (curNodeSource != &other.Tail) {
		new Node(*curNodeSource, Tail.m_Prev_p, &Tail);
		m_size++;
		curNodeSource = curNodeSource->m_Next_p;
	}
}
List::List(List&& other) {
	m_size = other.m_size;

	Head.m_Next_p = other.Head.m_Next_p;
	Head.m_Next_p->m_Prev_p = &Head;
	other.Head.m_Next_p = &other.Tail;

	Tail.m_Prev_p = other.Tail.m_Prev_p;
	Tail.m_Prev_p->m_Next_p = &Tail;
	other.Tail.m_Prev_p = &other.Head;
}

void List::AddExistingNodeT( Node& ExistingNode) {
	ExistingNode.m_Prev_p = Tail.m_Prev_p;
	Tail.m_Prev_p->m_Next_p = &ExistingNode;
	ExistingNode.m_Next_p = &Tail;
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}

void List::AddExistingNodeH(Node& ExistingNode){
	ExistingNode.m_Prev_p = &Head;//Tail.m_Prev_p;
	Head.m_Next_p = &ExistingNode;
	ExistingNode.m_Next_p = Head.m_Next_p;
	Head.m_Next_p->m_Prev_p = &ExistingNode;
	m_size++;
}

void List::AddToTail(const Shape& Obj) {
	new Node(&Obj,Tail.m_Prev_p, &Tail);
	m_size++;
}
void List::AddToTail(Shape&&Obj) {
	new Node(static_cast<Shape&&>(Obj), Tail.m_Prev_p, &Tail);
	m_size++;
}

void List::AddToHead(const Shape& Obj){
	new Node(&Obj, &Head, Head.m_Next_p);
	m_size++;
}

void List::AddToHead(Shape&& Obj) {
	new Node(static_cast<Shape&&>(Obj), &Head, Head.m_Next_p);
	m_size++;
}

void List::RemoveFirst() {
	if (Head.m_Next_p != &Tail) {
		delete Head.m_Next_p;
	}
}

void List::RemoveLast(){
	if (Head.m_Next_p != &Tail) {
		delete Tail.m_Prev_p;
	}
}






void List::Swap(List& other) {
	//List tmp(*this);

	Node* tmpH = Head.m_Next_p;
	Node* tmpT = Tail.m_Prev_p;

	if (other.Head.m_Next_p != &other.Tail) {
		Head.m_Next_p = other.Head.m_Next_p;
		Head.m_Next_p->m_Prev_p = &Head;
		Tail.m_Prev_p = other.Tail.m_Prev_p;
		Tail.m_Prev_p->m_Next_p = &Tail;
	}
	else {
		Head.m_Next_p = &Tail;
		Tail.m_Prev_p = &Head;
	}

	if ((tmpH != &Tail)||(tmpT != &Head)) {
		other.Head.m_Next_p = tmpH;
		other.Head.m_Next_p->m_Prev_p = &other.Head;
		other.Tail.m_Prev_p = tmpT;
		other.Tail.m_Prev_p->m_Next_p = &other.Tail;
	}
	else {
		other.Head.m_Next_p = &other.Tail;
		other.Tail.m_Prev_p = &other.Head;
	}
	m_size ^= other.m_size;
	other.m_size ^= m_size;
	m_size ^= other.m_size;

	
}


List::Node& List::FindMinSQ() {
	Node* MinNode = nullptr;
	SetCurH();
	if (curN->m_Shape) {
		MinNode = curN;
	}
	else { return Tail; }
	while (curN != &Tail){
		if (curN->m_Shape->GetArea() < MinNode->m_Shape->GetArea()) {
			MinNode = curN;
		}
		++*this;
	}
	SetCurZ();
	return *MinNode;
}

void List::SortSQ() {
	List tmp;
	while (Head.m_Next_p != &Tail){
		tmp.AddExistingNodeT(GetRemoveNode(FindMinSQ()));
	}
	Swap(tmp);
}

//template<typename V, typename M>
	List::Node& List::FindMin(double (*pred)(const Shape& , const Shape&)){
		Node* MinNode = nullptr;
		SetCurH();
		if (curN->m_Shape) {
			MinNode = curN;
		}
		else { return Tail; }
		while (curN != &Tail) {
		
			MinNode = pred(*MinNode->m_Shape, *curN->m_Shape, pred);
			//if(pred(*curN->m_Shape,* MinNode->m_Shape)<0){
			//if (curN->m_Shape->GetArea() < MinNode->m_Shape->GetArea()) {
				//MinNode = curN;
		
			++*this;
		}
		SetCurZ();
		return *MinNode;
	}
//template<typename V, typename M>
	void List::SortP( double(*pred)(const Shape& , const Shape&)){
		List tmp;
		while (Head.m_Next_p != &Tail) {
			tmp.AddExistingNodeT(GetRemoveNode(FindMin(pred)));
		}
		Swap(tmp);

	}




List::Node* List::SetNext(List::Node * N){
	return N = N->m_Next_p;
}

List::Node* List::SetPrev(List::Node * N) {
	return N = N->m_Prev_p;
}

void List::operator++(){
	if (curN->m_Next_p) {
		curN = curN->m_Next_p;
	}
}

void List::operator--(){
	if (curN->m_Prev_p) {
		curN = curN->m_Prev_p;
	}
}


List::Node& List::GetRemoveNode(Node& del) {
	if (del.m_Prev_p) {
		del.m_Prev_p->m_Next_p = del.m_Next_p;
	}
	if (del.m_Next_p) {
		del.m_Next_p->m_Prev_p = del.m_Prev_p;
	}
	del.m_Prev_p = nullptr;
	del.m_Next_p = nullptr;
	m_size--;
	return del;
}


List& List::operator=(const List& other) {
	List::Node*curDest = Head.m_Next_p;
	List::Node*curSource = other.Head.m_Next_p;
	while (curDest->m_Next_p && curSource->m_Next_p){
		*curDest = *curSource;
		//++*this;
		
		SetNext(curDest);// = curDest->m_Next_p;
		SetNext(curSource);// = curSource->m_Next_p;
	}
	if (curDest != &Tail) {
		SetPrev(curDest);// = curDest->m_Prev_p;
		while (curDest->m_Next_p != &Tail){
			RemoveLast();
		}
	}
	else{
		while (curSource != &other.Tail){
			new Node(*curSource,Tail.m_Prev_p,&Tail);
			SetNext(curSource);// = curSource->m_Next_p;
		}
	}
	return *this;
}



//void operator++(List::Node&&old)
//{
//	if (old.m_Next_p) {
//		old.GetAdr() = old.m_Next_p->GetAdr();
//	}/////?????????? =((
//}
//void operator--(List::Node&old)
//{
//	if (old.m_Prev_p) {
//		*old.GetAdr() = *old.m_Prev_p->GetAdr();										/////?????????? =((
//	}
//}
std::ostream& operator<<(std::ostream& os, const List& l) {          
	if (l.Head.m_Next_p == &l.Tail) { os << "List is empty" << std::endl; }
	else {
		List::Node* curN = l.Head.m_Next_p;
		while (curN != &l.Tail) {
			if (curN->m_Shape) {
				os << *curN << std::endl; //*curN->m_Shape<<endl;
				//std::cout << std::endl;
			}
			curN = curN->m_Next_p;
		}
	}
	return os;
}

List::~List(){
	while (Head.m_Next_p != &Tail){
		delete Tail.m_Prev_p;
	}
	m_size = 0;
	// delete Head,Tail ???
}
