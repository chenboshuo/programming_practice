#include <stdbool.h>

bool isRobotBounded(char *instructions) {
  int x_move[4] = { 0, -1, 0, 1 };
  int y_move[4] = { 1, 0, -1, 0 };
  int loc[2] = { 0, 0 };
  enum direction { NORTH, WEST, SOUTH, EAST };
  enum direction direction = NORTH;

  for (; *instructions; ++instructions) {
    switch (*instructions) {
      case 'L':
        ++direction;
        direction %= 4;
        break;
      case 'R':
        --direction;
        direction %= 4;
        break;
      default:
        loc[0] += x_move[direction];
        loc[1] += y_move[direction];
        break;
    }
  }

  return (loc[0] == 0 && loc[1] == 0) ||
         (loc[0] > 0 && loc[1] == 0 && direction != EAST) ||
         (loc[0] < 0 && loc[1] == 0 && direction != WEST) ||
         (loc[0] == 0 && loc[1] > 0 && direction != NORTH) ||
         (loc[0] == 0 && loc[1] < 0 && direction != SOUTH);
}

// Input:
// "LLGRL"
// Output:
// false
// Expected:
// true
