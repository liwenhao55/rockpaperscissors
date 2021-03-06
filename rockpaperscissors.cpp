
      // Example program
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
enum object{ROCK,PAPER,SCISSORS};
void displayRules();
object getPlay();
void play(int&,int&,int&); 
void print(int,int,int);
object AI();
object findwinner(object,object); 

int main() 

{   srand(time(NULL));
    int Choice, p1wins = 0, p2wins = 0,  ties = 0;
    do { 
        cout << "Rock - Papers - Scissors"<< endl; 
        cout << "To see the rules enter 1"<< endl;  
        cout << "To play the game enter 2"<< endl; 
        cout << "To display results enter 3"<< endl;  
        cout << "To exit, enter 9"<< endl;    
        cin >> Choice;
        if(!cin) 
        { 
            cin.clear(); 
            cin.ignore(100,'\n'); 
} 
switch (Choice){ 
    case 1:  
    displayRules(); 
    break; 
    case 2:  
    play(p1wins,p2wins,ties);
    break; 
    case 3:  
    print(p1wins,p2wins,ties);
    break; 
     case 9:  
    break;
} 
} while (Choice !=9); 
return 0;
}
void displayRules()
{
    cout << "\nWelcome to rock paper scissors." << endl;
    cout << "\nYou must select either rock paper or scissors" << endl;
    cout<< "\n If both players select the same thing, it will end in a tie" << endl;
    cout << "Scissors cut paper : Scissor wins." << endl;
    cout << "Rock breaks scissors : Rock wins." << endl;
    cout << "Paper covers rock : Paper wins." << endl;
}

object getPlay() {
    cout << "Enter R for rock, S for Scissors, P for paper: ";

    while (true) {
        char ch;
        cin >> ch;
        switch (ch) {
            case 'R':
            case 'r':
                return ROCK;

            case 's':
            case 'S':
                return SCISSORS;

            case 'p':
            case 'P':
                return PAPER;
        }
    }
}
void play(int& win1, int& win2, int& tie)
{
    object player1,player2, winner; 
    bool isGood = false; 
  do 
  {   
    cout <<"Player one. " << endl; 
    player1 = getPlay(); 
    switch(player1)
    {
 case ROCK:
    cout <<"Rock"<< endl; break;
   case PAPER:
    cout <<"Paper"<< endl;break; 
     case SCISSORS:
    cout <<"Scissors"<< endl; break;
  } 
    cout <<"Computer chooses "; 
    player2 = AI(); 
    cout << endl; 
    winner = findwinner(player1,player2); 
    if (player1 == player2) 
    {    
      cout << " Game is a tie" << endl; 
      tie++;
    } 
     if (winner == player1) 
    {    
      cout << "Player 1 wins" << endl; 
      win1++;
    } 
      if (winner == player2) 
    {    
      cout << "Player 2 wins" << endl; 
      win2++;
    } isGood = true;
 }while(isGood==false);
}
object AI() 
{ 
    object computer;
    int num = rand() % 3;
      switch(num) {
        case 0:
            computer = ROCK;
            cout <<"Rock"<< endl;break;
        case 1:
            computer = PAPER;
            cout <<"Paper"<< endl; break;
        case 2:
            computer = SCISSORS;
            cout <<"Scissors"<< endl; break;
    }
    return computer;

} 
object findwinner(object p1,object p2) 
{ 
if ((p1 ==ROCK && p2 == SCISSORS) || (p2 == ROCK && p1 == SCISSORS)) 
return ROCK; 
if ((p1 ==ROCK && p2 == PAPER) || (p2 == ROCK && p1 == PAPER)) 
return PAPER; 
else  
return SCISSORS;
} 
void print(int p1, int p2, int tie) 
{ 
cout <<"Player 1 wins = " << p1 << endl;
cout <<"Computer wins = " << p2 << endl; 
cout <<"Nobody wins = " << tie << endl; 
cout <<"Total games = " << p1 + p2 + tie<<endl;
}
