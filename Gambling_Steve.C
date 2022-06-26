//include required header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define NUMBER_OF_DOGS 9

//define the structs
typedef struct DOG
{
  char name[100];
  int amount;
  int odds;
} DOG;

//define the struct betamount
typedef struct BET_Amount
{
  int number;
  int wager;
  char betOn[100];
} BET_Amount;

//define the race
typedef struct RACE
{
  bool won;
  BET_Amount bet;
  DOG first;
  struct RACE *next;
} RACE;

//define the array
DOG dogList[NUMBER_OF_DOGS];
RACE *start = NULL;
int funds = 0;

//implement the method to swap the dogs
void
swapDogs (DOG * i, DOG * j)
{
  DOG t = *i;
  *i = *j;
  *j = t;
}

//implement the method to sort the dogs
void
sortDogs ()
{
  // sort by name field
  for (int i = 0; i < NUMBER_OF_DOGS - 1; i++)
    {
      for (int j = i + 1; j < NUMBER_OF_DOGS; j++)
	{
	  if (strcmp (dogList[i].name, dogList[j].name) > 0)
	    {
	      swapDogs (&dogList[i], &dogList[j]);
	    }
	}
    }
}

//implement the method search by name
int
searchByName (char name[])
{
  sortDogs ();
  int index = -1;
  int high = NUMBER_OF_DOGS - 1;
  int low = 0;
  while (low <= high)
    {
      int mid = (low + high) / 2;
      if (strcmp (dogList[mid].name, name) == 0)
	{
	  index = mid;
	  break;
	}
      else if (strcmp (dogList[mid].name, name) > 0)
	{
	  high = mid - 1;
	}
      else if (strcmp (dogList[mid].name, name) < 0)
	{
	  low = mid + 1;
	}
    }
  return index;
}

//implement method to shuffle the dogs
void
shuffleDogs ()
{
  // unique randomized shuffle
  srand (time (NULL));
  for (int i = 0; i < NUMBER_OF_DOGS - 1; i++)
    {
      int j = rand () % (i + 1);
      swapDogs (&dogList[i], &dogList[j]);
    }
}

//implement method to compute the winner
bool
computeWinner (BET_Amount * bet, RACE * race)
{
  DOG first = race->first;
  if (strcmp (bet->betOn, first.name) == 0)
    {
      int index = searchByName (bet->betOn);
      DOG d = dogList[index];
      int wager = d.amount * bet->wager;
      funds = funds + wager;
      printf ("\n\nBeginnners Luck! %s came 1st in the race. You won %d", bet->betOn,
	      wager);
      printf ("\nUpdated funds: %d", funds);
      return true;
    }
  else
    {
      int index = searchByName (bet->betOn);
      DOG d = dogList[index];
      int wager = d.amount * bet->wager;
      funds = funds - wager;
      printf ("\n\nTough life bud, hopefully you didn't lose to much! %s didn't win the race. You lost %d", bet->betOn,
	      wager);
      printf ("\nUpdated funds: %d", funds);
      return false;
    }
}

//implement the method for race
void
race (BET_Amount bet)
{
  shuffleDogs ();
  RACE *ndptr = (RACE *) malloc (sizeof (RACE));
  ndptr->first = dogList[0];
  ndptr->bet = bet;
  ndptr->next = NULL;
  ndptr->won = computeWinner (&bet, ndptr);
  // store outcome
  if (start == NULL)
    {
      start = ndptr;
    }
  else
    {
      RACE *ptr = start;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = ndptr;
      free (ptr);
    }
}

//implement the method to display the results
void
results ()
{
  printf ("\n\nRACE RESULTS");
  printf ("\n----------------------------------------------");
  RACE *ptr = start;
  while (ptr->next != NULL)
    {
      BET_Amount bet = ptr->bet;
      DOG dog = ptr->first;
      printf ("\nRace number %d", bet.number);
      printf ("\nRace status %s", ptr->won ? "WON" : "LOST");
      printf ("\nBet on %s", dog.name);
      printf ("\n-----------------------------------------");
      ptr = ptr->next;
    }
  BET_Amount bet = ptr->bet;
  DOG dog = ptr->first;
  printf ("\nRace number %d", bet.number);
  printf ("\nRace status %s", ptr->won ? "WON" : "LOST");
  printf ("\nBet on %s", dog.name);
  printf ("\n-------------------------------------------------");
}

//implement the method to display the dogs
void
displayDogs ()
{
  //sortDogs();
  printf ("\n\n%-20s | %-20s | %-20s", "Dog Name", "Payout",
	  "Odds of Winning");
  char payoutSuffix[] = " to 1";
  char oddsSuffix[] = " %";
  for (int i = 0; i < NUMBER_OF_DOGS; i++)
    {
      char payout[10];
      char odds[10];
      sprintf (payout, "%d", dogList[i].amount);
      strcat (payout, payoutSuffix);
      sprintf (odds, "%d", dogList[i].odds);
      strcat (odds, oddsSuffix);
      printf ("\n%-20s | ", dogList[i].name);
      printf ("%-20s | ", payout);
      printf ("%-20s", odds);
    }
}

//implement menu for banking
void
displayBankingMenu ()
{
  printf ("\n\nBANKING MENU");
  printf ("\n[W]ithdraw funds");
  printf ("\n[D]eposit funds");
  printf ("\n[E]xit bank");
  printf ("\nPlease make a selection: ");
}

//implement method for banking transactions
void
banking_transactions ()
{
  bool flag = true;
  while (flag)
    {
      displayBankingMenu ();
      char option;
      int amount;
      scanf (" %c", &option);
      switch (option)
	{
	case 'W':
	  // withdraw funds
	  printf ("\nAmount: ");
	  scanf (" %d", &amount);
	  if (amount > funds)
	    {
	      printf ("\nInsufficient funds, we are coming after your organs...Steve %d for withdrawing %d", funds,
		      amount);
	    }
	  else
	    {
	      funds = funds - amount;
	      printf ("\nUpdated funds: %d", funds);
	    }
	  break;
	case 'D':
	  // deposit funds
	  printf ("\nAmount: ");
	  scanf (" %d", &amount);
	  funds = funds + amount;
	  printf ("\nUpdated funds: %d", funds);
	  break;
	case 'E':
	  flag = false;
	  break;
	default:
	  printf ("\nUnrecognized selection %c", option);
	  break;
	}
    }
}

//implement the method gamble
void
gamble (int count)
{
  int wager = 0;
  char name[100];
  printf ("\nEnter a wager, Steve: ");
  scanf (" %d", &wager);
  printf ("\nDogs on race track: ");
  displayDogs ();
  printf ("\n\nEnter a dog's name: ");
  scanf (" %[^\n]s", &name);
  getchar ();
  int index = searchByName (name);
  if (index == -1)
    {
      goto name;

    }
  else
    {
      goto allocate;
    }
name:
  printf ("\n\n %s is not racing!", name);

allocate:
  BET_Amount * bet = (BET_Amount *) malloc (sizeof (BET_Amount));
  strcpy (bet->betOn, name);
  bet->number = count;
  bet->wager = wager;
  race (*bet);
  free (bet);
}


//implement the method to start the game
void
start_game (int amounts[], int odds[])
{
  char namesofDog[9][32] = { "Dano", "Hercules", "Hades", "Mercy", "Zeus", "Brandton", "Trent", "Gordo", "Toto"
  };
  for (int i = 0; i < NUMBER_OF_DOGS; i++)
    {
      dogList[i].amount = amounts[i];
      dogList[i].odds = odds[i];
      strcpy (dogList[i].name, namesofDog[i]);
    }
}

//Implement method to display menu
void
displayTrackMenu ()
{
  printf ("\n\nDOG TRACK MENU");
  printf ("\n[G]amble");
  printf ("\n[B]anking");
  printf ("\n[R]esults of each race that Steve wagered");
  printf ("\n[L]eave the dog track");
  printf ("\n\nPlease make a selection: ");
}

//implement the method to track the dogs
void
track_dogs ()
{
  bool flag = true;
  int count = 0;
  while (flag)
    {
      displayTrackMenu ();
      char option;
      scanf (" %c", &option);
      printf ("\n\n");
      switch (option)
	{
	case 'G':
	  gamble (++count);
	  break;
	case 'B':
	  banking_transactions ();
	  break;
	case 'R':
	  // display race outcomes
	  results ();
	  break;
	case 'L':
	  printf ("\nLeaving the dog track!");
	  flag = false;
	  break;
	default:
	  printf ("\nUnrecognized selection %c", option);
	  break;
	}
    }
}

//main method
int
main (void)
{
  //declare array for amounts
  int amounts[] = { 2, 5, 10, 15, 50, 20, 10, 5, 3 };
  //declare the odd win percentages
  int odds[] = { 40, 10, 8, 6, 1, 4, 8, 10, 13 };
  //call the method with two arrays
  start_game (amounts, odds);
  track_dogs ();
  return 0;
