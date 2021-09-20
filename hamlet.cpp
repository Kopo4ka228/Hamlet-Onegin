#include "C:\Github\std_funcs\my_funcs().h"
#include <TXLib.h>
#include "sort_alphabet.h"

int const maxSymbols = 512;  // kill!    //макс кол-во символов в строке (должно делиться на 8)

//-----------------------------------------------------------------------------

int main()
{

    FILE* file = fopen("Hamlet.txt", "r");

    int nLines = 0;
    printf("Введите количество строк nLines\n");
    scanf("%d", &nLines);

    char** input_string_array = (char**) calloc (nLines, sizeof (char*)); //динамический массив со строками из текста
    to_initialise_array(input_string_array, nLines);

    int numstr = 0;
    while (numstr < nLines)
    {
        fgets (input_string_array[numstr], maxSymbols, file);
        numstr++;
    }  // fn

    // придумать сортировку
    sorting(input_string_array, nLines);

    print_not_empty_lines(input_string_array, nLines);

    free_array(input_string_array, nLines);
    return 0;
}
