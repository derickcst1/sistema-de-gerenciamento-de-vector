#include "header.hpp"

int main()
{

    while (true)
    {
        int menu_option = menu();

        switch (menu_option)
        {
        case 0:
            return 0;
            break;

        case 1:
            insert_string(dictionary);
            break;

        case 2:
            show_dictionary(dictionary);
            vizualization_time();
            break;

        case 3:
            search_string(dictionary);
            vizualization_time();
            break;

        case 4:
            search_substring(dictionary);
            vizualization_time();
            break;

        case 5:
            remove_string_by_index(dictionary);
            break;

        case 6:
            remove_string_by_substring(dictionary);
            break;

        default:
            break;
        }
    }
}