#include <unistd.h>
#include <stdlib.h>

int validate(int *arr, int lt_to_rb, int rb_to_lt, int n);
int determine_check_scope(int *arr, int curr_idx, int *visible_count, int n);

//validation
int validate(int *arr, int lt_to_rb, int rb_to_lt, int n){
	int count=1;
	int seen=1;
	int highest=arr[0];

	while(count<n){
		if(highest<arr[count]){
			seen++;
			highest=arr[count];
		}
		count++;
	}
	if(seen!=rb_to_lt)
		return -1;

	seen=1;
	highest=arr[--count];
	while(count>0){
                if(highest<arr[count-1]){
                        seen++;
                        highest=arr[count-1];
                }
                count--;
        }
        if(seen!=lt_to_rb)
                return -1;

	return 1;
}

//determine check scope
int determine_check_scope(int *arr, int curr_idx, int *visible_count, int n){
	//"col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left row2left row3left row4left row1right row2right row3right row4right"
	//"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	int ltrb=0;
	int rblt=0;
	int *casey=malloc(n*sizeof(int));
	if(casey==NULL){
		write(2,"mem allocation failed!",22);
		return -1;
	}
	int track=0;
	//check row
	if((curr_idx+1)%n==0){
		int i=n*2;
		//assuming 1st row, curr_idx/n=0; assign visibility to match
		ltrb=visible_count[i+(curr_idx/n)];
		rblt=visible_count[i+n+(curr_idx/n)];
		while(track<n){
			//placing backwards, so need to val from rtl then ltr
			casey[track]=arr[curr_idx-track];
			track++;
		}
		if(validate(casey,ltrb,rblt,n)!=1){
			free(casey);
			return -1;
		}
	}
	//check col
	if((curr_idx+1)>n*(n-1)){
		ltrb=visible_count[(curr_idx%n)];
                rblt=visible_count[(curr_idx%n)+n];
		track=0;
                while(track<n){
			//placing backwards, so need to val from btt then ttb
                        casey[track]=arr[curr_idx-(track*n)];
			track++;
                }
		if(validate(casey,ltrb,rblt,n)!=1){
			free(casey);
			return -1;
		}
	}
	//return 1 if true and -1 if false
	free(casey);
	return 1;
}
