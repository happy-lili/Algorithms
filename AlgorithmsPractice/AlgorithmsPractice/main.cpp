#include <iostream>;
#include <string>;
#include <conio.h>

using namespace std;

int search_1(int A[], int size, int key)
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

/*void test_1(int A[], int size, int key, string success, string error)
{
	search_1(A, size, key);
	int result = search_1(A, size, key);
	if (A[result] == key)
		cout << success << endl;
	else
		cout << error << endl;
}*/
 
void test_1(int A[], int size, int key, string success, string error)
{
	if (A[search_1(A, size, key)] == key)
		cout << success << endl;
	else
		cout << error << endl;
}

void test_2(int A[], int size, int keyBeg, int keyMid, int keyEnd, string success, string error)
{
	if (A[search_1(A, 2, keyBeg)] == keyBeg)
		cout << "Begin: " << success << endl;
	else
		cout << "Begin: " << error << endl;
	if (A[search_1(A, size - size/2, keyMid)] == keyMid)
		cout << "Middle: " << success << endl;
	else
		cout << "Middle: " << error << endl;
	if (A[search_1(A, size, keyEnd)] == keyEnd)
		cout << "End: " << success << endl;
	else
		cout << "End: " << error << endl;
}

int search_binary(int B[], int size, int key)
{
	return -1;

}
int main(int argc, char* argv[])
{

	int arr1[] = { 1 };
	int arr2[] = { 2 };
	int arr3[] = { 1, 2 };
	int arr4[] = { 3, 4 };
	int arr5[] = { 2, 4, 7, 9, 34 };
	test_1(arr1, 1, 1, "Test 1.1 (el 1): success", "Test 1.1 (el 1): error");
	test_1(arr2, 1, 2, "Test 1.2 (el 1): success", "Test 1.2 (el 1): error");
	test_1(arr3, 2, 2, "Test 1.3 (el 2): success", "Test 1.3 (el 2): error");
	test_1(arr4, 2, 4, "Test 1.4 (el 2): success", "Test 1.4 (el 2): error");
	test_2(arr5, 5, 2, 7, 34, "Test 2 (el beg, mid, end): success", "Test 2 (el beg, mid, end): error");




	_getch();
	return 0;
}