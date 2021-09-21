#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int const a_minus_A = 'a' - 'A';
int const MAXSYMBOLS = 512;

int Alphabet (char* str1, char* str2);
char* Skip_Spaces (char* line); // возвращает указатель на первую букву(пропускает пробелы)
bool is_Capital (char ch);     // не используется
int is_notEmpty (const char* str);
void swap_arrays (char* str1, char* str2, int maxSymbols);
void sorting (char** input_string_array, int nLines);
void print_not_empty_lines (char** input_string_array, int nLines);
char** to_initialise_array (int nLines);
void free_array (char** input_string_array, int nLines);
void put_lines_in_array (FILE* file, char** input_string_array, int nLines);
int put_all_Lines (FILE* file);

int put_all_Lines (FILE* file)
{
    char ch = getc (file);
    int count = 0;
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
        ch = getc (file);
    }
    return count + 1;
}
//-----------------------------------------------------------------------------

int Alphabet (char* str1, char* str2)
{
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    char* line1 = Skip_Spaces (str1);
    char* line2 = Skip_Spaces (str2);
                                                                // на обычных примерах протестирована
    for(int i = 0; line1[i] != '\0' && line2[i] != '\0'; i++)
    {
        if (line1[i] != line2[i])
        {
            if (is_Capital(line1[i]))
                line1[i] += a_minus_A;
            if (is_Capital(line2[i]))
                line2[i] += a_minus_A;
            return line1[i] - line2[i];
        }
    }

    return 0;
}

//-----------------------------------------------------------------------------

char* Skip_Spaces (char* line)
{
    assert (line != NULL);

    int i = 0;
    while (*(line + i) == ' ')        //протестирована на обычных примерах
        {
        i++;
        }

    return (line + i);
}

//-----------------------------------------------------------------------------

bool is_Capital (char ch)
{
    if (ch >= 'A' && ch <= 'Z') return true;
    else return false;
}

//-----------------------------------------------------------------------------

int is_notEmpty (const char* str)
{
    assert(str != nullptr);

    int count = 0;
    for (int i = 0; i < str[i]; i++)
    {
        if (str[i] != ' ')
        {                                    // протестирована на обычных примерах
            count++;
        }
    }

    return /* истинность того факта, что */ (str [count] != '\0');
}

//-----------------------------------------------------------------------------
void swap_arrays (char* str1, char* str2, int MAXSYMBOLS)
{
  assert(str1 != nullptr);
  assert(str2 != nullptr);

  long long tmp = 0;
  for (int nchars = 0; nchars < MAXSYMBOLS; nchars += sizeof(long long))
  {
    tmp = * (long long*) (str1 + nchars);
    *(long long*)(str1 + nchars) = *(long long*)(str2 + nchars);  //porasitelno
    *(long long*)(str2 + nchars) = tmp;                           //(fascinating, yeah)
  }
}

//-----------------------------------------------------------------------------
void sorting(char** input_string_array, int nLines)
{
    int the_num_of_the_perestanovok___muahahaha = 1;
    while (the_num_of_the_perestanovok___muahahaha != 0)
    {
        the_num_of_the_perestanovok___muahahaha = 0;
        for(int num_line = 0; num_line < nLines - 1; num_line++)
         {
            if (Alphabet (input_string_array[num_line], input_string_array[num_line + 1]) > 0)
          {
            swap_arrays (input_string_array[num_line], input_string_array[num_line + 1], MAXSYMBOLS);
            the_num_of_the_perestanovok___muahahaha++;
          }
         }
    }

 }

//-----------------------------------------------------------------------------
void print_not_empty_lines (char** input_string_array, int nLines)
{
    for(int i = 0; i < nLines; i++)
    {
        if (is_notEmpty(input_string_array[i]))
            {
                puts(input_string_array[i]);
            }
    }
}

//-----------------------------------------------------------------------------
char** to_initialise_array(int nLines)
{
    char** input_string_array = (char**) calloc (nLines, sizeof (char*)); //динамический массив со строками из текста

    for(int i =  0; i < nLines; i++)
    {
        input_string_array[i] = (char*) calloc (MAXSYMBOLS, sizeof (char));
    }

    return input_string_array;
}

//-----------------------------------------------------------------------------
void free_array(char** input_string_array, int nLines)
{
    for (int i = 0; i < nLines; i++)
    {
        free(input_string_array[i]);
    }

    free(input_string_array);
}

//-----------------------------------------------------------------------------
void put_lines_in_array(FILE* file, char** input_string_array, int nLines)
{
    int numstr = 0;
    while (numstr < nLines)
    {
        fgets (input_string_array[numstr], MAXSYMBOLS, file);
        numstr++;
    }
}
