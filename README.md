# Задача: быстрая сортировка

**Дано**:  

- массив X (необходимо сформировать вручную с помощью генератора
случайных чисел);
- При каждом запуске массив должен отличаться;
- количество элементов 1024.

**Описание задачи**:

Необходимо произвести сортировку элементов массива с помощью
алгоритма быстрой сортировки (сортировка Хоара). Для этого необходимо выбрать
опорный элемент в массиве pivot (случайный элемент). Затем пройтись по массиву и
все элементы меньше pivot, поставить слева от pivot, а все элементы больше pivot,
поставить справа от pivot. Затем для сформированных двух частей массива (0:pivot,
pivot:end) рекурсивно повторить операции сортировки до тех пор пока весь массив не
будет отсортирован.

## Запуск программы

QuickSort.exe

**Входные данные**: не требуются, формируются автоматически

**Выходные данные**:

- unsorted.csv, исходный неотсортированнный массив
- sorted.csv, отсортированный массив

Файлы сохраняются в ту же папку, откуда запускается QuickSort.exe
