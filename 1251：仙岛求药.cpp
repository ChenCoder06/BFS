#include <iostream>
#include <cstring>

int dx[4] = {0,0,1,-1},
    dy[4] = {1,-1,0,0};

void f(char** arr,int x,int y,int n,int m)
{
    int (*quene)[2] = new int[m*n+1][2];
    int** step = new int*[n];
    for(int i = 0;i<n;i++)
    {
        step[i] = new int[m];
        for(int j = 0;j<m;j++)
        {
            step[i][j] = -1;
        }
    }
    int front = 0,rear = 1;
    quene[1][0] = x, quene[1][1] = y;
    arr[x][y] = '#';
    step[x][y] = 0;
    while(front < rear)
    {
        front++;
        for(int i = 0;i < 4;i++)
        {
            int xx = quene[front][0] + dx[i],yy = quene[front][1] + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && arr[xx][yy] != '#')
            {
                rear++;
                quene[rear][0] = xx, quene[rear][1] = yy;
                step[xx][yy] = step[quene[front][0]][quene[front][1]] + 1;
                if(arr[xx][yy] == '*')
                {
                    std::cout << step[xx][yy] << std::endl;
                    delete[] quene;
                    for(int i = 0;i<n;i++)
                    {
                        delete[] step[i];
                    }
                    delete[] step;
                    return;
                }
                arr[xx][yy] = '#';
            }
        }
    }
    std::cout << -1 << std::endl;
    delete[] quene;
    for(int i = 0;i<n;i++)
    {
        delete[] step[i];
    }
    delete[] step;
}
int main()
{
    int n,m,x,y;
    while(true)
    {
        std::cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        char** arr = new char*[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = new char[m];
            for(int j = 0;j<m;j++)
            {
                std::cin >> arr[i][j];
                if(arr[i][j]=='@')
                {
                    x = i,y = j;
                }
            }
        }
        f(arr,x,y,n,m);
        for(int i = 0;i<n;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}