#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

static const int SIZE_ARRAY = 10;

void swap (int array[], int i, int j)
{
    int tmp;

    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void quick_sort_iteration (int array[], int n)
{
    int i, last;

    swap(array, 0, rand() % n);
    last = 0;
    for (i = 0; i < n; i++)
        if (array[i] < array[0])
            swap(array, ++last, i);

    
}

void quick_sort_recursion (int array[], int n)
{
    int i, last;

    if (n <= 1)
        return;

    swap(array, 0, rand() % n);
    last = 0;
    for (i = 0; i < n; i++)
        if (array[i] < array[0])
            swap(array, ++last, i);
    swap(array, 0, last);
    quick_sort_recursion(array, last);
    quick_sort_recursion(array + last + 1, n - last - 1);
}

int main (void)
{
    int array_src[SIZE_ARRAY];

    for (int i = 0; i < SIZE_ARRAY; i++)
        array_src[i] = rand() % (i + 1);

    for (int i = 0; i < SIZE_ARRAY; i++)
        printf("%d ", array_src[i]);

    printf("\n");

    quick_sort_iteration(array_src, SIZE_ARRAY);

    for (int i = 0; i < SIZE_ARRAY; i++)
        printf("%d ", array_src[i]);

    printf("\n");

    return 0;
}


