#ifndef VERITAS_H_INCLUDED
#define VERITAS_H_INCLUDED

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define MAXQUES 30      // maximum number of Qs in a Quiz
#define QUIZFILESIZE 31 // Quiz file size in records; includes QuizInfo at end of file
#define SCOREFILESIZE 12 // Score file size in records
#define QUESLENGTH 80   // maximum length of question/answer std::strings
#define NAMELENGTH 33   // maximum length of player name

#define VERITASQUIZ "Created by the Veritas Quiz "
#define VERSION "Beta v0.143" // current version
#define BUILDDATE "2021-09-30" // date of build
// 2021-09-30 builds: added command line option 'e' to launch sample quiz, fixed score file not displaying quiz subject, fixed bug with About screen not displaying

#define MAX32 "(max. 32 characters)"
#define MAX80 "(max. 80 characters)"

#define WHATNAME "What is your name "

#define PRESSENTER " Press <Enter> to continue."
#define SHOULDNOT "This text should not appear. Please enter 1 for the answer."
#define ABOUT1 " Veritas is a basic Quiz program for console mode Windows and Linux."
#define ABOUT2 " Veritas is written and maintained by Devlin Wright."
#define COPYRIGHT " Copyright (c) Devlin Wright 2016-2021."

#define QUIZFILEEXT ".qzp" // file extension for Quizzes, added automatically
#define SAMPLEQUIZ "egypt.qzp" // filename of sample Quiz
#define SCOREFILENAME "scores.qzs" // filename for score file

#define MAXMENUOPTS 6 // number of main menu choices
#define MENU1 "Play a Quiz"
#define MENU2 "Play Sample Quiz"
#define MENU3 "Create a Quiz"
#define MENU4 "View High Scores"
#define MENU5 "About Veritas"
#define MENULAST "Quit Veritas"

#define DEFAULTNAME "Default Player"
#define DEFAULTSUBJECT "Default Subject"

#define BUNCHASPACES "                                 "

#define GREENTEXT "\033[32m"
#define REDTEXT "\033[31m"
#define CYANTEXT "\033[36m"
#define NORMALTEXT "\033[0m"

enum mainMenu {
    MENUDEFAULT,
    MENU_PLAY,
    MENU_SAMPLE,
    MENU_CREATE,
    MENU_SCORE,
    MENU_ABOUT,
    MENU_QUIT
};
struct QuesRec {
    char question[QUESLENGTH];
    char option1[QUESLENGTH];
    char option2[QUESLENGTH];
    char option3[QUESLENGTH];
    int correctAnswer;
};

struct ScoreRec {
    char playerName[NAMELENGTH];
    char subject[NAMELENGTH];
    int highScore;
};

typedef struct QuesRec quesInfo;
typedef struct ScoreRec scoreInfo;

class Ques {
    private:
        quesInfo currentQuestion;
        scoreInfo currentHighScore;
        std::fstream quesFile;
        std::fstream scoreFile;
        int sizeOfQuestion;
        int sizeOfScore;
        int getAnswer(std::string name, int maxAnswer);
        void createScoreFile();
        void sortScoreFile();
        void createSampleQuiz();
        void showQuestion(quesInfo currQues, int i);
        char* scoreSubject();
    public:
        Ques();
        int mainMenu(std::string name);
        int fileCreate(std::string fName);
        int displayQuestion(int x, int i, std::string name);
        void displayScore();
        void writeScore(int score, double scorePercentage, std::string name, char* fName);
        void closeFile(int x);
        int createQuiz(std::string name);
};

std::string getFileExtension(const std::string& inputFName);
std::string getName(std::string promptString, int isQuizFile);

double scorePercent(int score);

char* buildVerString();
char* buildYNString();

size_t v_strcpy(char *dst, const char *src, size_t size);

void clrScrn();
void outputChars(int i, int j, const char c);
void errorFile(int fileError);
void pressEnter();
void showAbout();
void titleLine();

bool returnToMenu();
bool scoreCompare(scoreInfo s1, scoreInfo s2);
bool validInput(std::string enteredAnswer);

#endif // VERITAS_H_INCLUDED
