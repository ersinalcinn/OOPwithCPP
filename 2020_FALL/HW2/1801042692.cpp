#include <iostream>
#include<stdlib.h> //for exit and terminal clear
#include<fstream>//for file load and save
#include<string> //for file path vs
using namespace std;
int newPath[12][12];//In order to be able to use backtracking, I find out where my reference table, which I have defined, is going by keeping 1 and 0 from here.
enum type{x=120,o=111,X=88,O=79,DOT=46};//I created the enum function according to the data type. So I can change the value I created with a single operation from anywhere.ıts so easy
void User_1(int boardSize,int hex_Board[12][12],int selectType);
void User_2(int boardSize,int hex_Board[12][12],int selectType);
void printBoard(int boardSize,int hex_Board[12][12]);
void makeComptRand(int boardSize,int hex_Board[12][12],int x,int y);
int control_Table(int hex_Board[12][12],int boardSize,int *returnValue){
	/*In this function, whether the hex table is full or not, depending on the situation, parameter by reference and a
	I am sending it back to the function with a pointer using constant parameter by reference.  */
	auto countSize=0;
	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			if(hex_Board[i][j]==type::x || hex_Board[i][j]==type::o){
				countSize++;
			}
		}
	}
	if(countSize==(boardSize*boardSize)) *returnValue=1;
	else returnValue=0;
}
void final_Upper(int boardSize,int hex_Board[12][12],int Upcell_winner){
	//As x or o, whichever won the game, I enlarge the variables in the way they won and clarify the path.
	for(int i=0;i<boardSize;i++){
		for(int j=0;j<boardSize;j++){
			if(Upcell_winner==1){
				if(newPath[i][j]==1)
				{
					hex_Board[i][j]=type::X; //if x wins the game
				}
			}
			else
			{
				if(newPath[i][j]==1)
				{
				    hex_Board[i][j]=type::O; //if o wins the game
				}
			}
		}
	}
	printBoard(boardSize,hex_Board);
}
void printBoard(int boardSize,int hex_Board[12][12]){
	//The function defined to print the table on the screen. This kind of refreshing the table.
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
			hex_Board[j][k]=type::DOT; //the equivalent of the dot in the ascii table is 46
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
	if(hex_Board[x][y]==type::x)
	{
		newPath[x][y]=1;
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
		if (hex_Board[x - 1][y]==type::x && newPath[x-1][y]==0)  {newPath[x-1][y]=1;return findPath(x-1,y,boardSize,hex_Board);}
		if (hex_Board[x][y + 1]==type::x && newPath[x][y+1]==0)   {newPath[x][y+1]=1; return findPath(x,y+1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y +1]==type::x && newPath[x-1][y+1]==0) {newPath[x-1][y+1]=1; return findPath(x-1,y+1,boardSize,hex_Board);}
		if (hex_Board[x+1][y]==type::x && newPath[x+1][y]==0)  { newPath[x+1][y]=1; return findPath(x+1,y,boardSize,hex_Board);}
		if (hex_Board[x+1][y-1]==type::x && newPath[x+1][y-1]==0)  { newPath[x+1][y-1]=1; return findPath(x+1,y-1,boardSize,hex_Board);}

		if (hex_Board[x][ y - 1]==type::x && newPath[x][y-1]==0)  {newPath[x][y-1]=1; return findPath(x,y-1,boardSize,hex_Board);}
		else newPath[x][y]=0;
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
	if(hex_Board[x][y]==type::o)
	{
		newPath[x][y]=1;
		if (hex_Board[x+1][y]==type::o && newPath[x+1][y]==0)  { newPath[x+1][y]=1; return findPath(x+1,y,boardSize,hex_Board);}
		if (hex_Board[x][y + 1]==type::o && newPath[x][y+1]==0)   {newPath[x][y+1]=1; return findPath(x,y+1,boardSize,hex_Board);}
		if (hex_Board[x+1][y-1]==type::o && newPath[x+1][y-1]==0)  { newPath[x+1][y-1]=1; return findPath(x+1,y-1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y +1]==type::o && newPath[x-1][y+1]==0) {newPath[x-1][y+1]=1; return findPath(x-1,y+1,boardSize,hex_Board);}
		if (hex_Board[x][ y - 1]==type::o && newPath[x][y-1]==0)  {newPath[x][y-1]=1; return findPath(x,y-1,boardSize,hex_Board);}
		if (hex_Board[x - 1][y]==type::o && newPath[x-1][y]==0)  {newPath[x][y]=1;return findPath(x-1,y,boardSize,hex_Board);}

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
	auto result=0;
	int ct;
	char ch;
	/*I wrote my if conditions to determine a random value next to the entered position in the table.
	 * Write to these conditions, I provided the necessary if conditions to put '0' next to it regardless of the position.
	 *I aimed for him to win the game by providing much better defense against the user
	 */
	if(hex_Board[x+1][y]==type::DOT) hex_Board[x+1][y]=type::o;
	else if(hex_Board[x][y+1]==type::DOT) hex_Board[x][y+1]=type::o;
	else if(hex_Board[x-1][y]==type::DOT) hex_Board[x-1][y]=type::o;
	else if(hex_Board[x][y-1]==type::DOT) hex_Board[x][y-1]=type::o;
	else if(hex_Board[x-1][y+1]==type::DOT) hex_Board[x-1][y+1]=type::o;
	else if(hex_Board[x+1][y-1]==type::DOT) hex_Board[x+1][y-1]=type::o;
	/* Then, to avoid any problems, I wrote the else condition.
	 * If any of the positions I specified in this condition are not met,
	 * I put '0' to the first empty row and column in the table starting from 0.*/
	else {
		for(int i=0;i<boardSize;i++){
			for(int k=0;k<boardSize;k++){
				if(hex_Board[i][k]==type::DOT){
					hex_Board[i][k]=type::o;
					i=boardSize;
					break;
				}
			}
		}
	}
	for(int i=0;i<boardSize;i++)
	{
		if(hex_Board[0][i]==type::o && result==0)////I added the initial initial values ​​to the findpath function and directed it to the function.
		{
			result=findPath(0,i,boardSize,hex_Board);
		}
	}
	system ("clear");
	//I printed the table again for the user to see the location.
	if(result==2)//If the value returned from the Findpath function is 2, I indicate that the Computer won the game
	{
		final_Upper(boardSize,hex_Board,2);
		cout<<"Computer WIN!\n";
	}
	else
	{
		printBoard(boardSize,hex_Board);
		User_1(boardSize,hex_Board,2);
	}////SelectyType means user_1 is selected. I ran the user_1 function.
}
void saveFile(int hex_Board[12][12],const int boardSize,const int selectType,const int x,string path){
	/*saveFile. This function works if the user wants to save the game. So if the user specifies "save" tag and "path" tag.
	 *If the game is uservsuser, it will print 1 if not 2 on the first line.
	 *If  the user who wants to save the game is the 1st user, 1 will write 2 if not the author.
	 *Line 3 shows the length of the game's boardSize.
	 *In the last line, it writes the hex table completely and writes to the specified txt file.
	 *I used default argument and const variable in this function
	 */
	ofstream output(path);
	output<<selectType<<"\n";
	output<<x<<"\n";
	output<<boardSize<<"\n";
	for(int i=0;i<boardSize;i++){
		for(int k=0;k<boardSize;k++){
			output<<char(hex_Board[i][k]);
		}
	}
}
void loadFile(int hex_Board[12][12],int boardSize,int selectType,string path,int selectUser=0){
	/*First, I pull the file path from the function. Then I used the lineCount variable to read the file line by line.
	 *By reading char by char I read it whenever "\ n" is not equal and assign these values ​​to the necessary variables.
	 *In the last row, I created an array with size 144 to pull the hex table (for the max value). I cast every char data I read into int and synchronized it to my array.
	 *In this function I used auto type variables and decltype..
	 */
	char line;
	auto temp=0,counter=0,result=0,y=0,count=0,x1=0;
	decltype(temp) resultBoard,lineCount;
	int loadArray[144];
	ifstream input(path);
	if(input.is_open())
	{
		while(input.get(line)){
			if(line!='\n'){
				if(lineCount==0)
				{
					if(line=='1') selectType=1;
					else selectType=2;
				}
				else if(lineCount==1)
				{
					if(line=='1') selectUser=1;
					else selectUser=2;
				}
				else if(lineCount==2 )
				{
					boardSize=(line-48);
				}
				else
				{
					loadArray[counter]=int(line);
					counter++;
				}
			}
			else lineCount++;
		}
		input.close();
		system ("clear");
		/*I closed the file and cleared the terminal screen. Then I filled the table with for loops nested into the hex table according to the size of the boardSize.
		 *Since we don't know how full the table is, I called the control_Table function so I checked the table.
		 *Finally, if the table is about to be full, I took the last step and determined who won. Or if the table is full, I aimed to finish the program by giving a warning that the game is over.*/
		for(int i=0;i<boardSize;i++){
			for(int y=0;y<boardSize;y++){
				hex_Board[i][y]=loadArray[count];
					count++;
			}
		}
		control_Table(hex_Board,boardSize,&resultBoard);
		if(resultBoard!=1)
		{
			if(selectType==1)
			{
				if(selectUser==1)
				{
					printBoard(boardSize,hex_Board);
					User_1(boardSize,hex_Board,selectType);
				}
				else
				{
					printBoard(boardSize,hex_Board);
					User_2(boardSize,hex_Board,selectType);
				}
			}
			else if(selectType==2)
			{
				if(selectUser==1)
				{
					printBoard(boardSize,hex_Board);
					User_1(boardSize,hex_Board,selectType);
				}
				else
				{
					printBoard(boardSize,hex_Board);
					User_2(boardSize,hex_Board,selectType);
				}
			}
		}
		else
		{
			for(int i=0;i<boardSize;i++)
			{
				if(hex_Board[i][0]==type::x)
				{
					x1=i;
					result=findPath(x1,0,boardSize,hex_Board);//I added the initial initial values ​​to the findpath function and directed it to the function.
				}
			}
			for(int i=0;i<boardSize;i++)
			{
				if(hex_Board[0][i]==type::o && result==0)
				{
					y=i;
					result=findPath(0,y,boardSize,hex_Board);
				}
			}
			if(result==1)//If the value returned from the Findpath function is 1, I indicate that the 1st user won the game
			{
				final_Upper(boardSize,hex_Board,1);
				cout<<"1.USER WIN\n";
			}
			if(result==2)//If the value returned from the Findpath function is 2, I indicate that the 2nd user won the game
			{
				final_Upper(boardSize,hex_Board,2);
				cout<<"2.USER WIN\n";
			}
			/*Here, I differentiate between selectType and uservsuser or uservscomp.
 	 	 	 If uservsuser is selected, the value 1 will work and the user_2 function will run to enter the value of user 2*/
			else
			{
				printBoard(boardSize,hex_Board);
				cout<<"-->GAME OVER\n";
			}
		}
	}
	else cerr<<"Unable to load game";
}
void User_1(int boardSize,int hex_Board[12][12],int selectType)
{
	//To be able to use it in my for condition so I have defined the alphabet sequence here as well.for loop
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	string ch,path;
	int ct,x,y,k,k1;
	auto result=0,check=0,resultBoard=0;
	cout << "1.User Move to :";//I get location from user 1
	cin>>ch;
	//I first read the first string expression. Here I found whether the expression specifies save, load or position.
	if(ch=="SAVE"){
		cin>>path;//I read the file extension by reading it in the second string.
		cout<<"GAME SAVED..\n";
		saveFile(hex_Board,boardSize,selectType,1,path);
		User_1(boardSize,hex_Board,selectType);
	}
	else if(ch=="LOAD"){
		cin>>path;//I read the file extension by reading it in the second string.
		cout<<"GAME İS LOADED..\n";
		loadFile(hex_Board,boardSize,selectType,path);
	}
	else
	{
		//If the location is specified, the last condition will work
		system ("clear");
		ct=int(ch[1]-48);
		for(int t=0;t<12;t++)
			{
				if(alpha[t]==ch[0] && hex_Board[ct-1][t]==type::DOT)
				{
					check=1;
					hex_Board[ct-1][t]=type::x;
					k=ct-1;
					k1=t;
				}
			}
			//If the entered location is full, I printed the error message on the screen and called the 1.user function again.
			if(check!=1)
			{
				printBoard(boardSize,hex_Board);
				cerr<<"Try again..\n";
				User_1(boardSize,hex_Board,selectType);
			}
			else
				/*If check is 1, I first refreshed my hex_Board table.
				 *Then,I am looking for an X in this region with [i] [0] starting zone. If X exists I called my findpath function.		 */
			{
				for(int i=0;i<boardSize;i++)
				{
					if(hex_Board[i][0]==type::x)
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
				/*Here, I differentiate between selectType and uservsuser or uservscomp.
				 If uservsuser is selected, the value 1 will work and the user_2 function will run to enter the value of user 2*/
				else
				{
					control_Table(hex_Board,boardSize,&resultBoard);
					if(resultBoard!=1)
					{
						printBoard(boardSize,hex_Board);
						if(selectType==1) User_2(boardSize,hex_Board,selectType);
						else makeComptRand(boardSize,hex_Board,k,k1);//SelectyType means uservscomp is selected. I ran the computerrand function.
					}
					else
					{
						printBoard(boardSize,hex_Board);
						cout<<"GAME OVER\n";
					}
				}
			}
	}
	//cin >>ch>>ct;
	/*I pulled the letter and number the user entered. Then I checked the letter he entered in the sequence.
	 * I found the appropriate value for the condition and used the index in the array to check hex_Board with the if condition.
	 *Assign the 'X' value of 120 to that position after passing the condition.
	 *Since I will pass the variables k and k1 to the function, I assign the positions to them as temporary variables.
	 *I used the check variable to check if the position is empty or not and issue a warning.
	 *I If the condition is met, the value of the variable will be 1 */
}
void User_2(int boardSize,int hex_Board[12][12],int selectType)
{
	//To be able to use it in my for condition so I have defined the alphabet sequence here as well.for loop
	char alpha[12]={'a','b','c','d','e','f','g','h','i','j','k','l'};
	string path,ch;
	auto result=0,check=0,resultBoard=0;
	int ct,x,y;
	cout << "2.User Move to :";//I get location from user 1
	/*I pulled the letter and number the user entered. Then I checked the letter he entered in the sequence.
		 * I found the appropriate value for the condition and used the index in the array to check hex_Board with the if condition.
		 *Assign the '0' value of 111 to that position after passing the condition.
		 *Since I will pass the variables k and k1 to the function, I assign the positions to them as temporary variables.
		 *I used the check variable to check if the position is empty or not and issue a warning.
		 *I If the condition is met, the value of the variable will be 1 */
		cin>>ch;
		//I first read the first string expression. Here I found whether the expression specifies save, load or position.
		if(ch=="SAVE"){
			cin>>path;//I read the file extension by reading it in the second string.
			cout<<"GAME SAVED..\n";
			saveFile(hex_Board,boardSize,selectType,2,path);
			User_2(boardSize,hex_Board,selectType);

		}
		else if(ch=="LOAD"){
			cin>>path;//I read the file extension by reading it in the second string.
			cout<<"GAME İS LOADED..\n";
			loadFile(hex_Board,boardSize,selectType,path);
		}
		else
		{
			//If the location is specified, the last condition will work
			system ("clear");
			ct=int(ch[1]-48);
	for(int t=0;t<12;t++){
		if(alpha[t]==ch[0] && hex_Board[ct-1][t]==type::DOT )
		{
			check=1;
			hex_Board[ct-1][t]=type::o;
		}
	}
	//If the entered location is full, I printed the error message on the screen and called the 2.user function again.
	if(check!=1)
	{
		printBoard(boardSize,hex_Board);
		cerr<<"Try again..\n";
		User_2(boardSize,hex_Board,selectType);
	}
		/*If check is 1, I first refreshed my hex_Board table.
		 *Then,I am looking for an X in this region with [i] [0] starting zone. If X exists I called my findpath function.		 */
	else
	{
		for(int i=0;i<boardSize;i++)
		{
			if(hex_Board[0][i]==type::o && result==0)
			{
				y=i;
				result=findPath(0,y,boardSize,hex_Board);
			}
		}
		if(result==2)//If the value returned from the Findpath function is 2, I indicate that the 2nd user won the game
		{
			final_Upper(boardSize,hex_Board,2);
			cout<<"2.USER WIN\n";
		}
		else
		{
			control_Table(hex_Board,boardSize,&resultBoard);
			if(resultBoard!=1)
			{
				printBoard(boardSize,hex_Board);
				User_1(boardSize,hex_Board,1);
			}//SelectyType means user_1 is selected. I ran the user_1 function.
			else
			{
				printBoard(boardSize,hex_Board);
				cout<<"GAME OVER\n";
			}
		}

	}
  }
}
int main() {
	system ("clear");
	/*[12] [12] I have created the double-size hex_Board array.
	  I have defined the necessary variables.
	  I have written my if conditions according to the user response.*/
	/*-->The user can play the game by entering a value such as a1 b5 d3 e6.*/
	auto lineCount=0,counter=0;
	int boardSize,selectType;
	int loadArray[144];
	int hex_Board[12][12];
	cout << "===============================================\n";
	cout<<"[6]->6x6\n[7]->7x7\n[8]->8x8\n[9]->9x9\n[10]->10x10\n[11]->11x11\n[12]->12x12\n";
	cout << "Please enter board size :";

	cin >>boardSize;
	if(boardSize>=6 && boardSize<=12){
		cout <<"Please Select Game Mode\n\n";
		cout << "1-User vs User \n2-User vs Computer\nSelect:";
		cin >>selectType;/*I have called my functions that meet the condition of the user's response and sent it to the function to create the table for you.*/
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
		else cerr << "Wrong Selection.\n" << endl;
	}
	else  cerr << "Wrong Board Size.Select:[6-12]\n" << endl;
	return 0;
}

