#include "Fractions.h"
#include <string>
#include <iostream>
#include "manipulation.h"

using namespace hisa;

Fractions::Fractions(int numerateur,int denominateur):m_numerateur(numerateur),m_denominateur(denominateur)
{
	checking(m_numerateur,m_denominateur);
	simplify();
}

void Fractions::simplify()
{
	int pgcd=PGCD(m_numerateur,m_denominateur);
	m_numerateur/=pgcd;
	m_denominateur/=pgcd;
}


void Fractions::denominateurise(Fractions& b)
{
	int ppcm=PPCM(m_denominateur,b.m_denominateur);
	int a_multiplier_a=ppcm/m_denominateur;
	int a_multiplier_b=ppcm/b.m_denominateur;
	m_denominateur*=a_multiplier_a;
	b.m_denominateur*=a_multiplier_b;
	m_numerateur*=a_multiplier_a;
	b.m_numerateur*=a_multiplier_b;
	
}

int  Fractions::getNum()
{
	return m_numerateur;
}

int  Fractions::getDenum(){
	return m_denominateur;
}
 
void Fractions::setNum(int num)
{
	m_numerateur=num;
}
void Fractions::setDenum(int denum){
	m_denominateur=denum;
}
void Fractions::set(int num,int denum){
	m_numerateur=num;
	m_denominateur=denum;
}



void Fractions::inverse(){
	int tmp=m_numerateur;
	m_numerateur=m_denominateur;
	m_denominateur=tmp;
}


Fractions Fractions::add(Fractions b)
{
	denominateurise(b);
	m_numerateur+=b.m_numerateur;
	simplify();
	return *this;
}

Fractions Fractions::sub(Fractions b)
{
	denominateurise(b);
	m_numerateur-=b.m_numerateur;
	simplify();
	return *this;
}

Fractions Fractions::mult(Fractions b)
{
	m_numerateur*=b.m_numerateur;
	m_denominateur*=b.m_denominateur;
	simplify();
	return *this;

}

Fractions Fractions::div(Fractions  b)
{
	b.inverse();
	m_numerateur*=b.m_numerateur;
	m_denominateur*=b.m_denominateur;
	simplify();
	return *this;
}

void Fractions::display() const
{
	if(m_numerateur==0)
		std::cout<<"0";
	else

		std::cout<<m_numerateur<<"/"<<m_denominateur;
}
Fractions::~Fractions()
{

}