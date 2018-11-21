//Brandon Tran, Aleksey Garbaly,

#include <stdio.h>
#include <string.h>
#include <math.h>

/**Extra functions to have less coding && string Challenge**/
int sign(int card)//determine the suit of a card
{
    int suit;
    suit = (card%4);
    return suit;
}//sign

int num(int card)//determine the value of the card
{
    int suit;
    suit = sign(card);
    int value;
    value = ((card-suit)/4)+1;
    return value;
}//num

int result(int card)//determine if it is non-number and return corresponding non-number thing
{
    int value;
    value = num(card);
    int result = 0;

    if(value > 9)
    {
        if(value%9 == 2)
        {
            result = value%9;
        }
        else if(value%9 == 3)
        {
            result = value%9;
        }
        else if(value%9 == 4)
        {
            result = value%9;
        }
    }
    else
    {
        if(value%9 == 1)
        {
            result = value%9;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

/** Actual Lab functions needed**/
int getCards(int Cards[])
{
    int num_card = 0;
    int count = 1;
    int trigger = 0;
    while((count < 10) && (trigger == 0))//pulled out after count = 9, or when trigger goes off
    {
        printf("Please enter a card or enter -1 to finish: ");
        scanf(" %i", &num_card);
        if((num_card > 51) || (num_card < -1))
        {
            printf("Sorry, the number you entered is not valid.\n");
        }
        else if(num_card == -1)//pull out of loop
        {
            trigger = 1;//do nothing;
        }
        else
        {
            Cards[count-1] = num_card;//count-1 will begin at 0
            ++count;
        }
    }
    return count;
}//getCards

void displayCards(int Cards[], int numCards)
{

    /**SET UP STRING ARRAYS*/
    char suits[4][9] =
    {
        {'c','l','u','b','s','\0'},
        {'s','p','a','d','e','s','\0'},
        {'d','i','a','m','o','n','d','s','\0'},
        {'h','e','a','r','t','s','\0'}
    };

    char nonnum[5][6] =
    {
        {'E','r','r','o','r','\0'},
        {'A','c','e','\0'},
        {'J','a','c','k','\0'},
        {'Q','u','e','e','n','\0'},
        {'K','i','n','g','\0'}
    };

    /**DO THE THING*/
    int card;
    int i;
    int card_value;
    printf("\nYour hand is:");
    for(i = 1; i < numCards; i = i+1)
    {
        card = Cards[i-1];
        if(result(card) != 0)//non number card
        {
            printf("\n\t%s of %s",nonnum[result(card)],suits[sign(card)]);
        }
        else
        {
            card_value = num(card);
            printf("\n\t%i of %s",card_value,suits[sign(card)]);
        }
    }
}//displayCards

int simpleSumCards(int Cards[], int numCards)
{
    int i = 0;
    int card_value;
    int card;
    int sum_cards = 0;
    int sum_suit = 0;
    int suit;
    int hand = 0;
    while(i < numCards-1)
    {
        card = Cards[i];
        suit = sign(card);
        card_value = num(card);
        sum_cards =  sum_cards + card_value;
        sum_suit = sum_suit + suit;
        ++i;
    }
    //printf("The total value of your hand is:\n");
    hand = sum_cards - sum_suit;
    //printf(" %i", hand);
    return hand;
}//simpleSumCards

int hasThreeOrMoreNonnumberCards(int Cards[], int numCards)
{
    int trigger = 0;
    int card;
    int suit;
    int value;
    int count = 0;
    int i;
    for(i = 0; i < numCards -1; i = i+1)
    {
        card = Cards[i];
        suit = sign(card);
        value = num(card);
        if ((value > 10)||(value == 1))
        {
            count = count + 1;
        }
    }
    if (count >= 3)
    {
        trigger = 1;
    }
    return trigger;
}// hasThreeOrMoreNonnumberCards

int isPrime(int score)
{
    int i;
    int prime = 1;
    for(i = 2; i < (sqrt(score)); i=i+1)
    {
        if((score%i) != 0)//not divisible
        {
            //Do nothing you're one step closer to being prime
        }
        else//Oh, no something divisible
        {
            prime = 0;
        }
    }
    return prime;
}//isPrime

int nextHighestPowerofTwo(int score)
{
    int two_power = 2;
    while(score > two_power)
    {
        two_power = two_power*2;
    }
    return two_power;
}//nextHighestPowerofTwo

int calculateHandValue(int Cards[],int numCards)
{
    int score;
    score = simpleSumCards(Cards,numCards);

    if(hasThreeOrMoreNonnumberCards(Cards,numCards) == 1)
    {
        score = (score*score)+7;
    }

    if(isPrime(score) == 1)
    {
        score = score + nextHighestPowerofTwo(score);
    }
    return score;
}

int main()
{
    printf("Welcome to Up-To-9-Card Myer!!\n\n");
    int hand[9];
    int score;
    int numCards = getCards(hand);
    displayCards(hand,numCards);
    score = calculateHandValue(hand,numCards);
    printf("\n\nThe total value of your hand is:\n%i points\n", score);
}
