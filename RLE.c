#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* RLE(char* input) {
    char* output = malloc(2 * strlen(input) + 1);
    int k = 0;
    int out_put_index = 0;
    while (input[k] != '\0')
    {
        char current = input[k];
        int counter = 1;

        while (input[k + 1] != '\0' && current == input[k + 1])
        {
            k++;
            counter++;
        }
        out_put_index += sprintf(&output[out_put_index], "%d%c", counter, current);
        k++;
    }
    sprintf(&output[out_put_index], "\0");
    return output;
}
