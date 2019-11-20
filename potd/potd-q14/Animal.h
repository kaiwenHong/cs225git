#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <string>

using namespace std;

class Animal {
    private:
        string type_;
    protected:
        string food_;
    public:
        Animal();
        Animal(string type, string food);

        void setFood(string nu_food);
        string getFood();
        void setType(string nu_type);
        string getType();
        string print();
};
#endif
