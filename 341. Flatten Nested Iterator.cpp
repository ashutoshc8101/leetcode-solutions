class NestedIterator {
    vector<NestedInteger> nList;
    unordered_map<int, NestedIterator*> mp;
    int i = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nList = nestedList;
    }

    int next() {
        if (nList[i].isInteger()) {
            return nList[i++].getInteger();
        }

        NestedIterator* itr = mp[i];

        if (itr->hasNext()) {
            return itr->next();
        }

        i++;
        return next();
    }

    bool hasNext() {
        if (i >= nList.size()) return false;

        if (nList[i].isInteger()) return true;

        if (mp.find(i) == mp.end()) {
            NestedIterator* itr = new NestedIterator(nList[i].getList());
            mp[i] = itr;
        }

        if (!mp[i]->hasNext()) {
            i++;
            return hasNext();
        }
        return true;
    }
};