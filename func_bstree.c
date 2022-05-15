// func_bstree.c //
// define functions of binary search tree.

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
// #include "tree.h"

void Init(TREE** root)
{
  *root = NULL;
}

//Searching.
TREE* Searching(TREE* root, TDATA target)
{
  TREE* cNode = root;

  while(cNode != NULL)
  {
    if(getData(cNode) == target)
    {
      return cNode;
    }
    else if(target < getData(cNode))
    {
      cNode = getLeftSubTree(cNode);
    }
    else
    {
      cNode = getRightSubTree(cNode);
    }
  }
  return NULL;
}


// Insertion.
void Insert(TREE** root, TDATA data)
{
  TREE* pNode = NULL; //parent node address; 
  TREE* cNode = *root;
  TREE* nNode; //new Node;

  while(cNode != NULL)
  {
    pNode = cNode;

    if(getData(cNode) == data)
    {
      // violation of key rules.
      return;
    }
    else if(data < getData(cNode))
    {
      cNode = getLeftSubTree(cNode);
    }
    else
    {
      cNode = getRightSubTree(cNode);
    }
  }

  nNode = makeNode();
  setData(nNode, data);
 
  if(pNode != NULL)
  {
    if(data < getData(pNode))
    {
      makeLeftSubTree(pNode, nNode);
    }
    else
    {
      makeRightSubTree(pNode, nNode);
    }
  }
  else
  {
    *root = nNode;
  }
}

// Remove.

TREE* Remove(TREE** root, TDATA target)
{
  TREE* vRoot = makeNode();
  TREE* cNode = *root;
  TREE* pNode = vRoot;
  TREE* Temp; //remove node address for memory free.

  // connection of virtual root of right side main root.
  changeRightSubTree(vRoot, *root);

  while(cNode != NULL && getData(cNode) != target)
  {
    pNode = cNode;

    if(target < getData(cNode))
    {
      cNode = getLeftSubTree(cNode);
    }
    else
    {
      cNode = getRightSubTree(cNode);
    }
  }


  if(cNode == NULL)
    return NULL;
  
  if(getLeftSubTree(cNode) == NULL && getRightSubTree(cNode) == NULL)
  {
    if(target == getData(getLeftSubTree(pNode)))
    {
      Temp = removeLeftSubTree(pNode);
    }
    else
    {
      Temp = removeRightSubTree(pNode);
    }
  }

  else if(getLeftSubTree(cNode) == NULL || getRightSubTree(cNode) == NULL)
  {
    //cNode sub child address.
    TREE* subcNode;
    Temp = cNode;

    if(getLeftSubTree(cNode) == NULL)
    {
      subcNode = cNode->right;  
    }
    else
    {
      subcNode = cNode->left;
    }
    
    if(getLeftSubTree(pNode) == cNode)
    {
      changeLeftSubTree(pNode, subcNode);
    }
    else
    {
      changeRightSubTree(pNode, subcNode);
    }
  }

  else
  {
    TREE* mNode = getRightSubTree(cNode);
    TREE* mpNode = cNode;
    TDATA temp_data;

    while(getLeftSubTree(mNode) != NULL)
    {
      mpNode = mNode;
      mNode = getLeftSubTree(mNode);
    }
    
    temp_data = getData(cNode);
    setData(cNode, getData(mNode));

    if(getLeftSubTree(mpNode) == mNode)
    {
      changeLeftSubTree(mpNode, getRightSubTree(mNode));
    }
    else
    {
      changeRightSubTree(mpNode, getRightSubTree(mNode));
    }

    setData(mNode, temp_data);
    Temp = mNode;
  }

  if(getRightSubTree(vRoot) != *root)
  {
    *root = getRightSubTree(vRoot);  
  }

  free(vRoot);
  return Temp;  
}
