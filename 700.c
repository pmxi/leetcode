/*
 * An iterative implementation.
 */

struct TreeNode *searchBST(struct TreeNode* root, int val) {
    struct TreeNode *current = root;
    while (1) {
        // failed
        if (!current) {
            return NULL;
        }
        // found
        if (current->val == val) {
            return current;
        }
        else if (val > current->val) {
            current = current->right;
        }
        // else explore the left subtree
        else {
            current = current->left;
        }
    }
    // added so returns in all control paths
    return NULL;
} /* searchBST() */
