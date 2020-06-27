/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    
}node;

typedef struct{
    struct node *head,*tail;
    int node_count;
}linklist;

void init_list(linklist *ptr)
{
    ptr->head=NULL;
    ptr->tail=NULL;
    ptr->node_count=0;
}

int Enqueue(linklist *ptr,int value)
{
    node *nodeptr;
    nodeptr=(node*)malloc(sizeof(node));
    if(nodeptr==NULL)
    {
        printf("Node not created");
        return(0);
    }
    nodeptr->data=value;
    nodeptr->next=NULL;
    
    if(ptr->node_count==0)
    {
        ptr->head=nodeptr;
        ptr->tail=nodeptr;
        
    }
    else
    {
        ptr->tail->next=nodeptr;
        ptr->tail=nodeptr;
    }
    ptr->node_count++;
}

int dequeue(linklist *ptr)
{
    node *nodeptr=ptr->head;
    if(ptr->node_count==0)
    {
        printf("QUEUE Is Empty");
        return(0);
        
    }
    ptr->head=nodeptr->next;
    free(nodeptr);
    ptr->node_count--;
    
}
int printf_forward(node *p)
{
    if(p->next==NULL)
    {
        return(1);
    }
    printf(" %d ",p->data);
    printf_forward(p->next);
}

void printf_list(linklist *ptr)
{
    printf_forward(ptr->head);
}


int main()
{
    linklist list;
    int mode=0,value=0;
    init_list(&list);
    
    while(1)
    {
        printf("Enter the mode=");
        scanf("%d",&mode);
        switch(mode)
        {
            case 1:printf("Enter the value=");
                scanf("%d",&value);
                Enqueue(&list,value);
                break;
            case 2:dequeue(&list);
                break;
            case 3:printf_list(&list);
                break;    
            default:break;
            
        }
    }
    
    return 0;
}
