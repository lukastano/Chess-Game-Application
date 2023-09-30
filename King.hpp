#include "Piece.hpp"

#ifndef KING_HPP
#define KING_HPP

namespace chessitem {
    class King : public Piece {
        Q_OBJECT
    public:
        King(const QString& color, int row, int col, QWidget* parent = nullptr);
        ~King();
        static int getCompteur();
        std::vector<std::vector<bool>> getValidMove();
        bool isInCheck()const { return inCheck; }
        void setIsInCheck(bool booleen) { inCheck = booleen; }
        bool isKing() override { return true; }


    signals:
        void kingClicked(King* king);


    protected:
        void mousePressEvent(QMouseEvent* event);

    private:
        static int compteur_;
        bool inCheck = false;
    };
}


#endif // KING_HPP



