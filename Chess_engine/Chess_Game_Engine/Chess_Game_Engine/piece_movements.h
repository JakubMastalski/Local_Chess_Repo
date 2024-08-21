#pragma once

#include "custom_picturebox.h"
#include <array>

using namespace System;
using namespace System::Drawing;

public ref class PieceMovements
{
private:
    // Metody sprawdzaj¹ce ruchy dla ró¿nych figur
    bool check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
  //  bool check_Bishopmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
  //  bool check_Rookmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
  //  bool check_Queenmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
   // bool check_Kingmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
    //bool check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
};