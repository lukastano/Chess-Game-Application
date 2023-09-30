#include "Piece.hpp"

#ifndef CAVALIER_HPP
#define CAVALIER_HPP
namespace chessitem {
    class Cavalier : public Piece {
        Q_OBJECT
    public:
        Cavalier(const QString& color, int row, int col, QWidget* parent = nullptr);
        std::vector<std::vector<bool>> getValidMove();

    signals:
        void cavalierClicked(Cavalier* cavalier);

    protected:
        void mousePressEvent(QMouseEvent* event) override;

    };
}



#endif // CAVALIER_HPP



