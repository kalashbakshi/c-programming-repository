// C Program to Insert an element at a specific position in an Array

#include <stdio.h>

int main()
{
	int arr[100] = { 0 };
	int i, x, pos, n = 10;

	// initial array of size 10
    for (i=0; i<10; i++)
    {
    	printf("Insert the %d element: ",i+1);
		scanf("%d",&arr[i]);
		printf("\n");
	}

	// print the original array
	printf("The original array is:\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// element to be inserted
	printf("Insert the element that you want to be inserted:");
	scanf("%d",&x);

	// position at which element
	// is to be inserted
	printf("Insert the position at which you want to enter the element:");
	scanf("%d",&pos);

	// increase the size by 1
	n++;

	// shift elements forward
	for (i = n - 1; i >= pos; i--)
		arr[i] = arr[i - 1];

	// insert x at pos
	arr[pos - 1] = x;

	// print the updated array
	printf("The updated array is:\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
