#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

const char* OPTIONS_CHAR = "-o";
const char* OCCURRENCES_CHAR = "o";
const char* LINE_NUMBERS_CHAR = "l";
const char* REVERSE_SEARCH_CHAR = "r";
const char* IGNORE_CASE_CHAR = "i";

void search_from_file(std::string operation, std::string sub_string, std::string filename, bool show_line_numbers, bool show_occurrences, bool reverse_search, bool ignore_case);
void to_lower_case(std::string& str);

#endif // HEADER_H
