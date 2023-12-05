#include <iostream>
using namespace std;

int main ()
{
	const int ROW_SIZE = 2; //number of rows
	const int COLUMN_SIZE = 5; //number of columns
	int row_sum[ROW_SIZE];
	int column_sum[COLUMN_SIZE];
	int matrix[ROW_SIZE][COLUMN_SIZE]; //2D array
	int sum_1, sum_2;

	for (int i = 0; i < ROW_SIZE; ++i){
		for (int h = 0; h < COLUMN_SIZE; ++h){
		cout << "Enter data for row#" << i + 1 << " and column# " << h + 1 << ": ";
		cin >> matrix [i][h];
		}
	}

	cout << "You entered: " << endl;
	for (int i = 0; i < ROW_SIZE; ++i){
		for (int h = 0; h < COLUMN_SIZE; ++h){
			cout << matrix [i][h] << "\t";
		}
		cout  << endl;
	}

	for(int i = 0; i < ROW_SIZE; ++i){
		sum_1 = 0;
		for (int h = 0; h < COLUMN_SIZE; ++h){
			sum_1 += matrix[i][h];
		}
			row_sum[i] = sum_1;
	}

	for(int i = 0; i < COLUMN_SIZE; ++i){
    	sum_2 = 0;
    for(int h = 0; h < ROW_SIZE; ++h){
      sum_2 += matrix[h][i];
    }
    column_sum[i] = sum_2;
  }
 
  for(int i = 0; i < ROW_SIZE;  i++){
    cout << "Row #" << i+1 << " sum: " << row_sum[i] << endl;
  }
  for(int i = 0; i < COLUMN_SIZE; i++){
    cout << "Column #" << i+1 << " sum: " << column_sum[i] << endl;
  }

	return 0;
}