    //Amount of i's
// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//global const
const int num_of_bowlers = 10;
const int num_of_scores = 4;
const int printWidth = 50;
//Declaring Struct to be able to be accessed 
	struct BowlerData
	{
		std::string bowlerName;
		int bowlerScores[num_of_scores];
		int avgScore;
	}; 

class Bowling{
	//private array same structure and private string of filename
	private:
	std::string fileName;
	BowlerData bowlingRaw[num_of_bowlers];
	//public constructor
	public:	
	Bowling(std::string fileName)
	{
		//points at filename initializing it to whatever it is called as in class call
		this -> fileName = fileName;
	}
	bool GetBowlingData(){
		//initialize infile to open filename
		std::fstream inFile;
		//opening file
		inFile.open(fileName);
		std::cout << "Opening File..." << std::endl;
		//checking if file opens..
		if(!inFile){
			std::cout << "Failed to open, sorry." << std::endl;
			return false;
		}		
		else{
			std::cout << "File sucessfully opened." << std::endl << std::endl;
		}
	//Filling up struct with data, since its two dimension have to run two for loops, Outer Loop Gets the names
	while(inFile)
	{
		for(int bowlerIndex = 0; bowlerIndex < num_of_bowlers; bowlerIndex++)
		{
			//Collecting data from open file, should be just the name
			inFile >> bowlingRaw[bowlerIndex].bowlerName;
			//after grabbing name grabs 5 scores.
			
			for(int scoresIndex = 0; scoresIndex < num_of_scores; scoresIndex++)
			{
				//Reads numbers storing them in bowlerscores index while following along with bowlerindex
				inFile >> bowlingRaw[bowlerIndex].bowlerScores[scoresIndex];
			}
			//after 10 iterations ofthe outer loop the structure should be filled with the bowler names and scores
		}
	}
	inFile.close();
	return true; 
	}
	//average score method
	void GetAverageScore(){
			//holding sum of scores
		int average;
		//need two loops one to calculate the average and one to add together sum of all
		for(int bowlerIndex = 0; bowlerIndex < num_of_bowlers; bowlerIndex++)
		{
			average = 0; //zero out to keep avg to each bowler
			for(int scoreIndex = 0; scoreIndex < num_of_scores; scoreIndex++){
				//adding sum of bowlers score storing in avg
				average = bowlingRaw[bowlerIndex].bowlerScores[scoreIndex] + average;
			}
			//calc average
			average = average / num_of_scores;
			//assigning average to bowler storing in avgScore
			bowlingRaw[bowlerIndex].avgScore = average;
	}

	}
	void PrintPrettyResults()
	{
	for(int bowlerIndex = 0; bowlerIndex < num_of_bowlers; bowlerIndex++)
	{
	//want to print out name first
	std::cout << bowlingRaw[bowlerIndex].bowlerName << "'s scores in four rounds was:" << std::endl;
	//Looop to print out scores dont want to try anything fancy I have already struggled enough as is...
	for(int scoreIndex = 0; scoreIndex < num_of_scores; scoreIndex++)
	{
		std::cout << bowlingRaw[bowlerIndex].bowlerScores[scoreIndex] << " ";
	}
	//printing out average of that bowler
	std::cout << std::endl << bowlingRaw[bowlerIndex].bowlerName << "'s average score for four rounds was: " << bowlingRaw[bowlerIndex].avgScore << std::endl;
	std::cout << std::setfill('_') << std::setw(printWidth) << '_' << std::endl << std::endl;
	}

	}
};

int main()
{
//instance of class with txt file as parameter 
Bowling BowlingResults("BowlingScores.txt");
//making sure bowling results actually opens the file so it doesnt spew out garbage
if(BowlingResults.GetBowlingData() == false){
	return -1;
}
//average results
BowlingResults.GetAverageScore();
//print results!
BowlingResults.PrintPrettyResults();

}