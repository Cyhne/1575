/* Define all your MyList-related functions here, including the get_identity
    function
 * You do not need to include MyList.h in this hpp header file. It includes
    this file at the bottom.
 */


//  PRINT LIST FUNCTION
/*template <typename T>
void MyList<T>::printList()
{
    Node<T> *curr = m_sentinel->m_next;
    for(int i = 0; i < m_size; i++)
    {
       std::cout << curr->m_element << " ";
       curr = curr->m_next;
    }
    std::cout << endl;
    curr = m_sentinel->m_prev;
    for(int i = 0; i < m_size; i++)
    {
       std::cout << curr->m_element << " ";
       curr = curr->m_prev;
    }
    std::cout << endl;

 }
*/


void get_identity(string &my_id)
{
   my_id = "ryy5fm";
}

template <typename T>
MyList<T>::MyList()
{
   m_sentinel = new Node<T>(nullptr, nullptr);
   m_sentinel->m_next = m_sentinel;
   m_sentinel->m_prev = m_sentinel;

   m_size = 0;
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
   m_size = 0;
   m_sentinel = new Node<T>(nullptr, nullptr);
   m_sentinel->m_next = m_sentinel;
   m_sentinel->m_prev = m_sentinel;
   Node<T> *sourceNode = source.m_sentinel->m_next;
   while(m_size < source.m_size)
   {
      push_back(sourceNode->m_element);
      sourceNode = sourceNode->m_next;
   }

}

// Use the removeall function from the sample lecture code as your guide
template <typename T>
MyList<T>::~MyList()
{
   clear();
   delete m_sentinel;
}

template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
   clear();
   Node<T> *sourceNode = source.m_sentinel->m_next;
   for(m_size = 0; m_size<source.m_size;)
   {
      push_back(sourceNode->m_element);
      sourceNode = sourceNode->m_next;
   }
   return *this;
}

template <typename T>
T & MyList<T>::front()
{
   return m_sentinel->m_next->m_element;
}

template <typename T>
T & MyList<T>::back()
{
   return m_sentinel->m_prev->m_element;
}

// Assigns new contents (#count elements, each initialized to a copy of
//  value) to the list and replace its current contents
//  (size should be modified accordingly)
template <typename T>
void MyList<T>::assign(int count, const T &value)
{
   clear();
   for(m_size=0;m_size<count;)
      push_back(value);
}

// Default list size of 0, with one sentinel node as in the
//  default constructor
template <typename T>
void MyList<T>::clear()
{
   if(m_sentinel->m_next == m_sentinel->m_prev)
      return;

   while(m_sentinel->m_next != nullptr && m_sentinel->m_next != m_sentinel->m_prev)
   {
      pop_back();
   }
   pop_back();
}

template <typename T>
void MyList<T>::push_front(const T &x)
{
   Node<T> *head = m_sentinel->m_next;

   Node<T> *addNode = new Node<T>(x, m_sentinel, head);
   head->m_prev = addNode;
   m_sentinel->m_next = addNode;
   head = addNode;
   m_size++;
}

template <typename T>
void MyList<T>::push_back(const T &x)
{
   Node<T> *tail = m_sentinel->m_prev;

   Node<T> *addNode = new Node<T>(x, tail, m_sentinel);
   tail->m_next = addNode;
   m_sentinel->m_prev = addNode;
   tail = addNode;
   m_size++;
}

template <typename T>
void MyList<T>::pop_back()
{
   Node<T> *holder = m_sentinel->m_prev;
   m_sentinel->m_prev = m_sentinel->m_prev->m_prev;
   m_sentinel->m_prev->m_next = m_sentinel;
   delete holder;
   holder = nullptr;
   m_size--;
}

template <typename T>
void MyList<T>::pop_front()
{
   Node<T> *holder = m_sentinel->m_next;
   m_sentinel->m_next = m_sentinel->m_next->m_next;
   m_sentinel->m_next->m_prev = m_sentinel;
   delete holder;
   holder = nullptr;
   m_size--;
}

// Simplified version (not exactly like std::list.insert) that inserts x
//  before element at position i.
// Note: You should be able to insert in an empty list
template <typename T>
void MyList<T>::insert(int i, const T &x)
{
   Node<T> *curr = m_sentinel->m_next;

   for(int j=0;j<i;j++)
   {
      curr = curr->m_next;
   }

   Node<T> *addNode = new Node<T>(x, curr->m_prev, curr);
   curr->m_prev->m_next = addNode;
   curr->m_prev = addNode;

   m_size++;
}

// Removes all elements in list that are equal to value
template <typename T>
void MyList<T>::remove(T value)
{
   int holder = m_size;
   Node<T> *curr;
   Node<T> *shifter = m_sentinel->m_next;
   for(int i = 0; i<holder; i++)
   {
      curr = shifter;
      if(curr->m_element == value)
      {
         curr->m_prev->m_next = curr->m_next;
         curr->m_next->m_prev = curr->m_prev;
         delete curr;
         m_size--;
      }
      shifter = shifter->m_next;
   }

}

// Removes element at position i
template <typename T>
void MyList<T>::erase(int i)
{
   Node<T> *curr = m_sentinel->m_next;
   for(int j = 0; j<i; j++)
      curr = curr->m_next;
   curr->m_prev->m_next = curr->m_next;
   curr->m_next->m_prev = curr->m_prev;
   delete curr;
   m_size--;
}

// Reverses the order of the elements in the list
template <typename T>
void MyList<T>::reverse()
{
   T holder;
   Node<T>*frontIterator = m_sentinel->m_next;
   Node<T>*backIterator = m_sentinel->m_prev;
   for(int i = 0; i < m_size/2; i++)
   {
      holder = backIterator->m_element;
      backIterator->m_element = frontIterator->m_element;
      backIterator = backIterator->m_prev;
      frontIterator->m_element = holder;
      frontIterator = frontIterator->m_next;
   }
}

template <typename T>
bool MyList<T>::empty()
{
   if(m_sentinel->m_next == m_sentinel->m_prev)
      return true;
   else
      return false;
}

template <typename T>
int MyList<T>::size()
{
   return m_size;
}
