#include <iostream>
#include <string>

#define DEBUG 1
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

using namespace std;

/*
    1. zigzag is scanned diagonally
    2. each diagonal represents the same distance (sum of x_index & y_index) to left upper corner
    3. e.g. A B F G
            C E H
            D I
            J
        distance 0 : A (0, 0)
                 1 : B (1, 0), C (0, 1)
                 2 : D (0, 2), E (1, 1), F (2, 0)
    4. Namely, given sum of distance r, if r is even, x_index increases from 0 to r, y_index decreases from r to 0
    5. one more restrict is (odd, even) will be filled empty
 */

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        // roughly allocate with long size, *2 for worst case numRow = 1
        int numCols = s.length() * 2;
        if (0 == numCols) return result;
        
        // allocate resource
        char **data = (char **) malloc(sizeof(char*) * numCols);
        memset(data, 0, sizeof(char*) * numCols);
        for (size_t i = 0; i < numCols; i++){
            data[i] = (char *) malloc(sizeof(char) * numRows);
            memset(data[i], 0, sizeof(char) * numRows);
        }

        // fill in
        int distance = 0;
        int x_index = 0;
        int y_index = 0;

        debug_print("numRows: %d, numCols: %d\n", numRows, numCols);
        for (size_t i = 0; i < s.length(); i++){
            if (1 == x_index % 2 && 0 == y_index % 2){
                i--;
            }else{
                data[x_index][y_index] = s.at(i);
            }

            debug_print("data[%d][%d]:%c\n", x_index, y_index, data[x_index][y_index]);
            if (0 == distance % 2){
                x_index++;
                y_index--;
                if (y_index < 0){
                    y_index++;
                }
            }else{
                x_index--;
                y_index++;
                if (x_index < 0){
                    x_index++;
                } 
                if (y_index > numRows - 1){
                    x_index += 2;
                    y_index--;
                }
            }
            distance = x_index + y_index;
        }

        // scan line-by-line
        for (size_t j = 0; j < numRows; j++){
            for (size_t i = 0; i < numCols; i++){
                if (data[i][j]) result += data[i][j];
            }
        }

        // release resource
        for (size_t i = 0; i < numCols; i++){
            if (data[i]){
                free(data[i]);
                data[i] = NULL;
            }
        }

        if (data){
            free(data);
            data = NULL;
        }
        
        return result;
    }
};

int main(){
    Solution sol;
    string result;
//    result = sol.convert("sample", 3);
//    result = sol.convert("vcakvfswgkgszhcscpuhhigcchceedszhujczdaiohapocirreaapicrrfxviruplgtljvtzcvrtxbmqhmrwuvplamjkdfbrlwexsxyusrprubjcncajyqxaeglklobzlhydewzyqprkqcmgfnrdfoflwsvkhylsfjxlhwlxneighwomlfrqwwcupzeyypqfaprinehbjrjqoxezcvsarwvivbgvtybtnuddalgjcpbsofusamtuiocfrldklgebajeaukmzbnrptlhvzcpjsupkhsusyatakxcgjofkezbxmlsmnkvgemqlgmdgnzizwnfidnuhowgajzmwlkepyuchjhnygyxflepotjyhheisfwpqithhqjoztdxbbwioczdwjddshnlnmcduxlbnwrorvntyjdnmdskovpicdvrrxvlvinkegzybmtcywrmbjwpglakqvchvzvshicnqdluqgwqdnceyywglwqetunotigasjqjoddgkzwpoyvoyrumpkqjfdxamgdeptpdysmitixhjtvhmrtcclnjpmjdsmjjhzngrzqnjqwslucxlxbpjoyabkdvyofinuqhvgueyqxjkbjwyklhbmhewmzwbeeqyuxtdrabkxlwausyggghuplscnofrvvsptlsmlwykhvkbpjjxrrrgejkra", 33);
//    result = sol.convert("PAYPALISHIRING", 3);
//    result = sol.convert("AB", 1);
    result = sol.convert("ABC", 2);
    printf("result: %s\n", result.c_str());
    return 0;
}

