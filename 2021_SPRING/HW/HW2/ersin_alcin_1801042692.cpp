#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*Keep this auxiliary class in the vector, seperate colors R, G, B from others*/
class Pixel 
{
public:
	string R, G, B;
};
class ppmImage
{
public:

	ppmImage();  //default constructor
	ppmImage(ppmImage& ppm_file_name); // Consructor takes a ppm file name
	ppmImage(int , int ); //Constructor takes height and weight 

	int getHeight() const;  //Getter functions
	int getWidth()  const;
	int getSize()  const;
	string getPixels_R(int , int ) const;
	string getPixels_G(int , int ) const;
	string getPixels_B(int , int ) const;

	void setWH(int,int); 	//Setter functions
	void setPixels_R(int , int , string );
	void setPixels_G(int , int , string );
	void setPixels_B(int , int , string );
	void setSize(int);

	void print_ppm_dimension();  //Prints the size information of the ppmImage object.
	int save_ppm(const string& path); //Save file process
	friend ofstream& operator << (ofstream& out, ppmImage &file); //Overwriting the file with operator overloading
	friend ostream& operator << (ostream& out, ppmImage &file);   //Print screen with operator overloading
	friend ifstream& operator >> (ifstream& in, ppmImage &file);  //Reading the file with operator overloading
		
private:
	 int height;
	 int width;
	 int size; 
	 vector<vector<Pixel> > pixels;	 //2D vector  keeps color information in the vector's position information.
};
ppmImage::ppmImage(){
	width = 0; 		//default constructor takes the size information 0 to start. 
	height = 0;
}
ppmImage::ppmImage(int x, int y){

	/*
		Constructor takes height and weight parameters
		Keeps the initial color information to white and
		size is 255.
	*/
	Pixel _pixel;
	width = y;
	height = x;
	size = 255;
	for (int i = 0; i < height; ++i)
	{
		vector<Pixel> p1;
		for (int j = 0; j < width; ++j)
		{
			_pixel.R = "255";
			_pixel.G = "255";
			_pixel.B = "255";
			p1.push_back(_pixel);
		}
		pixels.push_back(p1);
	}
}

/////////////////////////////////////////////////  GETTERS  /////////////////////////////////////////////////
int ppmImage::getWidth() const{
	return width;
}
int ppmImage::getHeight() const {
	return height;
}
int ppmImage::getSize()  const{
	return size;
}
string ppmImage::getPixels_R(int a, int b) const{
	return pixels[a][b].R;
}
string ppmImage::getPixels_G(int a, int b) const{
	return pixels[a][b].G;
}
string ppmImage::getPixels_B(int a, int b) const{
	return pixels[a][b].B;
}
////////////////////////////////////////////////  SETTERS  ///////////////////////////////////////////////////
void ppmImage::setWH(int a, int b){
	width = b;
	height = a;
}
void ppmImage::setSize(int _size){
	size = _size;
}
void ppmImage::setPixels_R(int a, int b,string value){
	pixels[a][b].R = value ;
}
void ppmImage::setPixels_G(int a, int b,string value){
	pixels[a][b].G = value ;
}
void ppmImage::setPixels_B(int a, int b,string value){
	pixels[a][b].B = value ;
}

/*
	Using operator overloading to save the read file information to new files to save.
*/
ofstream& operator << (ofstream& out, ppmImage &file){
	out << "P3"<<endl;
	out << file.getHeight() << " " << file.getWidth() << endl;
	out << file.getSize() << endl;
	for (int i = 0; i < file.height; ++i)
	{
		for (int j = 0; j < file.width; ++j)
		{
			out << file.pixels[i][j].R  << " ";
			out << file.pixels[i][j].G  << " ";
			out << file.pixels[i][j].B  << " ";
		}
		out << endl;
	}
}
/*
	Print the screen 
*/
ostream& operator << (ostream& out, ppmImage &file){
	out << "P3"<<endl;
	out << file.getHeight() << " " << file.getWidth() << endl;
	out << file.getSize() << endl;
	for (int i = 0; i < file.height; ++i)
	{
		for (int j = 0; j < file.width; ++j)
		{
			out << file.pixels[i][j].R  << " ";
			out << file.pixels[i][j].G  << " ";
			out << file.pixels[i][j].B  << " ";
		}
		out << endl;
	}
}
/*
	The funciton of operator overloading where I perform the reading file >> operations.
	Performs control of P3 data.
	It checks the value of 255 and performs the saving.
	It enables the color information to be save and stored seperately as R, G, B.
*/
ifstream& operator >> (ifstream& in, ppmImage& file)
{
	string _P3, _width, _height, _size;
	string _R, _G, _B;
	Pixel _pixel;
	if(in.is_open()){
		in >> _P3;
		if(_P3 == "P3")
		{
			
			in >> _height >> _width ;
			file.setWH(atoi(_width.c_str()),atoi(_height.c_str()) );
			in >> _size;
			file.setSize(atoi(_size.c_str()));
			for (int i = 0; i < file.getHeight(); ++i)
			{
				vector<Pixel> p1;
				for (int j = 0; j < file.getWidth(); ++j)
				{
					in >> _R >> _G >> _B ;
					_pixel.R = _R;
					_pixel.G = _G;
					_pixel.B = _B;
					p1.push_back(_pixel);
				}
				file.pixels.push_back(p1);
			}
		}
		else
		{
			cout << "Header File name not equal to P3.";
		}
	}
	else
	{
		cout << "The file could not  be opened.!";
	}
}

void ppmImage::print_ppm_dimension(){   //////////Prints the size information of the ppmImage object.
	cout << *this;
}
int ppmImage::save_ppm(const string& path){   
	ofstream fp(path);
	fp << *this;
	fp.close();
}

	//////////////////////////////////// STANDOLE FUNCTIONS  ////////////////////////////
/*
read_ppm functions runs the operator overlading and reading the file.
*/
int read_ppm(const string source_ppm_file_name, ppmImage& destination_object){ 
	ifstream fp(source_ppm_file_name);
	fp >> destination_object;
	fp.close();
	return 1;
}
/*
write_ppm functions runs the operator overlading and writing the file.
*/
int write_ppm(const string destination_ppm_file_name,  ppmImage& source_object){
	source_object.save_ppm(destination_ppm_file_name);
}
/*
	The data in the R, G , B color channels to be able to replace them.
	swap_choice = 2 ( Red and green swap values ) 
	swap_choice = 3 ( Red and blue swap values ) 
	swap_choice = 4 ( blue and green swap values ) 
*/
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice)
{
	string temp ;
	if(swap_choice == 2 )
	{
		for (int i = 0; i < image_object_to_be_modified.getHeight(); i++)
		{
			for (int j = 0; j < image_object_to_be_modified.getWidth(); j++)
			{
				temp = image_object_to_be_modified.getPixels_G(i,j);
				image_object_to_be_modified.setPixels_G(i,j,image_object_to_be_modified.getPixels_R(i,j));
				image_object_to_be_modified.setPixels_R(i,j,temp);
			}
		}
	}
	else if(swap_choice == 3 )
	{
		for (int i = 0; i < image_object_to_be_modified.getHeight(); i++)
		{
			for (int j = 0; j < image_object_to_be_modified.getWidth(); j++)
			{
				temp = image_object_to_be_modified.getPixels_B(i,j);
				image_object_to_be_modified.setPixels_B(i,j,image_object_to_be_modified.getPixels_R(i,j));
				image_object_to_be_modified.setPixels_R(i,j,temp);
			}
		}
	}
	else if(swap_choice == 4 )
	{
		for (int i = 0; i < image_object_to_be_modified.getHeight(); i++)
		{
			for (int j = 0; j < image_object_to_be_modified.getWidth(); j++)
			{
				temp = image_object_to_be_modified.getPixels_B(i,j);
				image_object_to_be_modified.setPixels_B(i,j,image_object_to_be_modified.getPixels_G(i,j));
				image_object_to_be_modified.setPixels_G(i,j,temp);
			}
		}
	}
	else{
		return 0;
	}
	return 1;
}
/*
	The function resets all color values except the desired color.
	color_choice= 1 ( blue and green swap 0 ) 
	color_choice = 2 ( Red and blue swap 0 ) 
	color_choice = 3 ( red and green swap 0 ) 
*/
ppmImage& single_color( ppmImage& source, int color_choice){
	if(color_choice == 1)
	{
		for (int i = 0; i < source.getHeight(); i++)
		{
			for (int j = 0; j < source.getWidth(); j++)
			{
				source.setPixels_B(i,j,"0");
				source.setPixels_G(i,j,"0");
			}
		}
	}
	if(color_choice == 2)
	{
		for (int i = 0; i < source.getHeight(); i++)
		{
			for (int j = 0; j < source.getWidth(); j++)
			{
				source.setPixels_B(i,j,"0");
				source.setPixels_R(i,j,"0");
			}
		}
	}
	if(color_choice == 3)
	{
		for (int i = 0; i < source.getHeight(); i++)
		{
			for (int j = 0; j < source.getWidth(); j++)
			{
				source.setPixels_R(i,j,"0");
				source.setPixels_G(i,j,"0");
			}
		}
	}
	return source;
}
int main(int argc, char const *argv[])
{
	ppmImage ppm;
	int choiceNumber;
	string ppm_file_name;
	if(argc != 3 )
	{
		return 0;
	}

	choiceNumber = stoi(argv[1],nullptr);
	ppm_file_name = argv[2];

	switch(choiceNumber)
	{
		case 1:
			if(read_ppm(ppm_file_name,ppm) == 1){
				write_ppm("o1.ppm",ppm);
			}
			else cerr << "Error" << endl;

		break;
		case 2: 
			if(read_ppm(ppm_file_name,ppm) == 1){
				if(swap_channels(ppm,2) == 1){
					write_ppm("o2.ppm",ppm);
				}
				
			}
			else cerr << "Error" << endl;
		break;
		case 3:
			if(read_ppm(ppm_file_name,ppm) == 1){
				if(swap_channels(ppm,3) == 1){
					write_ppm("o3.ppm",ppm);
				}
			}
			else cerr << "Error" << endl;
		 break;
		case 4: 
			if(read_ppm(ppm_file_name,ppm) == 1){
				if(swap_channels(ppm,4) == 1){
					write_ppm("o4.ppm",ppm);
				}
			}
			else cerr << "Error" << endl;
		break;
		case 5: 
			if(read_ppm(ppm_file_name,ppm) == 1){
				single_color(ppm,1);
				write_ppm("o5.ppm",single_color(ppm,1));
			}
			else cerr << "Error" << endl;
		break;
		case 6: 
			if(read_ppm(ppm_file_name,ppm) == 1){
				single_color(ppm,2);
				write_ppm("o6.ppm",single_color(ppm,2));
			}
			else cerr << "Error" << endl;
		break;
		case 7:
			if(read_ppm(ppm_file_name,ppm) == 1){
				single_color(ppm,3);
				write_ppm("o7.ppm",single_color(ppm,3));
			}
			else cerr << "Error" << endl;
		break;
		default: 
			cerr << "Invalid Value." << endl;
		break;
	}
}
