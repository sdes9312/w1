41141130

作業1

題目描述

Ackerman函數是非原始遞迴函數，常被用來測試遞迴效率與堆疊深度
以下是Ackerman定義公式

<img width="734" height="138" alt="image" src="https://github.com/user-attachments/assets/65f47d7d-c53a-4560-af73-351ebda20d55" />

解題策略
Ackerman公式意思是當m=0時會回傳n+1,n=0且m>0時會回傳m-1並使n=1,再依照回傳後的值再重新回到公式中,當m>0且n>0時則會回傳A(m−1,A(m,n−1))並且進入雙重遞迴(正常遞迴程式)
非遞迴程式則是使用堆疊的方式進行模擬每次都會記錄(m,n)並根據題目的條件堆疊

程式:

遞迴程式碼:
```cpp
#include <iostream>
using namespace std;

int ackermann(int m, int n) {
    if (m == 0) return n + 1;
    else if (n == 0) return ackermann(m - 1, 1);
    else return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    int m = 2, n = 3;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;
    return 0;
}
```
非遞迴程式碼:
```cpp
#include <iostream>
#include <stack>
using namespace std;

int ackermann(int m, int n) {
    stack<int> s;
    s.push(m);

    while (!s.empty()) {
        m = s.top();
        s.pop();

        if (m == 0) {
            n = n + 1;
        } else if (n == 0) {
            s.push(m - 1);
            n = 1;
        } else {
            s.push(m - 1);
            s.push(m);
            n = n - 1;
        }
    }
    return n;
}

int main() {
    int m = 3, n = 4;
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl;
    return 0;
}
```
效能分析

時間複雜度:
(1)遞迴版本:超指數皆

(2)非遞迴版本:與遞迴版本相同

空間複雜度:
(1)遞迴版本:每呼叫一次都會占用一層

(2)非遞迴版本:不受系統限制

遞迴是利用多層的函式呼叫容易爆堆疊而非遞迴是利用模擬呼叫堆疊相較遞迴，比較安全、穩定。


測試驗證
| 測試案例       | 參數(a,b)     | 預期輸出       | 實際輸出      |
| ------------- | ------------- | ------------- | ------------- |
| 測試1         | (0,1)         | 2             |2              |
| 測試2         | (1,2)         | 4             | 4             |
| 測試3         | (0,4)         | 5             | 5             |
| 測試4         | (2,3)         | 9             | 9             |
| 測試5         | (3,4)         | 125           | 125           |

```
編譯與執行命令

遞迴版本

g++ 1.1.cpp -o ackermann
./ackermann

非遞迴版本

g++ 1.2.cpp -o ackermann
./ackermann

```
申論、開發報告

1.雖然遞迴版本相對於非遞迴好理解，但輸入值過大容易崩潰

2.遞迴版本在輸入值較小時能展現指數級的成長

3.非遞迴版本雖複雜但可以調整大小以適應需求

4.非遞迴版本能追蹤並便於除錯

作業2

題目描述

給定一個集合 S，請設計一個遞迴函數來產生所有的 子集合（power set）
如果輸入s=(a,b,c)則powerset(s)={(),(a),(b),(c),(a,b),(a,c),(b,c),(a,b,c)}

解題策略
拿掉第一個元素，對剩下的集合遞迴產生power set,然後把每個子集合都再傳回第一個元素並組成新的子集合

程式:
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generatePowerset(const vector<char>& set, vector<char>& subset, int index) {
    if (index == set.size()) {
        cout << "(";
        for (char c : subset) {
            cout << c;
        }
        cout << ")" << endl;
        return;
    }

    generatePowerset(set, subset, index + 1);

    subset.push_back(set[index]);
    generatePowerset(set, subset, index + 1);
    subset.pop_back();
}

int main() {
    vector<char> set = {'a', 'b', 'c'};
    vector<char> subset;
    
    cout << "Powerset: " << endl;
    generatePowerset(set, subset, 0);
    
    return 0;
}
```
效能分析

時間複雜度:O(2^n)

空間複雜度:O(n)

測試驗證
| 測試案例       | 輸入           | 預期輸出       | 實際輸出      |
| ------------- | ------------- | ------------- | ------------- |
| 測試1         | { }           | { }          |{ }         |
| 測試2         | {a}        | { }, {a}             | { }, {a}             |
| 測試3         | {a,b}         | { }, {a}, {b}, {a,b}             | { }, {a}, {b}, {a,b}             |
| 測試4         | {a,b,c}        | { }, {c}, {b}, {b,c}, {a}, {a,c}, {a,b}, {a,b,c}             | { }, {c}, {b}, {b,c}, {a}, {a,c}, {a,b}, {a,b,c}             |
```
編譯與執行命令
g++ -o 2 2.cpp

2.exe
```
申論、開發報告

1.此題利用遞迴程式可以更快的把子集合處理

2.遞迴程式相對於非遞迴較簡單

心得:藉由這次作業充分了解遞迴的概念以及在演算法的處理上也有許多收穫
