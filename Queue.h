#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>

template <class TYPE>
struct QueueItem
{
	TYPE data;
	QueueItem<TYPE> *next;

	inline QueueItem<TYPE>() : next(NULL)
	{ }

	inline QueueItem<TYPE>(TYPE new_data) : data(new_data), next(NULL)
	{ }
};

template <class TYPE>
class Queue
{

private:

	QueueItem<TYPE> *start;
	unsigned int num_elements;

public:

	Queue() : start(NULL), num_elements(0)
	{ }

	void push(const TYPE &new_data)
	{
		QueueItem<TYPE> *new_QueueItem = new QueueItem<TYPE>(new_data);

		if (start == NULL)
			start = new_QueueItem;
		else
			getLast()->next = new_QueueItem;

		num_elements++;
	}

	bool pop(TYPE &pop_data)
	{
		if (start == NULL)
			return false;

		QueueItem<TYPE> *node_to_delete = new QueueItem<TYPE>;
		node_to_delete = start;

		pop_data = start->data;
		start = start->next;
		delete node_to_delete;

		num_elements--;

		return true;
	}

	QueueItem<TYPE> *getLast() const
	{
		if (start == NULL)
			return start;

		QueueItem<TYPE> *tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;

		return tmp;
	}

	const TYPE *peek(unsigned int position) const
	{

		TYPE *ret = NULL;

		if (start != NULL && position < num_elements)
		{
			unsigned int counter = 0;
			QueueItem<TYPE> *tmp = start;

			for (; counter < position; counter++)
				tmp = tmp->next;

			ret = &(tmp->data);
		}
		return ret;
	}

	void clear()
	{
		if (start != NULL)
		{
			QueueItem<TYPE> *tmp = start;
			QueueItem<TYPE> *tmp_next;

			while (tmp->next != NULL)
			{
				tmp_next = tmp->next;
				delete tmp;
				tmp = tmp_next;
			}

			start = NULL;
			num_elements = 0;
		}
	}

	unsigned int count() const
	{
		return num_elements;
	}
};

#define DYN_ARRAY_BLOCK_SIZE 16

template <class TYPE>
class Queue2
{
private:

	TYPE *data;
	unsigned int allocated_memory;
	unsigned int num_elements;

	void reallocate(unsigned int new_mem_size)
	{
		allocated_memory = new_mem_size;
		TYPE *tmp = new TYPE[allocated_memory];

		if (data != NULL)
		{
			for (unsigned int i = 0; i < num_elements; i++)
				tmp[i] = data[i];

			delete[] data;
		}
		data = tmp;
	}

public:

	// Constructors
	Queue2<TYPE>() : data(NULL), allocated_memory(0), num_elements(0)
	{
		reallocate(DYN_ARRAY_BLOCK_SIZE);
	}

	Queue2<TYPE>(unsigned int new_memory_size) : data(NULL), num_elements(0)
	{
		reallocate(new_memory_size);
	}

	void push(const TYPE &new_data)
	{
		if (num_elements == allocated_memory)
			reallocate(++allocated_memory);

		data[num_elements++] = new_data;
	}

	bool pop(TYPE &pop_data)
	{
		if (num_elements > 0)
		{
			pop_data = data[0];

			for (unsigned int i = 0; i < num_elements - 1; i++)
				data[i] = data[i + 1];
			num_elements--;

			return true;
		}
		return false;
	}

	const TYPE *peek(unsigned int pos) const
	{
		TYPE *ret = NULL;

		if (pos < num_elements)
			ret = &data[pos];

		return ret;
	}

	void clear()
	{
		num_elements = 0;
	}

	unsigned int count() const
	{
		return num_elements;
	}

};

#endif //!__QUEUE_H__