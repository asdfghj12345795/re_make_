#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDSET			20 //Increase the card set to avoid duplication
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

int dollar[N_MAX_USER]; //set the array of dollor by number of user 
int n_user;

int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD]; //setting that the user has 
int cardSum[N_MAX_USER]; //number of cards
int bet[N_MAX_USER]; //players do betting
int gameEnd=0; // flag of end
int PLAY_NUMBER;//fix the play number 
int N_ROUND=1; //represent the count of round
int Card_set[N_CARD] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52}; //total card is 52
int Dollar[N_MAX_USER];
int Round_B_price[N_MAX_GO][N_MAX_USER]; //The betting amount variable of the player in the field.
int Player_Card[N_MAX_GO][N_MAX_USER]; // [i][j] : ith card of j player
int Dealer_card[N_MAX_GO]; //[j] : jth card of dealer
int cardcnt=0;

int *card[N_CARDSET*N_CARD];

//card tray object
int mixCardTray()
{
  int CardTray[N_CARDSET*N_CARD];

}

	
					

//player info
int dollar[N_MAX_USER]={50,50,50,50,50};	//dollars that each player has



//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
							//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


//card processing functions ---------------

//calculate the actual card number in the blackjack game



int Matching_the_card_number(int number_array) // decide the number (1~K,Q,J) of cards
{
	int Card_set[number_array];
	int check; // Variable being able to through the division.
	int confirm =13; /// Number of confirmation.
	int number; // variable of the card number
	
	check = number_array%13;
	
	switch(check){
		
		case 0:
			number=1;
			printf("%d", number);
			break;
		
		case 1:
			number=2;
			printf("%d", number);
			break;
		
		case 2:
			number=3;
			printf("%d", number);
			break;
		
		case 3:
			number=4;
			printf("%d", number);
			break;
		
		case 4:
			number=5;
			printf("%d", number);
			break;

		case 5:
			number=6;
			printf("%d", number);
			break;

		case 6:
			number=7;
			printf("%d", number);
			break;

		case 7:
			number=8;
			printf("%d", number);
			break;

		case 8:
			number=9;
			printf("%d", number);
			break;

		case 9:
			number=10;
			printf("%d", number);
			break;
	
		case 10:
			number=10;
			printf("JACK(11)");
			break;

		case 11:
			number=10;
			printf("QUEEN(12)");
			break;

		case 12:
			number=10;
			printf("KING(13)");
			break;
			
	}

return (number);

}
	

int Matching_the_card_shape(int number_array)//decide the shape of card like ¢¾¢À¢¼¡ß.
{
	int Card_set[number_array];
	int check; // Variable being able to through the division.
	int confirm =13; /// Number of confirmation.
	char shape; // express the shape
	char HEA, SPA, CLV, DIA;
	
	check = number_array/confirm;
	
	switch(check)
	{
		case 0:
			shape = HEA; 
			break;
		
		case 1:
			shape = SPA;
			break;
		
		case 2:
			shape = CLV;
			break;
			 
		case 3:
			shape = DIA;	 		
			break;	
	}
	
	return (shape);		
}

//card array controllers -------------------------------

extern int cardcnt;

//get one card from the tray
int Card_Offer_player(int cardcnt, int Nofplayer)//Give the card each player.
{
		int Player_Card[cardcnt+1][Nofplayer];
		
		srand((unsigned)time(NULL));
		Player_Card[cardcnt+1][Nofplayer] = rand()%52;
	
		cardcnt++;	
		return (Player_Card[cardcnt+1][Nofplayer]);//There are 17 cardsets and 17 n_max_go, so there is no need to ask for redundancy.

}


//playing game functions -----------------------------

//player settiing
extern int PLAY_NUMBER;

int PLAY_NUM(void) // input the sum of players
{	
	
	do{
		printf("Input the number of players (MAX :5) :");
		scanf("%d", &PLAY_NUMBER);
		
		if(PLAY_NUMBER<1)
		{
			printf("too small\n");
		}
		
		else if(PLAY_NUMBER>5)
		{
			printf("too many player\n");
		}

}while(PLAY_NUMBER<0||PLAY_NUMBER>5);

printf("\n");
printf("---> card is mixed and put into the tray\n");
printf("\n");
return 0;
}

//betting

extern int Dollar[N_MAX_USER]; //express that is external.
extern PLAY_NUMBER; //express that is external.
extern int Round_B_price[N_MAX_GO][N_MAX_USER]; // express that is external.

 
int RANDOM_B_PLAYER() // Ramdom betting system for other players
{
	int i;
	int B_max[N_MAX_USER];
	
	B_max[N_MAX_USER] = Dollar[N_MAX_USER]; //Make as much as the number of player the array for money.
	
	for(i=1;i<PLAY_NUMBER;i++) //the user is the player : array number [0].
	{
		B_max[i]=Dollar[i];
		srand((unsigned)time(NULL));
		Round_B_price[1][i] = 1+rand()%B_max[i]; //Set random betting amount for i-th player in 1st round.
	}
	
	return (Round_B_price[1][i]);
	
}

int BETTING_SET() //Betting for play
{
	int bet_user; // betting price for user
	int i;
	
	printf("\n");
	printf("-----betting step-----\n");
	printf("\n");
	do{
		printf("   -> your betting (total : %d) : ", Dollar[0]);
		scanf("%d", &bet_user);
		
		if(bet_user>Dollar[0])
		{
			printf("Too much!\n");
			}
		
		else if(bet_user<0)
			{
			printf("Too small!\n");			
		}
	}while(bet_user<0 || bet_user>Dollar[0]);
	
	for(i=1;i<PLAY_NUMBER;i++) //the user is the player : array number [0].
	{
		bet[i]= RANDOM_B_PLAYER();
		printf("   -> player %d bets $%d (out of $%d)\n", i, bet[i], Dollar[i]);
	}
	
	printf("---------------------\n");	 
}

extern int cardcnt;

//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<PLAY_NUMBER;i++)
	{
		cardhold[i][0] = Card_Offer_player(cardcnt, i);
		cardhold[i][1] = Card_Offer_player(cardcnt, i);
	}
	//2. give two card for the dealer
	cardhold[PLAY_NUMBER][0] = Card_Offer_player(cardcnt, PLAY_NUMBER); //the number of dealer array is Play_number.
	cardhold[PLAY_NUMBER][1] = Card_Offer_player(cardcnt, PLAY_NUMBER);
	

	
}

extern int cardcnt;

int getAction(int N_USER ,int N_GO) //Obtain the number of PLAYERs in the array and the number of cards as parameters 
 {
	int answer; // variable ro present to say the stay or go 
	printf("\n");
	
	printf("----------my turn !--------------");
	
	
	printf("::: Action ? (0 - go, others - stay) : ");
	scanf("%d", &answer);
	
	if(answer==0) // Give one more card to situations in which you want to get one more card.
	{
		cardhold[N_USER][N_GO] = Card_Offer_player(cardcnt,N_USER);
		printf("\n");
	}
	
	else
	{
		printUserCardStatus(N_USER, N_GO);
	}
	
	return 0;
	 
}

int printCard(int PLAY_NUMBER, int cardcnt) // Show all the cards player have.
{
	int i;
	for(i=0;i<cardcnt;i++)
	{	
		offercards();
		Card_Offer_player(cardcnt,i);
		Matching_the_card_number(cardhold[PLAY_NUMBER-1][i]); //Make sure player hand out the cards and match each shape and number.
		Matching_the_card_shape(cardhold[PLAY_NUMBER-1][i]);	
	}
	return (Matching_the_card_number(cardhold[PLAY_NUMBER-1][i]),Matching_the_card_shape(cardhold[PLAY_NUMBER-1][i]));
}

int printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("----------CARD OFFERING-----------");
	printf("\n");
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		{
		printCard(user,cardcnt);
	printf("\n ::: %c%d ",Matching_the_card_number(cardhold[user][i]),Matching_the_card_shape(cardhold[user][i]));
	printf("------------------------------------");
	printf("\n");
	}
}

//print initial card status
void printCardInitialStatus(int N_USER, int cardcnt) {
	
	printUserCardStatus(N_USER, cardcnt-1);

} // In order to print out the status of the initial card distribution, you must print out the situation before you receive one card.

extern int cardcnt;

// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult(int cardhold[PLAY_NUMBER][cardcnt]) 
{
	int sum_player =0;
	int sum_dealer =0;
	int i;
	int j;
	
	for(i=0;i<=cardcnt;i++)
	{
	sum_player += Matching_the_card_number(cardhold[PLAY_NUMBER-1][i]);
	}
	
	for(j=0;j<=cardcnt;j++)
	{
		sum_dealer +=Matching_the_card_number(cardhold[PLAY_NUMBER][j]);
	}
	
	if(sum_player<21) //The sum of all cards is less than 21.
	{
		printf("sum : %d", sum_player);
		getAction(0,cardcnt);
	}
	
	else if(sum_player>21) //In case of overflow and defeat, because the sum of all cards is greater than 21.
	{
		printf("%d / OVERFLOW >>> LOSE!\n", sum_player);
	}
	
	else if(sum_player<sum_dealer) // a situation in which the sum of all cards is lost for reasons smaller than the sum of the cards in the dealer.
	{
		printf("%d / DEAD", sum_player);
	}
	
	else if (sum_player==21) //a situation in which the sum of all cards is 21.
		{
		if(cardcnt==2)
		{
			printf("BLACKJACK!\n"); // a situation in which a blackjack (when two cards were received and 21 were received)		
		}
	
		else
		{
			printf("winner\n"); //a situation in which three or more cards are received and all numbers are won by 21.
	
		}
}

		return 0;
}

extern int cardcnt;

//End turn and output final result of user.
int checkResult(void)
{
	printUserCardStatus(0, cardcnt); //Use a function that represents the shape and number of cards you have currently
	calcStepResult(cardhold[0][cardcnt]); //Use a function to get the sum of the numbers you have

}



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int cardcnt =0;
	int i;
	
	
	//Game initialization --------
	//1. players' dollar
	int dollar[N_MAX_USER]={50,50,50,50,50};
	//2. card tray
	mixCardTray();
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	PLAY_NUM();
	printf("\n");

	//Game start --------
	do {
		printf("\n------------------ GAME start --------------------------\n");
		
		betDollar();
		offerCards(); //1. give cards to all the players
		printCardInitialStatus(0,cardcnt);
		
		extern int cardcnt;
		
		for (i=1;i<PLAY_NUMBER;i++) //each player
		{
		
		printf("\n");
		
		//each player's turn
		
			while (getAction(0,cardcnt)) //do until the player dies or player says stop
			{
				printUserCardStatus(i,cardcnt) ; //print current card status printUserCardStatus();
				printf("\n");
				calcStepResult(cardhold[i][cardcnt]); //check the card status ::: calcStepResult() ~ check if the turn ends or not
				printf("\n");
				getAction(0,cardcnt);//GO? STOP? ::: getAction()
				printf("\n");
				cardcnt++;
			}
		}
		
		checkResult();
	} while (gameEnd == 0);
	
	return 0;
}
