/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void buildSpiralArr(int **input_array, int *result, int startRow, int startCol, int endRow, int endCol, int *resInd) {
	int i;
	if (startRow > endRow || startCol > endCol)
		return;
	for (i = startCol; i <= endCol; i++, (*resInd)++)
		result[*resInd] = input_array[startRow][i];
	startRow++;
	for (i = startRow; i <= endRow; i++, (*resInd)++)
		result[*resInd] = input_array[i][endCol];
	endCol--;
	for (i = endCol; i >= startCol && startRow <= endRow; i--, (*resInd)++)
		result[*resInd] = input_array[endRow][i];
	endRow--;
	for (i = endRow; i >= startRow && startCol <= endCol; i--, (*resInd)++)
		result[*resInd] = input_array[i][startCol];
	startCol++;
	buildSpiralArr(input_array, result, startRow, startCol, endRow, endCol, resInd);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	int resultIndex = 0;
	int *result = (int *)malloc(sizeof(int) * rows * columns);
	buildSpiralArr(input_array, result, 0, 0, rows - 1, columns - 1, &resultIndex);
	return result;
}


