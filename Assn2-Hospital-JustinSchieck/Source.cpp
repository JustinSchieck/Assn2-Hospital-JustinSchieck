#include <iostream>
using namespace std;
int get_rate_drop_factor(int,int);
int menuChoice, calc;
int get_problem();
int fig_ml_hr(int);
double by_weight(float, int, int);
int by_units(int, int);
//Justin Schieck
//200328630


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

int get_rate_drop_factor(int rate, int dropRate) {

	int dropsMin;
	dropsMin = (rate*dropRate) / 60;
	return dropsMin;

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
	menuChoice = get_problem();
	switch (menuChoice) {
	case(1): {

		int rate, dropRate;

		cout << "Enter rate in ml / hr " << endl;
		cin >> rate;
		cout << "Enter tubings drop factor in drops / ml:  " << endl;
		cin >> dropRate;
		calc = get_rate_drop_factor(rate,dropRate);
		cout << "The drop rate per minute is: " << calc << endl;
		system("pause");
		return(0);
	}
	case(2): {
		
		int hours, lPerHour;

		cout << "Enter number of hours: " << endl;
		cin >> hours;
		lPerHour = fig_ml_hr(hours);
		cout << "The rate in millilitres per hour is: " << lPerHour << endl;
		system("pause");
		return(0);

	}
	case(3): {

		int weightKg, conMg;
		float rateMeasure;
		double totalMl;
		cout << "Enter rate in mg / kg / hr: " << endl;
		cin >> rateMeasure;
		cout << "Enter patient weight in kg : " << endl;
		cin >> weightKg;
		cout << "Enter concentration in mg / ml : " << endl;
		cin >> conMg;
		totalMl = by_weight(rateMeasure, weightKg, conMg);

		cout << "The rate in millilitres per hour is: " << totalMl << endl;
		system("pause");
		return(0);

	}
	case(4): {
		int unitHour, conUnit, totalUnit;
		cout << "Enter rate in units / hr: " << endl;
		cin >> unitHour;
		cout << "Enter concentration in units / ml : " << endl;
		cin >> conUnit;
		totalUnit = by_units(unitHour, conUnit);

		cout << "The rate in millilitres per hour is: " << totalUnit << endl;
		system("pause");
		return(0);

	}
	case(5): {
		cout << "Thank you for running this Program..." << endl;
		system("pause");
		return(0);
		}
	}

}
	

