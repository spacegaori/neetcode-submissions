class LinkedList {
   public:
    LinkedList() : head(nullptr) {}

    int get(int index) {
        auto curr = head.get(); // use a raw pointer to traverse without taking ownership
        while (curr != nullptr && index > 0) {
            curr = curr->next.get();
            index--;
        }
        if (curr != nullptr && index == 0) {
            return curr->value;
        }

        return -1;
    }

    void insertHead(int val) {
        head = std::make_unique<Node>(val, std::move(head));
    }

    void insertTail(int val) {
        if (head == nullptr) {
            insertHead(val);
            return;
        }
        auto tail = head.get(); // use a raw pointer to traverse without taking ownership
        while (tail->next != nullptr) {
            tail = tail->next.get();
        }

        // tail is now at the end
        // create a new node next to the current tail
        tail->next = std::make_unique<Node>(val, nullptr);
    }

    bool remove(int index) {
        if (head == nullptr) {
            return false;
        }
        if (head != nullptr && index == 0) {
            head = std::move(head->next);
            return true;
        }

        auto prev = head.get(); // get non-owning raw pointer to head for traversal
        while (prev != nullptr && index > 1) {
            prev = prev->next.get();
            index--;
        }

        if (prev != nullptr && prev->next != nullptr && index == 1) {
            prev->next = std::move(prev->next->next);
            return true;
        }

        return false;
    }

    std::vector<int> getValues() {
        auto values = std::vector<int>();
        auto curr = head.get();
        while (curr != nullptr) {
            values.emplace_back(curr->value);
            curr = curr->next.get();
        }

        return values;
    }

   private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;

        Node (int value, std::unique_ptr<Node> next) : value(value), next(std::move(next)) {}
    };
    std::unique_ptr<Node> head;
};
