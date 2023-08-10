#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int firstNumber = 3,lastNumber = 100,i,j;
	bool isprime;
	for (i = firstNumber; i <= lastNumber; i++)
	{
		isprime = true;
		for (j = 2; j <= i-1; j++)
		{
			if ((i%j) == 0)
			{
				isprime = false;
			}
		}
		if (isprime)
		{
			cout << i << " is a prime number." << endl;
		}
	}
}