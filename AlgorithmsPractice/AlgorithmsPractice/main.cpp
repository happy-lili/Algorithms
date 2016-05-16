#include <iostream>;

using namespace std;

int search(int A[], int size, int key)
{
	for (int i = 0; i < size; ++i)
	{
		if (A[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int search2(int A[], int size, int key)
{
	A[size] = key;
	int i = 0;
	while (A[i] != key)
		++i;

	if (i != size)
		return i;
	    
	return -1;
}


int main()
{

}