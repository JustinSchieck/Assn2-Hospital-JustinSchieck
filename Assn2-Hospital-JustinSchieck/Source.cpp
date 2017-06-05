#include <iostream>
using namespace std;


//Justin Schieck
//200328630
//Might put some serious validation in if bored.


//variables
int menuChoice, calc;

//functions initialization
int get_problem();
int get_rate_drop_factor();
int get_kg_rate_conc();
int get_unit_conc();
int fig_drops_min(int, int);
int fig_ml_hr(int);
double by_weight(float, int, int);
int by_units(int, int);


//functions code
int get_problem() {
	int choice;

	cout << "Please chose one of the following for calculation" << endl;
	cout << "1 for ml / hr & tubing drop factor" << endl;                    //drops / min
	cout << "2 for 1 L for (number) hr" << endl;                             //ml / hr
	cout << "3 for mg / kg / hr & concentration in mg / ml" << endl;         //ml / hr
	cout << "4 for units / hr & concentration in units / ml" << endl;        //ml / hr
	cout << "5 to exit Program" << endl;
	cin >> choice;

	return choice;
}

int get_rate_drop_factor() {

	int rate, dropRate, dropPerMin;

	cout << "Enter rate in ml / hr " << endl;
	cin >> rate;
	cout << "Enter tubings drop factor in drops / ml:  " << endl;
	cin >> dropRate;
	dropPerMin = fig_drops_min(rate, dropRate);
	
	return dropPerMin;

}


int get_kg_rate_conc() {
	//Prompts the user to enter the data required for problem 3, 
	//and sends this data back to the calling module via output parameters
	float rateMg;
	int concentrationMg, weight;
	double totalMl;

	cout << "Enter rate in mg / kg / hr: " << endl;
	cin >> rateMg;
	cout << "Enter patient weight in kg : " << endl;
	cin >> weight;
	cout << "Enter concentration in mg / ml : " << endl;
	cin >> concentrationMg;
	

	totalMl = by_weight(rateMg, weight, concentrationMg);
	return totalMl;
}

int get_unit_conc() {
	//Prompts the user to enter the data required for problem 4, 
	//and sends this data back to calling module via output parameters
	int unitHour, conUnit, returnUnit;
	cout << "Enter rate in units / hr: " << endl;
	cin >> unitHour;
	cout << "Enter concentration in units / ml : " << endl;
	cin >> conUnit;

	returnUnit = by_units(unitHour, conUnit);
	return returnUnit;
}

int fig_drops_min(int rateMgKg,int dropFactor ) {
	// Takes rate and drop factor as input parameters and returns drops/min 
	//(rounded to nearest whole drop) as a function value
	int returnAmount;
	
	returnAmount = (rateMgKg * dropFactor) / 60;

	return returnAmount;


}

int fig_ml_hr(int hours) {

	int perHour;
	perHour = 1000 / hours;
	return perHour;

}
double by_weight(float rateMeasure, int weightKg, int conMg) {
	double mlPerHour;

	mlPerHour = (rateMeasure * weightKg) / conMg;

	return mlPerHour;
}
int by_units(int unitHour, int conUnit) {
	int mlByUnit;

	mlByUnit = unitHour / conUnit;

	return mlByUnit;
}

int main()
{
	//runs program until 5 is pressed.
	do {
		
		menuChoice = get_problem();
		
		switch (menuChoice) {
		case(1): {

			int calc;

			calc = get_rate_drop_factor();

			cout << "The drop rate per minute is: " << calc << endl;
			break;
		}
		case(2): {

			int hours, lPerHour;

			cout << "Enter number of hours: " << endl;
			cin >> hours;
			lPerHour = fig_ml_hr(hours);
			cout << "The rate in millilitres per hour is: " << lPerHour << endl << endl;
			break;

		}
		case(3): {

			double rateMeasure;

			rateMeasure = get_kg_rate_conc();

			cout << "The rate in millilitres per hour is: " << rateMeasure << endl << endl;

			break;
		}
		case(4): {
			int totalUnit;
			totalUnit = get_unit_conc();

			cout << "The rate in millilitres per hour is: " << totalUnit << endl << endl;

			break;
		}

		case(5): {
			cout << "Thank you for running this Program..." << endl << endl;

			}
		}
	} while (menuChoice != 5);
	system("pause");
	return(0);
}
	

