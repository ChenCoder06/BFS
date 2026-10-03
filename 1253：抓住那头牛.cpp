#include <iostream>
#include <cstring>
#include <algorithm>

int f(int N,int K)
{
    if(N==K)return 0;
    int limit = std::max(N,K) * 2 + 1;
    bool* visited = new bool[limit + 1];
    int* dist = new int[limit + 1];
    int* quene = new int[limit + 1];

    for(int i = 0;i<=limit;i++)visited[i] = false;
    int front = 0 , rear = 0;
    quene[rear++] = N;
    visited[N] = true;
    dist[N] = 0;

    while(front < rear)
    {
        int pos = quene[front++];
        int next[3] = {pos-1,pos+1,2*pos};
        for(int i = 0;i<3;i++)
        {
            int np = next[i];
            if(np < 0 || np > limit)continue;
            if(visited[np])continue;
            visited[np] = true;
            dist[np] = dist[pos] + 1;
            quene[rear++] = np;

            if(np == K)
            {
                int ans = dist[np];
                delete[] visited;
                delete[] dist;
                delete[] quene;
                return ans;
            }
        }
    }
    delete[] visited;
    delete[] dist;
    delete[] quene;
    return -1;
}

int main()
{
    int N,K;
    std::cin >> N >> K;
    std::cout << f(N,K);
    return 0;
}