#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void sort(int* arr, int begin, int end)
{
    const int size = 10;
    int pivot;
    int i = begin;
    int j = end;

    pivot = arr[rand() % size];

    //cout << pivot;

    if (i >= j)
        return;

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i <= j) 
        {
            if (arr[i] > arr[j]) 
            {
            int buffer;

            buffer = arr[j];
            arr[j] = arr[i];
            arr[i] = buffer;

            i++;
            j--;
            }
        }
    }

    if (begin < j) sort(arr, begin, j);
    if (i < end) sort(arr, i, end);
    
    return sort(arr, begin, end);
}

int main() {
    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    int size = 10;
    int Arr[size];
    
    char path[] = "QuikSort.txt";

    fstream file;                                                       
        file.open(path, fstream::trunc | fstream::in | fstream::out);                                   

        if (!file.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
        }                                                               
        else 
        {
            cout << "Файл открыт!" << endl;

            for(int i = 0; i < size; i++)
            {
                Arr[i] = rand() % 50;
                cout << Arr[i] << " ";
            } 

            sort(Arr, 0, size - 1);
            
            cout << "\n";

            for (int i = 0; i < size; i++)
            {
            cout << Arr[i] << " ";
            }
        }

       file.close();
}