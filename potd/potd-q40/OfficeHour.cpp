#include <iostream>
#include "OfficeHour.h"

using namespace std;
/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!

    //No Staff On duty
    if (!onDutyStaff.size()) return -1;

    vector<bool> available;
//    for (Staffer b : onDutyStaff) available[b] = true;

    //Remove staffs that are tired.
    for (size_t i = 0; i < onDutyStaff.size(); i++) {
      if (onDutyStaff[i].getEnergyLevel() == 0) {
        onDutyStaff.erase(onDutyStaff.begin() + i);
      }
    }

    if (nthStudent == 0) return 0;

    int time = 0;
    for (int i = 1; i < nthStudent; i++) {
      Student firstInLine = queue.front();
      if (onDutyStaff[i % onDutyStaff.size()].answerQuestion(firstInLine.getQuestionType(), firstInLine.getTimeNeeded()) == 112358) {
        onDutyStaff.erase(onDutyStaff.begin() + i % onDutyStaff.size());
      }
      if (!onDutyStaff.size()) return -1;
      time += onDutyStaff[i % onDutyStaff.size()].answerQuestion(firstInLine.getQuestionType(), firstInLine.getTimeNeeded());
      queue.pop();
    }

    return time;
}
