#pragma once
#include "InitializeChessBoard.h"
#include <vector>

using namespace System;
using namespace System::Collections::Generic;

namespace ChessGameEngine {
    {
        // Deklaracja klasy pośredniczącej
        public ref class ChessBoardWrapper {
        private:
            ChessGameEngine::ChessBoard* chessBoard; // Wskaźnik na obiekt klasy ChessBoard

        public:
            // Konstruktor
            ChessBoardWrapper();

            // Destruktor
            ~ChessBoardWrapper();

            // Metoda do pobierania planszy w formie listy dwuwymiarowej
           
        };
    }
}