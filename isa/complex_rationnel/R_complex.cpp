#include "R_complex.h"
#include <iostream>
using namespace hisa;

R_complex::R_complex(Fractions reel,Fractions imaginaire):m_reel(reel),m_imaginaire(imaginaire)
{

}

R_complex::~R_complex()
{

}

void R_complex::setReel(Fractions& b)
{
    m_reel.setNum(b.getNum());
    m_reel.setDenum(b.getDenum());
}

void R_complex::setImaginaire(Fractions& b)
{
    m_imaginaire.setNum(b.getNum());
    m_imaginaire.setDenum(b.getDenum());
}

Fractions R_complex::getReel()
{
    return m_reel;
}

Fractions R_complex::getImaginaire()
{
    return m_imaginaire;
}

R_complex R_complex::add(R_complex& b)
{
    m_reel.add(b.getReel());
    m_imaginaire.add(b.getImaginaire());
    return *this;
}

R_complex R_complex::sub(R_complex& b)
{
    m_reel.sub(b.getReel());
    m_imaginaire.sub(b.getImaginaire());
    return *this;
}

R_complex R_complex::mult(R_complex& b)
{
    R_complex buff;
    m_reel=m_reel.mult(b.m_reel).sub(m_imaginaire.mult(b.m_imaginaire));
    m_imaginaire=buff.m_imaginaire.mult(b.m_reel).add(buff.m_reel.mult(b.m_imaginaire));
    return *this;

}
R_complex R_complex::div(R_complex& b)
{
    R_complex buff=*this;
    m_reel =  (m_reel.mult(b.m_reel).add(m_imaginaire.mult(b.m_imaginaire))).div((b.m_reel.mult(b.m_reel).add(b.m_imaginaire.mult(b.m_imaginaire))));
    m_imaginaire =  (b.m_reel.mult(buff.m_imaginaire).sub(buff.m_reel.mult(b.m_imaginaire))).div((b.m_reel.mult(b.m_reel).add( b.m_imaginaire.mult(b.m_imaginaire))));
    return *this;
}

void R_complex::display() const
{
    m_reel.display();
    std::cout<<"+"<<"(";
    m_imaginaire.display();
    std::cout<<")i"<<std::endl;
}