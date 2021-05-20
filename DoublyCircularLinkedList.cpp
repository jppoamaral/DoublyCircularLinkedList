#include "DoublyCircularLinkedList.h"

LinkedList::LinkedList()
	: count(0)
	, head(nullptr)
	, tail(nullptr)
{	
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Insert(int id, std::string name)
{
	Node* node = CreateNode(id, name, head, tail);
	if (IsEmpty())
	{
		tail = node;
		head = node;
	}
	else
	{
		head->previous = node;
		head = node;
		tail->next = head;
	}
	count++;
}

void LinkedList::Append(int id, std::string name)
{
	Node* node = CreateNode(id, name, head, tail);
	if (IsEmpty())
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		node->previous = tail;
		tail = node;
		head->previous = tail;
	}
	count++;
}

Node* LinkedList::RemoveHead()
{
	if (IsEmpty())
	{
		return nullptr;
	}

	Node* toRemove = head;
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		head->previous = tail;
	}
	count--;
	
	toRemove->next = toRemove->previous = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveTail()
{
	if (head == tail)
		return RemoveHead();
	

	//método antigo:
		//Node* toRemove = head;
		//Node* previous = nullptr;
		//while (toRemove != tail)
		//{
			//previous = toRemove;
			//toRemove = toRemove->next;
		//}
		//previous->next = head;

	Node* toRemove = tail;
	tail->previous->next = head;
	tail = tail->previous;
	head->previous = tail;
	
	count--;
	toRemove->next = toRemove->previous = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveNode(int value)
{
	Node* toRemove = head;
	Node* previous = nullptr;
	while (toRemove != nullptr && toRemove->id != value)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}

	if (toRemove == nullptr)
		return nullptr;
	else if (toRemove == head)
		return RemoveHead();
	else if (toRemove == tail)
		return RemoveTail();
	else if (toRemove != nullptr)
	{
		previous->next = toRemove->next;
		toRemove->next->previous = previous;

		--count;

		toRemove->next = toRemove->previous = nullptr;
		return toRemove;
	}

	return nullptr;
}

Node* LinkedList::GetHead() const
{
	return head;
}

Node* LinkedList::GetTail() const
{
	return tail;
}

Node* LinkedList::GetNode(int value) const
{
	Node* node = head;
	while (node != nullptr)
	{
		if (node->id == value)
			return node;
		node = node->next;
	}
	return nullptr;
}

int LinkedList::Count() const
{
	return count;
}

bool LinkedList::IsEmpty() const
{
	return ((head == nullptr) && (tail == nullptr)) || (count == 0);
}

void LinkedList::Clear()
{
	Node* node = head;
	Node* next = nullptr;

	for (int i = 0; i < count; ++i)
	{
		next = node->next;
		delete node;
		node = next;
	}
	head = tail = nullptr;
	count = 0;
}

Node* LinkedList::CreateNode(int id, std::string name, Node* next, Node* previous)
{
	Node* node = new Node;
	node->id = id;
	node->name = name;
	node->next = next;
	node->previous = previous;
	return node;
}

void LinkedList::DestroyNode(Node* node)
{
	delete node;
}