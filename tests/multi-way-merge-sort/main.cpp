#include<iostream>
#include<memory.h>

using namespace std;

int inputs[5][100];
int cursors[5];
int lengths[5];
int result[100];

typedef struct _entry
{
	int data;
	int index;
} entry;

class min_heap
{
public:
	min_heap(): _size(1) { }
	void push(entry e);
	entry pop();
	bool any() { return _size > 1; }
	
private:
	void swap(int i, int j)
	{
		entry temp = _data[i];
		_data[i] = _data[j];
		_data[j] = temp;
	}
	
	entry _data[100];
	int _size;
};

int main()
{
	min_heap heap;
	for (int i = 0; i < 5; i ++)
	{
		cin>>lengths[i];
		for (int j = 0; j < lengths[i]; j ++)
			cin>>inputs[i][j];
		entry first;
		first.data = inputs[i][0];
		first.index = i;
		heap.push(first);
		cursors[i] = 1;
	}
	
	int length = 0;
	while (heap.any())
	{
		entry e = heap.pop();
		result[length++] = e.data;
		int idx = e.index;
		int cursor = cursors[idx];
		if (cursor < lengths[idx])
		{
			entry next;
			next.data = inputs[idx][cursors[idx]++];
			next.index = idx;
			heap.push(next);
		}
	}
	
	for (int i = 0; i < length; i ++)
		cout<<result[i]<<" ";
	cout<<endl;
	
	return 0;
}


void min_heap::push(entry e)
{
	_data[_size++] = e;
	int i = _size - 1;
	while (i > 1)
	{
		int parent = i / 2;
		if (_data[parent].data > _data[i].data)
			swap(i, parent);
		i = parent;
	}
}

entry min_heap::pop()
{
	entry result = _data[1];
	
	_data[1] = _data[--_size];
	int i = 1;
	while (i < _size)
	{
		int left_child_i = i * 2;
		int right_child_i = left_child_i + 1;
		
		// has no child or
		if ((left_child_i >= _size && right_child_i >= _size) || 
			// if doesn't have left child, or has left child and smaller than it
			((left_child_i >= _size || (left_child_i < _size && _data[i].data <= _data[left_child_i].data)) && 
			// if doesn't have right child, or has right child and smaller than it
			(right_child_i >= _size || (right_child_i < _size && _data[i].data <= _data[right_child_i].data))))
			// then we don't need to go down any more
			break;

		bool goto_left = false;
		if ((left_child_i < _size && right_child_i < _size && _data[left_child_i].data < _data[right_child_i].data && _data[i].data > _data[left_child_i].data) || 
			(left_child_i < _size && right_child_i >= _size && _data[i].data > _data[left_child_i].data))
			goto_left = true;
		swap(i, goto_left ? left_child_i : right_child_i);
		i = (goto_left ? left_child_i : right_child_i);
	}
	
	return result;
}