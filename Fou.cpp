#include "Fou.hpp"
namespace chessitem {
    Fou::Fou(const QString& color, int row, int col, QWidget* parent) : Piece(color, row, col, parent) {
    }

    void Fou::mousePressEvent(QMouseEvent* event) {
        if (event->button() == Qt::LeftButton) {
            emit fouClicked(this);
        }
    }
    std::vector<std::vector<bool>> Fou::getValidMove() {
        std::vector<std::vector<bool>> validMoves = std::vector<std::vector<bool>>(8, std::vector<bool>(8, false));

        int currentRow = y() / squareSize_;
        int currentCol = x() / squareSize_;

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