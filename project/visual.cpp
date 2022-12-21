#include<iostream>
#include<string>
#include<math.h>
using namespace std;

long det(matrix[][10],int r){
   if(r==1){
    return matrix[0][0];
   }
   if(r==2){
       return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
    
   }
   if(r==3){
           w= matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];
    e = matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2];
    f = matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1];
     return matrix[0][0] * w - matrix[0][1] * e + matrix[0][2] * f;
    
   }




int main(){


    int r,c,x1,x2,y1,y2,d,size1,size2,w,e,f,sign,i,j,k,det,total;
    const int rows=10; const int columns=10;




cout<<"Please enter dimensions of Matrix A:"<<endl;
cin>>x1>>x2;
cout<<"Please enter dimensions of Matrix B:"<<endl;
cin>>y1>>y2;
cout<<"Please enter values of Matrix A:"<<endl;
size1=x1;
 size2=y2;
int sum[size1+1][size2+1];
int matrixxx[x1][x2];


//
int matrix_1[rows][columns];
for(r=0;r<x1;r++){
    for(c=0;c<x2;c++){
            cin>>matrix_1[r][c];}}
//

int matrix_2[rows][columns];
cout<<"Please enter values of Matrix B:"<<endl;
for(r=0;r<y1;r++){
    for(c=0;c<y2;c++){
       cin>>matrix_2[r][c];}}
//
    do{
cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
         cin>>d;
        switch(d){
//_______________________________________________________________________________________________________________________
   case 1: //sum of a+b
 if(x1==y1&&x2==y2){
for(r=0;r<x1;r++){
    for(c=0;c<x2;c++){
            if(c==x2-1){
            cout<<matrix_1[r][c]+matrix_2[r][c]<<" ";
            cout<<endl;
            continue;}
 cout<<matrix_1[r][c]+matrix_2[r][c]<<" ";}}}
               else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;


               break;
 //_______________________________________________________________________________________________________________________

        case 2: //difference a-b
 if(x1==y1&&x2==y2){
 for(r=0;r<x1;r++){
    for(c=0;c<x2;c++){
            if(c==x2-1){
            cout<<matrix_1[r][c]-matrix_2[r][c]<<" ";
            cout<<endl;
            continue;}
 cout<<matrix_1[r][c]-matrix_2[r][c]<<" ";}}}
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;


 break;
 //______________________________________________________________________________________________________________________________
    case 3://a*b
        if(x2==y1){
for(r=0;r<x1;r++){
    for(c=0;c<y2;c++){
sum[r][c]=0;

for(int m=0;m<x2;m++){
 sum[r][c]+=matrix_1[r][m]*matrix_2[m][c];}
    }
    }for(r=0;r<x1;r++){
    for(c=0;c<y2;c++){
            if(c==y2-1){
            cout<<sum[r][c]<<" ";
            cout<<endl;
            continue;}
 cout<<sum[r][c]<<" ";}}}
 else
    cout<<"The operation you chose is invalid for the given matrices."<<endl;
 break;
//________________________________________________________________________________________________

        case 4: //a/b

 break;
 //___________________________________________________________________________________________
        case 5:
            if(x1==x2){

   
                sign=1;

total=0;i=j=0;
for(int k=0;k<x1;k++){

              for(int r=0;r<x1;r++){//rows move >>>>>first row
    for(int c=1;c<x2;c++){

            if(c==k)
                continue;
         matrixxx[i][j]=matrix_1[r][c-1];
                    j++;}

                   i++;}

                   total+=sign*matrix_1[0][c]*det;
                   sign*=-1 ; }
                 cout<<total;

            }
        break;
//___________________________________________________________________________________________



        case 6:


         break;
//___________________________________________________________________________________________
        case 7:
            cout<<"Thank you!"<<endl;
            break;
 default:
     cout<<"The operation you chose is invalid for the given matrices."<<endl;
               }} while(d!=7);



}
