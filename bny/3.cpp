#include <bits/stdc++.h>
using namespace std;

string circularCircuit(string input1)
{
    int n = input1.size();

    if(n == 1)
        return input1;

    vector<string> answers;

    for(int first = 0; first <= 1; first++)
    {
        for(int second = 0; second <= 1; second++)
        {
            vector<int> p(n);

            p[0] = first;
            p[1] = second;

            for(int i = 1; i < n-1; i++)
                p[i+1] = (input1[i]-'0') ^ p[i] ^ p[i-1];

            bool valid = true;

            if((p[n-2] ^ p[n-1] ^ p[0]) != (input1[n-1]-'0'))
                valid = false;

            if((p[n-1] ^ p[0] ^ p[1]) != (input1[0]-'0'))
                valid = false;

            if(valid)
            {
                string prev="";
                for(int x : p)
                    prev += char(x+'0');

                answers.push_back(prev);
            }
        }
    }

    if(answers.size()==0)
        return "No Chance";

    if(answers.size()>1)
        return "Multiple Scenario";

    return answers[0];
}

int main()
{
    string input1;
    cin >> input1;

    cout << circularCircuit(input1);
}