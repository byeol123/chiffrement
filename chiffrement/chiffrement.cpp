#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void initialisation(char* cle)
{
	ifstream fic;
	fic.open("cle.txt");
	int i = 0;
	fic >> cle[0];
	while (!fic.eof())
	{
		i++;
		fic.get(cle[i]);
	}
	fic.close();
}
void chiffrer(char* cle)
{
	ifstream fic;
	ofstream ficw;
	fic.open("plaintext.txt");
	ficw.open("cyphertext.txt");
	char c;
	fic.get(c);
	while (!fic.eof())
	{
		ficw << cle[c - 'a'];
		fic.get(c);
		
	}
	fic.close();
	ficw.close();

}

void dechiffrer(char* cle)
{
	ifstream fic;
	ofstream ficw;
	fic.open("cyphertext.txt");
	ficw.open("dechiff.txt"); 
	char c;
	char word;
	fic.get(c);
	while (!fic.eof())
	{
		for (int i = 0; i < 26; i++)
		{
			if (c == cle[i])
			{	

				cout << i;
				word = 'a' + i;
				ficw << word;
				fic.get(c);
			}
		} 

	}
	fic.close();
	ficw.close();

}

int main()
{  
	int menu = 0;
    char cle[26];
	initialisation(cle);
	cout << "voulez vous chiffrer ou dechiffrer ? appuyer sur 1 ou 2\n";
	cin >> menu;
	if (menu == 1)
	{	
		chiffrer(cle);
		return 0;
	}
	else if(menu == 2)
	{
		dechiffrer(cle);
		return 0;
	}
	
	
}


