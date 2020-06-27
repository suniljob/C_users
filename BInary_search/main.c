/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int size=10;
int array[]={10,20,30,40,50,60,70,80,90,100};

int Binary_search(int target)
{
    int Ubound=(size-1),Lbound=0,m;
    
    while(Ubound>=Lbound)
    {
       m=(Ubound+Lbound)/2;
       if(target==array[m])
       return(1);   
       else if(target<array[m])
       Ubound=m-1;  
       else if(target>array[m])
       Lbound=m+1;
              
    }
    return(0);    
}

int main()
{
    int value=0,ret=0;
    while(1)
    {
       printf("Enter the value to search=");
       scanf("%d",&value);
       ret=Binary_search(value);
       if(ret)
        printf("Target Matched\n");
       else
        printf("Target not matched\n");
   
    }
    return 0;
}
