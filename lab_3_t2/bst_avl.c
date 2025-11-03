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

typedef struct AVLNode {
  struct AVLNode *left;
  struct AVLNode *right;
  Artist artist;
  int height;
} AVLNode;

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

AVLNode *createAVLNode(Artist artist) {
  AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
  if (newNode == NULL) {
    printf("Memory allocation failed for AVLNode");
    exit(1);
  }
  newNode->artist = artist;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1;
  return newNode;
}

int max(int a, int b) { return (a > b) ? a : b; }

int height(AVLNode *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int compareArtists(Artist a1, Artist a2) { return strcmp(a1.name, a2.name); }

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
    node->height = 1 + max(height(node->left), height(node->right));
  }
}

AVLNode *rightRotate(AVLNode *y) {
  AVLNode *x = y->left;
  AVLNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  updateHeight(y);
  updateHeight(x);

  return x;
}

AVLNode *leftRotate(AVLNode *x) {
  AVLNode *y = x->right;
  AVLNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

int getBalance(AVLNode *node) {
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

AVLNode *insertAVL(AVLNode *node, Artist artist) {
  if (node == NULL) {
    return createAVLNode(artist);
  }

  int cmp = compareArtists(artist, node->artist);
  if (cmp < 0) {
    node->left = insertAVL(node->left, artist);
  } else if (cmp > 0) {
    node->right = insertAVL(node->right, artist);
  } else {
    printf("Artist with name \"%s\" already exists.\\n", artist.name);
    return node;
  }

  updateHeight(node);

  int balance = getBalance(node);

  if (balance > 1 && compareArtists(artist, node->left->artist) < 0) {
    return rightRotate(node);
  }

  if (balance < -1 && compareArtists(artist, node->right->artist) > 0) {
    return leftRotate(node);
  }

  if (balance > 1 && compareArtists(artist, node->left->artist) > 0) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && compareArtists(artist, node->right->artist) < 0) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

AVLNode *minValueAVLNode(AVLNode *node) {
  AVLNode *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

AVLNode *deleteAVL(AVLNode *root, char *name) {
  if (root == NULL)
    return root;

  int cmp = strcmp(name, root->artist.name);

  if (cmp < 0)
    root->left = deleteAVL(root->left, name);
  else if (cmp > 0)
    root->right = deleteAVL(root->right, name);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      AVLNode *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      AVLNode *temp = minValueAVLNode(root->right);
      root->artist = temp->artist;
      root->right = deleteAVL(root->right, temp->artist.name);
    }
  }

  if (root == NULL)
    return root;

  updateHeight(root);

  int balance = getBalance(root);

  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

AVLNode *searchAVL(AVLNode *root, char *name) {
  if (root == NULL || strcmp(root->artist.name, name) == 0)
    return root;

  if (strcmp(name, root->artist.name) > 0)
    return searchAVL(root->right, name);

  return searchAVL(root->left, name);
}

void preorderAVL(AVLNode *node) {
  if (node != NULL) {
    printf("%s ", node->artist.name);
    preorderAVL(node->left);
    preorderAVL(node->right);
  }
}

void inorderAVL(AVLNode *node) {
  if (node != NULL) {
    inorderAVL(node->left);
    printf("%s ", node->artist.name);
    inorderAVL(node->right);
  }
}

void postorderAVL(AVLNode *node) {
  if (node != NULL) {
    postorderAVL(node->left);
    postorderAVL(node->right);
    printf("%s ", node->artist.name);
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

void displayLoop(int type, BSTNode *bstRoot, AVLNode *avlRoot) {
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
      displayLoop(1, bstRoot, NULL);
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

void buildAVLLoop() {
  int ch = 0;
  AVLNode *avlRoot = NULL;
  while (ch != -1) {
    printf("--------------------------\n");
    printf("AVL Tree\n");
    printf("--------------------------\n");
    printf("1. Insert Person\n");
    printf("2. Delete (Key)\n");
    printf("3. Search (Key)\n");
    printf("4. Display\n");
    printf("5. Exit to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1: {
      Artist newArtist;
      printf("Enter artist name: ");
      scanf("%s", newArtist.name);
      printf("Enter artist genre: ");
      scanf("%s", newArtist.genre);
      avlRoot = insertAVL(avlRoot, newArtist);
      printf("Artist %s inserted into AVL.\n", newArtist.name);
      break;
    }
    case 2: {
      char nameToDelete[STRING_SIZE];
      printf("Enter artist name to delete: ");
      scanf("%s", nameToDelete);
      avlRoot = deleteAVL(avlRoot, nameToDelete);
      printf("Artist %s deleted from AVL (if found).\n", nameToDelete);
      break;
    }
    case 3: {
      char nameToSearch[STRING_SIZE];
      printf("Enter artist name to search: ");
      scanf("%s", nameToSearch);
      if (searchAVL(avlRoot, nameToSearch) != NULL) {
        printf("Artist %s found in AVL.\n", nameToSearch);
      } else {
        printf("Artist %s not found in AVL.\n", nameToSearch);
      }
      break;
    }
    case 4:
      displayLoop(0, NULL, avlRoot);
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

void buildComparison() {
  printf("Nothing to compare yet!\n");
  return;
}

int main() {
  int ch = 0;
  while (ch != -1) {
    printf("--------------------------\n");
    printf("BST & AVL Tree Implementation\n");
    printf("--------------------------\n");
    printf("1. Work with Binary Search Tree (BST)\n");
    printf("2. Work with AVL Tree\n");
    printf("3. Compare AVL and BST\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      buildBSTLoop();
      break;
    case 2:
      buildAVLLoop();
      break;
    case 3:
      buildComparison();
      break;
    case 4:
      ch = -1;
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }
  return 0;
}
