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
    for(int i =  0; i < nLines; i++)
    {
        input_string_array[i] = (char*) calloc (maxSymbols, sizeof (char));
    }  // fn

    int numstr = 0;
    while (numstr < nLines)
    {
        fgets (input_string_array[numstr], maxSymbols, file);
        numstr++;
    }  // fn

    // придумать сортировку
    int the_num_of_the_perestanovok___muahahaha = 1;
    while (the_num_of_the_perestanovok___muahahaha != 0)
    {
        the_num_of_the_perestanovok___muahahaha = 0;
        for(int num_line = 0; num_line < nLines - 1; num_line++)
        {
            if (Alphabet(input_string_array[num_line], input_string_array[num_line + 1]) > 0)
            {
                swap_arrays(input_string_array[num_line], input_string_array[num_line + 1], maxSymbols);
                the_num_of_the_perestanovok___muahahaha++;
            }
        }
    }  // the zhirnaya funkcija!

    for(int i = 0; i < nLines; i++)
    {
        if (is_notEmpty(input_string_array[i]))
            {
                puts(input_string_array[i]);
            }
    } // fn

    free (input_string_array); // �������� ���������� ������� ������������
    return 0;
}
