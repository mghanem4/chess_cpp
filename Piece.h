#pragma once
#include <string>

enum class Color { WHITE, BLACK };
// Forward declaration, can't include Board but need it, causes a circular dep.
class Board;  
class Piece {
    protected:
        Color color;

    public:
    // cosntructor, takes a color (W or B)
        Piece(Color c) : color(c) {}
        virtual ~Piece() = default;
        virtual bool isValidMove(int srcRow, int srcCol, int destRow, int destCol,const Board& board) const = 0;
    // getters
        Color getColor() const { return color; }
        virtual char getSymbol() const = 0;
};
