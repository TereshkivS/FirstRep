#include <iostream>
#include <fstream>
#define A 1
#define B 10
#define C 19
#define D 28

using namespace std;

class MagicQ{
protected:
    //4 малих масиви створити
    int **cells;
    int _size;
public:
    MagicQ(ifstream& fl){
        _size=6;
        cells=new int* [_size];
        for(int i=0;i<_size;i++)
            cells[i]=new int [_size];
        for(int i=0;i<_size;i++)
            for(int j=0;j<_size;j++)
                cells[i][j]=0;
//        fl >> cells[1][4];
//        fl >> cells[1][5];
//        fl >> cells[2][0];
//        fl >> cells[2][1];
//        fl >> cells[3][0];
//        fl >> cells[4][0];
//        fl >> cells[5][5];

    }
    ~MagicQ(){
        for(int i=0;i<_size;i++)
            delete [] cells[i];
        delete [] cells;
    }
    friend ostream& operator << (ostream&, const MagicQ&);
    void Searchingchuslo();
    void FillA(int, int);

};



void MagicQ::FillA(int x,int y)
{
    int limit = cells[x][y]<A ? 0 : (cells[x][y]<B ? A : (cells[x][y]<C ? B : (cells[x][y]<D ? C : D)));
    if(limit==0)
        return;
    int temp_i, temp_j;
    //вниз вліво
    for(int i=x, j=y, temp_m=cells[x][y]; temp_m<limit+9; temp_m++,i=(i+1)%3,j=(j-1)%3){
        if(j == -1){
            j=2;
            if(i == 0){
                j=0;
                i=1;    // i=abs(j); j=j+i
            }
        }
        if(cells[i][j]!=0 && cells[i][j]<temp_m){
            cells[--temp_i][temp_j]=temp_m;
            i=temp_i;
            j=temp_j;
            continue;
        }
        cells[i][j]=temp_m;
        temp_i=i;
        temp_j=j;
    }
        //вверх вправо
    for(int i=x, j=y, temp_m=cells[x][y]; temp_m>limit-1; temp_m--, i=(i-1)%3,j=(j+1)%3){
         if(i==-1){
            i=2;
            if(j==0){
                i=1;
                j=2;
            }
         }
         if(cells[i][j]!=0 && cells[i][j]>temp_m){
            cells[++temp_i][temp_j]=temp_m;
            i=temp_i;
            j=temp_j;
            continue;
         }
         cells[i][j]=temp_m;
         temp_i=i;
         temp_j=j;
    }
}

ostream& operator << (ostream& of, const MagicQ& obj)
{

    for(int i=0;i<obj._size;i++){
        for(int j=0;j<obj._size;j++){
            of.setf(ios::left);
            of.width(4);
            of  << obj.cells[i][j];
        }
        of << endl;
    }
    return of;
}

class ThreexThree{
private:
    int **postn;
    int sizep;
public:
    ThreexThree(){
        sizep=3;
        postn=new int* [sizep];
        for(int i=0;i<sizep;i++)
            postn[i]=new int [sizep];
        for(int i=0;i<sizep;i++)
            for(int j=0;j<sizep;j++)
                postn[i][j]=0;
        postn[1][1]=23;

    }
    ~ThreexThree(){
        for(int i=0;i<sizep;i++)
            delete [] postn[i];
        delete [] postn;
    }
    friend ostream& operator << (ostream&, const ThreexThree&);
    void FillB(int,int);

};

void ThreexThree::FillB(int x, int y)    //в параметри правила треба передати
{
    int limit = postn[x][y]<A ? 0 : (postn[x][y]<B ? A : (postn[x][y]<C ? B : (postn[x][y]<D ? C : D)));
    if(limit==0)
        return;
    int temp_i, temp_j;
    //вниз вліво
    for(int i=x, j=y, temp_m=postn[x][y]; temp_m<limit+9; temp_m++,i=(i+1)%3,j=(j-1)%3){
        if(j == -1){
            j=2;
            if(i == 0){
                j=0;
                i=1;    // i=abs(j); j=j+i
            }
        }
        if(postn[i][j]!=0 && postn[i][j]<temp_m){
            postn[--temp_i][temp_j]=temp_m;
            i=temp_i;
            j=temp_j;
            continue;
        }
        postn[i][j]=temp_m;
        temp_i=i;
        temp_j=j;
    }
        //вверх вправо
    for(int i=x, j=y, temp_m=postn[x][y]; temp_m>limit-1; temp_m--, i=(i-1)%3,j=(j+1)%3){
         if(i==-1){
            i=2;
            if(j==0){
                i=1;
                j=2;
            }
         }
         if(postn[i][j]!=0 && postn[i][j]>temp_m){
            postn[++temp_i][temp_j]=temp_m;
            i=temp_i;
            j=temp_j;
            continue;
         }
         postn[i][j]=temp_m;
         temp_i=i;
         temp_j=j;
    }
}

void MagicQ::Searchingchuslo()
{
    for(int i=0;i<_size;i+=3)
        for(int j=1;j<_size;j+=3)
            if(cells[i][j] == 1 || cells[i][j] == 10 || cells[i][j] == 19 || cells[i][j] == 28)
                cout << cells[i][j] ;
                //встановити вгору -> вправо
    for(int i=2;i<_size;i+=3)
        for(int j=1;j<_size;j+=3)
            if(cells[i][j] == 1 || cells[i][j] == 10 || cells[i][j] == 19 || cells[i][j] == 28){
                cout << cells[i][j]<< endl <<endl;
                //встановити вниз -> вліво
                FillA(i,j);
            }
    for(int i=1;i<_size;i+=3)
        for(int j=0;j<_size;j+=3)
            if(cells[i][j] == 1 || cells[i][j] == 10 || cells[i][j] == 19 || cells[i][j] == 28)
                cout << cells[i][j];
                //встановити вліво -> вгору
     for(int i=1;i<_size;i+=3)
        for(int j=2;j<_size;j+=3)
            if(cells[i][j] == 1 || cells[i][j] == 10 || cells[i][j] == 19 || cells[i][j] == 28)
                cout << cells[i][j];
                //встановити вліво -> вгору
}

ostream& operator << (ostream& of, const ThreexThree& obj)
{

    for(int i=0;i<obj.sizep;i++){
        for(int j=0;j<obj.sizep;j++){
            of.setf(ios::left);
            of.width(4);
            of << obj.postn[i][j];
        }
        of << endl;
    }
    return of;
}

int main()
{
    ifstream ifile("chusla.txt");
    MagicQ oop(ifile);
    cout << oop << endl;
    oop.Searchingchuslo();
    cout << oop << endl;
//    ThreexThree oop;
//    cout << oop<<endl;
//    oop.FillB(1,1);
//    cout << oop<<endl;
    return 0;
}
