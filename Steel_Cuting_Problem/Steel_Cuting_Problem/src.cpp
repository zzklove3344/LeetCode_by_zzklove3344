#include<stdio.h>
#include<stdlib.h>

typedef struct priceType
{
	int lengthOfSteel;
	int price;
}Price;

typedef struct returnValue
{
	int* r;
	int* s;
}Value;



Value* ExtendenBottomUpCutRod(Price* priceTable, int tableLength, int steelLength)
{
	int* r = (int *)malloc((steelLength+1) * sizeof(int));//Store the optimal solution
	int* s = (int *)malloc(steelLength * sizeof(int));//Store the cutting scheme
	Value* v = (Value *)malloc(sizeof(Value));
	int temp = -1, i = 0, j = 0;
	r[0] = 0;
	for (i = 1;i <= steelLength; ++i)
	{
		temp = -1;
		for (j = 1;j <= i;++j)
		{
			if (temp < (priceTable[j - 1].price + r[i - j]))
			{
				temp = priceTable[j - 1].price + r[i - j];
				s[i - 1] = j;
			}
		}
		r[i] = temp;

	}
	v->r = r;
	v->s = s;
	return v;
}

int main(void)
{
	Value *v;
	Price t[10];//Price Table
	int tl = 10;//Length of Table
	int s = 10;//Length of Steel

	//Test Example
	t[0].lengthOfSteel = 1, t[0].price = 1;
	t[1].lengthOfSteel = 2, t[1].price = 5;
	t[2].lengthOfSteel = 3, t[2].price = 8;
	t[3].lengthOfSteel = 4, t[3].price = 9;
	t[4].lengthOfSteel = 5, t[4].price = 10;
	t[5].lengthOfSteel = 6, t[5].price = 17;
	t[6].lengthOfSteel = 7, t[6].price = 17;
	t[7].lengthOfSteel = 8, t[7].price = 20;
	t[8].lengthOfSteel = 9, t[8].price = 24;
	t[9].lengthOfSteel = 10, t[9].price = 30;

	v = ExtendenBottomUpCutRod(t, tl, s);
	for (int i = 0;i < s;++i)
		printf_s("%-3d   ", v->r[i + 1]);
	printf_s("\n");
	for (int i = 0;i < s;++i)
		printf_s("%-3d   ", v->s[i]);
	printf_s("\n");
	return 0;
}