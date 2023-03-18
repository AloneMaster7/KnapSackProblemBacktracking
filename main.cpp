#include <iostream>
using namespace std;
void knapsack(int* X,int* optX,int size,int* w,int* p,int b,int* optP,int l=0){
    if(l == size){
        int sum=0;
        for(int i=0;i<l;i++){
            if(X[i])
                sum+=w[i];
        }
        if(sum <= b){
            sum=0;
            for(int i=0;i<size;i++){
                if(X[i])
                    sum+=p[i];
            }
            if(sum > *optP){
                *optP = sum;
                for(int i=0;i<size;i++)
                     optX[i] = X[i];
            }
        }
    }
    else{
        X[l] = 1;
        knapsack(X,optX,size,w,p,b,optP,l+1);
        X[l] = 0;
        knapsack(X,optX,size,w,p,b,optP,l+1);
    }
}

int main(){
    const int size = 4;
    int X[size];
    int optX[size]={0};
    int w[size] = {10,20,15,12};
    int p[size] = {6,9,8,7};
    int b = 27;
    int optP = 0;
    knapsack(X,optX,size,w,p,b,&optP);
    for(int i=0;i<size;i++)
        cout<<optX[i]<<' ';
    cout<<endl;
    return 0;
}
