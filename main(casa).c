#include <stdio.h>
#include <stdlib.h>

int* FindDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize )
{
    int* result = (int*)malloc( sizeof( int ) * matSize * *matColSize );

    *returnSize = matSize * *matColSize;

    int i = 0, j = 0, k = 0;
    int direcao = 1;    // subindo = 1, descendo = 0

    while ( k < matSize * *matColSize )
    {
        result[k] = mat[i][j];
        k++;

        if ( direcao == 1 )    
        {
            if ( j == *matColSize - 1 )
            {
                i++;
                direcao = 0;
            }
            else if ( i == 0 )
            {
                j++;
                direcao = 0;
            }
            else
            {
                i--;
                j++;
            }
        }
        else   
        {
            if ( i == matSize - 1 )
            {
                j++;
                direcao = 1;
            }
            else if ( j == 0 )
            {
                i++;
                direcao = 1;
            }
            else
            {
                i++;
                j--;
            }
        }
    }

    return result;
}

int main()
{
    int m = 3, n = 3, returnSize;

    int* matColSize = (int*)malloc( sizeof( int ) * m );
    int** mat = (int**)malloc( sizeof( int* ) * m );

    int valores[3][3] =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    for ( int i = 0; i < m; i++ )
    {
        mat[i] = (int*)malloc( sizeof( int ) * n );
        matColSize[i] = n;

        for ( int j = 0; j < n; j++ )
        {
            mat[i][j] = valores[i][j];
        }
    }

    int* resultado = FindDiagonalOrder( mat, m, matColSize, &returnSize );

    printf( "Resultado: " );

    for ( int i = 0; i < returnSize; i++ )
    {
        printf( "%d ", resultado[i] );
    }

    printf( "\n" );

    for ( int i = 0; i < m; i++ )
    {
        free( mat[i] );
    }

    free( mat );
    free( matColSize );
    free( resultado );

    return 0;
}
