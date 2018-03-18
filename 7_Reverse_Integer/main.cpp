#include <iostream>
#include <string>
#include <vector>
#include <cassert>  // for assert
#include <climits>

#define DEBUG 1
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

using namespace std;

class Solution {
public:

    int reverse(int x) 
    {
        // 1. int to char first
        // INT_MAX: 2147483647, INT_MIN: -2147483648 (11 digits including sign)
        const int MAX_LENGTH = 11;

        // add null at the end
        char valInChar[MAX_LENGTH + 1] = {};
        int result = 0;
        int pivot = 0;
        int negative = 0;

        sprintf(valInChar, "%d", x); 

        if ('-' == valInChar[0]) negative = 1;
        for (size_t i = 0; i < MAX_LENGTH; i++){
            debug_print("i: %lu, valInChar[i] = %c\n", i, valInChar[i]);
        }

        // 2. reverse the string with sign and remove preceding zeros
        char resultInChar[MAX_LENGTH] = {};
        int foundNonZero = 0;
        for (size_t i = 0; i < MAX_LENGTH; i++){
            if (foundNonZero){
                if ('-' != valInChar[MAX_LENGTH - 1 - i]) 
                    resultInChar[i - pivot + negative] = valInChar[MAX_LENGTH - 1 - i];
            }else{
                if (valInChar[MAX_LENGTH - 1 - i]){ 
                    debug_print("i: %lu, valInChar[MAX_LENGTH - 1 - i]:%d\n", i, valInChar[MAX_LENGTH - 1 - i]);
                    pivot = i;
                    foundNonZero = 1;
                    if (negative) resultInChar[i - pivot] = '-';
                    resultInChar[i - pivot + negative] = valInChar[MAX_LENGTH - 1 - i];
                    debug_print("pivot: %d\n", pivot);
                }
            }
        }

        for (size_t i = 0; i < MAX_LENGTH; i++){
            debug_print("i: %lu, resultInChar[i] = %c\n", i, resultInChar[i]);
        }

        // 3. check if it is overflow
        // INT_MAX: 2147483647, INT_MIN: -2147483648
        const double int_max_in_double = (double) INT_MAX;
        const double int_min_in_double = (double) INT_MIN;
        double result_in_double = atof(resultInChar);
        debug_print("int_max_in_double: %.0f, int_min_in_double: %.0f, result_in_double: %.0f\n", int_max_in_double, int_min_in_double, result_in_double);
        if (result_in_double > int_max_in_double || result_in_double < int_min_in_double)
            return 0;

        // 4. reverse back to integer (atoi)
        result = atoi(resultInChar);
        debug_print("result: %d\n", result);

        return result;
    }
};

int main(){
    Solution sol;
    int result;

    printf("max signed int: %d, min signed int: %d\n", INT_MAX, INT_MIN);

//  test set:
    result = sol.reverse(123);
    assert(321 == result);

//  test set:
    result = sol.reverse(-123);
    assert(-321 == result);

//  test set:
    result = sol.reverse(120);
    assert(21 == result);

//  test set:
    result = sol.reverse(1534236469);
    assert(0 == result);

//  test set:
    result = sol.reverse(-2147483412);
//    assert(-2143847412 == result);

    return 0;
}

