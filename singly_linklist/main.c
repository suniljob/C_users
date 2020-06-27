/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  unsigned int value;
  struct node *next;
} node;

typedef struct
{

  struct node *head;
  struct node *tail;
  int nodecount;
} listptr;

void
initlist (listptr * linklst)
{

  linklst->head = NULL;
  linklst->tail = NULL;
  linklst->nodecount = 0;

}

void
Incert_node_fromTail (listptr * linklistptr, unsigned int data)
{
  node *newnodeptr = (node *) malloc (sizeof (node));
  if (newnodeptr == NULL)
    {
      printf ("Node not created");
      return;

    }
  newnodeptr->value = data;
  newnodeptr->next = NULL;
  if (linklistptr->nodecount == 0)
    {
      linklistptr->head = newnodeptr;
      linklistptr->tail = newnodeptr;

    }
  else
    {
      linklistptr->tail->next = newnodeptr;
      linklistptr->tail = newnodeptr;

    }
  
  linklistptr->nodecount++;

}

void
Incert_node_fromhead (listptr * linklistptr, unsigned int data)
{

  node *newnodeptr = (node *) malloc (sizeof (node));

  if (newnodeptr == NULL)
    {
      printf ("Node not created");
      return;

    }
  newnodeptr->value = data;
  newnodeptr->next = NULL;
  if (linklistptr->nodecount == 0)
    {
      linklistptr->head = newnodeptr;
      linklistptr->tail = newnodeptr;

    }
  else
    {

      newnodeptr->next = linklistptr->head;
      linklistptr->head = newnodeptr;


    }

  linklistptr->nodecount++;

}

int
print_the_list (listptr * linklistptr)
{
  node *current;
  if (linklistptr->nodecount == 0)
    {
      printf ("No node to print\n");
      return (1);
    }
  current = linklistptr->head;

  while (current != NULL)
    {

      printf (" %d ", current->value);
      current = current->next;

    }

  printf ("\r\n");
}

int
print_the_Detaillist (listptr * linklistptr)
{
  node *current;
  if (linklistptr->nodecount == 0)
    {
      printf ("No node to print\n");
      return (1);
    }

  current = linklistptr->head;
  printf ("Head=%p\n", current);
  while (current != NULL)
    {

      printf ("%p %d %p\n", current, current->value, current->next);
      current = current->next;


    }
  printf ("tail=%p\n", linklistptr->tail);
}

void
find_data_in_list (listptr * linklistptr, unsigned int target)
{
  node *node_data;
  node_data = linklistptr->head;
  while (node_data != NULL)
    {
      if (node_data->value == target)
	{
	  printf ("%p %d  %p\n", node_data, node_data->value,
		  node_data->next);
	}
      node_data = node_data->next;
    }

}

int
Delete_head_node (listptr * linklistptr)
{
  node *headnode_del;
  if (linklistptr->nodecount == 0)
    {

      printf ("No NOde is there to Delete\n");
      return (1);
    }
  else
    {
      headnode_del = linklistptr->head;
      linklistptr->head = headnode_del->next;
      linklistptr->nodecount--;
      free (headnode_del);
    }
}

int
Delete_tail_node (listptr * linklistptr)
{
  node *tailnode_del,*tempnode;
  tailnode_del = linklistptr->head;
  if (linklistptr->nodecount == 0)
    {

      printf ("No NOde is there to Delete\n");
      return (1);
    }
    else if(tailnode_del->next==NULL)
    {
        free(tailnode_del);
        linklistptr->nodecount--;
    }
  else
    {
      
     while ((tailnode_del != linklistptr->tail))
	{
	  tempnode=tailnode_del;
	  tailnode_del = tailnode_del->next;
	}
	
    linklistptr->tail = tempnode;
    linklistptr->tail->next = NULL;
    free(tailnode_del);
    linklistptr->nodecount--; 	
    


    }

  
  free (tailnode_del->next);
 }
 
void 
Delete_inbetween_node(listptr * linklistptr,unsigned int target)
{
    node *nodeptr,*current;
    nodeptr=linklistptr->head;
   
    while(nodeptr!=linklistptr->tail)
    {
        current=nodeptr;
        nodeptr=nodeptr->next;
        if(nodeptr->value==target)
        {
            current->next=nodeptr->next;
            free(nodeptr);
            nodeptr=current->next;
            linklistptr->nodecount--;
        }
        
    }
    
}
 
void Reverse_list(listptr * linklistptr)
{
    node *nodeptr,*current,*tempptr;
    nodeptr=linklistptr->head; 
    while(nodeptr!=NULL)
    {
        tempptr=nodeptr->next;
        if(nodeptr==linklistptr->head)
        nodeptr->next=NULL;
        else
        nodeptr->next=current;
        
        current=nodeptr;
        nodeptr=tempptr;
    }
    linklistptr->tail=linklistptr->head;
    linklistptr->head=current;
}

int forward_list(node *nodeptr)
{
    
    
    if(nodeptr==NULL)
    {
        return(0);
    }
    printf(" %d ",nodeptr->value);
    forward_list(nodeptr->next);
}

void print_listforward(listptr *ptr)
{
    
    forward_list(ptr->head);
}

int RecReverse_list(node *nodeptr)
{
    
    
    if(nodeptr==NULL)
    {
        return(0);
    }
    
    RecReverse_list(nodeptr->next);
    printf(" %d ",nodeptr->value);
}


void print_listReverse(listptr *ptr)
{
    
    RecReverse_list(ptr->head);
}


int
main ()
{
  unsigned int data;
  int choise = 0;
  listptr lstptr;
  initlist (&lstptr);

  while (1)
    {

      printf ("Enter the choise=");
      scanf ("%d", &choise);

      switch (choise)
	{
	case 1:
	  printf ("Incert the dat in tail end=");
	  scanf ("%d", &data);
	  Incert_node_fromTail (&lstptr, data);
	  break;
	case 2:
	  printf ("Incert the dat in head end=");
	  scanf ("%d", &data);
	  Incert_node_fromhead (&lstptr, data);
	  break;
	case 3:
	  printf ("Enter the data to find in the linked list=");
	  scanf ("%d", &data);
	  find_data_in_list (&lstptr, data);
	  break;
	case 4:
	  printf ("print the list\r\n");
	  print_the_list (&lstptr);
	  break;
	case 5:
	  printf ("print the linkedlist detail\r\n");
	  print_the_Detaillist (&lstptr);
	  break;
	case 6:
	  printf("Enter the data to delete_inbetween");
	  scanf("%d",&data);
	  Delete_inbetween_node(&lstptr,data);  
	  break;  
	case 7:
	  Delete_head_node (&lstptr);
	  break;
	case 8:
	  Delete_tail_node (&lstptr);
	  break;
	case 9:
	  Reverse_list(&lstptr);
	  break;
	case 10:
	  print_listforward(&lstptr);
	  break;
	case 11:
	  print_listReverse(&lstptr);
	  break;  
	  
	  
	default:
	  printf ("no option selected\r\n");
	  break;
	}



    }


  return 0;
}


