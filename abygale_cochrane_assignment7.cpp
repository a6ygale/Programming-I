//Abygale Cochrane
//April 28th, 2024

//this code is can be used to perform addition, subtraction, 
//multiplication, and division on complex numbers

//initialize
#include <iostream>
#include <sstream>
using namespace std;

//variables used
string first_input; //stores first user input as string
string second_input; //stores second user input as string
string R1; //separates real part of first input
string I1; //separates imaginary part of first input
string R2; //separates real part of second input
string I2; //separates imaginary part of second input
string p; //used to store plus sign thats split during the cin process
double I_opp; //used to store imaginary part after operation
double R_opp; //used to store real part after operation
double I_complex; //used to store the complex-conjugated imaginary component 
double I_num; //used to store imaginary part in numerator of division
double R_num; //used to store real part in numerator of division
double R_den; //used to store real part in denominator of division (shouldn't be a remaining I)
double Imaginary; //the imaginary part specified inside class
double Real; //the imaginary part specified inside class
double Modulus; 
char run; //used to rerun program if user specifies


//class used to initialize real and imaginary parts of both
//inputs as well as functions to perform operations
class Complex_Numbers {

	public:
		//CONSTRUCTORS//------------------------------------------------------------------------
		Complex_Numbers(string Re) {//constructor in the case that there's only a real input

			Real = stod(Re); //converts from string to double
			Imaginary = 0; 
			Modulus = Real; 
		}

		Complex_Numbers(string Re, string Im) {//constructor if there's a real and imaginary
			Real = stod(Re);//converts from string to double
			Im.pop_back(); //takes out i at end so it's just the number
			Imaginary = stod(Im);//converts from string to double
			Modulus = sqrt(Real ^ 2 + Imaginary ^ 2); //distance formula
		};
		Complex_Numbers() {//constructor for a 0 real 0i default value
			Real = 0;
			Imaginary = 0;
			Modulus = 0; 
		}

		//MEMBER FUNCTIONS-----------------------------------------------------------------------
		
		//performs addition operation between class parts and the real/imaginary of the input
		void addition(double Re2, double Im2, string first, string second) {

			R_opp= Real + Re2; //adds real parts together
			I_opp = Imaginary + Im2; //adds imaginary parts together

			if (R_opp == 0) {//this just removes negation if the values zero
				R_opp = 0;
			}

			if (I_opp < 0) {//reformates sign of imaginary part to match original input
				cout << first_input << " + " << second_input << " = " << R_opp << " - " << abs(I_opp) << "i \n";
			}
			else {
				cout << first_input << " + " << second_input << " = " << R_opp << " + " << abs(I_opp) << "i \n";
			}
		}

		//performs subtraction operation between class parts and the real/imaginary of the input
		void subtraction(double Re2, double Im2, string first, string second) {
			R_opp = Real - Re2; //subtracts real parts
			I_opp = Imaginary - Im2; //subtracts imaginary parts

			if (R_opp == 0) {//this just removes negation if the values zero
				R_opp = 0;
			}

			if (I_opp < 0) {//reformates sign of imaginary part to match original input
				cout << first_input << " - " << second_input << " = " << R_opp << " - " << abs(I_opp) << "i \n";
			}
			else {
				cout << first_input << " - " << second_input << " = " << R_opp << " + " << abs(I_opp) << "i \n";
			}
		}

		//performs multiplication operation between class parts and the real/imaginary of the input
		void multiplication(double Re2, double Im2, string first, string second) {

			I_opp = (Real *Im2) + (Re2 * Imaginary) ; //takes two i terms and adds together
			R_opp = (Real * Re2) - (Imaginary * Im2); //turns i^2 to -1, subtracting from real

			if (R_opp == 0) {//this just removes negation if the values zero
				R_opp = 0;
			}

			if (I_opp < 0) {//reformates sign of imaginary part to match original input
				cout << first_input << " * " << second_input << " = " << R_opp << " - " << abs(I_opp)<<"i \n";
			}
			else {
				cout << first_input << " * " << second_input << " = " << R_opp << " + " << abs(I_opp)<<"i \n";
			}
		}

		//performs division operation between class parts and the real/imaginary of the input
		void division(double Re2, double Im2, string first, string second) {
			I_complex = -Im2; //need to multiply by complex conjugate aka negation of imaginary
			I_num = (Real * I_complex) + (Re2 * Imaginary); //takes two i terms and adds together
			R_num = (Real * Re2) - (Imaginary * I_complex); //turns i^2 to -1, subtracting from real

			R_den = (Re2 * Re2) - (I_complex * Im2); //turns i^2 to -1, subtracting from real
			//please note there is no imaginary denominator because we multiplied
			//by the complex conjugate

			R_opp = R_num / R_den; //divides real part
			R_opp = round(R_opp * 1000.0) / 1000.0; 

			I_opp = I_num / R_den;//divides imaginary part
			I_opp = round(I_opp * 1000.0) / 1000.0;

			if (R_opp == 0) {//this just removes negation if the values zero
				R_opp = 0; 
			}


			if (I_opp < 0) {//reformates sign of imaginary part to match original input
				cout << first_input << " / " << second_input << " = " << R_opp << " - " << abs(I_opp)<<"i \n";
			}
			else {
				cout << first_input << " / " << second_input << " = " << R_opp << " + " << abs(I_opp)<<"i \n";
			}
		}

		//performs comparative operation between class parts and the real/imaginary of the input
		void same(double Re2, double Im2, string first, string second) {
			if (Real == Re2 && Imaginary == Im2) {
				cout << first_input << " == " << second_input << " = " <<"True \n";
			}
			else {
				cout << first_input << " == " << second_input << " = " << "False \n";
			}
		}

		//used to retrieve Modulus variable of class in main code
		double getModulus() {
			return Modulus; 
		}

		//used to retrieve real variable of class in main code
		double getReal() {
			return Real; 
		}
		//used to retrieve imaginary variable of class in main code
		double getImaginary() {
			return Imaginary; 
		}

	private: 
		double Real;//real part of the object
		double Imaginary; //imaginary part of the object
		double Modulus; //distance from origin
};

int main()
{

	run = 'Y'; //initializing loop to run

	while (run == 'Y' || run == 'y') {//as long as user types y, the code will rerun

		//asks for first complex number
		cout << "\nEnter a complex number in the format a + bi: \n";
		cin >> R1 >> p >>I1; //separates by space delimination into real, sign, and imaginary
		first_input = R1 + " " + p + " " + I1; //stores as string for later outputs
		cout << "You entered: "<<first_input<<"\n"; //returns what the user's input was
		if (p == "-") {//if there was a negative, attaches it to imaginary digit
			I1 = "-"+I1;
		}
		Complex_Numbers first(R1, I1); //creates object for first input
		
		//asks for second complex number
		cout << "\nEnter another complex number in the format a + bi: \n";
		cin >> R2 >> p >>I2;//separates by space delimination into real, sign, and imaginary
		second_input = R2 + " " + p + " " + I2; //stores as string for later outputs
		cout << "You entered: " << second_input <<"\n\n"; //returns what the user's input was
		if (p == "-") {//if there was a negative, attaches it to imaginary digit
			I2 = "-" + I2;
		}
		Complex_Numbers second(R2, I2); //creates object for second input

		//this is where all of the results of operations get returned to the terminal
		//i used class functions of the first input for operation, which already stored those
		//real and imaginary parts
		//i used getReal/Imaginary functions in the second object to retrieve those parts
		//i then used them as parameters into the first
		cout << "Results: \n"; 
		first.addition(second.getReal(), second.getImaginary(), first_input, second_input);
		cout << "\n"; 
		first.subtraction(second.getReal(), second.getImaginary(), first_input, second_input);
		cout << "\n";
		first.multiplication(second.getReal(), second.getImaginary(), first_input, second_input);
		cout << "\n";
		first.division(second.getReal(), second.getImaginary(),first_input, second_input);
		cout << "\n";
		first.same(second.getReal(), second.getImaginary(), first_input, second_input); 
		cout << "\n";
		

		//uses the user input as a condition for the while loop
		//they are able to break it or reloop based on what they enter
		cout << "Would you like to run the program again? (Y/N)\n"; 
		cin >> run; 
	}

	cout << "Bye!";
	return 0; 
}