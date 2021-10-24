#include "library.h"
#include "book.h"

Library::Library()
{
	m = 0;
}

int Library::get_m()
{
	return m;
}

bool Library::search()
{
	int id;
	cout << "Please enter the ID of the book:" << endl;
	cin >> id;
	for (int i = 0; i < m; i++)
	{
		if (book1[i].get_id() == id)
		{
			cout << "ID:"
				 << "    "
				 << "Price:"
				 << "    "
				 << "Stock:" << endl;
			cout << book1[i].get_id() << "        " << book1[i].get_price() << "          " << book1[i].get_number() << endl;
			return true;
		}
	}
	cout << "The book you are looking for does not exist!" << endl;
	return false;
}

void Library::set_book1(int id, double price, int number)
{
	Book b(id, price, number);
	this->book1[m] = b;
	m++;
	//cout << "Congratulations on completing the storage of the book!" << endl;
}

bool Library::borrow_book(int id, int num) //借书
{
	for (int i = 0; i < m; i++)
	{
		if (book1[i].get_id() == id) //如果查找的书本存在
		{
			if (book1[i].get_number() == 0)
			{
				cout << "The book you are looking for has been borrowed!" << endl;
				return false;
			}
			else
			{
				book1[i].set_number(book1[i].get_number() - num);
				int sale = sale_num;
				sale_num += num;
				int id = book1[i].get_id();
				double price = book1[i].get_price();
				int number = book1[i].get_number();

				for (int i = 0; i < sale_num; i++)
				{
					Book c(id, price, number);
					this->book_borrow[sale + i] = c;
					//cout << "book_borrow[sale_num]:  " << book_borrow[i].get_id() << endl;
				}

				return true;
			}
		}
	}
	cout << "The book you are looking for does not exist/ Finished borrowing！" << endl;
	return false;
}

void Library::show()
{

	cout << "ID:"
		 << "    "
		 << "Price:"
		 << "    "
		 << "Stock:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << book1[i].get_id() << "        " << book1[i].get_price() << "          " << book1[i].get_number() << endl;
	}
	return;
}

double Library::sale_sum()
{
	double sum = 0.0;
	double average;
	for (int i = 0; i < sale_num; i++)
	{
		sum += book_borrow[i].get_price();
	}
	average = sum / sale_num;
	return sum;
}
double Library::sale_average()
{
	double sum = 0.0;
	double average;
	for (int i = 0; i < sale_num; i++)
	{
		sum += book_borrow[i].get_price();
	}
	average = sum / sale_num;
	
	return average;
}
void Library::sale_show(double sum, double average)
{
	cout << "Sales:"
		 << "    "
		 << "sum:"
		 << "    "
		 << "average:" << endl;
	cout << sale_num << "        " << sum  << "     " << average << endl;
	return ;
}

