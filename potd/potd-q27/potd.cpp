#include "potd.h"

using namespace std;

string getFortune(const string &s) {

  int fortuneIndex = s.length() % 5;

  if (fortuneIndex == 0) return "A dream you have will come true.";
  if (fortuneIndex == 1) return "You will become great if you believe in yourself.";
  if (fortuneIndex == 2) return "You must try, or hate yourself for not trying.";
  if (fortuneIndex == 3) return "The greatest risk is not taking one.";
  return "Wealth awaits you very soon.";

}
