#pragma once
#include <string>

enum class Color { WHITE, BLACK };

class Piece {
    protected:
        Color color;

    public:
    // cosntructor, takes a color (W or B)
        Piece(Color c) : color(c) {}
        virtual ~Piece() = default;
        virtual bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) const = 0;
    // getters
        Color getColor() const { return color; }
        virtual char getSymbol() const = 0;
};
