#include <unistd.h>
#include <stdlib.h>

int tracking(int *arr, int i, int *used_row, int *used_col, int n, int *visible_count);
int *fill_arr(int *arr, char *str);
int find_size(char *str);

int main(int argc, char *argv[]){
        // handles incorrect input count
        //printf("Let's start!\n");
        if(argc!=2){
                write(2,"Error!",6);
                return -1;
        }
        //printf("Passed argument count check!\n");
        //determine n*n
        int size=find_size(argv[1]);
        if(size<=0)
                return -1;
        //printf("Found size?\n");
        //allocate mem
        int *visibility=malloc(size*4*sizeof(int));
        int *casey=malloc(size*size*sizeof(int));
        int *used_row=malloc(size*size*sizeof(int));
        int *used_col=malloc(size*size*sizeof(int));
        if(visibility==NULL || casey==NULL || used_row==NULL || used_col==NULL){
                write(2,"mem allocation failed!",22);
                return -1;
        }
        fill_arr(visibility,argv[1]);
        int i=0;
        while(i<(size*size)){
                casey[i]=0;
                used_row[i]=1;
                used_col[i]=1;
                i++;
        }
        i=0;
        char c;
        //printf("Ready to start traversing?");
        if(tracking(casey,0,used_row,used_col,size,visibility)==1){
                while(i<(size*size)){
                        c=casey[i]+'0';
                        write(1,&c,1);
                        if((i+1)%size!=0)
                                write(1," ",1);
                        else
                                write(1,"\n",1);
                        i++;
                }
        }
        free(visibility);
        free(casey);
        free(used_row);
        free(used_col);
        return 0;
}
