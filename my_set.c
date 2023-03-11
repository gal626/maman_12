#include<stdio.h>
#include<stdlib.h>

/* TODO: change size */
#define ENLARGE_SIZE 2

/* checks if num is in the set starting from the pointer ptr */
int contains(const int *ptr, int current_size, int num){
    int k;
    for(k = 0; k < current_size; k++)
        if(ptr[k] == num){
            return 1;
        }
    return 0;
}

/* create a set from input of numbers until getting EOF
 * This functions ignores non digit input*/
int * get_set(int *length_of_inputs){
    int *ptr, size, num;

    size = ENLARGE_SIZE;
    /*allocate a memory for integers in amount of size*/
    ptr = malloc(size * sizeof(int));

    printf("insert_numbers\n");
    while(scanf("%d", &num) != EOF ){
        printf("input: %d\n", num);
        if(!contains(ptr, *length_of_inputs, num)){
            if (*length_of_inputs == size){
                /* enlarge the set length by ENLARGE_SIZE elements*/
                size+=ENLARGE_SIZE;
                ptr = realloc(ptr, size * sizeof(int));
                printf("size is %d\n", size); /* TODO: only for debug */
            }
            /* insert num to the set */
            *(ptr + *length_of_inputs) = num;
            *length_of_inputs+=1;
        }
        else{
            printf("%d already in set\n", num); /* TODO: only for debug */
        }
    }
    return ptr;
}

/* print 'length_of_inputs' elements starting from the pointer ptr */
void print_set(int *ptr, int length_of_inputs){
    //printing all input numbers
    printf("set is: (");
    int i;
    for(i = 0; i < length_of_inputs-1; i++)
        printf("%d, ",ptr[i]);
    printf("%d)", ptr[i]);

}

int main()
{
    /* number of integers received from the input, initialized to 0*/
    int length_of_inputs;
    length_of_inputs = 0;
    int *ptr = get_set(&length_of_inputs);
    print_set(ptr, length_of_inputs);
    return 0;
}