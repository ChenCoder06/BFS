#include <iostream>
#include <cstring>
//定义上下前后左后方向
int dx[6] = {0,0,0,0,1,-1},
    dy[6] = {0,0,1,-1,0,0},
    dz[6] = {1,-1,0,0,0,0};

void f(char*** total,int x,int y,int z,int story,int lenth,int width)
{
    int (*quene)[4] = new int[story*lenth*width][4];
    int*** s = new int**[story];
    for(int i = 0;i<story;i++)
    {
        s[i] = new int*[lenth];
        for(int j = 0;j<lenth;j++)
        {
            s[i][j] = new int[width];
            for(int k =0;k<width;k++)
            {
                s[i][j][k] = -1;
            }
        }
    }
    int front = 0,rear = 1;
    s[x][y][z] = 0;
    quene[1][0] = x,quene[1][1] = y,quene[1][2] = z;
    while(front < rear)
    {
        front++;
        for(int i = 0;i<6;i++)
        {
            int x1 = quene[front][0] + dx[i],y1 = quene[front][1] + dy[i],z1 = quene[front][2] + dz[i];
            if(x1 >=0 && x1 < story && y1>=0 && y1 <lenth && z1 >=0 && z1 < width && total[x1][y1][z1] != '#' && s[x1][y1][z1] == -1)
            {
                rear++;
                s[x1][y1][z1] = s[quene[front][0]][quene[front][1]][quene[front][2]] + 1;
                if(total[x1][y1][z1] == 'E')
                {
                    std::cout << "Escaped in " << s[x1][y1][z1] <<  " minute(s)." << std::endl;
                    delete[] quene;
                    for(int i = 0;i<story;i++)
                    {
                        for(int j = 0;j<lenth;j++)
                        {
                            delete[] s[i][j];
                        }
                        delete[] s[i];
                    }
                    delete[] s;
                    return;
                }
                quene[rear][0] = x1,quene[rear][1] = y1,quene[rear][2] = z1;
            }
        }
    }
    std::cout << "Trapped!" << std::endl;
    delete[] quene;
    for(int i = 0;i<story;i++)
    {
        for(int j = 0;j<lenth;j++)
        {
            delete[] s[i][j];
        }
        delete[] s[i];
    }
    delete[] s;
}

int main()
{
    int story,lenth,width;
    while(true)
    {
        std::cin >> story >> lenth >> width;
        if(story == 0 && lenth == 0 && width == 0)
        {
            break;
        }
        char*** total = new char**[story];
        //记录起点位置
        int x,y,z;
        for(int i =0;i<story;i++)
        {
            total[i] = new char*[lenth];
            for(int j = 0;j<lenth;j++)
            {
                total[i][j] = new char[width];
                for(int k = 0;k<width;k++)
                {
                    std::cin >> total[i][j][k];
                    if(total[i][j][k] == 'S')
                    {
                        x = i,y = j,z = k;
                    }
                }
            }
        }
        f(total,x,y,z,story,lenth,width);
        //删除申请的数组
        for(int i =0;i<story;i++)
        {
            for(int j = 0;j<lenth;j++)
            {
                delete[] total[i][j];
            }
            delete[] total[i];
        }
        delete[] total;
    }
    return 0;
}