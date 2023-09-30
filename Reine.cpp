#include "Reine.hpp"

namespace chessitem {
    Reine::Reine(const QString& color, int row, int col, QWidget* parent) : Piece(color, row, col, parent) {
    }

    void Reine::mousePressEvent(QMouseEvent* event) {
        if (event->button() == Qt::LeftButton) {
            emit reineClicked(this);
        }
    }

    std::vector<std::vector<bool>> Reine::getValidMove() {
        std::vector<std::vector<bool>> validMoves = std::vector<std::vector<bool>>(8, std::vector<bool>(8, false));

        int currentRow = y() / squareSize_;
        int currentCol = x() / squareSize_;


        for (int i = currentCol + 1; i < 8; i++) {
            if (chessTableLabel_.getPieceAtPosition(currentRow, i) == nullptr) {
                validMoves[currentRow][i] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow, i)->getColor() != this->getColor()) {
                validMoves[currentRow][i] = true;
                break;
            }
            else {
                break;
            }
        }
        for (int i = currentCol - 1; i >= 0; i--) {
            if (chessTableLabel_.getPieceAtPosition(currentRow, i) == nullptr) {
                validMoves[currentRow][i] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow, i)->getColor() != this->getColor()) {
                validMoves[currentRow][i] = true;
                break;
            }
            else {
                break;
            }
        }
        for (int i = currentRow + 1; i < 8; i++) {
            if (chessTableLabel_.getPieceAtPosition(i, currentCol) == nullptr) {
                validMoves[i][currentCol] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(i, currentCol)->getColor() != this->getColor()) {
                validMoves[i][currentCol] = true;
                break;
            }
            else {
                break;
            }
        }
        for (int i = currentRow - 1; i >= 0; i--) {
            if (chessTableLabel_.getPieceAtPosition(i, currentCol) == nullptr) {
                validMoves[i][currentCol] = true;
            }
            else if (chessTableLabel_.getPieceAtPosition(i, currentCol)->getColor() != this->getColor()) {
                validMoves[i][currentCol] = true;
                break;
            }
            else {
                break;
            }
        }

        int i = 1;
        while (currentRow - i >= 0 && currentCol + i < 8) {
            if (chessTableLabel_.getPieceAtPosition(currentRow - i, currentCol + i) == nullptr) {
                validMoves[currentRow - i][currentCol + i] = true;
                i++;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow - i, currentCol + i)->getColor() != this->getColor()) {
                validMoves[currentRow - i][currentCol + i] = true;
                break;
            }
            else {
                break;
            }
        }

        i = 1;
        while (currentRow - i >= 0 && currentCol - i >= 0) {
            if (chessTableLabel_.getPieceAtPosition(currentRow - i, currentCol - i) == nullptr) {
                validMoves[currentRow - i][currentCol - i] = true;
                i++;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow - i, currentCol - i)->getColor() != this->getColor()) {
                validMoves[currentRow - i][currentCol - i] = true;
                break;
            }
            else {
                break;
            }
        }

        i = 1;
        while (currentRow + i < 8 && currentCol + i < 8) {
            if (chessTableLabel_.getPieceAtPosition(currentRow + i, currentCol + i) == nullptr) {
                validMoves[currentRow + i][currentCol + i] = true;
                i++;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow + i, currentCol + i)->getColor() != this->getColor()) {
                validMoves[currentRow + i][currentCol + i] = true;
                break;
            }
            else {
                break;
            }
        }

        i = 1;
        while (currentRow + i < 8 && currentCol - i >= 0) {
            if (chessTableLabel_.getPieceAtPosition(currentRow + i, currentCol - i) == nullptr) {
                validMoves[currentRow + i][currentCol - i] = true;
                i++;
            }
            else if (chessTableLabel_.getPieceAtPosition(currentRow + i, currentCol - i)->getColor() != this->getColor()) {
                validMoves[currentRow + i][currentCol - i] = true;
                break;
            }
            else {
                break;
            }
        }

        return validMoves;

    }

}