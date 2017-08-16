#include <iostream>
#include <string>

using namespace std;

#pragma warning(disable:4996)

#define ALCOHOL_SPECIFIC 0.8
#define WEIGHT_DIVISION_CONSTANT 0.1

int main()
{
	int   drinkingAmount;	//飲酒量
	double Weight, Alcohol, DaPh, Frequency, DaTime;
	char *answer;
	FILE *fp;

	cout << "体重(kg):";
	cin >> Weight;

	cout << "度数(%):";
	cin >> Frequency;

	cout << "摂取量(ml):";
	cin >> drinkingAmount;
	cout << "\n";

	if (Weight == 0 || Frequency == 0 || drinkingAmount == 0)
	{
		return EXIT_FAILURE;
	}

	DaPh = Weight * WEIGHT_DIVISION_CONSTANT;	//分解できる純アルコール量/h
	Alcohol = (Frequency / 100) * drinkingAmount * ALCOHOL_SPECIFIC;	//純アルコール量

	DaTime = Alcohol / DaPh;	//アルコール分解時間

	cout << "\n";

	cout << DaTime << "\n";

	if ((fp = fopen("alc.txt", "w")) == NULL)
	{
		cout << "FileopenError";
		return EXIT_FAILURE;
	}

	fprintf(fp, "%.2f", DaTime);

	fclose(fp);


	return 0;
}