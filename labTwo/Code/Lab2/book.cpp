#include "book.h"

Book::Book()
{
	id = 0;
	number = 0;
	price = 0;
}

Book::Book(int id, double price, int number)
{
	this->number = number;
	this->id = id;
	this->price = price;
}

//get

int Book::get_number()
{
	return number;
}

int Book::get_id()
{
	return id;
}


double Book::get_price()
{
	return price;
}

//set

void Book::set_number(int number)
{
	this->number = number;
}

void Book::set_id(int id)
{
	this->id = id;
}

void Book::set_price(double price)
{
	this->price = price;
}


