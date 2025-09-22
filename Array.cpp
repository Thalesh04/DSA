#include <bits/stdc++.h>
using namespace std;
template <class T>
class Array
{

    T *arr;
    int s;

public:
    // parameterized constructor
    Array(int size)
    {
        arr = new T[size];
        s = size;
    }

    void enterArrays()
    {
        for (int i = 0; i < s; i++)
        { 
            cout << "enter element:" << endl;
            cin >> arr[i];
        }
    }

    void Display()
    {
        for (int i = 0; i < s; i++)
        {
            cout << arr[i];
        }
    }

    void insertionSort()
    {
        for (int i = 0; i < s; i++)
        {
            int k = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > k)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = k;
        }
    }
    // Selection Sort
    void selectSort()
    {
        int i, j;
        for (i = 0; i < s - 1; i++)
        {
            int minIndex = i;
            for (j = i + 1; j < s; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
};

int main()
{
    // data type
    Array<int> arr(5);
    cout << "before sort" << endl;
    arr.enterArrays();
    arr.Display();
    cout << "after sort" << endl;
    arr.insertionSort();
    arr.Display();
}