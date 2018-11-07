// name: Drew Waller, dgw0015
// partner: Daniel Clayton, 
// group name: _proj01 5
// filename: hw3.cpp
// due date:09/14/2018
//collaboration: I did not use any external sources for this assignment.
/* problem: Project 1 programming part: We must create a program, that is a text based game called Dragons. The goal is for the
   player to make it to the end of the hall in the Shelby Center. The player is composed of three main attributes, money, time, and intelligence.
   If the player is to run out of any of the three attributes they die. Along the hall there will be many obsticle the player must overcome. 
   These may have a positive or negative impact on the player depending on the nature of the encounter. If the player reaches the end of the 
   end of the hall they win and there score is recoreded on a high scores list. */
   
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

//Global Variables and Constants.
const int HARD_HALL_LENGTH = 100;
const int MEDIUM_HALL_LENGTH = 50;
const int EASY_HALL_LENGTH = 20;
const int MAX_HIGHSCORESLIST_SIZE = 10;
typedef unsigned int unsInt;
bool check_number(unsInt& input); // global method that will check the for integer inputs of the users.



class PlayGame  {

private:
   string playerName;
   int money;
   int intelligence;
   int progress;
   int time;
   int score;
   int hall_length;
   bool alive;

public:
   // CONSTRUCTOR
   PlayGame(string playerNameIn, unsInt levelIn); // will set the players name through the paramenter and set progress = 0, and hall length.
   ~PlayGame(); // class default destructor
   // END CONSTRUCTORS

   // MEMBER FUNCTION DECLARATIONS
   void setAttributes(); // will set all three attributes to a fixed value.
   void turnSelection(); // will display the 5 opetion the palyer player has each turn.
   void move();
   void readTechnical_papers(); //  + intelligence(random amount), - time(fixed).
   void searchFor_change(); // + money(random amount), - time(fixed).
   void viewCurrent_status(); // prints the player attributes and current position in hall when called.
   void quitGame();
   void checkScore(); // checks to see if any attribute = 0 after each turn.
   int reportScore(); // if player wins, their score is calculated here and reported to high scores list. 
   void plusProg(); // just progress++ accessor method.
};

//class that handles the encounters each player has.
class Encounters  {

   private:
   int eCounterRoll;
   
   public:
   int getRandomNum();
   void doPuzzle();
   void seeProfessor();       // still need to complete this skeleton... missing functions.
   void anotherGrad();
   void grutWork();
   void gradePapers();
   
   
   };
   
   //Class for the High Scores List.
class HighScoresList {
   
   private:
   int highScoresList[MAX_HIGHSCORESLIST_SIZE];
   
   public:
   sortHigh_scores();      //still need to complete this skeleton.
   printScoreList();
   
   };



int main()  {

   string playerNameIn;
   unsInt optionIn;
   unsInt levelIn;
   bool result;
   int i;

   cout << "\nHi, what's your name? ";
   cin >> playerNameIn;
   cout << "\n";

   cout << "--------------------------------------------------" << endl;
   cout << setw(25); cout << "Welcome " << playerNameIn << "!" << endl;
   cout << "--------------------------------------------------\n" << endl;
   
   cout << "1 - Start a New Game of Shelby Center Hall and Dragons!!" << endl;
   cout << "2 - See the top 10 High Scores!" << endl;
   cout << "3 - Quit and exit.\n" << endl;
   cout << "\tPlease select and option from above(1-3): ";
   cin >> optionIn;
   result = check_number(optionIn);
   
   if (result == false) {
   
      while (result == false) {
         int i = 0; // max attempts will be 5. Notice if statement == 5 we exit system.
         
         if (i == 5)   {
            cout << "Please try again at another time. \n *** Goodbye ***" << endl;
         
            return 1;
         }
         
         cout << "\nError: Please enter a integer value: ";
         cin >> optionIn;
         cout << "\n";
         i++;
         result = check_number(optionIn);
      }
      
   }
   cout << endl;
   
   if (optionIn == 1)  {
      cout << "Before we begin, select a difficulty level" << endl;
      cout << "1 - Easy\n2 - Medium\n3 - Hard\nEnter your selection: ";
      cin >> levelIn;
      result = check_number(levelIn);
      
      if (result == false) {
      
         while (result == false) {
            int i = 0; // max attempts will be 5. Notice if statement == 5 we exit system.
         
            if (i == 5)   {
               cout << "Please try again at another time. \n *** Goodbye ***" << endl;
            
               return 1;
            }
         
            cout << "\nError: Please enter a integer value: ";
            cin >> optionIn;
            cout << "\n";
            i++;
            result = check_number(optionIn);
         }
      }
   
      cout << "We are now entering the Game..." << endl;
   
   
   //here we will create a new game and pass the playerName and level.
   //by passing the level we can then use the constants to set the hall length.
   //we still need to come up with starting values for the attributes.  
   
   }

   if (optionIn == 2)   {
   
   //Create new HighScore object and use the methods from its class.
   }
   
   // exit option
   if (optionIn == 3)   {
   
      cout << "Thank you for playing!! \n\t\t\t *** Goodbye ***" << endl;
   
      return 0;
   }  

   return 0;
}


//FUNCTION DEFINITIONS

//implementing the constructor
PlayGame::PlayGame(string playerNameIn, unsInt levelIn)   {

   alive = true;
   playerName = playerNameIn;
   progress = 0;
   
   if (levelIn == 1) {
      hall_length = EASY_HALL_LENGTH;
   }
   else if (levelIn == 2)  {
      hall_length = MEDIUM_HALL_LENGTH;
   }
   else if (levelIn == 3)  {
      hall_length = HARD_HALL_LENGTH;
   }
   else  {
      levelIn = 1; // will set to the easiest setting if a value other then 1-3 is passed through. 
   }
   
   setAttributes();
}

//sets the player attributes to fixed value.
void PlayGame:: setAttributes()  {

   money = 20;
   intelligence = 30;
   time = 25;
}

//displays the 5 options to the player for at the beginning of each turn.
void PlayGame:: turnSelection() {

//will simply print of the options and use if = 1, if = 2... ect then call the 
//appropriate function below. (move(), readTec_papers.....ya know)
}

//incrememts progress.
void PlayGame:: plusProg() {
   progress++;
}
   
//Player selects to move and moves step down the hall
void PlayGame:: move()  {
   plusProg();

// then create encounter object, generate random number for encounters list.

}

/* player selects the read papers option and gains a random amt of intelligence and looses
   and fixed amt of time */
void PlayGame:: readTechnical_papers() {




}

/* Player selects the search for loose chance option and gains a random amt of money and
   looses a fixed amt of time */
void PlayGame:: searchFor_change()  {
   
   
   
}

// Player selects the view character option and the progress and player attributes are displayed.
void PlayGame:: viewCurrent_status()   {

//here will be a basic cout of the each attribute and the players current progress

}

// Player selects to quit the game.
void PlayGame:: quitGame() {

   return; // ends execution.
}

/* This method is called after each encounter to make sure no attribute is 0. If one does = 0. bool alive = false
   and the program displays " You Lose ".*/
void PlayGame:: checkScore()  {
   
   
   
}
   
   // reports the score to high scores list iff the player wins
int PlayGame:: reportScore()  {
   
   score = money * intelligence * time;
   
   return score;
}

// checks for and integer input.
bool check_number(unsInt& input)  {

   if (!cin >> input)   {
      
      cin.clear(); 
      cin.ignore(1000, '\n'); 
      return false;
   }
   else  {
      
      return true;
   }
}


