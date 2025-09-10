/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    void sort(vector<int>& arr, int start, int mid, int end) {
        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++)
            left[i] = arr[start + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = start;

        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < n1) {
            arr[k++] = left[i++];
        }

        while (j < n2) {
            arr[k++] = right[j++];
        }
    }

    void merge(vector<int>& arr, int start, int end) {
        if (start >= end) return;

        int mid = (start + end) / 2;
        merge(arr, start, mid);
        merge(arr, mid + 1, end);

        sort(arr, start, mid, end);
    }

    Node* mergeSort(Node* head) {
        vector<int> arr;
        Node* temp = head;

        while (temp) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        merge(arr, 0, arr.size() - 1);

        temp = head;
        int index = 0;
        while (temp) {
            temp->data = arr[index++];
            temp = temp->next;
        }

        return head;
    }
};
