#include <stdio.h>
#include "Point2d.h"
#include "String.h"
#include "DList.h"
#include "Trees.h"

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

	Tree<char> t('F');
	TreeNode<char> *b = t.addChild('B');
	t.addChild('A', b);
	TreeNode<char> *d = t.addChild('D', b);
	t.addChild('C', d);
	t.addChild('E', d);
	TreeNode<char> *g = t.addChild('G');
	TreeNode<char> *i = t.addChild('I', g);
	TreeNode<char> *h = t.addChild('H', i);

	DList<TreeNode<char>*> list;
	t.witdhIterative(&list);

	doubleNode<TreeNode<char>*> *item = list.getFirst();
	for (; item != NULL; item = item->next)
		printf("%c", item->data->data);
		
	getchar();

	return 0;
}