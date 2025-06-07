#pragma once
#include <array>
#include <memory>
#include "Piece.h"

class Board {
private:
/* For this project, I need automatic cleanup without manual memory management. And I can't really determine what processes will be used later (still developing)*/
// 8 x8 grid for the board
    std::array<std::array<std::shared_ptr<Piece>, 8>, 8> grid;
    Color colorTurn;

public:
// const
    Board();
    void display() const;
    bool movePiece(int srcRow, int srcCol, int destRow, int destCol);
    std::shared_ptr<Piece> getPiece(int row, int col) const;

};
