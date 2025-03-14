#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>
#include <stack>
#include <utility>

class Grid {

    private:

        struct Node {
            int first;
            int second;
            int value = 0;
            int save_state[9][9];
            std::set<int> checked_digits;
            Node(int f, int s) : first(f), second(s) {}

            friend std::ostream& operator<<(std::ostream& os, const Node& n) {
                os << "[" << n.value << "]";
                return os;
            }
        };

        Node* arr[9][9];
        std::stack<Node*> location_stack;


    public:
        Grid() {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    arr[i][j] = new Node(i - 1, j - 1);
                }
            }
        }

        void generateSudokuGrid(int seed = time(0)) {
            srand(seed);
            for (int i = 8; i >= 0; --i) {
                for (int j = 8; j >= 0; --j) {
                    location_stack.push(arr[i][j]);
                }
            }
            solveGrid();

        }
    
        bool checkRow(Node* n) {
            for (int i = 0; i < 9; ++i) {
                if (i == n->first) continue;
                if (arr[i][n->second]->value == n->value) {
                    return false;
                }
            }
            return true;
        }

        bool checkColumn(Node* n) {
            for (int i = 0; i < 9; ++i) {
                if (i == n->second) continue;
                if (arr[n->first][i]->value == n->value) {
                    return false;
                }
            }
            return true;
        }
        
        bool checkBox(Node* n) {
            int boxRow = n->first - n->first % 3;
            int boxCol = n->second - n->second % 3;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (arr[boxRow + i][boxCol + j] == n) continue;
                    if (arr[boxRow + i][boxCol + j]->value == n->value) {
                        return false;
                    }
                }
            }
            return true;
        }

        void saveGridState(Node* node) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (node->first == i and node->second == j) {
                        node->save_state[i][j] = 0;
                    } else {
                        node->save_state[i][j] = arr[i][j]->value;
                    }
                }
            }
        }

        Node* getPreviousNode(Node* current) {
            if (current->first == 0 && current->second == 0) {
                return nullptr;
            } else if (current->second == 0) {
                return arr[current->first - 1][8];
            } else {
                return arr[current->first][current->second - 1];
            }
        }

        bool compareGrid(Node* node) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (node->save_state[i][j] != arr[i][j]->value) {
                        return false;
                    }
                }
            }
            return true;
        }

    
        bool solveGrid() {
            if (location_stack.empty()) {
                return true;
            }

            Node* current = location_stack.top();

            printGrid();

            if (!compareGrid(current)) {
                current->checked_digits.clear();
            }

            while (current->checked_digits.size() < 9) {
                current->value = rand() % 9 + 1;
                if (current->checked_digits.find(current->value) != current->checked_digits.end()) {
                    continue;
                }
                current->checked_digits.insert(current->value);
                if (checkRow(current) && checkColumn(current) && checkBox(current)) {
                    saveGridState(current);
                    location_stack.pop();
                    if (solveGrid()) {
                        return true;
                    } else {
                        location_stack.push(current);
                    }
                }
            }

            current->value = 0;
            current->checked_digits.clear();
            return false;
        }
        
        void printGrid() {
            std::cout << "==================" << std::endl;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    std::cout << *arr[i][j];
                }
                std::cout << std::endl;
            }
        }

    friend std::ostream& operator<<(std::ostream& os, const Grid g) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                os << "[" << g.arr[i][j]->value << "]";
            }
            os << std::endl;
        }
        return os;
    }

};