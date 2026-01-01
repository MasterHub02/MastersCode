#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }
int isEmpty(Stack* s) { return s->top == -1; }
int isFull(Stack* s) { return s->top == MAX-1; }
void push(Stack* s, char c) { if(!isFull(s)) s->items[++s->top] = c; }
char pop(Stack* s) { return isEmpty(s) ? '\0' : s->items[s->top--]; }
char peek(Stack* s) { return isEmpty(s) ? '\0' : s->items[s->top]; }

// Function to check if parentheses are balanced
int isBalanced(const char* expr) {
    Stack s;
    init(&s);
    for(int i=0; expr[i]!='\0'; i++) {
        char c = expr[i];
        if(c=='(' || c=='{' || c=='[') {
            push(&s, c);
        } else if(c==')' || c=='}' || c==']') {
            if(isEmpty(&s)) return 0;
            char top = pop(&s);
            if((c==')' && top!='(') ||
               (c=='}' && top!='{') ||
               (c==']' && top!='['))
                return 0;
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[100];
    printf("Enter arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr,"\n")] = 0;

    if(isBalanced(expr))
        printf("Expression is Balanced\n");
    else
        printf("Expression is Not Balanced\n");

    return 0;
}




Algorithm: Balanced Parentheses

1. Start
2. Initialize an empty stack
3. Read arithmetic expression
4. For each character in expression:
   a) If character is '(', '{', or '[':
       - Push it onto the stack
   b) If character is ')', '}', or ']':
       - If stack is empty, return "Unbalanced"
       - Else, pop from stack and check if it matches the opening bracket
           - If not matched, return "Unbalanced"
5. After processing all characters:
   - If stack is empty, return "Balanced"
   - Else, return "Unbalanced"
6. End




Start
  |
  v
Initialize empty stack
  |
  v
For each character in expression:
  |
  +--> If '(', '{', '[' -> Push to stack
  |
  +--> If ')', '}', ']':
         - If stack empty -> Unbalanced (End)
         - Else pop top
         - If top does not match -> Unbalanced (End)
  |
After all characters:
  - If stack empty -> Balanced
  - Else -> Unbalanced
  |
  v
End
