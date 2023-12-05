#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct data{
    int id;
    float gpa;
}DATA_TYPE;

typedef struct listnode{
    DATA_TYPE *dataStructPtr; //head
    struct listnode *next;
}LIST_NODE_TYPE;

int menu();
void processChoice(int, LIST_NODE_TYPE **, char *, char *);
void addDataToFront(LIST_NODE_TYPE **);
void addDataToBack(LIST_NODE_TYPE **);
void removeDataFromFront(LIST_NODE_TYPE **);
void removeDataFromBack(LIST_NODE_TYPE **);
void findData(LIST_NODE_TYPE **);
void displayData(LIST_NODE_TYPE **);
void writeToFile(LIST_NODE_TYPE **, char *);
void readFromFile(LIST_NODE_TYPE **, char *);
void append(LIST_NODE_TYPE **,DATA_TYPE *);

int main(int argc, char *argv[]){
    LIST_NODE_TYPE *headPtr = NULL;
    char *outFileName = "studentData.bin";
    char *inFileName = "studentData.bin";
    int choice = 0;
    int id = 0;

    choice = menu();
    processChoice(choice, &headPtr, outFileName, inFileName);

    while (choice != 9){
        choice = menu();
        processChoice(choice, &headPtr, outFileName, inFileName);
    }
    return 0;
}
int menu(){
    int choice = 0;
    printf("Please choose from the following options:\n");
    printf("1. Add data to the front of the list\n");
    printf("2. Add data to the back of the list\n");
    printf("3. Remove data from the front of the list\n");
    printf("4. Remove data from the back of the list\n");
    printf("5. Find data in the list\n");
    printf("6. Display data in the list\n");
    printf("7. Write data to file\n");
    printf("8. Read data from file\n");
    printf("9. Quit\n");
    scanf("%d", &choice);
    return choice;
}
void processChoice(int choice, LIST_NODE_TYPE **headPtrPtr, char *outFileName, char *inFileName){
    switch(choice){
        case 1:
            addDataToFront(headPtrPtr);
            break;
        case 2:
            addDataToBack(headPtrPtr);
            break;
        case 3:
            removeDataFromFront(headPtrPtr);
            break;
        case 4:
            removeDataFromBack(headPtrPtr);
            break;
        case 5:
            findData(headPtrPtr);
            break;
        case 6:
            displayData(headPtrPtr);
            break;
        case 7:
            writeToFile(headPtrPtr, outFileName);
            break;
        case 8:
            readFromFile(headPtrPtr, inFileName);
            break;
        case 9:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}
void addDataToFront(LIST_NODE_TYPE **headPtrPtr){
    int id = 0;
    float gpa = 0.0;
    int end = 0;

    DATA_TYPE *newDataPtr = (DATA_TYPE*)malloc(sizeof(DATA_TYPE));
    printf("Please enter the id of the student you would like to add to the front of the list\n");
    scanf("%d", &id);
    newDataPtr -> id = id;

    printf("Please enter the gpa of the student you would like to add to the front of the list\n");
    scanf("%f", &gpa);
    newDataPtr -> gpa = gpa;

    LIST_NODE_TYPE *nodePtr = (LIST_NODE_TYPE*)malloc(sizeof(LIST_NODE_TYPE));
    nodePtr -> dataStructPtr = newDataPtr;
    nodePtr -> next = NULL;

    if(*headPtrPtr == NULL){
        *headPtrPtr = nodePtr;
        return;
    }
    nodePtr -> next = *headPtrPtr;
    *headPtrPtr = nodePtr;
}
void addDataToBack(LIST_NODE_TYPE **headPtrPtr){
    int id = 0;
    float gpa = 0.0;
    int end = 0;
    int exit = 0;

    DATA_TYPE *newDataPtr = (DATA_TYPE*)malloc(sizeof(DATA_TYPE));
    printf("Please enter the id of the student you would like to add.\n");
    scanf("%d", &id);
    newDataPtr -> id = id;

    printf("Please enter the gpa of the student you would like to add.\n");
    scanf("%f", &gpa);
    newDataPtr -> gpa = gpa;

    LIST_NODE_TYPE *nodePtr = (LIST_NODE_TYPE*)malloc(sizeof(LIST_NODE_TYPE));
    nodePtr -> dataStructPtr = newDataPtr;
    nodePtr -> next = NULL;

    if(*headPtrPtr == NULL){
        *headPtrPtr = nodePtr;
        return;
    }
    LIST_NODE_TYPE *currPtr = *headPtrPtr;
    LIST_NODE_TYPE *prevPtr = NULL;
    while(currPtr){
        prevPtr = currPtr;
        currPtr = currPtr -> next;
    }
    prevPtr -> next = nodePtr;
}
void removeDataFromFront(LIST_NODE_TYPE **headPtrPtr){
    LIST_NODE_TYPE *currPtr = *headPtrPtr;

    if(*headPtrPtr == NULL){
    printf("Sorry there is no data to remove.\n");
    }else{
        *headPtrPtr = currPtr -> next;
        free(currPtr -> dataStructPtr);
        free(currPtr);
    }
}
void removeDataFromBack(LIST_NODE_TYPE **headPtrPtr){
    LIST_NODE_TYPE *currPtr = *headPtrPtr;
    LIST_NODE_TYPE *prevPtr = NULL;
    LIST_NODE_TYPE *temp;

    while(currPtr -> next != NULL){
        prevPtr = currPtr;
        currPtr = currPtr -> next;
    }
    if(prevPtr == NULL){
        *headPtrPtr = NULL;
    }else{
        prevPtr -> next = NULL;
    }
    free(currPtr -> dataStructPtr);
    free(currPtr);
}
void findData(LIST_NODE_TYPE **headPtrPtr){
    int choice = 0;
    int searchID = 0;
    float searchGPA = 0.0;
    LIST_NODE_TYPE *currPtr = *headPtrPtr;

    printf("Please choose from the following options:\n");
    printf("1. Search by ID\n");
    printf("2. Search by GPA\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("Please enter the ID you would like to search for.\n");
            scanf("%d", &searchID);
            while(currPtr){
                int comparedID = currPtr -> dataStructPtr -> id;
                float comparedGPA = currPtr -> dataStructPtr -> gpa;
                if(comparedID == searchID){
                    printf("THe details for that ID are:\n");
                    printf("ID: %d\n, GPA: %.2f\n", comparedID, comparedGPA);
                }
            }
            printf("Sorry that ID was not found.\n");
            break;
        case 2:
            printf("Please enter the GPA you would like to search for.\n");
            scanf("%f", &searchGPA);
            while(currPtr){
                int comparedID = currPtr -> dataStructPtr -> id;
                float comparedGPA = currPtr -> dataStructPtr -> gpa;
                if(comparedGPA == searchGPA){
                    printf("THe details for that GPA are:\n");
                    printf("ID: %d\n, GPA: %.2f\n", comparedID, comparedGPA);
                }
            }
            printf("Sorry that GPA was not found.\n");
            break;
        default:
            printf("Sorry that was a invalid option please try again.\n");
            break;
    }
}

void displayData(LIST_NODE_TYPE **headPtrPtr){
    printf("current data on the list");
    LIST_NODE_TYPE *currPtr = *headPtrPtr;
    if(currPtr != NULL){
        while(currPtr){
            int displayID = currPtr -> dataStructPtr -> id;
            float displayGPA = currPtr -> dataStructPtr -> gpa;
            printf("ID: %d\n, GPA: %.2f\n", displayID, displayGPA);
            currPtr = currPtr -> next;
        }
    }else{
        printf("Sorry there is no data to display.\n");
    }
}
void writetoFile(LIST_NODE_TYPE **headPtrPtr, char *outFileName){
    int fd = open(outFileName, O_WRONLY | O_CREAT, 0644);
    LIST_NODE_TYPE *currPtr = *headPtrPtr;
    if(fd == -1){
        printf("Sorry there was an error opening the file.\n");
        return;
    }
    while(currPtr){
        DATA_TYPE *dataPtr = currPtr -> dataStructPtr;
        write(fd, dataPtr, sizeof(DATA_TYPE));
        currPtr = currPtr -> next;
    }
    close(fd);
}
void readFromFile(LIST_NODE_TYPE **headPtrPtr, char *inFileName){
    int fd = open(inFileName, O_RDONLY);
    DATA_TYPE readData;

    if(fd == -1){
        printf("Sorry there was an error opening the file.\n");
        return;
    }
    while(read(fd, &readData, sizeof(DATA_TYPE))== sizeof(DATA_TYPE)){
        DATA_TYPE *readDataPtr = (DATA_TYPE*)malloc(sizeof(DATA_TYPE));
        readDataPtr -> id = readData.id;
        readDataPtr -> gpa = readData.gpa;
        append(headPtrPtr, readDataPtr);
    }
    close(fd);
}
void append(LIST_NODE_TYPE **headPtrPtr, DATA_TYPE *data){
    LIST_NODE_TYPE *nodePtr = (LIST_NODE_TYPE*)malloc(sizeof(LIST_NODE_TYPE));
    nodePtr -> dataStructPtr = data;
    nodePtr -> next = NULL;

    if(*headPtrPtr == NULL){
        *headPtrPtr = nodePtr;
        return;
    }
    LIST_NODE_TYPE *currPtr = *headPtrPtr;
    LIST_NODE_TYPE *prevPtr = NULL;

    while(currPtr){
        prevPtr = currPtr;
        currPtr = currPtr -> next;
    }
    prevPtr -> next = nodePtr;
}