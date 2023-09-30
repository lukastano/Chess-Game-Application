#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include <QDebug>
#include <stdexcept>
#include "ChessTableLabel.hpp"

#ifndef PIECE_HPP
#define PIECE_HPP

class Piece : public QLabel {
    //Q_OBJECT
public:
    Piece(const QString& color, int row, int col, QWidget* parent = nullptr);

    QString getColor() const { return color_; }

    int getRow() const { return row_; }

    int getCol() const { return col_; }

    virtual bool isKing() { return false; }

    virtual std::vector<std::vector<bool>> getValidMove() = 0;




protected:

    ChessTableLabel& chessTableLabel_;
    int squareSize_ = 50;

private:
    QString color_;
    int row_;
    int col_;
    int oldRow_;
    int oldCol_;

};

#endif // PIECE_HPP