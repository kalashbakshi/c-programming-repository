//C program to Implement a Circular Linked List and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

// function prototyping
struct node *create(int);
void insert_at_begin(int);
void insert_at_end(int);
void insert_at_position(int, int);
int getData();
int getPosition();
int size_of_list();


int main()
{
    char user_active = 'Y';
    int user_choice;
    int data, position;

    while(user_active == 'Y' || user_active == 'y')
    {

        printf("\n\n------ Circular Singly Linked List -------\n");
        printf("\n1. Insert a node at beginning");
        printf("\n2. Insert a node at end");
        printf("\n3. Insert a node at given position");

        printf("\n\n------------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);

        printf("\n------------------------------\n");
        switch(user_choice)
        {
            case 1:
                printf("\nInserting a node at beginning");
                data = getData();
                insert_at_begin(data);
                break;

            case 2:
                printf("\nInserting a node at end");
                data = getData();
                insert_at_end(data);
                break;

            case 3:
                printf("\nInserting a node at the given position");
                data = getData();
                position = getPosition();
                insert_at_position(data, position);
                break;

            default:
                printf("\n\t Invalid Choice\n");
        }

        printf("\n...............................\n");
        printf("\nDo you want to continue? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }

    return 0;
}

struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// function to insert a new node at the beginning of the list
void insert_at_begin(int data)
{
    struct node *new_node = create(data);

    if (new_node != NULL)
    {
        struct node *last = head;

        // if the list is empty
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        // traverse to the end node
        while (last->next != head)
        {
            last = last->next;
        }

        // update  the last node to the new node
        last->next = new_node;

        // update the next pointer of the new node to the head node
        new_node->next = head;

        // update the head of the list to new node
        head = new_node;
    }
}

// function to insert a new node at the end of the list
void insert_at_end(int data)
{
    struct node *new_node = create(data);

    if (new_node != NULL)
    {

        // if the list is empty
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        struct node *last = head;

        // traverse to the end node
        while (last->next != head)
        {
            last = last->next;
        }

        // update  the last node to the new node
        last->next = new_node;

        // update the next pointer of the new node to the head node
        new_node->next = head;
    }
}

// function to insert a new node at the given position
void insert_at_position(int position, int data)
{
    // checking if the position is valid or not
    if (position <= 0)
    {
        printf("\nInvalid Position\n");
    }
    else if (head == NULL && position > 1)
    {
        printf("\nInvalid Position\n");
    }
    else if (head != NULL && position > size_of_list())
    {
        printf("\nInvalid Position\n");
    }
    else if (position == 1)
    {
        insert_at_begin(data);
    }
    else
    {
        struct node *new_node = create(data);

        if (new_node != NULL)
        {
            struct node *temp = head, *prev = NULL;
            // Since, temp is already pointing to first node
            // then count will be start at second node
            int i = 1;

            // traverse the list to the given position
            while (++i <= position)
            {
                prev = temp;
                temp = temp->next;
            }

            // update the prev node to the new noe
            prev->next = new_node;

            // update the new node to the temp (position node)
            new_node->next = temp;
        }
    }
}
// function to calculate the size of the list
int size_of_list()
{
    if (head == NULL)
    {
        return 0;
    }

    struct node *temp = head;
    int count = 1;

    while (temp->next != head)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

int getData()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);

    return data;
}

int getPosition()
{
    int pos;
    printf("\n\nEnter Position: ");
    scanf("%d", &pos);

    return pos;
}
