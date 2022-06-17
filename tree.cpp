//
//  tree.cpp
//  Modul14
//
//  Created by Ariq Heritsa on 17/06/22.
//

#include "tree.h"

// 1305213031 - Ariq Heritsa Maalik
address allocation(infotype X) {
  address n = new node;

  info(n) = X;
  left(n) = nil;
  right(n) = nil;

  return n;
}

// 1305213031 - Ariq Heritsa Maalik
void insertBST(address &root, address n) {
  if (root == nil) {
    // tree kosong
    root = n;
  } else {
    // n lebih kecil dari root
    if (info(n) < info(root)) {
      if (left(root) == nil) {
        left(root) = n;
      } else {
        insertBST(left(root), n);
      }

    // n lebih besar dari root
    } else if (info(n) > info(root)) {
      if (right(root) == nil) {
        right(root) = n;
      } else {
        insertBST(right(root), n);
      }
    }
  }
}

// 1305213031 - Ariq Heritsa Maalik
address findNode(address root, infotype X) {
  if (root != nil) {
    if (info(root) == X) {
      return root;
    } else {
      if (X < info(root)) {
        return findNode(left(root), X);
      } else {
        return findNode(right(root), X);
      }
    }
  } else {
    return nil;
  }
}

// 1305213031 - Ariq Heritsa Maalik
int countInternalNode(address root) {
  if (root == nil || (left(root) == nil && right(root) == nil)) {
    return 0;
  }

  return 1 + countInternalNode(left(root)) + countInternalNode(right(root));
}

// 1305213031 - Ariq Heritsa Maalik
void printLeaves(address root) {
  if (root != nil) {
    printLeaves(left(root));

    if (left(root) == nil && right(root) == nil) {
      cout << info(root) << " -> ";
    }

    printLeaves(right(root));
  }
}

// 1305213031 - Ariq Heritsa Maalik
int countLeaves(address root) {
  if (root != nil) {
    if (left(root) == nil && right(root) == nil) {
      return 1;
    } else {
      return countLeaves(left(root)) + countLeaves(right(root));
    }
  }

  return 0;
}

// 1305213031 - Ariq Heritsa Maalik
int maxNumber(address root) {
  if (right(root) == nil) {
    return info(root);
  }

  return maxNumber(right(root));
}

// 1305213031 - Ariq Heritsa Maalik
void inOrder(address root) {
  if (root != nil) {
    cout << info(root) << " -> ";
    preOrder(left(root));
    preOrder(right(root));
  }
}

// 1305213031 - Ariq Heritsa Maalik
void preOrder(address root) {
  if (root != nil) {
    cout << info(root) << " -> ";
    preOrder(left(root));
    preOrder(right(root));
  }
}

// 1305213031 - Ariq Heritsa Maalik
void postOrder(address root) {
  if (root != nil) {
    postOrder(left(root));
    postOrder(right(root));
    cout << info(root) << " -> ";
  }
}
