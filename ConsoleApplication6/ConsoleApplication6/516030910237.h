#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
	int value;    // record value
	Node * next;
	Node(int v) : value(v), next(NULL) {}
};

class List
{
private:
	int size;		// the current length of the list
	Node * head;	// Head of the list
public:
	List(const vector<int>& v) : size(v.size())		// 1->2->3->...end
	{
		head = new Node(v[0]);
		Node *p1, *p2 = NULL;
		for (int i = 1; i < size; i++)
		{
			p1 = new Node(v[i]);
			if (i == 1)
				head->next = p1;
			else
				p2->next = p1;
			p2 = p1;
		}
	}

	List(int * array, int array_size) : size(array_size)	// 1->2->3->...end
	{
		head = new Node(array[0]);
		Node *p1, *p2 = NULL;
		for (int i = 1; i < size; i++)
		{
			p1 = new Node(array[i]);
			if (i == 1)
				head->next = p1;
			else
				p2->next = p1;
			p2 = p1;
		}
	}

	int length() { return size; }
	void change_length(int length) { size = length; }
	Node* rhead() { return head; }
	void change_head(Node *p) { head = p; }

	bool insert(int pos, int value)	// insert a node, after this the node's place is pos
	{
		if (pos >= 0 && pos <= size) // correctness checking
		{
			if (pos > 0 && pos < size)		// not the head or end
			{
				Node *p1 = head, *p2;
				for (int i = 0; i < pos - 1; i++)
				{
					p1 = p1->next;
				}
				p2 = p1->next;
				p1->next = new Node(value); // insert
				p1->next->next = p2;
			}
			else if (pos == 0)				// replace the head
			{
				Node *p1 = head;
				head = new Node(value);
				head->next = p1;
			}
			else if (pos == size)			// add the end
			{
				Node *p1 = head;
				for (int i = 1; i < size; i++)
				{
					p1 = p1->next;
				}
				p1->next = new Node(value);
			}
			size += 1; // size + 1
			return true;
		}
		else return false;
	}

	int find(int value)				// find the first node whose value == 
	{
		Node *p = head;
		for (int i = 0; i < size; i++)
		{
			if (p->value == value)
				return i;		// return the place
			else p = p->next;
		}
		return -1;		// not find return -1
	}

	int remove(int value)				// remove all the nodes whose value ==
	{
		int n = 0; // the size of nodes whose value !=
		Node *p1 = head, *p2 = NULL, *p3 = NULL;
		for (int i = 0; i < size; i++)
		{
			if (p1->value != value)  // combine the node whose value !=
			{
				if (n == 0)
					head = p1;
				else
					p2->next = p1;
				n += 1;
				p2 = p1;
				p1 = p1->next;
			}
			else
			{
				p3 = p1;
				p1 = p1->next;
				delete p3;			// delete the node whose value ==
			}
		}
		int m = size - n;
		size = n;
		return m; // return the size of removed nodes
	}

	bool split(int pos, List & new_list) // split a list, the (pos,end] add to new_list
	{
		if (pos >= 0 && pos < size) // correctness checking
		{
			Node *p1 = head, *p2 = new_list.rhead();
			for (int i = 0; i < pos; i++)
			{
				p1 = p1->next;
			}
			for (int i = 1; i < new_list.length(); i++)
			{
				p2 = p2->next;
			}
			p2->next = p1->next;
			p1->next = NULL;
			new_list.change_length(new_list.length() + size - pos - 1);
			size = pos + 1;
			return true;
		}
		else return false;
	}

	void combine(List & append_list)	// conbine two list, the append'head to this'end
	{
		Node *p = head;
		for (int i = 1; i < size; i++)
		{
			p = p->next;
		}
		p->next = append_list.rhead();
		size += append_list.length();
		append_list.change_head(NULL);
		append_list.change_length(0);
	}

	void printAll()					// print all node'values
	{
		Node *p = head;
		for (int i = 1; i <= size; i++)
		{
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}

	~List()
	{
		Node *current = head, *temp = NULL;
		while (current)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
	}
};