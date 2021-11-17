#include <iostream>
#include <string>
#include <vector>

using namespace std;

//string decToBinaryStr(long long dec)
//{
//    vector<char> vec;
//    string res;
//
//    cout << dec << endl;
//
//    if (dec == 0)
//    {
//        res = "0";
//        return res;
//    }
//
//    while (dec)
//    {
//        vec.push_back(*to_string(dec % 2).c_str());
//        dec /= 2;
//    }
//    for (int i = vec.size() - 1; i >= 0; i--)
//    {
//        res += vec.at(i);
//    }
//
//    return res;
//}
//
//string addBinary(string a, string b) 
//{
//    int base = 2;
//    char* aEnd;
//    char* bEnd;
//    int aInt = strtol(a.c_str(), &aEnd, base);
//    int bInt = strtol(b.c_str(), &bEnd, base);
//
//    cout << aInt << " " << bInt << endl;
//
//    long long sum = double(aInt) + double(bInt);
//
//    cout << sum << endl;
//
//    return  decToBinaryStr(sum);
//}

//双指针从后往前遍历 加法逻辑进位

string addBinary(string a, string b)
{
    string res = "";

    int i = a.size() - 1;
    int j = b.size() - 1;

    int carry = 0;

    while (i >= 0 || j >= 0)
    {
        int aIndex = i >= 0 ? a[i--] - '0' : 0;
        int bIndex = j >= 0 ? b[j--] - '0' : 0;
        int sum = carry + aIndex + bIndex;
        carry = sum >= 2 ? 1 : 0;
        sum = sum >= 2 ? sum - 2 : sum;
        res.append(to_string(sum));
    }

    //处理最后一位进位
    if (carry == 1)
    {
        res.append("1");
    }

    //反转
    std::reverse(res.begin(), res.end());
    return res;

}

int main()
{
    string a = "0";
    string b = "0";

    cout << addBinary(a, b) << endl;

}

