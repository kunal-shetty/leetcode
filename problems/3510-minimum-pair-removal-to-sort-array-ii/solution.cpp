// 3510. Minimum Pair Removal to Sort Array II
// Difficulty: Hard
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/
// Runtime: 1001 ms (beats —)
// Memory: 234.8 MB (beats —)
// Submitted: 2026-01-23

class Solution {
private:
    struct Node {
        long long value;
        int originalIndex;
        Node* previous;
        Node* next;
        
        Node(long long val, int idx) : value(val), originalIndex(idx), previous(nullptr), next(nullptr) {}
    };
    
    struct Item {
        Node* firstNode;
        Node* secondNode;
        long long pairSum;
        
        Item(Node* first, Node* second, long long sum) 
            : firstNode(first), secondNode(second), pairSum(sum) {}
        
        bool operator>(const Item& other) const {
            if (pairSum == other.pairSum) {
                return firstNode->originalIndex > other.firstNode->originalIndex;
            }
            return pairSum > other.pairSum;
        }
    };
    
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        priority_queue<Item, vector<Item>, greater<Item>> pq;
        vector<bool> isMerged(n, false);
        int inversionCount = 0;
        int operationCount = 0;
        
        vector<Node*> nodeList;
        nodeList.push_back(new Node(nums[0], 0));
        
        for (int i = 1; i < n; i++) {
            nodeList.push_back(new Node(nums[i], i));
            
            nodeList[i - 1]->next = nodeList[i];
            nodeList[i]->previous = nodeList[i - 1];
            
            Item newItem(nodeList[i - 1], nodeList[i], 
                        nodeList[i - 1]->value + nodeList[i]->value);
            pq.push(newItem);
            
            if (nums[i - 1] > nums[i]) {
                inversionCount++;
            }
        }
        
        while (inversionCount > 0) {
            if (pq.empty()) {
                break;
            }
            
            Item currentItem = pq.top();
            pq.pop();
            
            Node* first = currentItem.firstNode;
            Node* second = currentItem.secondNode;
            long long currentSum = currentItem.pairSum;
            
            if (isMerged[first->originalIndex] || 
                isMerged[second->originalIndex] || 
                first->value + second->value != currentSum) {
                continue;
            }
            
            operationCount++;
            
            if (first->value > second->value) {
                inversionCount--;
            }
            
            Node* previousNode = first->previous;
            Node* nextNode = second->next;
            
            first->next = nextNode;
            if (nextNode != nullptr) {
                nextNode->previous = first;
            }
            
            if (previousNode != nullptr) {
                bool wasInverted = previousNode->value > first->value;
                bool isInverted = previousNode->value > currentSum;
                
                if (wasInverted && !isInverted) {
                    inversionCount--;
                } else if (!wasInverted && isInverted) {
                    inversionCount++;
                }
                
                Item leftItem(previousNode, first, previousNode->value + currentSum);
                pq.push(leftItem);
            }
            
            if (nextNode != nullptr) {
                bool wasInverted = second->value > nextNode->value;
                bool isInverted = currentSum > nextNode->value;
                
                if (wasInverted && !isInverted) {
                    inversionCount--;
                } else if (!wasInverted && isInverted) {
                    inversionCount++;
                }
                
                Item rightItem(first, nextNode, currentSum + nextNode->value);
                pq.push(rightItem);
            }
            
            first->value = currentSum;
            isMerged[second->originalIndex] = true;
        }
        
        // Clean up
        for (Node* node : nodeList) {
            delete node;
        }
        
        return operationCount;
    }
};
