#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// =========================
// 基础打印
// =========================

template <typename T>
void debugPrint(const T& value) {
  cout << value;
}

template <typename A, typename B>
void debugPrint(const pair<A, B>& p) {
  cout << "(";
  debugPrint(p.first);
  cout << ", ";
  debugPrint(p.second);
  cout << ")";
}

// =========================
// 通用容器打印
// 适用于 vector / list / set / unordered_set / deque 等
// =========================

template <typename T>
void debugPrintContainer(const T& container) {
  cout << "[";
  bool first = true;
  for (const auto& elem : container) {
    if (!first) cout << ", ";
    debugPrint(elem);
    first = false;
  }
  cout << "]";
}

// vector
template <typename T>
void debugPrint(const vector<T>& v) {
  debugPrintContainer(v);
}

// deque
template <typename T>
void debugPrint(const deque<T>& d) {
  debugPrintContainer(d);
}

// list
template <typename T>
void debugPrint(const list<T>& l) {
  debugPrintContainer(l);
}

// set
template <typename T>
void debugPrint(const set<T>& s) {
  debugPrintContainer(s);
}

// multiset
template <typename T>
void debugPrint(const multiset<T>& s) {
  debugPrintContainer(s);
}

// unordered_set
template <typename T>
void debugPrint(const unordered_set<T>& s) {
  debugPrintContainer(s);
}

// =========================
// map / unordered_map
// =========================

template <typename K, typename V>
void debugPrint(const map<K, V>& m) {
  cout << "{";
  bool first = true;
  for (const auto& [key, value] : m) {
    if (!first) cout << ", ";
    debugPrint(key);
    cout << ": ";
    debugPrint(value);
    first = false;
  }
  cout << "}";
}

template <typename K, typename V>
void debugPrint(const unordered_map<K, V>& m) {
  cout << "{";
  bool first = true;
  for (const auto& [key, value] : m) {
    if (!first) cout << ", ";
    debugPrint(key);
    cout << ": ";
    debugPrint(value);
    first = false;
  }
  cout << "}";
}

// =========================
// 对外调试接口
// =========================

template <typename T>
void debug(const T& value, const string& name = "") {
  if (!name.empty()) {
    cout << name << " = ";
  }
  debugPrint(value);
  cout << endl;
}