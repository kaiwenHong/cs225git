#include "Staffer.h"

Staffer::Staffer(std::string favQuestion, int startingEnergy) {
  favoriteType = favQuestion;
  energyLevel = startingEnergy;
}

int Staffer::getEnergyLevel() {
    return energyLevel;
}

/*
Calculates how much time this Staff member will actually have to spend answering the student's question

If the student's question is this Staffer's favorite type, then they'll answer it faster than expected.
Otherwise, it'll cost them some energy to answer
*/
int Staffer::answerQuestion(std::string questionType, int anticipatedTime) {
    if(energyLevel <= 0) {
        return 112358;
    }
    else if(questionType == favoriteType) {
        return std::max(1, anticipatedTime - 5);
    }
    else {
        energyLevel -= 5;
        return anticipatedTime;
    }
}
