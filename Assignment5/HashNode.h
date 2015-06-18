#pragma once
#include "Interfaces05.h"
//
class HashNode
{
public:
	
	CompositeKey key;
	int value;
	HashNode* next=NULL;
};
