#include <iostream>
using namespace std;
#ifndef BOOK_H_
#define BOOK_H_
class Book
{
public:
	Book();
	Book(int id, double price, int number);
	//get
	int get_id();//get book id
	int get_number();//get book stock
	double get_price();//get book price
	//set
	void set_number(int n_number);//set book stock
	void set_id(int id);//set book id
	void set_price(double price);//set book price
	void show(int id);//show book information
private:
	int number;//book stock
	int  id;//book id
	double price;//book price

};
#endif 