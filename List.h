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
		//friend Node& operator++(Node& obj) { return &obj = obj.m_Next_p; }
		//friend std::ostream& operator<<(std::ostream&, const Node&);
		~Node();

		friend class List;

	};
	Node Head;
	Node Tail;
	size_t m_size;
	//Node* curN = nullptr;
	
protected:
	void AddExistingNodeT(Node&);
	void AddExistingNodeH(Node&);
	Node& GetRemoveNode(Node&);
	
public:
	List();
	List(const List&);
	List(List&&);
	~List();
	
	//Node& Find(List&, typename T );
	Node& FindMinSQ(List&);
	void AddToTail(const Shape&);
	void AddToTail(Shape&&);
	void AddToHead(const Shape&);
	void AddToHead(Shape&&);
	void RemoveFirst();
	void RemoveLast();
	//bool FindRemoveCir(const Shape&);
	//uint32_t FindRemoveAllCir(const Shape&);
	void Swap(List&);
	void SortSQ();
	Node* SetNext(Node*);
	Node* SetPrev(Node*);
	//friend void operator++(Node&);
	//friend void operator--(Node&);
	List& operator=(const List&);
	

	friend std::ostream& operator<<(std::ostream&, const Node&);
	friend std::ostream& operator<<(std::ostream&, const List&);
	//friend std::ofstream& operator<<(std::ofstream&, const List&);
	//friend std::ifstream& operator >> (std::ifstream&, List&);

};




