#include <iostream>
#include <cstring>

int dx[8] = {1,2,2,1,-1,-2,-2,-1},
    dy[8] = {2,1,-1,-2,-2,-1,1,2};

void f(int** arr,int x,int y,int x1,int y1,int n)
{
    if(x==x1 && y==y1)
    {
        std::cout << '0' << std::endl;
        return;
    }
    int (*quene)[2] = new int[n*n+1][2];
    int front = 0,rear = 1;
    quene[1][0] = x, quene[1][1] = y;
    while(front < rear)
    {
        front++;
        for(int i = 0;i < 8;i++)
        {
            int xx = quene[front][0] + dx[i],yy = quene[front][1] + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n && arr[xx][yy] == 0)
            {
                rear++;
                quene[rear][0] = xx, quene[rear][1] = yy;
                arr[xx][yy] = arr[quene[front][0]][quene[front][1]] + 1;
                if(xx == x1 && yy == y1)
                {
                    std::cout << arr[xx][yy] << std::endl;              
                    delete[] quene;    
                    return;
                }
            }
        }
    }
    delete[] quene;
}
int main()
{
    int n,x1,y1,x2,y2;
    int count;
    std::cin >> count;
    while(count--)
    {
        std::cin >> n >> x1 >> y1 >> x2 >> y2;
        int** arr = new int*[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = new int[n];
            for(int j = 0;j<n;j++)
            {
                arr[i][j] = 0;
            }
        }
        f(arr,x1,y1,x2,y2,n);
        for(int i = 0;i<n;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}