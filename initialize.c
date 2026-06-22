int find_size(char *str){
        int n=0;
        while(str[n]!='\0'){
                if(n%2==0){
                        if(str[n]<'1' || str[n]>'9')
                                return -1;
                }
                else{
                        if(str[n]!=' ')
                                return -1;
                }
                n++;
        }
        if(n!=31 && n!=39 && n!=47 && n!=55 && n!=63 && n!=71)
                return -1;
        return (++n)/8;
}

int *fill_arr(int *arr, char *str){
        int i=0;
        while(str[i]!='\0'){
                if(i%2==0)
                        arr[i/2]=str[i]-'0';
                i++;
        }
        return arr;
}
