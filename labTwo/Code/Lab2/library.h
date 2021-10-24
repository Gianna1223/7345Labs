#include "book.h"
using namespace std;

#ifndef LIBRARY_H_
#define LIBRARY_H_
class Library
{
public:
	Library();
	int get_m();//get m
	bool search();//search book
    void set_book1(int id, double price, int number);//create a new book
	bool borrow_book(int id, int num);//borrow a book
	void show();//show library information
	double sale_sum();//calculate total sales
	double sale_average();//calculate average sales
	void sale_show(double sum, double average);//show sales information

private:
	int m;//total book number
	int sale_num=0;//total sale number
	Book book1[1000];
	Book book_borrow[1000];
};
#endif 