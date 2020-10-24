//
// Created by Rustam Habibullayev on 21-Oct-20.
//

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_CAPACITY 2

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = STACK_CAPACITY;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack)
{
    free(stack->array);
    free(stack);
    printf("deallocated\n");
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void resize(struct Stack* stack)
{

    stack->capacity *= 2;
    // creating temporary array for resizing
    int *temp_arr;
    // doubling the size of the array using malloc()
    temp_arr = (int *) malloc(stack->capacity * sizeof(int));
    // copying existing elements of the stack
    for (int i = 0; i < stack->capacity; i++) {
        temp_arr[i] = stack->array[i];
    }
    // freeing allocated memory for stack array
    free(stack->array);
    // copying to stack->array
    stack->array = temp_arr;
    printf("stack reallocated, new length: %d\n", stack->capacity);
}

void shrink(struct Stack* stack){
    stack->capacity /= 2;
    stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));
    printf("stack reallocated, new length: %d\n",stack->capacity);
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        resize(stack);
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    if(stack->top <= stack->capacity/4){
        shrink(stack);
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int printStack(struct Stack* stack){

    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->array[i]);
    printf("\n\n");

return 0;
}

int main()
{
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d popped from stack\n", pop(stack));

    deallocStack(stack);
    return 0;
}

