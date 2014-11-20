class Solution {
public:
    int removeElement(int A[], int n, int elem) {
            int front, rear;
            front = 0; rear = n;
            while (front < rear)
            {
                if (A[front] == elem)
                {
                    swap(A[front], A[--rear]);
                }
                else front++;
            }
            return front;
    }
};
