#include<iostream>
#include<string>
#include<vector>
#include"LibrarySystem.hpp"
#include"LibraryThread.hpp"
#include<ctime>
#include<chrono>
using namespace std;
int main(void){
    clock_t start,end;
    cout<<"Creating Library System"<<endl;
    BorrowSystem* bs=BorrowSystem::CreateOrGet();
    cout<<"Create Books"<<endl;
    Book b1=Book(3,59,7320);
    Book b2=Book(2,12,7316);
    Book b3=Book(5,30,7359);
    Book b4=Book(4,63,4315);
    Book b5=Book(7,41,7321);
    Book b6=Book(4,17,5317);
    Book b7=Book(3,45,5321);
    Book b8=Book(2,32,5345);
    vector<Book*> books;
    books.push_back(&b1);
    books.push_back(&b2);
    books.push_back(&b3);
    books.push_back(&b4);
    books.push_back(&b5);
    books.push_back(&b6);
    books.push_back(&b7);
    books.push_back(&b8);
    cout<<"Creating Borrow Threads"<<endl;
    bs->CreateBorrowThread(1,7320,books[0]);
    bs->CreateBorrowThread(2,7316,books[1]);
    bs->CreateBorrowThread(2,7359,books[2]);
    bs->CreateBorrowThread(1,4315,books[3]);
    bs->CreateBorrowThread(3,7321,books[4]);
    bs->CreateBorrowThread(2,5317,books[5]);
    bs->CreateBorrowThread(3,5321,books[6]);
    bs->CreateBorrowThread(1,5345,books[7]);
    
    start=clock();
    bs->book_BorrowThreads[0]->Work();
    bs->book_BorrowThreads[1]->Work();
    bs->book_BorrowThreads[2]->Work();
    bs->book_BorrowThreads[3]->Work();
    bs->book_BorrowThreads[4]->Work();
    bs->book_BorrowThreads[5]->Work();
    bs->book_BorrowThreads[6]->Work();
    bs->book_BorrowThreads[7]->Work();
    end=clock();
    cout<<"The execution time of reservation with multithread is "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    int running = 1;

#ifdef __EMSCRIPTEN__
    this_thread::sleep_for(chrono::microseconds(5 * 1000000));
    cout << "Finishing Tickets Reservation" << endl;
    cout<<"The execution time of reservation with multithread is "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
#else
    while (running)
    {
        std::string command;
        std::cout << "Enter stop, finish ";
        std::cin >> command;

        if (command == "stop")
        {
            running = 0;
        }
        else if (command == "finish")
        {
            cout << "Total Tickets Reserved: " << bs->book_Books.size()<< std::endl;
        }
        else
        {
            std::cout << "Unknown Command" << std::endl;
        }
    }
    #endif
}
