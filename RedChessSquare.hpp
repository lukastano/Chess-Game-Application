#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>


class RedChessSquare : public QLabel
{
    Q_OBJECT
public:
    RedChessSquare(int row, int col, int size, QWidget* parent = nullptr);

    int row() const { return m_row; }
    int col() const { return m_col; }
    int size() const { return m_size; }

signals:
    void RedSquareClicked(RedChessSquare* square);

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    int m_row;
    int m_col;
    int m_size;
};

