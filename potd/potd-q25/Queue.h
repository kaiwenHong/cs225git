#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>
#include <queue>

class Queue {
    public:
        Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
    private:
        std::queue<int> myqueue;
};

#endif
