#include <iostream>
#include <cstdlib>   // dla funckji rand i srand 
#include <ctime>
#include <chrono>    // dla zmierzenia czasu dzialania algorytmu

using namespace std;

/*------------------------------------
Sortowanie przez scalanie (Merge sort)
-------------------------------------*/

// Funkcja lanczy dwie podtablicy w jedna posortowana
void Merge(int *a, int first, int last, int mid) {
	int i = first;
	int j = mid + 1;
	int k = 0;
	
	int temp[last-first+1];
	
	// laczy dwie czesci w jedna tablice temp[]
	while (i <= mid && j <= last) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++; 
            i++;
		}
		else {
			temp[k] = a[j];
			k++; 
            j++;
		}
	}
	// Wstawia wszystkie pozostale elementy od i do mid do tablicy temp[]
	while (i <= mid) {
		temp[k] = a[i];
		k++; 
        i++;
	}
	// Wstawia wszystkie pozostale elementy od j do last do tablicy temp[]
	while (j <= last) {
		temp[k] = a[j];
		k++;
        j++;
	}
	// Przydziela posortowane elementy przechowywane w tablice temp[] do tablicy a[]
	for (i = first; i <= last; i++) {
		a[i] = temp[i-first];
	}
}
 
void MergeSort(int *a, int first, int last) {
	int mid;
	if (first < last) {
		mid=(first+last)/2;
	
		MergeSort(a, first, mid);  // tablica z elementami po lewej od srodka
		MergeSort(a, mid+1, last); // tablica z elementami po prawej od srodka 
	
		Merge(a, first, last, mid);
	}
}

/*------------------------------------
Sortowanie Shella (Shellsort)
-------------------------------------*/

// Funkcja sortowania Shellsort.
void ShellSort(int a[], int n)
{
	// Odstep 'i' jest porownywany pomiedzy indeksem elementu, poczatkowo n/2.
	for(int i = n/2; i > 0; i = i/2)
	{
		for(int j = i; j < n; j++)
		{
			for(int k = j-i; k >= 0; k = k-i)
			{
				// Sortowanie Babelkowe (Bubble sort)
				// Jezeli element z wiekszym indeksem jest wiekszy od poprzedniego, to przerwij petle.                
				if(a[k+i] >= a[k])                                                                                  
				break;
				// Zamieniamy miejscami wartosci elementow
				else
				{
					swap(a[k], a[k+i]);    
				}
			}
		}
	}
}

/*------------------------------------
Sortowanie szybkie (quicksort)
-------------------------------------*/
// Funkcja sortowania quicksort.
void QuickSort(int *a, int first, int last) {
    int f = first;
    int l = last - 1; // bo kolejnosc elementow zaczyna sie od 0
    int size = last - first;

    if(size > 1) {
        int pivot = a[rand() % size + f];          // element osiowy
        while(f < l) {
            while(a[l] > pivot && l > f){
                l--;
            }
            while(a[f] < pivot && f <= l){
                f++;
            }
            if(f < l) {                // zamieniamy miejscami wartosci elementow
                swap(a[f], a[l]);
                f++;
            }
        }
        QuickSort(a, first, f);   // elementy tablicy po lewej stronie od elementu osiowego
        QuickSort(a, l, last);    // elementy tablicy po prawej stronie od elementu osiowego
    }
}

// Wypelnia tablice losowymi elementami
int* makeRandomArray(int size){
    int* array = new int[size];
    srand(time(NULL));       // inicjalizacja generowania losowych liczb
    for (int i = 0; i < size; i++) {
        array[i] = rand();      //(100.0*rand()) / RAND_MAX; - elementy tablicy sa wypelniane liczbami calkowitymi w przedziale od 0 do 99
    }
    return array;
}

int* Twentyfivepercent(int size){
    int* array = new int[size];
    for (int i = 0; i < size/4; i++)
    {
        array[i] = i;
    }
    for (int i = size/4; i < size; i++) {
        array[i] = rand(); //(100.0*rand()) / RAND_MAX;
    }
    return array;
    
}

int* Fiftypercent(int size){
    int* array = new int[size];
    for (int i = 0; i < size/2; i++)
    {
        array[i] = i;
    }
    for (int i = size/2; i < size; i++) {
        array[i] = rand(); //(100.0*rand()) / RAND_MAX;
    }
    return array;
    
}

int* Seventyfivepercent(int size){
    int* array = new int[size];
    for (int i = 0; i < size*3/4; i++)
    {
        array[i] = i;
    }
    for (int i = size*3/4; i < size; i++) {
        array[i] = rand(); //(100.0*rand()) / RAND_MAX;
    }
    return array;
    
}

int* Nintyfivepercent(int size){
    int* array = new int[size];
    for (int i = 0; i < size*95/100; i++)
    {
        array[i] = i;
    }
    for (int i = size*95/100; i < size; i++) {
        array[i] = rand(); //(100.0*rand()) / RAND_MAX;
    }
    return array;
    
}

int* Nintyninepercent(int size){
    int* array = new int[size];
    for (int i = 0; i < size*99/100; i++)
    {
        array[i] = i;
    }
    for (int i = size*99/100; i < size; i++) {
        array[i] = rand(); //(100.0*rand()) / RAND_MAX;
    }
    return array;
    
}

int* Nintyninepointsevenpercent(int size){
    int* array = new int[size];
    for (int i = 0; i < size*99.7/100; i++)
    {
        array[i] = i;
    }
    for (int i = size*99.7/100; i < size; i++) {
        array[i] = rand(); //(100.0*rand()) / RAND_MAX;
    }
    return array;
    
}

int* ArraySortingInReverse(int size){
    int* array = new int[size];
    for (int i = size-1; i >= 0 ; i--)
    {
        array[i] = i;
    }
    return array;
    
}

// Drukuje posortowana tablice
void printArray(int *a, int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {

    // int size = 10000;
	
	// int size = 50000;

	// int size = 100000;

	// int size = 500000;

	int size = 1000000;

    int *arr = makeRandomArray(size);

	// int *arr = Twentyfivepercent(size);

	// int *arr = Fiftypercent(size);

	// int *arr = Seventyfivepercent(size);

	// int *arr = Nintyfivepercent(size);

	// int *arr = Nintyninepercent(size);

	// int *arr = Nintyninepointsevenpercent(size);

	// int *arr = ArraySortingInReverse(size);

	int first=0, last=size;

    const chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

	// MergeSort(arr, first, last);

    // ShellSort(arr, size);

    QuickSort(arr, first, last);

    const chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

	cout<<"\nPosortowana tablica: ";
    printArray(arr, size);

    cout << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " ms" << endl;

    delete [] arr;


    return 0;
 }