#include "Piece.hpp"

#ifndef TOUR_HPP
#define TOUR_HPP
namespace chessitem {
    class Tour : public Piece {
        Q_OBJECT
    public:
        Tour(const QString& color, int row, int col, QWidget* parent = nullptr);
        std::vector<std::vector<bool>> getValidMove();

    signals:
        void tourClicked(Tour* pion);


    protected:
        void mousePressEvent(QMouseEvent* event) override;


    };
}



#endif // TOUR_HPP



