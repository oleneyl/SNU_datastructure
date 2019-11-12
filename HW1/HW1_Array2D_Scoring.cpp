#include "HW1_Array2D.h"
#define ARRAY_SIZE 12
#define DIST_MAX 30


int main() {
	int c;
	cin >> c;

	if (c == 1) {
		Array2D a(5);
		Array2D b(20);
		Array2D c(90);
		cout << a << endl << endl;
		cout << b << endl << endl;
		cout << c << endl << endl;
	}

	else if (c == 2) {
		Array2D a(ARRAY_SIZE);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				a.MoveRight(i, j);
				cout << a << endl << endl;
			}
		}
	}

	else if (c == 3) {
		Array2D b(ARRAY_SIZE);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				b.MoveLeft(i, j);
				cout << b << endl << endl;
			}
		}
	}

	else if (c == 4) {
		Array2D a(ARRAY_SIZE);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				a.MoveUp(i, j);
				cout << a << endl << endl;
			}
		}
	}

	else if (c == 5) {
		Array2D b(ARRAY_SIZE);
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				b.MoveDown(i, j);
				cout << b << endl << endl;
			}
		}
	}

	else if (c == 6) {
		Array2D a(ARRAY_SIZE);
		for (int i = 1; i < 2 * ARRAY_SIZE - 2; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				a.MoveUpRight(i, j);
				cout << a << endl << endl;
			}
		}
	}

	else if (c == 7) {
		Array2D b(ARRAY_SIZE);
		for (int i = 1; i < 2 * ARRAY_SIZE - 2; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				b.MoveDownLeft(i, j);
				cout << b << endl << endl;
			}
		}
	}

	else if (c == 8) {
		Array2D a(ARRAY_SIZE);
		for (int i = 1; i < 2 * ARRAY_SIZE - 2; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				a.MoveUpLeft(i, j);
				cout << a << endl << endl;
			}
		}
	}

	else if (c == 9) {
		Array2D b(ARRAY_SIZE);
		for (int i = 1; i < 2 * ARRAY_SIZE - 2; i++) {
			for (int j = 0; j < DIST_MAX; j++) {
				b.MoveDownRight(i, j);
				cout << b << endl << endl;
			}
		}
	}

	return 0;
}