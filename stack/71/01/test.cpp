//
// Created by chugang on 2020/7/6.
//
#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    string path1 = "/a/../../b/../c//.//";
    string result1 = solution.simplifyPath(path1);
    cout << result1 << endl;
    string path2 = "/../";
    string result2 = solution.simplifyPath(path2);
    cout << result2 << endl;
    string path3 = "/..";
    string result3 = solution.simplifyPath(path3);
    cout << result3 << endl;
    return 0;
}
