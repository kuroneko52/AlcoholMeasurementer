#include <iostream>
#include <string>

using namespace std;

#pragma warning(disable:4996)

#define ALCOHOL_SPECIFIC 0.8
#define WEIGHT_DIVISION_CONSTANT 0.1

int main()
{
	int   drinkingAmount;	//�����
	double Weight, Alcohol, DaPh, Frequency, DaTime;
	char *answer;
	FILE *fp;

	cout << "�̏d(kg):";
	cin >> Weight;

	cout << "�x��(%):";
	cin >> Frequency;

	cout << "�ێ��(ml):";
	cin >> drinkingAmount;
	cout << "\n";

	if (Weight == 0 || Frequency == 0 || drinkingAmount == 0)
	{
		return EXIT_FAILURE;
	}

	DaPh = Weight * WEIGHT_DIVISION_CONSTANT;	//�����ł��鏃�A���R�[����/h
	Alcohol = (Frequency / 100) * drinkingAmount * ALCOHOL_SPECIFIC;	//���A���R�[����

	DaTime = Alcohol / DaPh;	//�A���R�[����������

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