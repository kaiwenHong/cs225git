#pragma once

#include <algorithm>
#include <cmath>
#include <string>

class Staffer {
    public:
        Staffer(std::string favQuestion, int startingEnergy);

        int getEnergyLevel();

        int answerQuestion(std::string questionType, int anticipatedTime);

    private:
        int energyLevel;
        std::string favoriteType;
};
