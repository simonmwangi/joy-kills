#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"

#define DefaultNoOfUnits 8

struct studentInfo {
    char studentName[23];
    char studentId[12];
    char courseName[50];

    struct CourseUnits
    {
        char unitName[20];
        int unitMarks;
      //  int unitChecker; //0 is for failed 1 for passed  and 2 for deferred
      //  char unitStatus[10]; //Shows if the unit was deferred, passed or failed
    }LeastScored,HighestScored;



        //int leastScored;
        //char leastScoredName[20];
        int noOfUnits;  //this are those units that he had done during the exam
        int totalMarks;
        int overallPercentage;
        int overallAverage;
        char grade[10];

};
/*
struct LeastScored
    {
        char name[20];
        int marks;
    };

    struct HighestScored
    {
        char name[10];
        int marks;
    };
*/

struct studentInfo theStudent[4];
struct CourseUnits theUnit[7] , LeastScored , HighestScored;


void EnterStudentDetails()
{
    //
    int StudentsNo =0;


    //To store the values entered for each unit in the for loop
    int marks =0;
    bool finished = false;
    while(finished == false)
    {
        //The special no is just the number of the student in the array theStudent ****
        printf("Your special no for accessing your results is: %d \n", StudentsNo);
        printf("Enter student name: \t");
        scanf("%s[^\n]", &theStudent[StudentsNo].studentName);
        printf("Enter the students school Id: \t");
        scanf("%s", &theStudent[StudentsNo].studentId);
        printf("Enter the student's current course: \t");
        scanf("%s", &theStudent[StudentsNo].courseName);
        printf("How many units did the student sit for during the exam? \n ");
        scanf("%d", &theStudent[StudentsNo].noOfUnits);

        int deferredUnits = DefaultNoOfUnits - theStudent[StudentsNo].noOfUnits;


        ///Calculate the no of deferred units and award each deferred unit with 0
        if(theStudent[StudentsNo].noOfUnits < DefaultNoOfUnits)
        {
            printf("It seems that the student missed some unit(s) during the exam \n");
            printf("Please enter the deferred units below \n");



            int i;
            for(i = 0; i < deferredUnits; i++)
            {
            printf("Enter unit name: \t");
            scanf("%s", theUnit[i].unitName);
            //The default mark for a deferred unit is 0
            theUnit[i].unitMarks = 0;
            }
            printf("That's All Now Continue To Enter Those He/She Completed \n");
        }

        printf("***Now enter the name and marks for the respective units*** \n");

        ///Let the user now enter the remaining units that the student completed
        int i;
        for(i=deferredUnits;i< DefaultNoOfUnits; i++)
        {

            printf("Enter unit name: \t");
            scanf("%s", theUnit[i].unitName);
            printf("Enter the marks for the unit: \t");
            scanf("%d", &theUnit[i].unitMarks);
            //Add marks for all the units the student is doing
            marks += theUnit[i].unitMarks;

        }

        //Store the value from marks var in theUnits for loop to theStudent's location in the array
        theStudent[StudentsNo].totalMarks = marks;
        //Calculate the average for the specific student
        theStudent[StudentsNo].overallAverage = (theStudent[StudentsNo].totalMarks)/ DefaultNoOfUnits ;


    ///Local Var test of type int for holding the unit Marks that were entered above
    int test[8];
    int a=0;
    while(a < 8)
    {
        test[a] = theUnit[a].unitMarks;
        printf("Entered TEsts is: %d and is at location: %d \n",test[a], a);
        a++;
    }
        ///Calculate Highest Scored Unit********************************************************
        int highestScored;
        if(test[0] == test[0] && test[0] > test[1] && test[0] > test[2] && test[0] > test[3] && test[0] > test[4] && test[0] > test[5] && test[0] > test[6] && test[0] > test[7])
               {
                   HighestScored = theUnit[0];
                printf("The highest scored unit was: %s", theUnit[0].unitName);
                highestScored = theUnit[0].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (test[1] > test[0] && test[1] == test[1] && test[1] > test[2] && test[1] > test[3] && test[1] > test[4] && test[1] > test[5] && test[1] > test[6] && test[1] > test[7])
            {
                HighestScored = theUnit[1];
                printf("The highest scored unit was: %s", theUnit[1].unitName);
                highestScored = theUnit[1].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (test[2] > test[0] && test[2] > test[1] && test[2] == test[2] && test[2] > test[3] && test[2] > test[4] && test[2] > test[5] && test[2] > test[6] && test[2] > test[7])
            {
                HighestScored = theUnit[2];
                printf("The highest scored unit was: %s", theUnit[2].unitName);
                highestScored = theUnit[2].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (test[3] > test[0] && test[3] > test[1] && test[3] > test[2] && test[3] == test[3] && test[3] > test[4] && test[3] > test[5] && test[3] > test[6] && test[3] > test[7])
            {
                HighestScored = theUnit[3];
                printf("The highest scored unit was: %s", theUnit[3].unitName);
                highestScored = theUnit[3].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (theUnit[4].unitMarks > theUnit[0].unitMarks && theUnit[4].unitMarks > theUnit[1].unitMarks && theUnit[4].unitMarks > theUnit[2].unitMarks && theUnit[4].unitMarks > theUnit[3].unitMarks && theUnit[4].unitMarks == theUnit[4].unitMarks && theUnit[4].unitMarks > theUnit[5].unitMarks && theUnit[4].unitMarks > theUnit[6].unitMarks && theUnit[4].unitMarks > theUnit[7].unitMarks)
            {
                HighestScored = theUnit[4];
                printf("The highest scored unit was: %s", theUnit[4].unitName);
                highestScored = theUnit[4].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (theUnit[5].unitMarks > theUnit[0].unitMarks && theUnit[5].unitMarks > theUnit[1].unitMarks && theUnit[5].unitMarks > theUnit[2].unitMarks && theUnit[5].unitMarks > theUnit[3].unitMarks && theUnit[5].unitMarks > theUnit[4].unitMarks && theUnit[5].unitMarks == theUnit[5].unitMarks && theUnit[5].unitMarks > theUnit[6].unitMarks && theUnit[5].unitMarks > theUnit[7].unitMarks)
            {
                HighestScored = theUnit[5];
                printf("The highest scored unit was: %s", theUnit[5].unitName);
                highestScored = theUnit[5].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (theUnit[6].unitMarks > theUnit[0].unitMarks && theUnit[6].unitMarks > theUnit[1].unitMarks && theUnit[6].unitMarks > theUnit[2].unitMarks && theUnit[6].unitMarks > theUnit[3].unitMarks && theUnit[6].unitMarks > theUnit[4].unitMarks && theUnit[6].unitMarks > theUnit[5].unitMarks && theUnit[6].unitMarks == theUnit[6].unitMarks && theUnit[6].unitMarks > theUnit[7].unitMarks)
            {
                HighestScored = theUnit[6];
                printf("The highest scored unit was: %s", theUnit[6].unitName);
                highestScored = theUnit[6].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
        else if (theUnit[7].unitMarks > theUnit[0].unitMarks && theUnit[7].unitMarks > theUnit[1].unitMarks && theUnit[7].unitMarks > theUnit[2].unitMarks && theUnit[7].unitMarks > theUnit[3].unitMarks && theUnit[7].unitMarks > theUnit[4].unitMarks && theUnit[7].unitMarks > theUnit[5].unitMarks && theUnit[7].unitMarks > theUnit[6].unitMarks && theUnit[7].unitMarks == theUnit[7].unitMarks)
            {
                HighestScored = theUnit[7];
                printf("The highest scored unit was: %s", theUnit[7].unitName);
                highestScored = theUnit[7].unitMarks;
                printf("%d", highestScored);
                printf("\n");
            }
            ///*************************************************************Calculate The Highest Scored Unit End


            ///Calculate The Least Scored Unit*******************************************************************
            int leastScored;

            //We are gonna cheat the system a bit due to an unexplainable error where least scored unit is calculated
            //when the user enters deferred units into the system
            if(test[0] == 0)
            {
                LeastScored = theUnit[0];
                printf("The least scored unit was: %s", theUnit[0].unitName);
                leastScored = test[0];

            }
            else
            {
                if(test[0] == test[0] && test[0] < test[1] && test[0] < test[2] && test[0] < test[3] && test[0] < test[4] && test[0] < test[5] && test[0] < test[6] && test[0] < test[7])
                    {
                        LeastScored = theUnit[0];
                printf("The least scored unit was: %s", theUnit[0].unitName);
                leastScored = theUnit[0].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[1] < test[0] && test[1] == test[1] && test[1] < test[2] && test[1] < test[3] && test[1] < test[4] && test[1] < test[5] && test[1] < test[6] && test[1] < test[7])
                    {
                        LeastScored = theUnit[1];
                printf("The least scored unit was: %s", theUnit[1].unitName);
                leastScored = theUnit[1].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[2] < test[0] && test[2] < test[1] && test[2] == test[2] && test[2] < test[3] && test[2] < test[4] && test[2] < test[5] && test[2] < test[6] && test[2] < test[7])
                    {
                        LeastScored = theUnit[2];
                printf("The least scored unit was: %s", theUnit[2].unitName);
                leastScored = theUnit[2].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[3] < test[0] && test[3] < test[1] && test[3] < test[2] && test[3] == test[3] && test[3] < test[4] && test[3] < test[5] && test[3] < test[6] && test[3] < test[7])
                    {
                        LeastScored = theUnit[3];
                printf("The least scored unit was: %s", theUnit[3].unitName);
                leastScored = theUnit[3].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[4] < test[0] && test[4] < test[1] && test[4] < test[2] && test[4] < test[3] && test[4] == test[4] && test[4] < test[5] && test[4] < test[6] && test[4] < test[7])
                    {
                        LeastScored = theUnit[4];
                printf("The least scored unit was: %s", theUnit[4].unitName);
                leastScored = theUnit[4].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[5] < test[0] && test[5] < test[1] && test[5] < test[2] && test[5] < test[3] && test[5] < test[4] && test[5] == test[5] && test[5] < test[6] && test[5] < test[7])
                    {
                        LeastScored = theUnit[5];
                printf("The least scored unit was: %s", theUnit[5].unitName);
                leastScored = theUnit[5].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[6] < test[0] && test[6] < test[1] && test[6] < test[2] && test[6] < test[3] && test[6] < test[4] && test[6] < test[5] && test[6] == test[6] && test[6] < test[7])
                    {
                        LeastScored = theUnit[6];
                printf("The least scored unit was: %s", theUnit[6].unitName);
                leastScored = theUnit[6].unitMarks;
                printf("%d", leastScored);
                printf("\n");
            }
                else if (test[7] < test[0] && test[7] < test[1] && test[7] < test[2] && test[7] < test[3] && test[7] < test[4] && test[7] < test[5] && test[7] < test[6] && test[7] == test[7])
                    {
                        LeastScored = theUnit[7];
                printf("The least scored unit was: %s", theUnit[7].unitName);
                //leastScored = theUnit[7].unitMarks;
                printf("%d", leastScored);
                printf("\n");
                }
            }


            ///******************************************************************Calculate Least Scored Unit End

        //If for Grades
        int avg = theStudent[StudentsNo].overallAverage;
        char grade[6];

        if(avg > 70)
        {
            strcpy(theStudent[StudentsNo].grade, "A");
            //theStudent[StudentsNo].grade = grade;
            //printf("The student's grade is: %s", grade);
            printf("\n");
        }
        else if (avg > 60)
        {
            strcpy(theStudent[StudentsNo].grade, "B");
            //theStudent[StudentsNo].grade = grade;
            //printf("The student's grade is: %s", grade);
            printf("\n");
        }
        else if (avg > 50)
        {
            strcpy(theStudent[StudentsNo].grade, "C");
            //theStudent[StudentsNo].grade = grade;
            //printf("The student's grade is: %s", grade);
            printf("\n");
        }
        else if (avg > 40)
        {
            strcpy(theStudent[StudentsNo].grade, "D");
            //theStudent[StudentsNo].grade = grade;
            //printf("The student's grade is: %s", grade);
            printf("\n");
        }
        else if (avg > 0)
        {
            strcpy(theStudent[StudentsNo].grade, "Fail");
            //grade = theStudent[StudentsNo].grade;
            //theStudent[StudentsNo].grade = grade;
            //printf("The student's grade is: %s", grade);
            printf("\n");
        }




            //We need to reset the marks var for the next student's marks so as to avoid adding marks from the previous student
            marks =0;


        /////////////////////////
        setColor(YELLOW);
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<STUDENT RESULT SLIP>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
        printf("************************************************************************************* \n");
        setColor(WHITE);
        printf("Student Name: \t %s \n", theStudent[StudentsNo].studentName);
        printf("Student Id: \t %s \n", theStudent[StudentsNo].studentId);
        printf("Course Name: \t %s \n", theStudent[StudentsNo].courseName);

        printf("************************************************************************************* \n");
        printf("\n");
        printf("Units in the course::>> \n 0 in any marks for a unit means the unit was not completed. \n ");
        for(i=0; i< DefaultNoOfUnits; i++)
        {
            printf("Unit Name: \t %s \n", theUnit[i].unitName);
            printf("Unit Marks: \t %d \n", theUnit[i].unitMarks);
            printf("\n");
        }
        printf("************************************************************************************* \n");
        printf("\n");

        setColor(GREEN);
        printf("Highest Scored Unit was: %s with %d marks \n", HighestScored.unitName , HighestScored.unitMarks);
        setColor(RED);
        printf("Least Scored Unit was: %s with %d marks \n", LeastScored.unitName , LeastScored.unitMarks);

        setColor(WHITE);
        printf("************************************************************************************* \n");
        printf("\n");

        printf("Total Marks for the Course>>> \t %d \n", theStudent[StudentsNo].totalMarks);
        printf("Average for the Course>>>> \t %d \n", theStudent[StudentsNo].overallAverage);
        printf("Final Grade>>> \t %s \n", theStudent[StudentsNo].grade );

        setColor(YELLOW);
        printf("************************************************************************************* \n");
        printf("\n");
        printf("<<<<<<<<<<<<<<<<<<<<<<<<STUDENT RESULT SLIP END>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");



        //Increment studentNo for the next data to be entered
        StudentsNo ++;

        setColor(GREEN);
        int EnterMarks;
            printf("Do you wish to enter another student's marks??\n Enter 1 for Yes and 2 for No");
            scanf("%d", &EnterMarks);
            if(EnterMarks == 2)
            {
                break;
            }

    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    //printf("1: Unit 1 for student 1 %s", theStudent[1].unitName);
    //printf("1: %d \n", theStudent[0].totalMarks);
    //printf("%d \n", theStudent[0].overallAverage);
    //printf("2: %d \n", theStudent[1].totalMarks);
    //printf("%d \n", theStudent[1].overallAverage);
    //theUnits[i].overallPercentage = (float)((float)theUnits[i].totalMarks/(float)500)*100;
    //printf("Displaying Entered Names \n");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

}

int main()
{
    setColor(WHITE);
    EnterStudentDetails();


    return 0;
}
