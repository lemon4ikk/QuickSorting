#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

void sort(int Arr[], int begin, int end)
{
    if (begin >= end) return;

    const int size = 1024;
    int pivot;
    int i = begin;
    int j = end;
    int buffer;

    pivot = Arr[rand() % size];

    while (i <= j)
    {
        while (Arr[i] < pivot) i++;
        while (Arr[j] > pivot) j--;
        
        if (i <= j) 
        {
            buffer = Arr[j];
            Arr[j] = Arr[i];
            Arr[i] = buffer;

            i++;
            j--;
        }
    }
        sort(Arr, begin, j);
        sort(Arr, i, end);
}

int main() {
    setlocale(LC_ALL, "ru");

    srand(1234);

    const int size = 1024;
    int Arr[size];
    
    char path_unsorted[] = "unsorted.csv";
    char path_sorted[] = "sorted.csv";

    fstream unsorted, sorted;     
        unsorted.open(path_unsorted, fstream::trunc | fstream::in | fstream::out);                                                   
        sorted.open(path_sorted, fstream::trunc | fstream::in | fstream::out);                                    

        if (!unsorted.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
            cout << "Файл открыт!" << endl;

            for(int i = 0; i < size; i++)
            {
                Arr[i] = rand() % 1000;
                unsorted << Arr[i] << "\n";
            } 

            sort(Arr, 0, size - 1);

            for (int i = 0; i < size; i++)
            {
            sorted << Arr[i] << "\n";
            }
        }

        unsorted.close();
        sorted.close();
}