#define SIZE 9
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
		int board[SIZE][SIZE];
		int rotate_board[SIZE][SIZE];
};


