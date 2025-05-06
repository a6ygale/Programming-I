//abygale cochrane
//february 28th, 2024


//this code generates a environment for the
//dice game 'Pig' in which the user and 
//computer compete to see who can accumulate
//100 points first


#include <iostream>
#include<cstdlib>
#include <time.h>
#include <vector>
using namespace std;


int humanScore = 0;//score of human, recalculated after each turn
int computerScore = 0;//score of computer, recalculated after each turn
int turnPoints; //how many points total are gained during the turn, recalculated after each roll
int points; //points earned for each roll, includes bonus points for rolling doubles
int roll; //variable that stores random number generated, simulates an actual dice roll
int lastRoll; //used to refer back to previous rolls stored in vector
vector <int> turnRolls;//vector that stores all rolls in each turn for callback
int yourTurn; //allows for bonus turns, can be used to run another human/computer turn
string run; //indicates whether roll process should run again given an 'r' or 'h' input value
string startComputer; //user input to start computer turn required
					//DISCLAIMER- no need to check actual value, just a way to ensure user interaction


//fuction that displays current score whenever called
void displayScore(int humanScore, int computerScore )
{
	cout << "Human Score: " << humanScore << "\n"
		<< "Computer Score: " << computerScore << "\n";
}

//function that automates wheter the computer should roll
//again or halt their turn
string runAgain(int computerScore, int turnPoints)
{
	//when score is still low and hasnt accumulated many points on turn yet
	if (computerScore<50 && turnPoints<10)
	{	
		run = "r";
	}

	//score is still low but gained sufficient points on turn computer is advised to protect points earned so far
	else if (computerScore < 50 && turnPoints > 10) 
	{
		run = "h";
	}
	//score is higher so computer will be more conservative and only roll if it has less than 6 points on a turn
	else if(computerScore > 50 && turnPoints < 6)
	{
		run = "r";
	}

	//if it hase more than 6, it should protect those points and end its turn
	else if (computerScore > 50 && turnPoints > 6)
	{
		run = "h";
	}
	return run;
}



//function that checks form double rolls to give a bonus
int checkDouble(vector<int> turnRolls, int turnPoints)
	{
		lastRoll = turnRolls.size()-1;//find how many turns went by 

		//checks if at least 2 turns went by and last two rolls were equal
		if (lastRoll > 0 && turnRolls[lastRoll] == turnRolls[lastRoll - 1])
		{
			cout << "You got double points!\n";
			points = turnRolls[lastRoll] * 2;//doubles dice value
		}
		
		else //if it wasnt a double, the user only earned dice value from last roll
		{	
			points = turnRolls[lastRoll];
		}
		turnPoints = turnPoints + points; //add up points from last roll to turns total
		return turnPoints;
	}



//function that provides a turn directly after if user rolls 3 sixes in a row by revaluing yourTurn
int checkSixes(vector<int> turnRolls)
	{
	lastRoll = turnRolls.size()-1;

	//cheks that theres enough rolls to qualify for triple 6
	if (lastRoll > 1 && turnRolls[lastRoll] == 6 && turnRolls[lastRoll - 1] == 6 && turnRolls[lastRoll - 2] == 6)
	{
		cout << "You got a bonus turn!\n";
		yourTurn = 1;//reassigns variable so that the humanTurn() function will run again directly after
		//this turn is over
	}
	else
		yourTurn = yourTurn;
	
	return yourTurn; 
	}


//the primary fuction for all actions in human turn
//including roll, bonus points, bonus turns, and option to roll again
int humanTurn()
{
	yourTurn = 1;
	while (yourTurn == 1)
	{
		cout << "\n" << "Human's Turn\n";

		//clears all rolls and points so it only records for this turn
		turnRolls.clear();
		turnPoints = 0;
		run = "r";
		yourTurn = yourTurn - 1;

		while (run == "r")//rolling as long as user doesnt say they want to halt their turn
		{
			//produces a random number in the range of a normal dice
			roll = rand() % 6 + 1;
			cout << "You rolled a " << roll << ".\n";
			
			if (roll == 1)//if you roll a one, no points and turn is over
			{
				cout << "Your turn and points have been FORFEITED\n";
				turnPoints = 0;
				run = "h";
			}
			else //if you didnt roll a 1, checks for bonuses and adds up points
			{
				turnRolls.push_back(roll); //adds last roll to vector containing all rolls in turn
				turnPoints = checkDouble(turnRolls, turnPoints);//doubles point value if you rolled 2 of the same dice
				yourTurn = checkSixes(turnRolls);//if there's 3 sixes it will keep your turn
				
				cout << "type r to roll again or h to halt your turn:\n";
				cin >> run;
				
			}

		}//done rolling
		//adds the points from the turn to overall score
		humanScore = humanScore + turnPoints;
		displayScore(humanScore, computerScore);
	
	}
	return humanScore;
}



//the primary fuction for all actions in human turn
//including roll, bonus points, bonus turns, and oautomatic decision to roll or hold

int computerTurn() 
{
	yourTurn = 1;
	while (yourTurn == 1)
	{
		cout << "\n" << "Computer's Turn\n" <<"type c to continue\n";
		cin >> startComputer;
		//clears all rolls and points so it only records for this turn
		turnRolls.clear();
		turnPoints = 0;
		run = "r";
		yourTurn = yourTurn - 1;

		//rolling as long as user doesnt say they want
		//to halt their turn
		while (run == "r")
		{	
			roll = rand() % 6 + 1;//produces a random number in the range of a normal dice
			cout << "Computer rolled a " << roll << ".\n";

			if (roll == 1)//if you roll a one, no points and turn is over
			{
				cout << "Your turn and points have been FORFEITED\n";
				turnPoints = 0;
				run = 'h';
			}
			else
			{
				turnRolls.push_back(roll);//adds last roll to vector containing all rolls in turn
				turnPoints = checkDouble(turnRolls, turnPoints);//doubles point value if you rolled 2 of the same dice
				yourTurn = checkSixes(turnRolls);//if there's 3 sixes it will keep your turn
				run = runAgain(computerScore, turnPoints); //automatically decides whether it should roll again or not
			}
		}
		//adds the points from the turn to overall score
		computerScore = computerScore + turnPoints;
		displayScore(humanScore, computerScore);
	}

	return computerScore;
}


int main()
{
	//seeding random number generator
	srand(time(0));


		while (humanScore < 100 && computerScore < 100)//continues going between human and computer turn until someone wins
		{
			humanScore = humanTurn();
			computerScore = computerTurn();
			
		}
		if (humanScore > computerScore)
		{
			cout << "\nYOU WIN!!!";
		}
		else
		{
			cout << "\nYou lost :( \n" << "better luck next time.\n";
		}
		return 0;
}
