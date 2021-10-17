#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* next;
};

class LinkList
{
public:
  LinkList();
  ~LinkList();
  void insert(int data);
  void display();
  void delete_node(int data);
  void delete_list();
  void reverse();
  void sort();
  void merge(LinkList* list2);
private:
  Node* head;
};

LinkList::LinkList()
{
  head = NULL;
}

LinkList::~LinkList()
{
  delete_list();
}

void LinkList::insert(int data)
{
  Node* new_node = new Node;
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void LinkList::display()
{
  Node* temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void LinkList::delete_node(int data)
{
  Node* temp = head;
  Node* prev = head;
  while (temp != NULL)
  {
    if (temp->data == data)
    {
      if (temp == head)
      {
        head = head->next;
      }
      else
      {
        prev->next = temp->next;
      }
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
}

void LinkList::delete_list()
{
  Node* temp = head;
  Node* prev = head;
  while (temp != NULL)
  {
    prev = temp;
    temp = temp->next;
    delete prev;
  }
}

void LinkList::reverse()
{
  Node* temp = head;
  Node* prev = NULL;
  while (temp != NULL)
  {
    Node* next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  head = prev;
}

void LinkList::sort()
{
  Node* temp = head;
}

void LinkList::merge(LinkList* list2)
{
  Node* temp1 = head;
  Node* temp2 = list2->head;
  while (temp1 != NULL && temp2 != NULL)
  {
    if (temp1->data < temp2->data)
    {
      temp1 = temp1->next;
    }
    else
    {
      Node* temp3 = temp2->next;
      list2->delete_node(temp2->data);
      list2->insert(temp2->data);
      temp2 = temp3;
    }
  }
}

int main()
{
  LinkList list1, list2;
  list1.insert(10);
  list1.insert(20);
  list1.insert(30);
  list1.insert(40);
  list1.insert(50);
  list1.insert(60);
  list1.insert(70);
  list1.insert(80);
  list1.insert(90);
  list1.insert(100);
  list1.insert(110);
  list1.insert(120);


  list2.insert(1);
  list2.insert(2);
  list2.insert(3);
  list2.insert(4);

  list1.merge(&list2);
  list1.display();
  list2.display();
  return 0;
}

