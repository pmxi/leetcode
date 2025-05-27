using System;
using System.Collections.Generic;


public class Solution {
    public int MaxOperations(int[] nums, int k) {
        // counter for the number of operations.
        int ops = 0;
        var complements = new MultiSet<int>();
        foreach (int n in nums) {
            // k - n is the complement of n.
            if (complements.Count(k - n) >= 1) {
                complements.Erase(k - n);
                ops++;
            }
            else {
                complements.Insert(n);
            }
        }
        return ops;
    }
}


public class MultiSet<T>
{
    // underlying storage: element → its multiplicity
    private readonly Dictionary<T,int> _counts = new Dictionary<T,int>();

    // Insert one occurrence of 'item'
    public void Insert(T item)
    {
        if (_counts.TryGetValue(item, out int c))
            _counts[item] = c + 1;
        else
            _counts[item] = 1;
    }

    // Erase one occurrence of 'item'; returns true if something was removed
    public bool Erase(T item)
    {
        if (!_counts.TryGetValue(item, out int c))
            return false;

        if (c > 1)
            _counts[item] = c - 1;
        else
            _counts.Remove(item);

        return true;
    }

    // How many times does 'item' appear?
    public int Count(T item)
    {
        return _counts.TryGetValue(item, out int c) ? c : 0;
    }
}

