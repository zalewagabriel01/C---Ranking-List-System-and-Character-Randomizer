#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int RandomNumber() //return random index for array
{
    int k = rand() % 82;
	return k;
}
		
int main () 
{
    int i,n,g;
	int Player1_counter=0,Player2_counter=0; //wins counter
	char *tmp;
	char input;

	char *stage;
	bool stage_change = true;

    time_t t;
    srand((unsigned) time(&t)); //generate random numbers at every start

	char *characters []={"Mario","Luigi","Peach","Bowser","Yoshi","Rosaluma","Bowser Jr.","Wario","G&W","DK","Diddy", //set all characters for player 1
	                     "Little Mac","Link","Zelda","Sheik","Ganonek","Tink","Samus","ZSS","Pit","Palutena","Marth",
	                     "Ike","Robin","Duck Hunt","Kirby","Meta- Knight","DEDEDE","Fox","Falco","Pikachu","Lucario",
	                     "Pokemon Trainer","Jiggly","Greninja","R.O.B","Ness","Falcon","Villager","Olimar","Wii Fit","Shulk",
	                     "Dr. Mario","Dark Pit","Lucina","Mega Man","Pac- Man","Sonic","Mewtwo","Lucas","Roy","Ryu",
	                     "Cloud","Corrin","Bayonetta","Inkling","Ridley","Simon","Chrom","Snake",
	                     "K Rool","Ken","Incineroar","Mii Brawler","Mii Sowrdfighter","Mii Gunner","Ice Climbers","Pichu",
	                      "Young Link","Wolf","Isabelle","Plant","Joker","Hero","Banjo","Terry","Byleth","Min Min","Steve","Sephiroth","Pyra&Mythra","Kazuya"};

	char *characters2[82]; //copy all characters into player 2
	for (i=0;i<82;i++)
	{
		characters2[i] = characters[i];
	}

	char *stages []={"Battlefield","FD","Tnc","SV","PS2","NC","SBF"}; //define stages

    printf("Player 1");
    printf("%12. Player 2");
	printf("%12. Stage\n");

for(i=0;i<82;i++) //shuffle all characters for player 1
{
      n= RandomNumber();
      tmp=characters[i];
      characters[i]=characters[n];
      characters[n]=tmp;
}
	
for(i=0;i<82;i++) //shuffle all characters for player 2
{
      g= RandomNumber();
      tmp=characters2[i];
      characters2[i]=characters2[g];
      characters2[g]=tmp;
}
for(i=0;i<82;i++) //output every round
{
    printf("%d: %s\n",i+1,characters[i]);
    printf("%21.d: %s\n",i+1,characters2[i]);

    if(stage_change) //if new round -> generate new stage
    {
        stage = stages[rand() % 7];
	}
	printf("%40d: %s\n\n",i+1,stage);


	printf("Who won? Press 1 for Player1, Press 2 for Player2: ");
	scanf("%c",&input);
	fflush(stdin);
	printf("Press again for sure:");
    scanf("%c",&input);
				
    if(input=='1') //if player 1 won, give them a point
    {
	    Player1_counter++;
		stage_change = true;
    }

    else if(input=='2') //if player 2 won, give them a point
    {
	    Player2_counter++;
		stage_change = true;
    }

    else //in case of wrong input, ask about the round again
    {
	    printf("Either press 1 or 2\n");
        i--;
		stage_change = false; //keep the same stage
    } 

			
	printf("Next Character -> press ENTER\n");
    while( getchar() != '\n' );
    while( getchar() != '\n' );
		
}

printf("Player 1 won %d Match(es)\n\nPlayer 2 won %d Match(es)\n\n",Player1_counter,Player2_counter);

	if(Player1_counter<Player2_counter) //check who won
		printf("Player 2 is the winner!\n");
	else if(Player1_counter>Player2_counter)
		printf("Player 1 is the winner!\n");
	else
		printf("Double KO\n");
       
   return 0;
}
