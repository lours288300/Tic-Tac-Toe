 #include <stdio.h>
 #include <stdlib.h>
void print();
char arr[3][3]={{'7','8','9'},
				{'4','5','6'},
				{'1','2','3'}};
char o;
int win=0,i,j,k=1,n,yn[9]={0,0,0,0,0,0,0,0,0};
int main(void){
	print();
	while(k!=10&&win==0){
		o=k%2==0?'X':'O';
		printf("Enter one position>>> ");
		scanf("%d",&n);
		fflush(stdin);
		if(n>9||n<1)
			printf("Enter Error!\n");
		else if(yn[n-1]==0){
			for (j=0;j<3;j++)
				for(int f=0;f<3;f++)
					if(arr[j][f]==48+n)
						arr[j][f]=o;
			yn[n-1]=1;
			k+=1;
		}
		else
			printf("Repeat Enter!\n");
		print();
		if(k>4)
			for(i=0;i<3;i++)
				if(arr[i][0]==arr[i][1]&&arr[i][0]==arr[i][2]||
				   arr[0][i]==arr[1][i]&&arr[0][i]==arr[2][i]||
				   arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2]||
			       arr[2][0]==arr[0][2]&&arr[2][0]==arr[1][1]){
					printf(" %c win!",o);
					win=1;
					break;
				}
	    if(k==10 && win != 1)
			printf("Flat");
		printf("\n");
	}
	return 0;
}
void print(){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf("%2c",arr[i][j]);
		printf("\n");
	}
}
