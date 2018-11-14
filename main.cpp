/*
Developer: Joshua Raygoza
Email: joshuar9781@student.vvc.edu
Filename: main.cpp
Description: This program is to store input data from the user and print out a bank statement with
	     form of (day, amount and discription) with the min and max daily balance with interest rate of 5%.
*/
#include <iostream>
#include <string>
#include <vector>
#include "main.h"

int Max_Day = 30;

Transaction::Transaction(std::string v_discription, double v_amount, int v_day){
	i_day = v_day;
	i_amount = v_amount;
	i_discription = v_discription;
}

double Transaction::get_amount() const{
	return i_amount;
}

int Transaction::get_day() const{
	return i_day;
}
void read(){
	
	std::cin >> v_day;
	std::cin >> v_amount;
	std::cin.ignore();
	std::getline(std::cin,v_discription);	
}
void Transaction::print(){
	std::cout <<"Day: "<< i_day<<"Amount: "<< i_amount<<"Description: "<< i_discription<< std::endl;
}
Statement::Statement(){
}
void Statement::read(){
	std::cout <<"Enter Transaction in Day, Amount, Description form: " << std::endl;
	bool more = true;
	while (more){
		Transaction new_trans;
		new_trans.read();
		if (std::cin.fail())
		   more = false;
		else
		  transactions.push_back(new_trans);
	}
	compute_balance();
}
void Statement::compute_balance(){
	int i = 0;
	int day;
	double balance = 0;

	for (day = 1; day <= Max_Day; day++){
		while (i < transactions.size() && transactions[i].get_day() == day){
			balance = balance + transactions[i].get_amount();
			i++;
		}
	day_balance.push_back(balance);
	}
}
double Statement::avg_day_balance(){
	int day;
	double sum_balance = 0;
	
	for (day = 0; day < day_balance.size(); day++)
	sum_balance = sum_balance + day_balance[day];
		return sum_balance / Max_Day;
}
double Statement::min_day_balance(){
	int day;
	double min_balance = day_balance[0];
	for (day = 1; day < day_balance.size(); day++)
		if (day_balance[day] < min_balance)
			min_balance = day_balance[day];
	return min_balance;
}
void Statement::print(){
	int day;
	int i = 0;
	
	for (day = 1; day <= Max_Day; day++){
		std::cout<<"Day: "<< day <<" Balance: " << day_balance[i - 1] <<std::endl;
		while (i < transactions.size() && transactions[i].get_day() == day){
			transactions[i].print();
			i++;
		}
	}
	const double Interest = 0.05;
	std::cout <<" Minimum Daily Balance interest: " << min_day_balance() * Interest << std::endl;
	std::cout <<" Averge Daily Balance Interest: "<< avg_day_balance() * Interest << std::endl;
}

int main()
{
	std::vector<Transaction> transactions;
	bool more = true;
	while(more){
	Transaction transactions;
	transactions.read();
	transactions.push_back(transactions);
	std::cout << "Enter another (Y/N)";
	char response;
	std::cin >> response;
	if(response != 'y' && response != 'Y')
		more = false;
	}
	print(Transaction)	
	return 0;
}
