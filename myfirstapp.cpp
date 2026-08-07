#include <iostream>  
#include <string>  
#include <cstdlib> 
#include <ctime>
#include <cmath>
using namespace std; 
 int ReadRoundNumber()
{
     int RoundNumber = 0;
     do 
     {
         cout << "\nHow many rounds do you want to play (1 to 10)?\n";
         cin >> RoundNumber;
     } while (RoundNumber < 1 || RoundNumber > 10);

     return RoundNumber;
}

 enum enChoice 
 {
     Stone = 1 ,
     Paper = 2 ,
     Scissors = 3
};

 enum enWinner
 {
     Player,
     Computer,
     Draw
 };

 struct stGameResults {

     int PlayerWins;
     int ComputerWins;
     int Draws;
     enWinner FinalWinner;

 };
 int RandomNumber(int from  , int to  )
 {

     return rand() % (to - from + 1) + from;

 }

 void PrintRoundHeader(int RoundNumber)
 {
     cout << "Round [ " << RoundNumber << " ] begins:" << endl;
     cout << endl;

 }

enChoice ReadPlayerChoice()
{
    int Choice;
    do 
    {
        cout << "Your Choice : [1]:Stone , [2]:Paper , [3]:Scissors" << endl;
        cin >> Choice;

    } while (Choice < 1 || Choice > 3 );

    return (enChoice)Choice;
}

enChoice RandomComputerChoice()
{
    return (enChoice)RandomNumber(1, 3);
}

string ChoiceName(enChoice Choice)
{
    switch (Choice)
    {
    case enChoice::Stone:
        return "Stone";     
       
    case enChoice::Paper:
        return "Paper";        

    case enChoice::Scissors:
        return "Scissors";

    default:
        return "Unknown";

    }
}

enWinner WhowonTheRound(enChoice PlayerChoice, enChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
        return Draw;

    if ((PlayerChoice == Stone && ComputerChoice == Scissors)

        || (PlayerChoice == Scissors && ComputerChoice == Paper)

        || (PlayerChoice == Paper && ComputerChoice == Stone))

        return Player;

    else
        return Computer;

}

string WinnerName(enWinner Winner)
{
    switch (Winner) {

    case enWinner::Player:
        return "Player";

    case enWinner::Computer:
        return "Computer";

    case enWinner::Draw:
        return "No Winner";

    default:
        return "Unknown";
    }
}
void SetScreenColor(enWinner Winner)
{
    switch (Winner) {
    case enWinner::Draw:
        system("color 6E");
        break;

    case enWinner::Player:
        system("color 2A");
        break;

    case enWinner::Computer:
        system("color 4C");
        break;
     }

}
void StartGame()
 {
     int TotalRounds = ReadRoundNumber();

     stGameResults GameResults;
     GameResults.PlayerWins = 0;
     GameResults.ComputerWins = 0;
     GameResults.Draws = 0;


     for (int RoundNumber = 1; RoundNumber <= TotalRounds; RoundNumber++)
     {
         PrintRoundHeader(RoundNumber);

         enChoice PlayerChoice = ReadPlayerChoice();
         enChoice ComputerChoice = RandomComputerChoice();

      enWinner RoundWinner = WhowonTheRound(PlayerChoice, ComputerChoice);

      if (RoundWinner == Player)
          GameResults.PlayerWins++;

      else if (RoundWinner == Computer)
          GameResults.ComputerWins++;

      else
          GameResults.Draws++;

      SetScreenColor(RoundWinner);
     cout << "Player  Choice: " <<" [ " << ChoiceName(PlayerChoice)<< " ] " << endl;
     cout << "Computer Choice: " << " [ " << ChoiceName(ComputerChoice) << " ] " << endl;
     cout << "Round Winner : " << " [ " << WinnerName(RoundWinner) << " ] " << endl;
     cout << "______________________________________________________________________________" << endl;
     }

     if (GameResults.PlayerWins > GameResults.ComputerWins)
         GameResults.FinalWinner = Player;
        
     else if (GameResults.PlayerWins < GameResults.ComputerWins)
         GameResults.FinalWinner = Computer;

     else
         GameResults.FinalWinner = Draw;

     cout << "Player Wins : " << GameResults.PlayerWins << endl;
     cout << "Computer Wins : " << GameResults.ComputerWins << endl;
     cout << "Draws  : " << GameResults.Draws << endl;
     cout << "Final Winner :" << WinnerName(GameResults.FinalWinner) << endl;

     system("pause");
      system("color 0F");

 }


int main()
{
    srand((unsigned)time(NULL));

   
    StartGame();
}