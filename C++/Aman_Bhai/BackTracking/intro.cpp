/*
so backtracking is an algoriithmic technique for solving recursive problems by trying to build 
each possible soultion incrementally and removing those solution that fail to satisfy the constraints
of the problem at any point of time
*/


//now first que RAT IN A MAZE PROBLEM the rat can only move in two dir ie right and down
//first if it is even possibe?
//then how?
/*
  so this is the mapyou can go in 1 not in 0 , 0's are walls 
1 0 1 0 1 
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

or iska output
1 0 0 0 0 
1 1 1 1 0
0 0 0 1 0 
0 0 0 1 1 
0 0 0 0 1  THIS IS THE PATH 
*/
#include <iostream>
using namespace std;

bool isSafe(int **arr,int x,int y,int n){
	if(x<n && y<n && arr[x][y]==1){
		return true;
	}
	return false;
}

bool ratInMaze(int** arr,int x,int y,int n,int** solArr){
	//base condition
	if((x==(n-1)) && (y==(n-1))){
		solArr[x][y]=1;
		return true;
	}

	if(isSafe(arr,x,y,n)){
		solArr[x][y]=1;
		if(ratInMaze(arr,x+1,y,n,solArr)){
			return true;
		}
		if(ratInMaze(arr,x,y+1,n,solArr)){
			return true;
		}
		//ab agar dono mei hi false ho gaya to tab karage ham backtrack
		solArr[x][y]=0; //BACKTRACKING
		return false;
	}
	return false;
}

int main(){
	int n;
	cin>>n;

	int ** arr=new int *[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	cout<<endl;

	//solution arr
	int ** solarr=new int *[n];
	for(int i=0;i<n;i++){
		solarr[i]=new int[n];
		for(int j=0;j<n;j++){
			solarr[i][j]=0;
		}
	}

	if(ratInMaze(arr,0,0,n,solarr)){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}	
	}


    return 0;
}