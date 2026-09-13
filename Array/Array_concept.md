# Array - Zero se Advanced tak Complete Guide (Hindlish)
### (Code C++ aur Python dono me diya gaya hai)

---

## 1. Array Kya Hota Hai? (Basic Definition)

Array ek **data structure** hai jisme hum **same type ke multiple values** ko **ek hi naam** ke under, **continuous (lagatar) memory locations** me store karte hain.

**Real life example samjho:**
Socho tumhare paas ek **train** hai jisme 5 **compartments** hain, aur sab compartments **ek dusre se juде hue** hain (connected/continuous). Har compartment ka apna number hai (0, 1, 2, 3, 4). Agar tumhe 3rd compartment me jana hai, to tum seedha "compartment number 2" bol sakte ho (kyunki counting 0 se start hoti hai) — tumhe train ke start se chalna nahi padega.

Array bilkul aisa hi hai:
- Har "compartment" = ek **element** (value)
- Har compartment ka number = **index**
- Poori train = **array**

```
Index:     0     1     2     3     4
         +-----+-----+-----+-----+-----+
Array:   | 10  |  25 |  3  |  47 |  8  |
         +-----+-----+-----+-----+-----+
Address: 1000  1004  1008  1012  1016   (agar int 4 bytes ka hai)
```

**Important baat:** Array me sab elements **same data type** ke hote hain (sab int, ya sab char, ya sab string) aur ye memory me **ek ke baad ek (contiguous)** rakhe jaate hain.

---

## 2. Indexing Kaise Kaam Karti Hai

- Zyadatar languages (C, C++, Java, Python, JavaScript) me array **0-based indexing** use karti hain.
- Iska matlab: pehla element index `0` par hota hai, doosra `1` par, aur agar array ka size `n` hai to last element ka index hoga `n-1`.

```
Array size = 5  ->  Valid indexes = 0, 1, 2, 3, 4
```

**Interview me common galti (mistake):** Loop me `i <= n` likh dena, jabki hona chahiye `i < n`. Isse "Index Out of Bounds" error aata hai. Hamesha yaad rakho: **last valid index = size - 1**.

---

## 3. Memory Me Array Kaise Store Hota Hai (Bahut Important)

Ye samajhna zaroori hai ki array itna **fast** kyu hota hai access karne me.

Jab array banaya jata hai, computer memory me ek **continuous block** allocate karta hai. Har element ka address is formula se nikalta hai:

```
Address of arr[i] = Base_Address + (i * size_of_each_element)
```

**Example:**
Agar array `arr` ka base address hai `1000`, aur har element `int` type ka hai (4 bytes), to:

```
arr[0] -> 1000 + (0*4) = 1000
arr[1] -> 1000 + (1*4) = 1004
arr[2] -> 1000 + (2*4) = 1008
arr[3] -> 1000 + (3*4) = 1012
```

Isi formula ki wajah se, array me **kisi bhi index par direct pahuchna (Random Access)** sirf **O(1) time** me ho jata hai — chahe wo index 0 ho ya 1000000, calculation same time lagega. Ye array ki sabse badi taakat hai.

```
       Base Address = 1000
            |
            v
  +-----+-----+-----+-----+-----+
  | 10  | 25  |  3  | 47  |  8  |
  +-----+-----+-----+-----+-----+
  1000  1004  1008  1012  1016
```

---

## 4. Types of Arrays

### A) One-Dimensional (1D) Array
Simple linear list of elements (jo humne upar dekha).

### B) Two-Dimensional (2D) Array (Matrix)
Ye array ka array hota hai — rows aur columns ki form me.

```
        col0  col1  col2
row0 [   1     2     3  ]
row1 [   4     5     6  ]
row2 [   7     8     9  ]
```

Memory me 2D array **row-major order** me store hota hai (zyadatar languages jaise C, C++, Java, Python me):

```
Memory: 1 2 3 4 5 6 7 8 9   (row by row store hota hai)
```

Formula for 2D array address (row-major):
```
Address of arr[i][j] = Base + (i * total_columns + j) * size_of_element
```

### C) Multi-Dimensional Array
3D, 4D arrays bhi possible hain (array of array of array...), but practical use kam hota hai, mostly 1D aur 2D hi interview me common hain.

### D) Static vs Dynamic Array
- **Static Array:** Size fix hota hai, compile time par decide hota hai (jaise C++ ka `int arr[5]`). Size badal nahi sakte.
- **Dynamic Array:** Size runtime par badal sakta hai (jaise Python ki `list`, C++ ka `vector`, Java ka `ArrayList`, JavaScript ka `Array`).

**Dynamic array internally kaise kaam karta hai (bahut important interview concept):**
Jab dynamic array full ho jata hai aur naya element add karna ho, to:
1. Ek **naya bada array** banaya jata hai (usually **double size**)
2. Purane sare elements **copy** kiye jate hain naye array me
3. Naya element add kiya jata hai
4. Purana array **delete/free** kar diya jata hai

Isliye normal insertion O(1) hoti hai, lekin jab resize hota hai tab O(n) lagta hai. Overall (amortized) ye still O(1) mana jata hai.

---

## 5. Array Declaration & Initialization

**C++ (Static array):**
```cpp
int arr[5];                              // declaration
int arr[5] = {10, 20, 30, 40, 50};       // initialization
int arr[] = {1, 2, 3};                   // size auto-decided
```

**C++ (Dynamic array - vector):**
```cpp
#include <vector>
vector<int> arr;                    // empty dynamic array
vector<int> arr(5);                 // size 5, all zero
vector<int> arr = {10, 20, 30, 40, 50};
```

**Python (list, jo dynamic array jaisa behave karta hai):**
```python
arr = [10, 20, 30, 40, 50]
arr = [0] * 5     # size 5, sab zero
```

---

## 6. Basic Operations on Array

### 6.1 Traversal (Sab elements ko visit karna)

**C++:**
```cpp
for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
}
```

**Python:**
```python
for i in range(len(arr)):
    print(arr[i])
```
**Time Complexity:** O(n)

### 6.2 Access
**C++:**
```cpp
int value = arr[3];
```
**Python:**
```python
value = arr[3]
```
**Time Complexity:** O(1)

### 6.3 Search

**a) Linear Search**

**C++:**
```cpp
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

**Python:**
```python
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1
```
Time Complexity: **O(n)**

**b) Binary Search** (sirf sorted array par kaam karta hai)

**C++:**
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

**Python:**
```python
def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```
Time Complexity: **O(log n)**

**Diagram - Binary Search kaise kaam karta hai:**
```
arr = [2, 5, 8, 12, 16, 23, 38, 45]   target = 23

Step1: low=0, high=7, mid=3 -> arr[3]=12 < 23 -> low=4
Step2: low=4, high=7, mid=5 -> arr[5]=23 == 23 -> FOUND!
```

### 6.4 Insertion
Array me beech me element insert karne ke liye, saare elements ko **ek position right shift** karna padta hai.

```
Before insert (insert 99 at index 2):
[10, 20, 30, 40, 50]

Shift elements right from end:
[10, 20, _, 30, 40, 50]  -> shift 40->pos4, 30->pos3
[10, 20, 99, 30, 40]     -> place 99 at index 2
```

**C++:**
```cpp
void insertAt(vector<int>& arr, int index, int value) {
    arr.push_back(0);                      // size badhao
    for (int i = arr.size() - 1; i > index; i--) {
        arr[i] = arr[i - 1];                // right shift
    }
    arr[index] = value;
}
```

**Python:**
```python
def insert_at(arr, index, value):
    arr.append(0)
    for i in range(len(arr) - 1, index, -1):
        arr[i] = arr[i - 1]
    arr[index] = value
```
**Time Complexity:** Worst case O(n)

### 6.5 Deletion

**C++:**
```cpp
void deleteAt(vector<int>& arr, int index) {
    for (int i = index; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];                // left shift
    }
    arr.pop_back();
}
```

**Python:**
```python
def delete_at(arr, index):
    for i in range(index, len(arr) - 1):
        arr[i] = arr[i + 1]
    arr.pop()
```
**Time Complexity:** Worst case O(n)

### 6.6 Update
**C++:**
```cpp
arr[2] = 100;
```
**Python:**
```python
arr[2] = 100
```

---

## 7. Advantages & Disadvantages of Array

**Advantages:**
- Random access O(1) — bahut fast
- Cache-friendly hai (memory contiguous hone ki wajah se CPU cache better use hota hai)
- Simple aur easy to use
- Memory efficient (koi extra pointer overhead nahi, jaise linked list me hota hai)

**Disadvantages:**
- Static array ka size fix hota hai, badal nahi sakte
- Insertion/deletion beech me mehengi hai (O(n))
- Agar bada continuous memory block nahi mila, to allocation fail ho sakta hai

---

## 8. Array vs Linked List (Common Interview Question)

| Feature | Array | Linked List |
|---|---|---|
| Memory | Contiguous | Scattered (nodes with pointers) |
| Access | O(1) random access | O(n) — traverse karna padta hai |
| Insertion/Deletion (middle) | O(n) - shifting | O(1) if pointer available |
| Memory overhead | Kam | Zyada (extra pointer store karna padta hai) |
| Size | Fixed (static) ya resizable (dynamic) | Dynamic hamesha |
| Cache performance | Better | Worse |

---

## 9. Prefix Sum Technique

Prefix sum ek technique hai jisme hum ek naya array banate hain jisme `prefix[i]` = `arr[0] + arr[1] + ... + arr[i]` (start se lekar i tak ka total sum).

```
arr    = [3, 1, 4, 1, 5]
prefix = [3, 4, 8, 9, 14]
```

**Fayda:** Iske baad, kisi bhi range `[l, r]` ka sum **O(1)** me nikal sakte hain:
```
sum(l, r) = prefix[r] - prefix[l-1]
```

**C++:**
```cpp
vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}
```

**Python:**
```python
def build_prefix_sum(arr):
    n = len(arr)
    prefix = [0] * n
    prefix[0] = arr[0]
    for i in range(1, n):
        prefix[i] = prefix[i - 1] + arr[i]
    return prefix
```

---

## 10. Two Pointer Technique

Jab array **sorted** ho, to do pointers use karke problems O(n) me solve ho jaate hain, jabki normal approach O(n²) legi.

**Example: Do numbers dhundo jinka sum = target (sorted array me)**

**C++:**
```cpp
vector<int> twoSumSorted(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) return {left, right};
        else if (currentSum < target) left++;
        else right--;
    }
    return {-1, -1};
}
```

**Python:**
```python
def two_sum_sorted(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1     # sum badhana hai, chota number hatao
        else:
            right -= 1    # sum ghatana hai, bada number hatao
    return [-1, -1]
```

**Diagram:**
```
arr = [2, 7, 11, 15]   target = 18
        L            R
        2 + 15 = 17 < 18  -> left++

arr = [2, 7, 11, 15]
           L        R
           7 + 15 = 22 > 18 -> right--

arr = [2, 7, 11, 15]
           L     R
           7 + 11 = 18 == 18  -> FOUND! [1, 2]
```

---

## 11. Sliding Window Technique

Jab humein array ke **continuous subarray** (window) par kaam karna ho — jaise "maximum sum of subarray of size k" — to poora subarray dobara dobara sum nahi karte, balki window ko slide karte hain.

**Example: Size k ka maximum sum subarray**

**C++:**
```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];
    int maxSum = windowSum;
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];   // naya add, purana remove
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
```

**Python:**
```python
def max_sum_subarray(arr, k):
    window_sum = sum(arr[:k])
    max_sum = window_sum
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i-k]   # naya element add, purana remove
        max_sum = max(max_sum, window_sum)
    return max_sum
```

**Diagram (k=3):**
```
arr = [2, 1, 5, 1, 3, 2]

Window1: [2,1,5] sum=8
Window2:    [1,5,1] sum=7  (remove 2, add 1)
Window3:       [5,1,3] sum=9  (remove 1, add 3)
Window4:          [1,3,2] sum=6  (remove 5, add 2)

Max = 9
```
Time Complexity: **O(n)** instead of O(n*k).

---

## 12. Problem Solve Karne Ka Approach — Kaise Sochein (SABSE IMPORTANT SECTION)

Jab bhi koi array problem mile, is process ko follow karo:

**Step 1: Problem ko achhe se samjho**
- Input kya hai? Output kya chahiye?
- Constraints kya hain (array size kitni badi ho sakti hai — ye batata hai kaunsi time complexity chalegi)
- Example khud se ek chota sa banao aur haath se solve karke dekho

**Step 2: Brute Force socho pehle**
- Sabse simple/obvious solution socho, chahe wo slow ho (O(n²) ya O(n³))
- Ye tumhe problem samajhne me help karega

**Step 3: Pattern pehchano**

| Signal in Problem | Likely Technique |
|---|---|
| "Sorted array" + "pair/triplet sum" | Two Pointer |
| "Subarray/substring of size k" | Sliding Window |
| "Range sum queries" (multiple) | Prefix Sum |
| "Maximum/minimum subarray sum" | Kadane's Algorithm |
| "Duplicate/missing number" | Hashing ya XOR |
| "Next greater/smaller element" | Stack |
| "Kth largest/smallest" | Heap ya Sorting |
| "0s, 1s, 2s sort karo" | Dutch National Flag |
| "In-place, O(1) space" | Swapping / index marking tricks |

**Step 4: Optimize karo**
- Kya extra space use karke time bacha sakte ho? (Hashmap, prefix array)
- Kya sorting se help milegi?
- Kya do pointer ya sliding window fit hota hai?

**Step 5: Dry run karo**
Code likhne se pehle, ek chote example par haath se (pen-paper style) trace karo. Ye galtiyan pakadne me sabse zyada help karta hai.

**Step 6: Edge cases socho**
- Empty array
- Single element array
- All elements same
- Already sorted / reverse sorted
- Negative numbers
- Duplicate values

---

## 13. Time & Space Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| Access (by index) | O(1) |
| Search (unsorted) | O(n) |
| Search (sorted - binary search) | O(log n) |
| Insertion (end) | O(1) amortized |
| Insertion (beginning/middle) | O(n) |
| Deletion (end) | O(1) |
| Deletion (beginning/middle) | O(n) |
| Traversal | O(n) |

---

## 14. Frequently Asked Interview Problems

### Problem 1: Reverse an Array
**Approach:** Two pointer - ek start se, ek end se, swap karte jao jab tak wo cross na ho jayein.

**C++:**
```cpp
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
```

**Python:**
```python
def reverse_array(arr):
    left, right = 0, len(arr) - 1
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    return arr
```
Time: O(n), Space: O(1)

---

### Problem 2: Find the Second Largest Element
**Approach:** Ek pass me hi largest aur second largest dono track karo, sorting ki zaroorat nahi.

**C++:**
```cpp
int secondLargest(vector<int>& arr) {
    long long first = LLONG_MIN, second = LLONG_MIN;
    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num != first) {
            second = num;
        }
    }
    return second;
}
```

**Python:**
```python
def second_largest(arr):
    first = second = float('-inf')
    for num in arr:
        if num > first:
            second = first
            first = num
        elif num > second and num != first:
            second = num
    return second
```
Time: O(n), Space: O(1)
**Common galti:** Sort karke `arr[-2]` le lena — ye kaam to karega but O(n log n) hoga, jabki O(n) me ho sakta hai.

---

### Problem 3: Move All Zeros to End
**Approach:** Do pointer — ek pointer jo "next non-zero position" track kare.

**C++:**
```cpp
void moveZeros(vector<int>& arr) {
    int pos = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[pos], arr[i]);
            pos++;
        }
    }
}
```

**Python:**
```python
def move_zeros(arr):
    pos = 0
    for i in range(len(arr)):
        if arr[i] != 0:
            arr[pos], arr[i] = arr[i], arr[pos]
            pos += 1
    return arr
```
**Diagram:**
```
arr = [0, 1, 0, 3, 12]
pos=0
i=0: arr[0]=0, skip
i=1: arr[1]=1 !=0, swap(0,1) -> [1,0,0,3,12], pos=1
i=2: arr[2]=0, skip
i=3: arr[3]=3 !=0, swap(1,3) -> [1,3,0,0,12], pos=2
i=4: arr[4]=12 !=0, swap(2,4) -> [1,3,12,0,0], pos=3

Result: [1, 3, 12, 0, 0]
```
Time: O(n), Space: O(1)

---

### Problem 4: Find Duplicate Number
**Approach (if numbers are 1 to n):** Har number ko uske apne index par mark karo (negative kar do), agar already negative mila to wahi duplicate hai.

**C++:**
```cpp
int findDuplicate(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int index = abs(arr[i]);
        if (arr[index] < 0) return index;
        arr[index] = -arr[index];
    }
    return -1;
}
```

**Python:**
```python
def find_duplicate(arr):
    for num in arr:
        index = abs(num)
        if arr[index] < 0:
            return index
        arr[index] = -arr[index]
    return -1
```
Time: O(n), Space: O(1) — ya simple approach: Hashset/unordered_set use karo (Space O(n) but easy to write).

---

### Problem 5: Find Missing Number (1 to n)
**Approach:** Sum formula use karo.

**C++:**
```cpp
int findMissing(vector<int>& arr, int n) {
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    for (int num : arr) actualSum += num;
    return expectedSum - actualSum;
}
```

**Python:**
```python
def find_missing(arr, n):
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(arr)
    return expected_sum - actual_sum
```
Time: O(n), Space: O(1)
(Alternative: XOR technique bhi use hoti hai jo overflow-safe hai bade numbers ke liye)

---

### Problem 6: Two Sum (Unsorted Array)
**Approach:** Hashmap use karo - complement dhundo.

**C++:**
```cpp
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[arr[i]] = i;
    }
    return {-1, -1};
}
```

**Python:**
```python
def two_sum(arr, target):
    seen = {}
    for i, num in enumerate(arr):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return [-1, -1]
```
Time: O(n), Space: O(n)
**Ye bahut famous interview question hai — Amazon, Google, Microsoft sab me poochi jaati hai.**

---

### Problem 7: Kadane's Algorithm (Maximum Subarray Sum)
**Problem:** Continuous subarray dhundo jiska sum maximum ho.
**Approach:** Har position par decide karo — "kya current element ko purane subarray me jodna better hai ya naya subarray current element se start karna better hai?"

**C++:**
```cpp
int kadane(vector<int>& arr) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
```

**Python:**
```python
def kadane(arr):
    max_sum = arr[0]
    current_sum = arr[0]
    for i in range(1, len(arr)):
        current_sum = max(arr[i], current_sum + arr[i])
        max_sum = max(max_sum, current_sum)
    return max_sum
```

**Diagram:**
```
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: current=-2, max=-2
i=1: current=max(1, -2+1=-1)=1, max=1
i=2: current=max(-3, 1-3=-2)=-2, max=1
i=3: current=max(4, -2+4=2)=4, max=4
i=4: current=max(-1, 4-1=3)=3, max=4
i=5: current=max(2, 3+2=5)=5, max=5
i=6: current=max(1, 5+1=6)=6, max=6
i=7: current=max(-5, 6-5=1)=1, max=6
i=8: current=max(4, 1+4=5)=5, max=6

Answer = 6  (subarray: [4,-1,2,1])
```
Time: O(n), Space: O(1)
**Ye sabse zyada poocha jane wala array problem hai interviews me.**

---

### Problem 8: Rotate Array by K Positions
**Approach (best - Reversal Algorithm):**
1. Poora array reverse karo
2. Pehle k elements reverse karo
3. Baaki n-k elements reverse karo

**C++:**
```cpp
void reverseRange(vector<int>& arr, int l, int r) {
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    reverseRange(arr, 0, n - 1);
    reverseRange(arr, 0, k - 1);
    reverseRange(arr, k, n - 1);
}
```

**Python:**
```python
def rotate(arr, k):
    n = len(arr)
    k = k % n
    def reverse(a, l, r):
        while l < r:
            a[l], a[r] = a[r], a[l]
            l += 1
            r -= 1
    reverse(arr, 0, n-1)
    reverse(arr, 0, k-1)
    reverse(arr, k, n-1)
    return arr
```

**Diagram (arr=[1,2,3,4,5,6,7], k=3):**
```
Original:        [1,2,3,4,5,6,7]
Full reverse:    [7,6,5,4,3,2,1]
Reverse first k: [5,6,7,4,3,2,1]
Reverse rest:    [5,6,7,1,2,3,4]   <- Final Answer
```
Time: O(n), Space: O(1)

---

### Problem 9: Dutch National Flag Algorithm (Sort 0s, 1s, 2s)
**Approach:** Teen pointers use karo — low, mid, high.

**C++:**
```cpp
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
```

**Python:**
```python
def sort_012(arr):
    low, mid, high = 0, 0, len(arr) - 1
    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:  # arr[mid] == 2
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1
    return arr
```
Time: O(n), Space: O(1) — sirf ek pass me sorting ho jati hai bina comparison-based sort use kiye.

---

### Problem 10: Best Time to Buy and Sell Stock (Max Profit)
**Approach:** Ab tak ka minimum price track karo, aur har din potential profit calculate karo.

**C++:**
```cpp
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}
```

**Python:**
```python
def max_profit(prices):
    min_price = float('inf')
    max_profit = 0
    for price in prices:
        min_price = min(min_price, price)
        max_profit = max(max_profit, price - min_price)
    return max_profit
```
Time: O(n), Space: O(1)

---

### Problem 11: Trapping Rain Water
**Approach:** Har position par pani utna hi rukega jitna `min(left_max, right_max) - current_height` hoga.

**C++:**
```cpp
int trapRainWater(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);
    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];
    return water;
}
```

**Python:**
```python
def trap_rain_water(height):
    n = len(height)
    left_max = [0]*n
    right_max = [0]*n
    left_max[0] = height[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], height[i])
    right_max[n-1] = height[n-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], height[i])
    water = 0
    for i in range(n):
        water += min(left_max[i], right_max[i]) - height[i]
    return water
```
Time: O(n), Space: O(n) (optimize karke O(1) space me bhi ho sakta hai two-pointer se)

---

### Problem 12: Product of Array Except Self
**Approach:** Bina division use kiye, left product aur right product arrays banao.

**C++:**
```cpp
vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++) {
        result[i] = left;
        left *= arr[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= right;
        right *= arr[i];
    }
    return result;
}
```

**Python:**
```python
def product_except_self(arr):
    n = len(arr)
    result = [1]*n
    left = 1
    for i in range(n):
        result[i] = left
        left *= arr[i]
    right = 1
    for i in range(n-1, -1, -1):
        result[i] *= right
        right *= arr[i]
    return result
```
Time: O(n), Space: O(1) extra (output array ko nahi ginte)

---

### Problem 13: Majority Element (Boyer-Moore Voting Algorithm)
**Problem:** Wo element dhundo jo array me n/2 se zyada baar aaye.

**C++:**
```cpp
int majorityElement(vector<int>& arr) {
    int count = 0;
    int candidate = 0;
    for (int num : arr) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}
```

**Python:**
```python
def majority_element(arr):
    count = 0
    candidate = None
    for num in arr:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate
```
Time: O(n), Space: O(1)
**Intuition:** Har baar jab count 0 hota hai, hum candidate change kar dete hain. Majority element hamesha survive karega kyunki wo dusre sabse zyada baar hai.

---

## 15. Common Mistakes Jo Beginners Karte Hain

1. **Off-by-one errors** — loop me `<=` aur `<` ka confusion, index out of bounds
2. Array modify karte waqt (jaise delete/insert) loop me forward jaana, jabki kabhi kabhi **backward loop** zyada safe hota hai
3. Empty array ya single element array ka edge case bhool jana
4. Brute force (O(n²)) hi likh dena bina optimize kiye — interview me hamesha poocho khud se "kya isse better ho sakta hai?"
5. Sorted array assume kar lena jabki diya nahi gaya — hamesha problem statement dobara padho
6. C++ me `vector` ka size() function `unsigned int` return karta hai — agar loop me `i` ko negative karna ho (jaise reverse loop), to `int` me convert karna na bhoolo, warna infinite loop ho sakta hai

---

## 16. Practice Karne Ka Roadmap

1. Pehle basic operations achi tarah practice karo (traverse, search, insert, delete)
2. Fir Two Pointer aur Sliding Window wale problems karo
3. Fir Prefix Sum wale problems
4. Fir Kadane's + Dutch Flag + Rotation jaise medium problems
5. Last me Trapping Rain Water, Product Except Self jaise thoda tricky problems

**Practice platforms:** LeetCode (Array tag), GeeksforGeeks, Codeforces (starting problems)

---

## Summary (Ek Nazar Me)

- Array = same-type elements, contiguous memory
- Access O(1), Search O(n)/O(log n), Insert/Delete O(n) worst case
- Important techniques: Two Pointer, Sliding Window, Prefix Sum, Kadane's, Dutch Flag
- Interview me pattern pehchanna sabse zaroori skill hai — problem padho, signal dhundo, technique match karo
- Hamesha brute force se start karo, phir optimize karo, phir edge cases check karo

Agar tumhe kisi bhi topic (jaise Kadane's algorithm ya Sliding Window) ko aur deeply, more examples ke saath samajhna hai, to bata dena — main us par alag se detailed explanation de sakta hoon.