#include <iostream>
#include <vector>
#include <set>
using namespace std;

char find_missing_letter(vector<string>& square) {
    set<char> letters = {'A', 'B', 'C'};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (square[i][j] == '?') {
                set<char> row_letters(square[i].begin(), square[i].end());
                set<char> col_letters = {square[0][j], square[1][j], square[2][j]};
                for (char letter : letters) {
                    if (row_letters.find(letter) == row_letters.end() &&
                        col_letters.find(letter) == col_letters.end()) {
                        return letter;
                    }
                }
            }
        }
    }
    return ' ';  // This line will never be reached.
}

int main() {
    int t;
    cin >> t;
    vector<char> results(t);  // Use vector<char> to store the results
    
    for (int testcase = 0; testcase < t; ++testcase) {
        vector<string> square(3);
        for (int i = 0; i < 3; ++i) {
            cin >> square[i];
        }
        results[testcase] = find_missing_letter(square);
    }
    
    for (char result : results) {
        cout << result << endl;
    }
    
    return 0;
}
