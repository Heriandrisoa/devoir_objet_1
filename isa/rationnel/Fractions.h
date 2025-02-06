#ifndef FRACTIONS
#define FRACTIONS
#include <string>
namespace hisa
{
	class Fractions{
		public:
			Fractions(int numerateur=0,int denominateur=1);
			void denominateurise(Fractions& b); //mampitovy denominateur
			void inverse();
			void simplify();
			int getNum();
			int getDenum();
			void setNum(int num);
			void setDenum(int denum);
			void set(int num,int denum);
			Fractions add(Fractions b);
			Fractions sub(Fractions b);
			Fractions mult(Fractions b);
			Fractions div(Fractions b);
			void display() const;
			~Fractions();
			private:
			int m_numerateur;
			int m_denominateur;
	};

	Fractions sum(Fractions  a,Fractions b);
	Fractions sous(Fractions  a,Fractions b);
	Fractions mult(Fractions a, Fractions b);
	Fractions div(Fractions a, Fractions b);	
}

#endif
