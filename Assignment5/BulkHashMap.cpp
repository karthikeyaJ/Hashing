#include "Interfaces05.h"
#include "BulkHashMap.h"
#include "HashNode.h"

void BulkHashMap::insert(std::vector<std::pair<CompositeKey, int> >& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		insert(data[i].first, data[i].second);
	}
}

int BulkHashMap::getValue(CompositeKey key)
{
	int x = hash_function(key);
	HashNode* l = cvector.at(x);
	while (l != NULL)
	{
		if (l->key == key)
			return l->value;
		else
			l = l->next;
	}
}

void BulkHashMap::insert(CompositeKey key, int value)
{
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


int BulkHashMap::hash_function(CompositeKey value)
{
	int x = (value.key1 + value.key2 + value.key3);// % 11;
	int y = x % 11;
	return y;
}
