#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class game{
    public:
    char board[9];
    int filed;
    bool gamestate;
    bool player;
    string player1,player2;
    int position;

    void menu();
    void display();
    void play();
    bool checkwin();
    bool feasible(int from,int to,char c);
};
bool game::feasible(int from,int to,char c){
    unordered_map<int,vector<int>> m;
    m[1]={2,4,5};
    m[2]={1,3,5};
    m[3]={2,5,6};
    m[4]={1,5,7};

    m[6]={3,5,9};
    m[7]={4,5,8};
    m[8]={5,7,9};
    m[9]={5,6,8};
    if(board[from-1]!=c)
        return false;
    if(board[to-1]!=' ')
        return false;
    if(from==5){
        board[from-1]=' ';
        board[to-1]=c;
        return true;
    }
    vector<int> temp=m[from];
    for(int i:temp){
        if(i==to){
            board[from-1]=' ';
            board[to-1]=c;
            return true;
        }
    }
    return false;
}
void game::display(){

    cout<<endl<<endl<<endl<<endl;
    cout<<"--------------------------------| TIC TAC TOE GAME-PLAY |--------------------------------";
    cout<<endl<<endl<<endl;
    cout<<"--------------------------------| BOARD STATUS |--------------------------------"<<endl<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|   "<<board[0]<<"    |   "<<board[1]<<"    |   "<<board[2]<<"    |"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|   "<<board[3]<<"    |   "<<board[4]<<"    |   "<<board[5]<<"    |"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|   "<<board[6]<<"    |   "<<board[7]<<"    |   "<<board[8]<<"    |"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;


}
void game::play(){
    system("cls");
    gamestate=1;
    cout<<endl<<endl<<endl<<endl;
    cout<<"--------------------------------|TIC TAC TOE GAME-PLAY|--------------------------------";
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t"<<"ENTER THE NAME OF PLAYER 1 : ";
    cin>>player1;
    cout<<"\t\t\t\t"<<"ENTER THE NAME OF PLAYER 2 : ";
    cin>>player2;
    filed=0;
    player=0;

    for(int i=0;i<9;i++)
        board[i]=' ';
    while(gamestate){

        system("cls");

        display();

        if(filed<6){
            cout<<"\t\t\t\t"<<"PLAYER : ";
            if(!player)
                cout<<player1<<endl;
            else
                cout<<player2<<endl;
            cout<<"\t\t\t\t"<<"ENTER THE POSITION FOR THE TOKEN PLACEMENT : ";
            cin>>position;
            if(board[position-1]!=' '){
                cout<<"\t\t\t\t"<<"INVALID CHOICE !"<<endl;

                cout<<"\t\t\t\t"<<"ENTER ANY KEY TO CONTINUE "<<endl;
                getch();
                continue;

            }
            if(!player)
                board[position-1]='X';
            else
                board[position-1]='O';
            if(checkwin()){
                    string winner;
                    if(!player)
                        winner=player1;
                    else
                        winner=player2;
                    system("cls");
                    display();

                    cout<<"\t\t\t\t"<<"THE WINNER IS "<<endl;
                    cout<<"\t\t\t\t"<<"********"<<winner<<"********"<<endl;
                    gamestate=0;
                    return;
            }
            if(player)
                player=0;
            else
                player=1;
            filed++;
      }
      else{
            cout<<"\t\t\t\t"<<"PLAYER : ";
            if(!player)
                cout<<player1<<endl;
            else
                cout<<player2<<endl;
            cout<<"\t\t\t\t"<<"THE TOKENS FOR PLACMENTS IS COMPLETED "<<endl;
            cout<<"\t\t\t\t"<<"YOU CAN NOW MOVE THE TOKENS OR DRAW "<<endl;
            bool draw;
            cout<<"\t\t\t\t"<<"ENTER YOUR CHOICE FOR DRAW[0/1] : ";
            cin>>draw;
            if(draw){
                cout<<"\t\t\t\t"<<"GAME DRAW "<<endl;
                gamestate=0;
                return;
            }
            else{
                int from,to;
                char c;
                if(!player)
                    c='X';
                else
                    c='O';
                cout<<"\t\t\t\t"<<"ENTER VALID POSITIONS FOR MOVEMENT "<<endl;
                cout<<"\t\t\t\t"<<"FROM : ";
                cin>>from;
                cout<<"\t\t\t\t"<<"TO ";
                cin>>to;
                if(feasible(from,to,c)){
                    cout<<"\t\t\t\t"<<"MOVEMENT SUCCESSFUL "<<endl;
                    if(checkwin()){
                    string winner;
                    if(!player)
                        winner=player1;
                    else
                        winner=player2;
                    system("cls");
                    display();

                    cout<<"\t\t\t\t"<<"THE WINNER IS "<<endl;
                    cout<<"\t\t\t\t"<<"********"<<winner<<"********"<<endl;
                    gamestate=0;
                    return;
                   }
                   if(player)
                     player=0;
                   else
                     player=1;

                }
                else{
                    cout<<"\t\t\t\t"<<"INVALID MOVE !"<<endl;

                    cout<<"\t\t\t\t"<<"ENTER ANY KEY TO CONTINUE "<<endl;
                    getch();

                }
            }

          }

    }


}
bool game::checkwin(){
    vector<vector<int>> winner={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    char s;
    if(!player)
        s='X';
    else
        s='O';
    for(vector<int> i:winner){
        if(board[i[0]]==s&&board[i[1]]==s&&board[i[2]]==s){
            return true;
        }
    }
    return false;
}
void game::menu(){

    mainstart:
    int choice;
    system("cls");

    cout<<endl<<endl<<endl<<endl;
    cout<<"--------------------------------|WELCOME TO TIC TAC TOE GAME|--------------------------------";
    cout<<endl<<endl<<endl;
    cout<<"--------------------------------|TUTORIAL TO TIC TAC TOE GAME|--------------------------------";
    cout<<endl<<endl;
    cout<<"\t\t\t\t"<<"THE TAGS FOR THE BLOCKS ARE SHOWN BELOW FOLLOW THEM FOR THE GAME PLAY"<<endl<<endl;

   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|   "<<"1"<<"    |   "<<"2"<<"    |   "<<"3"<<"    |"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|   "<<"4"<<"    |   "<<"5"<<"    |   "<<"6"<<"    |"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|   "<<"7"<<"    |   "<<"8"<<"    |   "<<"9"<<"    |"<<endl;
   cout<<"\t\t\t\t"<<"|        |        |        |"<<endl;
   cout<<"\t\t\t\t"<<"|--------|--------|--------|"<<endl;

    cout<<endl<<endl;
    cout<<"\t\t\t\t"<<"1.NEWGAME"<<endl;
    cout<<"\t\t\t\t"<<"2.EXIT"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t"<<"ENTER YOUR CHOICE[1/2] : ";
    cin>>choice;
    switch(choice){
    case 1:
        play();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout<<"\t\t\t\t"<<"INVALID CHOICE "<<endl;
    };

    cout<<"\t\t\t\t"<<"ENTER ANY KEY TO CONTINUE"<<endl;
    getch();
    goto mainstart;

}

int main()
{
    game a;
    a.menu();
    return 0;
}
