#include <iostream>
using namespace std;

const int length=8;

int checkP(int,int, int,int, char[length][length],int);
int checkH(int,int, int,int, char[length][length]);
int checkR(int,int, int,int, char[length][length]);
int checkB(int,int, int,int, char[length][length]);
int checkK(int,int, int,int, char[length][length]);
int checkQ(int,int, int,int, char[length][length]);
int choiceChecker(int,int, int,int, char[length][length],int);
int isInBoard(char,const int, char[length][length]);
void play(int , char[length][length]);
int isMine(int ,char);
int kingSecurity(int ,int ,char[length][length],int );
int verticalAttack(int ,int ,char[length][length],int );
int horizontalAttack(int ,int ,char[length][length],int );
int diagonalAttack(int ,int ,char[length][length],int );
int horseAttack(int ,int ,char[length][length],int );
void descReset(char[length][length]);
void printDesc(char[length][length]);




int main(){

	const int boardSide=8;


	char chessMap[length][length]={
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o'}
	};
	


	descReset(chessMap);
	cout<<"good game!!";
	printDesc(chessMap);


	int playerNumber=0;

	while(isInBoard('k',boardSide,chessMap)==0&&isInBoard('K',boardSide,chessMap)==0){
		play(playerNumber,chessMap);

		playerNumber=(playerNumber+1)%2;

		cout<<"player"<<(playerNumber+1)<<" :: turn "<<endl;

}
return 0;
}

void play(int playerNumber, char desc[length][length]){
	int figureX=0;
	int figureY=0;
	int moveX=0;
	int moveY=0;


	cout<<"choose figure row:";
	cin>>figureY;
	cout<<"choose figure column:";
   cin>>figureX;
	cout<<"move to ";
   cin>>moveY;
	cin>>moveX;

	char empty='o';

	if (choiceChecker(figureX,figureY,moveX,moveY,desc,playerNumber)==0&& isMine(playerNumber,desc[figureY][figureX])==1){

	desc[moveY][moveX]=desc[figureY][figureX];
	desc[figureY][figureX]=empty;
	    printDesc(desc);
	}
	else{
	play(playerNumber,desc);
	}

}

int checkP(int currentX, int currentY,int nextX,int nextY,char desc[length][length],int playerNumber){

   int path=0;
	if(playerNumber==0){
		path=1;
	}
	else if(playerNumber==1){
		path=-1;
	}

	if(desc[nextY][nextX]=='o'){
		if((currentY==1||currentY==6) &&(nextY-currentY)*path<=2 &&(nextY-currentY)*path>0&&nextX==currentX){
			return 0;
		}
		else if ((currentY!=1||currentY!=6) &&(nextY-currentY)*path==1&&nextX==currentX){
			return 0;
		}
		else{return 1;}

	}
	else if(desc[nextY][nextX]!='o'){
		if (nextY-currentY==1 ){
			if(nextX-currentY==1||nextX-currentY==-1){
				cout<<"'KO!!'";
				return 0;
			}
			else {return 1;}

		}
	}
	return 1;
};

int choiceChecker(int currentX, int currentY,int nextX,int nextY,char desc[length][length],int player){

 int flag=0;

if (kingSecurity(currentX,currentY,desc,player)==0){

if(isMine(player,desc[nextY][nextX]==1)){


if(desc[currentY][currentX]=='h'||desc[currentY][currentX]=='H'){
flag=checkH(currentX,currentY,nextX,nextY,desc);
}
else if(desc[currentY][currentX]=='k'||desc[currentY][currentX]=='K'){
flag=checkK(currentX,currentY,nextX,nextY,desc);
}
else if(desc[currentY][currentX]=='q'||desc[currentY][currentX]=='Q'){
flag=checkQ(currentX,currentY,nextX,nextY,desc);
}
else if(desc[currentY][currentX]=='b'||desc[currentY][currentX]=='B'){
flag=checkB(currentX,currentY,nextX,nextY,desc);
}
else if(desc[currentY][currentX]=='p'||desc[currentY][currentX]=='P'){
flag=checkP(currentX,currentY,nextX,nextY,desc,player);
}
else if(desc[currentY][currentX]=='r'||desc[currentY][currentX]=='R'){
flag=checkR(currentX,currentY,nextX,nextY,desc);
}
else{flag=1;}

}
else{
	flag=1;
}

}

else{
		flag=1;
}


return flag;
}


int isMine(int playerNumber,char currentFigure ){

char figuresP1[6]={'R','H','B','K','Q','P'};
char figuresP2[6]={'r','h','b','k','q','p'};


if(playerNumber==1){
for (int i=0;i<6;i++){
	if (currentFigure==figuresP1[i]){
		return 0;
	}
}
return 1;

}
else if (playerNumber==2){
for (int i=0;i<6;i++){
	if (currentFigure==figuresP2[i]){
		return 0;
	}
}
return 1;
}
else{return 1;}
}


int checkB(int currentX, int currentY,int nextX,int nextY,char desc[length][length]){

int steps=0;

if(((nextX-currentX)/(nextY-currentY))==1||((nextX-currentX)/(nextY-currentY))==-1){

int flag=0;
	if(nextY>currentY&&nextX>currentX){
		steps=nextX-currentX;
		for(int i=1;i<steps;i++){
			if(desc[currentY+i][currentX+i]!='o'){
				flag=1;
			}
		}
	}
	else 	if(nextY<currentY&&nextX>currentX){
		steps=nextX-currentX;
		for(int i=1;i<steps;i++){
			if(desc[currentY-i][currentX+i]!='o'){
				flag=1;
			}
		}
	}
	else 	if(nextY<currentY&&nextX<currentX){
		steps=currentX-nextX;
		for(int i=1;i<steps;i++){
			if(desc[currentY-i][currentX-i]!='o'){
				flag=1;
			}
		}
	}
	else 	if(nextY>currentY&&nextX<currentX){
		steps=currentX-nextX;
		for(int i=1;i<steps;i++){
			if(desc[currentY+i][currentX-i]!='o'){
				flag=1;
			}
		}
	}
	cout<<10;
	return flag;
}
return 1;
}

int checkK(int currentX, int currentY,int nextX,int nextY,char desc[length][length]){
	if (nextX-currentX>1||nextX-currentX<-1||nextY-currentY>1||nextY-currentY<-1){
		if(nextX-currentX==0&&nextY-currentY==0){
			return 1;
		}
		else{return 0;}

	}
	else{return 1;}
}

int checkQ(int currentX, int currentY,int nextX,int nextY,char desc[length][length]){
	if(checkB(currentX,currentY,nextX,nextY,desc)==0||checkR(currentX,currentY,nextX,nextY,desc)==0){
		return 0;
	}
	else{return 1;}
}



int checkH(int currentX, int currentY,int nextX,int nextY,char desc[length][length]){
if (desc[nextY][nextX]=='o'){
	
	if(nextX-currentX==1&&nextY-currentY==2){
		return 0;
	}
	else if(nextX-currentX==-1&&nextY-currentY==2){
		return 0;
	}
	else if(nextX-currentX==-1&&nextY-currentY==-2){
		return 0;
	}
	else if(nextX-currentX==1&&nextY-currentY==-2){
		return 0;
	}
	else if(nextX-currentX==2&&nextY-currentY==1){
		return 0;
	}
	else if(nextX-currentX==-2&&nextY-currentY==1){
		return 0;
	}
	else if(nextX-currentX==-2&&nextY-currentY==-1){
		return 0;
	}
	else if(nextX-currentX==2&&nextY-currentY==-1){
		return 0;
	}
	else{
		return 1;
	}
	}
	return 1;
}

int checkR(int currentX, int currentY,int nextX,int nextY,char desc[length][length]){
	int flag=0;

	if(nextX==currentX||nextY==currentY){
		if (nextX>currentX){
			for(int i=currentX+1;i<nextX;i++){
				if (desc[currentY][i]!='o'){
					flag=1;
				}
			}
		}
		else if (nextX<currentX){
			for(int i=currentX-1;i>nextX;i--){
				if (desc[currentY][i]!='o'){
					flag=1;
				}
			}
		}
		else if (nextY>currentY){
			for(int i=currentY+1;i<nextY;i++){
				if (desc[i][currentX]!='o'){
					flag=1;
				}
			}
		}
		else if (nextY<currentY){
			for(int i=currentY-1;i>nextY;i--){
				if (desc[i][currentX]!='o'){
					flag=1;
				}
			}
		}
	}

	return flag;
}

int isInBoard(char value,const int arrLength, char array[length][length]){
	for(int i=0;i<arrLength;i++){
		for (int j = 0; i < arrLength; j++)
		{
			if (array[i][j]==value){
				return 0;
			}
		}
	}
	return 1;
};


void descReset(char board[length][length]){


 

board[0][0]='R';
board[0][1]='H';
board[0][2]='B';
board[0][3]='K';
board[0][4]='Q';
board[0][5]='B';
board[0][6]='H';
board[0][7]='R';

board[7][0]='r';
board[7][1]='h';
board[7][2]='b';
board[7][3]='k';
board[7][4]='q';
board[7][5]='b';
board[7][6]='h';
board[7][7]='r';

for(int i=0;i<length;i++){
	board[1][i]='P';
	board[6][i]='p';
}

};

void printDesc(char desc[length][length]){

	for(int i=0;i<length;i++){
		cout<<"\n"<<"_______________________\n";
		for(int j=0;j<length;j++){
			cout<<"|"<<desc[i][j]<<"|";	
		}
		cout<<"\n";
	}
	cout<<"________________________\n\n\n";

};

int kingSecurity(int kingX,int kingY,char desc[length][length],int player){

if(verticalAttack(kingX,kingY,desc,player)==1&&horizontalAttack(kingX,kingY,desc,player)==1&&horseAttack(kingX,kingY,desc,player)==1){
	return 0;
}
	return 1;
};

int verticalAttack(int X,int Y,char desc[length][length],int player){

int step=0;
	while(desc[Y+step][X]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y+step][X])==1) {
		if(desc[Y+step][X]=='R'||desc[Y+step][X]=='r'||desc[Y+step][X]=='q'||desc[Y+step][X]=='Q')
		{
			return 0;
		}
	}

	step=0;

	while(desc[Y-step][X]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y+step][X])==1) {
		if(desc[Y-step][X]=='R'||desc[Y-step][X]=='r'||desc[Y-step][X]=='q'||desc[Y-step][X]=='Q')
		{
			return 0;
		}
	}

	return 1;
};

int horizontalAttack(int X,int Y,char desc[length][length],int player){

int step=0;
	while(desc[Y][X+step]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y][X+step])==1) {
		if(desc[Y][X+step]=='R'||desc[Y][X+step]=='r'||desc[Y][X+step]=='q'||desc[Y][X+step]=='Q')
		{
			return 0;
		}
	}

	step=0;

	while(desc[Y][X-step]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y][X+step])==1) {
		if(desc[Y][X-step]=='R'||desc[Y][X-step]=='r'||desc[Y][X-step]=='q'||desc[Y][X-step]=='Q')
		{
			return 0;
		}
	}

	return 1;
};

int diagonalAttack(int X,int Y,char desc[length][length],int player){

int step=0;

	while(desc[Y+step][X+step]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y+step][X+step])==1) {
		if(desc[Y+step][X+step]=='B'||desc[Y+step][X+step]=='b'||desc[Y+step][X+step]=='q'||desc[Y+step][X+step]=='Q')
		{
			return 0;
		}
	}

	step=0;

	while(desc[Y-step][X-step]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y-step][X-step])==1) {
		if(desc[Y-step][X-step]=='B'||desc[Y-step][X-step]=='b'||desc[Y-step][X-step]=='q'||desc[Y-step][X-step]=='Q')
		{
			return 0;
		}
	}

	step=0;

	while(desc[Y+step][X-step]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y+step][X-step])==1) {
		if(desc[Y+step][X-step]=='B'||desc[Y+step][X-step]=='b'||desc[Y+step][X-step]=='q'||desc[Y+step][X-step]=='Q')
		{
			return 0;
		}
	}

	step=0;

	while(desc[Y+step][X-step]=='o'){	
		step++;
	}
	if(isMine(player,desc[Y+step][X-step])==1) {
		if(desc[Y+step][X-step]=='B'||desc[Y+step][X-step]=='b'||desc[Y+step][X-step]=='q'||desc[Y+step][X-step]=='Q')
		{
			return 0;
		}
	}

	return 1;
	
};


int horseAttack(int X,int Y,char desc[length][length],int player){

	int dX[8]={1,2,-1,-2,1,2,-1,-2};
	int dY[8]={2,1,-2,-1,-2,-1,2,1};

	for (int i = 0; i < 8; i++)
	{
		int nextX=X+dX[i];
		int nextY=Y+dY[i];

		if(desc[nextX][nextY]=='h'||desc[nextX][nextY]=='H')
		{
			if(isMine(player,desc[nextX][nextY])==1){
				return 0;
			}
		}
	
	}
	return 1;
};

