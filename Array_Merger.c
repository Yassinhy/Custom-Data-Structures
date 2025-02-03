#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void MergeArrays (int nums1[], int nums1Size, int nums2[], int nums2Size, int sum[]);

// compile time constants
#define first_array_size 7
#define second_array_size 7

int main(void)
{
    // initialize first array
    int first_array[first_array_size] = {2,4,7,12,13,15,18};

    //print the first array
    printf("First array:");
    for (int i = 0; i < first_array_size; i++)
    {
        printf(" %d", first_array[i]);
    }
    printf("\n");


    // initialize second array
    int second_array[second_array_size] = {1,3,6,9,10,12,14};

    //print the second array
    printf("Second array:");
    for (int i = 0; i < second_array_size; i++)
    {
        printf(" %d", second_array[i]);
    }
    printf("\n");

    //initialize merged array
    int merged_array_size = first_array_size + second_array_size;
    int merged_array[merged_array_size];

    //merge arrays
    MergeArrays (first_array, first_array_size, second_array, second_array_size, merged_array);

    //print the second array
    printf("Merged array:");
    for (int i = 0; i < merged_array_size; i++)
    {
        printf(" %d", merged_array[i]);
    }
    printf("\n");

    return 0;
}


void MergeArrays (int nums1[], int nums1Size, int nums2[], int nums2Size, int sum[])
{
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            sum[k] = nums1[i];
            i++;
            k++;
        }
        else if (nums1[i] > nums2[j])
        {
            sum[k] = nums2[j];
            j++;
            k++;
        }
        else
        {
            sum[k] = nums1[i];
            i++;
            k++;
            sum[k] = nums2[j];
            j++;
            k++;
        }
    }
    while (i < nums1Size)
    {
        sum[k] = nums1[i];
        i++;
        k++;
    }
    while (j < nums2Size)
    {
        sum[k] = nums2[j];
        j++;
        k++;
    }
    
}
