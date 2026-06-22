int determine_check_scope(int *arr, int curr_idx, int *visible_count, int n);

int tracking(int *arr, int i, int *used_row, int *used_col, int n, int *visible_count){
        int digit=1;

        //base case
        if(i==n*n)
                return 1;
        while(digit<=n){
                //if current "digit" is already used, skip the whole loop
                if(used_row[((i/n)*n)+(digit-1)]!=1 || used_col[((i%n)*n)+(digit-1)]!=1){
                        digit++;
                        continue;
                }
                //assign the digit to current spot, mark digit as taken
                arr[i]=digit;
                used_row[((i/n)*n)+(digit-1)]=-1;
                used_col[((i%n)*n)+(digit-1)]=-1;
                //check if row/col ready for validation
                if(!((i+1)%n==0 || (i+1)>n*(n-1)) || determine_check_scope(arr,i,visible_count,n)==1)
                        //if passed validation, track forward
                        if(tracking(arr,i+1,used_row,used_col,n,visible_count)==1)
                                return 1;
                //reinitialize current spot back to empty and free up taken digit
                arr[i]=0;
                used_row[((i/n)*n)+(digit-1)]=1;
                used_col[((i%n)*n)+(digit-1)]=1;
                digit++;
        }
        return -1;
}
