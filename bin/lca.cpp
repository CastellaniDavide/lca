#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int, int> > > collegamenti;
int gN;
queue <int> q;
vector <vector <int> > used;

void inizia(int N, int T, int A[], int B[], int C[])
{
    collegamenti.resize(N);
    gN = N;
    used.resize(N);

    for (size_t i = 0; i < N - 1; ++i)
    {
        collegamenti[A[i]].push_back(make_pair(B[i], C[i]));
        collegamenti[B[i]].push_back(make_pair(A[i], C[i]));
    }

    for (size_t i = 0; i < N; ++i)
    {
        used[i].resize(N, -1);
        q.push(i);
        used[i][i] = 0;

        while (!q.empty())
        {
            int c = q.front();
            q.pop();

            for (size_t j = 0; j < collegamenti[c].size(); ++j)
            {
                if(used[i][collegamenti[c][j].first] == -1)
                {
                    used[i][collegamenti[c][j].first] = (T == 0 ? used[i][c] + 1:
                                                         (T == 1 ? used[i][c] + collegamenti[c][j].second:
                                                          (T == 2 ? min(used[i][c], collegamenti[c][j].second):
                                                           (T == 3 ? used[i][c] + (collegamenti[c][j].second > 0 ? collegamenti[c][j].second : 0):
                                                            -1))));
                    q.push(collegamenti[c][j].first);
                }
            }
        }
    }
}

long long int distanza1(int u, int v)
{
    return used[u][v];
}

long long int distanza2(int u, int v)
{
    return used[u][v];
}

long long int minimo(int u, int v)
{
    return used[u][v];
}

long long int massimo(int u, int v)
{
    return used[u][v];
}

