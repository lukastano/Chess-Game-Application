#include "MainGui.hpp"
#include "Pion.hpp"
#include <QChar>
#include <QMessagebox>
#include <memory>
namespace gui {
    MainGui::MainGui(QWidget* parent)
        : QMainWindow(parent), chessTableLabel_(ChessTableLabel::instance())
    {

        m_view = new QGraphicsView(this);
        setCentralWidget(m_view);

        m_scene = new QGraphicsScene(this);
        m_view->setScene(m_scene);
    }

    void MainGui::addPiece(int row, int col, int mode) {
        using namespace chessitem;
        int mode1 = 1;
        int mode2 = 2;
        QString blanc = "Blanc";
        QString noir = "Noir";

        if (((row == 0 && col == 0) || (row == 0 && col == 7)) && mode == mode1) {
            Tour* tourNoir = new Tour(noir, row, col);
            chessTableLabel_.setPosition(row, col, tourNoir);
            QString noirTourUnicode = "\u265C";
            addChessItem(tourNoir, noirTourUnicode, col * squareSize_, row * squareSize_);
            connect(tourNoir, SIGNAL(tourClicked(chessitem::Tour*)), this, SLOT(onTourClicked(chessitem::Tour*)));
        }

        if (((row == 0 && col == 0) || (row == 0 && col == 7)) && mode == mode2) {
            Fou* fouNoir = new Fou(noir, row, col);
            chessTableLabel_.setPosition(row, col, fouNoir);
            QString blackFouUnicode = "\u265D";
            addChessItem(fouNoir, blackFouUnicode, col * squareSize_, row * squareSize_);
            connect(fouNoir, SIGNAL(fouClicked(chessitem::Fou*)), this, SLOT(onFouClicked(chessitem::Fou*)));
        }

        else if ((row == 0 && col == 1) || (row == 0 && col == 6)) {
            //add cavalier noir
            Cavalier* cavalierNoir = new Cavalier(noir, row, col);
            chessTableLabel_.setPosition(row, col, cavalierNoir);
            QString noirCavalierUnicode = "\u265E";
            addChessItem(cavalierNoir, noirCavalierUnicode, col * squareSize_, row * squareSize_);
            connect(cavalierNoir, SIGNAL(cavalierClicked(chessitem::Cavalier*)), this, SLOT(onCavalierClicked(chessitem::Cavalier*)));
        }

        else if (((row == 0 && col == 2) || (row == 0 && col == 5)) && mode == mode1) {
            Fou* fouNoir = new Fou(noir, row, col);
            chessTableLabel_.setPosition(row, col, fouNoir);
            QString blackFouUnicode = "\u265D";
            addChessItem(fouNoir, blackFouUnicode, col * squareSize_, row * squareSize_);
            connect(fouNoir, SIGNAL(fouClicked(chessitem::Fou*)), this, SLOT(onFouClicked(chessitem::Fou*)));
        }

        else if (((row == 0 && col == 2) || (row == 0 && col == 5)) && mode == mode2) {
            Tour* tourNoir = new Tour(noir, row, col);
            chessTableLabel_.setPosition(row, col, tourNoir);
            QString noirTourUnicode = "\u265C";
            addChessItem(tourNoir, noirTourUnicode, col * squareSize_, row * squareSize_);
            connect(tourNoir, SIGNAL(tourClicked(chessitem::Tour*)), this, SLOT(onTourClicked(chessitem::Tour*)));
        }

        else if (row == 0 && col == 4) {
            try {
                kingNoir = new King(noir, row, col);
                chessTableLabel_.setPosition(row, col, kingNoir);
                QString blackKingUnicode = "\u265A";
                addChessItem(kingNoir, blackKingUnicode, col * squareSize_, row * squareSize_);
                connect(kingNoir, SIGNAL(kingClicked(chessitem::King*)), this, SLOT(onKingClicked(chessitem::King*)));
            }

            catch (std::runtime_error e) {
                QMessageBox messageBox;
                messageBox.critical(0, "Vous avez ajouter plus de 2 roi",
                    e.what());
            }
        }

        else if (row == 0 && col == 3) {
            //add reine noir
            Reine* reineNoir = new Reine(noir, row, col);
            chessTableLabel_.setPosition(row, col, reineNoir);
            QString blackReineUnicode = "\u265B";
            addChessItem(reineNoir, blackReineUnicode, col * squareSize_, row * squareSize_);
            connect(reineNoir, SIGNAL(reineClicked(chessitem::Reine*)), this, SLOT(onReineClicked(chessitem::Reine*)));

        }
        else if (row == 1) {
            //add pion noir
            Pion* pionNoir = new Pion(noir, row, col);
            chessTableLabel_.setPosition(row, col, pionNoir);
            QString blackPawnUnicode = "\u265F";
            addChessItem(pionNoir, blackPawnUnicode, col * squareSize_, row * squareSize_);
            connect(pionNoir, SIGNAL(pionClicked(chessitem::Pion*)), this, SLOT(onPionClicked(chessitem::Pion*)));
        }

        else if (((row == 7 && col == 0) || (row == 7 && col == 7)) && mode == mode1) {
            //add tour blanc
            Tour* tourBlanc = new Tour(blanc, row, col);
            chessTableLabel_.setPosition(row, col, tourBlanc);
            QString whiteTourUnicode = "\u2656";
            addChessItem(tourBlanc, whiteTourUnicode, col * squareSize_, row * squareSize_);
            connect(tourBlanc, SIGNAL(tourClicked(chessitem::Tour*)), this, SLOT(onTourClicked(chessitem::Tour*)));
        }

        else if (((row == 7 && col == 0) || (row == 7 && col == 7)) && mode == mode2) {
            //add tour blanc
            Fou* fouBlanc = new Fou(blanc, row, col);
            chessTableLabel_.setPosition(row, col, fouBlanc);
            QString whiteFouUnicode = "\u2657";
            addChessItem(fouBlanc, whiteFouUnicode, col * squareSize_, row * squareSize_);
            connect(fouBlanc, SIGNAL(fouClicked(chessitem::Fou*)), this, SLOT(onFouClicked(chessitem::Fou*)));
        }


        else if ((row == 7 && col == 1) || (row == 7 && col == 6)) {
            //add cavalier blanc
            Cavalier* cavalierBlanc = new Cavalier(blanc, row, col);
            chessTableLabel_.setPosition(row, col, cavalierBlanc);
            QString noirCavalierUnicode = "\u2658";
            addChessItem(cavalierBlanc, noirCavalierUnicode, col * squareSize_, row * squareSize_);
            connect(cavalierBlanc, SIGNAL(cavalierClicked(chessitem::Cavalier*)), this, SLOT(onCavalierClicked(chessitem::Cavalier*)));


        }

        else if (((row == 7 && col == 2) || (row == 7 && col == 5)) && mode == mode1) {
            Fou* fouBlanc = new Fou(blanc, row, col);
            chessTableLabel_.setPosition(row, col, fouBlanc);
            QString whiteFouUnicode = "\u2657";
            addChessItem(fouBlanc, whiteFouUnicode, col * squareSize_, row * squareSize_);
            connect(fouBlanc, SIGNAL(fouClicked(chessitem::Fou*)), this, SLOT(onFouClicked(chessitem::Fou*)));


        }

        else if (((row == 7 && col == 2) || (row == 7 && col == 5)) && mode == mode2) {
            //add tour blanc
            Tour* tourBlanc = new Tour(blanc, row, col);
            chessTableLabel_.setPosition(row, col, tourBlanc);
            QString whiteTourUnicode = "\u2656";
            addChessItem(tourBlanc, whiteTourUnicode, col * squareSize_, row * squareSize_);
            connect(tourBlanc, SIGNAL(tourClicked(chessitem::Tour*)), this, SLOT(onTourClicked(chessitem::Tour*)));


        }

        else if (row == 7 && col == 4) {
            try {
                kingBlanc = new King(blanc, row, col);
                chessTableLabel_.setPosition(row, col, kingBlanc);
                QString whiteKingUnicode = "\u2654";
                addChessItem(kingBlanc, whiteKingUnicode, col * squareSize_, row * squareSize_);
                connect(kingBlanc, SIGNAL(kingClicked(chessitem::King*)), this, SLOT(onKingClicked(chessitem::King*)));
            }



            catch (std::runtime_error e) {
                QMessageBox messageBox;
                messageBox.critical(0, "Vous avez ajouter plus de 2 roi",
                    e.what());
            }
        }

        else if (row == 7 && col == 3) {
            //add reine blanc
            Reine* reineBlanche = new Reine(blanc, row, col);
            chessTableLabel_.setPosition(row, col, reineBlanche);
            QString whiteReineUnicode = "\u2655";
            addChessItem(reineBlanche, whiteReineUnicode, col * squareSize_, row * squareSize_);
            connect(reineBlanche, SIGNAL(reineClicked(chessitem::Reine*)), this, SLOT(onReineClicked(chessitem::Reine*)));

        }
        else if (row == 6) {
            Pion* pion = new Pion(blanc, row, col);
            chessTableLabel_.setPosition(row, col, pion);
            QString whitePawnUnicode = "\u2659";
            addChessItem(pion, whitePawnUnicode, col * squareSize_, row * squareSize_);
            connect(pion, SIGNAL(pionClicked(chessitem::Pion*)), this, SLOT(onPionClicked(chessitem::Pion*)));

        }

    }


    void MainGui::setChessBoard(int mode) {
        const int squareSize_ = 50;
        const int numRows = 8;
        const int numCols = 8;


        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                QGraphicsRectItem* square = new QGraphicsRectItem(
                    col * squareSize_, row * squareSize_,
                    squareSize_, squareSize_);

                square->setBrush((row + col) % 2 == 0 ?
                    Qt::lightGray : Qt::darkGray);

                m_scene->addItem(square);
                m_squares[row][col] = square;
                addPiece(row, col, mode);
            }
        }
    }


    void MainGui::addChessItem(Piece* label, QString pawnUnicode, int posX, int posY) {
        label->setText(pawnUnicode);
        label->setFont(QFont("Arial", squareSize_ / 1.5)); 
        label->move(posX, posY);
        QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget();
        label->setAttribute(Qt::WA_TranslucentBackground, true);
        proxy->setWidget(label);
        m_scene->addItem(proxy);
    }


    void MainGui::removeChessItem(Piece* piece) {
        if (piece != nullptr) {
            QGraphicsProxyWidget* proxy = piece->graphicsProxyWidget();
            if (proxy != nullptr) {
                m_scene->removeItem(proxy);
                piece = nullptr;
                delete piece;
            }
        }
    }


    void MainGui::highlightSquare(int row, int col, QColor color) {

        if (row < 0 || row > 7 || col < 0 || col > 7) { 

            return;
        }

 
        Piece* piece = chessTableLabel_.getPieceAtPosition(row, col);


        if (piece != nullptr) {

            if (piece->getColor() != m_currentColor) { 

                RedChessSquare* redSquare = new RedChessSquare(row, col, squareSize_, piece);
                QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget();
                proxy->setWidget(redSquare);
                m_scene->addItem(proxy);
                highlightedSquares_.append(redSquare);
                connect(redSquare, SIGNAL(RedSquareClicked(RedChessSquare*)), this, SLOT(onRedSquareClicked(RedChessSquare*)));
            }
            else {
                return;
            }
        }

        RedChessSquare* redSquare = new RedChessSquare(row, col, squareSize_, nullptr);
        QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget();
        proxy->setWidget(redSquare);
        m_scene->addItem(proxy);
        highlightedSquares_.append(redSquare);
        connect(redSquare, SIGNAL(RedSquareClicked(RedChessSquare*)), this, SLOT(onRedSquareClicked(RedChessSquare*)));
    }

    void MainGui::removeHighlighting() {
        for (auto rect : highlightedSquares_) {
            rect->deleteLater();
        }
        highlightedSquares_.clear();
    }

    void MainGui::refreshSelectedPiece() {
        m_selectedPiece = nullptr;
    }

    void MainGui::onPionClicked(chessitem::Pion* pion) {
        if (pion->getColor() == m_currentColorTurn) {
            if (pion->getColor() != m_currentColorTurn) {
                return;
            }
            chessitem::King* currentKing = (pion->getColor() == "Blanc") ? kingBlanc : kingNoir;

            removeHighlighting();
            refreshSelectedPiece();
            oldPosX = pion->y() / squareSize_;
            oldPosY = pion->x() / squareSize_;

            if (pion == nullptr) {
                return;
            }
            std::vector<std::vector<bool>> validMoves = pion->getValidMove();

            //// Highlight the valid moves
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    if (validMoves[row][col]) {
                        // Make a hypothetical move and check if it puts the king in check
                        if (!simulateMoveAndCheck(pion, oldPosX, oldPosY, row, col, pion->getColor())) {
                            highlightSquare(row, col, Qt::red);
                        }
                    }
                }
            }

            m_selectedPiece = pion;

        }
        else {
            QMessageBox msgBox;
            QString texte = m_currentColor;
            msgBox.setText("It's not your turn to play.");
            msgBox.exec();
        }
    }

    bool MainGui::simulateMoveAndCheck(Piece* piece, int oldRow, int oldCol, int newRow, int newCol, const QString& kingColor) {
        Piece* capturedPiece = chessTableLabel_.getPieceAtPosition(newRow, newCol);
        chessTableLabel_.setPosition(newRow, newCol, piece);
        chessTableLabel_.setPosition(oldRow, oldCol, nullptr);

        bool kingInCheck;
        if (piece->isKing()) {
            kingInCheck = isSquareAttacked(newRow, newCol, kingColor == "Blanc" ? "Noir" : "Blanc");
        }
        else {
            kingInCheck = isKingColorInCheck(kingColor);
        }

        chessTableLabel_.setPosition(oldRow, oldCol, piece);
        chessTableLabel_.setPosition(newRow, newCol, capturedPiece);

        return kingInCheck;
    }



    void MainGui::onKingClicked(chessitem::King* king) {


        if (king->getColor() == m_currentColorTurn) {


            removeHighlighting();
            refreshSelectedPiece();
            oldPosX = king->y() / squareSize_;
            oldPosY = king->x() / squareSize_;

            if (king == nullptr) {
                return;
            }

            m_currentColor = king->getColor();


            std::vector<std::vector<bool>> validMoves = king->getValidMove();

            //// Highlight the valid moves
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    if (validMoves[row][col]) {
                        // Make a hypothetical move and check if it puts the king in check
                        if (!simulateMoveAndCheck(king, oldPosX, oldPosY, row, col, king->getColor())) {
                            highlightSquare(row, col, Qt::red);
                        }
                    }
                }
            }

            m_selectedPiece = king;

        }

        else {
            QMessageBox msgBox;
            QString texte = m_currentColor;
            msgBox.setText("It's not your turn to play.");
            msgBox.exec();
        }

    }

    void MainGui::onFouClicked(chessitem::Fou* fou) {
        if (fou->getColor() == m_currentColorTurn) {

            removeHighlighting();
            refreshSelectedPiece();

            if (fou == nullptr) {
                return;
            }

            int row = fou->y() / squareSize_;
            int col = fou->x() / squareSize_;

            oldPosX = row;
            oldPosY = col;

            m_currentColor = fou->getColor();


            std::vector<std::vector<bool>> validMoves = fou->getValidMove();


            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    if (validMoves[row][col]) {

                        if (!simulateMoveAndCheck(fou, oldPosX, oldPosY, row, col, fou->getColor())) {
                            highlightSquare(row, col, Qt::red);
                        }
                    }
                }
            }

            m_selectedPiece = fou;

        }

        else {
            QMessageBox msgBox;
            QString texte = m_currentColor;
            msgBox.setText("It's not your turn to play.");
            msgBox.exec();
        }
    }




    void MainGui::onRedSquareClicked(RedChessSquare* square) {

        int row = square->row();
        int col = square->col();
        int size = square->size();

        if (row < 0 || row > 7 || col < 0 || col > 7)
            return;


        if (m_selectedPiece != nullptr) {
            if (chessTableLabel_.getPieceAtPosition(row, col) != nullptr) {
                //remove the eated chess piece
                chessTableLabel_.getPieceAtPosition(row, col)->hide();
                chessTableLabel_.setPosition(row, col, nullptr);
            }
            //move the current piece
            m_selectedPiece->move(col * size, row * size);
            chessTableLabel_.setPosition(row, col, m_selectedPiece);
            m_squares[row][col]->setZValue(-1);
            m_currentColor = "";
        }

        chessTableLabel_.setPosition(oldPosX, oldPosY, nullptr);

        removeHighlighting();

        bool isInCheck = isKingInCheck();
        bool isInCheckmate = isKingInCheckmate();

        if (isInCheckmate) {
            QMessageBox msgBox;
            if (m_currentColorTurn == "Blanc") {
                msgBox.setText("Les Blancs ont gagné !");
            }
            else {
                msgBox.setText("Les Noirs ont gagné !");
            }
            msgBox.exec();
            qApp->exit();
        }
        else if (isInCheck) {
            QMessageBox msgBox;
            if (m_currentColorTurn == "Blanc") {
                msgBox.setText("Le roi noir est en chec !");
            }
            else {
                msgBox.setText("Le roi blanc est en echec !");
            }
            msgBox.exec();
        }

        if (!isKingInCheck()) {
            if (isStalemate(m_currentColorTurn)) {
                QMessageBox msgBox;
                msgBox.setText("Egalite par stalemate");
                msgBox.exec();
                qApp->exit();
            }
        }

        if (m_selectedPiece->getColor() == "Blanc")
            m_currentColorTurn = "Noir";
        else
            m_currentColorTurn = "Blanc";
        m_selectedPiece = nullptr;


    }

    void MainGui::onTourClicked(chessitem::Tour* tower) {
        if (tower->getColor() == m_currentColorTurn) {
            removeHighlighting();
            refreshSelectedPiece();

            if (tower == nullptr) {
                return;
            }


            m_currentColor = tower->getColor();

            int currentRow = tower->y() / squareSize_;
            int currentCol = tower->x() / squareSize_;

            oldPosX = currentRow;
            oldPosY = currentCol;

            std::vector<std::vector<bool>> validMoves = tower->getValidMove();


            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    if (validMoves[row][col]) {

                        if (!simulateMoveAndCheck(tower, oldPosX, oldPosY, row, col, tower->getColor())) {
                            highlightSquare(row, col, Qt::red);
                        }
                    }
                }
            }

            m_selectedPiece = tower;
        }

        else {
            QMessageBox msgBox;
            QString texte = m_currentColor;
            msgBox.setText("It's not your turn to play.");
            msgBox.exec();
        }
    }

    void MainGui::onCavalierClicked(chessitem::Cavalier* knight) {
        if (knight->getColor() == m_currentColorTurn) {

            removeHighlighting();
            refreshSelectedPiece();

            if (knight == nullptr) {
                return;
            }

            int currentRow = knight->y() / squareSize_;
            int currentCol = knight->x() / squareSize_;

            oldPosX = currentRow;
            oldPosY = currentCol;

            std::vector<std::vector<bool>> validMoves = knight->getValidMove();


            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    if (validMoves[row][col]) {
 
                        if (!simulateMoveAndCheck(knight, oldPosX, oldPosY, row, col, knight->getColor())) {
                            highlightSquare(row, col, Qt::red);
                        }
                    }
                }
            }


            m_currentColor = knight->getColor();
            m_selectedPiece = knight;
        }

        else {
            QMessageBox msgBox;
            QString texte = m_currentColor;
            msgBox.setText("It's not your turn to play.");
            msgBox.exec();
        }
    }

    void MainGui::onReineClicked(chessitem::Reine* queen) {
        if (queen->getColor() == m_currentColorTurn) {
            removeHighlighting();
            refreshSelectedPiece();

            if (queen == nullptr) {
                return;
            }

            int row = queen->y() / squareSize_;
            int col = queen->x() / squareSize_;

            oldPosX = row;
            oldPosY = col;

            std::vector<std::vector<bool>> validMoves = queen->getValidMove();

  
            for (int row = 0; row < 8; ++row) {
                for (int col = 0; col < 8; ++col) {
                    if (validMoves[row][col]) {

                        if (!simulateMoveAndCheck(queen, oldPosX, oldPosY, row, col, queen->getColor())) {
                            highlightSquare(row, col, Qt::red);
                        }
                    }
                }
            }

            m_selectedPiece = queen;
        }

        else {
            QMessageBox msgBox;
            QString texte = m_currentColor;
            msgBox.setText("It's not your turn to play.");
            msgBox.exec();
        }
    }

    bool MainGui::isStalemate(const QString& currentColor) {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                Piece* piece = chessTableLabel_.getPieceAtPosition(row, col);

                if (piece != nullptr && piece->getColor() != currentColor) {
                    std::vector<std::vector<bool>> validMoves = piece->getValidMove();

                    for (int newRow = 0; newRow < 8; ++newRow) {
                        for (int newCol = 0; newCol < 8; ++newCol) {
                            if (validMoves[newRow][newCol]) {
                                if (!simulateMoveAndCheck(piece, row, col, newRow, newCol, piece->getColor())) {
                                    return false; 
                                }
                            }
                        }
                    }
                }
            }
        }

        return true; 
    }




    bool MainGui::isSquareAttacked(int row, int col, const QString& attackingColor) {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece* piece = chessTableLabel_.getPieceAtPosition(r, c);
                if (piece != nullptr && piece->getColor() == attackingColor) {
                    std::vector<std::vector<bool>> validMoves = piece->getValidMove();
                    if (validMoves[row][col]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }


    bool MainGui::isKingColorInCheck(const QString& kingColor) {
        // Determine which king to check based on the kingColor
        chessitem::King* kingToCheck = (kingColor == "Blanc") ? kingBlanc : kingNoir;

        int row = kingToCheck->y() / squareSize_;
        int col = kingToCheck->x() / squareSize_;
        QString attackingColor = (kingColor == "Blanc") ? "Noir" : "Blanc";

        return isSquareAttacked(row, col, attackingColor);
    }

    bool MainGui::isKingInCheck() {
        QString kingColor = m_currentColorTurn == "Blanc" ? "Noir" : "Blanc";
        QString attackingColor = m_currentColorTurn;

        chessitem::King* currentKing = kingColor == "Blanc" ? kingBlanc : kingNoir;

        int kingRow = currentKing->y() / squareSize_;
        int kingCol = currentKing->x() / squareSize_;
        bool result = isSquareAttacked(kingRow, kingCol, attackingColor);
        return result;
    }

    bool MainGui::isKingInCheckmate() {
        QString kingColor = m_currentColorTurn == "Blanc" ? "Noir" : "Blanc";
        chessitem::King* currentKing = kingColor == "Blanc" ? kingBlanc : kingNoir;

        int kingRow = currentKing->y() / squareSize_;
        int kingCol = currentKing->x() / squareSize_;


        if (!isSquareAttacked(kingRow, kingCol, m_currentColorTurn)) {
            return false;
        }


        std::vector<std::vector<bool>> kingMoves = currentKing->getValidMove();
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (kingMoves[row][col]) {

                    Piece* tempPiece = chessTableLabel_.getPieceAtPosition(row, col);
                    chessTableLabel_.setPosition(row, col, currentKing);
                    chessTableLabel_.setPosition(kingRow, kingCol, nullptr);


                    bool stillInCheck = isSquareAttacked(row, col, m_currentColorTurn);

                    // Undo the temporary move
                    chessTableLabel_.setPosition(kingRow, kingCol, currentKing);
                    chessTableLabel_.setPosition(row, col, tempPiece);

                    if (!stillInCheck) {
                        return false;
                    }
                }
            }
        }


        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece* piece = chessTableLabel_.getPieceAtPosition(r, c);
                if (piece != nullptr && piece->getColor() == kingColor && !(piece->isKing())) {
                    std::vector<std::vector<bool>> validMoves = piece->getValidMove();
                    for (int row = 0; row < 8; row++) {
                        for (int col = 0; col < 8; col++) {
                            if (validMoves[row][col]) {
                                Piece* tempPiece = chessTableLabel_.getPieceAtPosition(row, col);

                                chessTableLabel_.setPosition(row, col, piece);
                                chessTableLabel_.setPosition(r, c, nullptr);

                                bool stillInCheck = isSquareAttacked(kingRow, kingCol, m_currentColorTurn);

                                chessTableLabel_.setPosition(r, c, piece);
                                chessTableLabel_.setPosition(row, col, tempPiece);

                                if (!stillInCheck) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }



}