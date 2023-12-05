#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
    char itemName[30];
    float price;
} ITEM_TYPE;

int main(int argc, char * argv[])
{
    ITEM_TYPE * itemPtrs[10] = {0};
    int id;
    printf("Enter an ID > 0 and < 11: ");
    scanf("%d", &id);

    while (id >= 1 && id <= 10)
    {
        id--;
        if (itemPtrs[id] == 0)
        {
            char name[30];
            float price;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter the price: ");
            scanf("%f", &price);
            itemPtrs[id] = (ITEM_TYPE *) malloc(sizeof(ITEM_TYPE));
            strcpy(itemPtrs[id]->itemName, name);
            itemPtrs[id]->price = price;
        }
        else
        {
            printf("%d already taken.\n", (id+1));
        }
        printf("Enter an ID > 0 and < 11: ");
        scanf("%d", &id);
    }//end while

    for (id = 0; id < 10; id++)
    {
        if(itemPtrs[id] != 0)
        {
            printf("ID: %d\n", (id+1));
            printf("Name: %s\n", itemPtrs[id]->itemName);
            printf("Price: %.2f\n", itemPtrs[id]->price);
        }
    }
    return 0;
}



