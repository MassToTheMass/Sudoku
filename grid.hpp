#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>

class Grid {

    private:
        int arr[9][9];


    public:
        Grid() {}

        void generateSudokuGrid() {

            srand(time(0));

            for (int i = 0; i != 3; ++i) {
                for (int j = 0; j != 3; ++j) {
                    
                    std::set<int> occurrence_checker;
                    int chosen_number = 0;
                    occurrence_checker.insert(chosen_number);

                    for (int k = 0; k != 3; ++k) {
                        for (int l = 0; l != 3; ++l) {
                            while (occurrence_checker.insert(chosen_number).second) {
                                int chosen_number = rand() % 10;
                                std::cout << l << k << chosen_number << std::endl;
                            }
                            arr[i * 3 + k][j * 3 + l] = chosen_number;

                        }
                    }
                }
            }

            std::cout << arr << std::endl;
            
            return;
        }

};