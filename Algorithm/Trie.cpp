# include <iostream>
# include <vector>
# include <cstring>

# define SIZE 10e6
# define NUM_OF_CHAR 26

using namespace std;

class Trie {
    
    private:
        int count;
        vector<vector<int>> next;
        vector<int> exist;

    public:
        Trie () {
            count = 0;
            next.resize(SIZE, vector<int>(NUM_OF_CHAR, 0));
            exist.resize(SIZE, 0);
        }

        Trie (int size, int numOfChar) {
            count = 0;
            next.resize(size, vector<int>(numOfChar, 0));
            exist.resize(size, 0);
        }

        void insert (string s, int l) {
            int len = s.length();
            int p = 0;
            for (int i=0; i<len; i++){
                int cur_char = s[i] - 'a';
                if(next[p][cur_char] == 0)
                    next[p][cur_char] = ++count;
                p = next[p][cur_char];
            }
            exist[p] = 1;
        }

        bool find (string s, int l) {
            int len = s.length();
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