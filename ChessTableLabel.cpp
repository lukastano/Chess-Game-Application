#include "ChessTableLabel.hpp"
#include "Piece.hpp"

std::unique_ptr<ChessTableLabel> ChessTableLabel::instance_;

ChessTableLabel::ChessTableLabel() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            chessTable_[row][col] = nullptr;
        }
    }
}

ChessTableLabel& ChessTableLabel::instance() {
    if (!instance_) {
        instance_ = std::unique_ptr<ChessTableLabel>(new ChessTableLabel);
    }
    return *instance_;
}

void ChessTableLabel::setPosition(int row, int col, Piece* piece) {
    chessTable_[row][col] = piece;
}

Piece* ChessTableLabel::getPieceAtPosition(int row, int col) {
    return chessTable_[row][col];
}




