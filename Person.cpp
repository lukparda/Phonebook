#include "Person.h"

Per_details::Per_details(std::string name, std::string sur, std::string email, std::string add, std::string comp, std::string grp, std::string phone, std::string mobile) : F_name{ name }, L_name{ sur }, e_mail{ email }, address{ add }, company{ comp }, groups{ grp }, Pr_number{ phone }, Scd_number{ mobile }{}

void Phonebook::create_new_user() //OK
{
	std::string name;
	std::string l_name;
	std::string ema;
	std::string home;
	std::string firm;
	std::string grps;
	std::string tel;
	std::string mob;

	std::cout << "Enter first name: ";
	std::cin >> name;

	std::cout << "Enter last name: ";
	std::cin >> l_name;

	std::cout << "Enter primary phone number: ";
	std::cin >> tel;

	std::cout << "Enter secondary phone number: ";
	std::cin >> mob;

	std::cout << "Enter e-mail address: ";
	std::cin >> ema;

	std::cout << "Enter home address: ";
	std::cin >> home;

	std::cout << "Enter company name: ";
	std::cin >> firm;

	std::cout << "Which group is the contact related to?\n"
		<< "Friends.\n"
		<< "Family.\n"
		<< "Coworkers.\n"
		<< "Acquaintance\n>";
	std::cin >> grps;

	Per_details temp{ name,l_name,ema,home,firm, grps,tel,mob };
	
	members.emplace_back(temp);
}

void Phonebook::print_all_sorted() //OK
{
	char option;
	std::cout << "Sort contacts by first (f) or last name (l)?\n>";
	std::cin >> option;
	if (option == 'f')
	{
		std::sort(members.begin(), members.end(), [](const auto& s1, const auto& s2) {return (s1.F_name < s2.F_name); });
		for (const auto& i : members)
		{
			std::cout << i;
		}
	}
	else if (option == 'l')
	{
		std::sort(members.begin(), members.end(), [](const auto& s1,const  auto& s2) {return (s1.L_name < s2.L_name); });
		for (const auto& i : members)
		{
			std::cout << i;
		}
	}
	else
	{
		std::cout << "Invalid option. Try again.\n";
	}
}

void Phonebook::printName_Num() //OK
{
	std::pair<std::string, std::string> name_and_num;
	for (const auto& i : members) {
		name_and_num = std::make_pair(i.getFName(),i.getPrNum());
		std::cout << name_and_num.first << ", " << name_and_num.second << '\n';
	}
}

void Phonebook::search_by_names() //OK
{
	char option;
	std::string temp;
	std::cout << "First (f) or last (l) name?\n>";
	
	std::cin >> option;
	if (option == 'f')
	{
		std::cout << "first name?\n>";
		std::cin >> temp;
		auto result = std::find_if(members.begin(), members.end(), [&temp](const auto& per) {return per.F_name == temp; });
		for (const auto& i : members)
		{
			std::cout << *result;
		}
	}
	else if (option == 'l')
	{
		std::cout << "last name?\n>";
		std::cin >> temp;
		auto result = std::find_if(members.begin(), members.end(), [&temp](const auto& per) {return per.L_name == temp; });
		for (const auto& i : members)
		{
			std::cout << *result;
		}
	}
	else
	{
		std::cout << "Invalid option. Try again.\n";
	}
}

void Phonebook::search_per_company() //OK
{
	std::vector<Per_details> m_workers;
	std::string cmp;
	std::cout << "What company? ";
	std::cin >> cmp;
	std::for_each(members.begin(), members.end(), [cmp, &m_workers](const auto& emp) {
		if (emp.getCompany() == cmp)
		{
			m_workers.emplace_back(emp);
		}});
	for (const auto& i : m_workers)
	{
		std::cout << i << '\n';
	}
}

void Phonebook::search_per_group() //OK
{
	std::cout << "What group? ";
	std::vector<Per_details> m_groups;
	std::string grp;
	std::cin >> grp;
	std::for_each(members.begin(), members.end(), [grp, &m_groups](const auto& emp) {
		if (emp.getGroup() == grp)
		{
			m_groups.emplace_back(emp);
		}});
	for (const auto& i : m_groups)
	{
		std::cout << i << '\n';
	}
}

void Phonebook::count_ppl()
{
	std::cout << "Printing all:\n";
	auto family = std::count_if(members.begin(), members.end(), [](const auto& s) {return s.groups == "Family"; });
	auto friends = std::count_if(members.begin(), members.end(), [](const auto& s) {return s.groups == "Friends"; });
	auto coworkers = std::count_if(members.begin(), members.end(), [](const auto& s) {return s.groups == "Coworkers"; });
	auto acq = std::count_if(members.begin(), members.end(), [](const auto& s) {return s.groups == "Acquaintance"; });

	std::cout << "No. of people from Family group: " << family << '\n';
	std::cout << "No. of people from Friends group: " << friends << '\n';
	std::cout << "No. of people from Coworkers group: " << coworkers << '\n';
	std::cout << "No. of people from Acquaintance group: " << acq << '\n';
}

std::string Per_details::getFName() const
{
	return F_name;
}

std::string Per_details::getLName() const
{
	return L_name;
}

std::string Per_details::getCompany() const
{
	return company;
}

std::string Per_details::getGroup() const
{
	return groups;
}

std::string Per_details::getPrNum() const
{
	return Pr_number;
}

std::ostream& operator<<(std::ostream& out, const Per_details& profiles)
{
	out << "[ " << profiles.F_name << " "
		<< profiles.L_name << " "
		<< profiles.Pr_number << " "
		<< profiles.Scd_number << " "
		<< profiles.e_mail << " "
		<< profiles.address << " "
		<< profiles.company << " "
		<< profiles.groups << " ]" << std::endl;
	return out;
}