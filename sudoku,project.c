#include<stdio.h> //header files
int main() 
{
   
    int i,j,n,s; //initializing variables
int k,l; //initializing variables
    
int value[9][9]; //initializing matrix
    int total_row[9]; //initializing array for row
    int total_col[9]; //initializing array for column
    printf("'enter the inputs of a soduko,and check whether its correct or not'\n");
printf("\n input no of 'rows x column' \n");

    scanf("\n%d",&k); //taking input from user
    scanf("\t%d",&l); //taking input from user
   
   
   
    printf("values\n");
    for(i=0;i<k;i++)  //for loop for rows
    {
   
        total_row[i]=0; //initializing array for row
        for(j=0;j<l;j++) //for loop for columns
        {
            scanf("%d",&value[i][j]); //taking input from user
           
            total_row[i]=total_row[i]+value[i][j]; //adding the values of row
        }
    }
   
   
for(j=0;j<l;j++) //for loop for columns
    {
        total_col[j]=0; //initializing array for column
        for(i=0;i<k;i++) //for loop for rows
        {
           
            total_col[j]=total_col[j]+value[i][j];      //adding the values of column


        }
    }


for(i=0;i<k;i++) //for loop for rows
    {
        printf("\n"); //for new line
        for(j=0;j<l;j++) //for loop for columns
        {
            printf(" \t %d ",value[i][j]); //printing the values of matrix
        }
    }



s=((k*(k+1))/2);  //formula for 45 Rule in Sudoku
for(n=0;n<k;n++) 
{
    if((total_col[n])!=s) //checking the condition
   
       
    printf("\n incorrect i/p's col_%d ",n+1 ); //printing the output
   
    else if((total_row[n])!=s)
   
    printf(" incorrect i/p's row_%d ",n+1);
    else if(total_row[n] && s && total_col[n])
   
    printf("\n correct i/p for both %d  row and col ",n+1);
   
    else if(total_row[n] && s )
   
    printf("\n correct i/p for %d  row  ",n+1);
    else if(s && total_col[n])
   
    printf("\n correct i/p for %d  col ",n+1);
   
   
    else
    {
    }
}

}
