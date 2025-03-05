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

        Node arr[9][9];
        std::stack<std::pair<int, int>> location_stack;
        std::pair<int, int> origin = {0, 0};


    public:
        Grid() {
            location_stack.push(origin);
        }

        void generateSudokuGrid(int seed=time(0)) {

            srand(seed);

            for (int i = 0; i != 3; ++i) {
                for (int j = 0; j != 3; ++j) {
                    
                    std::set<int> occurrence_checker;
                    int chosen_number = 0;

                    for (int k = 0; k != 3; ++k) {
                        for (int l = 0; l != 3; ++l) {

                            do {
                                chosen_number = rand() % 9 + 1;
                            } while (!occurrence_checker.insert(chosen_number).second);

                            arr[i * 3 + k][j * 3 + l] = chosen_number;

                        }
                    }
                }
            }

            std::cout << arr << std::endl;
            
            return;
        }
    
    bool solveGrid() {
        std::pair<int, int> current = location_stack.top();
        int value = arr[current.first][current.second];

        for (int i = 0; i < 9; ++i) {
            if (i != current.first) {
                if (arr[i][current.second] == value) {

                }
            }
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