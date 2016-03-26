#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku(){


}

void Sudoku::giveQuestion(){
	int que[9][9] = {8,0,0,0,0,0,0,0,0,
					 0,0,3,6,0,0,0,0,0,
					 0,7,0,0,9,0,2,0,0,
					 0,5,0,0,0,7,0,0,0,
					 0,0,0,0,4,5,7,0,0,
					 0,0,0,1,0,0,0,3,0,
					 0,0,1,0,0,0,0,6,8,
					 0,0,8,5,0,0,0,1,0,
					 0,9,0,0,0,0,4,0,0};

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<que[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Sudoku::readIn()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>board[i][j];		
}

void Sudoku::solve()
{
	
}

void Sudoku::changeNum(int a,int b)
{
	/*
	int xA,xB,yA,yB;
	int i,j;
	if(a!=b && a!=0 && b!=0)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(board[i][j] == a)
				{
					xA = i; yA = j;
				}	
				else if(board[i][j] == b)
				{
					xB = i; yB = j;
				}
				
			}
		}
		
		board[xA][yA] = b; board[xB][yB] = a;
	}
	else
		exit(1);
	*/
}

void Sudoku::changeRow(int a,int b)
{
	int tmp0[9],tmp1[9],tmp2[9];
	while(a!=b)
	{
		if(a == 0){
			if(b == 1)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[3][i];
					board[1][i] = board[4][i];
					board[2][i] = board[5][i];
					board[3][i] = tmp0[i];
					board[4][i] = tmp1[i];
					board[5][i] = tmp2[i];		
				}
			}
			else if(b == 2)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[6][i];
					board[1][i] = board[7][i];
					board[2][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];		
				}
			}
		}
		if(a == 1){	
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[3][i];
					board[1][i] = board[4][i];
					board[2][i] = board[5][i];
					board[3][i] = tmp0[i];
					board[4][i] = tmp1[i];
					board[5][i] = tmp2[i];		
				}
			}
			else if(b == 2)
			{	
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[3][i];
					tmp1[i] = board[4][i];
					tmp2[i] = board[5][i];
					board[3][i] = board[6][i];
					board[4][i] = board[7][i];
					board[5][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];		
				}
			}
		}
		if(a == 2)
		{
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[6][i];
					board[1][i] = board[7][i];
					board[2][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];		
				}
			}
			else if(b == 1)
			{	
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[3][i];
					tmp1[i] = board[4][i];
					tmp2[i] = board[5][i];
					board[3][i] = board[6][i];
					board[4][i] = board[7][i];
					board[5][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];		
				}
			}

		}
		break;
	}
}

void Sudoku::changeCol(int a,int b)
{
	int tmp0[9],tmp1[9],tmp2[9];
	while(a!=b)
	{
		if(a == 0){
			if(b == 1)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][3];
					board[i][1] = board[i][4];
					board[i][2] = board[i][5];
					board[i][3] = tmp0[i];
					board[i][4] = tmp1[i];
					board[i][5] = tmp2[i];		
				}
			}
			else if(b == 2)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][6];
					board[i][1] = board[i][7];
					board[i][2] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];		
				}
			}
		}
		if(a == 1){	
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{

					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][3];
					board[i][1] = board[i][4];
					board[i][2] = board[i][5];
					board[i][3] = tmp0[i];
					board[i][4] = tmp1[i];
					board[i][5] = tmp2[i];		
				}
			}
			else if(b == 2)
			{	
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[i][3];
					tmp1[i] = board[i][4];
					tmp2[i] = board[i][5];
					board[i][3] = board[i][6];
					board[i][4] = board[i][7];
					board[i][5] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];		
				}
			}
		}
		if(a == 2)
		{
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][6];
					board[i][1] = board[i][7];
					board[i][2] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];		
				}
			}
			else if(b == 1)
			{	
				for(int i=0;i<9;i++)
				{
					tmp0[i] = board[i][3];
					tmp1[i] = board[i][4];
					tmp2[i] = board[i][5];
					board[i][3] = board[i][6];
					board[i][4] = board[i][7];
					board[i][5] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];		
				}
			}

		}
		break;
	}

}

void Sudoku::rotate(int n)
{
	while(n--)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{	
				rotate_board[i][j] = board[j][8-i];
			}
		}
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				board[i][j] = rotate_board[i][j];
	}

}

void Sudoku::flip(int n)
{

}

void Sudoku::transform()
{

}
