#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
/*
	Define template class for movie, book, music.
*/
/* -----------------------MOVIE */
template <class T,class T1,class T2,class T3,class T4>
class movie {
    T title;
    T1 director;
    T2 year;
    T3 genre;
    T4 starring;
  public:
  	movie()
  	{

  	}
    movie (T _Title, T1 _director,T2 _year,T3 _genre,T4 _starring)
      {title=_Title; director=_director; year=_year; genre=_genre; starring=_starring;}
    T getTitle ();
    T1 getDirector ();
    T2 getYear ();
    T3 getGenre ();
    T4 getStarring();
    void setTitle (T _Title);
    void setDirector (T1 _director);
    void setYear (T2 _year);
    void setGenre (T3 _genre);
    void setStarring (T4 _starring);
};
/* -----------------------MUSIC */
template <class T,class T1,class T2,class T3>
class music {
    T title;
    T1 artists;
    T2 year;
    T3 genre;
  public:
  	music()
  	{

  	}
    music (T _Title, T1 _artists,T2 _year,T3 _genre)
      {title=_Title; artists=_artists; year=_year; genre=_genre;}
    T getTitle ();
    T1 getArtists ();
    T2 getYear ();
    T3 getGenre ();
    void setTitle (T _Title);
    void setArtists (T1 _artists);
    void setYear (T2 _year);
    void setGenre (T3 _genre);
};
/* -----------------------MOVIE */
template <class T,class T1,class T2,class T3>
class book {
    T title;
    T1 authors;
    T2 year;
    T3 tags;
  public:
  	book()
  	{

  	}
    book (T _Title, T1 _authors,T2 _year,T3 _tags)
      {title=_Title; authors=_authors; year=_year; tags=_tags;}
    T getTitle ();
    T1 getAuthors ();
    T2 getYear ();
    T3 getTags ();
    void setTitle (T _Title);
    void setAuthors (T1 _authors);
    void setYear (T2 _year);
    void setTags (T3 _tags);
};
/* ------------Movie Class Getters */
template <class T,class T1,class T2,class T3,class T4>
T movie<T,T1,T2,T3,T4>::getTitle ()
{
  return title;
}
template <class T,class T1,class T2,class T3,class T4>
T1 movie<T,T1,T2,T3,T4>::getDirector ()
{
  return director;
}
template <class T,class T1,class T2,class T3,class T4>
T2 movie<T,T1,T2,T3,T4>::getYear ()
{
  return year;
}
template <class T,class T1,class T2,class T3,class T4>
T3 movie<T,T1,T2,T3,T4>::getGenre ()
{
  return genre;
}
template <class T,class T1,class T2,class T3,class T4>
T4 movie<T,T1,T2,T3,T4>::getStarring ()
{
  return starring;
}
/* ------------Movie Class Setters */
template <class T,class T1,class T2,class T3,class T4>
void movie<T,T1,T2,T3,T4>::setTitle(T _Title)
{
	title = _Title;
}
template <class T,class T1,class T2,class T3,class T4>
void movie<T,T1,T2,T3,T4>::setDirector(T1 _director)
{
    director = _director;
}
template <class T,class T1,class T2,class T3,class T4>
void movie<T,T1,T2,T3,T4>::setYear(T2 _year)
{
    year = _year;
}
template <class T,class T1,class T2,class T3,class T4>
void movie<T,T1,T2,T3,T4>::setGenre(T3 _genre)
{
	genre = _genre;
}
template <class T,class T1,class T2,class T3,class T4>
void movie<T,T1,T2,T3,T4>::setStarring(T4 _starring)
{
	starring = _starring;
}

/* ------------Music Class Getters */
template <class T,class T1,class T2,class T3>
T music<T,T1,T2,T3>::getTitle ()
{
  return title;
}
template <class T,class T1,class T2,class T3>
T1 music<T,T1,T2,T3>::getArtists ()
{
  return artists;
}
template <class T,class T1,class T2,class T3>
T2 music<T,T1,T2,T3>::getYear ()
{
  return year;
}
template <class T,class T1,class T2,class T3>
T3 music<T,T1,T2,T3>::getGenre ()
{
  return genre;
}

/* ------------Musc Class Setters */
template <class T,class T1,class T2,class T3>
void music<T,T1,T2,T3>::setTitle(T _Title)
{
	title = _Title;
}
template <class T,class T1,class T2,class T3>
void music<T,T1,T2,T3>::setArtists(T1 _artists)
{
    artists = _artists;
}
template <class T,class T1,class T2,class T3>
void music<T,T1,T2,T3>::setYear(T2 _year)
{
    year = _year;
}
template <class T,class T1,class T2,class T3>
void music<T,T1,T2,T3>::setGenre(T3 _genre)
{
	genre = _genre;
}

/* ------------Book Class Getters */
template <class T,class T1,class T2,class T3>
T book<T,T1,T2,T3>::getTitle ()
{
  return title;
}
template <class T,class T1,class T2,class T3>
T1 book<T,T1,T2,T3>::getAuthors ()
{
  return authors;
}
template <class T,class T1,class T2,class T3>
T2 book<T,T1,T2,T3>::getYear ()
{
  return year;
}
template <class T,class T1,class T2,class T3>
T3 book<T,T1,T2,T3>::getTags ()
{
  return tags;
}

/* ------------Book Class Setters */
template <class T,class T1,class T2,class T3>
void book<T,T1,T2,T3>::setTitle(T _Title)
{
	title = _Title;
}
template <class T,class T1,class T2,class T3>
void book<T,T1,T2,T3>::setAuthors(T1 _authors)
{
    authors = _authors;
}
template <class T,class T1,class T2,class T3>
void book<T,T1,T2,T3>::setYear(T2 _year)
{
    year = _year;
}
template <class T,class T1,class T2,class T3>
void book<T,T1,T2,T3>::setTags(T3 _tags)
{
	tags = _tags;
}
   
int main()
{
	//I created vector arrays of type template class to hold the data.
	vector<book<string,string,int,string>> bookVector;
	vector<music<string,string,int,string>> musicVector;
	vector<movie<string,string,int,string,string>> movieVector;

	//Input and ouput 
	ifstream readData("data.txt");
	ifstream readCommand("command.txt");
	ofstream writeFile("output.txt");

	//Variables
	string catalog_name, tempWord, command, word, field, new_tmp;
	int counter=0, check = 0, count = 0, year = 0; 

	/*
		I open the file and the first line of the file determines which catalog to keep. 
		I read the first line and then fill my data into vectors according to the catalog in the first line.
	*/
	if(readData.is_open())
	{
			getline(readData,catalog_name);
			if(catalog_name=="book")
			{
				/*
					If my catalog type is book, I run it with a for loop 4 times for each row,
					 since there are 4 different data types.
				*/
				bookVector.clear();
				while(!readData.eof())
				{
					book<string,string,int,string> data;
					for(int i = 0 ; i < 4 ; i++)
					{
						getline(readData,tempWord,'"');
						getline(readData,tempWord,'"');
						
						//First data title
						if(i == 0)
						{
							data.setTitle(tempWord);	
						}
						//Second data authors
						if(i == 1)
						{
							data.setAuthors(tempWord);
						}
						//Third data year
						if(i == 2)
						{
							stringstream years(tempWord);
							years>>year;
							data.setYear(year);
						}
						//Last data tags
						if(i==3)
						{
							data.setTags(tempWord);
						}
						
					}
					/*
						If we have not come to the end of the file,
						 we fill our vector with push back and write our data to my output file.
					*/
					if(!readData.eof()  )
					{
						bookVector.push_back(data);
						writeFile<<'"'<<bookVector[counter].getTitle()<<'"'<< " ";
						writeFile<<'"'<<bookVector[counter].getAuthors()<<'"'<<" ";
						writeFile<<'"'<<bookVector[counter].getYear()<<'"'<<" ";
						writeFile<<'"'<<bookVector[counter].getTags()<<'"'<<" ";
						writeFile<<endl;
						counter++;
					}
				
					
					
				}
				writeFile<<bookVector.size()<<" unique entries"<<endl;
				
				
				
			}
			if(catalog_name=="music")
			{
				/*
					If my catalog type is music, I run it with a for loop 4 times for each row,
					 since there are 4 different data types.
				*/
				writeFile<<"Catalog Read:"<<catalog_name<<endl;
				musicVector.clear();
				while(!readData.eof())
				{
					music<string,string,int,string> data;
					for(int i = 0 ; i < 4 ; i++)
					{
						getline(readData,tempWord,'"');
						getline(readData,tempWord,'"');
						
						if(i == 0)
						{
							data.setTitle(tempWord);
						}
						if(i == 1)
						{
							data.setArtists(tempWord);
						}
						if(i == 2)
						{
							stringstream years(tempWord);
							years>>year;
							data.setYear(year);
						}
						if(i == 3)
						{
							data.setGenre(tempWord);

						}
						

					}
					/*
						If we have not come to the end of the file,
						 we fill our vector with push back and write our data to my output file.
					*/
					if(!readData.eof() && check == 0 )
					{
						musicVector.push_back(data);
						writeFile<<'"'<<musicVector[counter].getTitle()<<'"'<< " ";
						writeFile<<'"'<<musicVector[counter].getArtists()<<'"'<<" ";
						writeFile<<'"'<<musicVector[counter].getYear()<<'"'<<" ";
						writeFile<<'"'<<musicVector[counter].getGenre()<<'"'<<" ";
						writeFile<<endl;
						counter++;
					}
					check=0;

				}
				writeFile<<musicVector.size()<<" unique entries"<<endl;

				
			}
			if(catalog_name=="movie")
			{
				/*
					If my catalog type is movie, I run it with a for loop 4 times for each row,
					 since there are 5 different data types.
				*/
				movieVector.clear();
				while(!readData.eof())
				{
					movie<string,string,int,string,string> data;
					for(int i = 0 ; i < 5 ; i++)
					{
						getline(readData,tempWord,'"');
						getline(readData,tempWord,'"');
						
						if(i == 0)
						{
							data.setTitle(tempWord);
							
						}
						if(i == 1)
						{
							data.setDirector(tempWord);
						}
						if(i == 2)
						{
							stringstream years(tempWord);
							years>>year;
							data.setYear(year);
						}
						if(i==3)
						{
							data.setGenre(tempWord);
						}
						if(i==4)
						{
							data.setStarring(tempWord);
						}
						

					}
					/*
						If we have not come to the end of the file,
						 we fill our vector with push back and write our data to my output file.
					*/
					if(!readData.eof() )
					{
						movieVector.push_back(data);
						writeFile<<'"'<<movieVector[counter].getTitle()<<'"'<< " ";
						writeFile<<'"'<<movieVector[counter].getDirector()<<'"'<<" ";
						writeFile<<'"'<<movieVector[counter].getYear()<<'"'<<" ";
						writeFile<<'"'<<movieVector[counter].getGenre()<<'"'<<" ";
						writeFile<<'"'<<movieVector[counter].getStarring()<<'"'<<" ";
						writeFile<<endl;
						counter++;
					}							
				}
				writeFile<<movieVector.size()<<" unique entries"<<endl;
				
			}
		
		
	}
	/*
		I just read the command file and couldn't do the search and sort parts.
	*/
	if(readCommand.is_open())
	{
		getline(readCommand,tempWord);
		writeFile<< tempWord;
		
	}
	
}
