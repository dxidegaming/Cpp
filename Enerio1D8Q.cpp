#include <iostream>
#include <cstdlib>
using namespace std;

bool goodSpot(int myArray[], int col);
void backTrack(int& col);
void print(int myArray[], int arrSize);
int counter = 0;
bool backTrackVar = false;

int main(){
    int arrSize;
    int myArray[arrSize], col = 1;
    myArray[0]=0;

    cout << "Enter an integer for the dimenson: ";
    cin >> arrSize;

    while(true){
        while(col<arrSize){

            if(!backTrackVar){
                myArray[col] = -1;
            }
            while(myArray[col] < arrSize){
                myArray[col]++;

                if(myArray[col] == arrSize){
                    backTrack(col);
                    break;
                }
                if(goodSpot(myArray, col)){
                    backTrackVar=false;
                    col++;
                    break;
                }
            }
        }
        print(myArray, arrSize);
        backTrack(col);
    }

    return 0;
}

bool goodSpot(int myArray[], int col){
    for(int a=0; a < col; a++){
        if(myArray[col] == myArray[a] || (col - a) == abs(myArray[col] - myArray[a])){
            return false;
        }
    }return true;
}

void backTrack(int& col){
    col--;
    if(col == -1){
        exit(1);
    }
    backTrackVar=true;
}

void print(int myArray[], int arrSize){
    cout << "Solution #: " << ++counter << endl;
    for(int a=0; a<arrSize; a++){
        cout << myArray[a] << " ";
    }cout << endl << endl;
}
