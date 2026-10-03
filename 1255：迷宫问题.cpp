#include <iostream>
#include <cstring>

int dx[4] = {0,0,1,-1},
    dy[4] = {1,-1,0,0};

//结构体用来存前置点的信息
struct pre_array
{
    int x;
    int y;
};
//f用来处理前置和处理迷宫图形
void f(int(*arr)[5],pre_array(*brr)[5])
{
    int (*quene)[2] = new int[26][2];
    int front = 0,rear = 1;
    quene[1][0] = 0, quene[1][1] = 0;
    brr[0][0].x=0,brr[0][0].y=0;
    arr[0][0] = 1;
    while(front < rear)
    {
        front++;
        for(int i = 0;i < 4;i++)
        {
            int xx = quene[front][0] + dx[i],yy = quene[front][1] + dy[i];
            if(xx >= 0 && xx < 5 && yy >= 0 && yy < 5 && arr[xx][yy] != 1)
            {
                rear++;
                quene[rear][0] = xx, quene[rear][1] = yy;
                brr[xx][yy].x=quene[front][0],brr[xx][yy].y=quene[front][1];
                if(xx == 4 && yy == 4)
                {
                    delete[] quene;
                    return;
                }
                arr[xx][yy] = 1;
            }
        }
    }
    delete[] quene;
}
//print用来打印从末点开始的最短路径信息
void print(pre_array (*brr)[5])
{
    pre_array temp[26];
    int len=0;
    int cx = 4,cy = 4;
    while(true)
    {
        temp[len].x = cx,temp[len].y = cy;
        ++len;
        if(cx == 0 && cy == 0)break;
        int px = brr[cx][cy].x;
        int py = brr[cx][cy].y;
        cx = px;
        cy = py;
    }
    for(int j=len-1;j>=0;j--)
    {
        std::cout << '(' << temp[j].x << ',' << ' ' << temp[j].y << ')';
        if(j==0)
        {
            continue;
        }
        std::cout << std::endl;
    }
}
int main()
{
    int (*arr)[5] = new int[5][5];
    pre_array (*brr)[5] = new pre_array[5][5];
    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    f(arr,brr);
    print(brr);
    delete[] brr;
    delete[] arr;
    return 0;
}