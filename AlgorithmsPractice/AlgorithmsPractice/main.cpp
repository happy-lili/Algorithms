#include <iostream>;
#include <string>;
#include <conio.h>
#include <cassert>

using namespace std;

int search_1(int A[], int size, int key)
{
	assert(size != NULL);

	for (int i = 0; i < size; ++i)
	{
		if (A[i] == key)
		{
			return i;
		}
	}
	return -1;
} 

int search_2(int A[], int size, int key)
{
	int i = 0;
	while (i < size)
	{
		if (A[i] == key)
			return i;
		++i;
	}

	return -1;
}

int search_3(int A[], int size, int key)
{
	A[size] = key;
	int i = 0;
	while (A[i] != key)
		++i;

	if (i != size)
		return i;

	return -1;
}

int search_4(int A[], int size, int key)
{
	if (size == 0)
		return -1;

	int end = size - 1;
	int last = A[end];
	if (last == key)
		return end;

	A[end] = key;
	int i = 0;
	while (A[i] != key)
		++i;
	A[end] = last;
	if (i != end)
		return i;

	return -1;
}

/*int search_binary(int B[], int key)
{
	if (B[0] != key)
	 {
		 cout << "if" << endl;
		 while (B[x] != key && x != 0)
		 {
			 cout << "while" << endl;
			 if (B[x] < key)
				 x += ceil(x / 2);
			 else
				 x -= ceil(x / 2);
				}
		 return x;
		 cout << x << endl;
			}
	return 0;//??
	cout << "0" << endl;
}*/

int search_binary(int B[], int key, int size)
{
	if (B[0] != key)
	{
		cout << "if" << endl;
		while (B[x] != key && x != 0)
		{
			cout << "while" << endl;
			if (B[x] < key)
				x += ceil(x / 2);
			else
				x -= ceil(x / 2);
		}
		return x;
		cout << x << endl;
	}
	return 0;//??
	cout << "0" << endl;
}


int search_binaryRec()
{

}


typedef int(*search_func)(int A[], int size, int key);

void test_1(search_func func, int A[], int size, int key, string success, string error)
{
	if (A[func(A, size, key)] == key)
		cout << success << endl;
	else
		cout << error << endl;
}

void test_2(search_func func, int A[], int size, int keyBeg, int keyMid, int keyEnd, string success, string error)
{
	if (A[func(A, size, keyBeg)] == keyBeg)
		cout << "Begin: " << success << endl;
	else
		cout << "Begin: " << error << endl;
	if (A[func(A, size, keyMid)] == keyMid)
		cout << "Middle: " << success << endl;
	else
		cout << "Middle: " << error << endl;
	if (A[func(A, size, keyEnd)] == keyEnd)
		cout << "End: " << success << endl;
	else
		cout << "End: " << error << endl;
}

void testingProcess()
{
	int arr1[] = { 1 };
	int arr2[] = { 2 };
	int arr3[] = { 1, 2 };
	int arr4[] = { 3, 4 };
	int arr5[] = { 2, 4, 7, 9, 34 };
// testing of the first variant
	test_1(search_1, arr1, 1, 1, "Test 1.1 (el 1): success", "Test 1.1 (el 1): error");
	test_1(search_1, arr2, 1, 2, "Test 1.2 (el 1): success", "Test 1.2 (el 1): error");
	test_1(search_1, arr3, 2, 2, "Test 1.3 (el 2): success", "Test 1.3 (el 2): error");
	test_1(search_1, arr4, 2, 4, "Test 1.4 (el 2): success", "Test 1.4 (el 2): error");
	test_2(search_1, arr5, 5, 2, 7, 34, "Test 2 (el beg, mid, end): success", "Test 2 (el beg, mid, end): error");
// testing of the second variant
	test_1(search_2, arr1, 1, 1, "Test 1.1 (el 1): success", "Test 1.1 (el 1): error");
	test_1(search_2, arr2, 1, 2, "Test 1.2 (el 1): success", "Test 1.2 (el 1): error");
	test_1(search_2, arr3, 2, 2, "Test 1.3 (el 2): success", "Test 1.3 (el 2): error");
	test_1(search_2, arr4, 2, 4, "Test 1.4 (el 2): success", "Test 1.4 (el 2): error");
	test_2(search_2, arr5, 5, 2, 7, 34, "Test 2 (el beg, mid, end): success", "Test 2 (el beg, mid, end): error");
// testing of the third variant
	int ar1[] = { 1, 0 };
	int ar2[] = { 2, 0 };
	int ar3[] = { 1, 2, 0 };
	int ar4[] = { 3, 4, 0 };
	int ar5[] = { 2, 4, 7, 9, 34, 0 };
	test_1(search_3, ar1, 1, 1, "Test 1.1 (el 1): success", "Test 1.1 (el 1): error");
	test_1(search_3, ar2, 1, 2, "Test 1.2 (el 1): success", "Test 1.2 (el 1): error");
	test_1(search_3, ar3, 2, 2, "Test 1.3 (el 2): success", "Test 1.3 (el 2): error");
	test_1(search_3, ar4, 2, 4, "Test 1.4 (el 2): success", "Test 1.4 (el 2): error");
	test_2(search_3, ar5, 5, 2, 7, 34, "Test 2 (el beg, mid, end): success", "Test 2 (el beg, mid, end): error");
// testing of the forth variant
	test_1(search_4, arr1, 1, 1, "Test 1.1 (el 1): success", "Test 1.1 (el 1): error");
	test_1(search_4, arr2, 1, 2, "Test 1.2 (el 1): success", "Test 1.2 (el 1): error");
	test_1(search_4, arr3, 2, 2, "Test 1.3 (el 2): success", "Test 1.3 (el 2): error");
	test_1(search_4, arr4, 2, 4, "Test 1.4 (el 2): success", "Test 1.4 (el 2): error");
	test_2(search_4, arr5, 5, 2, 7, 34, "Test 2 (el beg, mid, end): success", "Test 2 (el beg, mid, end): error");

}


int main(int argc, char* argv[])
{

	//testingProcess();
	int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	search_binary(B, 7);

	int key = 3;
	int x = sizeof(B) / sizeof(B[0]);
	int y = x / 2;
	binFuncRec(B, key, y);


	_getch();
	return 0;
}