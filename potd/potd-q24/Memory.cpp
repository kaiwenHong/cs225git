#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address) {
    Node* current = head;
    Node* temp = nullptr;
    while (current != NULL) {
        if (current->address == address) {
            // Your code there
            current->inUse = false;
            temp = current->next;
            while (temp != nullptr && temp->inUse == false) {
              current->next = temp->next;
              if(current->previous != nullptr) current->next->previous = current;
              delete temp;
              temp = current->next;
            }
            temp = current->previous;
            while (temp != nullptr && temp->inUse == false) {
              current->previous = temp->previous;
              current->address = temp->address;
              if(current->previous != nullptr) current->previous->next = current;
              else head = current;
              delete temp;
              temp = current->previous;
            }
            return true;
        }
        current = current->next;
    }
    return false;
}

/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.

Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment() {
    Node* current = head;
    while (current != NULL) {

        if (current->inUse) {
            // Do nothing
        } else {
            // TODO: Find the next chunk of allocated memory and shift it down to current's address
            // We recommend using the helper function `findNextAllocatedMemoryChunk
            // Your code here
            while (findNextAllocatedMemoryChunk(current)) {
              Node* nextUsed = findNextAllocatedMemoryChunk(current);
              size_t nextSize = getSize(nextUsed);
              current->next = nextUsed->next;
              if (current->previous != nullptr) current->previous->next = nextUsed;
              else head = nextUsed;
              current->previous = nextUsed;
              nextUsed->next = current;
              nextUsed->previous = current->previous;
              nextUsed->address = current->address;
              current->address = current->address + nextSize;
            }
        }

         current = current->next;
    }

    // TODO: Finally merge all of the free blocks of memory together
}
