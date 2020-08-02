#include <stdbool.h>

bool detectCapitalUse(char *word) {
  if (*word == '\0' || *(word + 1) == '\0') { return true; }
  bool first = (*word >= 'A' && *word <= 'Z');
  ++word;
  bool pre = (*word >= 'A' && *word <= 'Z');
  ++word;
  if (pre > first) { return false; }

  while (*word) {
    bool cur = (*word >= 'A' && *word <= 'Z');
    if (cur > first || cur != pre) { return false; }
    ++word;
  }
  return true;
}
