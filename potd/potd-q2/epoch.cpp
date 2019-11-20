#include "epoch.h"

int hours(long time_t) {
    return time_t / 3600;
}

int days(long time_t) {
    return time_t / 86400;
}

int years(long time_t) {
    return time_t / 31556926;
}