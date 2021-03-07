# include <iostream>
# include <vector>

# define SIZE 10e6
# define M 999997

struct Node
{
    int next, key, value;
};

class HashTable {
    private:
        std::vector<int> head;
        std::vector<Node> data;
        int size;
    
    public:
        HashTable () {
            head.assign(M, -1);
            data.assign(SIZE, Node());
            size = 0;
        }

        HashTable (long long thesize, int m) {
            head.assign(m, -1);
            data.assign(thesize, Node());
            size = 0;
        }

        int hashfun (int key) {
            return key % M;
        }

        int add (int key, int value) {
            if (get(key) != -1)
                return -1;
            data[++size] = (Node){head[hashfun(key)], key, value};
            head[hashfun(key)] = size;
            return value;
        }

        int get (int key) {
            for (int p = head[ hashfun(key) ]; p; p = data[p].next)
                if (data[p].key == key)
                    return data[p].value;
            return -1;
        }

        int modify (int key, int value) {
            for (int p = head[hashfun(key)]; p; p = data[p].next)
                if (data[p].key == key)
                    return data[p].value = value;
            return -1;
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
                if(ht.add(key, value) != -1)
                    std::cout <<"Success!\n";
                else
                    std::cout <<"Fail!\n";
                break;
            
            case 2:
                std::cout <<"Input key : ";
                std::cin >>key;
                value = ht.get(key);
                if(value != -1)
                    std::cout <<"value : " <<value <<std::endl;
                else
                    std::cout <<"Fail!\n";
                break;
            
            case 3:
                std::cout <<"Input key & value : ";
                std::cin >>key >>value;
                if(ht.modify(key, value) != -1)
                    std::cout <<"Success!\n";
                else
                    std::cout <<"Fail!\n";
                break;

            case 4:

            default:
                return 0;
                break;
        }
    }
}