#include "header.h"
#include "functions.cpp"
using namespace std;

int main(int argc, char* argv[])
{
    int found_index;
    string bigStr, subStr, filename, operation;

    // Vaihtoehtolippujen ilmoittaminen loogisiksi arvoiksi.
    bool occurrences = false;
    bool line_numbers = false;
    bool reverse_search = false;
    bool ignore_case = false;

    // kysy merkkijonoa ja alimerkkijonoa.
    // Tehdään vain, kun argumentit on annettu.
    if (argc == 1)
    {
        cout << "Give a string from which to search for: ";
        getline(cin, bigStr);

        cout << "Give search string: ";
        getline(cin, subStr);

        // etsi vastaavuus ja määritä arvo found_index:ille.
        found_index = bigStr.find(subStr);

        // tulosta output
        if (found_index != string::npos)
        {
            cout << "\"" << subStr << "\" found in \"" << bigStr << "\" in position " << found_index << endl;
        }
        else
        {
            cout << "\"" << subStr << "\" NOT found in \"" << bigStr << "\"" << endl;
        }
    }

    // Kun tiedosto ja hakusana annetaan, mutta ei lippuja.
    else if (argc == 3 && argv[2] != "")
    {
        operation = "";
        subStr = argv[1];
        filename = argv[2];
        search_from_file(operation, subStr, filename, line_numbers, occurrences, reverse_search, ignore_case);
    }

    // Kun liput, hakusana ja tiedostonimi annetaan.
    else if (argc == 4 && argv[2] != "")
    {
        operation = argv[1];
        subStr = argv[2];
        filename = argv[3];

        // Tarkista, että "-o" on ensimmäinen  argv[1]:ssa.
        if (strstr(argv[1], OPTIONS_CHAR) == argv[1])
        {

            // Poista kaksi ensimmäistä elementtiä ("-" ja "o") argv[1]:sta
            argv[1] = &argv[1][2];

            // etsi lippumerkkejä tiedostosta argv[1] ja aseta vastaavat liput //arvoon tosi, jos ne löytyvät.
            if (strstr(argv[1], OCCURRENCES_CHAR))
            {
                occurrences = true;
            }

            if (strstr(argv[1], LINE_NUMBERS_CHAR))
            {
                line_numbers = true;
            }

            if (strstr(argv[1], REVERSE_SEARCH_CHAR))
            {
                reverse_search = true;
            }

            if (strstr(argv[1], IGNORE_CASE_CHAR))
            {
                ignore_case = true;
            }

            search_from_file(operation, subStr, filename, line_numbers, occurrences, reverse_search, ignore_case);
        }

        // virheelliset liput, anna käyttäjälle virheilmoitus.
        else
        {
            cout << "error: Incorrect options." << endl;
        }
    }

    else
    {
        cout << "An exception occurred." << endl;
    }

    return 0;
}
