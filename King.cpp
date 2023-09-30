#include "King.hpp"



namespace chessitem {
    King::King(const QString& color, int row, int col, QWidget* parent) : Piece(color, row, col, parent) {
        compteur_++;
        if (compteur_ > 2) {
            compteur_--;
            parent = nullptr;
            delete parent;
            throw std::runtime_error("Erreur: Vous avez ajouter plus de 2 instances de Roi.");

        }
    }

    King::~King()
    {
        compteur_--;
    }

    void King::mousePressEvent(QMouseEvent* event) {
        if (event->button() == Qt::LeftButton) {
            emit kingClicked(this);
        }
    }
    std::vector<std::vector<bool>> King::getValidMove() {
        std::vector<std::vector<bool>> validMoves = std::vector<std::vector<bool>>(8, std::vector<bool>(8, false));

        int currentRow = y() / squareSize_;
        int currentCol = x() / squareSize_;

        for (int row = currentRow - 1; row <= currentRow + 1; row++) {
            for (int col = currentCol - 1; col <= currentCol + 1; col++) {
                if (row >= 0 && row <= 7 && col >= 0 && col <= 7 && (row != currentRow || col != currentCol)) {
                    if (chessTableLabel_.getPieceAtPosition(row, col) == nullptr || chessTableLabel_.getPieceAtPosition(row, col)->getColor() != this->getColor()) {
                        validMoves[row][col] = true;
                    }
                }
            }
        }

        return validMoves;
    }



    int King::compteur_ = 0;
    int King::getCompteur() { return compteur_; }
}

