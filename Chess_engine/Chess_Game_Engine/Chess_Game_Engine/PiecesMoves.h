#pragma once

#include "custom_picturebox.h"

namespace ChessGameEngine {

    using namespace System;

    public ref class PiecesMoves {
    public:
        PiecesMoves();
        bool check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);

    private:
        bool isWithinBounds;
    };
}
