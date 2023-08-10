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
	friend  ppmImage operator+(ppmImage& obj1,ppmImage& obj2); //Adds two ppmImage objects them pixel-by-pixel.
	friend  ppmImage operator-(ppmImage& obj1,ppmImage& obj2); //Subtraction two ppmImage objects them pixel-by-pixel.
	string operator()(int , int, int);
		
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
	return in;
}
/*
	Since the dimensions of the two ppm image objects are equal, operator+ overloading creates a new objects,
	writes the state of the sums to this new object and returns the new object.

*/
ppmImage operator+(ppmImage& obj1,ppmImage& obj2)
{
	ppmImage newObj(obj1.getHeight(),obj1.getWidth());
	int temp_R, temp_G, temp_B;
		for (int i = 0; i < obj1.getHeight(); i++)
		{
			for (int j = 0; j < obj1.getWidth(); j++)
			{
				temp_R = stoi(obj2.pixels[i][j].R) + stoi(obj1.pixels[i][j].R);
				temp_G = stoi(obj2.pixels[i][j].G) + stoi(obj1.pixels[i][j].G);
				temp_B = stoi(obj2.pixels[i][j].B) + stoi(obj1.pixels[i][j].B);

				if(temp_R>255)
				{
					temp_R = 255;
				}
				if(temp_G>255)
				{
					temp_G = 255;
				}
				if(temp_B>255)
				{
					temp_B = 255;
				}
				newObj.pixels[i][j].R = to_string(temp_R);
				newObj.pixels[i][j].G= to_string(temp_G);
				newObj.pixels[i][j].B = to_string(temp_B);
			}
		}
	
	return newObj;
	
}
/*
	 The same as the operator+ operation, only the extraction will be performed and the case of being less than 0
	 will be ignored.
*/
ppmImage operator-(ppmImage& obj1,ppmImage& obj2)
{
	ppmImage newObj(obj1.getHeight(),obj1.getWidth());
	int temp_R, temp_G, temp_B;
		for (int i = 0; i < obj1.getHeight(); i++)
		{
			for (int j = 0; j < obj1.getWidth(); j++)
			{
				temp_R = stoi(obj2.pixels[i][j].R) - stoi(obj1.pixels[i][j].R);
				temp_G = stoi(obj2.pixels[i][j].G) - stoi(obj1.pixels[i][j].G);
				temp_B = stoi(obj2.pixels[i][j].B) - stoi(obj1.pixels[i][j].B);

				if(temp_R<0)
				{
					temp_R = 0;
				}
				if(temp_G<0)
				{
					temp_G = 0;
				}
				if(temp_B<0)
				{
					temp_B = 0;
				}
				newObj.pixels[i][j].R = to_string(temp_R);
				newObj.pixels[i][j].G= to_string(temp_G);
				newObj.pixels[i][j].B = to_string(temp_B);
			}
		}
	
	return newObj;
	
}
/*
	The given x and y value represents the coordinates of the object, and rgb represents the color state.
	1 red 2 green 3 blue.. I had these values returned, which I kept as a string.
*/
string ppmImage::operator()(int x, int y, int rgb)
{
	string value;
	if(rgb == 1 ) 
	{
		value = this->pixels[x][y].R;
		return value;
	}
	if(rgb == 2 )
	{
		value = this->pixels[x][y].G;
		return value;
	}
	if(rgb == 3 )
	{
		value = this->pixels[x][y].B;
		return value;
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
				temp = image_object_to_be_modified(i,j,2);
				image_object_to_be_modified.setPixels_G(i,j,image_object_to_be_modified(i,j,1));
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
				temp = image_object_to_be_modified(i,j,3);
				image_object_to_be_modified.setPixels_B(i,j,image_object_to_be_modified(i,j,1));
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
				temp = image_object_to_be_modified(i,j,3);
				image_object_to_be_modified.setPixels_B(i,j,image_object_to_be_modified(i,j,2));
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
ppmImage single_color( ppmImage& source, int color_choice){
	ppmImage ppm;
	ppm.setWH(source.getHeight(),source.getWidth());
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
	
	for (int i = 0; i < source.getHeight(); i++)
	{
		for (int j = 0; j < source.getWidth(); j++)
		{
			ppm.setPixels_R(i,j,source(i,j,1));
			ppm.setPixels_G(i,j,source(i,j,2));
			ppm.setPixels_B(i,j,source(i,j,3));
		}
	}
	return ppm;
}
/*
	A function collet these data after two file extensions are given and converted to ppm objective.
*/
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3)
{
	ppmImage ppm1, ppm2, ppm3;
	
	if(read_ppm(filename_image1,ppm1) == 1)
	{
		if(read_ppm(filename_image2,ppm2) == 1)
		{	
			if(ppm1.getWidth() == ppm2.getWidth() && ppm1.getHeight() == ppm2.getHeight())
			{
				ppm3 = ppm1 + ppm2; // Addition ppm1 obj and ppm2 obj then create new ppm obj save it.
				write_ppm(filename_image3,ppm3);
			}
			else
			{
				cerr << "Error. Dimensions are different" << endl;
			}

		}
	}

}
/*
	Perform,ng the extraction of the color bits of the 2 file entered on the
	command line according to the size.
*/
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
	ppmImage ppm1, ppm2, ppm3;
	
	if(read_ppm(filename_image1,ppm1) == 1)
	{
		if(read_ppm(filename_image2,ppm2) == 1)
		{	
			ppm3 = ppm1 - ppm2;
			write_ppm(filename_image3,ppm3);
		}
	}
}
/*
	The data in th efile extension is saved in the read ppm object and the function
	where the screen printing takes place.
*/
int test_print(const string filename_image1)
{
	ppmImage ppm;
	if(read_ppm(filename_image1,ppm) == 1)
	{
		cout << ppm;
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	ppmImage ppm,temp;
	int choiceNumber;
	string ppm_file_name1, ppm_file_name2,ppm_file_name3;
	//If file1 and file2 are empty .Exit
	if(argv[3] == NULL || argv[2] == NULL) exit(1);
	choiceNumber = stoi(argv[1],nullptr);
	ppm_file_name1 = argv[2];
	ppm_file_name2 = argv[3];
	
	switch(choiceNumber)
	{
		case 1:
		//If file3 is not empty.
			if(argv[4] != NULL) 
			{
				ppm_file_name3 = argv[4];
				test_addition(ppm_file_name1,ppm_file_name2,ppm_file_name3);
			}
			else
			{
				cerr << "Error" << endl;
				exit(1);
			} 
		break;
		case 2:
		//If file3 is not empty.
			if(argv[4] != NULL)
			{
				ppm_file_name3 = argv[4];
				test_subtraction(ppm_file_name1,ppm_file_name2,ppm_file_name3);
			}
			else
			{
				cerr << "Error" << endl;
				exit(1);
			} 
		break;
		case 3:
			if(read_ppm(ppm_file_name1,ppm) == 1){
				if(swap_channels(ppm,3) == 1){
					write_ppm(ppm_file_name2,ppm);
				}
			}
			else cerr << "Error" << endl;
		 break;
		case 4: 
			if(read_ppm(ppm_file_name1,ppm) == 1){
				if(swap_channels(ppm,4) == 1){
					write_ppm(ppm_file_name2,ppm);
				}
			}
			else cerr << "Error" << endl;
		break;
		case 5: 

			if(read_ppm(ppm_file_name1,ppm) == 1){
				temp=single_color(ppm,1);
				write_ppm(ppm_file_name2,temp);
			}
			else cerr << "Error" << endl;
		break;
		case 6: 
			if(read_ppm(ppm_file_name1,ppm) == 1){
				temp=single_color(ppm,2);
				write_ppm(ppm_file_name2,temp);
			}
			else cerr << "Error" << endl;
		break;
		case 7:
			if(read_ppm(ppm_file_name1,ppm) == 1){
				temp=single_color(ppm,3);
				write_ppm(ppm_file_name2,temp);
			}
			else cerr << "Error" << endl;
		break;
		default: 
			cerr << "Invalid Value." << endl;
		break;
	}
}
