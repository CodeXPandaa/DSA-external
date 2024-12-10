#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Overflow \n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &ptr->info);
    ptr->next = head;
    head = ptr;
}

void insertAtEnd()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Overflow \n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &ptr->info);
    ptr->next = NULL;

    if (head == NULL)
    {

        head = ptr;
    }
    else
    {

        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void insertAtLocation()
{
    int loc, i;
    printf("Enter the location to insert (0 for beginning): ");
    scanf("%d", &loc);

    if (loc < 0)
    {
        printf("Invalid location!\n");
        return;
    }

    if (loc == 0)
    {
        insertAtBeginning();
        return;
    }

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Overflow \n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &ptr->info);

    struct node *temp = head;
    for (i = 0; i < loc - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Location exceeds the length of the list.\n");
        free(ptr);
    }
    else
    {
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("Underflow \n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->info);
    free(temp);
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("Underflow \n");
        return;
    }
    struct node *temp = head;
    if (temp->next == NULL)
    {

        printf("Deleted: %d\n", temp->info);
        free(temp);
        head = NULL;
    }
    else
    {

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("Deleted: %d\n", temp->next->info);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteFromLocation()
{
    int loc, i;
    printf("Enter the location to delete (0 for beginning): ");
    scanf("%d", &loc);

    if (loc < 0)
    {
        printf("Invalid location!\n");
        return;
    }

    if (loc == 0)
    {
        deleteFromBeginning();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for (i = 0; i < loc && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Location exceeds the length of the list.\n");
    }
    else
    {
        printf("Deleted: %d\n", temp->info);
        prev->next = temp->next;
        free(temp);
    }
}

void traverse()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    char ch;
    do
    {
        printf("1. Insert at beginning \n");
        printf("2. Insert at end \n");
        printf("3. Insert at location \n");
        printf("4. Delete from beginning \n");
        printf("5. Delete from end \n");
        printf("6. Delete from location \n");
        printf("7. Traverse \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtLocation();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            deleteFromLocation();
            break;
        case 7:
            traverse();
            break;
        default:
            printf("You entered a wrong choice!!\n");
        }

        printf(" \nDo you want to continue (Y/N): ");
        getchar();
        scanf("%c", &ch);
    } while (ch == 'Y' || ch == 'y');

    return 0;
}