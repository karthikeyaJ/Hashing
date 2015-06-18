#pragma once
#include "Interfaces05.h"
#include "HashNode.h"

class BulkHashMap:IBulkHashMap
{
public:
	BulkHashMap() {
		for (int i = 0; i <11; i++)
			cvector.push_back(NULL);
		head = NULL; x_size = 0;
	}
	~BulkHashMap() { }
	void insert(std::vector<std::pair<CompositeKey, int> >& data);
	int getValue(CompositeKey key);
private:
	void insert(CompositeKey key, int value);
	std::vector<HashNode*> cvector;
	int hash_function(CompositeKey value);
	int x_size;
	HashNode *head;

};