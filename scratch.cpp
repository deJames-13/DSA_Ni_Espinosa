#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getAttr(string tag)
{
    string res;    
    return res;
}

string findTag(vector<string> lines, string q)
{
    string temp;
    string curr_tag;
    string res;
    for (int j = 0; j < lines.size(); j++) {
        curr_tag = lines.at(j);
        if (curr_tag[0] == '/') {
            continue;
        }
        for (int z = 0; z < q.length(); z++) {
            if (q[z] == '.')
                
            temp += q[z];
        }
    }
    return res;
}

string findChild(vector<string> vs)
{
    string res;
    for (int i = 0; i<vs.size(); i++) {
        
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string res;
    string line;
    string query;
    vector<string> lines;
    int n, q;
    cin >> n >> q;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        string temp = "";
        for (int j = 0; j < line.length(); j++) {
            if (line[j] == '<' || line[j] == '>')
                continue;
            temp += line[j];
        }
        lines.push_back(temp);
    }
    lines.resize(n);
    cin.ignore();
    for (int i = 0; i < q; i++) {
        getline(cin, query);   
        res = findTag(lines, query)
    }
    
    
    return 0;
}
