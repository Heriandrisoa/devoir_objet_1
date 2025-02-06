#include <iostream>
#include "Complex.h"

using namespace hisa;

Complex::Complex(int reel, int imaginaire):m_reel(reel),m_imaginaire(imaginaire){

}

Complex::~Complex()
{

}

int Complex::getReel() const
{
    return m_reel;
}

int Complex::getImaginaire() const
{
    return m_imaginaire;
}

void Complex::setReel(int& r)
{
    m_reel=r;
}

void Complex::setImaginaire(int& i)
{
    m_imaginaire=i;
}

/*---------operateur-----------*/

Complex Complex::add(Complex& b)
{
    m_reel+=b.m_reel;
    m_imaginaire+=b.m_imaginaire;
    return *this;
}

Complex Complex::sub(Complex& b)
{

    m_reel-=b.m_reel;
    m_imaginaire-=b.m_imaginaire;
    return *this;
}

Complex Complex::mult(Complex& b)
{
    Complex buff=*this;
    m_reel=m_reel*b.m_reel-m_imaginaire*b.m_imaginaire;
    
    m_imaginaire=buff.m_imaginaire*b.m_reel+buff.m_reel*b.m_imaginaire;
    return *this;
}

Complex Complex::div(Complex& b)
{
    Complex buff=*this;
    m_reel = (int) (m_reel*b.m_reel+m_imaginaire*b.m_imaginaire)/(b.m_reel*b.m_reel+ b.m_imaginaire*b.m_imaginaire);
    m_imaginaire = (int) (b.m_reel*buff.m_imaginaire-buff.m_reel*b.m_imaginaire)/(b.m_reel*b.m_reel+ b.m_imaginaire*b.m_imaginaire);
    return *this;
}    

/*--operateur--*/


void Complex::display() const
{
    if(m_imaginaire==0)
        std::cout<<m_reel<<std::endl;
    else
    {
        if(m_reel!=0)
        {
            std::cout<<m_reel<<((m_imaginaire>0)?"+":"");
        }   
        if(abs(m_imaginaire)==1)
            std::cout<<((m_imaginaire==1)?"":"-");
        else
            std::cout<<m_imaginaire;    
        std::cout<<"i"<<std::endl;

    }
}