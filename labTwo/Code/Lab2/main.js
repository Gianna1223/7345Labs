import'./output.js'
var t0=performance.now();
var book=new Module.Book();
var lib=new Module.Library();

lib.set_book1(7316,5,10);
lib.set_book1(7450,1,10);
lib.set_book1(7320,15,10);
lib.set_book1(7319,10,10);
lib.set_book1(7345,5,10);

lib.borrow_book(7316,1);
lib.borrow_book(7450,2);
lib.borrow_book(7320,4);
lib.borrow_book(7319,3);
lib.borrow_book(7345,1);

lib.sale_sum();
var t1=performance.now();
var t=t1-t0;
document.body.innerHTML +="Total sales:" + lib.sale_sum()+ "<br> ";
document.body.innerHTML +="Average sales:" + lib.sale_average()+ "<br> ";
document.body.innerHTML+="The execution time of showing information is:"+t.toFixed(3)+"ms"+"<br\>";


