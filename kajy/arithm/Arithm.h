#ifndef __ARITHM
#define __ARITHM
#include "../complex_rationnel/R_complex.h"
#include "../rationnel/Fractions.h"
#include "../complex/Complex.h" 

enum type{
    RATIONNEL,
    R_COMPLEX_TYPE,
    COMPLEX_TYPE
};
namespace hisa
{
    class Arithm //afaka maka ny forme an'ny afaka additionnena rehetra
    {
        public:
           //afaka atao int..Complex ny anatiny
            Arithm();
            Arithm(int a);
            Arithm(R_complex a);
            Arithm(Complex a);
            Arithm(Fractions a);
            
            void set(int a);
            void set(Fractions a);
            void set(R_complex a);
            void set(Complex a);

            Complex get();
            R_complex get();
            Fractions get();
            int get();

            //afaka aditionnena am type rehetra koa
            void add(int a);
            void add(const R_complex a);
            void add(const Complex a);
            void add(const Fractions a);

            ~Arithm();
        private:
            R_complex m_r_complex;
            Complex m_complex;
            Fractions m_rationnel;
            int m_type;
    };   
}

#endif
