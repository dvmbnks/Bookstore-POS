program: main.cpp Book.cpp Book.h Customer.cpp Customer.h Digital_Book.cpp Digital_Book.h Inventory.cpp Inventory.h Order.cpp Order.h Physical_Book.cpp Physical_Book.h Used_Book.cpp Used_Book.h
	g++ -Werror -std=c++11 main.cpp Book.cpp Customer.cpp Digital_Book.cpp Inventory.cpp Order.cpp Physical_Book.cpp Used_Book.cpp -o program

unitProgram: UnitTesting.cpp Book.cpp Book.h Customer.cpp Customer.h Digital_Book.cpp Digital_Book.h Inventory.cpp Inventory.h Order.cpp Order.h Physical_Book.cpp Physical_Book.h Used_Book.cpp Used_Book.h
	g++ -Werror -std=c++11 UnitTesting.cpp Book.cpp Customer.cpp Digital_Book.cpp Inventory.cpp Order.cpp Physical_Book.cpp Used_Book.cpp -o unitProgram

clean:
	rm -f program unitProgram
