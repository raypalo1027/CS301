#include <iostream>

using namespace std;

void Print_Array(int [], int);
void Reverse_Array(int [], int);
void Fill_Array(int [], int);

int main()
{
  int size;
  cout << "Please enter a size for the array: ";
  cin >> size;
  cout << "The size of the array is " << size << ".\n";
  int myArray[size];

  Fill_Array(myArray, size);
  cout << "Original Array: ";
  Print_Array(myArray, size);
  cout << "\nReversed Array: ";
  Reverse_Array(myArray, size);
  Print_Array(myArray, size);
  cout << endl;

  return 0;
}

void Print_Array(int array[], int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
}

void Reverse_Array(int array[], int size)
{
  int temp;

  for(int i = 0; i < size / 2; i++)
  {
    temp = array[i];
    array[i] = array[size - 1 - i];
    array[size - 1 - i] = temp;
  }
}

void Fill_Array(int array[], int size)
{
  for(int i = 0; i < size; i++)
  {
    array[i] = i + 1;
  }
}
