#include <stack>
#include <utility>
#include <iostream>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
    
private:
    stack<pair<int,int>> st;
};

int main() {
    StockSpanner* obj = new StockSpanner();
   int param_1 = obj->next(100);
   int param_2 = obj->next(80);
   int param_3 = obj->next(60);
   int param_4 = obj->next(70);
   int param_5 = obj->next(60);
   int param_6 = obj->next(75);
   int param_7 = obj->next(85);

   cout << param_1 << endl;
   cout << param_2 << endl;
   cout << param_3 << endl;
   cout << param_4 << endl;
   cout << param_5 << endl;
   cout << param_6 << endl;
   cout << param_7 << endl;

   return 0;
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */