#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void sort(int Arr[], int begin, int end)
{
    if (begin > end) return;

    const int size = 10;
    int pivot;
    int i = begin;
    int j = end;
    int buffer;

    pivot = Arr[rand() % size];

    if (i >= j)
        return;

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

    srand(time(NULL));

    const int size = 10;
    int Arr[size];
    
    char path[] = "sorted.csv";
    char path2[] = "unsorted.csv";

    fstream file, file2;                                                       
        file.open(path, fstream::trunc | fstream::in | fstream::out);
        file2.open(path2, fstream::trunc | fstream::in | fstream::out);                                     

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
                file2 << Arr[i] << "\n";
            } 

            sort(Arr, 0, size - 1);
            
            file << "\n";

            for (int i = 0; i < size; i++)
            {
            file << Arr[i] << "\n";
            }
        }

       file.close();
}