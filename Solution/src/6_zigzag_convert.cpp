#include "../include/solution.h"

#define DEBUG 0
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

/*
    1. zigzag is scanned vertically and then diagonally
    2. e.g. A     G     M
            B   F H   L N
            C E   I K   O
            D     J     P
            ^^^^^^
            1 set occupies (assume n=rows)  n-2+1 columns and contains n+n-2=2n-2 numbers
 */

string Solution::convert(string s, int numRows) {
    string result;

    if (numRows <= 1) return s;
    const int verticalLineCount = 1;
    const int largestIndexInVerticalLine = numRows - 1;
    const int setNumbers = 2 * numRows - 2;
    const int setCols = numRows - 2 + 1;

    // 1. calculate needed cols
    int neededSetCols = s.length() / setNumbers * setCols;
    int residueCols = (0 == s.length() % setNumbers)? 0 : verticalLineCount;
    if (s.length() % setNumbers > largestIndexInVerticalLine)
        residueCols += s.length() - 1 - largestIndexInVerticalLine;
    int cols = neededSetCols + residueCols;
    debug_print("needed cols: %d\n", cols);

    // 2. allocate resource
    char **rowString = (char **)malloc(sizeof(char *)*numRows);
    for (size_t i=0; i< numRows; i++){
        rowString[i] = (char *)malloc(sizeof(char)*cols);
        memset(rowString[i], 0, sizeof(char)*cols);
    }

    // 3. fill data
    for (size_t i=0; i< s.length(); i++){
        int setCol = i / setNumbers * setCols;
        int residueCol = i - (i / setNumbers * setNumbers);
        if(residueCol < largestIndexInVerticalLine){
            residueCol = 0;
        }else{
            residueCol = residueCol - largestIndexInVerticalLine;
        }
        int col = setCol + residueCol;

        int row = i % setNumbers;
        if (row > largestIndexInVerticalLine){
            row = largestIndexInVerticalLine - residueCol;
        }

        debug_print("setCol: %d, residueCol: %d\n", setCol, residueCol);
        debug_print("i: %lu, row:%d, col: %d\n", i, row, col);
        rowString[row][col] = s[i];
    }

    // 4. print
    for (size_t i=0; i<numRows; i++){
        for (size_t j=0; j<cols; j++){
            if(rowString[i][j])
                result += rowString[i][j];
        }
    }

    // 5. release resource
    for (size_t i=0; i< numRows; i++){
        if(rowString[i]){
            delete rowString[i];
            rowString[i] = NULL;
        }
    }

    return result;
}
