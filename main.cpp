#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
public:
	Matrix(const int _size, const int _startRange, const int _endRange) {
		m_startRange = _startRange;
		m_endRange = _endRange;
		if (_size > M_MMS) m_size = M_MMS;
		else m_size = _size;
		m_matrix = new int*[m_size];
		for (int i = 0; i < m_size; i++) {
			m_matrix[i] = new int[m_size];
		}
	}

	~Matrix() {
		for (int i = 0; i < m_size; i++) {
			delete[] m_matrix[i];
		}
		delete[] m_matrix;
	}

	void fillMatrix() {
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				m_matrix[i][j] = rand() % (m_endRange - m_startRange + 1) + m_startRange;//!
			}
		}
	}

	void printMatrix() {
		for (int i = 1; i < m_size; i++) {
			for (int j = 1; j < m_size; j++) {
				cout << setw(5) << m_matrix[i][j];
			}
		cout << endl;
		}
		cout << endl;
	}

	void printRowSumInRange(const int _leftBorder, const int _rightBorder) {
		m_leftBorder = _leftBorder;
		m_rightBorder = _rightBorder;
		for (int i = 0; i < m_size; i++) {
			int menuItem{};
			for (int j = 0; j < m_size; j++) {
				if (m_matrix[i][j] > m_leftBorder and m_matrix[i][j] < m_rightBorder){
				    menuItem+=m_matrix[i][j];
				}
			}
			cout << endl << "In "<< i+1 << " row sum is "<< menuItem << endl;
		}
	}
	
	void isPositiveRow() {
		bool cur = 0;
		for (int i = 0; i < m_size; i++) {
			bool lineFlag = 1;
			if (!cur) {
				for (int j = 0; j < m_size; j++) {
					if (lineFlag) {
						if (m_matrix[i][j] < 0) lineFlag = 0;
					}
				}
				if (lineFlag) cur=1;
			}
		}
        cout << endl << "There are "<< cur << " positive rows in the matrix"<< endl;
	}

	void getTriangleSum() {
		int sum = 0;
		for (int i = 0; i < m_size; i++) {
			for (int j = i; j < m_size; j++) {
				sum += m_matrix[i][j];
			}
		}
	cout << endl << "Sum in triangle is " << sum << endl;
	}

private:
	int m_size;
	// Range is for fillMatrix() method
	int m_startRange;
	int m_endRange;
	// Borders is only for printRowSumInRange() method
	int m_leftBorder;
	int m_rightBorder;
	int** m_matrix = nullptr;
	const int M_MMS = 100; // M_MAXMATRIXSIZE
};
	
int InputMenu(){
    cout << endl;
    cout << "1- Для вывода матрицы" << endl;
    cout << "2- Для проверки наличия положительных рядов" << endl;
    cout << "3- Для нахождения суммы в диапазоне" << endl;
    cout << "4- Для нахождения суммы выше главной диагонали" << endl;
    cout << "0- Выход" << endl;
    int menuNumber = 0;
    cin >> menuNumber;
    return menuNumber;
}

void MenuLoop(Matrix& Mat) {
	int menuItem = -1;
	int left = 0, right = 0;
	while (menuItem != 0) {
		menuItem = InputMenu();
		switch(menuItem){
			case 1:
				Mat.printMatrix();
				break;
			case 2:
				Mat.isPositiveRow();
				break;
			case 3:
				cout << "Введите левую и правую границу: " ;
				cin >> left >> right;
				cout << endl;
				Mat.printRowSumInRange(left, right);
				break;
			case 4:
				Mat.getTriangleSum();
				break;
			case 0:
				break;
			default:
				cout << "Неправильно выбрана команда, повторите ввод" << endl;
				break;
		}
	}
}

int main() {
	#pragma region init
	srand(unsigned(time(NULL)));
	Matrix Mat(18, -13, 13);
	Mat.fillMatrix();
	#pragma endregion init
   	
	MenuLoop(Mat);

	return 0;
}
