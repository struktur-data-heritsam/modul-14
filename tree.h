//
//  tree.h
//  Modul14
//
//  Created by Ariq Heritsa on 17/06/22.
//

#ifndef tree_h
#define tree_h

#include <iostream>

using namespace std;

#define nil NULL
#define info(p) p->info
#define left(p) p->left
#define right(p) p->right

using namespace std;

typedef int infotype;
typedef struct node *address;

struct node {
  infotype info;
  address left, right;
};

address allocation(infotype X);

void insertBST(address &root, address n);

address findNode(address root, infotype X);

int countInternalNode(address root);

void printLeaves(address root);

int countLeaves(address root);

int maxNumber(address root);

void inOrder(address root);

void preOrder(address root);

void postOrder(address root);

#endif /* tree_h */
