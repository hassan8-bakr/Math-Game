
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>    
using namespace std;
enum enLevel { easy = 1,med = 2,hard = 3,mix =4};
enum enOperation { add = 1, sub = 2, milti =  3, divide = 4 , Mix = 5 };
void printredcolorscreen()
{
    system("color 4f");
    cout << "the answer is false" << endl;
}
void printgreencolorscreen()
{
    system("color 2f");
    cout << "the answer is true"<<endl;
}
struct game
{
    int number1 = 0;
    int number2 = 0;   
    short NumberOfQuestions;
    enLevel QuestionLevel;
    enOperation operationtype;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool IsCorrect = false; 
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
};
struct qutions
{
    game QuestionList[100];
   
};
short choosenumberlevel()
{
    short num;
    do
    {
     cout << "please enter your level of game [1]easy [2]med [3]hard [4]mix " << endl;
     cin >> num;
    } while(num < 1 || num > 4);
    return num;
}
short choosenoperationtype()
{
    short num;
    do
    {
        cout << "please enter your level of game [1]add [2]sub [3]multi [4]div [5]mix " << endl;
        cin >> num;
    } while (num < 1 || num > 5);
    return num;
}
int randomnumber(int from, int to)
{
    int randomnumber = 0;
    randomnumber = rand() % (to - from + 1) + from;
    return randomnumber;
}
int startgame()
{
    int round = 0;
    cout << "\t\t\t\t\t _____ welcome in math game _____\t\t\t\t\t"<<endl;
    cout <<endl << "  how many qeutions do you want to play ? ";
    cin >> round;
    return round;
}
enLevel chooselevelgame(short levelgame)
{
    
    if (levelgame == 4)
    {
        levelgame = randomnumber(1, 3);
    }
    switch (levelgame)
    {
     case 1:
         return enLevel::easy;
         break;
     case 2:
         return  enLevel::med;
         break;
     case 3:
         return  enLevel::hard;
         break;
    }
}
enOperation choosetypegame(short operationtype)
{
    
    if (operationtype == 5)
    {
         operationtype = randomnumber(1, 4);
    }
    switch (operationtype)
    {
    case 1:
        return enOperation::add;
    case 2:
        return enOperation::sub;
    case 3:
        return enOperation::milti;
    case 4:
        return enOperation::divide;
    }
}
string chooseoperationingame(enOperation operationtype)
{
    switch (operationtype)
    {
        case enOperation::add:
            return "+";
        case enOperation::sub:
            return "-";
            case enOperation::milti:
            return "*";
            case enOperation::divide:
            return "/";
    }
}
int trueanswer(enOperation game1,int number1,int number2)
{
    
    switch (game1)
    {
    case enOperation::add:
        return  number1 + number2;
        break;
        case enOperation::sub:
        return  number1 - number2;
        break; 
        case enOperation::milti:
            return  number1 * number2;
            break;
        case enOperation::divide:
            return number1 / number2;
            break;
       
    }
}
int chooselevelofnumber(enLevel game1)
{
   
    int number = 0;
    switch (game1)
    {
    case enLevel::easy:
        return randomnumber(1, 10);
        case enLevel::med:
        return randomnumber(10, 25);
        case enLevel::hard:
        return randomnumber(-25, 75);
    }
}
bool checkanswer(int correctanswer,int playeranswer)
{
    if (playeranswer == correctanswer)
    {
        printgreencolorscreen();
        return true;
    }
    else
    {
        printredcolorscreen();
        return false;

    }
}
void playmathgame()
{
    game mathgame;
    mathgame.NumberOfQuestions = startgame();
    mathgame.QuestionLevel = chooselevelgame(choosenumberlevel());
   chooselevelofnumber(mathgame.QuestionLevel);
   mathgame.operationtype = choosetypegame(choosenoperationtype());
   for (int i = 0;i < mathgame.NumberOfQuestions;i++)
   {
       cout << endl;
       cout << "quetion [" << i + 1 << " / " << mathgame.NumberOfQuestions <<"]" << endl;
       mathgame.number1 = chooselevelofnumber(mathgame.QuestionLevel);
       mathgame.number2 = chooselevelofnumber(mathgame.QuestionLevel);
       cout << "(" << mathgame.number1<< ")" << endl;
       cout << chooseoperationingame(mathgame.operationtype) << endl;
       cout << "(" << mathgame.number2 << ")" << endl;
       cin >> mathgame.PlayerAnswer;
       mathgame.CorrectAnswer = trueanswer(mathgame.operationtype, mathgame.number1, mathgame.number2);
       if (mathgame.PlayerAnswer == mathgame.CorrectAnswer)
       {
           printgreencolorscreen();
           mathgame.NumberOfRightAnswers++;
       }
       else
       {
           printredcolorscreen();
           cout << "the correct answer " << mathgame.CorrectAnswer << endl;
           mathgame.NumberOfWrongAnswers++;
       }

       cout << "_____________________________________"<<endl;

   }

 cout <<" THE CORRECT ANSWER " << "---> " << mathgame.NumberOfRightAnswers << endl;
 cout <<" THE WRONG ANSWER " << "---> " << mathgame.NumberOfWrongAnswers << endl;
}
void resetgame()
{
    char playAgain = 'y';
    cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain; 
    while (playAgain == 'Y' || playAgain == 'y')
    {
        system("color 0f");
        system("cls");
        playmathgame();
    } 

}

void finallydetails()
{

    game mathgame;
    playmathgame();
    resetgame();
}


int main()
{
    srand((unsigned)time(NULL));
    finallydetails();
}
