#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			17 // set the cardset to not consider the same situation.
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
int cardhold[N_MAE_USER][N_MAX_GO];

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER]={50,50,50,50,50};	//dollars that each player has



//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag

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
	
	switch(chack){
		
		case 0:
			number=1;
			break;
		
		case 1:
			number=2;
			break;
		
		case 2:
			number=3;
			break;
		
		case 3:
			number=4;
			break;
		
		case 4:
			number=5;
			break;

		case 5:
			number=6;
			break;

		case 6:
			number=7;
			break;

		case 7:
			number=8;
			break;

		case 8:
			number=9;
			break;

		case 9:
			number=10;
			break;
	
		case 10:
			number=11;
			printf("KING");
			break;

		case 11:
			number=12;
			printf("QUEEN");
			break;

		case 12:
			number=13;
			printf("JACK");
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

//get one card from the tray
int Card_Offer_player(int n, int Nofplayer)//Give the card each player.
{
		int Player_Card[n+1][Nofplayer];
		
		srand((unsigned)time(NULL));
		Player_Card[n+1][Nofplayer] = rand()%52;
	
			
		return (Player_Card[n+1][Nofplayer]);//There are 17 cardsets and 17 n_max_go, so there is no need to ask for redundancy.

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


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	for (i=0;i<PLAY_NUMBER;i++)
	{
		cardhold[i][0] = Card_Offer_player();
		cardhold[i][1] = Card_Offer_player();
	}
	//2. give two card for the operator
	cardhold[PLAY_NUMBER][0] = Card_Offer_player();
	cardhold[PLAY_NUMBER][1] = Card_Offer_player();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	
	
}

int getAction(int N_USER ,int N_GO) //Obtain the number of PLAYERs in the array and the number of cards as parameters 
 {
	int answer; // variable ro present to say the stay or go 
	
	printf("::: Action ? (0 - go, others - stay) : ");
	scanf("%d", &answer);
	
	if(answer==0) // Give one more card to situations in which you want to get one more card.
	{
		cardhold[N_USER][N_GO] = Card_Offer_player();
	}
	
	else
	{
		printUserCardStatus(N_USER, N_GO);
	}
	
	return 0; 
	
}

void printCard(int PLAY_NUMBER, int cardcnt) // Show all the cards player have.
{
	int i;
	for(i=0;i<cardcnt;i++)
	{	
		offercards();
		offercard();
		Matching_the_card_number(cardhold[PLAY_NUMBER-1][i]); //Make sure player hand out the cards and match each shape and number.
		Matching_the_card_shape(cardhold[PLAY_NUMBER-1][i]);	
	}
	return (Matching_the_card_number(cardhold[PLAY_NUMBER-1][i])Matching_the_card_shape(cardhold[PLAY_NUMBER-1][i]));
}

void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		{
		printCard(user,cardcnt);
	printf("\n ::: %c%d ",Matching_the_card_number(cardhold[PLAY_NUMBER-1][i]),Matching_the_card_shape(cardhold[PLAY_NUMBER-1][i]));
}
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
}

int checkResult() {
	
}

int checkWinner() {
	
}



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	PLAY_NUM();

	
	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for () //each player
		{
			while () //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
				//GO? STOP? ::: getAction()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
