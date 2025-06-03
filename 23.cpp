// Overall intuition:
// We will build the list in order. Since the lists are sorted, the next element
// is one of the heads of the lists. The best way to find the minimum among the heads
// is to use a PriorityQueue() implemented using a min-heap.

// Time and space complexity:
// Let n be the number of elements across all lists
// Let k be the number of lists
// Initialization is O(k), pop and push in the core while loop are O(log k)
// The complete while loop and algorithm is O(n log k)
// Space is O(k) for the heap

// custom comparator for a min-heap
struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> pq;
            // push the head of each non-empty list to the pq
            for(ListNode* head : lists) {
                if (head != nullptr) {
                    pq.push(head);
                }
            }
            // create a dummy head to start the merged list
            ListNode dummy(0);
            ListNode* tail = &dummy;
            // Extract the minimum head and append it to the merged list
            while (!pq.empty()) {
                ListNode* smallest = pq.top();
                pq.pop();
                // add smallest to the list and move the tail pointer forward
                tail->next = smallest;
                tail = smallest;
                if (smallest->next != nullptr) {
                    pq.push(smallest->next);
                }
            }
            // the dummy node was not actually part of the merged list
            return dummy.next;
        }
};

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
