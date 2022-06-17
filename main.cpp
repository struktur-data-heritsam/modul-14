//
//  main.cpp
//  Modul14
//
//  Created by Ariq Heritsa on 17/06/22.
//

#include <iostream>
#include "graph.h"
#include "tree.h"

using namespace std;

int main() {
  /**
   * Graph
   */
  cout << "A. GRAPH" << endl;
  Graph G;
  
  // inisialisasi graph G
  createGraph(G);
  
  // menambahkan node A, B, C, D ke dalam graph
  cout << "Membuat node pada graf" << endl;
  insertNewNode(G, 'A');
  insertNewNode(G, 'B');
  insertNewNode(G, 'C');
  insertNewNode(G, 'D');
  
  // menampilkan seluruh data node pada graph
  printNode(G);
  
  // hubungkan A ke C dengan jarak 5 km,
  // A ke D dengan jarak 10 km,
  // B ke D dengan jarak 7km, dan
  // D ke C dengan jarak 2 km
  cout << "Membuat edge pada graf" << endl;
  connecting(G, 'A', 'C', 5);
  connecting(G, 'A', 'D', 10);
  connecting(G, 'B', 'D', 7);
  connecting(G, 'D', 'C', 2);
  
  // menampilkan seluruh data node pada graph
  showPeta(G);
  
  // hitung biaya perbaikan jalan dari total seluruh jalur yang ada
  int biaya = biayaPerbaikanJalan(G);
  cout << "Biaya perbaikan jalan keseluruhan: Rp" << biaya  << "*1000000" << endl;
  
  cout << endl;
  
  /**
   * Tree
   */
  cout << "B. TREE" << endl;
  address P, root;
  infotype searchNode;
  
  // inisialisasi tree
  root = nil;
  
  // menambahkan node pada tree
  int n[9] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
  
  for (int i = 0; i < 9; i++) {
    P = allocation(n[i]);
    insertBST(root, P);
  }
  
  cout << "inorder: ";
  inOrder(root);
  cout << endl;
  
  cout << "preorder: ";
  preOrder(root);
  cout << endl;
  
  cout << "postorder: ";
  postOrder(root);
  cout << endl;
  
  cout << "Internal node: " << countInternalNode(root) << endl;
  cout << "Leaves: ";
  printLeaves(root);
  cout << endl;
  cout << "Count leaves: " << countLeaves(root) << endl;
  cout << "Largest Number: " << maxNumber(root) << endl;
  
  cout << "Enter the node to search: ";
  cin >> searchNode;
  
  P = findNode(root, searchNode);
  
  if (P != nil) {
    cout << "Node found!" << endl;
  } else {
    cout << "Node not found!" << endl;
  }
  
  return 0;
}
