#include "Board.h"
#include <iostream>
#include <string>

int main() {
    Board board;
    std::string input;
    int srcRow, srcCol, destRow, destCol;

    while (true) {
        board.display();
        std::cout << "Enter move (e.g., e2 e4):\n";
        std::cout << "           source (e2) -> destination (e4)\n";
        std::cin >> input;

        if (input.size() != 2) continue;
        srcCol = input[0] - 'a';
        srcRow = 8 - (input[1] - '0');

        std::cin >> input;
        if (input.size() != 2) continue;
        destCol = input[0] - 'a';
        destRow = 8 - (input[1] - '0');

        if (!board.movePiece(srcRow, srcCol, destRow, destCol)) {
            std::cout << "Invalid move!\n";
        }
    }

    return 0;
}
