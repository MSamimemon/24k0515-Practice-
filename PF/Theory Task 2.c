#include <stdio.h>
#include <string.h>

typedef struct Player
{
    int ballScores[12];
    char PlayerName[30];
    int totalscore;
};
int validatescore(int score)
{
    if (score >= 0 && score <= 6)
    {
        return score;
    }
    else{
    	return 0;
	}
}

struct Player playGame(struct Player player)
{
    for (int i = 0; i < 12; i++)
    {
        printf("Enter the score for ball %d\n", i + 1);
        int score;
        scanf("%d", &score);
        if (validatescore(score))
        {
            player.ballScores[i] = score;
            player.totalscore += score;
        }
        else{
        	printf("Invalid score! Ball marked but no runs added.\n");
            player.ballScores[i] = 0;

		}
        
    }
    return player;
}
void findwinner(struct Player player1, struct Player player2){
    printf("\nResult:\n");
    if (player1.totalscore>player2.totalscore)
    {
        printf("Winner is %s by scoring %d runs\n", player1.PlayerName,player1.totalscore);
    }
    if (player1.totalscore<player2.totalscore)
    {
        printf("Winner is %s by scoring %d runs\n", player2.PlayerName,player2.totalscore);
    }
    else{
        printf("It's a tie! Both Players have scored same runs\n ");
    }
}
void displayMatchScoreboard(struct Player player1, struct Player player2){
    printf("Match ScoreBoard\n");
    printf("\n Scores of %s are: \n", player1.PlayerName);
    for (int i = 0; i < 12; i++)
    {
        printf("Ball %d: %d\n", i+1,player1.ballScores[i]);
    }
    printf("Total Scores: %d\n", player1.totalscore);
    printf("Average Score: %.2f\n", player1.totalscore/12.0);
   
    printf("\n Scores of %s are: \n", player2.PlayerName);
    for (int i = 0; i < 12; i++)
    {
        printf("Ball %d: %d\n", i+1,player2.ballScores[i]);
    }
    printf("Total Scores: %d\n", player2.totalscore);
    printf("Average Score: %.2f\n", player2.totalscore/12.0);
    
}
int main()
{
    struct Player player1, player2;
    player1.totalscore=0;
    player2.totalscore=0;

    printf("WELCOME TO CRICKET SHOWDOWN\n");
    printf("--------------------------------------\n");
    printf("Enter the Name of Player1: ");
    fgets(player1.PlayerName,50,stdin);
    player1.PlayerName[strcspn(player1.PlayerName,"\n")]=='\0';
    printf("Enter the Name of Player2: ");
    fgets(player2.PlayerName,50,stdin);
    player2.PlayerName[strcspn(player2.PlayerName,"\n")]=='\0';
    
    printf(" %s's turn:\n", player1.PlayerName);
    player1= playGame(player1);
    printf(" %s's turn:\n", player2.PlayerName);
    player2= playGame(player2);

    displayMatchScoreboard(player1,player2);

    findwinner(player1,player2);

    return 0;
 
    
}