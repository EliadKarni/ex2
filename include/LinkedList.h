#pragma once

struct LinkedList
{
	~LinkedList();

	bool add_Node(void * newValue);
	bool delete_Node(int index);
	Node* m_root = nullptr;
	int m_size = 0;
};

struct Node
{
	void* m_data = nullptr;
	Node* m_next = nullptr;
};