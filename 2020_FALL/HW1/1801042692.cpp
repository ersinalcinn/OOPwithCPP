#include <iostream>
using namespace std;
void User_1(int boardSize,int hex_Board[12][12],int selectType);
void User_2(int boardSize,int hex_Board[12][12]);
void printBoard(int boardSize,int hex_Board[12][12]);
void makeComptRand(int boardSize,int hex_Board[12][12],int x,int y);
int newPath[12][12];
void final_Upper(int boardSize,int hex_Board[12][12],int Upcell_winner){
	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			if(Upcell_winner==1){
				if(hex_Board[i][j]==120)
				{
					hex_Board[i][j]=88;
				}
			}
			else
			{
				if(hex_Board[i][j]==111)
				{
				    hex_Board[i][j]=79;
				}
			}
		}
	}
	printBoard(boardSize,hex_Board);
}
void printBoard(int boardSize,int hex_Board[12][12]){
	//The function defined to print the table on the screen. I'm kind of refreshing the table.
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
		cout<<"   ";
		for(int i=0;i<boardSize;i++){
			cout<<alpha[i]<<"  ";
		}
		cout<<"\n";
		for(int j=0;j<boardSize;j++){
			for(int k=0;k<boardSize;k++){
				if(k==0){
					cout<<j+1<<"  ";

					for(int z=0;z<j;z++){
						cout<<" ";
					}
				}
				cout<<char(hex_Board[j][k])<<"  ";
			}
			cout<<"\n";
		}
	}
void fillBoard(int boardSize,int hex_Board[12][12]){
	/*First of all, I created the array in order to make a
	condition according to the letters I will press on the screen and the location the user will enter.*/
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	cout<<"   ";
	for(int i=0;i<boardSize;i++)
	{
		cout<<alpha[i]<<"  ";
	}
	cout<<"\n";
	/*Then I filled my table with periods (.), Taking as reference the table size specified by the user.
	I made arrangements to be able to print on the screen regularly.*/
	for(int j=0;j<boardSize;j++){
		for(int k=0;k<boardSize;k++){
			hex_Board[j][k]=46; //the equivalent of the dot in the ascii table is 46
			if(k==0){
				cout<<j+1<<"  ";
				for(int z=0;z<j;z++){
					cout<<" ";
				}
			}
			cout<<char(hex_Board[j][k])<<"  ";//I printed the 46 points on the screen as letters
		}
		cout<<"\n";
	}
}
int findPath(int x,int y,int boardSize,int hex_Board[12][12]){
	/*First of all, in this function,
	 * I checked that the y value I send in the first condition is not less than boardSize.
	 * If the value of y is equal to the value of boardSize, my condition will be met and return will return 1.
	 * Later, in my second condition, I used the condition according to whether the value is 'X' or 'Y'.
	 *  Thinking that there are different cases since they will start from the left and from the top. */
if(y<boardSize-1)
{
	if(hex_Board[x][y]==120)
	{
		/*First, I created a globally multidimensional array, to check
		 * where it is going through this array, to check if user 1 has taken the necessary steps to win the game.
		 *I check that he can reach the end of the game from the locations
		 *I he went to, if I wrote 1 in the reference table I just created to the
		 *I  regions he went to, in order not to pass the places he went to.
		 *it progresses by finding the X value in different locations,
		 *I reach the result by visiting the places that are X and 0 in the reference table.
		 *I have checked the positions using labyrinth recursion.
		 *I If the position is full, it returns to the starting point
		 *I by stepping back if there is no end of the position.
		 *I I tried to determine the winner by trying any path again	 */
		if (hex_Board[x+1][y]==120 && newPath[x+1][y]==0)  { newPath[x+1][y]=1; return findPath(x+1,y,boardSize,hex_Board);}
		if (hex_Board[x][y + 1]==120 && newPath[x][y+1]==0)   {newPath[x][y+1]=1; return findPath(x,y+1,boardSize,hex_Board);}
		if (hex_Board[x+1][y-1]==120 && newPath[x+1][y-1]==0)  { newPath[x+1][y-1]=1; return findPath(x+1,y-1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y +1]==120 && newPath[x-1][y+1]==0) {newPath[x-1][y+1]=1; return findPath(x-1,y+1,boardSize,hex_Board);}
		if (hex_Board[x][ y - 1]==120 && newPath[x][y-1]==0)  {newPath[x][y-1]=1; return findPath(x,y-1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y]==120 && newPath[x-1][y]==0)  {newPath[x][y]=1;return findPath(x-1,y,boardSize,hex_Board);}
		for(int j=0;j<boardSize;j++){
			for(int k=0;k<boardSize;k++){
				newPath[j][k]=0;
			}
		}
	}
}else return 1; //By returning 1, I am sending that user 1 won the game.
//Here, as above, I checked from X position this time. Then I checked if the position is 0.
if(x<boardSize-1)
{
	if(hex_Board[x][y]==111)
	{
		if (hex_Board[x+1][y]==111 && newPath[x+1][y]==0)  { newPath[x+1][y]=1; return findPath(x+1,y,boardSize,hex_Board);}
		if (hex_Board[x][y + 1]==111 && newPath[x][y+1]==0)   {newPath[x][y+1]=1; return findPath(x,y+1,boardSize,hex_Board);}
		if (hex_Board[x+1][y-1]==111 && newPath[x+1][y-1]==0)  { newPath[x+1][y-1]=1; return findPath(x+1,y-1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y +1]==111 && newPath[x-1][y+1]==0) {newPath[x-1][y+1]=1; return findPath(x-1,y+1,boardSize,hex_Board);}
		if (hex_Board[x][ y - 1]==111 && newPath[x][y-1]==0)  {newPath[x][y-1]=1; return findPath(x,y-1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y]==111 && newPath[x-1][y]==0)  {newPath[x][y]=1;return findPath(x-1,y,boardSize,hex_Board);}
		for(int j=0;j<boardSize;j++){
			for(int k=0;k<boardSize;k++){
				newPath[j][k]=0;
			}
		}
	}
		}else return 2; //I reverted user 2 or computer won
}
void makeComptRand(int boardSize,int hex_Board[12][12],int x,int y)
{
	int ct,result=0;
	char ch;
	/*I wrote my if conditions to determine a random value next to the entered position in the table.
	 * Write to these conditions, I provided the necessary if conditions to put '0' next to it regardless of the position.
	 *I aimed for him to win the game by providing much better defense against the user
	 */
	if(hex_Board[x+1][y]==46) hex_Board[x+1][y]=111;
	else if(hex_Board[x][y+1]==46) hex_Board[x][y+1]=111;
	else if(hex_Board[x-1][y]==46) hex_Board[x-1][y]=111;
	else if(hex_Board[x][y-1]==46) hex_Board[x][y-1]=111;
	else if(hex_Board[x-1][y+1]==46) hex_Board[x-1][y+1]=111;
	else if(hex_Board[x+1][y-1]==46) hex_Board[x+1][y-1]=111;
	/* Then, to avoid any problems, I wrote the else condition.
	 * If any of the positions I specified in this condition are not met,
	 * I put '0' to the first empty row and column in the table starting from 0.*/
	else {
		for(int i=0;i<boardSize;i++){
			for(int k=0;k<boardSize;k++){
				if(hex_Board[i][k]==46){
					hex_Board[i][k]=111;
					i=boardSize;
					break;
				}
			}
		}
	}
	for(int i=0;i<boardSize;i++)
	{
		if(hex_Board[0][i]==111)////I added the initial initial values ​​to the findpath function and directed it to the function.
		{
			result=findPath(0,i,boardSize,hex_Board);
		}
	}
	cout<<"Computer:\n";
	printBoard(boardSize,hex_Board);//I printed the table again for the user to see the location.
	if(result==2)//If the value returned from the Findpath function is 2, I indicate that the Computer won the game
	{
		cout<<"Computer WIN!\n";
		final_Upper(boardSize,hex_Board,2);

	}
	else User_1(boardSize,hex_Board,2);////SelectyType means user_1 is selected. I ran the user_1 function.

}
void User_1(int boardSize,int hex_Board[12][12],int selectType)
{
	//To be able to use it in my for condition so I have defined the alphabet sequence here as well.for loop
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	char ch;
	int ct,x,y,result=0,k,k1,check=0;
	cout << "1.User Move to :";//I get location from user 1
	cin >>ch>>ct;
	/*I pulled the letter and number the user entered. Then I checked the letter he entered in the sequence.
	 * I found the appropriate value for the condition and used the index in the array to check hex_Board with the if condition.
	 *Assign the 'X' value of 120 to that position after passing the condition.
	 *Since I will pass the variables k and k1 to the function, I assign the positions to them as temporary variables.
	 *I used the check variable to check if the position is empty or not and issue a warning.
	 *I If the condition is met, the value of the variable will be 1 */
	for(int t=0;t<12;t++)
	{
		if(alpha[t]==ch && hex_Board[ct-1][t]==46)
		{
			check=1;
			hex_Board[ct-1][t]=120;
			k=ct-1;
			k1=t;
		}
	}
	//If the entered location is full, I printed the error message on the screen and called the 1.user function again.
	if(check!=1)
	{
		printBoard(boardSize,hex_Board);
		cout<<"Try again..\n";
		User_1(boardSize,hex_Board,selectType);
	}
	else
		/*If check is 1, I first refreshed my hex_Board table.
		 *Then,I am looking for an X in this region with [i] [0] starting zone. If X exists I called my findpath function.		 */
	{
		printBoard(boardSize,hex_Board);
		for(int i=0;i<boardSize;i++)
		{
			if(hex_Board[i][0]==120)
			{
				x=i;
				result=findPath(x,0,boardSize,hex_Board);//I added the initial initial values ​​to the findpath function and directed it to the function.
			}
		}
		if(result==1)//If the value returned from the Findpath function is 1, I indicate that the 1st user won the game
		{
			final_Upper(boardSize,hex_Board,1);
			cout<<"1.USER WIN\n";

		}
		else
			/*Here, I differentiate between selectType and uservsuser or uservscomp.
			 If uservsuser is selected, the value 1 will work and the user_2 function will run to enter the value of user 2*/
		{
			if(selectType==1) User_2(boardSize,hex_Board);
			else makeComptRand(boardSize,hex_Board,k,k1);//SelectyType means uservscomp is selected. I ran the computerrand function.
		}
	}
}
void User_2(int boardSize,int hex_Board[12][12])
{
	//To be able to use it in my for condition so I have defined the alphabet sequence here as well.for loop
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	char ch;
	int ct,result=0,check=0,x,y;
	cout << "2.User Move to :";//I get location from user 1
	cin >>ch>>ct;
	/*I pulled the letter and number the user entered. Then I checked the letter he entered in the sequence.
		 * I found the appropriate value for the condition and used the index in the array to check hex_Board with the if condition.
		 *Assign the '0' value of 111 to that position after passing the condition.
		 *Since I will pass the variables k and k1 to the function, I assign the positions to them as temporary variables.
		 *I used the check variable to check if the position is empty or not and issue a warning.
		 *I If the condition is met, the value of the variable will be 1 */
	for(int t=0;t<12;t++){
		if(alpha[t]==ch && hex_Board[ct-1][t]!=120)
		{
			check=1;
			hex_Board[ct-1][t]=111;
		}
	}
	//If the entered location is full, I printed the error message on the screen and called the 2.user function again.
	if(check!=1)
	{
		printBoard(boardSize,hex_Board);
		cout<<"Try again..\n";
		User_2(boardSize,hex_Board);
	}
	else
		/*If check is 1, I first refreshed my hex_Board table.
		 *Then,I am looking for an X in this region with [i] [0] starting zone. If X exists I called my findpath function.		 */
	{
		printBoard(boardSize,hex_Board);
		for(int i=0;i<boardSize;i++)
		{
			if(hex_Board[0][i]==111)
			{
				y=i;
				result=findPath(0,y,boardSize,hex_Board);
			}
		}
		if(result==2)//If the value returned from the Findpath function is 2, I indicate that the 2nd user won the game
		{
			cout<<"2.USER WIN\n";
			final_Upper(boardSize,hex_Board,2);

		}
		else User_1(boardSize,hex_Board,1);//SelectyType means user_1 is selected. I ran the user_1 function.
	}
}
int main() {
	/*[12] [12] I have created the double-size hex_Board array.
	  I have defined the necessary variables.
	  I have written my if conditions according to the user response.*/
	/*-->The user can play the game by entering a value such as a1 b5 d3 e6.*/
	int boardSize,selectType;
	int hex_Board[12][12];
	cout << "===============================================\n";
	cout << "Please enter board size :";
	cin >>boardSize;
	if(boardSize>=6 && boardSize<=12){
		cout <<"Please Select Game Mode\n\n";
		cout << "1-User vs User \n2-User vs Computer\nSelect:";
		cin >>selectType;
		/*I have called my functions that meet the condition of the user's
		response and sent it to the function to create the table for you.*/
		if(selectType==1){
			cout << "\n1-User vs User Selected\n\n";
			fillBoard(boardSize,hex_Board);
			User_1(boardSize,hex_Board,selectType);
		}
		else if(selectType==2) {
			cout << "\n1-User vs Computer Selected\n\n";
			fillBoard(boardSize,hex_Board);
			User_1(boardSize,hex_Board,selectType);
		}
		else cout << "Wrong Selection.\n" << endl;
	}
	else  cout << "Wrong Board Size.Select:[6-12]\n" << endl;
	return 0;
}

