// Omar Hawash

/*
                                Implementing polynomials in C++

    this mini-project accepts a polynomial char array, and formats it to coefficents 
    and exponents  which  are  arranged to terms, to  process  the  folowing  needs:
    1- printing the polynomial in the correct format.
    2- calculate  the first & second derivative of the polyniomial, and  printing it
    as well.

    note:
        if you are running on windows, change "system ("clear")" to "system ("CLS")".
    
    sample run (1):
        // option "1" (insert new polynomial)
        // 6X^31+X^2+120X+21 , option "1" (go back to Menu)
        // option "2" outputs: 6X^31 + X^2 + 120X + 21, option "1" (go back to Menu)
        // option "3" outputs: 186X^30 + 2X + 120, option "1" (go back to Menu)
        // option "4" outputs: 5580X^29 + 2 , option "1" (go back to Menu)
        // option "0" exits the program.
*/

#include <iostream>
using namespace std;

// this function converts array of char to single integer.
int numberHandler(char number[100])
{
    int result = 0, numMulti = 1, gotNumber = 0;
    if (number[0] == '\0')
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {

            if ((number[i] >= 48 && number[i] <= 57) && !gotNumber)
            {
            }
            else if (gotNumber)
            {
                result += (((int)number[i]) - 48) * numMulti;
                numMulti = numMulti * 10;
                i = i - 2;
                if (i == -2)
                {
                    break;
                }
            }
            else if (number[i] == '\0')
            {
                gotNumber = 1;
                i = i - 2;
            }
        }

        return result;
    }
}

// this function erases the given char array.
void numberEraser(char *number)
{
    for (int i = 0; i < 100; i++)
        if (number[i] != '\0')
        {
            number[i] = '\0';
        }
        else
        {
            break;
        }
}

// this function erases the given integer array.
void numberEraser(int *number)
{
    for (int i = 0; i < 100; i++)
        if (number[i] != '\0')
        {
            number[i] = '\0';
        }
        else
        {
            break;
        }
}

// this function handles printing the polynomial.
void polyPrinter(int termCounter, char term, char *polyManipulation, int coE[], int exP[])
{

    for (int i = 0; i <= termCounter; i++)
    {
        if (exP[i] < 0)
        {
            i++;
        }
        else
        {
            if (coE[i] == 1 && exP[i] != 0)
            {
                cout << term;
            }
            else if (coE[i] == 0)
            {
            }
            else if (exP[i] != 0)
            {
                cout << coE[i] << term;
            }
            else if (coE[i] != 0)
            {
                cout << coE[i];
            }
            else
            {
                cout << "??";
            }

            if (exP[i] == 1)
            {
                cout << " " << polyManipulation[i + 1] << " ";
            }
            else if (exP[i] == 0)
            {
                cout << " " << polyManipulation[i + 1] << " ";
            }
            else if (exP[i] != 0 && exP[i] != 1)
            {
                cout << "^" << exP[i] << " " << polyManipulation[i + 1] << " ";
            }
            else
            {
                cout << "??";
            }
        }
    }
    cout << endl;
}

//this function computes the 1st or 2nd derivative of the given polynomial.
void calculateDerivative(int deUnit, int termCounter, char term, char *polyManipulation, int coE[], int exP[])
{
    char polyManipulationD[100];
    int coED[100], exPD[100];

    if (deUnit == 1 || deUnit == 0)
    {

        for (int i = 0; i <= termCounter; i++)
        {
            if (((exP[i] - deUnit) <= 0))
            {
                coED[i] = 0;
                exPD[i] = exP[i] - (1 + deUnit);
                polyManipulationD[i] = '\0';
            }
            else if ((exP[i] - deUnit) == 1)
            {
                exPD[i] = 0;
                if (deUnit == 1)
                {
                    coED[i] = coE[i] * exP[i];
                }
                else if (deUnit == 0)
                {
                    coED[i] = coE[i];
                }
                polyManipulationD[i] = polyManipulation[i];
            }
            else if ((exP[i] - deUnit) > 1)
            {
                exPD[i] = exP[i] - (1 + deUnit);
                if (deUnit == 1)
                {
                    coED[i] = ((coE[i] * exP[i]) * (exP[i] - 1));
                }
                else if (deUnit == 0)
                {
                    coED[i] = coE[i] * exP[i];
                }
                polyManipulationD[i] = polyManipulation[i];
            }
            else
            {
                cout << "wrong format!";
                break;
            }
        }
        polyPrinter(termCounter, term, polyManipulationD, coED, exPD);
    }
    else
    {
        cout << "derivative unvalid.";
    }
}


int main()
{
    system("clear");
    char poly[100];
    char term = 'X', polyManipulation[100], number[100];
    int coE[100], exP[100], termCounter = 0, coECounter = 0, exPCounter = 0, numberHowMany = 0;
    int cont,menuV;
    
    //looping through the menu for user input
    for (int menu = 0; menu < 100; menu++)
    {
        cout << "Select one of the folowing:\n [1] Insert new polynomial.\n [2] Print polynomial.\n [3] Compute 1st derivative.\n [4] Compute 2nd derivative.\n [0] Exit program.\n\n";
        cin >> menuV;
        system("clear");
        if (menuV == 1) // this manages the given polynomial and arranges in the proper way.
        {
            int exitCode=1;
            if (poly[0] != '\0')
            {
                termCounter = 0;
                term = 'X';
                coECounter = 0;
                exPCounter = 0;
                numberHowMany = 0;
                numberEraser(poly);
                numberEraser(polyManipulation);
                numberEraser(coE);
                numberEraser(exP);
            }
            cout << "enter polynomial:(e.g. 6X^31+X^2+120X+21)\n";
            cin >> poly;
            for (int polyPtr = 0; polyPtr < 100; polyPtr++)
            {
                if (poly[polyPtr] >= 48 && poly[polyPtr] <= 57)
                {
                    number[numberHowMany] = poly[polyPtr];
                    numberHowMany++;
                }
                else if ((poly[polyPtr] >= 65 && poly[polyPtr] <= 90) || (poly[polyPtr] >= 97 && poly[polyPtr] <= 122))
                {
                    if (poly[polyPtr] == term)
                    {
                        coE[termCounter] = numberHandler(number);
                        coECounter++;
                        numberEraser(number);
                        numberHowMany = 0;
                    }
                    else
                    {
                        exitCode=0;
                        cout << "Wrong format!\n";
                        break;
                    }
                }
                else if (poly[polyPtr] == '^')
                {
                }
                else if ((poly[polyPtr] == '+' || poly[polyPtr] == '-') || (poly[polyPtr] == '\0' && ((poly[polyPtr - 1] >= 48 && poly[polyPtr - 1] <= 57) || (poly[polyPtr - 1] >= 65 && poly[polyPtr - 1] <= 90))))
                {
                    if (coE[termCounter])
                    {
                        exP[termCounter] = numberHandler(number);
                        exPCounter++;
                    }
                    else
                    {
                        coE[termCounter] = numberHandler(number);
                        exP[termCounter] = 0;
                        coECounter++;
                        exPCounter++;
                    }
                    numberEraser(number);
                    polyManipulation[termCounter + 1] = poly[polyPtr];
                    numberHowMany = 0;
                    if (poly[polyPtr] == '+' || poly[polyPtr] == '-')
                    {
                        termCounter++;
                    }
                }
                else if (poly[polyPtr] == '\0')
                {
                    cout << "end of polynomial at " << polyPtr << endl;
                    if (coECounter == 0 && exPCounter == 0)
                    {
                        cout << "thats not a poly!";
                        exitCode=0;
                    }
                    else if (coECounter == exPCounter)
                    {
                        cout << "successfull!\n";
                    }
                    else
                    {
                        cout << "Wrong format!\n";
                        exitCode=0;
                    }
                    break;
                }
            }
            if(exitCode){
                system("clear");
            }else{
                cout << "no polynomial inserted!\n";
                break;
            }
        }
        else if (menuV == 2) // this prints the polynomial if already given.
        {
            if (poly[0] == '\0')
            {
                cout << "no polynomial inserted!\n";
            }
            else
            {
                polyPrinter(termCounter, term, polyManipulation, coE, exP);
                cout << "[1] Go back to Main Menu.\n[0] Exit program.\n\n";
                cin >> cont;
                if (cont == 0)
                {
                    break;
                }
                else if (cont == 1)
                {
                    system("clear");
                }
                else
                {
                    cout << "NOT AVAILABLE!\n\n";
                }
            }
        }
        else if (menuV == 3) // this computes the 1st derivative and prints it
        {
            if (poly[0] == '\0')
            {
                cout << "no polynomial inserted!\n";
            }
            else
            {
                cout << "Polynomial: ";
                polyPrinter(termCounter, term, polyManipulation, coE, exP);
                cout << "First derivative: ";
                calculateDerivative(0, termCounter, term, polyManipulation, coE, exP);

                cout << "\n\n[1] Go back to Main Menu.\n[0] Exit program.\n\n";
                cin >> cont;
                if (cont == 0)
                {
                    break;
                }
                else if (cont == 1)
                {
                    system("clear");
                }
                else
                {
                    cout << "NOT AVAILABLE!\n\n";
                }
            }
        }
        else if (menuV == 4) // this computes the 2nd derivative and prints it
        {
            if (poly[0] == '\0')
            {
                cout << "no polynomial inserted!\n";
            }
            else
            {
                cout << "Polynomial: ";
                polyPrinter(termCounter, term, polyManipulation, coE, exP);
                cout << "Second derivative: ";
                calculateDerivative(1, termCounter, term, polyManipulation, coE, exP);

                cout << "\n\n[1] Go back to Main Menu.\n[0] Exit program.\n\n";
                cin >> cont;
                if (cont == 0)
                {
                    break;
                }
                else if (cont == 1)
                {
                    system("clear");
                }
                else
                {
                    cout << "NOT AVAILABLE!\n\n";
                }
            }
        }
        else if (menuV == 0) // this is the program exit statment
        {
            cout << "\n\nYour program ended!\n\n";
            break;
        }
        else
        {
            cout << "NOT AVAILABLE!\n\n";
        }
    }

    return -1;
}