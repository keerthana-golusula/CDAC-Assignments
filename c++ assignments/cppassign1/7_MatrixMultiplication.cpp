#include<iostream>
using namespace std;
class Matrix {
	int rows, cols;
	int **Mat;
public:
	friend istream& operator>> (istream&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix);
	friend Matrix multiply(Matrix,Matrix);
};
istream& operator >> (istream& cin, Matrix& m) {
	cout << "enter no.of rows\n";
	cin >> m.rows;
	cout << "enter no.of columns\n";
	cin >> m.cols;
	m.Mat = new int*[m.rows];
	for (int i = 0; i < m.rows; i++) {
		m.Mat[i] = new int[m.cols];
	}
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			cin >> m.Mat[i][j];
		}
	}
	return cin;
}
ostream& operator<<(ostream& cout, Matrix m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			cout << m.Mat[i][j]<<" ";
		}
		cout << endl;

	}
	return cout;
}
Matrix multiply(Matrix m1,Matrix m) {
	Matrix M;
	if (m1.cols != m.rows) {
		cout << "Matrix Multiplication Not possible";
		exit(-1);
	}
	M.rows = m1.rows;
	M.cols = m.cols;
	M.Mat = new int*[M.rows];
	for (int i = 0; i < M.rows; i++) {
		M.Mat[i] = new int[M.cols];
	}
	for (int i = 0; i < M.rows; i++) {
		for (int j = 0; j <M.cols; j++) {
			M.Mat[i][j] = 0;
			for (int k = 0; k < m1.cols; k++) {
				M.Mat[i][j] += m1.Mat[i][k] * m.Mat[k][j];
			}
		}
	}

	return M;
}
int main() {
	Matrix m1, m2,m3;
	cout << "matrix1:\n";
	cin >> m1;
	cout << "matrix2:" << endl;
	cin >> m2;
	m3=multiply(m1,m2);
	cout << m3;
	return 0;
}