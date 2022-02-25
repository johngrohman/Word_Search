#include "matrix_search.h"

int main()
{
    int rows = 0;
    int cols = 0;
    int number_of_searches = 0;
    
    string word;

    cin >> number_of_searches;
    for(int i = 0; i < number_of_searches; i ++) {
        int solution [4] = {-1, -1, -1, -1};
        cin >> rows >> cols;
        char ** our_matrix = build_matrix(rows, cols);
        fill_matrix(rows, cols, our_matrix);
        cin >> word;
        cout << "Searching for \"" << word << "\" in matrix " << i << "yields:" << endl;
        matrix_search(solution, word, rows, cols, our_matrix);
        if (solution[1] != -1) {
            cout << "Start pos:(" << solution[0] << ", " << solution[1] << ") to End pos:(" << solution[2] << ", " << solution[3] << ")" << endl; 
        } else {
            cout << "The pattern was not found." << endl;
        }
        cout << endl;
        delete_matrix(rows, our_matrix);
    }
    return 0;
}

