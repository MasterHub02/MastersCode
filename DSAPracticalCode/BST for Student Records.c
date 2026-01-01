#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    struct Student *left, *right;
};

// Create new node
struct Student* createNode(int roll, char name[]) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Student* insert(struct Student* root, int roll, char name[]) {
    if(root == NULL)
        return createNode(roll, name);

    if(roll < root->roll)
        root->left = insert(root->left, roll, name);
    else if(roll > root->roll)
        root->right = insert(root->right, roll, name);

    return root;
}

// Search in BST
struct Student* search(struct Student* root, int roll) {
    if(root == NULL || root->roll == roll)
        return root;

    if(roll < root->roll)
        return search(root->left, roll);
    else
        return search(root->right, roll);
}

// Inorder traversal
void inorder(struct Student* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("Roll: %d, Name: %s\n", root->roll, root->name);
        inorder(root->right);
    }
}

int main() {
    struct Student* root = NULL;
    int choice, roll;
    char name[50];

    while(1) {
        printf("\n1. Insert Student\n2. Search Student\n3. Display All\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf("%s", name);
                root = insert(root, roll, name);
                break;

            case 2: {
                printf("Enter roll to search: ");
                scanf("%d", &roll);
                struct Student* result = search(root, roll);
                if(result)
                    printf("Found: Roll %d, Name %s\n", result->roll, result->name);
                else
                    printf("Student not found!\n");
                break;
            }

            case 3:
                printf("\nStudent Records (Inorder):\n");
                inorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}




Algorithm: Student Records using BST

1. Start
2. Create BST node with:
     - Roll number
     - Student name
3. Insert student:
     - If tree empty → create root
     - If roll < current node → insert in left subtree
     - If roll > current node → insert in right subtree
4. Search student:
     - If tree empty → record not found
     - If roll == node roll → record found
     - If roll < node roll → search left subtree
     - If roll > node roll → search right subtree
5. Display students using Inorder Traversal
6. End



Start
  |
  v
Initialize root = NULL
  |
  v
Menu:
  |
  +--> Insert Student
  |      If root is NULL → create node
  |      Else compare roll:
  |         roll < node → left
  |         roll > node → right
  |
  +--> Search Student
  |      If node is NULL → Not Found
  |      If roll == node → Found
  |      Else search left/right
  |
  +--> Display Students
  |      Inorder Traversal (Left → Root → Right)
  |
  +--> Exit
  |
  v
End

