#define MAXLEN 255
#include <iostream>
using namespace std;

typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

void print_next(SString T, int next[])
{
    for (int i = 1; i < T.length + 1; i++)
    {
        cout << "next[" << i << "]=" << next[i] << endl;
    }
}
void convert_string_sstring(string s, SString &ss)
{
    for (int i = 0; i < s.size(); i++)
    {
        ss.ch[i + 1] = s[i];
    }
    ss.length = s.size();
}

void get_next(SString T, int next[]) // 数组传递的是数组首地址，无需引用传递也能改变数组
{
    int i = 1, j = 0; // i代表后缀指针，j代表前缀指针
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
void get_nextval(SString T, int next[]) // 修正版next数组（改进版）
{
    int i = 1, j = 0; // i代表后缀指针，j代表前缀指针
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            if (T.ch[i] != T.ch[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
        {
            j = next[j];
        }
    }
}
int KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1; // i主串指针，j模式串指针
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j]; // 模式串向右滑动，从j开始匹配
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main()
{
    // 构造主串和模式串
    string pattern, text;
    SString T, S;
    pattern = "abaabc";
    text = "abaabaabcabaabc";
    convert_string_sstring(pattern, T);
    convert_string_sstring(text, S);

    // 实现KMP算法
    int next[T.length + 1];
    get_next(T, next);
    // get_nextval(T, next);
    print_next(T, next);
    cout << pattern << " | " << text << " 比较结果：" << KMP(S, T, next) << endl;
}
