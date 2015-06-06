#include <stdio.h>
#include "Point2d.h"
#include "String.h"
#include "DList.h"

// Fibonacci series
// POS  0  1  2  3  4  5  6  7  8  9 
// NUM  1  1  2  3  5  8 13 21 34 55

unsigned int fibo_recursive(unsigned int pos)
{
	return 0;
}

unsigned int fibo_iterative(unsigned int pos)
{
	unsigned int fibo_num = 1, curr_pos = 0;
	unsigned int prev_fibo_num = 0, tmp;

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
	/*for (unsigned int i = 0; i < 10; i++)
		printf("%d\n", fibo_recursive(i));
	*/

	/*String s1("abcdeaabcvabtrabc");
	String s2("abc");
	String s3("xxx");
	s1.replace(s2,s3);
	printf("%s", s1.getString());*/

	String a("1234567890");
	String a1(11);
	a1 = "1234567890";
	String b(5);
	String b1(50);
	b = "hola";
	b1 = "buenas";

	a.prefix(b);
	a1.prefix(b);
	b.prefix("1234567890");
	b1.prefix("1234567890");

	printf("%s", a.getString());
	printf("%s", a1.getString());
	printf("%s", b.getString());
	printf("%s", b1.getString());
		
	getchar();

	return 0;
}