#include "Board.h"
#include "Pawn.h"
#include <iostream>

Board::Board() : colorTurn(Color::WHITE) {
    // Initialize white pawns
    for (int i = 0; i < 8; ++i) {
        // grid starts from 0 to 7, row 1 is black, row 6 is white pawns
        grid[6][i] = std::make_shared<Pawn>(Color::WHITE);
        grid[1][i] = std::make_shared<Pawn>(Color::BLACK);
    }
}

/* display board */
void Board::display() const {
    // loop first through rows
    for (int row = 0; row < 8; ++row) {
        // enumerate rows
        std::cout << 8 - row << " ";
        // at each row, go through the columns
/* 
Ex: go thru each pawn in the first row:
    1. p p p p p p p
       _ _ _ _ _ _ _ 
*/
        for (int col = 0; col < 8; ++col) {
            // get symbol of the grid[row][col] for the symbol.
            if (grid[row][col]) std::cout << grid[row][col]->getSymbol() << " ";
            else std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << "  a b c d e f g h\n";
}

bool Board::movePiece(int srcRow, int srcCol, int destRow, int destCol) {
    // avoids making unnecessary copies of objects and deduce object type
    auto& src = grid[srcRow][srcCol];
    if (!src) return false;
    // if it is a valid move, make the switch, set destination to source and set source null
    if(src->getColor() !=colorTurn){
        std::cout << "Not your piece!\n";
        return false;
    }
    if (src->isValidMove(srcRow, srcCol, destRow, destCol)) {
        grid[destRow][destCol] = src;
        src = nullptr;
        // switch turns
        if(colorTurn == Color::WHITE) colorTurn = Color::BLACK;
        else colorTurn = Color::WHITE;
        
        return true;
    }
    return false;
}
