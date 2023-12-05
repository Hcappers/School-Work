#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;

} TREE_NODE_TYPE;

TREE_NODE_TYPE *createTreeNode(int data); // function to create the binary tree
void fillTreeNode(TREE_NODE_TYPE *); // function to fill the nodes in the binary tree
void printGivenLevel(TREE_NODE_TYPE *,int); // function to print the given level of the binary tree
void breadthFirstTraversal(TREE_NODE_TYPE *); // function to print the breadth first traversal of the binary tree
void depthFirstTraversal(TREE_NODE_TYPE *); // function to print the depth first traversal of the binary tree
int treeHeight(TREE_NODE_TYPE *); // function to find the height of the binary tree

int main(int argc, char *argv[]) {
  TREE_NODE_TYPE *root = createTreeNode(1);
  fillTreeNode(root);

  printf("The height of the tree is: %d\n", treeHeight(root));
  printf("The breath first traversal of the tree is: ");
  breadthFirstTraversal(root);
  printf("\n");
  printf("The depth first traversal of the tree is: ");
  depthFirstTraversal(root);

  return 0;
}

TREE_NODE_TYPE *createTreeNode(int data) {
  TREE_NODE_TYPE *newTreeNode = (TREE_NODE_TYPE *)malloc(sizeof(TREE_NODE_TYPE));
  newTreeNode -> data = data;
  newTreeNode -> left = NULL;
  newTreeNode -> right = NULL;

  return newTreeNode;
}

void fillTreeNode(TREE_NODE_TYPE *root) {
  // creating the left side of the tree.
  root -> left = createTreeNode(2);
  root -> left -> left = createTreeNode(5);
  root -> left -> right = createTreeNode(6);
  root -> left -> left -> left = createTreeNode(11);
  root -> left -> left -> right = createTreeNode(12);
  root -> left -> left -> right -> left = createTreeNode(17);
/*  // tree should look like this so far:
  //           1
  //         /
  //        2
  //        / \   
  //     5   6
  //      / \
  //   11 12
  //       /
  //      17
  // */

  // creating the right side of the tree.
  root -> right = createTreeNode(4);
  root -> right -> left = createTreeNode(9);
  root -> right -> left -> left = createTreeNode(13);
  root -> right -> left -> right = createTreeNode(14);
  root -> right -> right = createTreeNode(10);
  root -> right -> right -> left = createTreeNode(15);
  root -> right -> right -> right = createTreeNode(16);
  // complete tree should look like this:
  //           1
  //          /   \
  //         2     4
  //        / \   / \
  //       5   6 9   10
  //      / \   / \  / \
  //     11 12 13 14 15 16
  //       / 
  //      17
}

void printGivenLevel(TREE_NODE_TYPE *root, int level){
  if (root == NULL || level < 1){
    return;
  }
  if (level == 1){
    printf("%d, ", root -> data);
  }else{
    printGivenLevel(root -> left, level -1);
    printGivenLevel(root -> right, level -1);
  }
}

void breadthFirstTraversal(TREE_NODE_TYPE *root){
  //values should be outputted from left to right, top to bottom.
  int height = treeHeight(root);
  int i;
  for (i = 1; i <= height; i++){
    printGivenLevel(root, i);
  }
}

void depthFirstTraversal(TREE_NODE_TYPE *root){
  // Needs to out put the values from the bottom up. 
  if (root != NULL){
    depthFirstTraversal(root -> left);
    depthFirstTraversal(root -> right);
    printf("%d, ", root -> data);
  }else{
    return;
  }
}

int treeHeight(TREE_NODE_TYPE *root){
  int heightLeft = 0;
  int heightRight = 0;

  if (root != NULL){
    heightLeft = treeHeight(root -> left);
    heightRight = treeHeight(root -> right);

    return (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);

  }else {
    return 0;
  }
}