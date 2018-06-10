#include <bits/stdc++.h>

#define LL long long
#define MAXS 100005
const int ALPHABET_SIZE = 26;

using namespace std;

int data[MAXS];
LL data1[MAXS];

struct StrData {
    string str;
    int idx;
};

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    vector<StrData *> minStr;
    int minVal;
    int maxVal;
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    pNode->minVal = 0;
    pNode->maxVal = 0;

    return pNode;
}

struct StrData *getStrDataNode(string val, int pos) {
    struct StrData *data = new StrData;
    data->str=val;
    data->idx=pos;
    return data;
}

struct CompareValues
{
    int asTime( const StrData *v ) const // or static
    {
        //cout << "@@ " << v->idx << endl;
        return v->idx;
    }

    int asTime( int t ) const // or static
    {
        //cout << "## " << t << endl;
        return t;
    }

    template< typename T1, typename T2 >
    bool operator()( T1 const& t1, T2 const& t2 ) const
    {
        return asTime(t1) < asTime(t2);
    }
};

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key, int pos)
{
    struct TrieNode *pCrawl = root;
    int lastpos;

    for (int i = 0; i < key.length(); i++)
    {
        if (pCrawl->minStr.size() == 0) {
            pCrawl->minVal = pos;
            pCrawl->maxVal = pos;
        } else if (pos < pCrawl->minVal) {
            pCrawl->minVal = pos;
        } else if (pos > pCrawl->maxVal) {
            pCrawl->maxVal = pos;
        }

        //cout << "pos " << key[i] << " " << pos << " " << pCrawl->minVal << " " << pCrawl->maxVal << endl;

        if (pCrawl->minStr.size() == 0)
            (pCrawl->minStr).push_back(getStrDataNode(key,pos));
        else {
            lastpos = pCrawl->minStr.size()-1;
            if (key.compare((pCrawl->minStr[lastpos])->str) < 0) {
                (pCrawl->minStr).push_back(getStrDataNode(key,pos));
            } else {
                (pCrawl->minStr).push_back(getStrDataNode((pCrawl->minStr[lastpos])->str,pos));
            }
        }

        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    if (pCrawl->minStr.size() == 0) {
        pCrawl->minVal = pos;
        pCrawl->maxVal = pos;
    } else if (pos < pCrawl->minVal) {
        pCrawl->minVal = pos;
    } else if (pos > pCrawl->maxVal) {
        pCrawl->maxVal = pos;
    }

    //cout << "pos " << pos << " " << pCrawl->minVal << " " << pCrawl->maxVal << endl;

    if (pCrawl->minStr.size() == 0)
        (pCrawl->minStr).push_back(getStrDataNode(key,pos));
    else {
        lastpos = pCrawl->minStr.size()-1;
        if (key.compare((pCrawl->minStr[lastpos])->str) < 0) {
            (pCrawl->minStr).push_back(getStrDataNode(key,pos));
        } else {
            (pCrawl->minStr).push_back(getStrDataNode((pCrawl->minStr[lastpos])->str,pos));
        }
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// string lowerFind(vector<StrData> data, int val, int st, int en) {
// 	int m=(st+en)>>2;
// 	if (data[m]==val) {
// 		return data
// 	}
// }

// Returns true if key presents in trie, else
// false
string search(struct TrieNode *root, string key, int pos)
{
    struct TrieNode *pCrawl = root;
    //string empty="";

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        // if (pCrawl->children[index])
        // cout << key[i] << " " << (pCrawl->children[index])->minVal << " " << (pCrawl->children[index])->maxVal << endl;
        // else cout << "empty!!" << endl;

        if (!pCrawl->children[index] || ((pCrawl->children[index])->minVal) > pos || ((pCrawl->children[index])->minStr).size() == 0) {
            auto it = upper_bound((pCrawl->minStr).begin(), (pCrawl->minStr).end(), pos, CompareValues());
            if (it == (pCrawl->minStr).end()) {
                int sz = (pCrawl->minStr).size();
                //cout << "1 " << ((pCrawl->minStr)[sz-1])->str << endl;
                return ((pCrawl->minStr)[sz-1])->str;
            } else {
                --it;
                //cout << "2 " << (*it)->str << endl;
                return (*it)->str;
            }
        }

        pCrawl = pCrawl->children[index];
    }

    //cout << "end " << pCrawl->isEndOfWord << " " << (pCrawl->minStr)[0]->idx << endl;
    auto it = upper_bound((pCrawl->minStr).begin(), (pCrawl->minStr).end(), pos, CompareValues());
    if (it == (pCrawl->minStr).end()) {
        int sz = (pCrawl->minStr).size();
        //cout << "3 " << ((pCrawl->minStr)[sz-1])->str << endl;
        return ((pCrawl->minStr)[sz-1])->str;
    } else {
        --it;
        //cout << "4 " << (*it)->str << endl;
        return (*it)->str;
    }
    //return empty;
}

int main()
{
    int n,q,x;
    string s,r;

    scanf("%d",&n);

    struct TrieNode *root = getNode();

    for (int i=0; i<n; i++) {
        cin >> s;
        insert(root, s, i+1);
    }

    scanf("%d",&q);

    while(q--){
        cin >> x >> r;
        cout << search(root, r, x) << endl;
    }

    return 0;
}