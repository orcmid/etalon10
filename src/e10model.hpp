#pragma once
/* BlueCowGame.hpp 0.0.10            UTF-8                        2017-01-02 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <string>

class FBullCowGame 
{  /* A model for the Bulls and Cows Game.
      This model has no side-effects beyond its encapsulated state,
      with no input-output and player interaction here. */

public:
    FBullCowGame(std::string SecretWord);
        /* Each instance has its own alpha isogram, with the word
           size determined automatically.  Capitalization does not
           matter.  If the SecretWord is not an isogram, it is set 
           to "" so that WordSize() == 0 and all guesses will fail.
           */

    FBullCowGame(std::string SecretWord, unsigned MaxTries);
        /* Also specify MaxTries */

    unsigned WordSize() const;
        /* The size of the SecretWord.  
           0 if SecretWord was not a good isogram. */

    void SetGuess(std::string Guess);
         /* Enter a Guess to be the CurrentGuess() 
            until another is set.  Capitalization does not
            matter.
            */

    std::string CurrentGuess() const;
        /* The latest SetGuess() parameter and the 
           empty string, "", before the first SetGuess(). */

    bool IsOnlyLetters() const;
         /* When there are only alpha characters in 
            CurrentGuess() 
            */

    bool IsCorrectLength() const;
         /* When the CurrentGuess() of only letters has the
            same length as the SecretWord. */

    bool IsGoodIsogram() const;
         /* When CurrentGuess() is a well-formed isogram of 
            correct length, whether or not a winner. 
            */

    bool IsSecretGuessed() const;
         /* Ignoring capitalizations, CurrentGuess() matches 
            the secret word, unless the secret word is improper 
            (so WordSize() == 0)
            */

    unsigned Bulls() const;
        /* the number of Bulls when IsGoodIsogram(), else 0 */

    unsigned Cows() const;
        /* the number of Cows when IsGoodIsogram(), else 0 */

    unsigned GoodTries() const;
        /* the number of SetGuess() operations for which 
           IsGoodIsogram() was true.   
           */

    unsigned MaxTries() const;
        /* the number of tries suggested as a limit for the 
           current SecretWord */

private:
    std::string MySecret;
    std::string MyCurrentGuess;
    unsigned MyGoodTries;
    unsigned MyMaxTries;
        /* TODO: Completely hide this implementation info 
                 from the interface and contract?
                 */

};

/* ------1---------2---------3---------4---------5---------6---------7------ */


/* 0.0.10 2017-01-02-13:35 Add optional MaxTries constructor case.
   0.0.9 2017-01-02-12:56 Change ::SuggestedMaxTries() to ::MaxTries,
         simplify to MyGoodTries and MyMaxTries in the state.
   0.0.8 2016-12-29-09:32 Touch up line-lengths to avoid word wrapping at
         the ruler setting.  Add TODO.
   0.0.7 2016-12-25-07:53 Reflect that the handling of SecretWord and 
         CurrentGuess is case-insensitive, allowing players to use 
         capitalization in a way that aids zeroing in on a solution.  
         Touch-up interface comments.
   0.0.6 2016-12-24-13:47 Declare all methods const except SetGuess.  
         Aligning with Lecture 28.
   0.0.5 2016-12-24-10:04 Annotate the methods better.  
         Change WellFormedTries() to GoodTries().
   0.0.4 2016-12-23-17:43 Switch to SetGuess() and provide CurrentGuess().
         MyCows and MyBulls not needed in the state record.
   0.0.3 2016-12-22-22:31 Smooth and keep aligned with FBullCowGame.cpp
   0.0.2 2016-12-22-18:25 Complete privates, and smooth with FBullCowGame.cpp
   0.0.1 2016-12-22-14:58 Initial attempt at a pure model of the 
         situation as a challenge puzzle for Unreal Developer 
         Section02 Lecture 24 on Header Files as Contracts
         */

/*                      *** end of BullCowGame.hpp ***                       */
