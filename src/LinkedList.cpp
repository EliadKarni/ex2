#include "LinkedList.h"
#include <stdlib.h>
#include <iostream>

LinkedList::~LinkedList() {
	int i = 0;
	while (this->m_root != nullptr) {
		Node* temp = this->m_root->m_next;
		delete(this->m_root->m_data);
		delete(this->m_root);
		this->m_root = temp;
	}
};


bool LinkedList::add_Node(void *newValue) {
	Node* newNode = nullptr;

	newNode = new Node;
	if (newNode == nullptr) {
		std::cerr << "memory allocation error!\n";
		exit (EXIT_FAILURE);
	}
	
	newNode->m_next = this->m_root;
	newNode->m_data = newValue;
	++this->m_size;
	this->m_root = newNode;
};