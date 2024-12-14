#include <bits/stdc++.h>
//#include <iostream>

using namespace std;
 
class Running_maze{
    private:

        char maze_map[100][100];
        int row_position,col_position;
        int n;

    public: 

        void start(){
            cout<<"Breaking News!!!\nFlash, the fastest man alive is trapped in the maze!\n";
            cin>>n;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cin>> maze_map[i][j];
                    if(maze_map[i][j]=='*'){row_position=i;col_position=j;maze_map[i][j]='0';}
                }
            }
        }
        
        void left(){
            while(col_position>0 && maze_map[row_position][col_position-1]!='#'){
                col_position--;
                }
            cout<<"Flash moved to row: " << row_position+1 << " column:" << col_position+1 <<endl;
        }
        
        void right(){
            while(col_position < n-1 && maze_map[row_position][col_position+1]!='#'){
                col_position++;
            }
            cout<<"Flash moved to row: " << row_position+1 << " column:" << col_position+1 << endl;
        }
        
        void up(){
            while(row_position > 0 && maze_map[row_position-1][col_position] != '#'){
                row_position--;
            }
            cout << "Flash moved to row: " << row_position+1 << " column:" << col_position+1 << endl;
        }
        
        void down(){
            while (row_position < n-1 && maze_map[row_position+1][col_position] != '#'){
                row_position++;
            }
            cout << "Flash moved to row: " << row_position+1 << " column:" << col_position+1 << endl;
        }
        
        void info(){
            cout<<"The current position of Flash is row:"<<row_position+1<<" column:"<<col_position+1<<endl;
            maze_map[row_position][col_position]='*';
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<maze_map[i][j]<<" ";
                }cout<<"\n";
            }
            maze_map[row_position][col_position]='0';
        }
        
        void quit(){
            cout<<"BREAKING NEWS!!!\nFlash, the fastest man alive has successfully escaped the MAZE!\n";
        }
};
 
typedef class Running_maze RM;
 
int main(){
    RM flash;
    flash.start();
    char ctrl;
 
    while(1){
        cin>>ctrl;
        switch(ctrl){
            case 'l':
                flash.left();
                break;
            case 'r':
                flash.right();
                break;
            case 'u':
                flash.up();
                break;
            case 'd':
                flash.down();
                break;
            case 'i':
                flash.info();
                break;
            case 'q':
                flash.quit();
                return 0;
        }
    }

    return 0;
}