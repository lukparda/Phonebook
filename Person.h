#ifndef _PERSON_H_
#define _PERSON_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

struct Per_details
{
	friend std::ostream& operator<<(std::ostream& out, const Per_details& profiles);

	std::string F_name;
	std::string L_name;
	std::string e_mail;
	std::string address;
	std::string company;
	std::string groups;
	std::string Pr_number{};
	std::string Scd_number{};

	Per_details() = default;
	Per_details(std::string name, std::string sur, std::string email, std::string add, std::string comp, std::string grp, std::string phone, std::string mobile);

	Per_details& operator=(const Per_details& r) {
		if (this == &r) { return *this; };
		F_name = r.F_name;
		L_name = r.L_name;
		e_mail = r.e_mail;
		address = r.address;
		company = r.company;
		groups = r.groups;
		Pr_number = r.Pr_number;
		Scd_number = r.Scd_number;
		return *this;
	}

	std::string getFName() const;
	std::string getLName() const;
	std::string getCompany() const;
	std::string getGroup() const;
	std::string getPrNum() const;
};

class Phonebook
{
private:
	std::vector<Per_details> members;

public:
	//Phonebook() = default;
	//Phonebook(const Phonebook& copy) = default;
	//~Phonebook() = default;

	//test methods
	void create_new_user();
	void print_all_sorted();
	void printName_Num();
	void search_by_names();
	void search_per_company();
	void search_per_group();
	void count_ppl();
};

#endif