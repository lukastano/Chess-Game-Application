#include "Piece.hpp"

Piece::Piece(const QString& color, int row, int col, QWidget* parent) : QLabel(parent), color_(color), row_(row), col_(col), chessTableLabel_(ChessTableLabel::instance()) {}
