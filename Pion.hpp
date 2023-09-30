#include "Piece.hpp"

#ifndef PION_HPP
#define PION_HPP
namespace chessitem {
    class Pion : public Piece {
        Q_OBJECT
    public:
        Pion(const QString& color, int row, int col, QWidget* parent = nullptr);
        std::vector<std::vector<bool>> getValidMove();

    signals:
        void pionClicked(Pion* pion);

    protected:
        void mousePressEvent(QMouseEvent* event) override;
    private:
        int squareSize_ = 50;

    };
}



#endif // PION_HPP



