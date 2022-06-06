int main()
{
    FILE *cardFile;
    if( (cardFile = fopen("card.txt" , "r")) == NULL )
    {
        printf("cardFile can't be open!\n");
    }

    sCard info;
    int32_t count = 0;

    printf("count: ");
    scanf("%d",&count);

    card_info(cardFile , &info , count);
    printf("num: %d\n",info.num);
    for(int32_t i = 0 ; i<25 ; i++)
    {
        printf("suit: %d\n",info.suit[i]);
    }
}
