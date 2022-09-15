#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class game{
    
        vector<char> board;
        string player1_name;
        string player2_name;
        bool gamestate;
        bool player;
        int filed;
        void display();
        void play();
        string checkwin();
        bool move(int);
        bool move(int,int);
    public:    
        void menu();
      
};

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
bool game::move(int position){
    if(board[position-1]!=' ')
        return false;
    if(player==0){
        board[position-1]='X';
        player=1;
    }
    else{
        board[position-1]='O';
        player=0;
    }
    filed++; 
    return true;           
}
bool game::move(int from,int to){
    unordered_map<int,vector<int>> m;
    char c;
    if(player) 
        c='O';
    else    
        c='X';
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
        player = !player;
        return true;
    }
    vector<int> temp=m[from];
    for(int i:temp){
        if(i==to){
            board[from-1]=' ';
            board[to-1]=c;
            player = !player;
            return true;
        }
    }
    return false;
}
string game::checkwin(){
    vector<vector<int>> winner={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    bool flag=false;
    char s;
    if(player)
        s='X';
    else
        s='O';    
    for(vector<int> i:winner){
        if(board[i[0]]==s && board[i[1]]==s && board[i[2]]==s){
            flag=true;
            break;
            
        }
    }
    if(flag){
        if(player)
            return player1_name;
        else
            return player2_name;    

    }
    else{
        return "";
    }
}
void game::play(){

    system("cls");
    gamestate=1;
    player=0;
    board = vector<char> (9,' ');
    filed=0;
    cout<<endl<<endl<<endl<<endl;
    cout<<"--------------------------------|TIC TAC TOE GAME-PLAY|--------------------------------";
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t"<<"ENTER THE NAME OF PLAYER 1 : ";
    cin>>player1_name;
    cout<<"\t\t\t\t"<<"ENTER THE NAME OF PLAYER 2 : ";
    cin>>player2_name;
    int position;
    while(gamestate){
        system("cls");

        display();
        if(filed<6){
            cout<<"\t\t\t\t"<<"PLAYER : ";
            if(!player)
                cout<<player1_name<<endl;
            else
                cout<<player2_name<<endl;
            cout<<"\t\t\t\t"<<"ENTER THE POSITION FOR THE TOKEN PLACEMENT : ";
            cin>>position;
            if(!move(position)){
                cout<<"\t\t\t\t"<<"INVALID CHOICE !"<<endl;

                cout<<"\t\t\t\t"<<"ENTER ANY KEY TO CONTINUE "<<endl;
                getch();
                continue;
            }
            string result = checkwin();
            if(result!=""){
                system("cls");
                display();
                cout<<"\t\t\t\t"<<"THE WINNER IS "<<endl;
                cout<<"\t\t\t\t"<<"********"<<result<<"********"<<endl;
                gamestate=0;
                return;
            }
        }
        else{
            cout<<"\t\t\t\t"<<"PLAYER : ";
            if(!player)
                cout<<player1_name<<endl;
            else
                cout<<player2_name<<endl;
            cout<<"\t\t\t\t"<<"THE TOKENS FOR PLACMENTS IS COMPLETED "<<endl;
            cout<<"\t\t\t\t"<<"YOU CAN NOW MOVE THE TOKENS OR DRAW "<<endl;
            int draw;
            cout<<"\t\t\t\t"<<"ENTER YOUR CHOICE FOR DRAW[0/1] : ";
            cin>>draw;
            if(draw==1){
                cout<<"\t\t\t\t"<<"GAME DRAW "<<endl;
                gamestate=0;
                return;
            }
            else if(draw==0){
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
                if(move(from,to)){
                    cout<<"\t\t\t\t"<<"MOVEMENT SUCCESSFUL "<<endl;
                    string result = checkwin();
                    if(result!=""){
                        system("cls");
                        display();
                        cout<<"\t\t\t\t"<<"THE WINNER IS "<<endl;
                        cout<<"\t\t\t\t"<<"********"<<result<<"********"<<endl;
                        gamestate=0;
                        return;
                    }
                }
                else{
                    cout<<"\t\t\t\t"<<"INVALID MOVE !"<<endl;

                    cout<<"\t\t\t\t"<<"ENTER ANY KEY TO CONTINUE "<<endl;
                    getch();

                }
            }
            else{
                cout<<"\t\t\t\t"<<"INVALID CHOICE !"<<endl;

                cout<<"\t\t\t\t"<<"ENTER ANY KEY TO CONTINUE "<<endl;
                getch();
            }

        }
    }
    return;
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

    return;

}
int main()
{
    game a;
    a.menu();
    return 0;
}
