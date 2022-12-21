#include<iostream>
#include<string>
#include<cmath>
#include<math.h>
using namespace std;

int  det( int matrix[10][ 10],int r1);
void adjoint(int matrix_2[10][10], int adjointt[10][10], int r3);
void getinverse(int matrix_2[10][10], double inverse[10][10],int r3);
void getCoFactor(int matrix_2[10][10],int matrixx[10][10],int r1,int r2,int r3);

int main()
{


    int r,c,x1,x2,y1,y2,d,N_P_SIGN;
    const int rows=10;
    const int columns=10;
    int  matrixxss[10][10];
    cout<<"Please enter dimensions of Matrix A:"<<endl;
    cin>>x1>>x2;
    cout<<"Please enter dimensions of Matrix B:"<<endl;
    cin>>y1>>y2;
    cout<<"Please enter values of Matrix A:"<<endl;
    int sum[10][10];
    int matrixxx[10][10];
    int matrix_1[rows][columns];
    for(r=0; r<x1; r++)
    {
        for(c=0; c<x2; c++)
        {
            cin>>matrix_1[r][c];
        }
    }
//________________________________________________________________________________________________________________________

    int matrix_2[rows][columns];
    cout<<"Please enter values of Matrix B:"<<endl;
    for(r=0; r<y1; r++)
    {
        for(c=0; c<y2; c++)
        {
            cin>>matrix_2[r][c];
        }
    }
//_________________________________________________________________________________________________________________________________________
    do
    {
        cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
        cin>>d;
        switch(d)
        {
//_______________________________________________________________________________________________________________________
        case 1: //sum of a+b
            if(x1==y1&&x2==y2)
            {
                for(r=0; r<x1; r++)
                {
                    for(c=0; c<x2; c++)
                    {
                        if(c==x2-1)
                        {
                            cout<<matrix_1[r][c]+matrix_2[r][c]<<" ";
                            cout<<endl;
                            continue;
                        }
                        cout<<matrix_1[r][c]+matrix_2[r][c]<<" ";
                    }
                }
            }
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
            break;
//_______________________________________________________________________________________________________________________

        case 2: //difference a-b
            if(x1==y1&&x2==y2)
            {
                for(r=0; r<x1; r++)
                {
                    for(c=0; c<x2; c++)
                    {
                        if(c==x2-1)
                        {
                            cout<<matrix_1[r][c]-matrix_2[r][c]<<" ";
                            cout<<endl;
                            continue;
                        }
                        cout<<matrix_1[r][c]-matrix_2[r][c]<<" ";
                    }
                }
            }
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
            break;
//______________________________________________________________________________________________________________________________
        case 3://a*b
            if(x2==y1)
            {
                for(r=0; r<x1; r++)
                {
                    for(c=0; c<y2; c++)
                    {
                        sum[r][c]=0;

                        for(int m=0; m<x2; m++)
                        {
                            sum[r][c]+=matrix_1[r][m]*matrix_2[m][c];
                        }

                        if(c==y2-1)
                        {
                            cout<<sum[r][c]<<" ";
                            cout<<endl;
                            continue;
                        }
                        cout<<sum[r][c]<<" ";
                    }
                }
            }
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
            break;
//________________________________________________________________________________________________

        case 4:
            double   inverse[10][10];;
            double  sum[10][10];
            double  l,hh;
            if(x2==y1)
            {
                if(y1!=y2)
                {
                    cout<<"The operation you chose is invalid for the given matrices."<<endl;

                    break;
                }

                l=det(matrix_2,y1);
                if(l==0)
                {
                    cout<<"The operation you chose is invalid for the given matrices."<<endl;

                    break;
                }


                getinverse(matrix_2,inverse,y1);
                for(int r=0; r<x1; r++)
                {

                    for(int c=0; c<y2; c++)
                    {
                        sum[r][c]=0;

                        for(int m=0; m<x2; m++)
                        {
                            sum[r][c]+=matrix_1[r][m]*inverse[m][c];
                        }
                        if(sum[r][c]>0)
                            round(sum[r][c]);
                        else if(sum[r][c]<=-0.5)
                            round(sum[r][c]);
                        else if(sum[r][c]>-0.5&&sum[r][c]<=0)
                            sum[r][c]=0;


                        if(c==y2-1)
                        {
                            cout<<round(sum[r][c])<<" ";
                            cout<<endl;
                            continue;
                        }
                        cout<<round(sum[r][c])<<" ";

                    }
                }

            }
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;


            break;
//___________________________________________________________________________________________
        case 5:
            if(x1==x2)
                cout<<det(matrix_1,x1)<<endl;
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
            break;
//___________________________________________________________________________________________

        case 6:
            if(y1==y2)
                cout<<det(matrix_2,y1)<<endl;
            else
                cout<<"The operation you chose is invalid for the given matrices."<<endl;


            break;
//___________________________________________________________________________________________
        case 7:
            cout<<"Thank you!"<<endl;
            break;
        default:
            cout<<"The operation you chose is invalid for the given matrices."<<endl;
        }
    }
    while(d!=7);
}
// __________________________________________________________________________________
int det(int matrix[10][ 10],int r1)
{
    int N_P_SIGN,x,y,k,c;
    int total;


    total=0;
    if(r1==1)
    {
        return matrix[0][0];
    }
    if(r1==2)
    {
        return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];

    }

    else
    {
        int  matrixxx[10][10];
        N_P_SIGN=1;
        for( k=0; k<r1; k++)
        {

            x=0;
            for( int r=1; r<r1; r++)
            {
                y=0;
                for( c=0; c<r1; c++)
                {
                    if(c==k)
                        continue;
                    matrixxx[x][y]=matrix[r][c];


                    y++;
                }

                x++;
            }

            total+=N_P_SIGN*matrix[0][k]*det(matrixxx,r1-1);
            N_P_SIGN*=-1 ;
        }
        return total;
    }
}
void adjoint(int matrix_2[10][10], int adjointt[10][10], int r3)
{

    int sign = 1;
    int cofactor[10][10];

    for(int r=0; r<r3 ; r++)
    {
        for(int c=0; c<r3; c++)
        {

            getCoFactor(matrix_2,cofactor,r,c,r3);

            sign = pow(-1,(r+c));
            adjointt[c][r] = sign*det(cofactor,r3-1);

        }
    }
}
void getinverse(int matrix_2[10][10], double  inverse[10][10],int r3)
{

  double l=det(matrix_2,r3);

    int adjointt[10][10];
    adjoint(matrix_2,adjointt,r3);



    for(int r=0; r<r3; r++)
    {
        for(int c=0; c<r3; c++)
        {
            inverse[r][c] = adjointt[r][c]/l;
        }


    }
}
void getCoFactor(int matrix_2[10][10],int matrixx[10][10],int r1,int r2,int r3)
{
    int r,c,x,y;

    x=0;
    y=0;
    for(r = 0; r < r3; r++)
    {
        for(c=0; c<r3; c++)
        {
            matrixx[r][c] = 0;
            if(r!=r1 && c!=r2)
            {
                matrixx[x][y] = matrix_2[r][c];

                if(y < r3-2)
                    y++;
                else
                {
                    y = 0;
                    x++;
                }
            }
        }
    }

}
