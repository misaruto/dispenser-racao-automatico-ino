#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedListNode.h"

template <typename T>
class LinkedList
{
private:
  int len;
  LinkedListNode<T> *head;
  LinkedListNode<T> *tail;

public:
  LinkedList();

  void insert(T item);
  void remove(int position);
  // void forEach(void *function);
  LinkedListNode<T> *getHead();
  LinkedListNode<T> *find(T value);
  // LinkedListNode<T> *getItemByPosition(int position);

  int length();
  bool isEmpty();
  // virtual ~LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList()
{
  this->len = 0;
  this->head = nullptr;
};
template <typename T>
void LinkedList<T>::insert(T item)
{
  LinkedListNode<T> *novo = new LinkedListNode<T>();
  novo->setItem(item);
  novo->setNextNode(this->head);

  if (this->head == nullptr)
  {
    this->head->setNextNode(novo);
    this->head = novo;
  }
  else
  {
    this->head = novo;
    this->tail = novo;
  }

  this->len++;
}
template <typename T>
void LinkedList<T>::remove(int position)
{

  // cria um apontador para o nó anterior, pois contem o apontador para o que se quer apagar
  LinkedListNode<T> *anterior = getElemento(position);
  // cria um apontador para o que se quer apagar, pois ele contem o apontador para o proximo
  LinkedListNode<T> *atual = getElemento(position + 1);
  // o anterior passa a apontar para o proximo do que se quer apagar
  anterior->setNextNode(atual->getNextNode());
  this->len--;
};
template <typename T>
LinkedListNode<T> LinkedList<T>::*find(T value) {

};

// template <typename T>
// void LinkedList<T>::forEach(void *function)
// {
//   LinkedListNode<T> *node = this->head;
//   while (node->getNextNode() != nullptr)
//   {
//     function(node->getItem());
//     node = node->getNextNode();
//   }
// }
// template <typename T> LinkedListNode<T>
//     LinkedList<T>::*getItemByPosition(int position)
// {
//   LinkedListNode<T> node = this->head;
//   int index = 1;
//   while (index <= position - 1)
//   {
//     LinkedListNode<T> *next = node->getNextNode();
//     if (next == nullptr)
//     {
//       index = position;
//     }

//     node = next;
//     index++;
//   }
//   if (index == position)
//   {
//     return node;
//   }
//   return nullptr;
// };

template <typename T>
LinkedListNode<T> *LinkedList<T>::getHead()
{
  return this->head;
};
template <typename T>
int LinkedList<T>::length()
{
  return this->len;
};

template <typename T>
bool LinkedList<T>::isEmpty()
{
  return this->len == 0;
}
#endif