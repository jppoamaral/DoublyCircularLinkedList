//Nome: João Pedro de Paula Oliveira do Amaral - 32049390
//Nome: Nicolas de Barros - 32070837
#include <iostream>
#include <clocale>
#include "DoublyCircularLinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
	int i;
	Node* aux = list->GetHead();

	for (i = 0; i < list->Count(); ++i)
	{
		cout << "[" << aux->id << "] " << aux->name << "\n";
		aux = aux->next;
	}

	cout << "\n";
}

void PrintReverse(const LinkedList* list)
{
	int i;
	Node* aux = list->GetTail();

	for (i = 0; i < list->Count(); ++i)
	{
		cout << "[" << aux->id << "] " << aux->name << "\n";
		aux = aux->previous;
	}

	cout << "\n";
}

void PrintDoubleListInfo(const LinkedList* list)
{
	if (list->IsEmpty())
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR");
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular LinkedList)*** \n";
	
	LinkedList* list = new LinkedList();
	PrintDoubleListInfo(list);
	
	list->Insert(1, "Carol");
	list->Insert(2, "Eric");
	list->Insert(3, "John");
	list->Append(4, "Leo");
	list->Append(5, "Julia");
	list->Append(6, "Lisa");
	PrintDoubleListInfo(list);

	list->Clear();
	PrintDoubleListInfo(list);
	
	list->Insert(11, "Paulo");
	list->Append(22, "Thomas");
	list->Insert(33, "Olga");
	list->Append(44, "Bia");
	list->Insert(55, "Angela");
	list->Append(66, "Karen");
	list->Insert(77, "Adauto");
	PrintDoubleListInfo(list);

	Node* temp = list->RemoveNode(44);
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	list->DestroyNode(temp);
	PrintDoubleListInfo(list);

	temp = list->RemoveHead();
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	list->DestroyNode(temp);
	PrintDoubleListInfo(list);

	temp = list->RemoveTail();
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	list->DestroyNode(temp);
	PrintDoubleListInfo(list);

	delete list;

	cout << "Fim.\n";
}
