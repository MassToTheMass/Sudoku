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
            int value;
            Node(int f, int s) : first(f), second(s) {}

            friend std::ostream& operator<<(std::ostream& os, const Node& n) {
                os << n.value;
                return os;
            }
        };

        Node* arr[9][9];
        std::stack<Node*> location_stack;


    public:
        Grid() {}

        void generateSudokuGrid(int seed=time(0)) {

            srand(seed);
            for (int i = 8; i > 0; --i) {
                for (int j = 8; j > 0; --j) {
                    location_stack.push(new Node(i, j));
                }
            }
            solveGrid();

        }
    
        bool checkRow(Node* n) {

            for (int i = 0; i < 9; ++i) {
                if (i == n->first) {} else {
                    if (arr[i][n->second]->value == n->value) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool checkColumn(Node* n) {

            for (int i = 0; i < 9; ++i) {
                if (i == n->second) {} else {
                    if (arr[n->second][i]->value == n->value) {
                        return false;
                    }
                }
            }
            return true;
        }
        
        bool checkBox(Node* n) {

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (arr[i][j] == n) {} else {
                        if (arr[i][j]->value == n->value) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

    
        bool solveGrid() {
            Node* current = location_stack.top();

            // need to make a set to check numbers

            current->value = rand() % 9 + 1; // random between 1 and 9
            if (checkRow(current), checkColumn(current), checkBox(current)) {
                location_stack.pop();
            }
        }

        void printGrid() {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    std::cout << "[" << arr[i][j] << "]";
                }
                std::cout << std::endl;
            }
        }

    friend std::ostream& operator<<(std::ostream& os, const Grid g) {}

};