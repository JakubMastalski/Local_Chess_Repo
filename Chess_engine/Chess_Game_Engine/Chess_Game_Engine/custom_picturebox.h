
namespace ChessGameEngine {
    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    ref class custom_picturebox :
        public System::Windows::Forms::PictureBox
    {
    public:
        custom_picturebox() {};
        
        virtual property Color BackColor
        {
            Color get() override
            {
                return PictureBox::BackColor;
            }
            void set(Color color) override
            {
                
            }
        }

    };
};
