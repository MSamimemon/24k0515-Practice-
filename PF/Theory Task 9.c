#include<stdio.h>
int main(){

char input;
char grid[5][5]={
    {' ',' ','I','X',' '},
    {' ','X',' ',' ',' '},
    {'I',' ','X','X',' '},
    {' ',' ',' ','I','X'},
    {' ','X',' ',' ','P'},
};

int positionr=4,positionc=4;

while(1){
    for(int i=0;i<=4;i++){
    for(int j=0;j<=4;j++){
        printf("%c",grid[i][j]);
        printf(",");
    }printf("\n");;
}
printf("Enter Your Move \n");
scanf("%c",&input);
getchar();

if(input=='q'){
    printf("Game Over\n");
    break;
}

else if(input=='w'){//up
    positionr--;
    if(grid[positionr][positionc]=='X'){
        printf("Cannot Move Obstacle Ahead\n");
        positionr++;
    }

    else if(grid[positionr][positionc]=='I'){
        grid[positionr][positionc]=grid[positionr+1][positionc];
        grid[positionr+1][positionc]=' ';
    }

    else if(grid[positionr][positionc]==' '){
        grid[positionr][positionc]=grid[positionr+1][positionc];
        grid[positionr+1][positionc]=' ';
    }
}
else if(input=='a'){//left
    positionc--;
     if(grid[positionr][positionc]=='X'){
        printf("Cannot Move Obstacle Ahead\n");
        positionc++;
    }

    else if(grid[positionr][positionc]=='I'){
        grid[positionr][positionc]=grid[positionr][positionc+1];
        grid[positionr][positionc+1]=' ';
    }

    else if(grid[positionr][positionc]==' '){
        grid[positionr][positionc]=grid[positionr][positionc+1];
        grid[positionr][positionc+1]=' ';
    }
}
else if(input=='s'){//down
    positionr++;
     if(grid[positionr][positionc]=='X'){
        printf("Cannot Move Obstacle Ahead\n");
        positionr--;
    }

    else if(grid[positionr][positionc]=='I'){
        grid[positionr][positionc]=grid[positionr-1][positionc];
        grid[positionr-1][positionc]=' ';
    }

    else if(grid[positionr][positionc]==' '){
        grid[positionr][positionc]=grid[positionr-1][positionc];
        grid[positionr-1][positionc]=' ';
    }
}
else if(input=='d'){//right
    positionc++;
    if(grid[positionr][positionc]=='X'){
        printf("Cannot Move Obstacle Ahead\n");
        positionc--;
    }

    else if(grid[positionr][positionc]=='I'){
        grid[positionr][positionc]=grid[positionr][positionc-1];
        grid[positionr][positionc-1]=' ';
    }

    else if(grid[positionr][positionc]==' '){
        grid[positionr][positionc]=grid[positionr][positionc-1];
        grid[positionr][positionc-1]=' ';
    }
}

else{
    printf("Enter Valid Move\n");
}

if(positionc<0 || positionc>4 || positionr<0 || positionr>4){
    printf("Boundry wall Make Valid Move\n");
}
}
    return 0;
}