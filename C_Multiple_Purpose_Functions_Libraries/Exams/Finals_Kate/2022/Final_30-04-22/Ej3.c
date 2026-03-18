#include<stdio.h>

int main(void)
{





    return;
}


void print_stats( int counts[], int total)
{
    int counts_aux[sizeof(counts)/sizeof(int)];
    int i;

    for( i = 0; i < (sizeof(counts)/sizeof(int)); i++ )
        counts_aux[i] = total - counts[i];

    printf("Channel #0\t%.2f%\n", (counts_aux[0] * 100) / total);
    printf("Channel #1\t%.2f%\n", (counts_aux[1] * 100) / total);
    printf("Channel #2\t%.2f%\n", (counts_aux[2] * 100) / total);
    printf("Channel #3\t%.2f%\n", (counts_aux[3] * 100) / total);
    printf("Channel #4\t%.2f%\n", (counts_aux[4] * 100) / total);
    printf("Channel #5\t%.2f%\n", (counts_aux[5] * 100) / total);
    printf("Channel #6\t%.2f%\n", (counts_aux[6] * 100) / total);
    printf("Channel #7\t%.2f%\n", (counts_aux[7] * 100) / total);
    printf("Channel #8\t%.2f%\n", (counts_aux[8] * 100) / total);
    printf("Channel #9\t%.2f%\n", (counts_aux[9] * 100) / total);
    printf("Channel #10\t%.2f%\n", (counts_aux[10] * 100) / total);
    printf("Channel #11\t%.2f%\n", (counts_aux[11] * 100) / total);
    printf("Channel #12\t%.2f%\n", (counts_aux[12] * 100) / total);
    printf("Channel #13\t%.2f%\n", (counts_aux[13] * 100) / total);
    printf("Channel #14\t%.2f%\n", (counts_aux[14] * 100) / total);
    printf("Channel #15\t%.2f%\n", (counts_aux[15] * 100) / total);

    return;
}
