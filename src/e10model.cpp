/* FBullCowGame.cpp 0.0.9            UTF-8                        2017-01-02 */
/* ------1---------2---------3---------4---------5---------6---------7------ */



#include "FBullCowGame.hpp"

#include <string>
#include <ctype.h>
    /* XXX: Game is restricted to use of A-Z, a-z, 26-letter "Roman"
            alphabet.  Complexity of other alphabets is not addressed. 
            */


FBullCowGame::FBullCowGame(std::string SecretWord)
{
    MySecret = SecretWord;
    MyCurrentGuess = SecretWord;
        // XXX: temporarily to check as a good isogram

    if (!IsGoodIsogram())
        MySecret = std::string("");

    MyCurrentGuess = std::string("");
    MyGoodTries = 0;
    MyMaxTries = 5;
        /* TODO: Find a better way to estimate this based
                 on SecretWord.length() without giving 
                 anything away about complexity. */
}

FBullCowGame::FBullCowGame(std::string SecretWord, unsigned MaxTries)
    : FBullCowGame(SecretWord)
{
    MyMaxTries = MaxTries;
}

unsigned FBullCowGame::WordSize() const { return MySecret.length(); }

void FBullCowGame::SetGuess(std::string Guess)
{
    MyCurrentGuess = Guess;
    if (IsGoodIsogram()) MyGoodTries++;
}

std::string FBullCowGame::CurrentGuess() const { return MyCurrentGuess; }

bool FBullCowGame::IsOnlyLetters() const
{
    if (WordSize() == 0) return false;

    for (unsigned i = 0; i < MyCurrentGuess.length(); i++)
    {
        if (!isalpha(MyCurrentGuess[i])) return false;
    }

    return true;   
} 

bool FBullCowGame::IsCorrectLength() const
{
    if (!IsOnlyLetters()) return false;

    return MyCurrentGuess.length() == MySecret.length();
}

bool FBullCowGame::IsGoodIsogram() const
{   /* XXX: This Implementation does not require that SecretWord
            and CurrentGuess be known English words. It only
            deals with spelling, not recognition or even
            pronuncibility of the word.  This is an advantage
            in mechanical guessing heuristics but not awesome.
            */

    if (!IsCorrectLength()) return false;

    for (unsigned i = 1; i < MyCurrentGuess.length(); i++)
        /* Require CurrentGuess[i] to differ from all preceding 
           CurrentGuess[j], j < i
           */
        for (unsigned j = 0; j < i; j++)
            if (tolower(MyCurrentGuess[i]) == tolower(MyCurrentGuess[j])) 
                return false;

    return true;
}

bool FBullCowGame::IsSecretGuessed() const
{
    if (!IsGoodIsogram()) return false;

    return Bulls() == MySecret.length();
}

unsigned FBullCowGame::Bulls() const
{
    if (!IsGoodIsogram()) return 0;

    unsigned MyBulls = 0;

    for (unsigned i = 0; i < MySecret.length(); i++)
        if (tolower(MySecret[i]) == tolower(MyCurrentGuess[i])) 
            MyBulls++;

    return MyBulls;
}

unsigned FBullCowGame::Cows() const
{  
    if (!IsGoodIsogram()) return 0;

    unsigned MyCows = 0;

    for (unsigned i = 0; i < MySecret.length(); i++)
        for (unsigned j = 0; j < MyCurrentGuess.length(); j++)
            if (tolower(MySecret[i]) == tolower(MyCurrentGuess[j])) 
                MyCows++;

    return MyCows - Bulls();
}

unsigned FBullCowGame::GoodTries() const { return MyGoodTries; }

unsigned FBullCowGame::MaxTries() const 
    { return MyMaxTries; }


/* ------1---------2---------3---------4---------5---------6---------7------ */

/* 0.0.9 2017-01-02-13:24 Add FBullCowGame(SecretWord, MaxTries) constructor.
   0.0.8 2017-01-02-13:02 Rename ::SuggestedMaxTries() to ::MaxTries()
         and have MyGoodTries and MyMaxTries as state variables.
   0.0.7 2016-12-25-08:17 Use case-insensitive checking of SecretWord and 
         CurrentGuess.  Adjust formatting and tighten comments and identfication
         of edge cases. 
   0.0.6 2016-12-24-13:45 Set const on all methods except SetGuess().
   0.0.5 2016-12-24-10:31 Change WellFormedTries() to GoodTries(), scrub the
         method annotations. Add essential includes without assumptions about
         FBullCowGame.hpp.
   0.0.4 2016-12-23-17:44 Adjust method names, add CurrentGuess(), and stub
         out verification of SecretWord until IsGoodIsogram() is working.
   0.0.3 2016-12-23-08:06 Use Ladder of guards to get to IsGoodIsogram().
         All preconditions checked and all methods guarded regardless of
         the order in which they are checked by an user of the interface.
   0.0.2 2016-12-22-22:30 Clean up constructer, fix string.length() usage, 
         and add consistency checking.
   0.0.1 2016-12-22-18:24 Stub/Coordinate all FBullCowGame.hpp methods. 
         */


/*                    *** end of FBullCowGame.cpp ***                         */



