#pragma once

#include "Student.h"
#include "Staffer.h"
#include <queue>
#include <vector>

using namespace std;

int waitTime(queue<Student> currentQueue, vector<Staffer> onDutyStaff, int nthStudent);
