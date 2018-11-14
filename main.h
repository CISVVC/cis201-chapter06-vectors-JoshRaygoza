#ifndef MAIN_H
#define MAIN_H

#include<string>

class Transaction {
public:
	Transaction();
	Transaction(std::string v_discription, double v_amount, int v_day);
	void read () const;
	void print ();
	int get_day() const;
	double get_amount() const;
private:
	int i_day;
	double i_amount; 
	std::string i_discription;
};

class Statement{
public:
	Statement();
	void print();
	void read();
	void compute_balance();
	double avg_day_balance();
	double min_day_balance();
private:
	std::vector <Transaction> transactions;
	std::vector <double> day_balance;
};
#endif
