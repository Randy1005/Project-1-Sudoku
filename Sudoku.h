#define SIZE 9
#define UNASSIGNED 0

class Sudoku
{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void change();
		void flip(int n);
		void transform();
		void printOut(int grid[SIZE][SIZE]);
		/*******************/
		void push(int sp);
		int pop();
		unsigned char numberChkConflict(int sp);
		int getNextBlankForward(int sp);
		int getNextBlankBackward(int sp);
		void Try(int dir);
		unsigned char preChkNG(int board[][9],int m,int n);
		int tempNum[81];
		int tempSp;
		union UnionSudoku{
			int sdkuArr1[81];
			int sdkuArr2[9][9];
		}sudo;
		/*****************/
		bool Try(int board[SIZE][SIZE]);
		bool Try_backward(int chk_board[SIZE][SIZE]);
		bool findUnassigned(int board[SIZE][SIZE],int &row,int &col);
		bool usedInRow(int board[SIZE][SIZE],int row,int num);
		bool usedInCol(int board[SIZE][SIZE],int col,int num);
		bool usedInCell(int board[SIZE][SIZE],int cellStartRow,int cellStartCol,int num);
		bool isLegal(int board[SIZE][SIZE],int row,int col,int num);

		int board[SIZE][SIZE];
		int rotate_board[SIZE][SIZE];
		int flip_board[SIZE][SIZE];
		int chk_board[SIZE][SIZE];
		int solCount;
};


