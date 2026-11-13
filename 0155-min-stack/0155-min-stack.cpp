// Method 1(Using extra N space by making extraa stack)

// class MinStack {
// public:
//     stack<int> st;
//     stack<int> minSt;
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         st.push(value);
//         if(minSt.size()==0 or value < minSt.top()){
//             minSt.push(value);
//         }else{
//             minSt.push(minSt.top());
//         }


//     }
    
//     void pop() {
//         st.pop();
//         minSt.pop();
        
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return minSt.top();
        
//     }
// };



// push() → O(1)
// pop() → O(1)
// top() → O(1)
// getMin() → O(1)
// Space: O(N)



// Method  2(No extra space)

class MinStack {
    stack<long long> st;
    long long mn;
public:
    MinStack(){
        mn = LLONG_MAX;
    }

    void push(int value){
        long long val = value;
        if(st.size()==0){
            st.push(val);
            mn = val;
        }
        else{
            if(val>=mn){
                st.push(val);
            }else{ // new minimum
            st.push(val+(val-mn));
                // than new min
            mn = val;
            
            }
        }
    }

    void pop(){
        if(st.top()<mn){ //ghapla hua hai
            long long oldMin = 2*mn - st.top();
            mn = oldMin;
        }
        st.pop();
    }

    int top(){
        if(st.top()<mn){
            return mn;
        }
        else return st.top();
    }

    int getMin(){
        return mn;
    }
};

