#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct _sCard
{
    int32_t num;
    int32_t suit[25];
}__attribute__ ((__packed__));

typedef struct _sCard sCard;

int32_t card_struct_init(sCard *info)
{
    info->num = 0;
    for(int32_t i = 0 ; i<25 ; i++)
    {
        info->suit[i] = 0;
    }
}

int32_t card_info(FILE *cardFile , sCard *info , int32_t count)
{
    card_struct_init(info);

    char c;
    int32_t check = 0;
    int32_t index = 0;
    int32_t store = 0;
    count = count - 1;

    while((c = fgetc(cardFile)) != EOF) 
	{
        if(check == count)
        {
            if(index == 2 && c != '\n')
            {
                info->num = info->num*10 + ((int)c - 48);
            }
            if(index == 1 && c != ' ')
            {
                if(c == '/')
                {
                    store++;
                }
                else
                {
                    info->suit[store] = info->suit[store]*10 + ((int)c - 48);
                }
            }
            if(c == ' ')
            {
                index++;
            }
        }
        if(c == '\n')
        {
            check++;
        }
    }
}