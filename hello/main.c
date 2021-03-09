/* include header file */
#include <stdio.h>
#include <stdlib.h>

int a,b,c,d; //input
int count1=0;
int count2=0;
int fct=0,fc1=0,fc2=0;
int turn=0;
/* given TypeCard structure definition */
typedef struct card {
    char suit;   // 'S'pade / 'H'eart / 'C'lub / 'D'iamond
    int  rank;   // A (1) / 2 - 10 / J (11) / Q (12) / K (13);
    int  status; // covered (0) or flipped (1) or chosen (-1), etc.
} TypeCard;

void printCard( TypeCard   aCard )
{
    if (aCard.status == 0)
        printf("XXX");
    else


    {
        /* display suit of a card */
        switch (aCard.suit) {
            case 'S':
            case 'H':
            case 'C':
            case 'D':
                printf("%c", aCard.suit);
                break;
            default:
                printf("?");
        }

        /* Enter your code here. */

    {
        if((aCard.rank>=2) && (aCard.rank<=10))
        printf("%2d",aCard.rank);
        else
        {   switch(aCard.rank)
            {   case 1:printf(" A");break;
                case 11:printf(" J");break;
                case 12:printf(" Q");break;
                case 13:printf(" K");break;
            default:
            printf("??");
            }
        }
        /* display rank of a card */
    }
    }
    return;
}

void showDesktop( TypeCard   desktop[4][14] )
{
    /* show all 4 x 13 cards in the desktop 2D TypeCard array */

    for(int row=0;row<4;row++)
    {   for(int col=1;col<=13;col++)
        {printCard(desktop[row][col]);
        printf("\t");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    while(1){
    printf("******************************\n");
    printf("* Wellcome to Concentration! *\n");
    printf("******************************\n");
    printf("Please choose a mode of the game:\n");
    printf("1. Human vs. Computer\n");
    printf("2. Computer vs. Computer\n");
    printf("0.Quit\n");
    printf("Your choice:");
    scanf("%d",&n);



     TypeCard desktop[4][14] = {
        /* the first element (column 0) of each row is UNUSED */
        /* row: 0 - 3; col: 1 - 13 */
        {{}, {'S', 1}, {'S', 2}, {'S', 3}, {'S', 4}, {'S', 5}, {'S', 6}, {'S', 7}, {'S', 8}, {'S', 9}, {'S', 10}, {'S', 11}, {'S', 12}, {'D', 13}},
        {{}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9}, {'C', 10}, {'H', 11}, {'H', 12}, {'H', 13}},
        {{}, {'C', 13}, {'C', 12}, {'C', 11}, {'H', 10}, {'C', 9}, {'C', 8}, {'C', 7}, {'C', 6}, {'C', 5}, {'C', 4}, {'C', 3}, {'C', 2}, {'C', 1}},
        {{}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9}, {'D', 10}, {'D', 11}, {'D', 12}, {'S', 13}}
    };

    //quit
    if(n==0){
        return 0;
    }

    //human vs computer
    if(n==1)
    {
        showDesktop(desktop);
        while(1)
       {
        while(1){
        printf("Please input 1st card:");
        scanf("%d %d",&a,&b);
        if ((a>=0)&&(a<=3)&&(b>=1)&&(b<=13)){
            if(desktop[a][b].status==1){
                printf("The card must not be flipped already\n");
            }else{
        desktop[a][b].status=1;
        printf("You chose 1st card (%d,%2d) and it is ",a,b);
        printCard(desktop[a][b]);
        printf("\n");
        break;}}
        else{
            printf("Row and column must be within 0 - 3 and 1 - 13\n");
        }
        }
        while(1){
        printf("Please input 2nd card:");
        scanf("%d %d",&c,&d);
        if ((c>=0)&&(c<=3)&&(d>=1)&&(d<=13)){
                if(desktop[c][d].status==1){
                        if(((desktop[c][d].suit)==(desktop[a][b].suit))&&((desktop[c][d].rank)==(desktop[a][b].rank)))
                        printf("The second card cannot be the same as frist\n");
                        else{
                    printf("The card must not be flipped already\n");}
                }else{
        desktop[c][d].status=1;
        printf("You chose 2nd card (%d,%2d) and it is ",c,d);
        printCard(desktop[c][d]);
        printf("\n");
        break;}}
        else{
            printf("Row and column must be within 0 - 3 and 1 - 13\n");
        }
        }
        printf("\n");

       if ((desktop[a][b].rank)==(desktop[c][d].rank))
    {
        desktop[a][b].status=1;
        desktop[c][d].status=1;
        printf("You got a matched pair!\n");
        printf("\n");
        count1++;
    }else{
    desktop[a][b].status=0;
    desktop[c][d].status=0;
    }

    showDesktop(desktop);

    while(1){
    a=rand();
    a=a%4;
    b=rand();
    b=b%13+1;

        if (desktop[a][b].status==1){
        }else{
        desktop[a][b].status=1;
        printf("Computer chose 1st card (%d,%2d) and it is ",a,b);
        printCard(desktop[a][b]);
        printf("\n");
        break;}
    }

    while(1){
    c=rand();
    c=c%4;
    d=rand();
    d=d%13+1;

        if (desktop[c][d].status==1){
        }else{
        desktop[c][d].status=1;
        printf("Computer chose 2nd card (%d,%2d) and it is ",c,d);
        printCard(desktop[c][d]);
        printf("\n");
        break;}
    }

        if ((desktop[a][b].rank)==(desktop[c][d].rank))
    {
        desktop[a][b].status=1;
        desktop[c][d].status=1;
        printf("Computer got a matched pair!\n");
        printf("\n");
        count2++;
    }
    else{
        desktop[a][b].status=0;
        desktop[c][d].status=0;
    }

    showDesktop(desktop);

    fc1=count1*2;
    fc2=count2*2;
    fct=fc1+fc2;
    printf("\n");
    printf("Flipped cards: %d; You: %d; Computer: %d;\n",fct,fc1,fc2);
    printf("\n");

    turn++;

    if(fct==52){
        printf("*** END OF GAME ***\n");
        printf("%d turns played\n",turn);
        if (fc1>fc2){
            printf("You win!\n");
        }else{
            if (fc1<fc2){
                printf("Computer wins!\n");
            }else{
            printf("A tie!\n");
            }
        }
        printf("\n");
   break;
    }
    }
    }


    //computer vs computer
    if(n==2){
    showDesktop(desktop);

    while(1){
    while(1){
    a=rand();
    a=a%4;
    b=rand();
    b=b%13+1;

        if (desktop[a][b].status==1){
        }else{
        desktop[a][b].status=1;
        printf("Computer1 chose 1st card (%d,%2d) and it is ",a,b);
        printCard(desktop[a][b]);
        printf("\n");
        break;}
    }

    while(1){
    c=rand();
    c=c%4;
    d=rand();
    d=d%13+1;

        if (desktop[c][d].status==1){
        }else{
        desktop[c][d].status=1;
        printf("Computer1 chose 2nd card (%d,%2d) and it is ",c,d);
        printCard(desktop[c][d]);
        printf("\n");
        break;}
    }

        if ((desktop[a][b].rank)==(desktop[c][d].rank))
    {
        desktop[a][b].status=1;
        desktop[c][d].status=1;
        printf("Computer1 got a matched pair!\n");
        printf("\n");
        count1++;
    }
    else{
        desktop[a][b].status=0;
        desktop[c][d].status=0;
    }

    while(1){
    a=rand();
    a=a%4;
    b=rand();
    b=b%13+1;

        if (desktop[a][b].status==1){
        }else{
        desktop[a][b].status=1;
        printf("Computer2 chose 1st card (%d,%2d) and it is ",a,b);
        printCard(desktop[a][b]);
        printf("\n");
        break;}
    }

    while(1){
    c=rand();
    c=c%4;
    d=rand();
    d=d%13+1;

        if (desktop[c][d].status==1){
        }else{
        desktop[c][d].status=1;
        printf("Computer2 chose 2nd card (%d,%2d) and it is ",c,d);
        printCard(desktop[c][d]);
        printf("\n");
        break;}
    }

        if ((desktop[a][b].rank)==(desktop[c][d].rank))
    {
        desktop[a][b].status=1;
        desktop[c][d].status=1;
        printf("Computer2 got a matched pair!\n");
        printf("\n");
        count2++;
    }
    else{
        desktop[a][b].status=0;
        desktop[c][d].status=0;
    }


    fc1=count1*2;
    fc2=count2*2;
    fct=fc1+fc2;
    printf("\n");
    printf("Flipped cards: %d; Computer1: %d; Computer2: %d;\n",fct,fc1,fc2);
    printf("\n");

    turn++;

    if(fct==52){
        showDesktop(desktop);
        printf("*** END OF GAME ***\n");
        printf("%d turns played\n",turn);
        if (fc1>fc2){
            printf("Computer1 win!\n");
        }else{
            if (fc1<fc2){
                printf("Computer2 wins!\n");
            }else{
            printf("A tie!\n");
            }
            }
            printf("\n");
            break;

    }
    }
    }
    }
    return 0;
}

