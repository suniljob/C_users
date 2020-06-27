/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node *Right,*Left;
}node; 

int incert_node(node **rptr,int data)
{
    
    if(*rptr==NULL)
    {
        *rptr=(node*)malloc(sizeof(node));
        if(*rptr==NULL)
        {
            printf("NOde not vreated");
            return(1);
        }
        (*rptr)->key=data;
        (*rptr)->Right=(*rptr)->Left=NULL;
    }
    else if((*rptr)->key>data)
    incert_node(&(*rptr)->Left,data);
    else if((*rptr)->key<data)
    incert_node(&(*rptr)->Right,data);
    else
    printf("Duplicate NOde");
    
  //  printf("%d  %p  %p",(*rptr)->key,(*rptr)->Left,(*rptr)->Right);
}

int inorder_node(node *ptr)
{
    if(ptr!=NULL)
    {
         inorder_node(ptr->Left);
         printf(" %d ",ptr->key);
         inorder_node(ptr->Right);
    }
    else
    return 0;
}

int preorder_node(node *ptr)
{
    if(ptr!=NULL)
    {
        printf(" %d ",ptr->key);
        preorder_node(ptr->Left);
        preorder_node(ptr->Right);
        
    }
    else
    return 0;
        
    
}

int postorder_node(node *ptr)
{
    if(ptr!=NULL)
    {
        
        postorder_node(ptr->Left);
        postorder_node(ptr->Right);
        printf(" %d ",ptr->key);
    }
    else
    {
        
        return 0;
    }    
}

int Binary_search(node *ptr,int data)
{
    if(ptr!=NULL)
    {
        if(ptr->key!=data)
        {
            if(ptr->key>data)
            Binary_search(ptr->Left,data);
            else if(ptr->key<data)
            Binary_search(ptr->Right,data);
        }
        else
        printf("Target Matched");
    }
    else
    return 1;
}

int main()
{
    node *root;
    int mode=0,data=0;
    root=NULL;
    while(1)
    {
        printf("Enter the mode=");
        scanf("%d",&mode);
        switch(mode)
        {
            case 1:printf("Enter the Data to Incert=");
                   scanf("%d",&data);
                   incert_node(&root,data);
                   break;
            case 2:printf("Inorder=");
                   inorder_node(root);
                   break;
            case 3:printf("Preorder=");
                   preorder_node(root);
                   break;
            case 4:printf("Postorder=");
                   postorder_node(root);
            case 5:printf("Enter the Node to search=");
                   scanf("%d",&data);
                   Binary_search(root,data);       
                   break;       
      ;      default:
                   break;
        }
        
        
    }
    return 0;
    
    
}
