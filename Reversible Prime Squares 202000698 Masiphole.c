#include<stdio.h>
#include<stdbool.h>
  
// CS3520 ASSIGNMENT 1         THAPELO MASIPHOLE 202000698       
// A program that determines and prints the first 10 reversible prime squares


int Reverseprime[10];
int num=1;
int square;

bool primNum(int n) {
    int temp=0;
    int i;
    for(i=1; i<=n; i++) {
        if(n%i==0)
            temp++;
    }
    return (temp==2? true:false);
}

int Reversenum(int n)
{
    int reverse=0;
    while(n!=0)
    {
        reverse=reverse*10+n%10;
        n/=10;
    }
    return reverse;
}
bool checkpal(int n, int m)
{
    if(n==m)
        return true;
    else
        return false;
}

bool CheckSquare(int m)
{
    bool check=false;
    int i;
    for( i=1; i<=m; i++) {
        if(m/i==i && m%i==0) {
            if(primNum(i)) {
                check=true;
            }
            else {
                check=false;
            }
        }
    }
    return check;
}
// return false;

int main() {



    printf("The first 10 reversible prime squares are:\n");
    int i;
	for(i=0; i<=9; i++) {
        
        while(i<10) {
            if(primNum(num))
            {
                
                square=num*num;
                if(checkpal(square, Reversenum(square))) {
                    
                    num++;
                }
                else {
                    if(CheckSquare(Reversenum(square)))
                    {
                        
                        Reverseprime[i]=square;
                        num++;
                        break;
                    }
                    else {
                        num++;
                    }

                }

            }
            else num++;

        }
    }

    for(i=0; i<10; i++)
    {

        printf("(%d)%d\n",i+1, Reverseprime[i] );
    }
    return 0;
}

