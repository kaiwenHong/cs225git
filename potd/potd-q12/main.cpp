#include <iostream>
using namespace std;

#include "Animal.h"

int main() {
  Animal a;
  cout<<"Default constructor:"<<endl;
  cout<<"  Type: "<<a.getType()<<", Food: "<<a.getFood()<<endl;
  cout << a.print() << endl;
  cout<<endl;

  Animal b("horse", "hay");
  cout<<"Two parameter constructor:"<<endl;
  cout<<"  Type: "<<b.getType()<<", Food: "<<b.getFood()<<endl;
  cout << b.print() << endl;
  cout<<endl;

  b.setType("snake");
  b.setFood("mouse");
  cout<<"After using setters:"<<endl;
  cout<<"  Type: "<<b.getType()<<", Food: "<<b.getFood()<<endl;
  cout << b.print() << endl;
  cout<<endl;

  return 0;
}
