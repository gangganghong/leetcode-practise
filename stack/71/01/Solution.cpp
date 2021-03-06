//
// Created by chugang on 2020/7/6.
//
// 简化路径
// 思路有问题吧，拆东墙补西墙，总会漏掉情况
#include "Solution.h"

string Solution::simplifyPath(std::string path) {
    stack<char> temp;
    int len = path.size();
    for (int i = 0; i < len; i++) {
        if (temp.empty()) {
            temp.push(path[i]);
        } else {
            if (path[i] == '/') {
                if (temp.top() != '/' && i != len - 1) {
                    temp.push(path[i]);
                }
            } else if (path[i] == '.') {
                if (i + 1 < len && path[i + 1] == '.') {
                    while (!temp.empty() && temp.top() == '/' && temp.size() > 1) {
                        temp.pop();
                    }
                    if (!temp.empty() && temp.size() > 1) temp.pop();
                    i++;
                }
            } else {
                temp.push(path[i]);
            }
        }
    }

    string tempStr = "";
    while (!temp.empty()) {
        tempStr += temp.top();
        temp.pop();
    }

    string result;
    int size = tempStr.size();
    for (int i = size - 1; i >= 0; i--) {
        if (i == 0 && tempStr[i] == '/' && size > 1) continue;
        result += tempStr[i];
    }


    return result;
}