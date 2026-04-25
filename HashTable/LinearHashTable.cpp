#include <iostream>
#include <vector>
using namespace std;

class LinearHashTable
{

private:
	enum Status{ EMPTY, OCCUPIED, DELETED};
	struct Node {
		int key;
		Status status;
		Node():key(0), status (EMPTY){}
	};
	int capacity;
	vector<Node> table;
	int size;

	int hash(int key)
	{
		return key % capacity;
	}
	void rehash()
	{
		vector<Node>oldtable = table;
		capacity *= 2;

		table.clear();
		table.resize(capacity);
		size = 0;

		for (auto& v : oldtable)
		{
			if (v.status == OCCUPIED)
			{
				insert(v.key);
			}
		}
		
	}

public:
	LinearHashTable(int cap = 0)
	{
		capacity = cap;
		table.resize(capacity);
		size = 0;
	}

	void insert(int key)
	{
		if (size / capacity >= 0.75)rehash();
		int index = hash(key);
		while (table[index].status == OCCUPIED)
		{
			if (table[index].key == key)return;
			index = (index + 1) % capacity;
		}
		table[index].key = key;
		table[index].status = OCCUPIED;
		size++;
	}

	bool search(int key)
	{
		int index = hash(key);
		int start = index;
		while (table[index].status != EMPTY)
		{
			if (table[index].status == OCCUPIED  && table[index].key == key)return true;
			index = (index + 1) % capacity;
			if (index == start)break;
		}
		return false;
	}

	void remove(int key)
	{
		int index = hash(key);
		int start = index;
		while (table[index].status != EMPTY)
		{
			if (table[index].status == OCCUPIED && table[index].key == key)
			{
				table[index].status == DELETED;
				size--;
				return;
			}
			index = (index + 1) % capacity;
			if (index == start)return;
		}
	}

	void print()
	{
		for (auto& v : table)
		{
			if (v.status == OCCUPIED)cout << v.key << ",";
			else cout << "__,";
		}
	}

};