#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int rollDice();
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int rollDice()
{
	return (rand() % 6) + 1;
}
int humanTurn(int humanTotalScore)
{
	int score;
	char cInput;
	bool bTurnOver = false;
	cout << "It's your turn! Enter 'r' to roll." << endl;
	score = 0;
	do
	{
		int roll = rollDice();
		cout << "You rolled " << roll << endl;
		if (roll == 1)
		{
			cout << "You lose your turn. " << "Enter 'c' to continue." << endl;
			cin >> cInput;
			return 0;
		
		}
		else
		{
			score += roll;
			cout << "Your score this round is: " << score << endl;
			cout << "If you hold, your total score would be: " << humanTotalScore + score << endl;
			cout << "Press 'h' to hold or 'r' to roll again." << endl;
			cin >> cInput;
			if (cInput == 'h')
			{
				bTurnOver = true;
			}
		}
	} while (!bTurnOver);
	return score;
}
int computerTurn(int computerTotalScore)
{
	int score;
	char cInput;
	bool bTurnOver = false;
	cout << "It's the computer's turn!" << endl;
	score = 0;
	do
	{
		int roll = rollDice();
		cout << "You rolled " << roll << endl;
		if (roll == 1)
		{
			cout << "The computer loses its turn. " << "Enter 'c' to continue." << endl;
			cin >> cInput;
			return 0;
		
		}
		else
		{
			score += roll;
			cout << "The computer's score this round is: " << score << endl;
			cout << "If the computer holds, your total score would be: " << computerTotalScore + score << endl;
			if ((score >= 20) || (score + computerTotalScore >= 100))
			{
				cout << "Thr computer holds." << "Enter 'c' to continue " << endl;
				cin >> cInput;
				bTurnOver = true;
			}
		}
	} while (!bTurnOver);
	return score;
}
int main()
{
	int humanScore = 0;
	int computerScore = 0;
	bool gameOver = false;
	srand(static_cast<int>(time(NULL)));
	while(!gameOver)
	{	
		humanScore += humanTurn(humanScore);
		if (humanScore < 100)
		{
			computerScore += computerTurn(computerScore);
		}
		if (humanScore >= 100)
		{
			cout << "Congratulations, you win!" << endl;
			gameOver = true;
		}
		else if (computerScore >=100)
		{
			cout << "Sorry, the computer won." << endl;
			gameOver = true;
		}
	}
}