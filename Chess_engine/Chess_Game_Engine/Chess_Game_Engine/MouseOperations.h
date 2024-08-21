#pragma once

// Forward declaration to avoid circular dependency
ref class BoardForm;
ref class custom_picturebox;

#include <cmath>
#include <algorithm>
#include <math.h>

public ref class MouseOperations
{
private:
    // Method now accepts a reference to BoardForm
    void HandlePieceSelection(BoardForm^ boardForm, custom_picturebox^ selectedPictureBox);
};