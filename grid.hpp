#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>

class Grid {

    private:
        int arr[9][9];


    public:
        Grid() {}

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

    void printGrid() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                std::cout << "[" << arr[i][j] << "]";
            }
            std::cout << std::endl;
        }
    }

};