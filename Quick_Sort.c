#include <stdio.h>
#include <stdlib.h>

/*

To use the quick sort here are the parameters:

sort(the array you want to sort , 0 , length of the array)

it just sorts the array, so just call it (no return type / value)
Careful: quick sort is on average better than merge sort, but it may degrade to O(n^2), while merge is always O(nlog(n))
You may also put another value instead of the 0 in the parameters, it is a question of: from which element should the algorithm begin sorting?

*/


void sort (int array[] , int start , int end)
{
    if (start >= end)
    {
        return;
    }
    
    int length = end - 1;
    int pivot = array[length];
    int i = start - 1;
    int temp;
    for (int j = start; j < length; j++)
    {
        if (pivot > array[j])
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        } 
    }
    i++;
    temp = array[i];
    array[i] = pivot;
    array[length] = temp;
    sort(array,start, i);
    sort(array, i + 1, end);
}
