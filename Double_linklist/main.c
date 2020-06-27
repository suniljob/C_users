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
    struct node *next,*prev;
}node;

typedef struct{
    
    node *head,*tail;
    int node_count;
}linklist; 

void init_list(linklist *ptr)
{
    ptr->head=NULL;
    ptr->tail=NULL;
    ptr->node_count=0;
}
int incert_at_tail(linklist *ptr,int value)
{
    node *nodeptr;
    nodeptr=(node*)malloc(sizeof(node));
    if(nodeptr==NULL)
    {
        return(0);
    }
    nodeptr->data=value;
    nodeptr->next=NULL;
    nodeptr->prev=ptr->tail;
    
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
    //printf(" %d \n",ptr->node_count);
    ptr->node_count++;
    
}

int incert_at_head(linklist *ptr,int value)
{
    node *nodeptr;
    nodeptr=(node*)malloc(sizeof(node));
    if(nodeptr==NULL)
    {
        return(0);
    }
    nodeptr->data=value;
    nodeptr->next=ptr->head;
    nodeptr->prev=NULL;
    
    if(ptr->node_count==0)
    {
        ptr->head=nodeptr;
        ptr->tail=nodeptr;
        
    }
    else
    {
        ptr->head->prev=nodeptr;
        ptr->head=nodeptr;
        
    }
    //printf(" %d \n",ptr->node_count);
    ptr->node_count++;
    
}
int Delete_nodefrom_head(linklist *ptr)
{
    node *nodeptr;
    nodeptr=ptr->head;
    if(ptr->node_count==0)
    {
        
        printf("NO node for delete");
        return(0);
    }
    if(ptr->tail==ptr->head)
    {
       free(ptr->tail);
       ptr->tail=NULL;
       ptr->head=NULL;
       ptr->node_count=0;
    }
    else
    {
        ptr->head=nodeptr->next;
        ptr->head->prev=NULL;
        free(nodeptr);
        ptr->node_count--;
    }
    

}

int Delete_nodefrom_tail(linklist *ptr)
{
    node *nodeptr;
    nodeptr=ptr->tail;
    if(ptr->node_count==0)
    {
        
        printf("NO node for delete");
        return(0);
    }
    if(ptr->tail==ptr->head)
    {
       free(ptr->tail);
       ptr->tail=NULL;
       ptr->head=NULL;
       ptr->node_count=0;
    }
    else
    {
        ptr->tail=nodeptr->prev;
        ptr->tail->next=NULL;
        free(nodeptr);
        ptr->node_count--;
    } 
    
}

int printf_forward(node *p)
{
    if(p==NULL)
    {
        printf("No node to printf");
        return(0);
    }    
    
    printf(" %p  %d %p\n",p->prev,p->data,p->next);
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
            case 1:printf("Enter the value for Tail node=");
                   scanf("%d",&value);
                   incert_at_tail(&list,value);
                   break;
            case 2:printf("Enter the value for head node=");
                   scanf("%d",&value);
                   incert_at_head(&list,value);
                   break;
            case 3:printf_list(&list);
                   break;       
            case 4:Delete_nodefrom_tail(&list);
                   break;
            case 5:Delete_nodefrom_head(&list);
                   break;
            default:
                   break;
        }
    }

    return 0;
}
