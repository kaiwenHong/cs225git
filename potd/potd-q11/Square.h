#ifndef _SQUARE_H
#define _SQUARE_H

#include <string>

using namespace std;

class Square {
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
        Square & operator=(const Square & other);
        Square operator+(const Square & other);
};

#endif
