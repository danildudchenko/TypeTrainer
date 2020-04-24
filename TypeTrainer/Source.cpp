#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

void Game(char GeneratedArray[], char UserArray[], int n);
void Randomise(char arr[], int n);
void Print(char arr[], int n);
void UserEnter(char user[], char compuer[], int n);
void AnswerCheck(char user[], char compuer[], int n);
unsigned int checkTime = 0;

void main()
{
	srand(time(NULL));
	const int n = 49;
	char GeneratedArray[n];
	char UserArray[n];
	char UserAnswer;
	bool quit = true;
	cout << "RULES!!!!!\n1.Turn your caps on\n2.Press space where it is needed by ur own\n3.Input only symbols that u see\n4.All other buttons except suitable are incorrect";
	cout << "\n\n\nPress any key to start"; UserAnswer = getch();
	do
	{
		Game(GeneratedArray, UserArray, n);
		cout << "\n\n\nPress:\n\n q for quit \n\n n to try again"; UserAnswer = getch();
		switch (UserAnswer)
		{
		case 'q': quit = false; break;
		case 'Q': quit = false; break;
		case 'n': system("cls"); break;
		case 'N': system("cls"); break;
		default:system("cls"); break;
		}
	} while (quit == true);
}

void Game(char GeneratedArray[], char UserArray[], int n)
{
	Randomise(GeneratedArray, n);
	Print(GeneratedArray, n);
	UserEnter(UserArray, GeneratedArray, n);
	AnswerCheck(UserArray, GeneratedArray, n);
}
void Randomise(char arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		i % 5 == 4 ? arr[i] = ' ' : arr[i] = char((rand() % 25) + 65);
	}
}
void Print(char arr[], int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
	}
}
void UserEnter(char user[], char compuer[], int n)
{
	unsigned int start_time = clock();
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		user[i] = getch();
		if (user[i] != compuer[i])
		{
			cout << "\033[37;44m\033[1mX\033[0m";
		}
		else cout << user[i];
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	checkTime = search_time;
}
void AnswerCheck(char user[], char compuer[], int n)
{
	//number of correct answers
	int incorrect = 0, correct = 0;
	for (int i = 0; i < n; i++)
	{
		user[i] != compuer[i] ? incorrect++ : correct++;
	}
	cout << "\n\n\nNumber of correct answers: " << correct;
	cout << "\n\nNumber of mistakes: " << incorrect;
	//time
	int Sec = checkTime / 1000;
	int MSec = checkTime - (Sec * 1000);
	cout << "\n\nTotal time: " << Sec << "," << MSec << "Seconds";
	cout << "\n\nAvg symbols per seconds: " << double(n) / double(Sec);
	cout << "\n\nAvg correct symbols per seconds: " << double(correct) / double(Sec);
}