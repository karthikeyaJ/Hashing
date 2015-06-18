#pragma once
#include "Interfaces05.h"
#include "vector.h"
#include "HashNode.h"

class HashMap:public IHashMap
{
public:
	HashMap() {
		for (int i = 0; i <11; i++)
			cvector.push_back(NULL);
		head = NULL; x_size = 0;
	}
	~HashMap() {  }
	void insert(CompositeKey key, int value);
	void remove(CompositeKey key);
	bool containsKey(CompositeKey key);
	int getValue(CompositeKey key);
	int kthMinValue(int k);
	int size();
private:
	std::vector<HashNode*> cvector;
	std::vector<HashNode*> dvector;
	void topDown(std::vector<HashNode *>& points, int i, int endIndex);
	int hash_function(CompositeKey value);
	HashNode *head;
	int sum(CompositeKey keys);
	int x_size;
	void exchange(HashNode* &(f), HashNode * &(g));
};