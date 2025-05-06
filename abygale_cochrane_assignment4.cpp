
//Abygale Cochrane, March 24th
//UFID: 9923 5288

// this code uses an input time and converts it to 
//whatever timezone the user requests

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


//variable names
string timeIn; //the users input time
string currentTZ;//the users input current timezone
string targetTZ; //the users input target timezone for conversion
string TZ;//used when converting string timezones to integers to calculate time difference
int diff; //the difference between timezones
int diff1;//the original timezone in integer form
int diff2;//the target timezone in integer form
int hr; //the integer equivalent of the hour the user provided
int minute; //the integer equivalent of the minute the user provided
string HR; //the string equivalent of the target hour
string MINUTE; //the string equivalent of the target minute/original
string timeOfDay; //AM or PM indicator, also says when theres a day change
string run; //used to run program in a loop until the user wants to stop
int check; //output of check for errors


//converting timezones to integers for easy comparison of time difference
int calculateTZ(string TZ)
{
	if (TZ == "HST")
	{
		diff = 1;
	}
	else if (TZ == "PST")
	{
		diff = 3;
	}
	else if (TZ == "MST")
	{
		diff = 4;
	}
	else if (TZ == "CST")
	{
		diff = 5;
	}
	else if (TZ == "EST")
	{
		diff = 6;
	}
	else if (TZ == "GMT") {
		diff = 11;
	}
	else//this is if the timezone is not in program, used to indicate error later
	{
		diff = 0;
	}
	return diff;

}

//checks that all inputs are valid
int checkErrors(int diff1, int diff2, string timeIn) {

	//if the timezone given wasn't provided by the cases
	if (diff1 == 0 || diff2 == 0)
	{
		cout << "This is not a valid timezone, please try again\n";
		check = 1; 
	}

	//if the hours or minutes weren't in typical range
	else if (stoi(timeIn.substr(0, 2))>24 || stoi(timeIn.substr(0, 2))< 0 || stoi(timeIn.substr(3, 2))>59 || stoi(timeIn.substr(3, 2))<0)
	{
		cout << "This is not a valid time, please try again\n";
		check = 1;
	}
	else {
		check = 0; 
	}
	return check; 
}

//adds the difference between timezones and checks for 
//boundaries/ time of day
void adjustTime(string timeIn, int diff) {
	
	hr = stoi(timeIn.substr(0, 2));//string to int conversion
	minute = stoi(timeIn.substr(3, 2));//string to int conversion


	//checks if theres a 12hr input
	if (timeIn.size() > 5) {
		if (timeIn.substr(6, 2) == "PM");
		{
			hr = hr + 12;
		}
	}

	//adds difference in timezones
	hr = hr + diff; 

	//if its past noon, indicate PM
	if (hr > 12 && hr<24) {
		hr = hr - 12;
		timeOfDay = "PM (Same Day)";
	}
	//if its over 24hrs, indicate next day
	else if (hr > 24) {
		hr = hr - 24; 
		timeOfDay = "AM (Next Day)";
	}
	//if its before midnight, indicate previous day
	else if (hr < 0) {
		hr = hr + 12; 
		timeOfDay = "PM (Previous Day)"; 
	}

	//if none, then its AM on the same day
	else {
		timeOfDay = "AM (Same Day)";
	}
	
	//because in string/int conversions, the extra zero gets
	//lost, you have to add it back later 
	//ie check if theres a single digit and manually insert
	HR = to_string(hr);
	MINUTE = to_string(minute);
	if (HR.size() < 2) {
		HR = "0" + HR; 
	}
	if (MINUTE.size() < 2) {
		MINUTE = "0" + MINUTE;
	}
	
	//sends out calculated time to terminal
	cout << HR << ":" << MINUTE << " " << timeOfDay << "\n";

}


//the primary function that establishes user inputs and calls conversion functions
//and the error checking function
void convertTime() {
	//asks for and assigns input value
	cout << "Please enter the current time(HH:MM, 24 - hour format) :";
	cin >> timeIn;

	//asks for and assigns current timezone
	cout << "Enter the current time zone (e.g., GMT, EST, PST):";
	cin >> currentTZ;
	diff1 = calculateTZ(currentTZ);


	//asks for and assigns target timezone
	cout << "Enter the target time zone (e.g., EST, PST, JST):";
	cin >> targetTZ;
	diff2 = calculateTZ(targetTZ);

	//finds difference in timezones for conversion
	diff = diff2 - diff1;

	check = checkErrors(diff1,diff2,timeIn); 
	if (check == 0) {
		adjustTime(timeIn, diff);
	}

	//if there were errors, the program wont be able to convert and
	//it will attempt to rerun
	else {
		
	}




}


int main() {
	run = "y";

	//until user reassigns run variable to n, it will keep looping
	while(run == "y") {

		convertTime();
		cout << "run again? (y/n)\n";
		cin >> run; 
	}
	

	return 0;
}