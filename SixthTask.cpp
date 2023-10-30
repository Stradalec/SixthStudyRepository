/*************************************
* Автор: Калинин Андрей              *
* Лабораторная №6                    *
* Дата: 25.10.2023                   *
* Название:Работа с  файлами         *
* Вариант: 7                         *
* https://onlinegdb.com/tXL_R18Dd    *
*************************************/

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

struct student
{
  char studentSecondName[30];
  char studentFirstName[30];
  char studentClass[3];
  char studentHistoryScore[2];
  char studentMathScore[2];
  char studentPhysicsScore[2];
  double studentAverageScore;
};

using namespace std;

//This function help next function work (Gettign string count)

int lineCount(string fileName) {
  int lineCounter = 0;

  ifstream lineCount(fileName);

  if (!lineCount.is_open()) {
    return -1;
  }

  while (!lineCount.eof()) { //.eof = end of the file, reading until end of the file
    string countTemp;
    getline(lineCount, countTemp);
    ++lineCounter;
  }

  lineCount.close();

  return lineCounter;
}


int main() {

  string firstCrutch = "Most failing student: ";
  string secondCrutch = " ";
  int firstNumber;
  int secondNumber;
  int thirdNumber;
  int minimum = 10;
  double studentAverageScore;
  char temp[30];
  struct student studentsArray[100];
  int counterMain = 0;
  string firstFileName;
  string secondFileName;

  cout << "Name of input file: ";
  cin >> firstFileName;
  cout << "Name of output file: ";
  cin >> secondFileName;

  counterMain = lineCount(firstFileName);
  if (counterMain == -1) {
    printf("File does not open or found");
    return -1;
  }


  ifstream studentsFile(firstFileName);

  if (!studentsFile.is_open() ) {
    printf("Error: file does not open\n");
  } else {
    for (int studentIndex = 0; studentIndex < counterMain; ++studentIndex) {
      studentsFile.getline(temp, 30, ' ');
      sscanf(temp, "%s", studentsArray[studentIndex].studentSecondName);

      studentsFile.getline(temp, 30, ' ');
      sscanf(temp, "%s", studentsArray[studentIndex].studentFirstName);

      studentsFile.getline(temp, 3, ' ');
      sscanf(temp, "%s", studentsArray[studentIndex].studentClass);

      studentsFile.getline(temp, 2, ' ');
      sscanf(temp, "%s", studentsArray[studentIndex].studentHistoryScore);
      firstNumber = atoi(studentsArray[studentIndex].studentHistoryScore); // atoi = Char to integer

      studentsFile.getline(temp, 2, ' ');
      sscanf(temp, "%s", studentsArray[studentIndex].studentMathScore);
      secondNumber = atoi(studentsArray[studentIndex].studentMathScore);

      studentsFile.getline(temp, 2);
      sscanf(temp, "%s", studentsArray[studentIndex].studentPhysicsScore);
      thirdNumber = atoi(studentsArray[studentIndex].studentPhysicsScore);

      studentsArray[studentIndex].studentAverageScore = (firstNumber + secondNumber + thirdNumber) / 3;

      printf("%s %s %s %s %s %s %3.2lf \n", studentsArray[studentIndex].studentSecondName,
             studentsArray[studentIndex].studentFirstName, studentsArray[studentIndex].studentClass,
             studentsArray[studentIndex].studentHistoryScore, studentsArray[studentIndex].studentMathScore,
             studentsArray[studentIndex].studentPhysicsScore, studentsArray[studentIndex].studentAverageScore);

    if (studentsArray[studentIndex].studentAverageScore < minimum) {
      minimum = studentsArray[studentIndex].studentAverageScore;
      }

    }

    for (int lowScoreIndex = 0; lowScoreIndex < counterMain; ++lowScoreIndex) {
      if (studentsArray[lowScoreIndex].studentAverageScore == minimum) {
        printf("Most failing student: %s %s \n", studentsArray[lowScoreIndex].studentSecondName,
        studentsArray[lowScoreIndex].studentFirstName);
      }

    }

  studentsFile.close();
  }

  ofstream studentsFileOutput(secondFileName, ios::out);

  if (!studentsFileOutput.is_open() ) {
    printf("Error: file does not open\n");
  } else {
    for (int studentIndex = 0; studentIndex < counterMain; ++studentIndex) {
      studentsFileOutput << studentsArray[studentIndex].studentSecondName;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << studentsArray[studentIndex].studentFirstName;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << studentsArray[studentIndex].studentClass;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << studentsArray[studentIndex].studentHistoryScore;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << studentsArray[studentIndex].studentMathScore;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << studentsArray[studentIndex].studentPhysicsScore;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << studentsArray[studentIndex].studentAverageScore;
      studentsFileOutput << secondCrutch;

      studentsFileOutput << endl;
    }

    for (int lowScoreIndex = 0; lowScoreIndex < counterMain; ++lowScoreIndex) {
      if (studentsArray[lowScoreIndex].studentAverageScore == minimum) {
        studentsFileOutput << firstCrutch;
        studentsFileOutput << studentsArray[lowScoreIndex].studentSecondName;
        studentsFileOutput << secondCrutch;
        studentsFileOutput << studentsArray[lowScoreIndex].studentFirstName;
      }

    }

  studentsFileOutput.close();
  }

    return 0;
}
