/**********************************
* Автор: Калинин Андрей           *
* Лабораторная №6                 *
* Дата: 25.10.2023                *
* Название:Работа с  файлами      *
* Вариант: 7                      *
* https://onlinegdb.com/zlo8frfq8 *
**********************************/

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

int lineCount (string fileName) {
  int lineCounter = 0;
  
  ifstream lineCount (fileName);
  
  if (!lineCount.is_open ()) {
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


//This function do all work.  I created this, because it can be used two or more time.

void baseOfStudents (int counter, string fileName) {
  
  int firstNumber;
  int secondNumber;
  int thirdNumber;
  int minimum = 10;
  double studentAverageScore;
  char temp[30];
  struct student studentsArray[100];
  
  ifstream studentsFile (fileName);

  if (!studentsFile.is_open ())
    {
      printf ("Error: file does not open\n");
    } else {
      printf ("File open\n");
      for (int studentIndex = 0; studentIndex < counter; ++studentIndex) {
	    studentsFile.getline (temp, 30, ' ');
	    sscanf (temp, "%s", studentsArray[studentIndex].studentSecondName);
	    
	    if (studentsArray[studentIndex].studentSecondName == "") {
	      break;  
	    }
	    
		studentsFile.getline (temp, 30, ' ');
	    sscanf (temp, "%s", studentsArray[studentIndex].studentFirstName);
	    
	    studentsFile.getline (temp, 3, ' ');
	    sscanf (temp, "%s", studentsArray[studentIndex].studentClass);
	    
	    studentsFile.getline (temp, 2, ' ');
	    sscanf (temp, "%s", studentsArray[studentIndex].studentHistoryScore);
	    firstNumber = atoi(studentsArray[studentIndex].studentHistoryScore); // atoi = Char to integer
	    
	    studentsFile.getline (temp, 2, ' ');
	    sscanf (temp, "%s", studentsArray[studentIndex].studentMathScore);
	    secondNumber = atoi(studentsArray[studentIndex].studentMathScore);
	    
	    studentsFile.getline (temp, 2);
	    sscanf (temp, "%s", studentsArray[studentIndex].studentPhysicsScore);
	    thirdNumber = atoi(studentsArray[studentIndex].studentPhysicsScore);
	    
	    studentsArray[studentIndex].studentAverageScore = (firstNumber + secondNumber + thirdNumber) / 3;
	    
	    printf ("%s %s %s %s %s %s %3.2lf \n",  studentsArray[studentIndex].studentSecondName,
	    studentsArray[studentIndex].studentFirstName, studentsArray[studentIndex].studentClass, 
	    studentsArray[studentIndex].studentHistoryScore, studentsArray[studentIndex].studentMathScore,
	    studentsArray[studentIndex].studentPhysicsScore, studentsArray[studentIndex].studentAverageScore);
	    
	    if (studentsArray[studentIndex].studentAverageScore < minimum) {
	      minimum = studentsArray[studentIndex].studentAverageScore;   
	    }
	    
	  }
	  
	  for (int lowScoreIndex = 0; lowScoreIndex < counter; ++lowScoreIndex) {
	    if (studentsArray[lowScoreIndex].studentAverageScore == minimum) {
	     printf("Most failing student: %s %s \n", studentsArray[lowScoreIndex].studentSecondName,
	     studentsArray[lowScoreIndex].studentFirstName);   
	    }
	    
	  }
	  
      studentsFile.close();
    }
    
}

int main () {
  int counterMain = 0;
  string fileName;

  cout << "Name of file: ";
  cin >> fileName;
  
  counterMain = lineCount(fileName);
  if (counterMain == -1) {
    printf ("File does not open or found");
    return -1;
  }
  
  baseOfStudents(counterMain, fileName);

  return 0;
}
