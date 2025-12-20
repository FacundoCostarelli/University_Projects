//Algoritmo

int	i,aux;
int	numbersread = 0;
int	swapped;
int numbers[1000];
do {
		swapped = 0;
		for(i = 0; i < numbersread - 1; i++)
			if(numbers[i] > numbers[i + 1]) {
				swapped = 1;
				aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
			}
	} while(swapped);
	printf("The sorted values: ");
	for(i = 0; i < numbersread; i++)
		printf("%d ",numbers[i]);
	printf("\n");
