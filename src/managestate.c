#include <stdio.h>
#include <stdlib.h>


char** managestate(char** table,int enditeration, int length, int width){
    int i;
    int j;
    int countneightbours = 0;
    int iteration_now = 0;

    int** lifetable = (int**)malloc(length * sizeof(int*));
    for(i = 0; i++; i < length){
        lifetable[i]=(int*)malloc(width * sizeof(int));
    }

    while (iteration_now < enditeration) {

        for (i = 0; i < width; i++) {

            for (j = 0; j < length; j++) {

                if (table[i - 1][j - 1] == '0' && i > 0 && j > 0) countneightbours++;
                if (table[i][j - 1] == '0' && j > 0) countneightbours++;
                if (table[i + 1][j - 1] == '0' && j > 0 && i < width - 1) countneightbours++;

                if (table[i - 1][j] == '0' && i > 0 && j > 0) countneightbours++;
                if (table[i + 1][j] == '0' && j > 0 && i < width - 1) countneightbours++;

                if (table[i - 1][j + 1] == '0' && i > 0 && j < length - 1) countneightbours++;
                if (table[i][j + 1] == '0' && j < length - 1) countneightbours++;
                if (table[i + 1][j + 1] == '0' && j < length - 1 && i < width - 1) countneightbours++;

                lifetable[i][j] = countneightbours;
                countneightbours = 0;


            }
        }
        for (i = 0; i < width; i++) {

            for (j = 0; j < length; j++) {

                if (table[i][j] == '0' && (lifetable[i][j] == 2 || lifetable[i][j] == 3)) table[i][j] = '0';
                if (table[i][j] == '0' && (lifetable[i][j] != 2 || lifetable[i][j] != 3)) table[i][j] = '#';
                if (table[i][j] == '#' && lifetable[i][j] == 3) table[i][j] = '0';

            }
        }
        iteration_now++;
    }
    return table;
}