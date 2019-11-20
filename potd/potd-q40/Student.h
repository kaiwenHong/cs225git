#pragma once

#include <string>

class Student {
    public:
        Student(int anticipatedTimeNeeded, std::string questionType);
        int getTimeNeeded();
        std::string getQuestionType();

    private:
        int anticipatedTime;
        std::string qType;
};
