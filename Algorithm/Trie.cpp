# include <iostream>
# include <vector>
# include <cstring>

# define SIZE 10e6
# define NUM_OF_CHAR 26

using namespace std;

// 字典树
class Trie {
    
    private:
        // 使用的结点数
        int count;
        // 该结点通过某个字符可以到达的下一个结点
        vector<vector<int>> next;
        // 以该结点结尾的字符串是否存在
        vector<int> exist;

    public:
        Trie () {
            count = 0;
            next.assign(SIZE, vector<int>(NUM_OF_CHAR, 0));
            exist.assign(SIZE, 0);
        }

        Trie (int size, int numOfChar) {
            count = 0;
            next.assign(size, vector<int>(numOfChar, 0));
            exist.assign(size, 0);
        }

        // 插入字符串
        void insert (string s, int l) {
            int len = s.length();
            // p 表示当前的结点
            int p = 0;
            for (int i=0; i<len; i++){
                int cur_char = s[i] - 'a';
                if(next[p][cur_char] == 0)
                    // 如果没有，就添加结点
                    next[p][cur_char] = ++count;
                p = next[p][cur_char];
            }
            exist[p] = 1;
        }

        // 查找字符串
        bool find (string s, int l) {
            int len = s.length();
            // p 表示当前的结点
            int p = 0;
            for (int i=0; i<len; i++) {
                int cur_char = s[i] - 'a';
                if(next[p][cur_char] == 0)
                    return 0;
                p = next[p][cur_char];
            }
            return exist[p];
        }
};

int main () {
    Trie t;
    string s;
    cout <<"Insert the string : ";
    cin >> s;
    t.insert(s, s.length());
    s = "";
    cout <<"Find the string : ";
    cin >>s;
    cout <<s <<" exist ? " << ((t.find(s, s.length()) == 1) ? "Yes" : "No");
}