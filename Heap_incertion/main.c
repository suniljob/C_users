/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int size = 10, i = 1;
int arra[10];
int
incert_heap (int *ptr)
{
  int temp = 0, j = 0;
  arra[i] = *ptr;
  for (j = (i / 2); j >= 1; j = (j / 2))
    {
        //printf("Struck");
      if (arra[i] > arra[j])
	{
	  temp = arra[i];
	  arra[i] = arra[(i / 2)];
	  arra[(i / 2)] = temp;
	}
    }
  i++;

}

int
main ()
{
  int mode = 0, data = 0,k=0;
  while (1)
    {
      printf ("Enter the Mode=");
      scanf ("%d", &mode);
      switch (mode)
	{
	case 1:
	  printf ("Enter the data=");
	  scanf ("%d", &data);
	  incert_heap (&data);
	  break;
	case 2: for(k=1;k<size;k++)
	        printf(" %d ",arra[k]);
	        printf("\n");
	  break;
	default:
	  break;


	}


    }
  return 0;
}
