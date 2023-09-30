#include "Piece.hpp"

#ifndef REINE_HPP
#define REINE_HPP
namespace chessitem {
    class Reine : public Piece {
        Q_OBJECT
    public:
        Reine(const QString& color, int row, int col, QWidget* parent = nullptr);
        std::vector<std::vector<bool>> getValidMove();

    signals:
        void reineClicked(Reine* pion);

    protected:
        void mousePressEvent(QMouseEvent* event) override;

    };
}



#endif // REINE_HPP



