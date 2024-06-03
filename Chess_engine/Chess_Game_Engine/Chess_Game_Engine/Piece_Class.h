#pragma once
#include "custom_picturebox.h"


using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class Piece_Class : public custom_picturebox
{
	Piece_Class(int initialX, int initialY,String^ pieceColor, String^ pieceType)
	{
		piece_X = initialX;
		piece_Y = initialY;
		color = pieceColor;
		type = pieceType;
		refresh_position();
		load_image();
	}
public:

	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void check_move() = 0;
public:

	void refresh_position()
	{
		int squareSize = 460 / 8;
		this->Location = System::Drawing::Point(piece_X * squareSize, piece_Y * squareSize);
	}
	void load_image()
	{
		
	}
protected:

	int piece_X;
	int piece_Y; 
	String^ color;
	String^ type;
};

