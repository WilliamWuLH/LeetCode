# include <iostream>
# include <vector>

# define N 360007

class HashTable {
    private:
        std::vector<int> keys;
        std::vector<int> values;
    
    public:
        HashTable () {
            keys.assign(N, -1);
            values.assign(N, -1);
        }

        HashTable (int n) {
            keys.assign(n, -1);
            values.assign(n, -1);
        }

        int& operator [] (int n) {
            int index = (n % N + N) % N, count = 1;
            while (keys[index] != n && values[index] != -1) {
                index = (index + count * count) % N;
                count++;
            }
            keys[index] = n;
            return values[index];
        }
};

int main () {
    HashTable ht;
    while (true) {
        std::cout <<"\n1. add\t2. get\t3. modify\t4. exit\nYour chose : ";
        int n = 0;
        std::cin >> n;
        int key = 0, value = 0;
        switch (n)
        {
            case 1:
                std::cout <<"Input key & value : ";
                std::cin >>key >>value;
                ht[key] = value;
                break;
            
            case 2:
                std::cout <<"Input key : ";
                std::cin >>key;
                std::cout <<ht[key] <<std::endl;
                break;
            
            case 3:
                std::cout <<"Input key & value : ";
                std::cin >>key >>value;
                ht[key] = value;
                break;

            case 4:

            default:
                return 0;
                break;
        }
    }
}