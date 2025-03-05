#include "grid.hpp"

int main() {

    Grid* generator = new Grid();

    generator->generateSudokuGrid();
    generator->printGrid();

    return 0;
}