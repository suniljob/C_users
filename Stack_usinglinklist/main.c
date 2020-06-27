/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct{
    struct node *head;
    struct node *tail;
    int node_count;
    
}linklist;

int Push(linklist *list,int value){

    node *nodeptr;
    nodeptr=(node*)malloc(sizeof(node));
    if(nodeptr==NULL){
        printf("Node not created");
        return(0);
    }
    nodeptr->data=value;
    nodeptr->next=NULL;
    if(list->node_count==0){
        list->head=nodeptr;
        list->tail=nodeptr;
        
    }
    else
    {
        nodeptr->next=list->head;
        list->head=nodeptr;
    }
    list->node_count++;
    
    
}

int pop(linklist *list){
    node *nodeptr;
    nodeptr=list->head;
    if(list->node_count==0){
        list->head=NULL;
        list->tail=NULL;
        printf("stack is empty");
        return(0);
    }
    else
    {
        list->head=nodeptr->next;
        free(nodeptr);
        list->node_count--;
    }
    
    
}

int recprint(node *ptr){
    if(ptr==NULL)
    {
        return(1);
    }
    printf(" %d ",ptr->data);
    recprint(ptr->next);
}

void printf_Forword(linklist *list){
    if(list->node_count==0)
    {
        printf("Stack is empty");
    }
    else
    recprint(list->head);
}

void init_list(linklist *ptr)
{
    ptr->head=NULL;
    ptr->tail=NULL;
    ptr->node_count=0;
}
void main()
{
    linklist listptr;
    int mode=0,value=0;
    init_list(&listptr);
    while(1)
    {
        printf("Enter the mode=");
        scanf("%d",&mode);
        switch(mode)
        {
            case 1: 
                printf("Enter the value to push=");
                scanf("%d",&value);
                Push(&listptr,value);
                break;
            case 2: 
                pop(&listptr);
                break;
            case 3:        
                printf_Forword(&listptr);
                break;
            default:printf("Mode not selected");
                break;  
        }
    }
}