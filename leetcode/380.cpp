class RandomizedSet
{
public:
    unordered_set<int> vals;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        bool not_present = vals.find(val) == vals.end();
        vals.insert(val);
        return not_present;
    }

    bool remove(int val)
    {
        bool present = vals.find(val) != vals.end();
        vals.erase(val);
        return present;
    }

    int getRandom()
    {
        int n = vals.size();
        for (auto val : vals)
        {
            double x = ((double)rand() / (RAND_MAX));
            if (x < (double)1 / n)
            {
                return val;
            }
            --n;
        }
        return -1;
    }
};

/**
 * @brief 
 * 
 */
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> value_to_index;
    vector<int> values;

    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (value_to_index.find(val) != value_to_index.end())
            return false;
        value_to_index[val] = values.size();
        values.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (value_to_index.find(val) == value_to_index.end())
            return false;
        int index = value_to_index[val];
        value_to_index.erase(val);
        if (values.back() != val)
        { // only update index of the back if back != val
            values[index] = values.back();
            value_to_index[values.back()] = index;
        }
        values.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */