#include<iostream>
#include<cstring>
using namespace std;

void print(char a[][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}

int check(char a[][4])
{
    for(int i=1;i<4;i++)
    {
        if(a[i][1]=='O' && a[i][2]=='O' && a[i][3]=='O')
            return 1;
        else if(a[1][i]=='O' && a[2][i]=='O' && a[3][i]=='O')
            return 1;
        else if(a[i][1]=='X' && a[i][2]=='X' && a[i][3]=='X')
            return 2;
        else if(a[1][i]=='X' && a[2][i]=='X' && a[3][i]=='X')
            return 2;
        
    }
    if((a[1][1]=='O' && a[2][2]=='O' && a[3][3]=='O')||(a[1][3]=='O' && a[2][2]=='O' && a[3][1]=='O'))
        return 1;
    else if ((a[1][1]=='X' && a[2][2]=='X' && a[3][3]=='X')||(a[1][3]=='X' && a[2][2]=='X' && a[3][1]=='X'))
        return 2;
    else
        return 0;
}

int main()
{
    char b[50],c[50],d[50];
    char a[4][4]={{'.','1','2','3'},{'1','.','.','.'},{'2','.','.','.'},{'3','.','.','.'}};
    cout<<"Enter player 1 name : ";
    cin>>b;
    
    cout<<"Enter player 2 name : ";
    cin>>c;
    //cout<<b<<" "<<c<<endl;

    print(a);
    int row,col,t=0,chk=0,tt=0;
    strcpy(d,b);
    while(t<9 && chk==0)
    {
        cout<<endl<<d<<"'s chance :-"<<endl<<"Enter row  and column number :- ";
    again:    cin>>row>>col;
        if(row<=3 && row>=1 && col<=3 && col>=1 && a[row][col]=='.')
            if(tt==0)
            {
                tt=1;
                a[row][col]='O';
                strcpy(d,c);
            }
            else
            {
                tt=0;
                a[row][col]='X';
                strcpy(d,b);
            } 
        else
        {
            cout<<"Invalid row or column \n Please Enter again :- ";
            goto again;
        }
        chk = check(a);
        print(a);
        t++;
    }
    switch(chk)
    {
        case 0:cout<<"Game was a tie\n";
            break;
        case 1:cout<<"Winner is : "<<b<<"\n";
            break;
        case 2:cout<<"Winner is : "<<c<<"\n";
            break;
    }

    cout<<"\nThank You for Playing!\n";
    return 0;
}