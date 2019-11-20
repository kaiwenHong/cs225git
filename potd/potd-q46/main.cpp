#include <iostream>
#include <vector>
#include "Heap.h"

std::vector<int> data = {-65536, 12, 7, 8, 13, 4, -1, 6, 5, 10, 3 ,1, 15};

int main() {
    Heap h;

    for(std::vector<int>::iterator it = data.begin();
            it != data.end();
            it++)
        h.enQueue(*it);
        
	h.printQueue();

	while(h.size() != 1){
        std::cout << h.deQueue() << " Pop from Priority Queue" << std::endl;
	}
	return 0;	
}
