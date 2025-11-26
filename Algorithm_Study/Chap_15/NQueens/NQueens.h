// NxN 크기의 체스판에서 각 열에 퀸을 배치.
// N개의 퀸을 배치했을 때 서로가 위협받지 않는 경우를 구해라.
// 후보해 : N^2 C N, N=4일 때 1820가지의 후보해

#ifndef NQUEENS_H
#define NQUEENS_H

void PrintSolution( int Columns[], int NumberOfQueens );
int IsThreatened( int Columns[], int NewRow );
void FindSolutionForQueen( int Columns[], int Row, int NNumberOfQueens, int* SolutionCount );

#endif