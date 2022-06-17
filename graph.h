//
//  graph.h
//  Modul14
//
//  Created by Ariq Heritsa on 17/06/22.
//

#ifndef graph_h
#define graph_h

#include <iostream>

using namespace std;

#define nil NULL

typedef struct Node *adrNode;
typedef struct Edge *adrEdge;

struct Node {
  char idNode;
  adrNode nextNode;
  adrEdge firstEdge;
};

struct Edge {
  char id;
  int jarak;
  adrEdge nextEdge;
};

struct Graph {
  adrNode first;
};

// procedure createNode(input X char, output P : adrNode)
void createNode(char x, adrNode &P);

// procedure createGraph(output G:Graph)
void createGraph(Graph &G);

// Procedure showPeta (G : graph)
void showPeta(Graph G);

// Procedure InsertNewNode (Input/Output G : Graph, Input idNode : char)
void insertNewNode(Graph &G, char idNode);

// Function FindNode(G: Graph, id_Node : char) -> adrNode
adrNode findNode(Graph G, char idNode);

// Procedure Connecting (Input/Output G : Graph, Input Node1, Node2: char, jarak: integer)
void connecting(Graph &G, char node1, char node2, int jarak);

// Function biayaPerbaikanJalan (G : Graph): integer
int biayaPerbaikanJalan(Graph G);

void createEdge(char id, int jarak, adrEdge &e);

void printNode(Graph G);

#endif /* graph_h */
