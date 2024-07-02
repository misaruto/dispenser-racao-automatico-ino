#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <typename T>
class LinkedListNode
{
private:
  T item;
  LinkedListNode<T> *next;

public:
  LinkedListNode();
  LinkedListNode(const LinkedListNode<T> &orig);

  void setNextNode(LinkedListNode<T> *prox);
  LinkedListNode<T> *getNextNode() const;
  void setItem(T item);
  T getItem() const;

  // virtual ~LinkedListNode();
};

template <typename T>
LinkedListNode<T>::LinkedListNode()
{
  this->next = nullptr;
}
template <typename T>
LinkedListNode<T>::LinkedListNode(const LinkedListNode<T> &orig)
{
  this->item = orig.getItem();
  this->next = orig.getNextNode();
}

template <typename T>
T LinkedListNode<T>::getItem() const
{
  return this->item;
}

template <typename T>
void LinkedListNode<T>::setNextNode(LinkedListNode<T> *prox)
{
  this->next = prox;
}

template <typename T>
LinkedListNode<T> *LinkedListNode<T>::getNextNode() const
{
  return this->next;
}

template <typename T>
void LinkedListNode<T>::setItem(T item)
{
  this->item = item;
}

#endif