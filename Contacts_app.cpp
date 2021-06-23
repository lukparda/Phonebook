#include <iostream>
#include <vector>
#include "Person.h"

int main()
{
	Phonebook book;

	short option1{};
	short option2{};
	do 
	{
		std::cout << "Select an option: \n"
			<< "1. Print contacts sorted.\n"
			<< "2. Display first name and primary number only.\n"
			<< "3. Display contacts from the same company.\n"
			<< "4. Display contacts from the same group.\n"
			<< "5. Search for a contact.\n"
			<< "6. Count contacts by company and group.\n"
			<< "7. Save new contact.\n"
			<< "8. Exit.\n"
			<< ">";
		std::cin >> option1;
		switch (option1)
		{
		case 1:
			book.print_all_sorted(); break;
		case 2:
			book.printName_Num(); break;
		case 3:
			book.search_per_company(); break;
		case 4:
			book.search_per_group(); break;
		case 5:
			book.search_by_names(); break;
		case 6:
			book.count_ppl(); break;
		case 7:
			book.create_new_user(); break;
		case 8:
			std::cout << "Goodbye.\n";
			exit(0);
		default:
			std::cout << "Incorrect selection. Try again.\n"; break;
		}
	} while (option1 != 8);
	
}