#include<iostream>
#include"LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{

	head = nullptr;
}
LinkedList::~LinkedList()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::addAtHead(int value)
{

	if (!head)
	{
		head = new Node(value);
	}
	else
	{
		Node* start = new Node(value);
		start->next = head;
		head = start;
	}


}

void LinkedList::addAtTail(int value)
{
	if (!head)
	{
		head = new Node(value);
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;

		}
		temp->next = new Node(value);
	}
}

void LinkedList::addBefore(int targetValue, int newValue)
{
	Node* temp = head;
	Node* prev = nullptr;
	while (temp->next != nullptr)
	{
		prev = temp;
		temp = temp->next;
		if (temp->data == targetValue)
		{
			Node* n = prev->next;
			prev->next = new Node(newValue);
			prev->next->next = n;
		}
	}

}

void LinkedList::addAfter(int targetValue, int newValue)
{
	Node* temp = head;
	while (temp->next!= nullptr)
	{
		temp = temp->next;
		if (temp->data == targetValue)
		{
			Node* newNode = temp->next;
			temp->next = new Node(newValue);
			temp->next->next = newNode;
		}
	}

}

void LinkedList::deleteAtHead()
{
	if (!head)
	{
		exit(0);
	}
	Node* temp = head;
	head = head->next;
	delete temp;

}

void LinkedList::deleteAtTail()
{
	if (!head)
	{
		return;
	}
	else if (head->next==nullptr)//a little assignment issue may not allow your code to run
	{
		delete head;
		return;
	}
	else
	{
		Node* temp=head->next;
		Node* prev=head;
		while (temp->next!=nullptr)
		{
			temp = temp->next;
			prev = prev->next;
		}
		prev->next = nullptr;
		delete temp;
		
	}

}

void LinkedList::deleteBefore(int targetValue)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;

	}
	else
	{
		Node* beforePrev = nullptr;
		Node* prev = head;
		Node* temp = head->next;
		while (temp->next != nullptr && temp->data != targetValue)
		{
			beforePrev = prev;
			prev = prev->next;
			temp = temp->next;
			/*if (temp->data == targetValue)
			{
				Node* newNode = temp->next;
				delete temp;
				newNode = temp;
			}*/
		}
		if (temp != nullptr && beforePrev != nullptr)//understand it
		{
			beforePrev->next = prev->next;//understand it
			delete prev;
		}
	}
}

//void LinkedList::deleteAfter(int targetValue)//my logic
//{
//	if (head == nullptr || head->next == nullptr)
//	{
//		return;
//
//	}
//	else
//	{
//		
//		Node* prev = head;
//		Node* temp = head->next;
//		while (temp->next != nullptr && temp->data != targetValue)
//		{
//			//beforePrev = prev;
//			prev = prev->next;
//			temp = temp->next;
//			
//		}
//		Node* newNode = prev->next->next->next;
//		delete temp->next;
//		temp->next = newNode;
//		
//	}
//}
void LinkedList::deleteAfter(int targetValue)
{
	// If the list is empty or has only one node, nothing to delete
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	Node* temp = head;


	while (temp != nullptr && temp->data != targetValue)
	{
		temp = temp->next;
	}

	// If we found the targetValue and the node after it exists
	if (temp != nullptr && temp->next != nullptr)
	{
		Node* nodeToDelete = temp->next; // Node after targetValue
		temp->next = nodeToDelete->next; // Bypass the node to be deleted
		delete nodeToDelete;             // Delete the node
	}
}




int LinkedList::getSize()
{
	int counter = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		counter++;
	}
	return counter;
}

void LinkedList::reverse()
{
	Node* prev = nullptr;   // To store the previous node (initially set to null)
	Node* current = head;   // Start from the head
	Node* next = nullptr;   // To store the next node temporarily

	// Traverse the list and reverse the direction of the next pointers
	while (current != nullptr)
	{
		next = current->next;  // Store the next node
		current->next = prev;  // Reverse the current node's pointer

		prev = current;        // Move prev to this node
		current = next;        // Move current to the next node (stored in next)
	}

	head = prev;  // Set the new head to the last node we processed
}


void LinkedList::display()
{
	Node* temp = head;
	while (temp!= nullptr)
	{
		
		cout << temp->data << " ";
		temp = temp->next;
	
	}
	cout << '\n';
}