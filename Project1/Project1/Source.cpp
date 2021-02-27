#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int** createMatrix(int a, int b)
{
	int** M1 = new int* [a];
	for (int i = 0; i < a; i++)
		M1[i] = new int[b];
	return M1;
}

int** inputMatrix(int a, int b, int** M)
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			cin >> M[i][j];
	return M;
}

int** inputRandomMatrix(int a, int b, int** M)
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			M[i][j] = rand() % 10;
	return M;
}

void outputMatrix(int a, int b, int** M)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}

int** bringingMatrix(int l, int a, int b, int** M, int** M2)
{
	for (int i = 0; i < l; i++)
	{
		M2[i] = new int[l];
		for (int j = 0; j < l; j++)
			M2[i][j] = 0;
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			M2[i][j] = M[i][j];
	}
	return M2;
}

int** submatrixThings(int l, int** mat, int** M, int a, int b)
{
	for (int i = 0; i < l / 2; i++)
	{
		mat[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
			mat[i][j] = M[i + a * l / 2][j + b * l / 2];
	}
	return mat;
}

int** createIntermediateMatrix(int l, int** p)
{
	for (int i = 0; i < l / 2; i++)
	{
		p[i] = new int[l / 2];
	}
	return p;
}

int calculateIntermediateMatrix(int i, int j, int l, int p, int** mat1, int** mat2, int** mat3, int** mat4, int a, int b)
{
	p = 0;
	for (int z = 0; z < l / 2; z++)
	{
		p += (mat1[i][z] + a * mat2[i][z]) * (mat3[z][j] + b * mat4[z][j]);
	}
	return p;
}



int** supportingMatrix(int l, int** mat)
{
	for (int i = 0; i < l / 2; i++)
	{
		mat[i] = new int[l / 2];
	}
	return mat;
}




int** valuesOfSupportingMatrix(int i, int j, int** p1, int** p2, int** p3, int** p4, int a, int** mat)
{
	mat[i][j] = p1[i][j] + p2[i][j] + a * p3[i][j] - a * p4[i][j];
	return mat;
}


int alignmentResultMatrix(int l, int** M, int x, int b)
{
	for (int i = 0; i < l; i++)
	{
		x = 0;
		for (int j = 0; j < l; j++)
		{
			if (M[i][j] != 0)
			{
				x++;
				b = 100;
			}
		}
		if (x == 0 && i < b)
		{
			b = i;
		}
	}
	return b;
}

void main()
{
	srand(time(NULL));
	int n1, m1, n2, m2, k, l = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> n1 >> m1;
	} while (n1 <= 0 || m1 <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> n2 >> m2;
	} while (n2 <= 0 || m2 <= 0);
	int** M1 = createMatrix(n1, m1);
	int** M2 = createMatrix(n2, m2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> k;
	} while (k < 1 || k > 2);
	switch (k)
	{
	case 1:
		inputMatrix(n1, m1, M1);
		inputMatrix(n2, m2, M2);
		cout << "\nМатрица 1\n\n";
		outputMatrix(n1, m1, M1);
		cout << "\nМатрица 2\n\n";
		outputMatrix(n2, m2, M2);
		break;
	case 2:
		inputRandomMatrix(n1, m1, M1);
		inputRandomMatrix(n2, m2, M2);
		cout << "\nМатрица 1\n\n";
		outputMatrix(n1, m1, M1);
		cout << "\nМатрица 2\n\n";
		outputMatrix(n2, m2, M2);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (l < n1 || l < n2 || l < m1 || l < m2)
		l *= 2;
	int** M3 = new int* [l];
	int** M4 = new int* [l];
	M3 = bringingMatrix(l, n1, m1, M1, M3);
	M4 = bringingMatrix(l, n2, m2, M2, M4);
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	outputMatrix(l, l, M3);
	cout << "\nМатрица 2\n\n";
	outputMatrix(l, l, M4);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat1 = new int* [l / 2];
	mat1 = submatrixThings(l, mat1, M3, 0, 0);
	int** mat2 = new int* [l / 2];
	mat2 = submatrixThings(l, mat2, M3, 0, 1);
	int** mat3 = new int* [l / 2];
	mat3 = submatrixThings(l, mat3, M3, 1, 0);
	int** mat4 = new int* [l / 2];
	mat4 = submatrixThings(l, mat4, M3, 1, 1);
	int** mat5 = new int* [l / 2];
	mat5 = submatrixThings(l, mat5, M4, 0, 0);
	int** mat6 = new int* [l / 2];
	mat6 = submatrixThings(l, mat6, M4, 0, 1);
	int** mat7 = new int* [l / 2];
	mat7 = submatrixThings(l, mat7, M4, 1, 0);
	int** mat8 = new int* [l / 2];
	mat8 = submatrixThings(l, mat8, M4, 1, 1);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** p1 = new int* [l / 2];
	p1 = createIntermediateMatrix(l, p1);
	int** p2 = new int* [l / 2];
	p2 = createIntermediateMatrix(l, p2);
	int** p3 = new int* [l / 2];
	p3 = createIntermediateMatrix(l, p3);
	int** p4 = new int* [l / 2];
	p4 = createIntermediateMatrix(l, p4);
	int** p5 = new int* [l / 2];
	p5 = createIntermediateMatrix(l, p5);
	int** p6 = new int* [l / 2];
	p6 = createIntermediateMatrix(l, p6);
	int** p7 = new int* [l / 2];
	p7 = createIntermediateMatrix(l, p7);


	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			p1[i][j] = calculateIntermediateMatrix(i, j, l, p1[i][j], mat1, mat4, mat5, mat8, 1, 1);
			p2[i][j] = calculateIntermediateMatrix(i, j, l, p2[i][j], mat3, mat4, mat5, mat5, 1, 0);
			p3[i][j] = calculateIntermediateMatrix(i, j, l, p3[i][j], mat1, mat1, mat6, mat8, 0, -1);
			p4[i][j] = calculateIntermediateMatrix(i, j, l, p4[i][j], mat4, mat4, mat7, mat5, 0, -1);
			p5[i][j] = calculateIntermediateMatrix(i, j, l, p5[i][j], mat1, mat2, mat8, mat8, 1, 0);
			p6[i][j] = calculateIntermediateMatrix(i, j, l, p6[i][j], mat3, mat1, mat5, mat6, -1, 1);
			p7[i][j] = calculateIntermediateMatrix(i, j, l, p7[i][j], mat2, mat4, mat7, mat8, -1, 1);
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat9 = new int* [l / 2];
	mat9 = supportingMatrix(l, mat9);
	int** mat10 = new int* [l / 2];
	mat10 = supportingMatrix(l, mat10);
	int** mat11 = new int* [l / 2];
	mat11 = supportingMatrix(l, mat11);
	int** mat12 = new int* [l / 2];
	mat12 = supportingMatrix(l, mat12);

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			mat9 = valuesOfSupportingMatrix(i, j, p1, p4, p7, p5, 1, mat9);
			mat10 = valuesOfSupportingMatrix(i, j, p3, p5, p3, p5, 0, mat10);
			mat11 = valuesOfSupportingMatrix(i, j, p2, p4, p2, p4, 0, mat11);
			mat12 = valuesOfSupportingMatrix(i, j, p1, p3, p6, p2, 1, mat12);
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = createMatrix(l, l);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			M5[i][j] = mat9[i][j];
			M5[i][j + l / 2] = mat10[i][j];
			M5[i + l / 2][j] = mat11[i][j];
			M5[i + l / 2][j + l / 2] = mat12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	f = alignmentResultMatrix(l, M5, x, f);
	s = alignmentResultMatrix(l, M5, x, s);

	int** M6 = new int* [f];
	for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	outputMatrix(f, s, M6);
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < n1; i++)
		delete[] M1[i];
	for (int i = 0; i < n2; i++)
		delete[] M2[i];
	for (int i = 0; i < l; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}
	for (int i = 0; i < f; i++)
		delete[] M6[i];
	for (int i = 0; i < l / 2; i++)
	{
		delete[] mat1[i];
		delete[] mat2[i];
		delete[] mat3[i];
		delete[] mat4[i];
		delete[] mat5[i];
		delete[] mat6[i];
		delete[] mat7[i];
		delete[] mat8[i];
		delete[] mat9[i];
		delete[] mat10[i];
		delete[] mat11[i];
		delete[] mat12[i];
		delete[] p1[i];
		delete[] p2[i];
		delete[] p3[i];
		delete[] p4[i];
		delete[] p5[i];
		delete[] p6[i];
		delete[] p7[i];
	}
	delete[] M1, M2, M3, M4, M5, M6;
	delete[] mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10, mat11, mat12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}