#include "hash_list.h"
hash_list::hash_list() 
{
  head = NULL;
  size = 0;
}

hash_list::hash_list(const hash_list &other)
{
  head = NULL;
  struct node* present = NULL;
  struct node* secHead = other.head;
  
  if (secHead) present = new node;
  while(secHead)
  {

    present -> next = NULL;
    present -> key = secHead -> key;
    present -> value = secHead -> value;

    if (secHead == other.head)
    {

     head = present;

    }

    secHead = secHead -> next;

    if (secHead)
    {

        present -> next = new node;

    }

    present = present -> next;

  }

  size = other.get_size();
}

hash_list &hash_list::operator=(const hash_list &other)
{
  if (&other == this)
  {

    return *this;

  }
  struct node* current = head;
  hash_list ans = hash_list(other);
  head = ans.head;
  size = ans.size;
  ans.head = current;
  return *this;
}

void hash_list::insert(int key, float value) 
{
  struct node* var = new node;
  struct node* current = head;
  while (current)
  {
    if (current -> key == key)
    {

      current -> value = value;
      delete var;
      return;

    }

    current = current -> next;

  }
  var -> value = value;
  var -> key = key;
  var -> next = head;
  head = var;
  size++;

}

std::optional<float> hash_list::get_value(int key) const 
{
  struct node* current = head;
  while (current)
  {
    if (current -> key == key)
    {
        return current -> value;
    }

    current = current -> next;

  }
  
  return {};
}

bool hash_list::remove(int key) 
{
  struct node* current = head;
  struct node* before = NULL;
  while (current)
  {
    if (current -> key == key)
    {
      if (before)
      {
        before -> next = current -> next;
        delete current;
        size--;
      }
      else
      {
        head = current -> next;
        delete current;
        size--;
      }
      return 1;
    }
    before = current;
    current = current -> next;
  }
  return 0;
}

size_t hash_list::get_size() const 
{
  return size;
}

hash_list::~hash_list() 
{
  struct node* current = head;
  while (current)
  {
    head = current;
    current = current -> next;
    delete head;
  }
}

/** Dont modify this function for this lab. Leave it as is */
void hash_list::reset_iter() {}

/** Dont modify this function for this lab. Leave it as is */
void hash_list::increment_iter() {}

/** Dont modify this function for this lab. Leave it as is */
std::optional<std::pair<int *, float *>> hash_list::get_iter_value() {}

/** Dont modify this function for this lab. Leave it as is */
bool hash_list::iter_at_end() {}
