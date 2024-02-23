#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

void sort(int arr[], int begin, int end)         // Объявление функции sort 
{
    if (begin >= end) return;       // Условие для рекурсии 

    const int size = 1024;      // Инициализация константы, которая отвечает за размер массива
    int pivot;      // Инициализация опорного элемента
    int i = begin;      // Инициализация "указателя" для начала массива 
    int j = end;        // Инициализация "указателя" для конца массива 
    int buffer;

    pivot = arr[rand() % size];     // Выбор опорного элемента случайнм образом

    while (i <= j)      // Сортировка
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i <= j) 
        {
            buffer = arr[j];
            arr[j] = arr[i];
            arr[i] = buffer;

            i++;
            j--;
        }
    }
        sort(arr, begin, j);    // Разделеание массива на 2 части
        sort(arr, i, end);
}

int main() {
    setlocale(LC_ALL, "ru");    // RU локализация консоли

    srand(time(0));     // инициализация генератора псевдослучайных чисел

    const int size = 1024;  // инициализация константы, которая отвечает за размер массива
    int arr[size];  // инициализация массива c заданым ранее размером
    
    char path_unsorted[] = "unsorted.csv";  // Инициализация переменной, которая хранит название файла с неотсортрованным массивом 
    char path_sorted[] = "sorted.csv";  // Инициализация переменной, которая хранит название файла с отсортрованным массивом 

    fstream unsorted, sorted;  // Создание объектов unsorted и sorted класса fstream    

        unsorted.open(path_unsorted, fstream::trunc | fstream::in | fstream::out);    // Создание метода open и передача ему параметров trunc, in и out для объекта unsorted                                               
        sorted.open(path_sorted, fstream::trunc | fstream::in | fstream::out);       // Создание метода open и передача ему параметров trunc, in и out для объекта sorted                             

        if (!unsorted.is_open())    // Проверка  условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl; 
        }                                                               
        else 
        {
            cout << "Файл открыт!" << endl;

            for(int i = 0; i < size; i++)
            {
                arr[i] = rand() % 1000;     // Заполнение массива случайными значениями от 0 до 1000
                unsorted << arr[i] << "\n"; // Заполнение файла данными
            } 

            sort(arr, 0, size - 1);     // вызов функции sort
        }

        if (!sorted.is_open())    // Проверка  условия успешного открытия файла
        {
            cout << "Ошибка открытия файла!" << endl; 
        }                                                               
        else
        {
            for (int i = 0; i < size; i++)
            {
                sorted << arr[i] << "\n";       // Заполнение файла данными
            }
        }

        unsorted.close();   // Закрытие файлов при помощи метода close
        sorted.close();
}