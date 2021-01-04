#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack
{
    int tos;
    int array[MAX];
};

int is_empty(struct stack*st)
{
    return (st->tos==-1)?1:0;
}

int is_full(struct stack*st)
{
    return (st->tos==MAX-1)?1:0;
}

int top(struct stack*st)
{
    return st->array[st->tos];
}

void printStack(struct stack*st)
{
    int i;
    for(i=0;i<=(st->tos);i++)
    printf("%d ",st->array[i]);
    printf("\n");
}

void simple_push(struct stack*st,int n)
{
    if(!is_full(st))
    st->array[++(st->tos)]=n;
}

void pushMinMax(struct stack*st,struct stack*maxst,struct stack*minst,int n)
{
    if (!is_full(st))
    {
        simple_push(st,n);
        if (is_empty(maxst))
        simple_push(maxst,n);
        else
        {
            if (n>=top(maxst))
            simple_push(maxst,n);
            else
            simple_push(maxst,top(maxst));
        }
        if (is_empty(minst))
        simple_push(minst,n);
        else
        {
            if (n<=top(minst))
            simple_push(minst,n);
            else
            simple_push(minst,top(minst));
        }
    }
}

int simple_pop(struct stack*st)
{
    if(!is_empty(st))
    return st->array[(st->tos)--];
}

int popMinMax(struct stack*st,struct stack*maxst,struct stack*minst)
{
    int x=simple_pop(st);
    simple_pop(maxst);
    simple_pop(minst);
}

int getMin(struct stack*minst)
{
    return top(minst);
}

int getMax(struct stack*maxst)
{
    return top(maxst);
}

int getRange(struct stack*maxst,struct stack*minst)
{
    return top(maxst)-top(minst);
}

int main()
{
    struct stack st;
    struct stack maxst;
    struct stack minst;
    int arr[]={2,4,4,1,3};
    int i;
    st.tos=-1;
    maxst.tos=-1;
    minst.tos=-1;
    for(i=0;i<5;i++)
    {
        pushMinMax(&st,&maxst,&minst,arr[i]);
    }
    printStack(&st);
    printStack(&maxst);
    printStack(&minst);
    printf("min:%d ",getMin(&minst));
    printf("max:%d ",getMax(&maxst));
    printf("range:%d \n",getRange(&maxst,&minst));
    popMinMax(&st,&maxst,&minst);
    popMinMax(&st,&maxst,&minst);
    popMinMax(&st,&maxst,&minst);
    printStack(&st);
    printStack(&maxst);
    printStack(&minst);
    printf("min:%d ",getMin(&minst));
    printf("max:%d ",getMax(&maxst));
    printf("range:%d \n",getRange(&maxst,&minst));
}