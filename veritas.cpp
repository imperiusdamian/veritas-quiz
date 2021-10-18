#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#include "veritas.h"

//
// constructor for Ques
// sets up the Sample Quiz file if it doesn't exist
//
Ques::Ques()
{
    sizeOfQuestion = sizeof(currentQuestion);
    sizeOfScore = sizeof(currentHighScore);

    quesFile.open((char*)SAMPLEQUIZ, std::ios::in | std::ios::binary);
    scoreFile.open((char*)SCOREFILENAME, std::ios::in | std::ios::binary);

    if(!scoreFile.is_open()) createScoreFile(); else sortScoreFile();

    if(!quesFile.is_open()) createSampleQuiz();
}

void Ques::createScoreFile()
{
        scoreFile.open((char*)SCOREFILENAME, std::ios::out | std::ios::trunc | std::ios::binary);

        for(int i = 0; i < SCOREFILESIZE; i++)
        {
            currentHighScore.highScore = 0;
            v_strcpy(currentHighScore.playerName, DEFAULTNAME, NAMELENGTH);
            v_strcpy(currentHighScore.subject, DEFAULTSUBJECT, NAMELENGTH);
            scoreFile.write((char*)&currentHighScore, sizeOfScore);
        }
        closeFile(2);
}

void Ques::sortScoreFile()
{
        scoreInfo scores[SCOREFILESIZE];

        for(int i = 0; i < SCOREFILESIZE; i++)
        {
            scoreFile.read((char*)&currentHighScore, sizeOfScore);
            scores[i] = currentHighScore;
        }
        closeFile(2);

        std::sort(scores, scores + SCOREFILESIZE, scoreCompare);

        scoreFile.open((char*)SCOREFILENAME, std::ios::out | std::ios::trunc | std::ios::binary);
        for(int i = 0; i < SCOREFILESIZE; i++)
        {
            scoreFile.write((char*)&scores[i], sizeOfScore);
        }
        closeFile(2);
}

void Ques::createSampleQuiz()
{
        quesFile.open((char*)SAMPLEQUIZ, std::ios::out | std::ios::trunc | std::ios::binary);
    // 1
        v_strcpy(currentQuestion.question, "What is the meaning of the title Per-Aa?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "King of the Two Lands", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "King of Kings", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Great House", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 2
        v_strcpy(currentQuestion.question, "Which king is usually credited with building the Great Pyramid?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Ramesses", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Akhenaten", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Khufu", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 3
        v_strcpy(currentQuestion.question, "The New Kingdom is usually held to begin around when?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "1550 BCE", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "1069 BCE", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "664 BCE", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 4
        v_strcpy(currentQuestion.question, "Which major power did Ramesses II fight at Kadesh in 1274 BCE?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "The Mitanni", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "The Hittites", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Assyria", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 5
        v_strcpy(currentQuestion.question, "What was the god Thoth credited with?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Creation of the world", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Rulership of the afterlife", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Invention of writing", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 6
        v_strcpy(currentQuestion.question, "Which invention was introduced to Egypt by the Hyksos?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Iron weaponry", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Horse-drawn chariots", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Shadufs", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 7
        v_strcpy(currentQuestion.question, "The 22nd Dynasty was comprised of which usurping officials?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Overseers of the Necropolis", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Viziers of the South", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "High Priests of Amun", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 8
        v_strcpy(currentQuestion.question, "What was responsible for the death of Ramesses III?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "The Harem Conspiracy", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "The Battle of Kadesh", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Dental abscesses", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 9
        v_strcpy(currentQuestion.question, "Who discovered the tomb of Tutankhamun in 1922?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Zahi Hawass", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Howard Carter", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Kent Weeks", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 10
        v_strcpy(currentQuestion.question, "What was KV5 used for the burial of?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Apis bulls", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Akhenaten", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Sons of Ramesses II", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 11
        v_strcpy(currentQuestion.question, "Which king is credited with the unification of Egypt circa 3000 BCE?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Khufu", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Amenhotep", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Narmer", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 12
        v_strcpy(currentQuestion.question, "Which invaders were responsible for the end of the Middle Kingdom?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "The Hyksos", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "The Sea Peoples", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "The Libyans", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 13
        v_strcpy(currentQuestion.question, "How long was the reign of Pepi II in the Sixth Dynasty?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "67 years", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "94 years", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "110 years", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 14
        v_strcpy(currentQuestion.question, "Which city was the first capital of united Egypt?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Memphis", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Thebes", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Alexandria", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 15
        v_strcpy(currentQuestion.question, "Which god was held to be the creator deity during the New Kingdom?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Amun", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Ptah", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Osiris", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 16
        v_strcpy(currentQuestion.question, "The Ptolemaic dynasty blended which culture with the native Egyptian?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Roman", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Persian", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Greek", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 17
        v_strcpy(currentQuestion.question, "The discovery of which artifact led to the decipherment of hieroglyphs?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Scorpion Macehead", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Rosetta Stone", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Narmer Palette", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 18
        v_strcpy(currentQuestion.question, "What practice ended after the First Dynasty?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Pyramid building", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Retainer sacrifice", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Hieroglyphic writing", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 19
        v_strcpy(currentQuestion.question, "Which crown signifies rulership of Lower Egypt?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Hedjet", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Deshret", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Atef", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 20
        v_strcpy(currentQuestion.question, "What is the meaning of the name 'Kemet'?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Two Lands", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Red Land", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Black Land", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 21
        v_strcpy(currentQuestion.question, "Which king is credited with building the first pyramid?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Khufu", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Khasekhemwy", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Djoser", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 22
        v_strcpy(currentQuestion.question, "Which dynasty saw the temporary establishment of monotheistic religion?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Eighteenth", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Twenty-Fifth", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Thirtieth", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 23
        v_strcpy(currentQuestion.question, "Kings of which land ruled Egypt as the Twenty-Fifth Dynasty?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Persia", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Nubia", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Assyria", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 24
        v_strcpy(currentQuestion.question, "Who wrote the 'Aegyptiaca'?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Herodotus", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Ptolemy", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Manetho", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 25
        v_strcpy(currentQuestion.question, "Cleopatra VII committed suicide following whose death?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Mark Antony", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Julius Caesar", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Octavian", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 26
        v_strcpy(currentQuestion.question, "Mentuhotep II accomplished what in the Eleventh Dynasty?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Defeating the Sea Peoples", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Making peace with the Hittites", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Reuniting Egypt", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 27
        v_strcpy(currentQuestion.question, "Which period is also known as the Egyptian Empire?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Old Kingdom", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Middle Kingdom", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "New Kingdom", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 28
        v_strcpy(currentQuestion.question, "Which goddess was referred to as the Eye of Ra?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "Isis", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Ma'at", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Sekhmet", QUESLENGTH);
        currentQuestion.correctAnswer = 3;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 29
        v_strcpy(currentQuestion.question, "Where were the sacred Apis bulls buried?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "The Serapaeum", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "Valley of the Kings", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Memphis Necropolis", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // 30
        v_strcpy(currentQuestion.question, "When did the Arabs invade Egypt?", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "622 CE", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "641 CE", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "659 CE", QUESLENGTH);
        currentQuestion.correctAnswer = 2;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);
    // QuesInfo
        v_strcpy(currentQuestion.question, "Ancient Egypt", QUESLENGTH);
        v_strcpy(currentQuestion.option1, "ImperiusDamian", QUESLENGTH);
        v_strcpy(currentQuestion.option2, "imperiusdamian@gmail.com", QUESLENGTH);
        v_strcpy(currentQuestion.option3, "Created using the Veritas Quiz", QUESLENGTH);
        currentQuestion.correctAnswer = 1;
        quesFile.write((char*)&currentQuestion, sizeOfQuestion);

    closeFile(1);
}

//
// obtains and returns an option from the user
// used for menus and for answering questions
//
int Ques::getAnswer(std::string name, int maxAnswer)
{
        int answerGuess = 0;
        std::string inputAnswer;
        bool isValid;

        do
        {
            std::cout << " Please enter your answer, " << GREENTEXT << name << NORMALTEXT << ": ";
            getline(std::cin, inputAnswer);
            isValid = validInput(inputAnswer);
            if(isValid)
            {
                answerGuess = atoi(inputAnswer.c_str());
                isValid = (answerGuess >= 1 && answerGuess <= maxAnswer);
            }
            if(!isValid) std::cout << "Error: valid answer must be a number from " << CYANTEXT << "1" << NORMALTEXT << " to " << GREENTEXT << maxAnswer << NORMALTEXT << ". Please try again.\n";
        }
        while((!isValid));
        std::cout << "\n";

        return answerGuess;
} // end getAnswer()

//
// displays the main menu and gets user's choice
//
int Ques::mainMenu(std::string name)
{
        int menuOption = 0;
        int i = 0;
        std::string theMenu[MAXMENUOPTS] = {MENU1, MENU2, MENU3, MENU4, MENU5, MENULAST};

        titleLine();
        std::cout << std::endl << BUNCHASPACES << "MAIN MENU" << std::endl;
        std::cout << BUNCHASPACES << "=========" << std::endl;
        for(i = 0; i < MAXMENUOPTS; i++) std::cout << " " << GREENTEXT << i + 1 << NORMALTEXT << ": " << theMenu[i] << std::endl;
        std::cout << std::endl;
        menuOption = getAnswer(name, MAXMENUOPTS);

        return menuOption;
} // end mainMenu()

//
// displays a question
//
void Ques::showQuestion(quesInfo currQues, int i)
{
    titleLine();
    std::cout << std::endl << " Question " << i << " of " << MAXQUES << ":\n";
    std::cout << currQues.question  << std::endl << std::endl;
    std::cout << " 1: " << currQues.option1 << std::endl;
    std::cout << " 2: " << currQues.option2 << std::endl;
    std::cout << " 3: " << currQues.option3 << std::endl << std::endl;
} // end showQuestion()

//
// takes a file name and creates that file for writing to
// checks that file exists beforehand
//
int Ques::fileCreate(std::string fName)
{
    quesFile.open(fName, std::ios::in | std::ios::binary);
    if(quesFile.is_open()) return 1;

    quesFile.open(fName, std::ios::out | std::ios::trunc | std::ios::binary);
    if(!quesFile.is_open()) return 2;

    return 0;
}

//
// reads a question from the Quiz file and displays it
//
int Ques::displayQuestion(int x, int i, std::string name)
{
    bool fileError;
    int answerGuessed = 0;
    long filePosition;

    if(quesFile.is_open())
    {
        filePosition = x * sizeOfQuestion;
        fileError = (bool)quesFile.seekg(filePosition);
        fileError = (bool)quesFile.read((char*)&currentQuestion, sizeOfQuestion);
        if(fileError)
        {
            showQuestion(currentQuestion, i);
            answerGuessed = getAnswer(name, 3);

            if(answerGuessed == currentQuestion.correctAnswer) return 1; // end if()
        } // end if()
    }
    return 0;
} // end displayQuestion()

//
// reads the quiz subject for the score file
//
char* Ques::scoreSubject()
{
    bool fileError;
    int subjectPosition = 30 * sizeOfQuestion;

    if(quesFile.is_open())
    {
        fileError = (bool)quesFile.seekg(subjectPosition);
        fileError = (bool)quesFile.read((char*)&currentQuestion, sizeOfQuestion);
        if(fileError) return currentQuestion.question;
    } // end if
    return 0;
} // end scoreSubject()

//
// outputs list of high scores
//
void Ques::displayScore()
{
    titleLine();

    if(!scoreFile.is_open()) scoreFile.open((char*)SCOREFILENAME, std::ios::in | std::ios::binary);

    if(scoreFile.is_open())
    {
        std::cout << "\nCurrent High Scores\n===================\n\n";
        std::cout << "Player";
        outputChars(6, NAMELENGTH, ' ');
        std::cout << "Subject";
        outputChars(7, NAMELENGTH, ' ');
        std::cout << "Score\n";
        outputChars(0, 79, '=');
        std::cout << "\n";

        for(int i = 0; i < SCOREFILESIZE; i++)
        {
            scoreFile.read((char*)&currentHighScore, sizeOfScore);
            std::cout << GREENTEXT << currentHighScore.playerName << NORMALTEXT;
            outputChars(strlen(currentHighScore.playerName), NAMELENGTH, ' ');
            std::cout << currentHighScore.subject;
            outputChars(strlen(currentHighScore.subject), NAMELENGTH, ' ');
            std::cout << currentHighScore.highScore << std::endl;
        }
        closeFile(2);
    }
    std::cout << std::endl;
    pressEnter();
}

//
// closes a Quiz
//
void Ques::closeFile(int i)
{
    if(i == 1) quesFile.close(); else scoreFile.close();
}

//
// full Quiz-creation routine
//
int Ques::createQuiz(std::string name)
{
        std::string quizName;
        std::string promptName = name + ", what would you like to name your Quiz " + std::string(MAX32) + "? ";
        std::string inputAnswer;
        std::string buildString = std::string(VERITASQUIZ) + std::string(VERSION);
        int i;
        bool fileError;

        titleLine();
        std::cout << "Note: Names for Quizzes can only consist of letters and numbers. Spaces not allowed." << std::endl;
        quizName = getName(promptName, 1);

        std::transform(quizName.begin(), quizName.end(), quizName.begin(), ::tolower);

        fileError = fileCreate(quizName);
        if(fileError == 0)
        {
            std::cout << "New Quiz successfully created." << std::endl << "Now you can add the questions to the new Quiz." << std::endl << std::endl;
            pressEnter();
            for(i = 1; i <= MAXQUES; i++)
            {
                titleLine();
                std::cout << name << ", please enter question number " << i << " " << std::string(MAX80) << "." << std::endl;
                getline(std::cin, inputAnswer);
                v_strcpy(currentQuestion.question, inputAnswer.c_str(), QUESLENGTH);
                std::cout << std::endl << "Now please enter the first option for the answer " << std::string(MAX80) << "." << std::endl;
                getline(std::cin, inputAnswer);
                v_strcpy(currentQuestion.option1, inputAnswer.c_str(), QUESLENGTH);
                std::cout << std::endl << "Now please enter the second option for the answer " << std::string(MAX80) << "." << std::endl;
                getline(std::cin, inputAnswer);
                v_strcpy(currentQuestion.option2, inputAnswer.c_str(), QUESLENGTH);
                std::cout << std::endl << "Now please enter the third option for the answer " << std::string(MAX80) << "." << std::endl;
                getline(std::cin, inputAnswer);
                v_strcpy(currentQuestion.option3, inputAnswer.c_str(), QUESLENGTH);
                std::cout << std::endl << "Which of the three options is the correct answer (1-3)? ";
                getline(std::cin, inputAnswer);
                std::stringstream(inputAnswer) >> currentQuestion.correctAnswer;
                quesFile.write((char*)&currentQuestion, sizeOfQuestion);
            }
            titleLine();
            std::cout << "What is the subject of this Quiz " << MAX80 << "? ";
            getline(std::cin, inputAnswer);
            v_strcpy(currentQuestion.question, inputAnswer.c_str(), QUESLENGTH);
            v_strcpy(currentQuestion.option1, name.c_str(), QUESLENGTH);
            v_strcpy(currentQuestion.option2, buildString.c_str(), QUESLENGTH);
            v_strcpy(currentQuestion.option3, SHOULDNOT, QUESLENGTH);
            currentQuestion.correctAnswer = 1;
            quesFile.write((char*)&currentQuestion, sizeOfQuestion);
            closeFile(1);
            std::cout << name << ", you have successfully created your Quiz." << std::endl;
            pressEnter();
            return 0;
        }
        else return fileError;
}

//
// displays the user's score
//
void Ques::writeScore(int score, double scorePercentage, std::string name, char* fName)
{
        //quesInfo info;
        scoreInfo scores[SCOREFILESIZE];
        char* quizSubject;

        titleLine();
        std::cout << std::endl << "Final score: " << score << " of " << MAXQUES << "." << std::endl;
        std::cout << "That is " << std::setprecision(3) << scorePercentage << "%." << std::endl;
        if((int)scorePercentage >= 90) std::cout << "Awesome, you rocked it!" << std::endl << std::endl; // end if()

        if(quesFile.is_open()) closeFile(1);

        // test code to get quiz subject
        quesFile.open(fName, std::ios::in | std::ios::binary);
        quizSubject = scoreSubject();
//        while(quesFile)
//        {
//            quesFile.read((char*)&info, sizeOfQuestion);
//            std::cout << info.question << "\n";
//        }
//        pressEnter();
        closeFile(1);
        // end of test code

        if(!scoreFile.is_open()) scoreFile.open((char*)SCOREFILENAME, std::ios::in | std::ios::binary);
        scoreFile.read((char*)&currentHighScore, sizeOfScore);
        closeFile(2);

        if(score > currentHighScore.highScore)
        {
            currentHighScore.highScore = score;
            v_strcpy(currentHighScore.playerName, name.c_str(), NAMELENGTH);
            v_strcpy(currentHighScore.subject, quizSubject, NAMELENGTH);
            if(!scoreFile.is_open()) scoreFile.open((char*)SCOREFILENAME, std::ios::in | std::ios::out | std::ios::binary);
            scoreFile.write((char*)&currentHighScore, sizeOfScore);
            closeFile(2);
        }

        if(!scoreFile.is_open()) scoreFile.open((char*)SCOREFILENAME, std::ios::in | std::ios::binary);
        for(int i = 0; i < SCOREFILESIZE; i++)
        {
            scoreFile.read((char*)&currentHighScore, sizeOfScore);
            scores[i] = currentHighScore;
        }
        closeFile(2);

        std::sort(scores, scores + SCOREFILESIZE, scoreCompare);

        if(!scoreFile.is_open()) scoreFile.open((char*)SCOREFILENAME, std::ios::out | std::ios::trunc | std::ios::binary);
        for(int i = 0; i < SCOREFILESIZE; i++) scoreFile.write((char*)&scores[i], sizeOfScore);
        closeFile(2);

        pressEnter();
} // end writeScore()

//
// gets user name or a filename
//
std::string getName(std::string promptString, int isQuizFile)
{
        std::string name;
		std::string fileName;
		std::string fExt;

		titleLine();
        std::cout << std::endl << " " + promptString;
        if(isQuizFile == 0)
        {
			getline(std::cin, name);
            name[0] = toupper(name[0]);
            if(name.length() > NAMELENGTH) name.resize(NAMELENGTH);
	        return name;
        }
		else
		{
            getline(std::cin, fileName);
            size_t extPos = fileName.find_last_of(".");
            if(extPos != std::string::npos)
            {
                fExt = fileName.substr(extPos);
                if(fExt.length() > 0)
                {
                    for(unsigned int i = 0; i < fExt.length(); i++) fExt[i] = tolower(fExt[i]);
                }
            }
            else fExt = ".";
            if(fExt != ".qzp") fileName = fileName + ".qzp";
			return fileName;
		}
} // end getName()

//
// file extension handling
//
std::string getFileExtension(const std::string& inputFName)
{
    if(inputFName.find_last_of(".") != std::string::npos) return inputFName.substr(inputFName.find_last_of(".") + 1);

    return "";
} // end getFileExtension

//
// calculates score percentage
//
double scorePercent(int score)
{
    double percentage = 0.0f;
    percentage = ((double) score / MAXQUES) * 100.0f;

    return percentage;
} // end scorePercent()

//
// throws an error
//
void errorFile(int fileError)
{
    std::string fileString;

    if(fileError == 1) fileString = "File already exists"; else if(fileError == 2) fileString = "Error opening file";
    std::cout << std::endl << fileString << ". Please try again." << std::endl;
} // end errorFile()

//
// enter prompt
//
void pressEnter()
{
    std::string nullString;
    std::cout << PRESSENTER << std::endl;
    std::getline(std::cin, nullString);
} // end pressEnter()

//
// screen clearing, quick and dirty
//
void clrScrn()
{
    int erresult;

    erresult = system("cls");
    if (erresult)
    {
        erresult = system("clear");
        if(erresult)
        {
            std::cout << "Cannot clear screen.\n\n";
            pressEnter();
            for(int i = 0; i < 120; i++) std::cout << "\n"; // yes I know, bad practice, works in a pinch
        }
    }
} // end clrScrn()

//
// about screen
//
void showAbout()
{
    titleLine();
    std::cout << std::endl << ABOUT1 << std::endl;
    std::cout << ABOUT2 << std::endl;
    std::cout << std::endl << COPYRIGHT << std::endl << std::endl;
    pressEnter();
} // end showAbout()

//
// quiz title
//
void titleLine()
{
    clrScrn();
    std::cout << "\n                Veritas Test: " << VERSION << "; Build Date " << BUILDDATE << "\n\n";
} // end titleLine()

size_t v_strcpy(char *dst, const char *src, size_t size)
{
    size_t len = 0;

    while(size > 1 && *src)
    {
        *dst++ = *src++;
        size--;
        len++;
    }

    if(size > 0) *dst = 0;

    return len + strlen(src);
} // end v_strcpy()

//
// writes a specific character to screen a specific number of times
//
void outputChars(int i, int j, const char c)
{
    j++;
    for(int x = i; x <= j; x++) std::cout << c;
} // end outputChars()

//
// compare current user's score to high recorded score for subject
//
bool scoreCompare(scoreInfo s1, scoreInfo s2)
{
    return(s1.highScore < s2.highScore);
} // end scoreCompare()

//
// does user want to quit or no
//
bool returnToMenu()
{
    std::string yesOrNo = "";
    clrScrn();
    std::cout << " Display main menu " << buildYNString();
    getline(std::cin, yesOrNo);
    if(yesOrNo == "N" || yesOrNo == "n") return false;
    return true;
} // end returnToMenu()

//
// builds the current version string
//
char* buildVerString()
{
    char* verString = (char*)"";

    strcat(verString, VERITASQUIZ);
    strcat(verString, VERSION);

    return verString;
}

char* buildYNString()
{
    char* yNString = (char*)"(";

    strcat(yNString, GREENTEXT);
    strcat(yNString, "Y");
    strcat(yNString, NORMALTEXT);
    strcat(yNString, "/");
    strcat(yNString, GREENTEXT);
    strcat(yNString, "N");
    strcat(yNString, NORMALTEXT);
    strcat(yNString, "; N will quit)? ");

    return yNString;
}

//
// ensures user input is a valid number as opposed to strings etc
//
bool validInput(std::string enteredAnswer)
{
    for(char c : enteredAnswer)
    {
        if(!isdigit(c)) return false;
    }
    return true;
}
