#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
/*---------------------------------------------------------*/
int generateNumber(int digit);
int findDigit(int number);
int fillArray(int digitOfNumber[],int number,int digit);
int matchNumber(int digitOfNumber_1[],int digitOfNumber_2[],int digit);
int checkDigit(int digitOfNumber[],int digit);
/*-----------------------------------------------------------*/
/*The generateNumber [] function randomly determines a number */
/*according to the number of digits specified by the user and saves this number to the array.*/
int generateNumber(int digit,int number[])
{
	int counter = 0, control=0, i=0, value;
	do
	{
		value = rand() % 10 ;
		if (value == 0 && counter == 0)
		{
			value = (rand() % 9 ) + 1 ;
		}
		for (int i = 0; i < digit; ++i)
		{
			if (number[i] == value)
			{
				control++;
			}
		}
		if (control == 0)
		{
			number[counter]=value;
			counter++;
		}
		control=0;
	} while (counter != digit);
}
/*-----------------------------------------------------------*/
/*Finding the number of digits of the number entered by the user and returning the number*/
int findDigit(int number)
{
	int digit = 0, counter =0, temp;
	temp = number;
	do
	{
		number = number / 10;
		digit++;
	} while (number!=0);
	return digit;
	
}
/*-----------------------------------------------------------*/
/*Pressing this function fills the number with the number and */
/*the digit value of that number into a new array array in this function.*/
int fillArray(int digitOfNumber[],int number,int digit)
{
	int counter = 0;
	do
	{
		digitOfNumber[(digit-1)-counter]=number % 10;
		number = number / 10;
		counter++;
	} while (number!=0);
	
	return digit;
}
/*-----------------------------------------------------------*/
/*I keep the numbers and the misplaced numbers,*/
/*which are found as random or not, so that the user can guess */
/*the number he entered at the beginning and print it on the screen.*/
int matchNumber(int digitOfNumber_1[],int digitOfNumber_2[],int digit)
{
	int countExact = 0, countMisplaced = 0, i = 0, j = 0;
	for ( i = 0; i < digit; i++)
	{
		if (digitOfNumber_1[i] == digitOfNumber_2[i])
		{
			countExact++;
		}
		else
		{
			for ( j = 0; j < digit; j++)
			{
				if (digitOfNumber_2[i] == digitOfNumber_1[j])
				{
					countMisplaced++;
				}
			}
		}
	}
	cout << countExact << " " << countMisplaced << endl;
	return countExact;
}
/*-----------------------------------------------------------*/
/*I compare the number of digits of the numbers between*/
/* the two strings and check whether their elements are between 0 and 9.*/
int checkDigit(int digitOfNumber[],int digit)
{
	int counter = 0, i = 0;
	for (i = 0; i < digit; ++i)
	{
		if (digitOfNumber[i]>=0 && digitOfNumber[i]<=9)
		{
			counter++;
		}
	}
	if (counter == digit)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	//Variable defined
	int gameCounter = 1, checkMatch = 0, check_Digit = 0, digit, number;
	srand(static_cast<int>(time(NULL)));
	if (argv[1][0] == '-' && argv[1][1] == 'r' && argv[2] != NULL && argv[2][0] != '0')
	{
		/*I convert the value this user enters after -r to integer value with stringstream function*/
		/*then it checks whether the entered digit is within the given range and performs the necessary conditions.*/
		stringstream geek(argv[2]);
		geek >> digit;
		if (digit > 0 && digit <= 9)
		{
			int Number_1[digit];
			int Number_2[digit];
			int userNumber;
			generateNumber(digit,Number_1);
			do
			{
				/* I get a number from the user,									*/
				/* then I find the length of this number and						*/
				/* fill this number into the array, and then						*/
				/* I check the equality of the two numbers and the number of digits.*/
				cin >> userNumber;
				findDigit(userNumber);
				fillArray(Number_2, userNumber, findDigit(userNumber));
				check_Digit = checkDigit(Number_2,digit);
				if (check_Digit == 1)
				{
					/*if the digit entered by the user is not equal to the number generated and the number is greater than 0*/
					if (findDigit(userNumber) != digit && userNumber>0)
					{
						cerr << "E1" << endl;
						exit(1);
					}
					/* returns E1 error if the entered number is negative */
					if (userNumber < 0)
					{
						cerr << "E0" << endl;
						exit(1);
					}
					checkMatch = matchNumber(Number_1,Number_2,digit);
					if (checkMatch == digit)
					{
						cout << "FOUND " << gameCounter << endl;
						gameCounter = 100;

					}
					else if (gameCounter >= 100)
					{
						cout << "FAILED" << endl;

					}
					gameCounter++;
				}
				else
				{
					cout << "E2" << endl;
					gameCounter = 100;
					exit(1);
				}
				
			 }while (gameCounter<=100);	
		}
		else
		{
			cout << "E0" << endl;
		}
	}
	else if (argv[1][0] == '-' && argv[1][1] == 'u' && argv[2] != NULL && argv[2][0] != '0')
	{
		//Variable defined
		int number, userNumber, x = 0, digit ;
		stringstream geek(argv[2]);
		geek >> number;
		digit = findDigit(number);
		int Number_1[digit]; 
		int Number_2[digit];  
		fillArray(Number_1, number, digit);

		if (number > 0 && digit > 0 && digit <  10 && Number_1[0] != 0)
		{
			do
			{
				/* I get a number from the user,									*/
				/* then I find the length of this number and						*/
				/* fill this number into the array, and then						*/
				/* I check the equality of the two numbers and the number of digits.*/
				cin >> userNumber;
				findDigit(userNumber);
				fillArray(Number_2,userNumber, digit);
				/*if the digit entered by the user is not equal to the number generated */
				if (findDigit(userNumber) != digit)
				{
					cerr << "E1" << endl;
					exit(1);
				}
				/* returns E1 error if the entered number is negative */
				if (userNumber < 0)
				{
					cerr << "E2" << endl;
					exit(1);
				}
				checkMatch = matchNumber(Number_2,Number_1,digit);
				if (checkMatch == digit)
				{
					cout << "FOUND " << gameCounter << endl;
					gameCounter = 100;

				}
				else if (gameCounter >= 100)
				{
					cout << "FAILED" << endl;

				}

				gameCounter++;
			} while (gameCounter<=100);
		}
		else
		{
			cout << "E0" << endl;
		}
	}
	else
	{
		cerr << "E0" << endl;
		exit(1);
	}

}