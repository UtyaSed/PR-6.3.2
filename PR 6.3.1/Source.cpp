// PR 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 7
// рекурсивний спосіб окремої функції
// Обухова Віктора


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;


template <typename I>

void Create(I* a, const I size, const I Low, const I High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

template <typename I>

void Print(I* a, const I size, I i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

template <class I>

I IFirst(I* a, const I size, I& min, I i)
{
	if (a[i] % 2 == 1)
	{
		min = a[i];       // перший елемент, що
		return i;         // задовольняє умові
	}                     // вважаємо мінімальним
	if (i < size - 1)
		return IFirst(a, size, min, i + 1);
	else
		return -1;
}

template <class I>

int Min(I* a, const I size, I min, I i)
{
	if (a[i] < min && a[i] % 2 == 1)
		min = a[i];
	if (i < size - 1)
		return Min(a, size, min, i + 1);
	else
		return min;
}
int main()
{
	srand((unsigned)time(NULL));           // ініціалізація генератора випадкових чисел
	const int n = 10;
	int a[n];
	int Low = 12;
	int High = 70;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	int min;                                  // мінімальний елемент
	int imax = IFirst(a, n, min, 0);          // індекс мінімального елемента
	if (imax == -1)
		cerr << "немає елементів, які задовольняють умові" << endl;
	else
		cout << "min = " << Min(a, n, min, imax + 1) << endl;
	return 0;
}
