#ifndef CHESSTABLELABEL_HPP
#define CHESSTABLELABEL_HPP


#include <QObject>
#include <memory>  // Include <memory> for std::unique_ptr

class Piece;  // Forward declare Piece

class ChessTableLabel : public QObject {

public:
    static ChessTableLabel& instance();

    void setPosition(int row, int col, Piece* piece);

    Piece* getPieceAtPosition(int row, int col);

private:
    ChessTableLabel();

    ChessTableLabel(const ChessTableLabel&) = delete;
    ChessTableLabel& operator=(const ChessTableLabel&) = delete;

    static std::unique_ptr<ChessTableLabel> instance_;

    Piece* chessTable_[8][8];
};

#endif // CHESSTABLELABEL_HPP
