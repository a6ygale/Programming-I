//Abygale Cochrane
//April 14th, 2024
//this code can be used to perform a variety of operations on
//multiple rectangles, utilizing coordinates, width, and height properties of class

#include <iostream>
#include <array>
using namespace std; 

int recNumber; //variable that specifies which rectangle in array to operate on
string action; //variable thta indicates what method to call

class rectangle{ //this is the actual class with variables and methods specific to the individual rectangle
	private:  
		int X; //x coordinate of corner
		int Y; //y coordinate of corner
		int newX; //used as placeholder when swapping variables
		int newY; //used as placeholder when swapping variables
		int width; //widyh of rectangle
		int height; //height of rectangle
		int newWidth; //used as placeholder when swapping dimensions
		int newHeight; //used as placeholder when swapping dimensions
		int Xshift; //amount of units to move over x coordinate
		int Yshift; //amount of units to move over y coordinate


	public: //these are the methods that you can access from the main code
		void set() {// sets the x and y coordinate values
			cout << "Enter the corner x and y coordinates, width and height separated by spaces: ";
			cin >> X >> Y >> width >> height;
		}

		void move() {//shifts the x and y coordinates by specified unit amount
			cout << "Enter the amount you would like to move in the x and y directions separated by a space: "; 
			cin >> Xshift >> Yshift; 
			X = X + Xshift; 
			Y = Y + Yshift; 
		}
		void resize() {//changes height and width of rectangle
			cout << "Enter the new width and height separated by a space: ";
			cin >> width >> height; 
		}
		void rotate() { //uses standard formula to adjust coordinates, length, and width to what it would be if rotated 90 degrees clockwise
			newX = Y; //used placeholder variables so once one is rewritten, the other still has necessary info
			newY = -X; 
			X = newX; 
			Y = newY; 

			newWidth = height; 
			newHeight = width; 
			width = newWidth; 
			height = newHeight; 
		}
		void retrieveCorner() {//returns x and y coordinates
			cout << "(" << X << ", " << Y << ")\n"; 
		}
		void retrieveDimensions() { // returns height and width
			cout<< "Width: " << width << "\nHeight: " << height<<"\n";
		}
	};



int main() {
	recNumber = 0; //default rectangle number
	rectangle r[3]; //initializing array that can store 3 rectangles 
	action = "n"; //default of action variable

	while (action != "q"|| action != "Q") { //as long as the user hasn't quitted, keep offering menu
		cout << "Choose from the following options :\ns : set a Rectangle's properties\nm : move a Rectangle\nz : resize a Rectangle\nr : rotate a Rectangle\nq : quit\n";
		cin >> action; //this variable is the condition for different function executions

		if (action == "s"|| action == "S") { //takes upper or lowercase s to indicate setting rectangle
			while (recNumber != 1 && recNumber != 2 && recNumber != 3) {
				cout << "Which rectangle would you like to set? (1-3): ";
				cin >> recNumber;
			}
			r[recNumber - 1].set(); //executes method for specific rectange that sets it's specific coordinates and dimensions
		}
		else if (action == "m"|| action == "M") {//takes upper or lower m to indicate moving
			while (recNumber != 1 && recNumber != 2 && recNumber != 3) {
				cout << "Which rectangle would you like to set? (1-3): ";
				cin >> recNumber;
			}
			cout << "Rectangle " << recNumber << "'s current corner coordinates are: ";
			r[recNumber - 1].retrieveCorner();
			r[recNumber - 1].move();//executes method for specific rectange that shifts it's specific coordinates
		}
		else if (action == "z" || action =="Z") {//takes upper or lowercase z to indicate resizing
			while (recNumber != 1 && recNumber != 2 && recNumber != 3) {
				cout << "Which rectangle would you like to set? (1-3): ";
				cin >> recNumber;
			}
			cout << "Rectangle " << recNumber << "'s current dimensions are: "; 
			r[recNumber - 1].retrieveDimensions();
			r[recNumber - 1].resize();//scales the dimensions of rectangle by factor provided
		}
		else if (action == "r"|| action == "R") {//takes upper or lowercase r to indicate rotating 90 deg clockwise
			while (recNumber != 1 && recNumber != 2 && recNumber != 3) {
				cout << "Which rectangle would you like to set? (1-3): ";
				cin >> recNumber;
			}
			r[recNumber - 1].rotate(); //swaps x and Y coordinates as well as length and width, negates y
		}
		else if (action == "q"|| action =="Q") {//takes upper or lower q to indicate stopping of program
			cout << "Exiting program.Goodbye!";
			break; 
		}
		else { //if the user input isn't a specified case, then it will prompt the user to choose another letter next time
			cout << "This is not a valid input, please try again. \n"; 
		}

		//if rectangle was operated on, returns new properties
		if (recNumber == 1 || recNumber == 2 || recNumber == 3) {
			cout << "Rectangle " << recNumber << "'s properties are now: \nCorner: ";
			r[recNumber - 1].retrieveCorner();
			r[recNumber - 1].retrieveDimensions();
		}

	}
	

	return 0;
}

