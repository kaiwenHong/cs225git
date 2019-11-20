#include <iostream>
using namespace std;

#include "Queue.h"

int main() {
  Queue q;
  int r;

  cout<<"enqueue(3) to the queue..."<<endl;
  q.enqueue(3);
  cout<<"Queue size: "<<q.size()<<endl;

  cout<<"enqueue(2) to the queue..."<<endl;
  q.enqueue(2);
  cout<<"Queue size: "<<q.size()<<endl;

  cout<<"enqueue(1) to the queue..."<<endl;
  q.enqueue(1);
  cout<<"Queue size: "<<q.size()<<endl;


  cout<<"dequeue()"<<endl;
  r = q.dequeue();
  cout<<"Returned Value: "<<r<<", Queue size: "<<q.size()<<endl;

  cout<<"dequeue()"<<endl;
  r = q.dequeue();
  cout<<"Returned Value: "<<r<<", Queue size: "<<q.size()<<endl;

  cout<<"dequeue()"<<endl;
  r = q.dequeue();
  cout<<"Returned Value: "<<r<<", Queue size: "<<q.size()<<endl;

  return 0;
}
