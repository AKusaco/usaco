/* 合并两个有序的链表 */
/* 判断两个链表的首位置是否为空，若不为空，比较两个链表的首位置大小，将小的连接在p后，当有一个链表为空时将另一个链表的剩余部分连接在p后*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* merge;
    if(pHead1 == NULL){
        return pHead2;
    }
    else if(pHead2 == NULL){
        return pHead1;
    }
    if(pHead1 -> val <= pHead2 -> val){
        merge = pHead1;
        pHead1 = pHead1 -> next;
    }
    else{
        merge = pHead2;
        pHead2 = pHead2 -> next;
    }
    ListNode* p = merge;
    while(pHead1 != NULL &&  pHead2 != NULL){
        if(pHead1 -> val <= pHead2 ->val){
            p -> next = pHead1;
            p = p -> next;
            pHead1 = pHead1 -> next;
        }
        else{
            p -> next = pHead2;
            p = p -> next;
            pHead2 = pHead2 -> next;
        }
    }
    if(pHead1 == NULL){
        p -> next = pHead2;
    }
    else{
        p -> next = pHead1;
    }
    return merge;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == NULL){
        return pHead2;
    }
    else if(pHead2 == NULL){
        return pHead1;
    }
    ListNode* merge;
    if(pHead1 -> val <= pHead2 -> val){
        merge = pHead1;
        merge -> next = Merge(pHead1 -> next, pHead2);
    }
    else{
        merge = pHead2;
        merge -> next = Merge(pHead1, pHead2 -> next);
    }
    return merge
}
