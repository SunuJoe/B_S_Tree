// main1.c

#include <stdio.h>
#include "bstree.h"

void show(int data)
{
  printf("%d\n", data);
}

int main(int argc, char* argv[])
{
  TREE* bsroot;

  Init(&bsroot);

  Insert(&bsroot, 50);
  Insert(&bsroot, 25);
  Insert(&bsroot, 70);
  Insert(&bsroot, 15);
  Insert(&bsroot, 35);
  Insert(&bsroot, 62);
  Insert(&bsroot, 100);
  Insert(&bsroot, 27);
  Insert(&bsroot, 30);
  Insert(&bsroot, 55);
  Insert(&bsroot, 69);
  Insert(&bsroot, 85);
  Insert(&bsroot, 117);
  Insert(&bsroot, 59);
  Insert(&bsroot, 82);
  Insert(&bsroot, 90);


  TREE* temp;

  temp = Remove(&bsroot, 62);
  
  printf("remove node data %d\n", temp->data);
  
  temp = Remove(&bsroot, 50);
  printf("remove node data %d\n", temp->data);
  int a;

  postTraversal(bsroot, show); 

  return 0;
}
