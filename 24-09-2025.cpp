class SpecialQueue {

  public:

    multiset<int> st;
    vector<int> vp;
    
    void enqueue(int x) {
        // Insert element into the queue
        st.insert(x);
        vp.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if(!vp.empty()){
            auto it = st.find(vp[0]);
            if(it!=st.end())st.erase(it);
        }
        vp.erase(vp.begin());
    }

    int getFront() {
        // Get front element
        return vp[0];
    }

    int getMin() {
        // Get minimum element
        return *st.begin();
    }

    int getMax() {
        // Get maximum element
        return *st.rbegin();
    }
};
