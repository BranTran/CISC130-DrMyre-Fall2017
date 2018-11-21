/**Brandon Tran and Hannah Dasyam**/
#include <stdio.h>
#include <math.h>
/**Clean the board before the start*/
void Purge_board(int Game_board[][32],int x_size, int y_size)
{
    int i;
    int j;
    for(i=0; i<x_size; i=i+1) //Nested loop for all entries of the board
    {
        for(j=0; j<y_size; j=j+1)
        {
            Game_board[i][j] = 0;
        }
    }
}//Purge_board
/**User fill board based on coordinate*/
int user_fill(int Game_board[][32], int x_size, int y_size)
{
    int x_cor;
    int y_cor;
    int gate = 0;
    printf("Please populate the board using (x,y) coordinates. Enter (-1,-1) to finish.\n");
    printf("X: ");
    scanf(" %i", &x_cor);
    printf("Y: ");
    scanf(" %i", &y_cor);

    if((x_cor >= 0) && (y_cor >= 0) && (x_cor < x_size-2) && (y_cor < y_size-2))//Populate game board with numbers 0 to 29
    {
        printf("\nThe point %i,%i was put into the board\n",x_cor,y_cor);
        x_cor = x_cor + 1;//To put it into the buffered array
        y_cor = y_cor + 1;
        Game_board[x_cor][y_cor] = 1; // This coordinate is alive
    }
    else if((x_cor == -1)&&(y_cor == -1))//Done inputting
    {
        gate = 1;//Return the exit value
    }
    else//When it is not within board
    {
        printf("\nError: %i,%i is not a coordinate on the game board. Please try again.\n", x_cor,y_cor);
    }

    return gate;
}//user_fill

/**Auto fill board*/
void auto_fill(int Game_board[][32], int x_size, int y_size)
{
    int i;
    int j;
    srand((unsigned)time(NULL)); //Seed the random numbers
    for(i=1; i<x_size-1; i=i+1) //Go through the playable board
    {
        for(j=1; j<y_size-1; j=j+1)
        {
            int num = rand()%10;//Generates numbers 0-9, so a 1 in 10 chance for each
            if(num == 1)//One of the random number
            {
                Game_board[i][j] = num;
            }
            else
            {
                Game_board[i][j] = 0; // Everything else is 0
            }
        }
    }
}//auto_fill

/**Print Board*/
int Print_board(int Game_board[][32], int x_size, int y_size)
{
    int i;
    int j;
    int num = 0;//Number of alive cells
    system("CLS"); // Clears the terminal
    for(i=1; i<x_size-1; i=i+1) //Prints the playable board (elements 1 to full_size - 1)
    {
        for(j=1; j<y_size-1; j=j+1)
        {
            if(Game_board[i][j] != 1) //Area is dead
            {
                printf(" ");
            }
            else // Area is alive
            {
                printf("#");
                num = num + 1; //Add a life to the count
            }
        }
        printf("\n"); // Print next row of 2d array
    }
    return num;
}//Print_board

/**Calculate the neighbors*/
int Neighbor_check(int Game_board[][32],int x_size, int y_size)
{
    int i;
    int j;
    int neighbor = 0;
    int life = 0;

    /*******************
    Neighbor Calculation
    *******************/

    for (i=x_size-1;i<= x_size+1;i=i+1)  //Nested loop Down the row (-1,1)
    {
        for (j=y_size-1;j <= y_size+1; j = j+1) //Down the column(-1,1)
        {
            if(i== x_size && j == y_size)    //Not including the self (0,0)
            {
                //Do nothing
            }
            else
            {
                neighbor = neighbor + Game_board[i][j];
            }
        }
    }
    /*******************
    ******Arguments*****
    *******************/
    if (Game_board[x_size][y_size] == 1) //Current cell is alive
    {
        if (neighbor == 2 || neighbor == 3)
        {
            life = 1;
        }
        else
        {
            life = 0;
        }
    }
    else     //Current cell is dead
    {
        if (neighbor == 3)
        {
            life = 1;
        }
        else
        {
            life = 0;
        }
    }
    return life;
}//Neighbor_check

/**Put temp data back into Game board*/
void Refill_board(int Game_board[][32],int temp_board[][32],int x_size, int y_size)
{
    int i;
    int j;
    for(i=0; i<x_size; i=i+1) // The entire board is reassigned
    {
        for(j=0; j<y_size; j=j+1)
        {
            Game_board[i][j] = temp_board[i][j]; // The game board takes on the data from the temporary board
        }
    }
}//Refill_board

/**Evolves the board into the next generation*/
int playGame(int Game_board[][32],int future_temp_board[][32], int past_temp_board[][32],int present_temp_board[][32],int x_size, int y_size) //Evolves the code into the next generation
{
    int i;
    int j;
    int stable;
    for(i=1; i<x_size-1; i=i+1)
    {
        for(j=1; j<y_size-1; j=j+1)
        {

           future_temp_board[i][j] = Neighbor_check(Game_board, i, j);
            //otherwise check for the neighbors to determine life and death
        }
    }
    stable = Stable_check(Game_board,future_temp_board,past_temp_board,present_temp_board,x_size,y_size);

    //Take the data from temp_board and put it back into the game_board
    Refill_board(Game_board,future_temp_board,x_size,y_size);

    return stable;
}//Play_game

int Stable_check(int Game_board[][32],int future_temp_board[][32], int past_temp_board[][32],int present_temp_board[][32],int x_size, int y_size)
{
    int i;
    int j;
    int stable = 0;
    int match_past = 0;
    int match_present = 0;
    int total_spaces;
    total_spaces = (x_size-2)*(y_size-2);

    /**Check the last game board with the temp_board that holds the next generation (Checks stable groups)*/
    for(i=1; i<x_size-1; i=i+1)
    {
        for(j=1; j<y_size-1; j=j+1)
        {

            if(future_temp_board[i][j] == past_temp_board[i][j])    //Not including the self (0,0)
            {
                match_past = match_past + 1;
            }
        }
    }
    if(match_past == total_spaces)
    {
        stable = 1;
    }

    /**Check the last game board with the temp_board that holds the previous generation (Checks alternating groups)*/
    for(i=1; i<x_size-1; i=i+1)
    {
        for(j=1; j<y_size-1; j=j+1)
        {

            if(future_temp_board[i][j] == past_temp_board[i][j])    //Not including the self (0,0)
            {
                match_present = match_present + 1;
            }
        }
    }
    if(match_present == total_spaces)
    {
        stable = 1;
    }

    return stable;
}//Stable_check

int main()
{
    int x_size = 32; //Build a playable 30X30 board with 0's all around it.
    int y_size = x_size;
    int Game_board[x_size][y_size];
    Purge_board(Game_board,x_size,y_size);

    printf("Welcome to the Game of Life!\n");

    /********************
    ****FILL THE BOARD***
    ********************/
    int mode;
    int fill_method = 0;
    while(fill_method == 0)
    {
        printf("Please enter 0 for User mode or 1 for Automatic Mode: ");
        scanf(" %i", &mode);

        if(mode == 0)
        {
            printf("\nCurrently in User Mode\n");
            /**User Mode*/
            int gate = 0;
            while(gate == 0)//while the gate is open
            {
                gate = user_fill(Game_board,x_size,y_size);
                fill_method = 1;
            }
        }
        else if(mode == 1)
        {
            printf("\nCurrently in Auto Mode\n");
            /**Automatic Mode*/
            auto_fill(Game_board,x_size,y_size);
            fill_method = 1;
        }
        else
        {
            printf("\nError: Incorrect input. Please try again\n");
        }
    }

    /********************
    ****PLAY THE BOARD***
    ********************/
    int door = 0;
    int gen = 0;
    int num = 0;
    int trigger = 0;
    char confirm;
    int temp_boardA[x_size][y_size];
    Purge_board(temp_boardA,x_size,y_size);
    int temp_boardB[x_size][y_size];
    Purge_board(temp_boardB,x_size,y_size);
    int temp_boardC[x_size][y_size];
    Purge_board(temp_boardC,x_size,y_size);
    /**Go through multiple times**/
    while((door == 0)&&(trigger == 0))
    {
        num = Print_board(Game_board,x_size,y_size);
        printf("We are on Generation %i, there are %i still alive\n",gen, num);

        if(num == 0)//If the board is dead
        {
            printf("\nAll cells have been terminated. This game has ended\n");
            door = 1;
        }
        else
        {
            printf("Would you like to go into the next generation? (Y/N):");
            scanf(" %c", &confirm);
            if((confirm == 'Y')||(confirm == 'y'))//If they want to continue playing
            {
                //Do nothing
            }
            else
            {
                door = 1;
            }
        }

        /**Switch temp board based on generation number*/
        if(gen%3 == 1)//First
        {
            trigger = playGame(Game_board,temp_boardB,temp_boardC,temp_boardA,x_size,y_size);//
        }
        else if(gen%3 == 2)
        {
            trigger = playGame(Game_board,temp_boardC,temp_boardA,temp_boardB,x_size,y_size);//
        }
        else//Even Generations
        {
            trigger = playGame(Game_board,temp_boardA,temp_boardB,temp_boardC,x_size,y_size);
        }
        //door = Stable_board(Game_board,temp_boardA,temp_boardB,x_size,y_size);
        gen = gen + 1;
    }

    if (trigger == 1) // Terminated based stable state
    {
        printf("Board has reached a stable state. Game of \"DYNAMIC\" life will now terminate.\n");
    }
    printf("\nThank you for playing!\n");
}//main

