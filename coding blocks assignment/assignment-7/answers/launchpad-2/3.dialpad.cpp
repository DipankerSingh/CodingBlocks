 // Using the phone keypad return all possible words that can be produced given input digits
#include<iostream>
using namespace std;
int possibleWords(int i,char output[][100])
{
    char input[4];
    if(i==0)

    {
        output[0][0]='\0';
        return 1;
    }
    int digit=i%10;
    switch (digit)
    {
    case 2:
        input[0]='a';
        input[1]='b';
        input[2]='c';
        break;
    case 3:
        input[0]='d';
        input[1]='e';
        input[2]='f';
        break;
    case 4:
        input[0]='g';
        input[1]='h';
        input[2]='i';
        break;
    case 5:
        input[0]='j';
        input[1]='k';
        input[2]='l';
        break;
    case 6:
        input[0]='m';
        input[1]='n';
        input[2]='o';
        break;
    case 7:
        input[0]='p';
        input[1]='q';
        input[2]='r';
        input[3]='s';
        break;
    case 8:
        input[0]='t';
        input[1]='u';
        input[2]='v';
        break;
    case 9:
        input[0]='w';
        input[1]='x';
        input[2]='y';
        input[3]='z';
        break;
    default:
        return -1;
        break;
    }





    int numberOfRows=possibleWords(i/10,output);
    char temp[100][100];
    for(int i=0;i<numberOfRows;i++)
    {

        int j=0;
        do
        {
            temp[i][j] =output[i][j];
            j++;
        }
        while(output[i][j] != '\0');


		temp[i][j] = '\0';

    }


    for(int k=0;k<(digit==7||digit==9?4:3);k++)
    {
    for(int i=0;i<numberOfRows;i++)
    {
        // output[i+(k*numberOfRows)][0]=input[k];
        int j=0;
        do
        {
            output[i+(k*numberOfRows)][j+1] =temp[i][j];
            j++;
        }
        while(output[i+(k*numberOfRows)][j] != '\0');



		output[i+(k*numberOfRows)][0]=input[k];
    }

    }


	if(digit==7 || digit==9)
	return 4*numberOfRows;
	else
    return 3*numberOfRows;
}
int main()
{
    int i;
    cin>>i;
    char output[100][100];
    int numberOfRows=possibleWords(i,output);

    for (int j= 0; j < numberOfRows; j++) {
		cout << output[j] << endl;
	}
}
