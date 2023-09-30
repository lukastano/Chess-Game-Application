#include "Cavalier.hpp"

namespace chessitem {
    Cavalier::Cavalier(const QString& color, int row, int col, QWidget* parent) : Piece(color, row, col, parent) {
    }

    std::vector<std::vector<bool>> Cavalier::getValidMove()
    {
        std::vector<std::vector<bool>> validMoves = std::vector<std::vector<bool>>(8, std::vector<bool>(8, false));

        int currentRow = y() / squareSize_;
        int currentCol = x() / squareSize_;

        int possibleMoves[8][2] = {
            {2,1},
            {2,-1},
            {-2,1},
            {-2,-1},
            {1,2},
            {1,-2},
            {-1,2},
            {-1,-2}
        };

        for (int i = 0; i < 8; i++) {
            int row = currentRow + possibleMoves[i][0];
            int col = currentCol + possibleMoves[i][1];
            if (row >= 0 && row <= 7 && col >= 0 && col <= 7 &&
                (chessTableLabel_.getPieceAtPosition(row, col) == nullptr ||
                    chessTableLabel_.getPieceAtPosition(row, col)->getColor() != this->getColor())) {
                validMoves[row][col] = true;
            }
        }

        return validMoves;
    }

    void Cavalier::mousePressEvent(QMouseEvent* event) {
        if (event->button() == Qt::LeftButton) {
            emit cavalierClicked(this);
        }
    }
}