#include "Sudoku.h"
#include <iostream>
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

}

void Sudoku::changeRow(int a,int b)
{

}

void Sudoku::changeCol(int a,int b)
{

}

void Sudoku::rotate(int n)
{

}

void Sudoku::flip(int n)
{

}

void Sudoku::transform()
{

}
