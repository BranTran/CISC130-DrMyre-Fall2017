/*Melissa Guzman
Brandon Tran*/
#include <stdio.h>
int main ()
{
    //Get input string
    char str[1000];
    printf("Please enter your message:");// some other code might go here
    fgets(str, 1000, stdin);
    int size = strlen(str);
    str[size-1] = '\0';
    //Ask to encrypt or decrypt
    int choice;
    printf("Would you like to (1) encrypt this message or (2) decrypt it:");
    scanf(" %i", &choice);

    //Encrypting a message
    int index;
    int counter = 0;
    int difference;

    printf("The number choice is %i\n",choice);
    //To encrypt
    if (choice == 1)
    {
        //Go through each index
        while(counter <= (size-2))
        {
            //Separate uppercase, lowercase, other junk
            if(str[counter] >= 'a' && str[counter] <= 'z')
            {
                //Catching the wrap around after z
                index = (counter+1)%26;
                if((str[counter]+index) > 'z')
                {
                    difference = (str[counter]+index)-'z';
                    str[counter] = 'a'+(difference - 1);
                }
                else
                {
                    str[counter] = str[counter]+index;
                }
            }
            else if(str[counter] >= 'A' && str[counter] <= 'Z')
            {
                index = (counter+1)%26;
                if((str[counter]+index) > 'Z')
                {
                    difference = (str[counter]+index)-'Z';
                    str[counter] = 'A'+(difference - 1);
                }
                else
                {
                    str[counter] = str[counter]+index;
                }
            }
            else
            {
                str[counter] = str[counter];
            }
            counter = counter + 1;
        }//while counter
        printf("Your encrypted message is:\n%s",str);
    }//if choice ==1

    //Decrypt the message
    else if(choice == 2)
    {
        //Go through each index
        while(counter <= (size-2))
        {
            //Separate uppercase, lowercase, other junk
            if(str[counter] >= 'a' && str[counter] <= 'z')
            {
                //Catching the wrap around before a
                index = (counter+1)%26;
                if((str[counter]-index) < 'a')
                {
                    difference = 'a'-(str[counter]-index);
                    str[counter] = 'z'-(difference - 1);
                }
                else
                {
                    str[counter] = str[counter]-index;
                }

            }
            else if(str[counter] >= 'A' && str[counter] <= 'Z')
            {
                index = (counter+1)%26;
                if((str[counter]-index) < 'A')
                {
                    difference = 'A'-(str[counter]-index);
                    str[counter] = 'Z'-(difference - 1);
                }
                else
                {
                    str[counter] = str[counter]-index;
                }
            }
            else
            {
                str[counter] = str[counter];
            }
            counter = counter + 1;
        }//while counter
        printf("Your decrypted message is:\n%s", str);
    }//else if choice ==2
    else
    {
        printf("You didn't choose 1 or 2, no encryption for you.\n");
    }//else
}//int main
