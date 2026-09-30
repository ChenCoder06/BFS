#include <iostream>
//和1329题一样解法，但是方向由上下左右->上下左右左上左下右上右下
int dx[8] = {1,1,1,0,0,-1,-1,-1},
    dy[9] = {0,1,-1,1,-1,0,1,-1};

void f(char** arr,int x,int y,int N,int M);

int main()
{
    int N,M;
    std::cin >> N >> M;
    char **arr = new char*[N];
    for(int i =0;i<N;i++)
    {
        arr[i] = new char[M];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    int count = 0;
    for(int i = 0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(arr[i][j] == 'W')
            {
                f(arr,i,j,N,M);
                count ++;
            }
        }
    }
    std::cout << count << std::endl;
    for(int i=0;i<N;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

void f(char** arr,int x,int y,int N,int M)
{
    arr[x][y] = '.';
    int front = 0 , rear = 1;
    int quene[10000][3];
    quene[1][1] = x,quene[1][2] = y;
    do
    {
        front++;
        for(int i=0;i<8;i++)
        {
            int xx = quene[front][1] + dx[i] , yy = quene[front][2] +dy[i];
            if( xx>=0 && xx<N && yy>=0 && yy <M && arr[xx][yy] == 'W')
            {
                rear++;
                quene[rear][1] = xx;
                quene[rear][2] = yy;
                arr[xx][yy] = '.';
            }
        }
    } while (front < rear);
}