
#pragma once

template<class T> 
class Stack {
   struct Node { 
      T x; 
      Node *next; 
      Node (const T&_x, Node *n ) { x = _x; next = n; } 
   };
   Node * top;
public:
   Stack() { top = nullptr; }
   bool Empty() { return top == nullptr; }
   void Push(const T &_x)  { top = new Node(_x,top); }
   bool DelTop() {
      if (top) {
         Node * p = top;
         top = top->next;
         delete p;
         return true;
      } else {
         return false;
      }
   }
   bool Pop (T &_x) { 
      if (top) {
          _x = top->x;
      }
      return DelTop();
   }
   bool Contains (const T &_x) {
      for (Node *p = top; p; p=p->next) if (_x == p->x) return true;
      return false;
   }
};
