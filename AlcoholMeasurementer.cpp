// AlcoholMeasurementer.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

#define ALCOHOL_SPECIFIC 0.8
#define WEIGHT_DIVISION_CONSTANT 0.1
#define FILE_NAME "Result.txt"

int main()
{
	long h, m, s, i;
	int   drinkingAmount;	//飲酒量
	double Weight, Alcohol, DaPh, Frequency, DaTime;
	ofstream outputfile(FILE_NAME);

	cout << "体重(kg):";
	cin >> Weight;

	cout << "度数(%):";
	cin >> Frequency;

	cout << "摂取量(ml):";
	cin >> drinkingAmount;
	cout << "\n";

	if (Weight <= 0 || Frequency <= 0 || drinkingAmount <= 0)
	{
		return EXIT_FAILURE;
	}

	Alcohol = (Frequency / 100) * drinkingAmount * ALCOHOL_SPECIFIC;	//純アルコール量
	DaPh = Weight * WEIGHT_DIVISION_CONSTANT;	//分解できる純アルコール量/h

	DaTime = Alcohol / DaPh;	//アルコール分解時間

	i = DaTime * 3600;

	h = i / 3600;
	m = (i - h * 3600) / 60;
	s = i - h * 3600 - m * 60;

	outputfile << h << "h" << m << "m" << s << "s" << "\n";
	outputfile.close();

	return 0;
}
