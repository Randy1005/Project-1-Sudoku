#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

Sudoku::Sudoku(){


}

void Sudoku::giveQuestion(){
	/*
	int que[9][9] = {8,0,0,0,0,0,0,0,0,
					 0,0,3,6,0,0,0,0,0,
					 0,7,0,0,9,0,2,0,0,
					 0,5,0,0,0,7,0,0,0,
					 0,0,0,0,4,5,7,0,0,
					 0,0,0,1,0,0,0,3,0,
					 0,0,1,0,0,0,0,6,8,
					 0,0,8,5,0,0,0,1,0,
					 0,9,0,0,0,0,4,0,0};
	*/

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<board[i][j]<<" ";
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

bool Sudoku::Try(int board[SIZE][SIZE])
{
	int row,col;
	//If there is no unassigned location,we're finished
	if(!findUnassigned(board,row,col))
		return true;
	//1~9
	for(int num=1;num<=9;num++)
	{	
		//if no conflict with Sudoku rule
		if(isLegal(board,row,col,num))
		{
			//We try it!!
			board[row][col] = num;
			//return,hopefully success
			if(Try(board))
				return true;
			//if fail,start over
			board[row][col] = UNASSIGNED;
		}
	}
	return false;//this starts "backtracking"
	
}

/* search the board for a space that is unassigned, if found,then the space will be set "unassigned",and true is returned. Ifunassigned not found, false is returned*/
bool Sudoku::findUnassigned(int board[SIZE][SIZE],int &row,int &col)
{
	for(row=0;row<SIZE;row++)
		for(col=0;col<SIZE;col++)
			if(board[row][col]==UNASSIGNED)
				return true;
	return false;
}

/*returns boolean whether any "assigned" space within each row matches the given number*/
bool Sudoku::usedInRow(int board[SIZE][SIZE],int row,int num)
{
	for(int col=0;col<SIZE;col++)
		if(board[row][col]==num)
			return true;
	return false;
}

/*returns boolean whether any "assigned" space within each column matches the given number*/
bool Sudoku::usedInCol(int board[SIZE][SIZE],int col,int num)
{
	for(int row=0;row<SIZE;row++)
		if(board[row][col]==num)
			return true;
	return false;
}

/*returns boolean whether any "assigned" space within each cell matches the given number*/
bool Sudoku::usedInCell(int board[SIZE][SIZE],int cellStartRow,int cellStartCol,int num)
{
	for(int row=0;row<(SIZE/3);row++)
		for(int col=0;col<(SIZE/3);col++)
			if(board[row+cellStartRow][col+cellStartCol]==num)
				return true;
	return false;
}
/*returns boolean to check if we can fill this number in the space*/
bool Sudoku::isLegal(int board[SIZE][SIZE],int row,int col,int num)
{
	/*check if "num" is already placed in same row,col,or cell(just call function!!)*/
	return !usedInRow(board,row,num) && !usedInCol(board,col,num) && !usedInCell(board,row-row%3,col-col%3,num);
}

void Sudoku::solve()
{
	if(Try(board)==true)
	{
		cout<<"1"<<endl;
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
				cout<<board[i][j]<<" ";
			cout<<endl;	
		}
	}
	else
	{
		cout<<"0"<<endl;
		exit(1);
	}
}

void Sudoku::changeNum(int a,int b)
//seems to be useless and may cause board to become unsolvable
{
	int tmp_board[SIZE][SIZE];
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		tmp_board[i][j] = board[i][j];
	}
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(board[i][j]==a)
					board[i][j] = b;
				if(tmp_board[i][j]==b)
					board[i][j] = a;
			}
		}
	
}

void Sudoku::changeRow(int a,int b)
{
	while(a!=b)
	{
		if(a == 0){
			if(b == 1)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[3][i],board[0][i]);
					swap(board[4][i],board[1][i]);
					swap(board[5][i],board[2][i]);
					/*
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[3][i];
					board[1][i] = board[4][i];
					board[2][i] = board[5][i];
					board[3][i] = tmp0[i];
					board[4][i] = tmp1[i];
					board[5][i] = tmp2[i];
					*/		
				}
			}
			else if(b == 2)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[6][i],board[0][i]);
					swap(board[7][i],board[1][i]);
					swap(board[8][i],board[2][i]);
					/*
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[6][i];
					board[1][i] = board[7][i];
					board[2][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];
					*/		
				}
			}
		}
		if(a == 1){	
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[0][i],board[3][i]);
					swap(board[1][i],board[4][i]);
					swap(board[2][i],board[5][i]);
					/*
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[3][i];
					board[1][i] = board[4][i];
					board[2][i] = board[5][i];
					board[3][i] = tmp0[i];
					board[4][i] = tmp1[i];
					board[5][i] = tmp2[i];
					*/		
				}
			}
			else if(b == 2)
			{	
				for(int i=0;i<9;i++)
				{
					swap(board[6][i],board[3][i]);
					swap(board[7][i],board[4][i]);
					swap(board[8][i],board[5][i]);
					/*
					tmp0[i] = board[3][i];
					tmp1[i] = board[4][i];
					tmp2[i] = board[5][i];
					board[3][i] = board[6][i];
					board[4][i] = board[7][i];
					board[5][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];
					*/		
				}
			}
		}
		if(a == 2)
		{
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[0][i],board[6][i]);
					swap(board[1][i],board[7][i]);
					swap(board[2][i],board[8][i]);
					/*
					tmp0[i] = board[0][i];
					tmp1[i] = board[1][i];
					tmp2[i] = board[2][i];
					board[0][i] = board[6][i];
					board[1][i] = board[7][i];
					board[2][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];
					*/		
				}
			}
			else if(b == 1)
			{	
				for(int i=0;i<9;i++)
				{
					swap(board[3][i],board[6][i]);
					swap(board[4][i],board[7][i]);
					swap(board[5][i],board[8][i]);
					/*
					tmp0[i] = board[3][i];
					tmp1[i] = board[4][i];
					tmp2[i] = board[5][i];
					board[3][i] = board[6][i];
					board[4][i] = board[7][i];
					board[5][i] = board[8][i];
					board[6][i] = tmp0[i];
					board[7][i] = tmp1[i];
					board[8][i] = tmp2[i];
					*/		
				}
			}

		}
		break;
	}
}

void Sudoku::changeCol(int a,int b)
{
	while(a!=b)
	{
		if(a == 0){
			if(b == 1)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[i][0],board[i][3]);
					swap(board[i][1],board[i][4]);
					swap(board[i][2],board[i][5]);
					/*
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][3];
					board[i][1] = board[i][4];
					board[i][2] = board[i][5];
					board[i][3] = tmp0[i];
					board[i][4] = tmp1[i];
					board[i][5] = tmp2[i];
					*/		
				}
			}
			else if(b == 2)
			{
				for(int i=0;i<9;i++)
				{
					
					swap(board[i][0],board[i][6]);
					swap(board[i][1],board[i][7]);
					swap(board[i][2],board[i][8]);
					/*
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][6];
					board[i][1] = board[i][7];
					board[i][2] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];
					*/		
				}
			}
		}
		if(a == 1){	
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[i][0],board[i][3]);
					swap(board[i][1],board[i][4]);
					swap(board[i][2],board[i][5]);
					/*
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][3];
					board[i][1] = board[i][4];
					board[i][2] = board[i][5];
					board[i][3] = tmp0[i];
					board[i][4] = tmp1[i];
					board[i][5] = tmp2[i];
					*/		
				}
			}
			else if(b == 2)
			{	
				for(int i=0;i<9;i++)
				{
					swap(board[i][6],board[i][3]);
					swap(board[i][7],board[i][4]);
					swap(board[i][8],board[i][5]);
					/*
					tmp0[i] = board[i][3];
					tmp1[i] = board[i][4];
					tmp2[i] = board[i][5];
					board[i][3] = board[i][6];
					board[i][4] = board[i][7];
					board[i][5] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];
					*/		
				}
			}
		}
		if(a == 2)
		{
			if(b == 0)
			{
				for(int i=0;i<9;i++)
				{
					swap(board[i][0],board[i][6]);
					swap(board[i][1],board[i][7]);
					swap(board[i][2],board[i][8]);
					/*
					tmp0[i] = board[i][0];
					tmp1[i] = board[i][1];
					tmp2[i] = board[i][2];
					board[i][0] = board[i][6];
					board[i][1] = board[i][7];
					board[i][2] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];
					*/		
				}
			}
			else if(b == 1)
			{	
				for(int i=0;i<9;i++)
				{

					swap(board[i][6],board[i][3]);
					swap(board[i][7],board[i][4]);
					swap(board[i][8],board[i][5]);
					/*
					tmp0[i] = board[i][3];
					tmp1[i] = board[i][4];
					tmp2[i] = board[i][5];
					board[i][3] = board[i][6];
					board[i][4] = board[i][7];
					board[i][5] = board[i][8];
					board[i][6] = tmp0[i];
					board[i][7] = tmp1[i];
					board[i][8] = tmp2[i];
					*/		
				}
			}

		}
		break;
	}

}

void Sudoku::rotate(int n)	//only rotate once no matter parameter ??????
{
	for(int k=0;k<n;k++)
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
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(n==0)
				flip_board[i][j] = board[8-i][j];
			else
				flip_board[i][j] = board[i][8-j];
				
		}
	}
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			board[i][j] = flip_board[i][j];

}
void Sudoku::printOut(bool isAns)
{
	if(!isAns)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}


}
void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
void Sudoku::transform()
{
	readIn();
	change();
	printOut(false);	
}


