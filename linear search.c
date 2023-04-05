#include <stdio.h>
int main ()
{
    int arr[100];
    int i,num,e;
     printf (" \n Enter the number of elements in an array: \n ");
    scanf (" %d", &num);
    printf (" \n Enter %d elements in array: \n ", num);
    for (i = 0; i < num; i++ )
    {   printf ("Enter %d element in array: ", i+1);
        scanf (" %d", &arr[i]);
    }
    printf("Enter the element you want to check");
    scanf("%d,&e");
    for (i = 0; i < num; i++ )
    {
      if(e==arr[i])
      {
        printf("present element");
        break;
      }
      else
      {
        printf("Not present element");
        break;
      }
    }
   }









