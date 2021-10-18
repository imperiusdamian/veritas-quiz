#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>

#include "veritas.h"

int main(int argc, char* argv[])
{
    Ques veritasQuiz;
    int fileError = 0;
    bool fNameParameter;
    int i = 0;
    int score = 0;
    int menuOption = 0;
    double scorePercentage =  0.0f;
    std::string name;
    std::string fileName;
    std::string namePrompt = std::string(WHATNAME) + std::string(MAX32) + "? ";
    std::string fNamePrompt = "Please enter the  name of the Quiz to play " + std::string(MAX32) + ": ";
    std::string fNameInput = "";
    char cmdInput = 0;
    std::array<int, 30> rndQues {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                            12, 13, 14, 15, 16, 17, 18, 19, 20,
                            21, 22, 23, 24, 25, 26, 27, 28, 29};
    unsigned rndSeed;

    name = getName(namePrompt, 0);

    if(argc >= 2)
    {
        if(strlen(argv[1]) > 1)
        {
            std::cout << "\n Command line argument must be a single letter; proceeding to main menu.\n";
            pressEnter();
            fNameParameter = false;
        }
        else
        {
            if(argc == 3)
            {
                fNameInput = std::string(argv[2]);
                std::transform(fNameInput.begin(), fNameInput.end(), fNameInput.begin(), ::tolower);
            }
            cmdInput = argv[1][0];
            cmdInput = tolower(cmdInput);
            fNameParameter = true;
        }
    }
    else
    {
        fNameParameter = false;
    }

    do
    {
        rndSeed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(rndQues.begin(), rndQues.end(), std::default_random_engine(rndSeed));
        i = 0;

        if(!fNameParameter)
        {
            menuOption = veritasQuiz.mainMenu(name);
        }
        else
        {
            switch(cmdInput)
            {
                case 'q':
                    menuOption = 1;
                    break;
                case 'e':
                    menuOption = 2;
                    break;
                case 'c':
                    menuOption = 3;
                    break;
                case 's':
                    menuOption = 4;
                    break;
                case 'h':
                    menuOption = 5;
                    break;
            }
        }

        switch(menuOption)
        {
            case MENU_PLAY:
                score = 0;
                if(argc == 3)
                {
                    fileName = fNameInput;
                }
                else
                {
                    fileName = getName(fNamePrompt, 1);
                }
                fileError = veritasQuiz.fileCreate(fileName);
                if(fileError != 1)
                {
                    errorFile(fileError);
                }
                else
                {
                    for(int& x: rndQues)
                    {
                        i++;
                        score += veritasQuiz.displayQuestion(x, i, name);
                    } // end for()
                    scorePercentage = scorePercent(score);
                    char* fName = const_cast<char*>(fileName.c_str());
                    veritasQuiz.writeScore(score, scorePercentage, name, fName);
                } // end if-else()
                break; // end case 1
            case MENU_SAMPLE:
                score = 0;
                fileError = veritasQuiz.fileCreate(SAMPLEQUIZ);
//                if(fileError != 1) veritasQuiz.createSampleQuiz();
                for(int& x: rndQues)
                {
                    i++;
                    score += veritasQuiz.displayQuestion(x, i, name);
                } // end for()
                scorePercentage = scorePercent(score);
                veritasQuiz.writeScore(score, scorePercentage, name, (char*)SAMPLEQUIZ);
                break; // end case 2
            case MENU_CREATE:
                fileError = veritasQuiz.createQuiz(name);
                if(fileError)
                {
                    errorFile(fileError);
                }
                break; // end case 3
            case MENU_SCORE:
                veritasQuiz.displayScore();
                break; // end case 4
            case MENU_ABOUT:
                showAbout();
                break; // end case 5
            case MENU_QUIT:
                clrScrn();
                titleLine();
                std::cout << std::endl << "    Thanks for playing, " << GREENTEXT << name << NORMALTEXT << "." << std::endl;
                fNameParameter = false;
                break; // end case MAX_MENU_OPTS
        } // end switch
        if(fNameParameter)
        {
            bool quitYesNo = returnToMenu();
            if(!quitYesNo)
            {
                return 0;
            }
        }
        fNameParameter = false;
        std::cout << std::endl;
    }
    while(menuOption != MAXMENUOPTS); // end do while()

    return 0;
}
