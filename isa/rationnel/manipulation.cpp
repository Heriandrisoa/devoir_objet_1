
#include "manipulation.h"

void checking(int& numerateur,int& denominateur)
{
	if(denominateur<0)
	{
		numerateur*=-1;
		denominateur*=-1;
	}
}

int PPCM(int a,int b)
{
	int pgcd=PGCD(a,b);
	return (a*b)/pgcd;
}

int PGCD(int a,int b)
{
	if(a<b)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
	
	int reste=b,pgcd;
	while(reste!=0)
	{
		pgcd=reste;
		reste=a%b;
		a=b;
		b=reste;
	}
	return pgcd;	
}