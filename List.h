#pragma once
#include "Shape.h"
#include "circle.h"
#include "Rect.h"
//#include <conio.h>
//#include <iostream>
//#include <fstream>


class List {
	class Node {
	public:

		Node* m_Prev_p;
		Node* m_Next_p;
		Shape* m_Shape;
		
		Node(const Shape* = nullptr, Node* = nullptr, Node* = nullptr);
		Node(Shape&&, Node* = nullptr, Node* = nullptr);
		Node(const Node&, Node* = nullptr, Node* = nullptr);
		Node(Node&&, Node* = nullptr, Node* = nullptr);
		void operator=(Node&);
		Node* GetAdr() { return this; }
		//static Node& operator++(Node&& obj) {return &obj = obj.m_Next_p;}
		//friend Node& operator++(Node& obj) { return &obj = obj.m_Next_p; }
		void Swap(Node&);

		friend class List;
		~Node();
	};
	Node Head;
	Node Tail;
	size_t m_size;
	Node* curN = nullptr;
	
protected:
	void AddExistingNodeT(Node&);
	void AddExistingNodeH(Node&);
	Node& GetRemoveNode(Node&);
	inline void SetCurH() { curN = Head.m_Next_p; }
	inline void SetCurT() { curN = Tail.m_Prev_p; }
	inline void SetCurZ() { curN = nullptr; }
public:
	List();
	List(const List&);
	List(List&&);
	~List();
	
	//Node& Find(List&, typename T );
	Node& FindMinSQ();
	void AddToTail(const Shape&);
	void AddToTail(Shape&&);
	void AddToHead(const Shape&);
	void AddToHead(Shape&&);
	void RemoveFirst();
	void RemoveLast();

	//template<typename V, typename M>
	//	Node& FindMin(   V(*pred)(const  M&, const  M&));
	//bool FindRemoveCir(const Shape&);
	//uint32_t FindRemoveAllCir(const Shape&);
	template<typename M, typename V>
		const M& MinPred(const M& a, const M& b, V(*pred)(const  M&, const  M&));


	void Swap(List&);
	void SortSQ();
	List::Node & FindMin(double(*pred)(const Shape &, const Shape &));
	//template<typename V, typename M>
	
	void SortP(double(*pred)(const Shape&, const Shape&));
	
	Node* SetNext(Node*);
	Node* SetPrev(Node*);

	void operator++();
	void operator--();
	//friend void operator++(Node&);
	//friend void operator--(Node&);
	List& operator=(const List&);
	

	friend std::ostream& operator<<(std::ostream&, const Node&);
	friend std::ostream& operator<<(std::ostream&, const List&);
	//friend std::ofstream& operator<<(std::ofstream&, const List&);
	//friend std::ifstream& operator >> (std::ifstream&, List&);

};

//template<typename V, typename M>
// Node & List::FindMin(const V &(*)(const M &, const M &))
//{
//	// TODO: вставьте здесь оператор return
//}

template<typename M, typename V>
	const M & List::MinPred(const M & a, const M & b, V(*pred)(const M &, const M &))
		{
			if (pred(a, b) <= 0)
			{
				return a;
			}
			else { return b; }
		}
