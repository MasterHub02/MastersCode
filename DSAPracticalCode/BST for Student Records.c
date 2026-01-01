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
