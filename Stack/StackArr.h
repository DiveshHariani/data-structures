#include<malloc.h>
typedef struct
{
    void **stackArr;
    int max;
    int top;
}STACK;
STACK *create(int m)
{
     STACK *stack;
     stack=(STACK *)malloc(sizeof(STACK));
     if(stack==NULL) return NULL;

     stack->stackArr=(void **)malloc(sizeof(void *)*m);
     stack->max=m;
     stack->top=-1;
     return stack;
}

void push(STACK *stack,void *datap)
{
    if(stack->top==stack->max-1)
        printf("Stack if full");
    else
    {
        stack->top++;
        stack->stackArr[stack->top]=datap;
    }
}
void *pop(STACK *stack)
{
    void *ptr;
    if(stack->top==-1)
    {
        printf("Stack is empty");
        return NULL;
    }
    ptr=stack->stackArr[stack->top];
    stack->top--;
    return ptr;
}
void *peep(STACK *stack)
{
    if(stack->top==-1)
    {
        printf("Stack is empty");
        return NULL;
    }
    else
        return stack->stackArr[stack->top];
}
int full(STACK *stack)
{
    if(stack->top==stack->max-1) return 1;
    else return 0;
}
int empty(STACK *stack)
{
    if(stack->top==-1) return 1;
    else return 0;
}
void destroy(STACK *stack)
{
    printf("Stack is destroyed");
    free(stack);
    free(stack->stackArr);
}
