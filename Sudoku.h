#define SIZE 9
#define UNASSIGNED 0

class Sudoku
{
	public:
		Sudoku();
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		bool Try();
		bool findUnassigned(int board[SIZE][SIZE],int row,int col,int num);
		bool usedInRow(int board[SIZE][SIZE],int row,int num);
		bool usedInCol(int board[SIZE][SIZE],int col,int num);
		bool usedInCell(int board[SIZE][SIZE],int cellStartRow,int cellStartCol,int num);
		bool isLegal(int board[SIZE][SIZE],int row,int col,int num);

		int board[SIZE][SIZE];
		int rotate_board[SIZE][SIZE];
		int flip_board[SIZE][SIZE];
};


