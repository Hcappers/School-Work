#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int id;
    float gpa;
}DATA_TYPE;

int menu();
int nextFreeSlot(DATA_TYPE *dataArray[]);
void addData(DATA_TYPE *dataArray[]);
void displayData(DATA_TYPE *dataArray[]);

int main(int argc, char *argv[]){
    int choice = 0;
    DATA_TYPE *dataArray[6] = {0};

    choice = menu();

    while(choice){
        if(choice == 1){
            addData(dataArray);
        }
        if(choice == 2){
            displayData(dataArray);
        }
        if(choice == 3){
            printf("Good bye\n");
            break;
        }
        if(choice < 1 || choice > 3){
            printf(" Sorry that was a invalid option please run again\n");
        }
        choice = menu();
    }
    return 0;
}

int menu(){
    int choice = 0;

    printf("Welcome! Please choose an option\n");
    printf("Option 1: Add data\n");
    printf("Option 2: Display data\n");
    printf("Option 3: Exit\n");
    scanf("%d", &choice);
    return choice;
}

void addData(DATA_TYPE *dataArray[]){
    int option = 0;
    int newId = 0;
    float newGpa = 0.0;
    int pos = nextFreeSlot(dataArray);
    if(pos == -1){
        printf("Sorry there is no more space\n");
        return;
    }
    printf("Please enter the ID\n");
    scanf("%d", &newId);
    printf("Please enter the GPA\n");
    scanf("%f", &newGpa);

    DATA_TYPE *dataPTR = (DATA_TYPE *)malloc(sizeof(DATA_TYPE));
    dataPTR -> id = newId;
    dataPTR -> gpa = newGpa;
    dataArray[pos] = dataPTR;
}

void displayData(DATA_TYPE *dataArray[]){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(dataArray[i] != NULL){
            printf("ID: %d\n", dataArray[i] -> id);
            printf("GPA: %.2f\n", dataArray[i] -> gpa);
        }
    }
}

int nextFreeSlot(DATA_TYPE *dataArray[]){
    int i = 0;
    for(i = 0; i < 6; i++){
        if(dataArray[i] == 0){
            return i;
        }
    }
    return -1;
}

void displayData(DATA_TYPE *dataArray[]){
    int i = 0;
    while(i < 6 && dataArray[i] != 0){
        printf("ID: %d\n", dataArray[i] -> id);
        printf("GPA: %f\n", dataArray[i] -> gpa);
        printf("********************************** \n");
        i++;
    }
}