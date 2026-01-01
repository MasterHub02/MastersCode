#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    struct Employee *left, *right;
};

// Create new employee node
struct Employee* createEmployee(int id, char name[]) {
    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Preorder Traversal (Manager → Subordinates)
void preorder(struct Employee* root) {
    if(root != NULL) {
        printf("ID: %d Name: %s\n", root->id, root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal
void inorder(struct Employee* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("ID: %d Name: %s\n", root->id, root->name);
        inorder(root->right);
    }
}

// Postorder Traversal (Subordinates → Manager)
void postorder(struct Employee* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("ID: %d Name: %s\n", root->id, root->name);
    }
}

int main() {
    // Creating company hierarchy
    struct Employee* CEO = createEmployee(1, "CEO");
    CEO->left = createEmployee(2, "Manager_A");
    CEO->right = createEmployee(3, "Manager_B");
    CEO->left->left = createEmployee(4, "Employee_1");
    CEO->left->right = createEmployee(5, "Employee_2");

    printf("\nPreorder Traversal (Manager First):\n");
    preorder(CEO);

    printf("\nInorder Traversal:\n");
    inorder(CEO);

    printf("\nPostorder Traversal (Employee First):\n");
    postorder(CEO);

    return 0;
}




Algorithm: Employee Hierarchy using Tree Traversal

1. Start
2. Create employee node with:
     - Employee ID
     - Employee Name
     - Left child
     - Right child
3. Insert employees into tree
4. Traverse tree using:
     a) Preorder Traversal → Manager before subordinates
     b) Inorder Traversal → Hierarchical order
     c) Postorder Traversal → Subordinates before manager
5. Display employee details during traversal
6. End



Start
  |
  v
Is node NULL?
  |
  +-- Yes → Return
  |
  +-- No →
        Visit node
        Traverse left subtree
        Traverse right subtree
  |
  v
End
