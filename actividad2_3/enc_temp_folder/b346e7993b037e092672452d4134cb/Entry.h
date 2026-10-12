#pragma once
#include <string>
#include <vector>

class IP {
private:
	int octeto1;
	int octeto2;
	int octeto3;
	int octeto4;
	
public:
	IP() {
		octeto1 = 0;
		octeto2 = 0;
		octeto3 = 0;
		octeto4 = 0;
	}
	IP(std::string unparsed);
	const std::string getFullIP() {
		return std::to_string(octeto1) + "." + std::to_string(octeto2) + "." + std::to_string(octeto3) + "." + std::to_string(octeto4);
	}

	const bool operator<(IP other) {
		if (octeto1 < other.octeto1) return true;
		if (octeto2 < other.octeto2 && octeto1 == other.octeto1) return true;
		if (octeto3 < other.octeto3 && octeto2 == other.octeto2) return true;
		if (octeto4 < other.octeto4 && octeto3 == other.octeto3) return true;
		return false;
	}
	const bool operator>(IP other) {
		return !(*this < other);
	}
	const bool operator==(IP other) {
		return octeto1 == other.octeto1 && octeto2 == other.octeto2 && octeto3 == other.octeto3 && octeto4 == other.octeto4;
	}
	const bool operator>=(IP other) {
		return *this > other || *this == other;
	}
	const bool operator<=(IP other) {
		return *this < other || *this == other;
	}
	const bool operator!=(IP other) {
		return !(*this == other);
	}
};

class Entry {
private:
	std::string full_entry;
	std::string month;
	std::string day;
	std::string time;
	IP ip;
	std::string message;
public:
	Entry(std::string);

	const static int month_to_int(std::string);
	std::string get_full_entry();
	
	IP get_comparable() { return ip; }
};

std::vector<Entry*> create_vector_of_entries_from_file(std::string);
