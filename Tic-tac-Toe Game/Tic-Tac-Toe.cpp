#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'}};
int row,col;
char token='X';
bool tie=false;
string n1=" ",n2=" ";

void board(){
    
    cout<<"     |       |       \n";
    cout<<"  "<<space[0][0]<<"  |   "<<space[0][1]<<"   |  "<<space[0][2]<<" \n";
    cout<<"_____|_______|_______\n";
    cout<<"     |       |       \n";
    cout<<"  "<<space[1][0]<<"  |   "<<space[1][1]<<"   | "<<space[1][2]<<" \n";
    cout<<"_____|_______|_______\n";
    cout<<"     |       |       \n";
    cout<<"  "<<space[2][0]<<"  |   "<<space[2][1]<<"   |  "<<space[2][2]<<" \n";
    cout<<"     |       |       \n";
}

void enter(){
    int digit;
    if(token=='X'){
        cout<<n1<<", please enter: ";
        cin>>digit;
    }

    if(token=='O'){
        cout<<n2<<", please enter: ";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        col=0;
    }

    if(digit==2){
        row=0;
        col=1;
    }

    if(digit==3){
        row=0;
        col=2;
    }

    if(digit==4){
        row=1;
        col=0;
    }

    if(digit==5){
        row=1;
        col=1;
    }

    if(digit==6){
        row=1;
        col=2;
    }

    if(digit==7){
        row=2;
        col=0;
    }

    if(digit==8){
        row=2;
        col=1;
    }

    if(digit==9){
        row=2;
        col=2;
    }

    else if(digit<1 || digit>9){
        cout<<"Invalid!!"<<endl;
    }

    if(token=='X' && space[row][col]!='X' && space[row][col]!='O'){
        space[row][col]='X';
        token='O';

    }
    
    else if(token=='O' && space[row][col]!='X' && space[row][col]!='O'){
        space[row][col]='O';
        token='X';

    }

    else{
        cout<<"There is  no empty space!"<<endl;
        enter();
    }
    //board();

}

bool checkWin(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }

    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
        return true;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X' && space[i][j]!='O'){
                return false;
            }
        }
    }

    return false;

}

int main(){

    cout<<"\t\t\tWelcome to"<<endl;
    cout<<"\t\t    Tic-Tac-Toe Game"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter the name of first player: ";
    getline(cin,n1);
    cout<<"Enter the name o second player: ";
    getline(cin,n2);
    cout<<endl;
    cout<<n1<<", is player 1 and will play first"<<endl;
    cout<<n2<<", is player 2 and will next"<<endl;
    cout<<endl;

    while(!checkWin()){
        board();
        enter();
        checkWin();

    }
    board();

    if(token=='X'){
        cout<<n2<<" Wins the game!"<<endl;
    }
    else if(token=='O'){
        cout<<n1<<" Wins the game!"<<endl;
    }
    else{
        cout<<"It's a draw!"<<endl;
    }
}