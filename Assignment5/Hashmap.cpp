#include "Interfaces05.h"
#include "HashMap.h"
#include <iostream>
#include "vector.h"
#include "HashMap.h"
#include "HashNode.h"
#include "Interfaces02.h"


void HashMap::insert(CompositeKey key, int value)
{
	
	HashNode *s = new HashNode();
	s->key = key;
	s->value = value;
	dvector.push_back(s);

	CompositeKey v = key;	
	int index = hash_function(v);
	if (cvector.at(index) == NULL)
	{
		HashNode *p = new HashNode();
		p->key = key;
		p->value = value;
		cvector.at(index) = p;                    // insert(cvector.begin() + index, p);
		x_size++;
	}
	else
	{
		HashNode *q = new HashNode();
		q->key = key;
		q->value = value;
		
		head = cvector.at(index);
		
		while (head->next != NULL)
		{
				head = head->next;
		}
		head->next = q;
		head = cvector.at(index);
	}

}



void HashMap::remove(CompositeKey key)
{
	for (int j = 0; j < dvector.size(); j++)
	{
		if (dvector[j]->key == key)
		{
			dvector.erase(dvector.begin() + j);
		}
	}

	int x = hash_function(key);
	HashNode* l = cvector.at(x);
	if (l == NULL)
		return;
	else 
	if (l->key == key)
	{
		HashNode* temp = l->next;
		cvector.at(x) = temp;
			x_size--;
	}

	else
	{
			while (l->next != NULL)
			{
				if (l->next->key == key)
				{
					l->next = l->next->next;
					break;
				}
				l = l->next;
		}

	}
}
bool HashMap::containsKey(CompositeKey key)
{
	int x = hash_function(key);
	HashNode* l = cvector.at(x);
	if (l == NULL)
		return false;
	else
	if (l->key == key)
		return true;
	else
	{
		while (l->next != NULL)
		{
			if (l->next->key == key)
			{
				return true;
			}
			l = l->next;
		}
		return false;
	}

}
int HashMap::getValue(CompositeKey key)
{
	int x = hash_function(key);
	HashNode* l = cvector.at(x);
	while (l!=NULL )
    {
		if (l->key == key)
			return l->value;
		else
			l = l->next;
	}

}
int HashMap::kthMinValue(int k)
{
	std::vector<HashNode*> p;
	int vectorSize = dvector.size();
	for (int i = vectorSize / 2 - 1; i >= 0; i--)
	{
		topDown(dvector, i, vectorSize - 1);
	}
	int endIndex = vectorSize - 1;
	while (endIndex > 0)
	{
		exchange(dvector.at(0), dvector.at(endIndex));
		endIndex--;
		topDown(dvector, 0, endIndex);
	}
	return dvector.at(k)->value;
}

void HashMap::topDown(std::vector<HashNode *>&dvector,int i,int endIndex)
{
	int largest = 2 * i + 1;
	while (largest <= endIndex) 
	{
		HashNode *e = dvector.at(i);
		HashNode *f = dvector.at(largest);		
		if (largest < endIndex) 
		{
			HashNode* g = dvector[largest + 1];
			if (f->key < g->key)
			{
				largest++;
				f = g;
			}
		}
		if (e->key < f->key)
		{
			exchange(dvector.at(i), dvector.at(largest));
			i = largest;
			largest = 2 * i + 1;
		}
		else largest = endIndex + 1;
	}
}


void HashMap::exchange(HashNode* &(f), HashNode * &(g))
{
	HashNode* tempElement = f;
	f = g;
	g = tempElement;
	return;
}


int HashMap::size()
{
	return dvector.size();
}
int HashMap::hash_function(CompositeKey value)
{
	int x = (value.key1 + value.key2 + value.key3);// % 11;
	int y = x % 11;
	return y;
}

int HashMap::sum(CompositeKey keys)
{
	return keys.key1 + keys.key2 + keys.key3;
}