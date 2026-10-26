// ЛР 6.2 рек

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
int  MaxOddIndex(int* a, const int size, int i, int maxIndex);
bool SwapLastWithMaxOdd(int* a, const int size);

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20;
    int High = 20;

    Create(a, n, Low, High, 0);
    cout << "First array:" << endl;
    Print(a, n, 0);

    if (SwapLastWithMaxOdd(a, n))
    {
        cout << "Array after the swap:" << endl;
        Print(a, n, 0);
    }
    else
        cout << "There are no odd elements; the array remains unchanged." << endl;

    return 0;
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int MaxOddIndex(int* a, const int size, int i, int maxIndex)
{
    if (i < size)
    {
        if (a[i] % 2 != 0 && (maxIndex == -1 || a[i] > a[maxIndex]))
            maxIndex = i;
        return MaxOddIndex(a, size, i + 1, maxIndex);
    }
    else
        return maxIndex;
}

bool SwapLastWithMaxOdd(int* a, const int size)
{
    int k = MaxOddIndex(a, size, 0, -1);
    if (k == -1)
        return false;

    int t = a[k];
    a[k] = a[size - 1];
    a[size - 1] = t;
    return true;
}
