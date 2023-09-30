#include "RedChessSquare.hpp"

RedChessSquare::RedChessSquare(int row, int col, int size, QWidget* parent)
    : QLabel(parent)
    , m_size(size), m_row(row), m_col(col)
{
    setFixedSize(size, size);
    setAlignment(Qt::AlignCenter);
    setStyleSheet("background-color: rgba(255, 0, 0, 0.2);");
    move(col * size, row * size);
}

void RedChessSquare::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit RedSquareClicked(this);
    }

    QLabel::mousePressEvent(event);
}