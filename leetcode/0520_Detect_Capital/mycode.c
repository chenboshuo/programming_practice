#include <stdbool.h>
bool detectCapitalUse(char *word) {
  while (*word) {
    if (*word < 'A' || *word > 'Z') { return false; }
    ++word;
  }
  return true;
}
