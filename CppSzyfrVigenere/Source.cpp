#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

using namespace std;

//lepsza bespieczna wersja oparta o kod ASCII

void main()
{
	//polskie znaki w kosoli
	setlocale(LC_ALL, "");

	fstream f_files;
	fstream t_files;
	string s_from;
	string s_where;
	string szyfr;
	auto x = 0;

	cout << "1.Szyfrowanie " << endl << "2.Deszyfrowanie " << endl;
	cin >> x;
	cout << "Nazwa pliku z którego czytamy" << endl;
	cin >> s_from;
	cout << "Nazwa pliku do którego zapisujemy" << endl;
	cin >> s_where;
	cout << "Podaj szyfr" << endl;
	cin >> szyfr;
	
	//Zamiana ma³ych liter na du¿e w szyfr
	for (auto& i : szyfr)
	{
		if (i > 95) i -= 32;
	}

	f_files.open(s_from);
	t_files.open(s_where, ios::out);

	string t_string;
	string line;

	//zczytywanie linia po lini
	if (f_files.good())
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		while (getline(f_files, line))
		{

			t_string += line + '\n';
		}
	}
	else
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
	}
	//Zamiana ma³ych liter na du¿e w wejœciu
	for (auto& i : t_string)
	{
		if (i > 95) i -= 32;
	}
	string t_szyfr;
	auto l_szyfr = 0;
	for (auto i : t_string)
	{
		if ((48 <= i && i <= 57) || (65 <= i && i <= 90))
		{
			t_szyfr += szyfr[l_szyfr];
			l_szyfr++;
			if (l_szyfr == szyfr.size()) l_szyfr = 0;
		}
		else t_szyfr += i;
	}
	//cout << t_szyfr << endl;
	if (x == 1)
	{
		for (auto i = 0; i < t_string.size(); i++)
		{
			if (48 <= t_szyfr[i] && t_szyfr[i] <= 57)
			{
				const auto przes = t_szyfr[i] - 48;
				//cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					t_string[i]++;
					if (t_string[i] == 58) t_string[i] = 65;
					if (t_string[i] == 91) t_string[i] = 48;
				}
			}
			else if (65 <= t_szyfr[i] && t_szyfr[i] <= 90)
			{
				const auto przes = t_szyfr[i] - 55;
				//cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					t_string[i]++;
					if (t_string[i] == 58) t_string[i] = 65;
					if (t_string[i] == 91) t_string[i] = 48;
				}
			}
		}
	}
	else
	{
		for (auto i = 0; i < t_string.size(); i++)
		{
			if (48 <= t_szyfr[i] && t_szyfr[i] <= 57)
			{
				const auto przes = t_szyfr[i] - 48;
				//cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					t_string[i]--;
					if (t_string[i] == 47) t_string[i] = 90;
					if (t_string[i] == 64) t_string[i] = 57;
				}
			}
			else if (65 <= t_szyfr[i] && t_szyfr[i] <= 90)
			{
				const auto przes = t_szyfr[i] - 55;
				//cout << przes << endl;
				for (auto j = 0; j < przes; j++)
				{
					t_string[i]--;
					if (t_string[i] == 47) t_string[i] = 90;
					if (t_string[i] == 64) t_string[i] = 57;
				}
			}
		}
	}

	cout << t_string << endl;
	t_files << t_string;
	f_files.close();
	t_files.close();
}