#ifndef LEETCODESOLUTION
#define LEETCODESOLUTION
#include "LeetCodeConfig.h"
#include <limits.h>

vecInt deleteEqualsNum(const vecInt& vec)
{
    bool isEquals = true;
    vecInt res;

    for (int i : vec) {
        for (int j : res) {
            if (i == j) {
                isEquals = false;
                break;
            }
        }
        if (isEquals) {
            res.push_back(i);
        }
        isEquals = true;
    }
    return res;
}


/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/
vecPairInt twoSum(const vecInt& nums, int target)
{
    vecPairInt result;
    pairInt pairResult;
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if ((nums[i] + nums[j]) == target) {
                pairResult.first = i;
                pairResult.second = j;
                result.push_back(pairResult);
            }
        }
    }
    return result;
}

bool includeString(const string& str1, const string& str2)
{
    if (str1.size() < str2.size()) return false;
    bitset<128> _set1;
    const char* s1 = str1.data();

    while (*s1 != '\0') {
        _set1.set(*s1, 1);
        ++s1;
    }

    s1 = str2.data();
    while (*s1 != '\0') {
        if (_set1[*s1] == 0) return false;
        ++s1;
    }
    return true;
}

/**
  * 通过KMP算法比较字符串，sub在src中出现的位置
  * 当匹配失败后，j要移动k个位置要满足: arr[0 ~ k-1] == arr[j-k ~ j-1]
  *           i
  * A B C A B C D H I J K
  * A B C A B B
  *           j
  *       A B C A B B
  *       k         j
  *
  */
vecInt nextPos(const string& src)
{
    vecInt next;
    int size = src.size();
    int k = -1;
    int j = 0;

    next.resize(size);
    next[0] = -1;

    while (j < size - 1) {
        if (k == -1 || (src[j] == src[k])) {
            ++j;
            ++k;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
    return next;
}

int KMPmatchString(const string& src, const string& sub)
{
    if (src.empty() || sub.empty()) return -1;

    int i = 0;
    int j = 0;
    vecInt next = nextPos(sub);

    int srcSize = src.size();
    int subSize = sub.size();

    while (i < srcSize && j < subSize) {
        if (j == -1 || (src[i] == sub[j])) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    if (j == subSize) return i - j;
    return -1;
}

// Container With Most Water
/**
  * easy
  * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
  * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
  * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
  *
  * Note: You may not slant the container and n is at least 2.
  */

int MaxArea(vecInt& height) {
    int total = height.size();
    int max = 0;
    for (int h = 0; h < total; ++h) {
        for (int n = h + 1; 0 < total - n; ++n) {
            int tempMax = ((height[h] > height[n]) ? height[n]: height[h]) * (n - h);
            max = tempMax > max ? tempMax : max;
        }
    }

    return max;
}

/**
 * medium
 * add Binary
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 * The distance between two adjacent cells is 1.
 */
std::string addBinary(const std::string& a, const std::string& b)
{
    std::string result("");
    int m = a.size() - 1;
    int n = b.size() - 1;
    bool carry = false;
    while (n >= 0 || m >= 0) {
        int _n = n >= 0 ? b[n--] : 48;
        int _m = m >= 0 ? a[m--] : 48;
        int val = _n + _m - 96;
        if (carry) {
            val++;
        }
        if (val == 2) {
            carry = true;
            val = 0;
        }
        else if (val == 3) {
            carry = true;
            val = 1;
        }
        else {
            carry = false;
        }

        result.insert(0, std::to_string(val));
    }
    if (carry) {
        result.insert(0, "1");
    }
    return result;
}


static int atoiStatus = 0;
// string to int (atoi)
int strAtoi(const char* str1)
{
    long long nums = 0;
    bool sign = false;
    if (str1 != nullptr && *str1 != '\0') {
        char* str = (char*)malloc(strlen(str1) + 1);
        strcpy(str, str1);

        while (*str == ' ') {
            ++str;
        }

        if (*str == '-') {
            sign = true;
            str++;
        }
        else if (*str == '+') {
            str++;
        }
        while (*str >='0' && *str <='9') {
            atoiStatus = 1;
            nums = nums * 10 + *str - '0';
            if (nums > INT_MAX) {
                if (sign) {
                    return INT_MIN;
                }
                else {
                    return INT_MAX;
                }
            }
            str++;
        }
        if (sign) {
            nums = 0 - nums;
        }
        if (str != nullptr) {
            free(str);
            str = nullptr;
        }
    }

    return nums;
}

// ################################################################ LinkedList Start ###############################################################################

/**
  *Middle of the Linked List
  */

ListNodeInt* middleNode(ListNodeInt* head)
{
    if (head == nullptr) return head;
    ListNodeInt* fast = head;
    ListNodeInt* slow = head;
    int pos = 0;
    while (fast) {
        ++pos;
        fast = fast->next;
    }
    pos = (pos + 1)>>1;
    while (slow) {
        if (pos == 1) return slow;
        --pos;
        slow = slow->next;
    }
    return nullptr;
}

/**
  * Merge Two Sorted Lists
  * Input: 1->2->4, 1->3->4
  * Output: 1->1->2->3->4->4
  */
ListNodeInt* mergeTwoList(ListNodeInt* l1, ListNodeInt* l2)
{
    if (!l1 && !l2) return nullptr;
    if (!l1 && l2) return l2;
    if (l1 && !l2) return l1;

    ListNodeInt node {-1};
    ListNodeInt* cur = &node;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            cur->next = l1;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
         cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return node.next;
}

/**
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example :
        Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
        Output: 7 -> 0 -> 8
        Explanation: 342 + 465 = 807
 */

ListNode<int>* addTwoNum(ListNode<int>* l1, ListNode<int>* l2)
{
    ListNode<int>* result = new ListNode<int>;
    Node<int>* p = l1->head->next;
    Node<int>* q = l2->head->next;
    int deal = 0;

    while (p != nullptr || q != nullptr) {
        int x = 0, y = 0;

        if (p != nullptr) x = p->data;
        if (q != nullptr) y = q->data;
        int xy = x + y + deal;
        deal = xy / 10;
        std::cout<<xy<<std::endl;
        result->insert(xy % 10);
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }

    if (deal > 0) {
        result->insert(deal);
    }
    return result;
}

/**
 * Given a linked list, determine if it has a cycle in it.
 * @brief hasCycle
 * @param head
 * @return bool
 * 利用快慢指针，如果由环则快的指针一定会追上慢的
 */
bool hasCycle(ListNodeInt* head)
{
    ListNodeInt* fast = head;
    ListNodeInt* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

/**
 * @brief detectCycle
 * @param head
 * @return Node<int>*
 */
ListNodeInt* detectCycle(ListNodeInt* head)
{
    if (head == nullptr) return nullptr;
    ListNodeInt* fast = head;
    ListNodeInt* slow = head;
    ListNodeInt* entry = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            while (entry != slow) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return nullptr;
}


/**
 * @brief reverseList
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 */
ListNodeInt* reverseList(ListNodeInt* head)
{
    if (head == nullptr) return nullptr;
    ListNodeInt* cur = head;
    ListNodeInt* res = new ListNodeInt(0);
    res->next = head;

    while (head->next) {
        ListNodeInt* tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = res->next;
        res->next = tmp;
    }
    return res->next;
}

/**
 * Reverse a linked list from position m to n. Do it in one-pass
 * 1 ≤ m ≤ n ≤ length of list.
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */
ListNodeInt* reverserBetween(ListNodeInt* head, int m, int n)
{
    if (head == nullptr) return nullptr;

}


/**
 * @brief insertionSortList
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 */
ListNodeInt* insertionSortList(ListNodeInt* head)
{
    ListNodeInt* dummy = new ListNodeInt(-1);
    ListNodeInt* cur = dummy;
    while (head) {
        ListNodeInt* tmp = head->next;
        cur = dummy;

        while (cur->next && cur->next->data <= head->data) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }
    return dummy->next;
}

/**
  * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
  * You should preserve the original relative order of the nodes in each of the two partitions.
  */

ListNodeInt* partitionList(ListNodeInt* head, int x)
{
    if (head == nullptr) return nullptr;

    ListNodeInt* dummy = new ListNodeInt(-1);
    dummy->next = head;
    ListNodeInt* cur = dummy;
    ListNodeInt* res = new ListNodeInt(-1);
    ListNodeInt* temp = res;

    while (cur->next) {
        if (cur->next->data < x) {
            temp->next = cur->next;
            temp = temp->next;
            cur->next = cur->next->next;
            temp->next = nullptr;
        }
        else {
            cur = cur->next;
        }
    }

    temp->next = dummy->next;
    ListNodeInt* result = res->next;
    delete res;
    delete dummy;
    dummy = nullptr;
    res = nullptr;

    return result;
}



/** ############################################################## LinkedList Start ################################################################################ */





//############################################################### Binary Search Start ##############################################################################

/**
 * easy
 * Given a sorted (in ascending order) integer array nums of n elements and a target value,
 * write a function to search target in nums. If target exists, then return its index, otherwise return -1
 * @brief search
 * @return int
 */
int search(vecInt& nums, int target)
{
    int front = 0, mid = 0, back = nums.size() - 1;

    while (front <= back) {
        mid = (front + back) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            front = mid + 1;
        }
        else {
            back = mid - 1;
        }
    }
    return -1;
}

/**
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 * find the duplicate one
 * input : 1,3,4,2,2
 * output : 2
 */
int findDupLicate(vector<int>& nums)
{
    int front = 0, mid = 0, back = nums.size();

    while (front < back) {
        int total = 0;
        mid = front + (back - front) / 2;
        for (int num : nums) {
            if (num <= mid) {
                total++;
            }
        }
        if (total <= mid) {
            front = mid + 1;
        }
        else {
            back = mid;
        }
    }
    return front;

//利用快慢指针，巧妙的利用坐标和数值之间相互转换，而由于重复数字的存在，那么一定会形成环，ps:不存在相同数字可能会死循环 O(n)
//    int slow = 0, fast = 0, t = 0;
//    while (true) {
//        slow = nums[slow];
//        fast = nums[nums[fast]];
//        if (slow == fast) break;
//    }
//    while (true) {
//        slow = nums[slow];
//        t = nums[t];
//        if (slow == t) break;
//    }
//    return slow;
}

/** ############################################################### Binary Search End ############################################################################## */




//################################################################## Tree Start ###############################################################################

/**
  * 701. Insert into a Binary Search Tree
  */

TreeNodeInt* insertIntoBST(TreeNodeInt* root, int val)
{
    if (root == nullptr) return new TreeNodeInt(val);

    if (root->val > val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

/**
  * same tree
  * Compare two trees to see if they are the same
  */
bool sameTree(TreeNodeInt* a, TreeNodeInt* b)
{
    if (!a && !b) return true;
    else if (!a && b) return false;
    else if (a && !b) return false;
    else {
        if (a->val != b->val) return false;
        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }
}

/**
 * easy
 * Binary Tree Inorder traversal
 * @brief inorderTraversal
 * @param root
 * @return
 *
 * 考察二叉树的先后中遍历，运用stack的后进先出特性，先将节点的一侧节点入栈再将另一侧入栈，然后pop一次，这样后进的pop，先进的保留，然后loop，这样树的一侧被访问完毕在访问另外一侧
 */
vecInt inorderTraversal(TreeNode<int>* root) {
    vecInt vec;
//递归式先序遍历
//    if (root != nullptr) {
//        printf("%d\n", root->val);
//        inorderTraversal(root->left);
//        inorderTraversal(root->right);
//    }

    std::stack<TreeNode<int>*> stack;

    if (root == nullptr) {
        return vec;
    }

//先序遍历
    TreeNode<int>* node = nullptr;
    stack.push(root);
    while (!stack.empty()) {
        node = stack.top();
        stack.pop();
        vec.push_back(node->val);

        if (node->right) {
            stack.push(node->right);
        }

        if (node->left) {
            stack.push(node->left);
        }
    }

//中序遍历
//    TreeNode<int>* curNode = root;
//    while (curNode || !stack.empty()) {
//        while (curNode) {
//            stack.push(curNode);
//            curNode = curNode->left;
//        }
//        curNode = stack.top();
//        stack.pop();
//        vec.push_back(curNode->val);
//        curNode = curNode->right;
//    }

    //后序遍历
//    TreeNode<int>* node = nullptr;
//    stack.push(root);
//    while (!stack.empty()) {
//        node = stack.top();
//        stack.pop();
//        vec.insert(vec.begin(), node->val);

//        if (node->left) {
//            stack.push(node->left);
//        }
//        if (node->right) {
//            stack.push(node->right);
//        }

//    }
    return vec;
}

/**
 * @brief The BSTIterator class
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * 考察二叉树的中序遍历，isNext()当做外层循环
 */

class BSTIterator {
public:
    BSTIterator(TreeNodeInt* root) {
        while (root) {
            m_stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNodeInt* node = m_stack.top();
        m_stack.pop();

        int res = node->val;
        if (node->right != nullptr) {
            node = node->right;
            while (node) {
                m_stack.push(node);
                node = node->left;
            }
        }
        return res;
    }

private:
    std::stack<TreeNodeInt*> m_stack;
};

/**
 * medium
 * Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.
 * @brief addOneRow
 * @param root  current tree
 * @param v is insert value
 * @param d is depth of tree
 * @return
 * 考虑二叉树的层序遍历
 */

TreeNodeInt* addOneRowToTree(TreeNodeInt* root, int v, int d)
{
    if (root == nullptr) {
        return nullptr;
    }

    TreeNodeInt* node = nullptr;
    std::queue<TreeNodeInt*> queue;
    queue.push(root);

    while (!queue.empty()) {
        if (--d == 0) {
            return root;
        }
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            node = queue.front();
            queue.pop();

            if (d == 1) {
                TreeNodeInt* lchild = node->left;
                TreeNodeInt* rchild = node->right;
                node->left = new TreeNodeInt(v);
                node->right = new TreeNodeInt(v);
                node->left->left = lchild;
                node->right->right = rchild;
            }
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
    }
}

/**
 * Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive)
 * @brief rangeSumBST
 * @param root
 * @param int l
 * @param int r
 * @return int total
 */

static int rangeSumBSTTotal = 0;
int rangeSumBST(TreeNodeInt* root, int l, int r)
{
    if (root == nullptr) return 0;
    if (root->left != nullptr) rangeSumBST(root->left, l, r);
    if (root->val >= l && root->val <= r) rangeSumBSTTotal += root->val;
    if (root->right != nullptr) rangeSumBST(root->right, l, r);
    return rangeSumBSTTotal;
}

/**
  * Construct Binary Tree from Preorder and Inorder Traversal
  * preorder = [3,9,20,15,7]          3
  * inorder = [9,3,15,20,7]   ==>    / \
  *                                 9  20
  *                                   /  \
  *                                  15   7
  */

TreeNodeInt* constructFromPreInor(vecInt &pre, vecInt &inor, int preIndex, int left, int right)
{
    if (left > right) return nullptr;
    TreeNodeInt* root = new TreeNodeInt(pre[preIndex]);
//    if (left == right) return root;

    int size = pre.size();
    int mid = 0;
    for (int i = 0; i < size; ++i) {
        if (inor[i] == pre[preIndex]) {
            if (i > 0) mid = i;
        }
    }
    int lenL = mid - left;
    int lenR = right - left - lenL;
    if (lenL > 0) root->left = constructFromPreInor(pre, inor, preIndex + 1, left, mid - 1);
    if (lenR > 0) root->right = constructFromPreInor(pre, inor, preIndex + lenL + 1, mid + 1, right);
    return root;
}

TreeNodeInt* constructFromPreInor(vecInt& pre, vecInt& inor)
{
    if (pre.empty() || inor.empty()) return nullptr;
    return constructFromPreInor(pre, inor, 0, 0, pre.size() - 1);
}

/**
  * Construct Binary Tree from Preorder and Postorder Traversal
  * Return any binary tree that matches the given preorder and postorder traversals.
  * Values in the traversals pre and post are distinct positive integers.
  * 先序遍历的第一个为根节点，第二个为左子节点；后序遍历的最后一个是根，倒数第二个为右子节点
  */

TreeNodeInt* constructFromPrePost(vecInt& pre, vecInt& post, int preRoot, int postRoot)
{
    if (preRoot > postRoot) return nullptr;
    TreeNodeInt* root = new TreeNodeInt(pre[preRoot]);
    if (preRoot == postRoot) return root;

    int size = pre.size();
    int pos = 0;
    int mid = 0;
    for (int leftChildRoot = 0; leftChildRoot < size; ++leftChildRoot) {
        if (post[leftChildRoot] == pre[preRoot]) {
            if (leftChildRoot != 0) pos = post[leftChildRoot - 1];
        }
    }
    for (int i = 0; i < size; ++i) {
        if (pre[i] == pos) {
            if (i != 0) mid = i;
        }
    }

    root->left = constructFromPrePost(pre, post, preRoot + 1, mid - 1);;
    root->right = constructFromPrePost(pre, post, mid, postRoot);;
    return root;
}

TreeNodeInt* constructFromPrePost(vecInt& pre, vecInt& post)
{
    return constructFromPrePost(pre, post, 0, post.size() - 1);
}


/**
  * 108. Convert Sorted Array to Binary Search Tree
  * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
  * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
  *                                     0
  * [-10, -3, 0, 5, 9]   ===>          / \
  *                                  -3   9
  *                                  /   /
  *                                -10  5
  * 中序遍历即符合这种BST,可以使用二分法
  */

TreeNodeInt* sortArrayToBST(vecInt &nums, int left, int right)
{
    if (left > right) return nullptr;

    int mid = left + ((right - left) >> 1);
    TreeNodeInt* root = new TreeNodeInt(nums[mid]);
    root->left = sortArrayToBST(nums, left, mid - 1);
    root->right = sortArrayToBST(nums, mid + 1, right);
    return root;
}

TreeNodeInt* sortArrayToBST(vecInt& nums)
{
    if (nums.empty()) return nullptr;
    return sortArrayToBST(nums, 0, nums.size() - 1);
}

/**
  * Convert Sorted List to Binary Search Tree
  */

ListNodeInt* splitList(ListNodeInt** head)
{
    ListNodeInt* fast = (*head)->next->next;
    ListNodeInt* slow = *head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNodeInt* res = slow->next;
    slow->next = nullptr;
    return res;
}

TreeNodeInt* sortedListToBST(ListNodeInt* head)
{
     if (head == nullptr || head->next == nullptr) return head == nullptr ? nullptr : new TreeNodeInt(head->data);
     ListNodeInt* node = splitList(&head);
     TreeNodeInt* root = nullptr;
     if (node != nullptr) {
         root = new TreeNodeInt(node->data);
         root->left = sortedListToBST(head);
         root->right = sortedListToBST(node->next);
     }
     return root;
}



/**
 * easy
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 * @brief averageOfLevels
 * @param TreeNode<int>* root
 * @return  vector<double>
 * 考察二叉树层序遍历
 */

vecDou averageOfLevels(TreeNodeInt* root) {
    vecDou vec;
    if (root == nullptr) return vec;

    TreeNodeInt* node = nullptr;
    std::queue<TreeNodeInt*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double total = 0;
        for (int i = 0; i < size; ++i) {
            node = q.front();
            q.pop();
            total += node->val;
            std::cout<< node->val <<std::endl;
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        vec.push_back(total/size);
    }
    return vec;
}


/**
 * hard
 * @brief distanceK
 * @param root : root node of tree
 * @param target : current node
 * @return  a list of the values of all nodes that have a distance K from the target node;
 * Each node in the tree has unique values 0 <= node.val <= 500
 *
 * 可以讲该树当成无向图，然后进行DFS或者BFS搜索，找到所有距离为K的所有节点
 * 难点target没有指向父节点的指针，所以从root需要反推
 */
void RootToNode(TreeNodeInt* root, int k, vecInt& vec)
{
    if (root == nullptr) return;
    if (k == 0) vec.push_back(root->val);
    RootToNode(root->left, k - 1, vec);
    RootToNode(root->right, k - 1, vec);
}

int NodesDistanceK(TreeNodeInt* root, int k, TreeNodeInt* target, vecInt& vec)
{
    if (root == nullptr) return -1;

    if (target == root) {
        RootToNode(root, k, vec);
        return 1;
    }
    else {
        int lt = NodesDistanceK(root->left, k, target, vec);
        printf("outside lt = %d\n", lt);
        if (lt >= 0) {
            if (lt == k) {
                vec.push_back(root->val);
            }
            else {
                RootToNode(root->right, k - lt - 1, vec);
            }
            printf("lt = %d\n", lt);
            return lt + 1;
        }

        int rt = NodesDistanceK(root->right, k, target, vec);
        printf("outside rt = %d\n", lt);
        if (rt >= 0) {
            if (rt == k) {
                vec.push_back(root->val);
            }
            else {
                RootToNode(root->left, k - rt - 1, vec);
            }
            printf("rt = %d\n", rt);
            return rt + 1;
        }

        return -1;
    }
}

vecInt distanceK(TreeNodeInt* root, TreeNodeInt* target, int k)
{
    vecInt vec;
    if (root == nullptr) return vec;
    NodesDistanceK(root, k, target, vec);

    return vec;
}

/**
 * Medium
 * @brief all Possible fubll Bossible tree
 * @param n
 * @return vector<TreeNode<int>*>
 * Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree
 * 左右子树一定为奇数，左子树１，２，３则右子树n-1, n-3, n-5(除去根节点)
 */
vecNode allPossibleFBT(int n)
{
    vecNode res;
    if (n == 1) {
        res.push_back(new TreeNodeInt(0));
        return res;
    }
    n--; // 6
    for (int i = 1; i < n; i+=2) {
        vecNode l = allPossibleFBT(i); // 1
        vecNode r = allPossibleFBT(n - i); // 5
        for (TreeNodeInt* lnode : l) {
            for (TreeNodeInt* rnode : r) {
                TreeNodeInt* node = new TreeNodeInt(0);
                node->left = lnode;
                node->right = rnode;
                res.push_back(node);
            }
        }
    }
    return res;
}

/**
 * Medium
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer
 * @brief pruneTree
 * @param root
 * @return  TreeNode<int>*
 * 递归式后序遍历
 */

TreeNodeInt* pruneTree(TreeNodeInt* root)
{
    if (root == nullptr) return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
        root = nullptr;
        printf("delete\n");
    }
    return root;
}

/** ################################################################### Tree End ####################################################################################*/

/** ################################################################### 分治算法 ####################################################################################
 * 分治法的精髓：
 * 分--将问题分解为规模更小的子问题；
 * 治--将这些规模更小的子问题逐个击破；
 * 合--将已解决的子问题合并，最终得出“母”问题的解
 */

// 快速排序,最坏o(n2)     最好o(nlogn)每次区间n/2
// 改进：当递归到一定深度时，得到一个近似排好的序列，然后采用堆排序(内省排序)
int Partition(vecInt& arr, int start, int end){
    int key = arr[start];

    while (start < end) {
        while (start < end && arr[end] >= key) {
            --end;
        }
        swap(arr[start], arr[end]);
        while (start < end && arr[start] <= key) {
            ++start;
        }
        swap(arr[start], arr[end]);
    }
    return start;
}


void QuickSort(vecInt& arr, int start, int end) {
    if (start < end) {
        int mid = Partition(arr, start, end);
        QuickSort(arr, start, mid - 1);
        QuickSort(arr, mid + 1, end);
    }
}
// 快速排序当数据过大时，maximum recursion depth exceeded in comparison,改用栈实现
void QuickSort2(vecInt& arr, int start, int end) {
    if (arr.empty() || start < 0 || end < 0) return;

    std::stack<int> stack;
    stack.push(end);
    stack.push(start);
    int i = 0, j = 0;
    while (!stack.empty()) {
        i = stack.top();
        stack.pop();
        j = stack.top();
        stack.pop();
        if (i < j) {
            int mid = Partition(arr, i, j);
            if (mid > i) {
                stack.push(mid - 1);
                stack.push(i);
            }
            if (mid < j) {
                stack.push(j);
                stack.push(mid + 1);
            }
        }
    }
}

// c++ stl 技法
template<typename Iter>
void swapSort(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type value_type;
    value_type tmp = *begin;
    *begin = *end;
    *end = tmp;
}

template<typename Iter>
Iter Partition2(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type value_type;

    value_type key = *begin;
    while (std::distance(begin, end) > 0) {
        while (std::distance(begin, end) > 0 && *end >= key) {
            std::advance(end, -1);
        }
        swapSort(begin, end); // swap使用move会改变迭代器本身
        while (std::distance(begin, end) > 0 && *begin <= key) {
            std::advance(begin, 1);
        }
        swapSort(begin, end);
    }
    return begin;
}

template<typename Iter>
void QuickSort3(Iter begin, Iter end) {
    if (std::distance(begin, end) > 0) {
        Iter iter = Partition2(begin, end);
        QuickSort3(begin, iter - 1);
        QuickSort3(iter + 1, end);
    }
}

// 归并排序
int Merge(vecInt& arr, int start, int mid, int end) {
    vecInt tmp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= end) tmp.push_back(arr[j++]);
    int size = tmp.size();
    for (i = 0; i < size; ++i) {
        arr[start + i] = tmp[i];
    }
}

void MergeSort(vecInt& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

void adjust(vecInt& arr, int len, int index)
{
    int left = (index << 1) + 1;
    int right = (index << 1) + 2;

    int parent = index;
    if (arr[left] > arr[parent] && left < len) parent = left;
    if (arr[right] > arr[parent] && right < len) parent = right;
    if (parent != index) {
        swap(arr[parent], arr[index]);
        adjust(arr, len, parent);
    }
}

void heapSort(vecInt& arr) {
    int size = arr.size();
    for (int i = (size >> 1) - 1;i >= 0; --i) {
        adjust(arr, size, i);
    }

    for (int i = size - 1; i >=1; --i) {
        swap(arr[0], arr[i]);
        adjust(arr, i, 0);
    }

}

/** ################################################################### 动态规划算法 ####################################################################################
  * 类似分治算法，不同的是适合于用动态规划求解的问题，经分解得到子问题往往不是互相独立的。
  * 若用分治法来解这类问题，则分解得到的子问题数目太多，有些子问题被重复计算了很多次。
  * 如果我们能够保存已解决的子问题的答案，而在需要时再找出已求得的答案，这样就可以避免大量的重复计算，节省时间
  */

//有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法。
// f(n) = f(n-1)+f(n-2)

int steps[10] = {0};

int CalculationSteps(int n) {
    if (n == 1 || n == 2) return n;
    if (steps[n - 1] == 0) steps[n - 1] = CalculationSteps(n - 1);
    if (steps[n - 2] == 0) steps[n - 2] = CalculationSteps(n - 2);
    return steps[n - 1] + steps[n - 2];
}

void Calculation() {
     steps[10] = CalculationSteps(10);
     for (int i = 0; i < 10; ++i) {
         std::cout<<steps[i]<<",";
     }
     std::cout<<std::endl;
}

//给定一个矩阵m，从左上角开始每次只能向右走或者向下走，最后达到右下角的位置，路径中所有数字累加起来就是路径和，返回所有路径的最小路径和，如果给定的m如下，那么路径1,3,1,0,6,1,0就是最小路径和，返回12.

int steps2[4][4] = {0};

int minMatrix(int arr[4][4], int row, int col)
{
    if (row == 0 && col == 0) {
        steps2[row][col] = arr[row][col];
        return steps2[row][col];
    }

    if (col >= 1 && steps2[row][col - 1] == 0) steps2[row][col - 1] = minMatrix(arr, row, col - 1);
    if (row >= 1 && steps2[row - 1][col] == 0) steps2[row - 1][col] = minMatrix(arr, row - 1, col);
    if (row == 0 && col != 0) {
        steps2[row][col] = arr[row][col] + steps2[row][col - 1];
    }
    else if (col == 0 && row != 0) {
        steps2[row][col] = arr[row][col] + steps2[row - 1][col];
    }
    else {
        steps2[row][col] = arr[row][col] + min(steps2[row][col - 1], steps2[row - 1][col]);
    }
    return steps2[row][col];
}

int maxMatrix(int arr[4][4], int row, int col)
{
    if (row < 0 || col < 0) {

    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            steps2[i][j] = max(steps2[i + 1][j] + arr[i][j], steps2[i][j + 1] + arr[i][j]);
        }
    }
    return steps2[row][col];
}

#endif

