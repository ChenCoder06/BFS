#include <iostream>
#include <cstdlib>
#include <cstring>

int dx[12] = {-2,-2,-1,1,2,2,2,2,1,-1,-2,-2},
    dy[12] = {-1,-2,-2,-2,-2,-1,1,2,2,2,2,1};

int main()
{
    int s[101][101],quene[1000][4] = {0},x1,y1,x2,y2;
    memset(s,-1,sizeof(s));
    int head=1,tail=1;
    quene[1][1] = 1,quene[1][2]=1,quene[1][3] = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    while(head<=tail)
    {
        for(int i=0;i<12;i++)
        {
            int x = quene[head][1] + dx[i];
            int y = quene[head][2] + dy[i];
            if(x>0 && y>0)
            {
                if(s[x][y]==-1)
                {
                    s[x][y] = quene[head][3] + 1;
                    tail++;
                    quene[tail][1] = x;
                    quene[tail][2] = y;
                    quene[tail][3] = s[x][y];
                    if(s[x1][y1]>0 && s[x2][y2]>0)
                    {
                        std::cout << s[x1][y1] << std::endl;
                        std::cout << s[x2][y2] << std::endl;
                        return 0;
                    }
                }
            }
        }
        head++;
    }
    return 0;
}