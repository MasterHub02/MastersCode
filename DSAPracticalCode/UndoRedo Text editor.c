#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 1000
#define MAX_STACK 100

typedef struct {
    char* items[MAX_STACK];
    int top;
} Stack;

// Stack functions
void init(Stack* s) { s->top = -1; }
int isEmpty(Stack* s) { return s->top == -1; }
void push(Stack* s, const char* text) { 
    if(s->top < MAX_STACK-1) s->items[++s->top] = strdup(text); 
}
char* pop(Stack* s) { return isEmpty(s) ? NULL : s->items[s->top--]; }
void clear(Stack* s) { while(!isEmpty(s)) free(pop(s)); }

// Main
int main() {
    char text[MAX_TEXT] = "";
    Stack undo, redo;
    init(&undo);
    init(&redo);

    int choice;
    char input[100];

    while(1) {
        printf("\nCurrent Text: \"%s\"\n", text);
        printf("1. Insert Text\n2. Delete Last Character\n3. Undo\n4. Redo\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // remove newline

        switch(choice) {
            case 1:
                printf("Enter text to insert: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;  // remove newline

                push(&undo, text);  // save current text
                clear(&redo);       // clear redo stack
                strcat(text, input); // append text
                break;

            case 2:
                if(strlen(text)==0) { printf("Nothing to delete!\n"); break; }
                push(&undo, text);
                clear(&redo);
                text[strlen(text)-1] = '\0'; // delete last char
                break;

            case 3: {
                char* t = pop(&undo);
                if(t) { push(&redo, text); strcpy(text, t); free(t); }
                else printf("Nothing to undo!\n");
                break;
            }

            case 4: {
                char* t = pop(&redo);
                if(t) { push(&undo, text); strcpy(text, t); free(t); }
                else printf("Nothing to redo!\n");
                break;
            }

            case 5:
                clear(&undo);
                clear(&redo);
                exit(0);

            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}



Algorithm: Stack-Based Text Editor (Undo/Redo)

1. Start
2. Initialize empty text buffer
3. Initialize UndoStack and RedoStack
4. Repeat until exit:
   a) Insert Text:
       - Push current text to UndoStack
       - Append new text to buffer
       - Clear RedoStack
   b) Delete Last Character:
       - Push current text to UndoStack
       - Remove last character from buffer
       - Clear RedoStack
   c) Undo:
       - If UndoStack not empty:
           - Push current text to RedoStack
           - Pop from UndoStack and set as current text
   d) Redo:
       - If RedoStack not empty:
           - Push current text to UndoStack
           - Pop from RedoStack and set as current text
   e) Display current text
5. End


Start
  |
  v
Initialize text="", UndoStack, RedoStack
  |
  v
Loop:
  |
  +--> Insert Text:
  |      Push current text to UndoStack
  |      Append new text
  |      Clear RedoStack
  |
  +--> Delete Last Character:
  |      Push current text to UndoStack
  |      Remove last character
  |      Clear RedoStack
  |
  +--> Undo:
  |      If UndoStack not empty:
  |          Push current text to RedoStack
  |          Pop from UndoStack -> current text
  |
  +--> Redo:
  |      If RedoStack not empty:
  |          Push current text to UndoStack
  |          Pop from RedoStack -> current text
  |
  +--> Display current text
  |
  v
Repeat until exit
  |
  v
End
