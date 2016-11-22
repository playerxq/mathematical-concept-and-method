// uva-10308-road in north.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
struct AdjVertex
{
    AdjVertex(int id, int length)
        : _id(id),
          _length(length)
    {
    }

    int _id;
    int _length;
};

vector<AdjVertex> g_graph[10001];


// _depth:
// The longest length of the path from root to
// leaf.
//
// _maxLen
// The longest length of the path between any
// vertex in this tree.
//
struct TreeInfo
{
    int _depth;
    int _maxLen;
};

// @vertexId
// The id of the vertex which is the root
// of the tree.
//
// @parentVertexId
// The parent vertex id of the root.
//
TreeInfo getTreeInfo(int vertexId, int parentVertexId)
{
    int maxLen = 0;
    int depth1st = 0;
    int depth2nd = 0;

    for (int i = 0; i < g_graph[vertexId].size(); i++) {//找到当前树的子树的根
        if (g_graph[vertexId][i]._id == parentVertexId) {
            continue;
        }
        TreeInfo subTreeInfo = getTreeInfo(g_graph[vertexId][i]._id, vertexId);//递归得到子树信息
        int v = subTreeInfo._depth + g_graph[vertexId][i]._length;//当前树根到子树节点最长距离
        if (depth1st < v) {//找到DX DY为两个最长的距离 DX>=DY
            depth2nd = depth1st;
            depth1st = v;
        } else if (v > depth2nd) {
            depth2nd = v;
        }
        if (maxLen < subTreeInfo._maxLen) {//子树中的最长两点距离
            maxLen = subTreeInfo._maxLen;
        }
    }

    TreeInfo treeInfo;
    treeInfo._depth = depth1st;

    if (depth1st + depth2nd > maxLen) {//找到DY+DX与maxlen的最大值  即是否利用当前树根进行中转得到最长距离
        treeInfo._maxLen = depth1st + depth2nd;
    } else {
        treeInfo._maxLen = maxLen;
    }

    return treeInfo;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    string lineStr;
    while (!cin.eof()) {
        getline(cin, lineStr);
        while (lineStr.length() > 0 && !cin.eof()) {
            stringstream ss;
            ss << lineStr;
            int vertex1, vertex2, distance;
            ss >> vertex1 >> vertex2 >> distance;
            g_graph[vertex1].push_back(AdjVertex(vertex2, distance));
            g_graph[vertex2].push_back(AdjVertex(vertex1, distance));
            getline(cin, lineStr);
        }

        TreeInfo treeInfo = getTreeInfo(1, -1);
        cout << treeInfo._maxLen << endl;

        for (int i = 1; i <= 10000; i++) {
            g_graph[i].clear();
        }
    }
}

