#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100], wrd[100];

    puts("Enter line: ");
        gets_s(str);

    for (int i = 0, k = 0; str[i] != '\0'; i++)
        if (str[i] == '.')
        {
            for (int j = 0; j < i; j++)
                if ( isdigit(str[j]) )
                {
                    wrd[k] = str[j];
                    k++;
                }
            
            if (k)
            {
                wrd[k] = '.';
                k++;
            }

            for (int j = i+1; str[j] != '\0' && k > 0; j++)
                if ( isdigit(str[j]) )
                {
                    wrd[k] = str[j];
                    k++;
                }
                else if (str[j] == 'e')
                {
                    for (int l = j+1; str[l] != '\0'; l++)
                        if ( isdigit(str[l]) )
                        {
                            k = 0;
                            break;
                        }
                }
                    
            if (k && wrd[k-1] != '.')
            {
                wrd[k] = str[0] = '\0';
                puts(wrd);
            }
            k = 0;
        }

    if (str[0] != '\0') puts("No fixed dot numbers");

    return 0;
}