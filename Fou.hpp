#include "Piece.hpp"


#ifndef FOU_HPP
#define FOU_HPP

namespace chessitem {

    class Fou : public Piece {
        Q_OBJECT
    public:
        Fou(const QString& color, int row, int col, QWidget* parent = nullptr);
        std::vector<std::vector<bool>> getValidMove();

    signals:
        void fouClicked(Fou* king);

    protected:
        void mousePressEvent(QMouseEvent* event);

    };

}

#endif // Fou_HPP



