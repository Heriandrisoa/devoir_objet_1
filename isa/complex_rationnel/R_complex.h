#ifndef R_COMPLEX
#define R_COMPLEX
#include "../rationnel/Fractions.h"
namespace hisa
{
    class R_complex
    {
        private:
            Fractions m_reel;
            Fractions m_imaginaire;
        public:
            R_complex(Fractions reel=Fractions(),Fractions imaginaire=Fractions());
            ~R_complex();
            void setReel(Fractions& b);
            void setImaginaire(Fractions& b);
            Fractions getReel();
            Fractions getImaginaire();
            R_complex add(R_complex& b);
            R_complex sub(R_complex& b);
            R_complex mult(R_complex& b);
            R_complex div(R_complex& b);
            void display() const;
    };
}
#endif