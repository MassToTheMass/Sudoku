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
            Node* save_state[9][9];
            std::set<int> checked_digits;
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
                    location_stack.push(arr[i][j]);
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

        Node* getPreviousNode(Node* current) {
            if (current->first == 0) {
                return arr[8][current->first -1];
            } else {
                return arr[current->first - 1][current->second];
            }
        }

    
        bool solveGrid() {
            Node* current = location_stack.top();

            std::set<int> checked_digits;

            while (checked_digits.size() < 9) {
                current->value = rand() % 9 + 1; // random between 1 and 9
                if (checkRow(current), checkColumn(current), checkBox(current)) {
                    location_stack.pop();
                    return true;
                } else {
                    current->checked_digits.insert(current->value);
                }
            }

            

            location_stack.push(getPreviousNode(current));
            return false;

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