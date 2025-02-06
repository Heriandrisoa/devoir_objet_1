#ifndef COMPLEX
#define COMPLEX
namespace hisa
{
    class Complex
    {
        private:
            int m_reel;
            int m_imaginaire;
        public:
            Complex(int reel=0, int imaginaire=0);
            ~Complex();
            int getReel() const;
            int getImaginaire() const;
            void setReel(int& r);
            void setImaginaire(int& i);
            Complex add(Complex& b);
            Complex sub(Complex& b);
            Complex mult(Complex& b);
            Complex div(Complex& b);           
            void display() const;
    };
}
#endif