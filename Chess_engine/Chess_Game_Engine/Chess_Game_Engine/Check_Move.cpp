// Check_Move.cpp
#include "Check_Move.h"
#include "custom_picturebox.h" 

Check_Move::Check_Move()
{
    move_counter = 0;  // Initialize the move counter to 0
}

// Implementation of the reset_pb method
void Check_Move::reset_pb(array<array<custom_picturebox^>^>^ pictureBoxes)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (pictureBoxes[i][j]->ImageLocation == "C:\\Users\\USER\\Desktop\\on_move.png")
                pictureBoxes[i][j]->ImageLocation = "";
        }
    }
}