// name: Drew Waller, dgw0015
// partner: Daniel Clayton, dic0001
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
#include <fstream>
#include <ctime>
using namespace std;


//Global Variables and Constants.
const int HARD_HALL_LENGTH = 100;
const int MEDIUM_HALL_LENGTH = 50;
const int EASY_HALL_LENGTH = 20;
const int MAX_HIGHSCORESLIST_SIZE = 10;
const int MAX_PUZZLES = 10;
typedef unsigned int unsInt;
bool check_number(unsInt& input); // global method that will check the for integer inputs of the users.


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Class for execution of the game, tracking player attributes, progress within the game and calling on other classes
   to perform specific features of the game. Such as Encounters, Puzzles, and iff the player wins we will call on class 
   HighScores.
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlayGame  {

private:
   string playerName;
   int money;
   int intelligence;
   int progress;
   int time;
   int score;
   bool alive;

public:
   PlayGame(); //constructor
   ~PlayGame(); //destructor
   // MEMBER FUNCTION DECLARATIONS
   void setName(string nameIn); //sets the players name;
   void setDifficulty(); //will set the hall length returns 1, 2 or 3.
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
   int hall_length;
   int level; //used to set the difficulty level
   unsInt userInput; //used in the turnSection method to get user input.
};

 //implementing the constructor
PlayGame::PlayGame()   {

   alive = true;
   progress = 0;
   setDifficulty();
   setAttributes();
}

//sets the players name.
void PlayGame:: setName(string nameIn) {
   playerName = nameIn;
}

//sets the hall length of the game.
void PlayGame:: setDifficulty()  {

   cout << "Select a difficulty level" << endl;
   cout << "1 - Easy\n2 - Medium\n3 - Hard\nEnter your selection: ";
   cin >> level;
         
   while (level != 1 || level != 2 || level != 3)  {
      cout <<"Error: Invalid input, please enter 1, 2, or 3: ";
      cin >> level;
      cout << endl;
   }
   if (level = 1) {
      hall_length = EASY_HALL_LENGTH;
   }
   else if (level == 2) {
      hall_length = MEDIUM_HALL_LENGTH;
   }
   else if (level == 3) {
      hall_length = HARD_HALL_LENGTH;
   }
   else  {
      cout << "Error: Please try again later. *** Goodbye ***" << endl;
   }
   viewCurrent_status();
}


//sets the player attributes to fixed value.
void PlayGame:: setAttributes()  {

   money = 20;
   intelligence = 30;
   time = 25;
}

//displays the 5 options to the player for at the beginning of each turn.
void PlayGame:: turnSelection() { 
 
   cout << "\t1 - Move forward one spot. (takes time, and could encounter risky challenges)" << endl;
   cout << "\t2 - Read technical papers. (takes time, but boost intelligence)" << endl; 
   cout << "\t3 - Search for loose change. (takes time, but boost money)" << endl;
   cout << "\t4 - Veiw character attributes." << endl;
   cout << "\t5 - Quit the game." << endl; 

   cout << "\n\tPlease select your next action: ";
   cin >> userInput;

   if (check_number(userInput) == false)  {
      return;
   }
   
   else if (userInput == 1)  { //calls move.
   
      move();
   }
   else if  (userInput == 2)  { //calls read tech papers.
   
      readTechnical_papers();
   }
   else if (userInput == 3)   { //calls search for change.
   
      searchFor_change();
   }
   else if (userInput == 4)   { //calls view current status.
   
      viewCurrent_status();
   }
   else  {    
      quitGame();
   }
 

}

//incrememts progress since it is private.
void PlayGame:: plusProg() {
   progress++;
}
   
//Player selects to move and moves step down the hall
void PlayGame:: move()  {
   plusProg();

// then create Encounter object class, generate random number for encounters list.
   
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

   cout << "Your current attributes are:\n" << endl;
   cout << "intelligence: " << intelligence << endl;
   cout << "time: " << time << '\n' << "money: $" << money << ".00" << endl; 
   cout << "\nYou are" << (hall_length - progress) << "away from the end of the hall.\n" << endl; 

   turnSelection();
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

//destructor
PlayGame::~PlayGame()   {
}

   
/////////////////////////////////////////////////////
// class that handles the encounters each player has.
/////////////////////////////////////////////////////

class Encounters  {

   private:
   int eCounterRoll;
   
   public:
   void seeProfessor();       // still need to complete this skeleton... missing functions.
   void anotherGrad();
   void gruntWork();
   void gradePapers();
   int getRandomNum();
   

   
   
}; 

//Implementing the constructor
void Encounters:: seeProfessor() {
   
};  
   
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /* Class for the High Scores List. The list will old at most the top 10 scores from high to low. These will be 
      read in from a file with default scores. When a player score is higher than the lowest score it will replace 
      the lowest score. Then, the list is sorted again so that the new score is in its proper place in the list.
   *////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
class HighScoresList {
   
   private:
   int highScoresList[MAX_HIGHSCORESLIST_SIZE];
   
   public:
   void sortHigh_scores();      //still need to complete this skeleton.
   void printScoreList();
   
   };
   
////////////////////////////////////////////////////////////////////////////////////////////////////
// Class for executing puzzles for the player to complete in the game. Will effect player attributes.
///////////////////////////////////////////////////////////////////////////////////////////////////

class Puzzle  {

private:
   struct PuzzleNode {
       string question;
       string answer;
       int points;
       PuzzleNode *next;
   };
   typedef PuzzleNode* node_ptr_t; //Head of the puzzle list

public:
   void initialize_puzzles(node_ptr_t& root, node_ptr_t& current, int& questionCount); //Sets an initial list of puzzles
   PuzzleNode get_puzzle(); //returns a puzzle for use in PlayGame
   
};

///////////////////////////////////////////////////////////////////////////////////////////
// Class for implementing test cases. provides better readability to the program as a whole
///////////////////////////////////////////////////////////////////////////////////////////

class Testing  {

private:


public:


};

//////////////////////////////
// main - DRIVER OF EXECUTION
/////////////////////////////

int main()  {

   string playerNameIn;
   unsInt optionIn;
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
         i = 0; // max attempts will be 5. Notice if statement == 5 we exit system.
         
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
      cout << "/nWe are now entering the Game..." << endl; 
      PlayGame play;
      play.setName(playerNameIn);
   }
   else if (optionIn == 2)   {
   
   //Create new HighScore object and use the methods from its class.
   }
   else if (optionIn == 3)   {
   
      cout << "Thank you for playing!! \n\t\t\t *** Goodbye ***" << endl;
   
      return 0;
   }  

     
   return 0;
}

// checks for and integer input.
bool check_number(unsInt& input)  {
   int counter = 0;

   while (!(cin >> input))  {
      
      if (cin.eof())   {
         cout << "Please try again later. ***Goodbye*** " << endl;
         return false;
      }
      else {
         cin.clear(); 
         cin.ignore(1000, '\n'); 
      
         cout <<"Error: Invalid input, please enter 1, 2, or 3: ";
         cin >> input;
         counter++;
         cout << endl;
      }
   }
      
   return true;
}
