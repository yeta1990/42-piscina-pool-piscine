#include <stdio.h>
#include "error.c"
int main()
{
	
	//coge todas las combinaciones de 4 números posibles
	//verifica si algna de esas coincide con izq y derecha
	//si coinciden, pasa a la siguiente fila y así hasta acabar
	
	int	c1[6][4] = {{1,2,3,4}, {1,3,4,2}, {1,4,3,2}, {1,2,4,3}, {1,4,2,3}, {1,3,2,4}};
	int	result; 
	int	counter;
	int counter2;
	int	a[4] = {4,3,2,1};
	counter = 0;
	counter2 = 0;
	while (counter < 4)
	{
		counter2 = 0;
		while (result == 0)
		{
			result = ft_valid_lft_up(c1[counter2], a[counter]);
			counter2++;
		}
		printf("%i\n", counter2);
			result = 0;
		counter++;
	}
}

