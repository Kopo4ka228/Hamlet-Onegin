#include <string.h>
#include <stdlib.h>
#include <windows.h>

int const A_minus_a = 'a' - 'A';

int Alphabet (char* str1, char* str2);
char* Skip_Spaces (char* line); // возвращает указатель на первую букву(пропускает пробелы)
bool is_Capital (char ch);     // не используется
int is_notEmpty (const char* str);
void swap_arrays (char* str1, char* str2, int maxSymbols);

int Alphabet (char* str1, char* str2)
{
    char* line1 = Skip_Spaces (str1);
    char* line2 = Skip_Spaces (str2);
                                                                // на обычных примерах протестирована
    for(int i = 0; line1[i] != '\0' && line2[i] != '\0'; i++)
    {
        if (line1[i] != line2[i])
        {
            if (is_Capital(line1[i]))
                line1[i] += A_minus_a;
            if (is_Capital(line2[i]))
                line2[i] += A_minus_a;
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
void swap_arrays (char* str1, char* str2, int maxSymbols)
{
  long long tmp = 0;
  for (int nchars = 0; nchars < maxSymbols; nchars += sizeof(long long))
  {
    tmp = * (long long*) (str1 + nchars);
    *(long long*)(str1 + nchars) = *(long long*)(str2 + nchars);  //porasitelno
    *(long long*)(str2 + nchars) = tmp;                           //(fascinating, yeah)

  //  str1 [nchars] = str2 [nchars];
  //  str2 [nchars] = tmp;

    /*
    BYTE* BTtemp = (BYTE*) (&tmp);
    for (int i = 0; i < sizeof(long long); i++)
    {
        BTtemp[i] = str1[i + nchars];
        str1[i + nchars] = str2[i + nchars];      //лучше ли это побайтового копирования?
        str2[i + nchars] = BTtemp[i];
    }
    */
  }
}

