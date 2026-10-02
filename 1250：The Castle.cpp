#include <iostream>
#include <algorithm>

//四个方向的墙1:西，2北，4东，8南
int wall[4] ={1,2,4,8},
    dx[4] = {0,-1,0,1},
    dy[4] = {-1,0,1,0};

int f(int** arr,int** used,int x,int y,int m,int n)
{
    int count = 1;
    int (*quene)[2] = new int[m*n+1][2];
    int front = 0,rear = 1;
    quene[1][0] = x,quene[1][1] = y;
    used[x][y] = true;

    while(front < rear)
    {
        front++;
        for(int i=0;i<4;i++)
        {
            if(!(arr[quene[front][0]][quene[front][1]] & wall[i]))
            {
                int x1 = quene[front][0] +dx[i],y1 = quene[front][1] + dy[i];
                if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !used[x1][y1])
                {
                    rear++;
                    used[x1][y1] = true;
                    quene[rear][0] = x1,quene[rear][1] = y1;
                    count++;
                }
            }
        }
    }
    delete[] quene;
    return count;
}


int main()
{
    int m,n,maxx=0;
    std::cin >> m >> n;
    int** arr = new int*[m];
    int** used = new int*[m];
    for(int i = 0;i<m;i++)
    {
        arr[i] = new int[n];
        used[i] = new int[n];
        for(int j = 0;j<n;j++)
        {
            std::cin >> arr[i][j];
            used[i][j] = false;
        }
    }
    int count = 0;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(!used[i][j])
            {
                int room_size = f(arr,used,i,j,m,n);
                maxx = std::max(maxx,room_size);
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    std::cout << maxx << std::endl;
    for(int i = 0;i<m;i++)
    {
        delete[] arr[i];
        delete[] used[i];
    }
    delete[] arr;
    delete[] used;
    return 0;
}