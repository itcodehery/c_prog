#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 25

typedef struct {
  char name[STRING_SIZE];
  char genre[STRING_SIZE];
} Artist;

typedef struct BSTNode {
  struct BSTNode *left;
  struct BSTNode *right;
  int age;
} BSTNode;

BSTNode *createBSTNode(int age) {
  BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
  if (newNode == NULL) {
    printf("Memory allocation failed for BSTNode");
    exit(1);
  }
  newNode->age = age;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int max_val(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

BSTNode *insertBST(BSTNode *node, int age) {
  if (node == NULL) {
    return createBSTNode(age);
  }

  if (age < node->age) {
    node->left = insertBST(node->left, age);
  } else if (age > node->age) {
    node->right = insertBST(node->right, age);
  }
  return node;
}

BSTNode *minValueNode(BSTNode *node) {
  BSTNode *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

BSTNode *deleteBST(BSTNode *root, int age) {
  if (root == NULL)
    return root;

  if (age < root->age)
    root->left = deleteBST(root->left, age);
  else if (age > root->age)
    root->right = deleteBST(root->right, age);
  else {
    if (root->left == NULL) {
      BSTNode *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      BSTNode *temp = root->left;
      free(root);
      return temp;
    }

    BSTNode *temp = minValueNode(root->right);

    root->age = temp->age;

    root->right = deleteBST(root->right, temp->age);
  }
  return root;
}

void updateHeight(AVLNode *node) {
  if (node) {
    node->height = 1 + max_val(height(node->left), height(node->right));
  }
}

void inorderBST(BSTNode *node) {
  if (node != NULL) {
    inorderBST(node->left);
    printf("%d ", node->age);
    inorderBST(node->right);
  }
}

void preorderBST(BSTNode *node) {
  if (node != NULL) {
    printf("%d ", node->age);
    preorderBST(node->left);
    preorderBST(node->right);
  }
}

void postorderBST(BSTNode *node) {
  if (node != NULL) {
    postorderBST(node->left);
    postorderBST(node->right);
    printf("%d ", node->age);
  }
}

BSTNode *searchBST(BSTNode *node, int age) {
  if (node == NULL || node->age == age) {
    return node;
  }

  if (age > node->age) {
    return searchBST(node->right, age);
  }

  return searchBST(node->left, age);
}

void displayLoop(int type, BSTNode *bstRoot) {
  int ch = 0;
  char *name = type == 0 ? "AVL" : "BST";
  while (ch != -1) {
    printf("-----------------------\n");
    printf("Display for %s\n", name);
    printf("-----------------------\n");
    printf("1. Preorder\n");
    printf("2. Inorder\n");
    printf("3. Postorder\n");
    printf("4. Exit Display Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Preorder Traversal: ");
      if (type == 1) {
        preorderBST(bstRoot);
      } else {
        preorderAVL(avlRoot);
      }
      printf("\n");
      break;
    case 2:
      printf("Inorder Traversal: ");
      if (type == 1) {
        inorderBST(bstRoot);
      } else {
        inorderAVL(avlRoot);
      }
      printf("\n");
      break;
    case 3:
      printf("Postorder Traversal: ");
      if (type == 1) {
        postorderBST(bstRoot);
      } else {
        postorderAVL(avlRoot);
      }
      printf("\n");
      break;
    case 4:
      ch = -1;
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
    printf("\n");
  }
}

void buildBSTLoop() {
  int ch = 0;
  BSTNode *bstRoot = NULL;
  while (ch != -1) {
    printf("--------------------------\n");
    printf("Binary Search Tree\n");
    printf("--------------------------\n");
    printf("1. Insert Age Value\n");
    printf("2. Delete (Key)\n");
    printf("3. Search (Key)\n");
    printf("4. Display\n");
    printf("5. Exit to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1: {
      int age;
      printf("Enter age to insert: ");
      scanf("%d", &age);
      bstRoot = insertBST(bstRoot, age);
      printf("Age %d inserted into BST.\n", age);
      break;
    }
    case 2: {
      int age;
      printf("Enter age to delete: ");
      scanf("%d", &age);
      bstRoot = deleteBST(bstRoot, age);
      printf("Age %d deleted from BST (if found).\n", age);
      break;
    }
    case 3: {
      int age;
      printf("Enter age to search: ");
      scanf("%d", &age);
      if (searchBST(bstRoot, age) != NULL) {
        printf("Age %d found in BST.\n", age);
      } else {
        printf("Age %d not found in BST.\n", age);
      }
      break;
    }
    case 4:
      displayLoop(1, bstRoot);
      break;
    case 5:
      ch = -1;
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }
}

int main() {
  buildBSTLoop();
  return 0;
}
