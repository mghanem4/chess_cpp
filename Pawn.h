#pragma once
#include "Piece.h"
#include "Board.h"
class Pawn : public Piece {
public:
// constructor, pawn color (W or B)
    Pawn(Color c) : Piece(c) {}
    char getSymbol() const override {
        bool isWhite = color == Color::WHITE;
        if(isWhite) return 'P';
        else return 'p';
    }

    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol, const Board& board) const override {
        int dir, start;

        bool isWhite = color == Color::WHITE;


        if(isWhite) {
            dir = -1;
            // white pieces start on the top of array row 6
            start= 6;
        }
        else {
            dir = 1;
            // black pieces start on the bottom of array row 1
            start=1;
        }
        if (srcCol == destCol && destRow == srcRow + dir && !board.getPiece(destRow, destCol)) {
            return true;
        }

        // Double-step from initial position
        if (srcCol == destCol && srcRow == start && destRow == srcRow + 2 * dir && !board.getPiece(destRow, destCol)) {
            return true;
        }
            // Diagonal capture
        if (abs(destCol - srcCol) == 1 && destRow == srcRow + dir) {
            auto target = board.getPiece(destRow, destCol);
            if (target && target->getColor() != color)
                return true;
        }
        return false;
    }
};
