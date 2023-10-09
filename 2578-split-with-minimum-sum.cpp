// https://leetcode.cn/problems/split-with-minimum-sum/description/

class Solution
{
public:
    int splitNum(int num)
    {
        vector<int> split;

        while (num)
        {
            split.push_back(num % 10);
            num /= 10;
        }

        sort(split.begin(), split.end());

        int num1 = 0, num2 = 0;
        for (int i = 0; i < split.size(); i += 2)
        {
            num1 *= 10;
            num1 += split[i];

            if (i + 1 < split.size())
            {
                num2 *= 10;
                num2 += split[i + 1];
            }
        }

        return num1 + num2;
    }
};