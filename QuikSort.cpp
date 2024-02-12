#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void sort(int Arr[], int begin, int end)
{
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
            if (Arr[i] > Arr[j]) 
            {
            buffer = Arr[j];
            Arr[j] = Arr[i];
            Arr[i] = buffer;

            i++;
            j--;
            }
        }
    }

    if(j > begin) {
        return sort(Arr, begin, j);
    }
    if(end < i) {
        return sort(Arr, i, end);
    } 
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