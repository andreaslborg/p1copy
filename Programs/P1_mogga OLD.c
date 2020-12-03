#include <stdio.h>
#include <stdlib.h>

#define MAX_POSITION 3
#define MIN_POSITION 1
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ENTER_KEY 13
#define ESC_KEY 27

/* Function prototype declaration */
int mainMenu();
int modelMenu();
int finishMenu();
int readInput();
void printArrow();
void manual();

int main(void) {

    mainMenu();
    return EXIT_SUCCESS;
}

/* Funktionsliste */
int mainMenu() {
    int num, i, mainSelector=0, modelSelector, finishSelector, position=1;
    /* Menu selector */
    while(mainSelector != ENTER_KEY) {
        system("cls");
        printArrow(1, position); printf("Model system\n");
        printArrow(2, position); printf("Manual\n");
        printArrow(3, position); printf("Quit program\n");

        mainSelector = getch();
        position = readInput(mainSelector, position, 1, 3);
    }

    /* mainMenu switch case */
    switch(position) {
        case 1:
            /* Model system */
            modelMenu();
            break;
        case 2:
            /* Manual */
            system("cls");
            manual();
            printf("If you want to return to main menu, then press escape.");
            mainSelector = getch();
            if(mainSelector = ESC_KEY)
                return mainMenu();
            break;
        case 3:
            /* Quit */
            system("cls");
            printf("The program has shut down.\n");
            exit(1);
            break;
    }
}

int modelMenu() {
    int modelSelector, position=1;
    while(modelSelector != ENTER_KEY) {
        system("cls");
        printArrow(1, position); printf("New process\n");
        printArrow(2, position); printf("Delete process\n");
        printArrow(3, position); printf("Finish model\n");
        printArrow(4, position); printf("Go back to main menu\n");
        printArrow(5, position); printf("Quit program\n");

        modelSelector = getch();
        position = readInput(modelSelector, position, 1, 5);
    }
    /* modelMenu switch case */
    switch(position) {
        case 1:
            /* New process */
            printf("New process");
            break;
        case 2:
            /* Delete process */
            printf("Delete process");
            break;
        case 3:
            /* Finish model */
            finishMenu();
            break;
        case 4:
            /* Back to mainMenu */
            return mainMenu();
            break;
        case 5:
            /* Quit */
            system("cls");
            printf("The program has shut down.\n");
            exit(1);
            break;
    }
}

int finishMenu() {
    int finishSelector, position=1;
    while(finishSelector != ENTER_KEY){
        system("cls");
                                 printf("You have chosen to finish model\n");
        printArrow(1, position); printf("Total count\n");
        printArrow(2, position); printf("Ideal cycle time\n");
        printArrow(3, position); printf("Data for defect products\n");
        printArrow(4, position); printf("Data for unplanned stop\n");
        printArrow(5, position); printf("Run simulation\n");
        printArrow(6, position); printf("Go back to model system\n");
        printArrow(7, position); printf("Quit program\n");

        finishSelector = getch();
        position = readInput(finishSelector, position, 1, 7);
    }
    /* finish model switch case */
    switch(finishSelector) {
        case 1:
            /* Total count */
            break;
        case 2:
            /* Ideal cycle time */
            break;
        case 3:
            /* Defect products */
            break;
        case 4:
            /* Unplanned stop */
            break;
        case 5:
            /* Run simulation */
            break;
        case 6:
            /* Go back to model system */
            /* Virker ikke for some reason */
            return modelMenu();
            break;
        case 7:
            /* Quit */
            system("cls");
            printf("The program has shut down.\n");
            exit(1);
            break;
    }
}

/* This function prints the manual on the screen. */
void manual() {
    FILE *filePointer;
    char c; 
  
    // Open file 
    filePointer = fopen("Manual", "r"); 
    if (filePointer == NULL) { 
        printf("Can not open file \n"); 
        exit(0); 
    } 
  
    c = fgetc(filePointer);
    // Read contents from file 
    while (c != EOF) { 
        printf ("%c", c);
        c = fgetc(filePointer);
    } 

    fclose(filePointer); 
}

/* This function increments or decrements the position of the arrow in the arrow menu. */
int readInput(int keyPressed, int position, int minPosition, int maxPosition) {
    if(keyPressed == ARROW_DOWN && position != maxPosition)
        position++;
    else if(keyPressed == ARROW_UP && position != minPosition)
        position--;
    else
        position = position;
    
    return position;
}
/* This function checks that if the position from readInput is 
   the same as a position on the menu, then it print a ">" */
void printArrow (int realPosition, int arrowPosition) {
    if(realPosition == arrowPosition)
        printf(">    ");
    else
        printf("  ");
}