#pragma once
#include <string>
#include <vector>

class IP {
private:
	int octeto1;
	int octeto2;
	int octeto3;
	int octeto4;
	
	static bool is_octeto_valid(int);
public:
	IP();
	IP(std::string unparsed);
	static bool is_ip_valid(IP*);
	const std::string getFullIP();


	bool operator<(const IP& o) const;
	bool operator>(const IP& o) const;
	bool operator==(const IP& o) const;
	bool operator>=(const IP& o) const;
	bool operator<=(const IP& o) const;
	bool operator!=(const IP& o) const;
};

class Entry {
private:
	std::string full_entry;
	std::string month;
	std::string day;
	std::string time;
	IP* ip;
	std::string message;
public:
	Entry(std::string);

	const static int month_to_int(std::string);
	std::string get_full_entry();
	
	IP get_comparable() { return *ip; }
};

std::vector<Entry*> create_vector_of_entries_from_file(std::string);
