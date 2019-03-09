/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *
 * solution https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/1659/discuss/137441/simple-C-solution(in-0-ms)
 */
#include <stdlib.h>
int** generate(int numRows, int** columnSizes) {
    int** returnArray = (int**)malloc(sizeof(int*)*numRows);
    *columnSizes = (int*)malloc(sizeof(int)*numRows);
    for(int i=0;i<numRows;i++){
        (*columnSizes)[i] = i+1;
        returnArray[i] = (int*)malloc(sizeof(int)*(i+1));
        returnArray[i][0] = 1;
        returnArray[i][i] = 1;
        for(int j=1;j<i;j++){
            returnArray[i][j] = returnArray[i-1][j] + returnArray[i-1][j-1];
        }
    }
    return returnArray;
}
