#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
// constructor, pawn color (W or B)
    Pawn(Color c) : Piece(c) {}
    char getSymbol() const override {
        bool isWhite = color == Color::WHITE;
        if(isWhite) return 'P';
        else return 'p';
    }

    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) const override {
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
        if (srcCol == destCol && destRow == srcRow + dir) {
            return true;
        }

        // Double-step from initial position
        if (srcCol == destCol && srcRow == start && destRow == srcRow + 2 * dir) {
            return true;
        }
        return false;
    }
};
