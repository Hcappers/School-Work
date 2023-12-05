#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct student{
    char itemName[30];
    float price;
} ITEM_TYPE;

int nextFreeSlot(ITEM_TYPE *itemName[]);
void addData(ITEM_TYPE *itemName[]);

int main(int argc, char *argv[]){
    int id = 0;
    int i = 0;
    ITEM_TYPE *itemArray[10] = {0};
    
    printf("Please enter an ID. \n");
    scanf("%d",&id);
    id = id -1;

    while((id >= 1) && (id <= 10)){
        for(i = 0; i < 10; i++){
            addData(itemArray);
        }
    }

}

void addData(ITEM_TYPE *itemArray[]){
    int price = 0;
    char name[30];

    int pos = nextFreeSlot(itemArray);
    if(pos == -1){
        printf("There is no available space left\n");
        return;
    }
    printf("Please enter the new id you would like to use\n");
    scanf("%d", &price);
    printf("Please enter the name of the item \n");
    scanf("%s",name);

    itemArray[pos] = (ITEM_TYPE*)malloc(sizeof(ITEM_TYPE));
    itemArray[pos] -> price = price;
    strcpy(itemArray[pos] -> itemName, name);
}

int nextFreeSlot(ITEM_TYPE *itemArray[]){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(itemArray[i] == 0){
            return i;
        }
    }
    return -1;
}  