#include "Arithm.h"
using namespace hisa;
Arithm::Arithm(){
    
}
Arithm::Arithm(int a):m_type(0)
{
    m_rationnel.setNum(a);
    m_rationnel.setDenum(1);
}

Arithm::Arithm(R_complex a):m_r_complex(a),m_type(1)
{

}

Arithm::Arithm(Complex a):m_complex(a),m_type(2)
{

}

Arithm::Arithm(Fractions a):m_rationnel(a),m_type(0)
{

}

void Arithm::add(int a)
{

    switch(m_type)
    {
        case RATIONNEL:
            m_rationnel.add(Fractions(a,1));
            break;
        case R_COMPLEX_TYPE:
            m_r_complex.add_rationel(Fractions(a,1));
            break;
        case COMPLEX_TYPE:
            m_complex.add_int(a);
            break;
        default:
            break;
    }
}
void Arithm::add(R_complex a)
{

    switch(m_type)
    {
        case RATIONNEL:
            m_type=R_COMPLEX_TYPE;
            a.add_rationel(m_rationnel);
            m_r_complex=a;
            break;
        case R_COMPLEX_TYPE:
            m_r_complex.add(a);
            break;
        case COMPLEX_TYPE:
            m_type=R_COMPLEX_TYPE;
            m_r_complex=a;
            m_r_complex.add_complexe(m_complex);
            break;
        default:
            break;
    }
}
void Arithm::add(Complex a)
{
    switch(m_type)
    {
        case RATIONNEL:
            m_type=R_COMPLEX_TYPE;
            m_r_complex=R_complex(Fractions(a.getReel(),1),Fractions(a.getImaginaire(),1));
            m_r_complex.add_rationel(m_rationnel);
            break;

        case R_COMPLEX_TYPE:
            m_type=R_COMPLEX_TYPE;
            m_r_complex.add_complexe(a);
            break;
        case COMPLEX_TYPE:
            m_complex.add(a);
            break;
        default:
            break;
    }
}

void Arithm::add(Fractions a)
{

    switch(m_type)
    {
        case RATIONNEL:
            m_rationnel.add(a);
            break;
        case R_COMPLEX_TYPE:
            m_r_complex.add_rationel(a);
            break;
        case COMPLEX_TYPE:
            m_type=R_COMPLEX_TYPE;
            a.add(m_r_complex.getReel());
            m_r_complex.setReel(a);
            break;
        default:
            break;
    }
}

Arithm::~Arithm()
{

}
