#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue 
{
private:
	vector<int>heap;

	void HeapUp(int i)
	{
		while (i > 0)
		{
			int parent = (i - 1) / 2;
			if (heap[i] < heap[parent])
			{
				break;
			}
			swap(heap[i], heap[parent]);
			i = parent;
		}
			
	}

	void HeapDwn(int i)
	{
		int n = heap.size();
		while (true)
		{
			int largest = i;
			int left = (2 * i) + 1;
			int right = (2 * i) + 2;

			if (left<n && heap[left]>heap[largest])
			{
				largest = left;
			}

			if (right<n && heap[right]>heap[largest])
			{
				largest = right;
			}

			if (largest == i)
			{
				return;
			}

			swap(heap[largest], heap[i]);
			i = largest;
		}
	}

public:
	int top()
	{
		return heap[0];
	}

	bool empty()
	{
		return heap.empty();
	}

	void push(int value)
	{
		heap.push_back(value);
		HeapUp(heap.size() - 1);
	}
	
	void pop()
	{
		if (heap.empty())throw "It is empty";
		heap[0] = heap.back();
		heap.pop_back();
		if (!heap.empty())
		{
			HeapDwn(0);
		}

	}

	void verify()
	{
		while (!heap.empty())
		{
			cout << top() << " ";
			pop();
		}
	}

};



int main()
{
	PriorityQueue pq;
	srand(time(NULL));
	for (int i = 0;i < 20;i++)
	{
		pq.push(rand() % 100);
	}

	pq.verify();
}

