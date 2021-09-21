#include "C:\Github\std_funcs\my_funcs().h"
#include <TXLib.h>
#include "sort_alphabet.h"

int const ALL_LINES = -1;
//-----------------------------------------------------------------------------

int main()
{
    int nLines = 0;
    printf("Введите количество строк nLines\n");
    scanf("%d", &nLines);

    FILE* file = fopen("Hamlet.txt", "r");
    if (nLines == ALL_LINES)
    {
        nLines = put_all_Lines(file);
    }
    printf("%d", nLines);
    char** input_string_array = to_initialise_array(nLines);
    put_lines_in_array (file, input_string_array, nLines);

    // придумать сортировку
    sorting(input_string_array, nLines);

    print_not_empty_lines(input_string_array, nLines);

    free_array(input_string_array, nLines);
    return 0;
}
