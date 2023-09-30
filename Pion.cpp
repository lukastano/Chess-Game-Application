#include "Pion.hpp"

namespace chessitem {
    Pion::Pion(const QString& color, int row, int col, QWidget* parent) : Piece(color, row, col, parent) {
    }

    void Pion::mousePressEvent(QMouseEvent* event) {
        if (event->button() == Qt::LeftButton) {
            emit pionClicked(this);
        }
    }

    std::vector<std::vector<bool>> Pion::getValidMove() {
        std::vector<std::vector<bool>> validMoves(8, std::vector<bool>(8, false));
        int currentRow = y() / squareSize_;
        int currentCol = x() / squareSize_;

        int direction = (getColor() == "Blanc") ? -1 : 1;
        int newRow = currentRow + direction;

        if (newRow >= 0 && newRow <= 7 && chessTableLabel_.getPieceAtPosition(newRow, currentCol) == nullptr) {
            validMoves[newRow][currentCol] = true;

            if ((getColor() == "Blanc" && currentRow == 6) || (getColor() == "Noir" && currentRow == 1)) {
                newRow += direction;
                if (newRow >= 0 && newRow <= 7 && chessTableLabel_.getPieceAtPosition(newRow, currentCol) == nullptr) {
                    validMoves[newRow][currentCol] = true;
                }
            }
        }

        if (currentRow == 0 && direction == -1) {
            return validMoves;
        }
        if (currentRow == 7 && direction == 1) {
            return validMoves;
        }

        if (currentCol > 0) {
            int diagonalRow = currentRow + direction;
            int diagonalCol = currentCol - 1;
            Piece* piece = chessTableLabel_.getPieceAtPosition(diagonalRow, diagonalCol);
            if (piece != nullptr && piece->getColor() != getColor()) {
                validMoves[diagonalRow][diagonalCol] = true;
            }
        }

        if (currentCol < 7) {
            int diagonalRow = currentRow + direction;
            int diagonalCol = currentCol + 1;
            Piece* piece = chessTableLabel_.getPieceAtPosition(diagonalRow, diagonalCol);
            if (piece != nullptr && piece->getColor() != getColor()) {
                validMoves[diagonalRow][diagonalCol] = true;
            }
        }

        return validMoves;
    }
}


