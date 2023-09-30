#pragma once

#include "Piece.hpp"
#include "Pion.hpp" 
#include "RedChessSquare.hpp"
#include "King.hpp" 
#include "Fou.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Reine.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#pragma pop()
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <stdexcept>
#include "ChessTableLabel.hpp"

namespace chessitem {
    class Pion;
    class King;
    class Fou;
    class Tour;
    class Cavalier;
    class Reine;
}

namespace gui {
    class MainGui : public QMainWindow {
        Q_OBJECT
    public:
        MainGui(QWidget* parent = 0);
        bool isKingInCheck();
        ChessTableLabel& getChessTableLabel() const { return chessTableLabel_; }
        void setCurrentColorTurn(QString& color) { m_currentColorTurn = color; };
        void setChessBoard(int mode);
        bool isKingInCheckmate();

    private:
        void addChessItem(Piece* pion, QString unicode, int posX, int posY);
        void removeChessItem(Piece* piece);
        void highlightSquare(int row, int col, QColor color);
        void removeHighlighting();
        void refreshSelectedPiece();
        void addPiece(int row, int col, int mode);

        bool isKingColorInCheck(const QString& kingColor);;
        bool isMoveLegal(Piece* piece, int row, int col);
        bool isSquareAttacked(int row, int col, const QString& attackingColor);
        bool simulateMoveAndCheck(Piece* piece, int oldRow, int oldCol, int newRow, int newCol, const QString& kingColor);
        bool isStalemate(const QString& currentColor);


        QGraphicsView* m_view;
        QGraphicsScene* m_scene;
        const int squareSize_ = 50;
        QString m_currentColor;
        QString m_currentColorTurn = "Blanc";
        QGraphicsRectItem* m_squares[8][8];
        QList<RedChessSquare*> highlightedSquares_;
        QGraphicsRectItem* m_selectedSquare = nullptr;
        Piece* m_selectedPiece = nullptr;
        ChessTableLabel& chessTableLabel_;
        int oldPosX;
        int oldPosY;
        chessitem::King* kingNoir;
        chessitem::King* kingBlanc;



    private slots:
        void onPionClicked(chessitem::Pion* pion);
        void onKingClicked(chessitem::King* king);
        void onFouClicked(chessitem::Fou* fou);
        void onTourClicked(chessitem::Tour* tower);
        void onCavalierClicked(chessitem::Cavalier* knight);
        void onReineClicked(chessitem::Reine* reine);
        void onRedSquareClicked(RedChessSquare* square);
    };
}
