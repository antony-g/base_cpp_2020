class IntArray 
{
    IntArray(size_t size, int defaultValue);
    void push_back(int value);
    void erase(size_t position);
    int get(size_t position);
    void set(size_t position, int value);
    size_t size();
};
