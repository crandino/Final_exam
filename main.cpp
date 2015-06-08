#include <stdio.h>
#include "Point2d.h"
#include "String.h"
#include "DynArray.h"
#include "DList.h"
#include "Trees.h"

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
	/*String s1("abcdeaabcvabtrabc");
	String s2("abc");
	String s3("xxx");
	s1.replace(s2,s3);
	printf("%s", s1.getString());*/

	getchar();

	return 0;
}