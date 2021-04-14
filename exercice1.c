#include <stdio.h>
#include <stdarg.h>

// Exercice 1

int max(int nombre,...)
{
	int variable; // C'est la variable courante de la liste.
	int i;
	int max=0;
	va_list li;
	va_start(li,nombre);
	for(i=0;i<nombre;i++)
	{
		variable=va_arg(li,int);
		
		if(variable>max)
		{
			max=variable;
		}
	}
	va_end(li);
	return max;
}



int main(int argc, char * argv[])
{
	int maximum=max(5,9,4,487,2,6,45);
	printf("La valeur maximale est : %d\n", maximum);

return 0;
}
