#include "Cavalier.hpp"
#include "Piece.hpp"
#include "Pion.hpp" 
#include "King.hpp" 
#include "Fou.hpp"
#include "Tour.hpp"
#include "Cavalier.hpp"
#include "Reine.hpp"
#include "MainGui.hpp"


#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

#include "Cavalier.hpp"
using namespace chessitem;
using namespace gui;


TEST(King, validMoves) {
	int col = 3;
	int row = 3;
	int squareSize = 50;
	QString color = "Blanc";
	King king(color,row, col);

	king.move(row*squareSize, col*squareSize);
	std::vector<std::vector<bool>> validMoves = king.getValidMove();

	EXPECT_EQ(validMoves[3][4], true);
	EXPECT_TRUE(validMoves[2][2]);
	EXPECT_TRUE(validMoves[2][3]);
	EXPECT_TRUE(validMoves[2][4]);
	EXPECT_TRUE(validMoves[3][2]);
	EXPECT_TRUE(validMoves[3][4]);
	EXPECT_TRUE(validMoves[4][2]);
	EXPECT_TRUE(validMoves[4][3]);
	EXPECT_TRUE(validMoves[4][4]);
	
}

TEST(Fou, validMoves) {
	int col = 3;
	int row = 3;
	int squareSize = 50;
	QString color = "Blanc";
	Fou fou(color, row, col);

	fou.move(row * squareSize, col * squareSize);
	std::vector<std::vector<bool>> validMoves = fou.getValidMove();

	EXPECT_TRUE(validMoves[2][2]);
	EXPECT_TRUE(validMoves[1][1]);
	EXPECT_TRUE(validMoves[0][0]);
	EXPECT_TRUE(validMoves[2][4]);
	EXPECT_TRUE(validMoves[1][5]);
	EXPECT_TRUE(validMoves[4][2]);
	EXPECT_TRUE(validMoves[5][1]);
	EXPECT_TRUE(validMoves[4][4]);
	EXPECT_TRUE(validMoves[5][5]);
}

TEST(Pion, validMoves) {
	int col = 3;
	int row = 6;
	int squareSize = 50;
	QString color = "Blanc";
	Pion pion(color, row, col);

	pion.move(col * squareSize, row * squareSize);
	std::vector<std::vector<bool>> validMoves = pion.getValidMove();

	EXPECT_TRUE(validMoves[5][3]);
	EXPECT_TRUE(validMoves[4][3]);

	row = 1;
	color = "Noir";
	Pion pion2(color, row, col);


	pion2.move(col * squareSize, row * squareSize);
	std::vector<std::vector<bool>> validMoves2 = pion2.getValidMove();

	EXPECT_TRUE(validMoves2[2][3]);
	EXPECT_TRUE(validMoves2[3][3]);
}

TEST(Reine, validMoves) {
	int col = 3;
	int row = 3;
	int squareSize = 50;
	QString color = "Blanc";
	Reine queen(color, row, col);

	queen.move(col * squareSize, row * squareSize);
	std::vector<std::vector<bool>> validMoves = queen.getValidMove();


	EXPECT_TRUE(validMoves[4][4]); 
	EXPECT_TRUE(validMoves[2][4]); 
	EXPECT_TRUE(validMoves[3][5]); 
	EXPECT_TRUE(validMoves[3][1]); 
}

TEST(Tour, validMoves) {
	int col = 3;
	int row = 3;
	int squareSize = 50;
	QString color = "Blanc";
	Tour rook(color, row, col);

	rook.move(col * squareSize, row * squareSize);
	std::vector<std::vector<bool>> validMoves = rook.getValidMove();


	EXPECT_TRUE(validMoves[3][5]); 
	EXPECT_TRUE(validMoves[3][1]); 
	EXPECT_TRUE(validMoves[1][3]); 
	EXPECT_TRUE(validMoves[5][3]); 
}

TEST(MainGui, isKingInCheck) {

	int mode = 1;
	int initialRowKing = 0;
	int initialColKing = 4;
	int destinationRowKing = 4;
	int destinationColKing = 4;
	int initialRowFou = 7;
	int initialColFou = 2;
	int destinationRowFou = 5;
	int destinationColFou = 5;
	int squareSize = 50;
	MainGui mainGui;
	mainGui.setChessBoard(mode);


	//black king at (4, 4) and a white rook at (5, 5), which puts the black king in check
	Piece* kingNoir = mainGui.getChessTableLabel().getPieceAtPosition(initialRowKing, initialColKing);
	mainGui.getChessTableLabel().setPosition(destinationRowKing, destinationColKing, kingNoir);
	kingNoir->move(destinationRowKing * squareSize, destinationColKing * squareSize);
	mainGui.getChessTableLabel().setPosition(initialRowKing, initialColKing, nullptr);

	Piece* fouBlanc = mainGui.getChessTableLabel().getPieceAtPosition(initialRowFou, initialColFou);
	mainGui.getChessTableLabel().setPosition(destinationRowFou, destinationColFou, fouBlanc);
	fouBlanc->move(destinationRowFou * squareSize, destinationColFou * squareSize);
	mainGui.getChessTableLabel().setPosition(initialRowFou, initialColFou, nullptr);

	// Ensure the black king is in check
	QString noir = "Noir";
	QString blanc = "Blanc";


	//  white king is in check
	mainGui.setCurrentColorTurn(blanc);
	EXPECT_TRUE(mainGui.isKingInCheck());

	//  white king is not in check
	mainGui.setCurrentColorTurn(noir);
	EXPECT_FALSE(mainGui.isKingInCheck());

	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			mainGui.getChessTableLabel().setPosition(row, col, nullptr);
		}
	}
}

TEST(MainGui, isKingInCheckMate) {
	int mode = 1;
	int initialRowKingNoir = 0;
	int initialColKingNoir = 4;
	int initialRowQueenBlanc = 0;
	int initialColQueenBlanc = 3;
	int initialRowKingBlanc = 7;
	int initialColKingBlanc = 4;
	int destinationRowKingBlanc = 2;
	int destinationColKingBlanc = 6;
	int squareSize = 50;
	MainGui mainGui;
	mainGui.setChessBoard(1);


	// Place the white queen at (4, 7)
	Piece* queenBlanc = mainGui.getChessTableLabel().getPieceAtPosition(7, 3);
	mainGui.getChessTableLabel().setPosition(3, 7, queenBlanc);
	queenBlanc->move(7 * squareSize, 3 * squareSize);
	//clear the pawn in (1,6) and (1,5)
	mainGui.getChessTableLabel().setPosition(7,3, nullptr);
	mainGui.getChessTableLabel().setPosition(1, 5, nullptr);
	mainGui.getChessTableLabel().setPosition(1, 6, nullptr);


	QString noir = "Noir";
	QString blanc = "Blanc";

	mainGui.setCurrentColorTurn(blanc);
	EXPECT_TRUE(mainGui.isKingInCheck());
	EXPECT_TRUE(mainGui.isKingInCheckmate());

	// Clear the board
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			mainGui.getChessTableLabel().setPosition(row, col, nullptr);
		}
	}
}



#endif // TEST


