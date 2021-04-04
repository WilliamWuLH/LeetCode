#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSetUnion
{
    bool path_compression = true;

    private:
        int n;
        vector<int> f;
        vector<int> rank;
    
    public:
        DisjointSetUnion(int N){
            n = N;
            rank.resize(n, 1);
            f.resize(n, 1);
            for(int i=0; i<n; i++)
                f[i] = i;
        }

        int find(int x){
            if(path_compression){
                // if(x != f[x])
                //     f[x] = find(f[x]);
                // return f[x];
                return x == f[x] ? f[x] : f[x] = find(f[x]);
            }
            else{
                if(x == f[x])
                    return x;
                return find(f[x]);
            }
        }

        void unionset(int x, int y){
            x = find(x);
            y = find(y);
            f[x] = y;
        }

        void unionset_by_rank(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y)
                return;
            if(rank[x] > rank[y])
                swap(x, y);
            f[x] = y;
            rank[y] += rank[x];
        }
};

int main()
{
    int N = 0, num_of_pair;
    unordered_map<int, int> data;
    
    cout <<"Input the data size N : ";
    cin >> N;

    cout <<"Input the size of pair : ";
    cin >> num_of_pair;

    cout <<"Input the data : " <<endl;
    for(int i = 0; i < num_of_pair; i++){
        int a,b;
        cin >>a >>b;
        data[a] = b;
    }

    DisjointSetUnion dsu(N);
    unordered_map<int, int>::iterator it;

    for(it = data.begin(); it != data.end(); it++)
        dsu.unionset_by_rank(it->first, it->second);

    for(int i = 0; i < N; i++)
        cout <<i <<" : " <<dsu.find(i) <<endl;

    return 0;
}