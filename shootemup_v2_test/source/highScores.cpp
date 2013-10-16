//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include "highScores.h"
using namespace std;

// write to a to a file
void highScore::write(int score)
{
	ofstream myfile ("highscores.txt", ios::app);
	if (myfile.is_open())
	{
		myfile << score << "\n";
		myfile.close();
	}
	else 
		cout << "Unable to open file";
	return;
}
// print scores to console
void highScore::read()
{
	//string *line;
	char strings;
	ifstream myfile ("highscores.txt");
	if (myfile.is_open())
	{	
		while ( getline (myfile,line) )
		{
				cout << "Highscore: " << line << endl;
				//strings = myfile.get();
		}
    myfile.close();
	}

  else cout << "Unable to open file";

}