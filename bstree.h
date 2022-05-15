// bstree.h //
// binary search tree header define.

#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "tree.h"

//bstree make and initialization.
void Init(TREE** root);

//getData() using tree.h

TREE* Searching(TREE* root, TDATA target);

void Insert(TREE** root, TDATA data);

TREE* Remove(TREE** root, TDATA target);

#endif
