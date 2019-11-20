/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */


/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(nullptr);
}

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <typename T>
List<T>::~List() {
  /// @todo Graded in MP3.1
  _destroy();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode *curr = head_;
  while(curr != nullptr) {
    ListNode *prev;
    prev = curr;
    curr = curr->next;
    delete prev;
  }
  tail_ = nullptr;
  length_ = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode *curr = new ListNode(ndata);
  if(head_ == nullptr) {
    curr->prev = nullptr;
    curr->next = nullptr;
    head_ = curr;
    tail_ = curr;
  } else {
    curr->prev = nullptr;
    curr->next = head_;
    head_->prev = curr;
    head_ = curr;
  }
  length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode *curr = new ListNode(ndata);
  if(tail_ == nullptr) {
    curr->prev = nullptr;
    curr->next = nullptr;
    head_ = curr;
    tail_ = curr;
  } else {
    curr->next = nullptr;
    curr->prev = tail_;
    tail_->next = curr;
    tail_ = curr;
  }
  length_++;
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.1
  if(head_ == nullptr || tail_ == nullptr) return;
  if(startPoint == endPoint) return;

  //Retain a copy of original pointers.
  ListNode *temp = nullptr;
  ListNode *curr = startPoint;
  ListNode *original_start = startPoint;
  ListNode *original_start_prev = startPoint->prev;
  ListNode *original_end = endPoint;
  ListNode *original_end_next = endPoint->next;

  //Swap next and prev for all nodes between start and end.
  while(curr != endPoint) {
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }

  //Connect swapped nodes to other nodes.
  temp = curr->prev;
  curr->prev = original_start_prev;
  curr->next = temp;
  endPoint = original_start;
  endPoint->next = original_end_next;

  //Identify if swap occurs in between.
  if(original_start_prev == nullptr){
    head_ = curr;
  } else {
    original_start_prev->next = original_end;
  }
  if(original_end_next == nullptr) {
    tail_ = endPoint;
  } else {
    original_end_next->prev = original_start;
  }

}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
  if(length_ == 0 || length_ == 1) return;
  ListNode *startPoint = head_;
  ListNode *endPoint = head_;

  while(endPoint != nullptr){
    for(int i = 0; i < n - 1; i++) {
      if(endPoint->next == nullptr){
        reverse(startPoint, endPoint);
        return;
      }
      endPoint = endPoint->next;
    }
    reverse(startPoint, endPoint);
    if(endPoint->next == nullptr) return;
    else {
      startPoint = endPoint->next;
      endPoint = startPoint;
    }
  }

}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  if (length_ == 0 || length_ == 1) return;
  ListNode *curr = head_->next;
  ListNode *temp = nullptr;
  while (true) {
    if (curr->next != nullptr) {
      temp = curr->next->next;
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      curr->prev = tail_;
      curr->next = nullptr;
      tail_->next = curr;
      tail_ = curr;
      curr = temp;
    }
    if (curr == nullptr) break;
  }
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <typename T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_ -> next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.2
  ListNode *curr = start;
//  ListNode *head = start;
  for(int i = 0; i < splitPoint; i++) {
    if(curr->next == nullptr) return curr;
    curr = curr->next;
  }

  curr->prev->next = nullptr;
  curr->prev = nullptr;

  return curr;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if (first == nullptr) return second;
  if (second == nullptr) return first;
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  if (first->data < second->data) {
      head = first;
      tail = first;
      first = first->next;
  } else {
      head = second;
      tail = second;
      second = second->next;
  }
  while (first != nullptr && second != nullptr) {
      if (first->data < second->data) {
          tail->next = first;
          tail = first;
          first = first->next;
      } else {
          tail->next = second;
          tail = second;
          second = second->next;
      }
  }
  if (first != nullptr) tail->next = first;
  else tail->next = second;
  return head;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <typename T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if(chainLength == 0 || chainLength == 1) return start;
  ListNode * left_half = start;
  ListNode * right_half = split(start, chainLength / 2);
  left_half = mergesort(left_half, chainLength / 2);
  right_half = mergesort(right_half, chainLength -  chainLength / 2);
  return merge(left_half, right_half);
}
