#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>

int32_t blood_card(int32_t blood, int32_t max_blood)
{
    if(blood < max_blood)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int32_t jail_card(int32_t attack_time1, int32_t attack_time2, int32_t attack_time3, int32_t attack_time4, int32_t identity)
{
    if(identity == 1 || identity == 4)
    {
        srand(time(NULL));
        int32_t sort[4][2];
        int32_t check = 0;
        for(int32_t i = 0 ; i<4 ; i++)
        {
            for(int32_t j = 0 ; j<2 ; j++)
            {
                sort[i][j] = 0;
            }
        }
        for(int32_t i = 0 ; i<4 ; i++)
        {
            sort[i][0] = i+1;
        }
        sort[0][1] = attack_time1;
        sort[1][1] = attack_time2;
        sort[2][1] = attack_time3;
        sort[3][1] = attack_time4;
        if(identity == 1)
        {
            for(int32_t i = 0 ; i<4 ; i++)
            {
                for(int32_t j = i ; j<4 ; j++)
                {
                    if(sort[i][1] < sort[j][1])
                    {
                        int32_t tmp = sort[i][0];
                        int32_t tmp1 = sort[i][1];
                        sort[i][0] = sort[j][0];
                        sort[i][1] = sort[j][1];
                        sort[j][0] = tmp;
                        sort[j][1] = tmp1;
                    }
                }
            }
        }
        else if(identity == 4)
        {
            for(int32_t i = 0 ; i<4 ; i++)
            {
                for(int32_t j = i ; j<4 ; j++)
                {
                    if(sort[i][1] > sort[j][1])
                    {
                        int32_t tmp = sort[i][0];
                        int32_t tmp1 = sort[i][1];
                        sort[i][0] = sort[j][0];
                        sort[i][1] = sort[j][1];
                        sort[j][0] = tmp;
                        sort[j][1] = tmp1;
                    }
                }
            }
        }
        if(sort[0][1] == 0)
        {
            return 0;
        }   
        for(int32_t i = 1 ; i<4 ; i++)
        {
            if(sort[0][1] == sort[i][1])
            {
                check++;
            }
        }
        if(check == 0)
        {
            return sort[0][0];
        }
        if(check == 1)
        {
            int32_t rand = random() % 2;
            return sort[rand][0];
        }
        if(check == 2)
        {
            int32_t rand = random() % 3;
            return sort[rand][0];
        }
        if(check == 3)
        {
            int32_t rand = random() % 4;
            return sort[rand][0];
        }     
    }
    if(identity == 2 || identity == 3)
    {
        return 5;
    }
    return 0;
}

int32_t duel(int32_t remain , int32_t bang_num)
{
    if(remain == 2)
    {
        if(bang_num >= 3)
        {
            return 1;
        }
    }
    return 0;
}