#include "header.h"
using namespace std;

void to_lower_case(std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void search_from_file(std::string operation, std::string sub_string, std::string filename, bool show_line_numbers, bool show_occurrences, bool reverse_search, bool ignore_case)
{
     // Funktio, joka käsittelee tiedoston lukemisen ja tiedostosta hakemisen.
    fstream searchfile;
    searchfile.open(filename, ios::in);

    // muuttujien ilmoittaminen
    int line_number = 0, occurrences = 0, not_occurrences = 0;
    string file_line, file_line_temp, sub_string_temp = sub_string;
    bool file_error = false;
    bool sub_string_found = false;

    // muuta sub_string_temp pieniksi kirjaimille, jos ignore_case on tosi.
    if (ignore_case)
    {
        to_lower_case(sub_string_temp);
    }

    // Tarkistaa, että tiedosto voidaan lukea oikein.
    if (!searchfile)
    {
        file_error = true;
        cout << "An exception occurred." << endl;
    }

    // tapahtumien etsiminen ja niiden laskeminen.
    else
    {
        while (!searchfile.eof())
        {
            line_number++;
            getline(searchfile, file_line);
            file_line_temp = file_line;

            // jos ignore_case on tosi, muunna file_line_temp pieniin kirjaimiin.
            if (ignore_case)
            {

                to_lower_case(file_line_temp);
            }

            if (file_line_temp.find(sub_string_temp) != string::npos)
            {
                sub_string_found = true;
            }

            if (sub_string_found && !reverse_search)
            {
                occurrences++;

                 // jos show_line_numbers on tosi, tulosta myös rivien numerot,
                 // jos ei, tulosta vain rivin sisältö.
                 
                if (show_line_numbers)
                {
                    cout << line_number << ":";
                }
                if (operation != "-oo") {

                    cout << file_line << endl;
                }
            }

            else if (!sub_string_found && reverse_search)
            {
                not_occurrences++;

                if (show_line_numbers)
                {
                    cout << line_number << ":";
                }

                cout << file_line << endl;
            }

            sub_string_found = false;
        }
    }

    searchfile.close();

    // Tulostetaan, jos show_occurrences on tosi
    if (show_occurrences && !reverse_search && !file_error)
    {
        cout << "\nOccurrences of lines containing \"" << sub_string << "\": " << occurrences << endl;
    }

    else if (show_occurrences && reverse_search && !file_error)
    {
        cout << "\nOccurrences of lines NOT containing \"" << sub_string << "\": " << not_occurrences << endl;
    }
}

