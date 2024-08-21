#include "MouseOperations.h"
#include "BoardForm.h"
#include "custom_picturebox.h"

void MouseOperations::HandlePieceSelection(BoardForm^ boardForm, ISelectablePictureBox^ selectedPictureBox)
{
    if (selectedPictureBox != nullptr && selectedPictureBox->ImageLocation != "")
    {
        if (boardForm->promote_panel->Visible == false)
        {
            boardForm->piece_clicked = true;
            selectedPictureBox->Capture = true;
            selectedPictureBox->BringToFront();
            boardForm->new_selected = selectedPictureBox;
            boardForm->current_piece = selectedPictureBox->check_piece(); 
            boardForm->current_color = selectedPictureBox->check_color(); 
            boardForm->start_location = selectedPictureBox->Location;
            boardForm->file_path = selectedPictureBox->ImageLocation;
            selectedPictureBox->Tag = "Dragging";
        }
    }
}