#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>


using namespace std;



void main()
{
	setlocale(LC_ALL, "");
	fstream fFiles;
	fstream tFiles;
	string sFrom;
	string sWhere;
	int x = 0;
	string szyfr;
	cout << "1.Szyfrowanie " << endl << "2.Deszyfrowanie " << endl;
	cin >> x;
	cout << "Nazwa pliku z którego czytamy" << endl;
	cin >> sFrom;
	cout << "Nazwa pliku do którego zapisujemy" << endl;
	cin >> sWhere;
	cout << "Podaj szyfr" << endl;
	cin >> szyfr;

	fFiles.open(sFrom);
	tFiles.open(sWhere, ios::out);
	string tString;
	string line;
	if (fFiles.good())
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		while (getline(fFiles, line))
		{

			tString += line + '\n';
		}
	}
	else
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
	}
	for (auto i = 0; i < tString.size(); i++)
	{
		if (tString[i] > 95) tString[i] -= 32;
	}
	string tSzyfr;
	int lSzyfr = 0;
	for (auto i = 0; i < tString.size(); i++)
	{
		if (48 <= tString[i] && tString[i] <= 57 || 65 <= tString[i] && tString[i] <= 90)
		{
			tSzyfr += szyfr[lSzyfr];
			lSzyfr++;
			if (lSzyfr == szyfr.size()) lSzyfr = 0;
		}
		else tSzyfr += tString[i];
	}
	cout << tSzyfr << endl;



	if (x == 1)
	{
		for (auto i = 0; i < tString.size(); i++)
		{
			if (48 <= tSzyfr[i] && tSzyfr[i] <= 57)
			{
				int przes = tSzyfr[i] - 48;
				cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					tString[i]++;
					if (tString[i] == 58) tString[i] = 65;
					if (tString[i] == 91) tString[i] = 48;
				}
			}
			else if (65 <= tSzyfr[i] && tSzyfr[i] <= 90)
			{
				int przes = tSzyfr[i] - 55;
				cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					tString[i]++;
					if (tString[i] == 58) tString[i] = 65;
					if (tString[i] == 91) tString[i] = 48;
				}
			}
		}
	}
	else
	{
		for (auto i = 0; i < tString.size(); i++)
		{
			if (48 <= tSzyfr[i] && tSzyfr[i] <= 57)
			{
				int przes = tSzyfr[i] - 48;
				cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					tString[i]--;
					if (tString[i] == 47) tString[i] = 90;
					if (tString[i] == 64) tString[i] = 57;
				}
			}
			else if (65 <= tSzyfr[i] && tSzyfr[i] <= 90)
			{
				int przes = tSzyfr[i] - 55;
				cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					tString[i]--;
					if (tString[i] == 47) tString[i] = 90;
					if (tString[i] == 64) tString[i] = 57;
				}
			}
		}
	}

	cout << tString << endl;
	tFiles << tString;
	fFiles.close();
	tFiles.close();
}