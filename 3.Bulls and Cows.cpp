/*3.Bulls and Cows
You are playing the Bulls and Cows game with your friend.
You write down a secret number and ask your friend to guess what the number is.
When your friend makes a guess, you provide a hint with the following info:
The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but
are located in the wrong position. Specifically, the non-bull digits in the guess that
could be rearranged such that they become bulls.Given the secret number secret and your
friend's guess guess, return the hint for your friend's guess.The hint should be formatted
as "xAyB", where x is the number of bulls and y is the number of cows. Note that both
secret and guess may contain duplicate digits.
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int> m;
        int b=0,c=0;
        string p;
        for(int i=0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])
            {
                b++;
                continue;
            }
            m[secret[i]-'0']++;
            p+=guess[i];
        }
        for(int i=0;i<p.length();i++)
        {
            if(m.find(p[i]-'0')!=m.end() && m[p[i]-'0']>0)
            {
                c++;
                m[p[i]-'0']--;
            }
        }

        return to_string(b)+"A"+to_string(c)+"B";
    }
};
