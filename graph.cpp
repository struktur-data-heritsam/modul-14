//
//  graph.cpp
//  Modul14
//
//  Created by Ariq Heritsa on 17/06/22.
//

#include "graph.h"

// 1305213031 - Ariq Heritsa Maalik
void createNode(char x, adrNode &P) {
  P = new Node;

  P->idNode = x;
  P->firstEdge = nil;
  P->nextNode = nil;
  P->firstEdge = nil;
}

// 1305213031 - Ariq Heritsa Maalik
void createEdge(char id, int jarak, adrEdge &e) {
  e = new Edge;

  e->id = id;
  e->jarak = jarak;
  e->nextEdge = nil;
}

// 1305213031 - Ariq Heritsa Maalik
void createGraph(Graph &G) {
  G.first = nil;
}

// 1305213031 - Ariq Heritsa Maalik
void showPeta(Graph G) {
  adrNode currentNode;
  adrEdge currentEdge;

  currentNode = G.first;

  if (currentNode != nil) {
    while (currentNode != nil) {
      currentEdge = currentNode->firstEdge;

      while (currentEdge != nil) {
        cout << currentNode->idNode << " ke " << currentEdge->id << ": " << currentEdge->jarak << endl;
        currentEdge = currentEdge->nextEdge;
      }

      currentNode = currentNode->nextNode;
    }
  } else {
    cout << "Graph kosong!" << endl;
  }
}

// 1305213031 - Ariq Heritsa Maalik
void insertNewNode(Graph &G, char idNode) {
  adrNode newNode, currentNode;

  createNode(idNode, newNode);

  if (G.first == nil) {
    // graph kosong
    G.first = newNode;
  } else {
    // graph tidak kosong
    currentNode = G.first;

    while (currentNode->nextNode != nil) {
      currentNode = currentNode->nextNode;
    }

    currentNode->nextNode = newNode;
  }
}

// 1305213031 - Ariq Heritsa Maalik
adrNode findNode(Graph G, char idNode) {
  adrNode current = G.first;

  while (current != nil) {
    if (current->idNode == idNode) {
      return current;
    }

    current = current->nextNode;
  }

  return nil;
}

// 1305213031 - Ariq Heritsa Maalik
void connecting(Graph &G, char node1, char node2, int jarak) {
  // cari simpul
  adrNode currentVertex = findNode(G, node1);

  // buat edge baru
  adrEdge newEdge;
  createEdge(node2, jarak, newEdge);

  if (currentVertex != nil) {
    if (currentVertex->firstEdge == nil) {
      // edge masih kosong
      currentVertex->firstEdge = newEdge;
    } else {
      // edge tidak kosong
      adrEdge currentEdge = currentVertex->firstEdge;

      while (currentEdge->nextEdge != nil) {
        currentEdge = currentEdge->nextEdge;
      }

      currentEdge->nextEdge = newEdge;
    }
  }
}

// 1305213031 - Ariq Heritsa Maalik
int biayaPerbaikanJalan(Graph G) {
  adrNode currentVertex = G.first;
  int total = 0;

  while (currentVertex != nil) {
    adrEdge currentEdge = currentVertex->firstEdge;

    while (currentEdge != nil) {
      total += currentEdge->jarak * 1000;
      currentEdge = currentEdge->nextEdge;
    }

    currentVertex = currentVertex->nextNode;
  }

  return total;
}

// 1305213031 - Ariq Heritsa Maalik
void printNode(Graph G) {
  adrNode currentNode;

  currentNode = G.first;

  if (currentNode != nil) {
    while (currentNode != nil) {
      cout << currentNode->idNode << " ";

      currentNode = currentNode->nextNode;
    }

    cout << endl;
  } else {
    cout << "Graph kosong!" << endl;
  }
}

