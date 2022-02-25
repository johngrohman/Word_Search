#include "matrix.h"

char ** build_matrix(int rows, int cols)
{
    char ** p = new char*[rows];
    for (int i = 0; i < cols; i++) {
        p[i] = new char[cols];
    }
    return p;
}


void fill_matrix(int rows, int cols, char **matrix)
{
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            char input;
            cin >> input;
            matrix[r][c] = input;
        }
    }
}


void print_matrix(int rows, int cols, char **matrix)
{
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
}


void delete_matrix(int rows, char **matrix)
{
    for(int i = 0; i < rows; i++) {
        delete[]matrix[i];
        matrix[i] = nullptr;
    }
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
    sol[0] = 1;
    string goal = "";
    int length = -1;
    //Get the length of the word
    for(int i = 0; word[i]!='\0'; i++) {
        length++;
    }
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            //If we find the beginning of the word
            if (matrix[r][c] == word[0]) {
                //Look in all possible directions
                for(int i = 0; i < 8; i++) {
                    switch(i) {
                        //Case 0 starts with look straight to the left and goes around clockwise
                        //Add the length of the word to the current coords to see if we can even look in that direction
                        case 0: // left
                            //Check if we can look in this direction; if not, break
                            if (c-length < 0) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    //if the next leter to the right is equal to the word at an index
                                    if (word[i] == matrix[r][c-i]) {
                                        //check if we're at the end of the word
                                        if (i == length - 1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r;
                                            sol[3] = c-length;
                                        //otherwise, keep going
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 1: // top left
                            //Check if we can look in this direction; if not, break
                            if (c-length < 0 || r-length < 0) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r-i][c-i]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r-length;
                                            sol[3] = c-length;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 2: // top
                            //Check if we can look in this direction; if not, break
                            if (r-length < 0) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r-i][c]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r-length;
                                            sol[3] = c;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 3: // top right
                            //Check if we can look in this direction; if not, break
                            if (r-length < 0 || c+length > cols) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r-i][c+i]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r-length;
                                            sol[3] = c+length;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 4: // right
                            //Check if we can look in this direction; if not, break
                            if (c+length > cols) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r][c+i]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r;
                                            sol[3] = c+length;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 5: // bottom right
                            //Check if we can look in this direction; if not, break
                            if (c+length > cols || r+length > rows) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r+1][c+1]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r+length;
                                            sol[3] = c+length;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 6: // bottom
                            //Check if we can look in this direction; if not, break
                            if (r+length > rows) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r+1][c]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r+length;
                                            sol[3] = c;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                        case 7: // bottom left
                            //Check if we can look in this direction; if not, break
                            if (r+length > rows || c-length < 0) {
                                break;
                            } else {
                                for(int i = 1; i < length; i++) {
                                    if (word[i] == matrix[r+i][c-1]) {
                                        if (i == length-1) {
                                            sol[0] = r;
                                            sol[1] = c;
                                            sol[2] = r+length;
                                            sol[3] = c-length;
                                        } else {
                                            continue;
                                        }
                                    } else {
                                        break;
                                    }
                                }
                            }
                            break;
                    }
                }
            }

        }
    }
}

