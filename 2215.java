import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;


class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {

    Set<Integer> inNums1 = new HashSet<>();    
    for (int n : nums1) {
        inNums1.add(n);
    }

    Set<Integer> inNums2 = new HashSet<>();    
    for (int n : nums2) {
        inNums2.add(n);
    }
    List<Integer> ret1 = new ArrayList<>();

    for (int n : inNums1) {
        if (!inNums2.contains(n)) {
            ret1.add(n);
        }
    }

    List<Integer> ret2 = new ArrayList<>();

    for (int n : inNums2) {
        if (!inNums1.contains(n)) {
            ret2.add(n);
        }
    }

    List<List<Integer>> ret = new ArrayList<>();
    ret.add(ret1);
    ret.add(ret2);
    return ret;
    }
}
