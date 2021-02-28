
#pragma once
#include <stdio.h>

#include <vector>
#include <set>

class Graph;

class Node {
   friend class Graph;
   int id;
   Node *next;

public:
   Node(int _id, Node *_next) { id = _id; next = _next; }
};


class Graph {
   // array of start nodes and length of this array
   Node **start;
   int nStartNodes;
public:

   Graph() { nStartNodes = 0; start = nullptr; }
   ~Graph();

   // Initializtion for tests
   int LoadForTest1();
   int LoadForTest2();
   int LoadForTest3();
   int LoadForTest4();
   int LoadForTest5();

   // Attention!
   // Print function does not work for graphs with loops !!!
   // It falls into infinite cycle.
   // You sould correct it for using with such graphs !!!
   void Print(FILE *f, const char *text);
   std::set<int> startIds();

   std::vector<std::vector<int>> getUnorientedMatrix();//Returns adjacendy matrix
};
