#include<stdio.h>
//To use realloc in our program
#include<stdlib.h>

#define ENLARGE_SIZE 2

int contains(const int *ptr, int current_size, int n){
    int k;
    for(k = 0; k < current_size; k++)
        if(ptr[k] == n){
            return 1;
        }
    return 0;
}

int main()
{
    int *ptr,size,i,j;

    /*
     * Let's create memory for 2 integers
     * size = ENLARGE_SIZE
     */
    size = ENLARGE_SIZE;
    ptr = malloc(size * sizeof(int));
    int x = 0;
    j = 0;
    printf("insert_numbers\n");
    while( scanf("%d", &x) != EOF ){
        if(!contains(ptr, j, x)){
            if (j == size){
                size+=ENLARGE_SIZE;
                ptr = realloc(ptr, size * sizeof(int));
                printf("size is %d\n", size);
            }
            *(ptr + j) = x;
            j+=1;
        }
        else{
            printf("%d already in set\n", x);
        }
    }

    //printing elements
    for(i = 0; i < j; i++)
        printf("%d\n",ptr[i]);

    return 0;
}