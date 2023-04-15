#include <stdio.h>

int main()
{
    int array[100] = { 0 };
	int i, choice, element, position, n = 10;

    // initial array of size 10
    for (i=0; i<10; i++)
    {
    	printf("Enter the %d element: ",i+1);
		scanf("%d",&array[i]);
		printf("\n");
	}
    // print the original array
	printf("The original array is:\n");
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	    printf("\n");

    while (1)
    {
        printf("\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            printf("Enter the position where the element should be inserted: ");
            scanf("%d", &position);

            if (position < 0 || position > n)
            {
                printf("Invalid position! Please enter a valid position between 0 and %d.\n", n);
            }
            else
            {
                for (i = n; i > position; i--)
                {
                    array[i] = array[i - 1];
                }
                array[position] = element;
                n++;

                printf("Element %d inserted successfully at position %d.\n", element, position);
            }
            break;

        case 2:
            printf("Enter the position of the element to be deleted: ");
            scanf("%d", &position);

            if (position < 0 || position >= n)
            {
                printf("Invalid position! Please enter a valid position between 0 and %d.\n", n - 1);
            }
            else
            {
                element = array[position];
                for (i = position; i < n - 1; i++)
                {
                    array[i] = array[i + 1];
                }
                n--;

                printf("Element %d deleted successfully from position %d.\n", element, position);
            }
            break;

        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d", &element);

            for (i = 0; i < n; i++)
            {
                if (array[i] == element)
                {
                    printf("Element %d found at position %d.\n", element, i);
                    break;
                }
            }

            if (i == n)
            {
                printf("Element %d not found in the array.\n", element);
            }
            break;

        case 4:
            printf("Exiting the program\n");
            return 0;

        default:
            printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}
