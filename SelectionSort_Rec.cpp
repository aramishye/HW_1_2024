#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void RandNumbers(int a[], int n);
void Selection_Sort_Recursive(int a[], int n, int start = 0);
void Print(int a[], int n);

int main()
{
    srand(time(0));
    const int n = 10;
    int a[n]; 
    RandNumbers(a, n);
    Selection_Sort_Recursive(a, n);
    Print(a, n);
}

void RandNumbers(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = 50 + rand() % 52;
    }
}

void Selection_Sort_Recursive(int a[], int n, int start)
{
    if (start >= n - 1)
        return;

    int min_pos = start;
    for (int j = start + 1; j < n; j++)
    {
        if (a[j] < a[min_pos])
        {
            min_pos = j;
        }
    }

    if (min_pos != start)
    {
        int temp = a[start];
        a[start] = a[min_pos];
        a[min_pos] = temp;
    }

    Selection_Sort_Recursive(a, n, start + 1);
}

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << a[i];
    }
    cout << endl;
}
