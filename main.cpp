#include "LeetCodeSolution.h"

void FuncTestTwoSum()
{
    vecInt test;
    for (int i = 0; i < 10; ++i) {
        test.push_back(i);
    }

    for (pairInt i : twoSum(test, 13)) {
        std::cout<<i.first<<","<<i.second<<std::endl;
    }
}

void FuncTestAddTwoNum()
{
    ListNode<int>* l1 = new ListNode<int>;
    ListNode<int>* l2 = new ListNode<int>;
    l1->insert(2);
    l1->insert(4);
    l1->insert(3);

    l2->insert(5);
    l2->insert(6);
    l2->insert(4);

    ListNode<int>* result = addTwoNum(l1, l2);
    Node<int>* node = result->head->next;
    while (node != nullptr) {
        std::cout<<node->data<<"->";
        node = node->next;
    }
    std::cout<<std::endl;
}

void FuncTestInorderTraversal()
{
    TreeNodeInt* temp2 = new TreeNodeInt(3);
    TreeNodeInt* temp4 = new TreeNodeInt(5);
    TreeNodeInt* tem3 = new TreeNodeInt(4);
    TreeNodeInt* temp1 = new TreeNodeInt(2);
    temp1->left = temp2;
    temp1->right = temp4;
    TreeNodeInt* node = new TreeNodeInt(1);
    node->val = 1;
    node->right = temp1;
    node->left = tem3;

    vecInt vec;
    vec = inorderTraversal(node);
    for (int i : vec) {
        printf("%d \n", i);
    }
}

void FuncTestAddOneRowToTree()
{
    TreeNodeInt* root = new TreeNodeInt(4);

    TreeNodeInt* node1 = new TreeNodeInt(2);
    node1->left = new TreeNodeInt(3);
    node1->right = new TreeNodeInt(1);
    TreeNodeInt* node4 = new TreeNodeInt(6);
    node4->left = new TreeNodeInt(5);
    root->left = node1;
    root->right = node4;

    vecInt vec = inorderTraversal(addOneRowToTree(root, 1, 2));
    printf(" printf \n");
    for (int i : vec) {
        printf("%d \n", i);
    }
}

void FuncTestAllNodesDistanceKInBinaryTree()
{
    TreeNodeInt* root = new TreeNodeInt(0);

    TreeNodeInt* lchild = new TreeNodeInt(2);
//    TreeNodeInt* node1 = new TreeNodeInt(6);
//    TreeNodeInt* node2 = new TreeNodeInt(2);
//    node2->left = new TreeNodeInt(7);
//    node2->right = new TreeNodeInt(4);
//    lchild->left = node1;
//    lchild->right = node2;

    TreeNodeInt* rchild = new TreeNodeInt(1);
    rchild->left = new TreeNodeInt(3);
//    rchild->right = new TreeNodeInt(8);

    root->right = rchild;
    root->left = lchild;
    vecInt vec = distanceK(root, rchild->left, 3);

    for (int i : vec) {
        printf("%d \n", i);
    }
}

void FuncTestMaxArea()
{
    int vec[] = {1,8,6,2,5,4,8,3,7};
    vecInt vecI(vec, vec + 9);
    int maxArea = MaxArea(vecI);
    printf("maxArea = %d\n", maxArea);
}

void FuncTestAverageOfLevels()
{
    TreeNodeInt* root = new TreeNodeInt(3);
    TreeNodeInt* lchild = new TreeNodeInt(9);
    TreeNodeInt* rchild = new TreeNodeInt(20);
    rchild->left = new TreeNodeInt(15);
    rchild->right = new TreeNodeInt(7);
    root->left = lchild;
    root->right = rchild;

    vecDou vec = averageOfLevels(root);

    for (double i : vec) {
        std::cout<< i << std::endl;
    }
}

void FuncTestInsertIntoBST()
{
    TreeNodeInt* root = nullptr;
    for (int i = 0; i < 6; ++i) {
        root = insertIntoBST(root, i);
    }

    SequenceTraversal(root);
}

void FuncTestCompareSameTree()
{
    TreeNodeInt* root = new TreeNodeInt(3);
    TreeNodeInt* lchild = new TreeNodeInt(9);
//    lchild->left = new TreeNodeInt(10);
    TreeNodeInt* rchild = new TreeNodeInt(20);
    rchild->left = new TreeNodeInt(15);
    rchild->right = new TreeNodeInt(7);
    root->left = lchild;
    root->right = rchild;


    TreeNodeInt* root2 = new TreeNodeInt(3);
    TreeNodeInt* lchild2 = new TreeNodeInt(9);
    TreeNodeInt* rchild2 = new TreeNodeInt(20);
    rchild2->left = new TreeNodeInt(15);
    rchild2->right = new TreeNodeInt(7);
    root2->left = lchild2;
    root2->right = rchild2;
    std::cout<<sameTree(root, root2)<<std::endl;
}

// 0, 2, 1 ,6 ,7 ,4
void FuncTestBSTIterator()
{
    TreeNodeInt* root = new TreeNodeInt(6);

    TreeNodeInt* lchild = new TreeNodeInt(2);
    TreeNodeInt* node1 = new TreeNodeInt(1);
    TreeNodeInt* node2 = new TreeNodeInt(4);
    node2->left = new TreeNodeInt(3);
    node2->right = new TreeNodeInt(5);
    lchild->left = node1;
    lchild->right = node2;

    TreeNodeInt* rchild = new TreeNodeInt(8);
    rchild->left = new TreeNodeInt(7);
    rchild->right = new TreeNodeInt(9);
    root->left = lchild;
    root->right = rchild;

    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) {
        std::cout<<i.next()<<std::endl;
    }

}

void FuncTestAllPossibleFBT()
{
    vecNode vecnode = allPossibleFBT(7);

    for (TreeNodeInt* node : vecnode) {
        SequenceTraversal(node);
    }
}

void FuncTestPruneTree() {
    TreeNodeInt* root = new TreeNodeInt(1);

    TreeNodeInt* rchild = new TreeNodeInt(0);
    TreeNodeInt* node1 = new TreeNodeInt(0);
    TreeNodeInt* node2 = new TreeNodeInt(1);
    rchild->left = node1;
    rchild->right = node2;
    root->right = rchild;

    TreeNodeInt* lchild = new TreeNodeInt(1);
    TreeNodeInt* node3 = new TreeNodeInt(1);
    TreeNodeInt* node4 = new TreeNodeInt(1);
    node3->left = new TreeNodeInt(0);
    lchild->left = node3;
    lchild->right = node4;
    root->left = lchild;
    PreorderTraversal(pruneTree(root));
}

void FuncTestConstructFromPrePostTree()
{
    vecInt pre = {1,2,4,5,3,6,7};
    vecInt post = {4,5,2,6,7,3,1};

    TreeNodeInt* root = constructFromPrePost(pre, post);

    SequenceTraversal(root);
    PostTraversal(root);
}

void FuncTestConstructFromPreInortTree()
{
    vecInt preorder = {1, 2};
    vecInt inorder = {1, 2};
    TreeNodeInt* root = constructFromPreInor(preorder, inorder);
    SequenceTraversal(root);
    PostTraversal(root);
}

void FuncTestSortArrayToBST()
{
    vecInt vec = {-10,-3,0,5,9};
    SequenceTraversal(sortArrayToBST(vec));
}

void FuncTestBinarySearch()
{
    int vec[] = {-1, 0, 3, 5, 9, 12, 8};
    vecInt vecI(vec, vec + 7);
    std::cout<<search(vecI, 5)<<std::endl;
}
void FuncTestFindDupLicate()
{
    int vec[] = {1,3,4,2,2};
    vecInt vecI(vec, vec + 5);
    std::cout<<findDupLicate(vecI)<<std::endl;
}

void FuncTestLinkedListCycle()
{
    ListNodeInt* head = new ListNodeInt(0);
    ListNodeInt* one = new ListNodeInt(1);
    ListNodeInt* two = new ListNodeInt(2);
    ListNodeInt* three = new ListNodeInt(3);
    ListNodeInt* four = new ListNodeInt(4);
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = head;
    std::cout<<hasCycle(head)<<std::endl;
}

void FuncTestLinedListCyCleII()
{
    ListNodeInt* head = new ListNodeInt(0);
    ListNodeInt* one = new ListNodeInt(1);
    ListNodeInt* two = new ListNodeInt(2);
    ListNodeInt* three = new ListNodeInt(3);
    ListNodeInt* four = new ListNodeInt(4);
    ListNodeInt* five = new ListNodeInt(5);
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = two;
    std::cout<<detectCycle(head)->data<<std::endl;
}

void FuncTestReverseList()
{
    ListNodeInt* head = new ListNodeInt(1);
    ListNodeInt* two = new ListNodeInt(2);
    ListNodeInt* three = new ListNodeInt(3);
    ListNodeInt* four = new ListNodeInt(4);
    ListNodeInt* five = new ListNodeInt(5);
    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    ListNodeInt* res = reverseList(head);

    while (res) {
        std::cout<<res->data<<std::endl;
        res = res->next;
    }
}

void FuncTestInsertionSortList()
{
    ListNodeInt* head = new ListNodeInt(4);
    ListNodeInt* two = new ListNodeInt(2);
    ListNodeInt* three = new ListNodeInt(1);
    ListNodeInt* four = new ListNodeInt(3);
    ListNodeInt* five = new ListNodeInt(5);
    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;
    ListNodeInt* res = insertionSortList(head);
    while (res) {
        std::cout<<res->data<<std::endl;
        res = res->next;
    }
}

void FuncTestminPathMatrix()
{
    int arr[4][4] = {{4,1,5,3},{3,2,7,7},{6,5,2,8},{8,9,4,5}};

    steps2[4][4] = minMatrix(arr, 4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout<<"i = "<<i<<" j = "<<j<<" steps = "<<steps2[i][j]<<std::endl;
        }
    }
}

void FuncTestCalSteps()
{
    Calculation();
}

void FuncTestQuickSort()
{
    int a[] = {49,38,65,97,76,13,27};
    vecInt arr(a, a + 7);
//    QuickSort(arr, 0, 6);
//    QuickSort2(arr, 0, 6);
    QuickSort3(arr.begin(), arr.end() -1);

    for (int i : arr) {
        std::cout<<i<<std::endl;
    }
}

void FuncTestMergeSort()
{
    int a[] = {49,38,65,97,76,13,27};
    vecInt arr(a, a + 7);
    MergeSort(arr, 0, 6);
    for (int i : arr) {
        std::cout<<i<<std::endl;
    }
}

void FuncTestPartitionList()
{
    ListNodeInt* head = new ListNodeInt(1);
    ListNodeInt* two = new ListNodeInt(4);
    ListNodeInt* three = new ListNodeInt(3);
    ListNodeInt* four = new ListNodeInt(2);
    ListNodeInt* five = new ListNodeInt(5);
    ListNodeInt* six = new ListNodeInt(2);
    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;

    ListNodeInt* res = partitionList(head, 3);
    while (res) {
        std::cout<<res->data<<std::endl;
        res = res->next;
    }
}

void FuncTestMergeTwoList()
{
    ListNodeInt* head = new ListNodeInt(1);
    ListNodeInt* two = new ListNodeInt(2);
    ListNodeInt* three = new ListNodeInt(5);

    ListNodeInt* head1 = new ListNodeInt(1);
    ListNodeInt* two1 = new ListNodeInt(3);
    ListNodeInt* three1 = new ListNodeInt(4);
    head->next = two;
    two->next = three;
    head1->next = two1;
    two1->next = three1;

    ListNodeInt* node = mergeTwoList(head, head1);
    std::cout<<"---"<<std::endl;
    while (node) {
        std::cout<<node->data<<std::endl;
        node = node->next;
    }
}

void FuncTestConvertListToBST()
{
    ListNodeInt* head = new ListNodeInt(-10);
    ListNodeInt* two = new ListNodeInt(-3);
    ListNodeInt* three = new ListNodeInt(0);
    ListNodeInt* four = new ListNodeInt(9);
    ListNodeInt* five = new ListNodeInt(5);
    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    SequenceTraversal(sortedListToBST(head));
}

void test11(int& i) {
    printf("%d\n", i);
    ++i;
}
void test2(int&& i) {
    printf("%d\n", i);
    ++i;
}

int MyStrcmp(const char* str1, const char* str2)
{
    if (str1 == nullptr || str2 == nullptr) { throw "error input is nullptr";}

    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*(unsigned char*)str1 < *(unsigned char*)str2) return -1;
    else if (*(unsigned char*)str1 > *(unsigned char*)str2) return 1;
    else return 0;
}

char* MyStrcat(char* dest, const char* src)
{
    char* res = dest;
    if (src == nullptr || dest == nullptr) { throw "error input is nullptr";}

    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';

    return res;
}

char* MyStrcpy(char* dest, const char* src)
{
    char* res = dest;
    if (src == nullptr || dest == nullptr) {throw "error input is nullptr";}

    while (*dest || *src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return res;
}

// 拷贝的是字节
void* MyMemcpy(void* dest, const void* src, size_t n)
{
    char* pdest;
    char* psrc;
    if (!n) return dest;
    if (src == nullptr || dest == nullptr) {throw "error input is nullptr";}

    if (src >= dest || (char*)dest >= (char*)src + n - 1) {
        pdest = (char*)dest;
        psrc = (char*)src;
        while (n--) {
            *pdest++ = *psrc++;
        }
    }
    else {
        pdest = (char*)dest + n - 1;
        psrc = (char*)src + n - 1;
        while (n--) {
            *pdest-- = *psrc--;
        }
    }
    return dest;
}

void FuncTestAoti()
{
    std::string str = "23948230832589692831234";
    int num = strAtoi(str.c_str());
    std::cout<<num<<std::endl;
    std::cout<<atoiStatus<<std::endl;

}

void FuncTestCOperFunc()
{
    char* test1 = "hello";
    char test2[20] = "hello";
    char* test3 = "world";

    std::cout<<"test strcmp: "<<MyStrcmp(test1, test2)<<std::endl;
    std::cout<<"test strcmp: "<<MyStrcmp(test1, test3)<<std::endl;
    std::cout<<"test strcat: "<<MyStrcat(test2, test3)<<std::endl;
    std::cout<<"test strcat: "<<test2<<std::endl;
    std::cout<<"test strcat: "<<MyStrcpy(test2, test3)<<std::endl;
    std::cout<<"test strcat: "<<test2<<std::endl;

    std::cout<<"test memcpy: "<<(char*)MyMemcpy(test2, test1, 3)<<std::endl;
    std::cout<<"test memcpy: "<<test2<<std::endl;
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    MyMemcpy(arr, arr, 2 * sizeof(int));
    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;

    char mem[20] = "hello world !";
    std::cout<<"test memcpy: "<<(char*)MyMemcpy(mem + 5, mem, 5)<<std::endl;

//    std::cout<<"test memcpy: "<<test2<<std::endl;
}

void FuncTestMKPMatchString()
{
    std::cout<<KMPmatchString("asABCABEdsgasdg", "ABCABE")<<std::endl;
}

void FuncTestHeapSort()
{
    vecInt arr = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(arr);
    for (int i : arr) {
        std::cout<<i<<std::endl;
    }
}


class A {
public:
    A(int in, short _c):
        a(in),
        c(_c)
    {
    }
    virtual void test(){std::cout<<"A"<<std::endl;}

    const int a;
    short c;
};

class B
{
public:
    B():a(10) {}
    int a;
};

class D : public B{
public:

    int a;
};


class C : public A
{
public:
    C(int in, int shor):A(in, shor){}
    virtual void test(){ std::cout<<"C"<<std::endl;}
    int d;
};

template<typename T>
struct display{
    void operator() (const T& t) const {
        std::cout<<t<<std::endl;
    }
};

template<typename T>
void _print(T& t){
    std::cout<<"lvalue"<<std::endl;
}
template<typename T>
void _print(T&& t){
    std::cout << "rvalue" << std::endl;
}

template<typename T>
void TestForward(T && v){
    std::cout << "TestForward" << std::endl;
    _print(v);
    _print(std::forward<T>(v));
    _print(std::move(v));
}

#include<algorithm>
#include <unordered_map>

void otherTest()
{
    int i = (7 + 7) & -8;
    std::cout<<i<<std::endl;
    array<int, 5> ar={1, 2, 3, 4, 5};
//    std::vector<int> ar = {1, 2, 3, 4};
    std::for_each(ar.begin(), ar.end(), display<int>());
    std::cout<<gaode<<std::endl;

    unsigned int a = 6;
    int b = -19;
    std::cout<<a + b<< ","<<~0<<std::endl;

    std::vector<int> arr = {0,1,2,3,4,5,6,7};
    std::cout<<arr.size()<<", "<<arr.capacity()<<std::endl;
    arr.push_back(8);
    std::cout<<arr.size()<<", "<<arr.capacity()<<std::endl;

    std::cout<<*(arr.end())<<std::endl;
    std::unordered_map<string ,string> unMap;
    unMap.insert(std::unordered_map<string ,string>::value_type("t", "test"));
    std::cout<<unMap["t"]<<std::endl;
    std::list<int> ilist= {13,21,32,45, 12};
    ilist.push_back(934);

    for (std::list<int>::const_iterator it = ilist.begin(); it != ilist.end(); ++it) {
        std::cout<<*it<<std::endl;
    }
    std::cout<<*(ilist.end())<<std::endl;

    std::cout<<"======================================="<<std::endl;
    C a11(1 ,2.3);
    A c11 = a11;
    a11.test();
    c11.test();
    B b11;

    D d11;
    int && dfsd= 1;
    std::cout<<b11.a<<std::endl;
    std::cout<<d11.a<<std::endl;
    std::map<int ,string> map11= {{1, "1"},{2,"2"},{3,"3"}};
    for(pair<int, string> p : map11){
        std::cout<<p.first<<std::endl;
    }

    std::cout<<"======================================="<<std::endl;
    TestForward(1);
    int x = 1;
    TestForward(x);
    TestForward(std::forward<int>(x));
    std::deque<int> ideq(20, 9);
    std::cout<<ideq.size()<<std::endl;

    bool boooooo;
    std::cout<<boooooo<<std::endl;
}

int funcccc(int x)
{
    int countx = 0;

    while(x) {
        countx ++;
        std::cout<<bitset<sizeof(int)*8> (x)<<std::endl;
        std::cout<<bitset<sizeof(int)*8> (x-1)<<std::endl;
        x = x&(x - 1);
        std::cout<<bitset<sizeof(int)*8> (x)<<std::endl;
        std::cout<<"======="<<std::endl;
    }

    return countx;

}

class AAA
{
public:
    AAA() {std::cout<<"AAA()"<<std::endl;}
    AAA(const AAA&) {std::cout<<"AAA(const AAA&)"<<std::endl;}
    AAA& operator = (const AAA&) {std::cout<<"AAA& operator = (const AAA&)"<<std::endl;}
    ~AAA() {std::cout<<"~AAA()"<<std::endl;}

    void setA(int a) {m_a = a;}
    int getA() const noexcept { return m_a;}

private:
    int m_a;
    B m_b;
};

AAA retrurnA()
{
    AAA a;
    a.setA(1994);
    return a;
}

void TestReturnA(AAA a)
{

    std::vector<AAA> vec;

    vec.push_back(a);

//    std::cout<<a.getA()<<std::endl;
}

int main()
{

//    FuncTestTwoSum();
//    FuncTestAddTwoNum();
//    FuncTestMaxArea();
//    FuncTestInorderTraversal();
//    FuncTestAddOneRowToTree();
//    printf("%s \n", addBinary("1010", "10111").c_str());
//    FuncTestAllNodesDistanceKInBinaryTree();
//    FuncTestAverageOfLevels();
//    FuncTestBSTIterator();
//    FuncTestAllPossibleFBT();
//    FuncTestPruneTree();
//    FuncTestBinarySearch();
//    FuncTestFindDupLicate();
//    FuncTestLinkedListCycle();
//    FuncTestLinedListCyCleII();
//    FuncTestReverseList();
//    FuncTestInsertionSortList();
//    FuncTestCalSteps();
//    FuncTestminPathMatrix();
//    FuncTestQuickSort();
//    FuncTestMergeSort();
//    FuncTestCOperFunc();
//    FuncTestAoti();
//    FuncTestPartitionList();
//    FuncTestHeapSort();
//    FuncTestInsertIntoBST();
//    FuncTestCompareSameTree();
//    FuncTestConstructFromPrePostTree();
//    FuncTestConstructFromPreInortTree();
//    FuncTestSortArrayToBST();
//    FuncTestMergeTwoList();
//    FuncTestConvertListToBST();
//    FuncTestMKPMatchString();

//    std::cout<<funcccc(9999);
    TestReturnA(retrurnA());

}
