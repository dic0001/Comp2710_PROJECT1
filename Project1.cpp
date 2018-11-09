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
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
#include <ctime>
using namespace std;


//Global Variables and Constants.
const int HARD_HALL_LENGTH = 30;
const int MEDIUM_HALL_LENGTH = 25;
const int EASY_HALL_LENGTH = 20;
const int MAX_LIST_SIZE = 5;
bool check_number(int& input); // global method that will check the for integer inputs of the users.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Class for the High Scores List. The list will old at most the top 10 scores from high to low. These will be 
   read in from a file with default scores. When a player score is higher than the lowest score it will replace 
   the lowest score. Then, the list is sorted again so that the new score is in its proper place in the list.
*///////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
class HighScoresList {
   
   private:
   string playerName;
   string nameArray[MAX_LIST_SIZE];
   int scores[MAX_LIST_SIZE];
   //used to read and output files.
   bool readFile(const string& file);
   ifstream inStream;
   ofstream outStream;
   
   public:
   void askUserName(string& playerName); // gets the user name from main.
   string getPlayerName(); // just return the current players name.
   void createHighScoreList(); // creates a false list with default values.
   int calcScore(int& money, int& intelligence, int& time); //calculates the players final score.
   void newHighScore(int scoreIn); // adds a new high score to the list iff score > lowest high score.
   void sortScore_list(int scoreIn);
   void sortHigh_scores();      //still need to complete this skeleton.
   void printScoreList();
   void writeList();
   int finalScore;
   
   };
   
// return the players final score. scores should always be positive
int HighScoresList:: calcScore(int& money, int& intelligence, int& time)   {

   finalScore = money * intelligence * time;

   return finalScore;
} 

void HighScoresList:: askUserName(string& playerName)  {
      
   cout << "\nHi, what's your name? ";
   cin >> playerName;
   cout << "\n";
   cout << "--------------------------------------------------" << endl;
   cout << setw(25); cout << "Welcome " << playerName << "!" << endl;
   cout << "--------------------------------------------------\n" << endl;  

}

//return the players name from the high scores list memory.
string HighScoresList:: getPlayerName()  {

   return playerName;
}

// creates the default list. List only stores the top 5 scores
void HighScoresList:: createHighScoreList()  {

   string name1 = "\nDave";
   string name2 = "\nBuddy";  // you can change this and initialize the list
   string name3 = "\nMark";   // however you want to. 
   string name4 = "\nDrew";
   string name5 = "\nClint";
   
   

}

// adds new high score to the list iff the score in is > lowest high score currentl in list.
void HighScoresList:: newHighScore(int scoreIn) {

   int score;
// writes the new score to the list
   ofstream fileOut("highScoreList.txt");
   fileOut.open("highScoresList.txt");
   fileOut << score << " " << endl;
   fileOut.close();

//file in method if you want to use it.
   ifstream fileIn("highScoreLists.txt");
   if (fileIn.is_open()) {
      int score;
      fileIn >> score;
      cout << "Score: " << score;
      fileIn.close();
   }


}

//can us this method to add/sort the new score iff its greater than the lowest high score.
void HighScoresList:: sortScore_list(int newScoreIn)  {



}

/////////////////////////////////////////////////////
// class that handles the encounters each player has.
/////////////////////////////////////////////////////

class Encounters  {

   public:
   void seeProfessor(int& intelligence, int& time);
   void anotherGrad(int& time);
   void gruntWork(int& intelligence, int& time);
   void gradePapers(int& money, int& time);
   void endGame(); //used to exit the game from the Encouters class.
   int money;
   int intelligence;
   int time;
   
   };
   
//Player encounters a professor. - random amt of time, + intelligence.
void Encounters:: seeProfessor(int& intelligence, int& time)   {

   cout << "\nYou have encountered a professor.\nThis will cost you a random amount of time between 0 - 4. But may increase your intelligence." << endl;

   int timeLost = (rand() % 5);
   int intelGained = (rand() % 3);
   intelligence = intelligence + intelGained;
   time = time - timeLost;

   if (time <= 0) {
      cout << "\nYour time as run out and you have died in the Shelby Center hall from old age." << endl;
      endGame();
   }
      
   if (intelligence >= 25) {
      intelligence == 25;
   }
   
   cout << "\nYou gained " << intelGained << " intelligence but lost " << timeLost << "." << endl;
   cout << "\nPress any key to continue...";
   cin.ignore().get(); 

}

//Player encounters another graduate student. - random amt of time.
void Encounters:: anotherGrad(int&time)   {

   cout << "You have encountered another graduate student." << endl;
   cout << "This will cost you a random amount of time." << endl;
   int timeLost = (rand() % 5);
   time = time - timeLost;

   if (time <= 0) {
      cout << "\nYour time as run out and you have died in the Shelby Center hall from old age." << endl;
      endGame();
   }

   cout << "\nYou lost " << timeLost << " minutes of time." << endl;
   cout << "\nPress any key to continue...";
   cin.ignore().get();

}

//Player is attacked by grunt work. - both time and intelligence.
void Encounters:: gruntWork(int& intelligence, int& time)   {

   cout << "\nYou have encountered grunt work!!! This sucks!" << endl;
   cout << "\nThis will cost you time and intelligence." << endl;

   time = time - 8; //8 will just be a fixed amount.
   intelligence = intelligence - 8;

   if(time <= 0)  {
      cout << "\nYour time as run out and you have died in the Shelby Center hall from old age." << endl;
      endGame();
   }
   if (intelligence <= 0)  {
      cout << "\nYour intelligence has run out and you can no longer pass the class in the Shelby Center." << endl;
      cout << "\nYour Auburn college career died..maybe try another school." << endl;
   }

   cout << "\nYou lost 8 point from both intelligence and time." << endl;
   cout << "\nPress any key to continue...";
   cin.ignore().get();
}

//Player has to stop and grade papers.
void Encounters:: gradePapers(int& money, int& time)  {

   cout << "\nYour player has to stop and grade papers. You will gain money but pay with time." << endl;

   money = money + 5; // 5 and three are fixed loses.
   time = time - 3;

   if (time <= 0) {
      cout << "Your time as run out and you have died in the Shelby Center hall from old age." << endl;
      endGame();
   }
   if (money >= 25)  {
      money = 25;
   }

   cout << "\nYou lost 3 seconds of time and gained $5.00." << endl;
   cout << "\nPress any key to continue...";
   cin.ignore().get();

}

//exit the game.
void Encounters:: endGame()   {
   cout << "\n*** YOU LOSE ***\nYour score will not be recorded.\n\t*** Goodbye ***" << endl;
   exit(0); // ends execution.

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class for executing puzzles for the player to complete in the game. Will effect player attributes.
///////////////////////////////////////////////////////////////////////////////////////////////////

class Puzzles  {

private:
   int q1 = 0;
   int q2 = 1;
   int q3 = 2;
   int q4 = 3;
   int q5 = 4;
   int q6 = 5;
   string question[6]; //holds the 6 questions strings;

public:
   void init_questionsArr();
   void doPuzzle(int& money, int& intelliegence, int& time, int& progress);
   int money;
   int intelligence;
   int time;
   int progress;


};

// method executes the puzzle encounters throughout the game;
void Puzzles:: doPuzzle(int& money, int& intelligence, int& time, int& progress) {
   
   init_questionsArr();
   int input;
   string stringIn;

   int rdm = (rand() % 6) + 1; // generates a random number between 1-6.

   switch(rdm) 
   {
      case 1: cout << '\n' << question[0];
         cin >> input;
         if (input == 8) {
            cout << "\nYou are correct!! You gain $8.00." << endl;
            money = money + 8;
         }
         else   {
            cout << "\nSorry that incorrect you lose $15.00!! Come on that was easy!" << endl;      
            money = money - 15;
         } 
         break; 
        
      case 2: cout << 'n' << question[1];
         cin >> input;
         if (input == 144) {
            cout << "\nYou are correct!! You gain 5 intelligence point." << endl;
            intelligence = intelligence + 5;
         }
         else  {
            cout << "\nThat wrong! You lose 10 intelligence points." << endl;
            intelligence = intelligence - 5;
         }
         break;
      
      case 3: cout << '\n' << question[2];
         cin >> stringIn;
         if (stringIn == "Jupitar") {
            cout << "\nYou're correct!! Gain 5 minutes of time." << endl;
            time = time + 5;
         }
         else if (stringIn == "jupitar") {
            cout << "\nYou're correct!! Gain 5 minutes of time." << endl;
            time = time + 5;
         }
         else {
            cout << "\nHow'd you get that wrong!? You lose 5 minutes of time." << endl;
            time = time - 5;
         }
         break;
       
      case 4: cout << 'n' << question[3];
         cin >> stringIn;
         if (stringIn == "Milky Way" || stringIn == "milky way" || stringIn == "Milky way")   {
            cout << "\nThats right!! You gain $5.00." << endl; 
            money = money + 5;
         }
         else { 
            cout << "\nYour wrong and thats just sad! You lose $5.00." << endl;
            money = money - 5;
         }
         break;
           
      case 5: cout << 'n' << question[4];
         cin >> input;
         if (input == 256)  {
            cout << "\nSomeones good at math! You gain 10 intelligence points." << endl;
            intelligence = intelligence + 10;
         }
         else   {
            cout << "\nThat's incorrect!! You lose 10 intelligence points." << endl;
            intelligence = intelligence - 10;
         }
         break;
           
      case 6: cout << 'n' << question[5];
         cin >> input;
         if (input == 7)   {
            cout << "\nYou are right!! You gain 8 minutes of time." << endl;
            time = time + 8;
         }
         else  {
            cout << "\nWrong worng wrong!! You lose 8 mintues of time" << endl;
            time = time - 8;
         }   
         break;
      default : cout << 'n' << "Error: *** Goodbye ***" << endl;
            
         break;
         
         cout << "\nPress any key to continue...";
         cin.ignore().get();
   }
           

}

void Puzzles:: init_questionsArr()  {

   question[0] = "What is the square root of 64?: ";
   question[1] = "What is 12 x 12?: "; 
   question[2] = "What is the largest planet in our solar system?: ";
   question[3] = "What solar system do we live in?: ";
   question[4] = "What is 16 squared?: ";
   question[5] = "What binary number is this 0111?: ";
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Class for execution of the game, tracking player attributes, progress within the game and calling on other classes
   to perform specific features of the game. Such as Encounters, Puzzles, and iff the player wins we will call on class 
   HighScores.
*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlayGame  {

private:
   Encounters en;
   HighScoresList hsl;
   Puzzles pz;

public:
   PlayGame(); //constructor - initializes player and sets all three attributes to fixed vaules.
   ~PlayGame(); //destructor
   // MEMBER FUNCTION DECLARATIONS
   void setDifficulty(); //will set the hall length returns 1, 2 or 3. 
   void turnSelection(); // will display the 5 opetion the palyer player has each turn.
   void move(int& money, int& intelligence, int& time);
   void readTechnical_papers(int& intelligence, int& time); //  + intelligence(random amount), - time(fixed).
   void searchFor_change(int& money, int& time); // + money(random amount), - time(fixed).
   void viewCurrent_status(); // prints the player attributes and current position in hall when called.
   void quitGame();
   void checkScore(); // checks to see if any attribute = 0 after each turn.
   void reportScore(); // if player wins, their score is reported to high scores list from this method. 
   int money;
   int intelligence;
   int time;
   int score;
   int progress;
   int hall_length;
   int userInput; //used in the turnSection method to get user input.
};

 //implementing the constructor
PlayGame::PlayGame()   {

   progress = 0;
   money = (rand() % 10) + 15;
   intelligence = (rand() % 10) + 15;
   time = (rand() % 10) + 20;
   
}

//sets the hall length of the game.
void PlayGame:: setDifficulty()  {

   int level;

   cout << "Select a difficulty level" << endl;
   cout << "1 - Easy\n2 - Medium\n3 - Hard\nEnter your selection: ";
   cin >> level;
         
   if (level == 1) {
      hall_length = EASY_HALL_LENGTH;
      
      cout << "\nGreat! Your hall length is: " << hall_length << endl;
      turnSelection();
   }
   else if (level == 2) {
      hall_length = MEDIUM_HALL_LENGTH;
      
      cout << "\nAwesome! Your hall length is: " << hall_length << endl;
      turnSelection();
   }
   else if (level == 3) {
      hall_length = HARD_HALL_LENGTH;
      
      cout << "\nA challenge you seek! Your hall length is: " << hall_length << endl;
      turnSelection();
   }
   else  {
      cout << "Error: Please try again later with a valid level input." << endl;
      setDifficulty(); //recursive loop that will allow the player to re enter the correct level.
   }
   
}

//displays the 5 options to the player for at the beginning of each turn.
void PlayGame:: turnSelection() { 
 
   while (progress < hall_length)  {
   
      cout << "\nYour current attributes are: \n";
      cout << "intelligence: " << intelligence << endl;
      cout << "time: " << time << '\n' << "money: $" << money << ".00" << endl; 
      cout << "You are " << (hall_length - progress) << " away from the end of the hall." << endl;
   
      cout << "\n\t1 - Move forward one spot. (takes time, and could encounter risky challenges)" << endl;
      cout << "\t2 - Read technical papers. (takes time, but boost intelligence)" << endl; 
      cout << "\t3 - Search for loose change. (takes time, but boost money)" << endl;
      cout << "\t4 - Veiw character attributes." << endl;
      cout << "\t5 - Quit the game." << endl; 
   
      cout << "\n\tPlease select your next action: ";
      cin >> userInput;
   
      if (userInput == 1)  { //calls move.
      
         move(money, intelligence, time);
      }
      else if  (userInput == 2)  { //calls read tech papers.
      
         readTechnical_papers(intelligence, time);
      }
      else if (userInput == 3)   { //calls search for change.
      
         searchFor_change(money, time);
      }
      else if (userInput == 4)   { //calls view current status.
      
         viewCurrent_status();
      }
      else if (userInput == 5)  {    
         quitGame();
      }
      else  {
         cout << "Error: You must select on of the 5 option. Please try again." << endl;
      }
   }
   
   if (progress >= hall_length)  {
   
      reportScore();
   }
}
   
//Player selects to move and moves step down the hall
void PlayGame:: move(int& money, int& intelligence, int& time)  {
   
   int rdm = rand() % 100;
   
   if (rdm < 25)  { 
      progress++; // nothing happens
      cout << "\nYou moved forward one step closer to the end of the hall and avoided all problems." << endl;
      cout << "\nPress any key to continue...";
      cin.ignore().get();
   }
   
   //player must do puzzle.
   else if (rdm >= 25 && rdm < 55)  {
      pz.doPuzzle(money, intelligence, time, progress); // can effect any of the param
   }
   // encounter a professor.
   else if (rdm >= 55 && rdm < 65)  {
      en.seeProfessor(intelligence, time); // lose random amt of time and gain intelligence.
      progress++;
   }
   else if (rdm >= 65 && rdm < 75)  {
      en.anotherGrad(time); // loses random amt of time.
      progress++;
   }
   else if (rdm >= 75 && rdm < 90)  {
      en.gruntWork(intelligence, time); // loses time and intelliegence.
      progress++;
   }
   else if (rdm >= 90 && rdm < 99)   {
      en.gradePapers(money, time); // gain money but loses time.
      progress++;
   }
   

}

/* player selects the read papers option and gains a random amt of intelligence and looses
   and fixed amt of time */
void PlayGame:: readTechnical_papers(int& intelligence, int& time) {

   int intelGained = (rand() % 5) + 1;
   intelligence = intelligence + intelGained;

//Max intelligence statement
   if (intelligence > 25)  {
      intelligence = 25;
   }
   time = time - 4;
   if (time <= 0) {
      cout << "\nYour time as run out and you have died in the Shelby Center hall from old age." << endl;
      quitGame();
   }
   
   cout << "\nYou gained " << intelGained << " intelligence this time and lost 4 seconds of time." << endl;
   cout << "\nPress any key to continue...";
   cin.ignore().get();

}

/* Player selects the search for loose chance option and gains a random amt of money and
   looses a fixed amt of time */
void PlayGame:: searchFor_change(int& money, int& time)  {
   
   int moneyGained = rand() % 6;
   money = money + moneyGained;
 
 //max money boolean statement. stops the player from have to much money.
   if (money > 25)  {
      money = 25;
   }
   time = time - 4;
   if (time <= 0) {
      cout << "\nYour time as run out and you have died in the Shelby Center hall from old age." << endl;
      quitGame();
   }
   
   cout << "\nYou gained $" << moneyGained << ".00 but lost 4 seconds of time." << endl;
   cout << "\nPress any key to continue...";
   cin.ignore().get();
   
}

// Player selects the view character option and the progress and player attributes are displayed.
void PlayGame:: viewCurrent_status()   {

   cout << "\nYour current attributes are:\n" << endl;
   cout << "intelligence: " << intelligence << endl;
   cout << "time: " << time << '\n' << "money: $" << money << ".00" << endl; 
   cout << "You are" << (hall_length - progress) << "steps away from the end of the hall.\n" << endl; 

   turnSelection();
}

// Player selects to quit the game.
void PlayGame:: quitGame() {

   cout << "\n*** YOU LOSE ***\nYour score will not be recorded.\n\t*** Goodbye ***" << endl;
   exit(0); // ends execution.
}
   
   // reports the score to high scores list iff the player wins
void PlayGame:: reportScore()  {
   
   if (progress >= hall_length)  {
      cout << "Congrats!! You win and have made through the hall!" << endl;
      cout << "Your score is " << hsl.calcScore(money, intelligence, time);
      score = hsl.calcScore(money, intelligence, time);
      string playerName = hsl.getPlayerName(); //gets the name from high scores class.
      hsl.newHighScore(score);
      
      exit(0);
   
   }
}

//destructor
PlayGame::~PlayGame()   {

}

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

   HighScoresList hsl;
   Testing test;
   string playerName; // used as dummy string to call the getUserName(string& nameIn)
   int optionIn;
   int i;
   srand(time(0));
   
   hsl.askUserName(playerName);
   
   //main menu of the game system.
   cout << "1 - Start a New Game of Shelby Center Hall and Dragons!!" << endl;
   cout << "2 - See the top 10 High Scores!" << endl;
   cout << "3 - Quit and exit.\n" << endl;
   cout << "\tPlease select and option from above(1-3): ";
   cin >> optionIn;
   check_number(optionIn);
      
   cout << endl;
   
   if (optionIn == 1)  { 
      cout << "\nWe are now entering the Game...\n" << endl; 
      PlayGame play;
      play.setDifficulty();
   }
   else if (optionIn == 2)   {
   
   //hsl.fgbbj
   }
   else if (optionIn == 3)   {
   
      cout << "Thank you for playing!! \n\t\t\t *** Goodbye ***" << endl;
   
      return 0;
   }  

   return 0;
}

// checks for and integer input.
bool check_number(int& input)  {

   bool result;
   
   if (input != 1)   {
      if (input != 2)  {
         if (input != 3)  {
            result = false;
         }
      }
   }
         
   while (result == false)   { 
      cin.clear(); 
      cin.ignore(1000, '\n'); 
      result = false;
      
      cout <<"Error: Invalid input, please enter 1, 2, or 3: ";
      cin >> input;
      result = check_number(input);
      
   }
      
   return true;
}





