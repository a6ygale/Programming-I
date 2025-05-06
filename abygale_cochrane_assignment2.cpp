//loading libraries and including tuple to call later
#include <iostream> 
#include <tuple>
using namespace std;


// initializing variables

int money; 
//how much money the user inputs that they would like to spend
int number_of_notebooks; 
//how many notebooks they can buy with the money provided
int number_of_stickers; 
//how many stickers they will have leftover after any exchanges were 
// done for additional notebooks if applicable
int additional_notebooks;
//used to indicate any additional notebooks that could be received due to sticker exchange
int calculate_notebook(int);
//initializing function that will return the maximum number of notebooks user 
//can buy and their leftover sticker amount


//defining function that returns the number of notebooks and stickers
//as a tuple when given input variable of how much
//money to spend
std::tuple<int, int>  calculate_notebooks(int money)
{
	//the number of notebooks is equal to how many groups of $2 are in the 
	//amount of money provided, and the user will receive as many stickers as
	//they do notebooks
	int number_of_notebooks = money/2;
	int number_of_stickers = money/2;

	//including case when there are enough stickers to exchange for another 
	//notebook
	if (number_of_stickers > 11)
	{
		//finding how many stickers can be exchanged for additional notebooks
		additional_notebooks = number_of_stickers / 12;
		//adding the new notebooks to the total number of notebooks received
		number_of_notebooks = number_of_notebooks + additional_notebooks;
		//recalculating the number of stickers to exclude the ones exchanged for new notebooks
		number_of_stickers = number_of_stickers - (additional_notebooks * 12)+(additional_notebooks);
		//combining variables into tuple so that function can return multiple values
		return std::make_tuple(number_of_notebooks, number_of_stickers);
	}
	//if there arent enough stickers to exchange, then the number of notebooks
	//is just equal to the money divided by two to the last integer
	else
		return std::make_tuple(number_of_notebooks, number_of_stickers);
	
}


int main()
{
	//this is the main code that actually asks for user input and calls the function
	//initialing run variable so that the code can rerun as long as the user
	//says that they would like it to
	string run = "y";

	while (run == "y")
	{
		//sends prompt to terminal asking how much money the user would like to send and 
		//storing it as money variable
		cout << "How many dollars would you like to spend at the store?";
		cin >> money;


		//recalling output of function based on user money input
		std::tuple<int, int> result = calculate_notebooks(money);
		//initializing return variables in main code
		int n_of_notebooks, n_of_stickers;
		std::tie(n_of_notebooks, n_of_stickers) = result;

		//returning string to user telling them how many notebooks they can buy 
		//and how many stickers theyll have
		cout<<"You can buy "<<n_of_notebooks<<" notebooks. \n"
			<<"You will have "<<n_of_stickers<<" stickers remaining.\n"
		//asking if they would like to keep the while loop running, if they change 
		//the run value to n then the code will end
			<< "Would you like to use this program again? (y/n)";
		cin >> run;
	}

	return 0; 
}