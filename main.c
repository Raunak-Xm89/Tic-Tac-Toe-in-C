// Raunak Thapa Magar 37 G
// Important note this program takes input of the postion by normal metrics ; not indices
// so the input will start from 1 and not 0
#include <stdio.h>
int WinnerCheck(char[3][3],int,int,char);
int main() {
    //Define the initial phase
    char TicTc[3][3] = {{'-','-','-'},
                       {'-','-','-'},
                       {'-','-','-'}
    };
    int row,col,isX;
    char player;
    printf("Welcome to Tic Tac Toe by Raunak\n");
    //Loop for the game to run
    for (int gamei = 1; gamei <= 9; gamei++) {
        //Printing the initial Phase
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                printf("%c ", TicTc[i][j]);
            }
            printf("\n");
        };
        //Determining the player
        if(gamei%2 ==0){
            printf("Please select a position that you want to place in the format of row & column (You are X)\n");
            isX = 1;
            player = 'X';
        } else {
            printf("Please select a position that you want to place in the format of row & column (You are O)\n");
            isX = 0;
            player = 'O';
        }
        Value_scan : //Entry point if the value is invalid for row or column
        //scanning the row and col value
        scanf("%d",&row);
        scanf("%d",&col);
        //if the row and col value are invalid
        if((row < 1 || row >3) || (col <1 || col >3)){
                printf("Please input a valid value\n");
                goto Value_scan;
            }
         else{ //if the row and col value are valid
            if(TicTc[row-1][col-1] == '-'){ //-1 to get the index value and comparing if the position is empty or not
                if(isX == 1) {
                    TicTc[row - 1][col - 1] = 'X'; //For player X
                } else{
                    TicTc[row - 1][col - 1] = 'O'; //For player Y

                }
            } else {
                printf("This position is occupied please select another free position\n"); //if the position is not empty
                goto Value_scan;
            }
            //CHECKING IF THE WIN CONDITION IS TRUE
            int win = WinnerCheck(TicTc,row-1,col-1,player);
            if ( win == 1){
                printf("%c has won\n");
                return 0;
            }

        }
    }
    printf("The game is a Draw\n");

return 0;
}
int WinnerCheck(char arr [3][3],int i,int j, char player) {
    //Checking the win condition for row
    if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player){
        return 1;
    } else if (arr[0][j] == player && arr[1][j] == player && arr[2][j] == player) {//Win condition for column
        return 1;
    }
    //Check win condition for diagonal
    else if ((arr[0][0] == player && arr [1][1] == player && arr [2][2] == player) || (arr[0][2] == player && arr [1][1] == player && arr [2][0] == player)){
        return 1;
    } else{
        return 0;
    }

}