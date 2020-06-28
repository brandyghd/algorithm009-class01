//647. 回文子串
class Solution {
public:
    int countSubstrings(string s) {
        vector<char> v;
        vector<int> p(s.size() * 2 + 3, 0);
        v.push_back('$');
        for (auto c : s) {
            v.push_back('#');
            v.push_back(c);
        }
        v.push_back('#');
        v.push_back('\0');
        int mx = 0;
        int id;
        for (int i = 1; i < v.size() - 1; ++i) {
            if (i < mx) {
                p[i] = min(p[2 * id - i], mx - i);
            }
            else {
                p[i] = 1;
            }
            while (v[i - p[i]] == v[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        int sum = 0;
        for (int i = 2; i < v.size() - 2; ++i) {
            if (v[i] == '#')
                sum += p[i] / 2;
            else
                sum += (p[i] / 2);
        }
        return sum;
    }
};