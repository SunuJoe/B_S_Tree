// tree.h //
// basic tree using linked list.

#ifndef __TREE_H__
#define __TREE_H__

typedef int TDATA;

typedef struct __treeNode
{
  TDATA data;
  struct __treeNode* left;
  struct __treeNode* right;
} TREE;

TREE* makeNode(void);

void setData(TREE* root, TDATA data);
TDATA getData(TREE* root);

//make sub tree is with dynamic memory free.
void makeLeftSubTree(TREE* root, TREE* sub);
void makeRightSubTree(TREE* root, TREE* sub);

//change sub tree is no using free.
void changeLeftSubTree(TREE* root, TREE* sub);
void changeRightSubTree(TREE* root, TREE* sub);

TREE* getLeftSubTree(TREE* root);
TREE* getRightSubTree(TREE* root);

//remove
TREE* removeLeftSubTree(TREE* root);
TREE* removeRightSubTree(TREE* root);

typedef void (*Func_React)(TDATA data);

//Traversal for free sub trees. when using makeleftsubTree.
void Traversal(TREE* root);

void postTraversal(TREE* root, Func_React action);

#endif
