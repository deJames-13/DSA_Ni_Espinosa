#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getTagLine(vector<string> l, vector<string> t)
{
    string res = "";
    int deep = 0;
    int i = 0;
    string tag = t.at(i);
    string prev_tag = tag;
    for (int j = 0; j < l.size(); j++)
    {
        string line = l.at(j);

        if ("</" + prev_tag + '>' == line || "</" + t.at(0) + '>' == line)
            break;
        prev_tag = tag;

        if (line.find('<') == 0 && line.find("</") != 0)
            deep += 1;
        else if (line.find("</") == 0)
            deep -= 1;
        if (line.find('<' + tag) == 0)
        {
            if (deep > t.size())
                break;
            i++;
            if (i < t.size())
                tag = t.at(i);
            else
                return line;
        }
    }
    return res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    bool isValueTurn;
    string res, attr, line, query, temp;
    vector<string> lines, results;
    int n, q;
    cin >> n >> q;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        temp = "";
        for (int j = 0; j < line.length(); j++)
        {
            temp += line[j];
        }
        lines.push_back(temp);
    }
    lines.resize(n);
    for (int i = 0; i < q; i++)
    {
        getline(cin, query);

        vector<string> tags;
        int tag_s = 0;
        isValueTurn = false;
        temp = "";
        for (int i = 0; i < query.length(); i++)
        {
            if (query[i] == '.' || query[i] == '~')
            {
                tags.push_back(temp);
                tag_s += 1;
                temp = "";
                if (query[i] == '~')
                    isValueTurn = true;

                continue;
            }

            temp += query[i];

            if (isValueTurn && i + 1 == query.length())
                attr = temp + " = ";
        }
        temp = "";
        tags.resize(tag_s);
        res = getTagLine(lines, tags);
        if (res == "" || res.find(attr) == res.npos)
        {
            res = "Not Found!";
            results.push_back(res);
            continue;
        }
        int pos = res.find(attr);
        int quotes = 0;
        for (int i = pos + attr.length(); i < res.length(); i++)
        {
            if (quotes == 2)
                break;
            if (res[i] == '\"')
            {
                quotes += 1;
                continue;
            }
            temp += res[i];
        }
        results.push_back(temp);
    }
    results.resize(q);
    for (int i = 0; i < q; i++)
    {
        cout << results.at(i) << endl;
    }

    return 0;
}
