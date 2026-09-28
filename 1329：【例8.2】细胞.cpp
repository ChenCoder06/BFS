#include <iostream>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void f(int **arr,int x,int y,int m,int n);


int main()
{
    int m,n;
    std::cin >> m >> n;
    //申请一个存储m个int*类型的数组
    int **arr = new int*[m];
    //再申请m个存储n个int类型的数组，形成二维数组
    for(int i =  0 ;i<m ; i++)
    {
        arr[i] = new int[n];
    }
    //初始化各个元素
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            char ch;
            std::cin >> ch;
            arr[i][j] = ch - '0';
        }
    }
    int count = 0;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j])
            {
                f(arr,i,j,m,n);
                count ++;
            }
        }
    }
    std::cout << count << std::endl;
    //先处理二维数组内部的各个n个数组的内存
    for(int i=0;i<m;i++)
    {
        delete[] arr[i];
    }
    //再把外部二维数组内存去除
    delete[] arr;
    return 0;
}

void f(int** arr,int x,int y,int m,int n)
{
    arr[x][y] = 0;//将当前点设置为0,表示访问过
    int front = 0,rear = 1;
    int Node[1000][2];
    Node[1][0] = x,Node[1][1] = y;
    do
    {
        front++;
        for(int i=0;i<4;i++)
        {
            int xx = Node[front][0] + dx[i],yy = Node[front][1] +dy[i];
            if((xx>=0) && (xx<m) && (yy>=0) && (yy < n) && arr[xx][yy])
            {
                rear++;
                Node[rear][0] = xx;
                Node[rear][1] = yy;
                arr[xx][yy] = 0;
            }
        }
    } while (front < rear); 
}