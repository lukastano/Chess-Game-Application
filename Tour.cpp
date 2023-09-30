#include "Tour.hpp"

namespace chessitem {
    Tour::Tour(const QString& color, int row, int col, QWidget* parent) : Piece(color, row, col, parent) {
    }

    void Tour::mousePressEvent(QMouseEvent* event) {
        if (event->button() == Qt::LeftButton) {
            emit tourClicked(this);
        }
    }

    std::vector<std::vector<bool>> Tour::getValidMove() {

        std::vector<std::vector<bool>> validMoves = std::vector<std::vector<bool>>(8, std::vector<bool>(8, false));

        int currentRow = y() / squareSize_;
        int currentCol = x() / squareSize_;


        for (int col = currentCol + 1; col <= 7; col++) {
            if (chessTableLabel_.getPieceAtPosition(currentRow, col) == nullptr) {
                validMoves[currentRow][col] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow, col)->getColor() != this->getColor()) {
                validMoves[currentRow][col] = true;
                break;
            }
            else {

                break;
            }
        }


        for (int col = currentCol - 1; col >= 0; col--) {
            if (chessTableLabel_.getPieceAtPosition(currentRow, col) == nullptr) {
                validMoves[currentRow][col] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow, col)->getColor() != this->getColor()) {
                validMoves[currentRow][col] = true;
                break;
            }
            else {

                break;
            }
        }

        for (int row = currentRow - 1; row >= 0; row--) {
            if (chessTableLabel_.getPieceAtPosition(row, currentCol) == nullptr) {
                validMoves[row][currentCol] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(row, currentCol)->getColor() != this->getColor()) {
                validMoves[row][currentCol] = true;
                break;
            }
            else {

                break;
            }
        }


        for (int row = currentRow + 1; row <= 7; row++) {
            if (chessTableLabel_.getPieceAtPosition(row, currentCol) == nullptr) {
                validMoves[row][currentCol] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(row, currentCol)->getColor() != this->getColor()) {
                validMoves[row][currentCol] = true;
                break;
            }
            else {

                break;
            }
        }

        return validMoves;
    }

}