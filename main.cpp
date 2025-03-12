#include "grid.hpp"

int main() {

    Grid* generator = new Grid();

    generator->generateSudokuGrid();
    std::cout << generator << std::endl;

    return 0;
}