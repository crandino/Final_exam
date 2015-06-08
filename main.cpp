#include <stdio.h>

#include "DynArray.h"
#include <time.h>
#include <random>

// Fibonacci series
// POS  0  1  2  3  4  5  6  7  8  9 
// NUM  1  1  2  3  5  8 13 21 34 55

unsigned int fibo_recursive(unsigned int pos)
{
	if (pos > 1)
		return fibo_recursive(pos - 2) + fibo_recursive(pos - 1);
	else
		return 1;
}

unsigned int fibo_iterative(unsigned int pos)
{
	unsigned int curr_pos = 0;
	unsigned int fibo_num = 1, prev_fibo_num = 0, tmp;

	while (curr_pos != pos)
	{
		tmp = fibo_num;
		fibo_num += prev_fibo_num;
		prev_fibo_num = tmp;

		curr_pos++;
	}
	return fibo_num;
}

int main(int argc, char **argv)
{
	DynArray<int> d1,d2,d3,d4;
	srand(time(NULL));

	for (unsigned int i = 0; i < 10000; i++)
	{
		d1.pushBack(rand());
		d2.pushBack(rand());
		d3.pushBack(rand());
		d4.pushBack(rand());
	}

	printf("%d\n", d1.bubble_sort());
	printf("%d\n", d2.bubble_sort2());
	printf("%d\n", d3.combsort());
	printf("%d\n", d4.cocktailSort());

	for (unsigned int i = 0; i < 10000; i++)
	{
		d1.pushBack(rand());
		d2.pushBack(rand());
		d3.pushBack(rand());
		d4.pushBack(rand());
	}

	printf("%s\n", "---------------------");

	printf("%d\n", d1.bubble_sort());
	printf("%d\n", d2.bubble_sort2());
	printf("%d\n", d3.combsort());
	printf("%d\n", d4.cocktailSort());		

	getchar();

	return 0;
}