//������ �������.RTTI
//������������ �������
//������� :
//������� �����, ����������� �������� - ��������������� ������ ��� ��������, ����������� �� ������ � ���� �� �������� 
//																������.
//1.	�������� ������� ����� Shape � ����������� �� ���� ������ Rect, Circle�
//���������, ����� ������ � ���������� ������ ���� ����������(��������������) � ������ �� ���� ������.�������� �������� 
//																�� ������������� ������� � ��������������� �������.
//������������� ����������� ���������� ������� ��� ������� ������� ������������ ������.
//2.	�������� RTTI
//��� ��� ������� ����� ���� ������� ����, ��� ������������ ����������� ��������������� ���� ������� �� ����� ����������.
//2.1.������� RTTI
//Run - Time Type Information(RTTI) � ������������ ������������� ���� ������� : ��� ���������� ��������� �� ������ ���� 
//����������� ��������, �� ������ ������ ���� �� ����� ���� ��������� ��������� �� ������� �����.
//�������� RTTI ��������� ��� �����������(�� ���� ������ ��� ������� � ������� ������ ����������� �������) ���������� 
//��� ������� �� ����� ���������� ���������.��� ����������� ����� ��������� � ����������������� ������� �++ ���������� 
//	��������� ������� :
//1)	�������� dynamic_cast � ��� �������������� ���� ���������(��� ������) ����������� �����;
//2)	�������� typeid � ��� ������������� ������� ���� �������
//3)	����� type_info � ��� �������, ������������� typeid - ����������.
//
//2.2.��� ����������� ������ ��������� RTTI :
//1)	� ������ ������� Project / Settings / C / C++ / Category / C++ Language � ���������, ���  Enable RTTI ����������
//2)	#include <typeinfo>
//
//2.3.������ ������������� ��������� dynamic_cast
//�������� dynamic_cast ���������� ����������� � ���������� ���� ���������, ���� ������ ������������� �������������� ����, 
//����� ������� ��������.
//void SomeFunc(CShape* p)
//{
//	if (Rect* pr = dynamic_cast<Rect*>(p))//���� �� ������� ��������, ������ ������ ���� Rect
//	{
//		pr->...		//����� ����� ������������ ����������� ��������� ��� ��������� � ������ ������������ ������ Rect 
//      (��������, � ������������� ������� ������������ ������)
//	}
//}
//
//3.	����������� ����������� ������, �������� �������� ����� �������� ������� ����� ��������
//��������� : ��� ��� � ������ ����� ������������ ����� �������� � ��� ��� �����, ����� ������� ������� - ��������� ���� 
//�������(����������, ���������, ������������, �������������� �������������) = > ����������� �������, �� ����� 
//��������������� ������ �� ����������� �����, � ��������� ��������� � ������������ ����������.
//	������ ����������� ����� �������� :
//3.1.��������������� ����� ��� �������� ������ � ������ ����� ���������.
//1) ������������� ���������� ���������������� ������ Node :
//class Node
//{
//	Node* pPrevious;	//��������� �� ���������� �������
//	Node* pNext;		//��������� �� ��������� �������
//						//���������: ����� ������� ������� ��������� ������???
//
//public:
//	//�
//};
//
//
//2) ������������� ���������� ������� ������ Node.���������: ����� ����� ������������� ���� ������ � ����� ������� 
//		������� �������� ? ? ?
//
//3.2.�������� �����, ����������� ������
//������ ��������������� ����� Node ����� ������������ ��� �������� �������� ������ �� ��������, ����������� �� Shape 
//													- �������� ��� ���� ����� ��� ���������� ������ � List.
//
//1)	������������� ���������� ������
//2)	������������� ���������� �������
//
//
//��������� : ������ ����� ��� ����������� ��� ���������� ������ Remove() � ������ Shape � ����������� ������� �����������
//											�������� == ��� != (�������� ������� ������� ��� �����������!)
//
//	4.	����������
//	�������� ��� ������ List ���������� �� ����������� ������� �������(�� �����, �� �������� �� ������ ���������).
//	5.	����� ������ � ���� � ������ �� �����
//
//	1) ���������� ���������� �������� � ����.��� �������� �������� �������������� ������� ofstream.
//	������ ������ � ���� :


//#include <tchar.h>
#include <iostream>
#include <conio.h>
#include"List.h"
//#include "Shape.h"

//#define _CRT_SECURE_NO_WARNINGS
#define	  stop __asm nop
#define _CLS system("cls");
#define _SP system("pause");
//using namespace std;

void main() {
	List L8;

	List l;
	Circle* pc = new Circle(2,5);
	l.AddToTail(*pc);
	delete pc;	
	l.AddToTail(Rect(3, 5, 2, 6));
	l.AddToTail(Circle(1, 1));

	List L2(l);

	List L3(std::move(L2));
	std::cout << L2;
	std::cout << L3;
	_SP
 	L3.SortP(&Shape::GetArea);
	std::cout << L3;
	_SP
	
	_SP



}