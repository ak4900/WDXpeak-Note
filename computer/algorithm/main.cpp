//
//  main.cpp
//  AlgorithmLearing
//
//  Created by WangDa on 11/13/14.
//  Copyright (c) 2014 DaWang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "stringbasic.h"

using namespace std;


int main(int argc, const char * argv[])
{
    // Chapter 1
    // --------------------------
    // 字符移动
    cout << "## String Basic ##\n";
    cout << "字符移动\n";
    char s[] = "abcdefg";
    cout << "s:" << s << endl;
    LeftRotateString(s, 7, 4);
    cout << "s:" << s << endl;
    
    Node *head = CreateSampleLinkedList(6);
    OutputLinkedList(head);
    head = SplitAndReverse(head, 4);
    OutputLinkedList(head);
    
    // 举一反三 第三题：可以用链表，然后反转输出即可
    // I am a student. -> student. a am I
    
    // -----------------------------
    // 字符串包含
    cout << "字符串包含\n";
    string a = "ABCDEFGHIJKLMNOPQRS";
    string b = "SDLKFJLSDKN";
    string c = "ALKDNAZYQ";
    
    cout << StringContains1(a, b) << endl;
    cout << StringContains1(a, c) << endl;
    cout << StringContains2(a, b) << endl;
    cout << StringContains2(a, c) << endl;
    cout << StringContains3(a, b) << endl;
    cout << StringContains3(a, c) << endl;
    
    // ----------------------------
    // 带通配符的字符串匹配问题
    cout << "带通配符的字符串匹配问题\n";
    char setence[] = "ABCDEFGHIJKLMNOPQRS";
    char rule[] = "A??D";
    cout << my_find(setence, rule) << endl;
    
    
    // -----------------------------
    // 字符串转为整型
    cout << "字符串转为整型\n";
    char num[] = "1024";
    cout << StrToInt(num) << endl;
    
    // -----------------------------
    // 回文判断
    cout << "回文判断\n";
    char d[] = "abcdcba";
    char e[] = "dacrocodilad";
    
    cout << isPalindrome1(d, str_len(d)) << endl;
    cout << isPalindrome1(e, str_len(e)) << endl;
    cout << isPalindrome2(d, str_len(d)) << endl;
    cout << isPalindrome2(e, str_len(e)) << endl;
    cout << isPalindromeLinkedList(head) << endl;
    
    stack<char> f;
    stack<char> g;
    
    f.push('a');
    f.push('b');
    f.push('c');
    f.push('b');
    f.push('a');
    
    g.push('a');
    g.push('b');
    g.push('c');
    g.push('c');
    g.push('a');
    
    cout << isPalindromeStack(f) << endl;
    cout << isPalindromeStack(g) << endl;
    
    // -------------------
    // 最长回文子串的长度
    cout << "最长回文子串的长度\n";
    char h[] = "acrzabcddcbeaacr";
    
    cout << LongestPalindrome(h, str_len(h)) << endl;
    cout << LongestPalindromeON(h, str_len(h)) << endl;

    // -------------------
    // 第一个只出现一次的字符
    cout << "第一个只出现一次的字符\n";
    cout << FirstNotRepeatChar(h) << endl;
    
    
    // Chapter 2
    // --------------------------
    // 寻找最小的 K 个数
    cout << "寻找最小的 K 个数\n";
    int numbers[] = {10,9,8,7,6,5,4,3,2,1};
    findSmallK1(numbers, 10, 4);
    findSmallK2(numbers, 10, 4);
    
    // -------------------------
    // 求解500万以内的亲和数
    /*
     如果两个数 a 和 b，a 的所有真因数之和等于 b，b 的所有真因数之和等于 a，则 a和 b 是一对亲和数。(220,284)(1184,1210)(2620,2294)
     */
    
    
    return 0;
}
