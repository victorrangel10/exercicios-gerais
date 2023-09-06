#include <stdio.h>
#include <string.h>

int palindromo(char *str, int tamanho){
    if (tamanho==1 || tamanho==0)
    {
       return 1;
    }
    

    if (str[0]==str[tamanho-1])
    {
        for ( int i = 0; i < tamanho; i++)
        {
            str[i]=str[i+1];
        }
        
        str[tamanho-2]='\0';

        printf("%s\n",str);

        return palindromo(str,tamanho-2);
        
    
    }else return 0;
    
}

int main(){
    char str[100001];
    while(scanf("%s",str)==1){
    
        if(palindromo(str,strlen(str))){
            printf("SIM");
        }else{
            printf("NAO");
        }
        }
    return 0;
    
    
}
