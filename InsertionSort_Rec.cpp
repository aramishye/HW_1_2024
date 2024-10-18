#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void RandNumbers(int a[], int n);
void Insertion_Sort(int a[], int n);
void Insertion_Sort_Recursive(int a[], int n);
void Print(int a[], int n);

int main()
{
    srand(time(0));
    const int n = 10;
    int a[n]; 
    RandNumbers(a, n);
    Insertion_Sort_Recursive(a, n);
    Print(a, n);
}

void RandNumbers(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 50 + rand() % 52;
    }
}

void Insertion_Sort_Recursive(int a[], int n)
{
    if (n <= 1) 
        return;

    Insertion_Sort_Recursive(a, n - 1);

    int key = a[n - 1];
    int j = n - 2;

    while (j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = key;
}

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}
