#ifndef _HEAP_H
#define _HEAP_H

#include <vector>

class Heap {
    private:
        std::vector<int> _data;
        void _percolateDown(int hole);

    public:
        int size() const;
        void enQueue(const int &x);
        int deQueue();
        void printQueue();
        std::vector<int> & getData();
};

#endif
