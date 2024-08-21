#pragma once

ref class Check_Move
{
public:
    int move_counter;

    // Constructor
    Check_Move();

    void reset_pb(array<array<custom_picturebox^>^>^ pictureBoxes);
};