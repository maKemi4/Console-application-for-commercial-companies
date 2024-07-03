#include "deque.h"
#include "commercialOrg.h"

using namespace std;

Deque::Deque()
: deqSize(0)
, deqHead(nullptr)
, deqTail(nullptr) {}

Deque::~Deque() 
{
    clear();
}

Deque::Deque(Deque &&d) noexcept
: deqSize(0)
, deqHead(d.deqHead)
, deqTail(d.deqTail) {
    d.deqSize = 0;
    d.deqHead = d.deqTail = nullptr;
}

Deque &Deque::operator=(Deque &&d) noexcept 
{
    if (this != &d) {
        clear();

        deqSize = d.deqSize;
        deqHead = d.deqHead;
        deqTail = d.deqTail;

        d.deqSize = 0;
        d.deqHead = d.deqTail = nullptr;
    }
    return *this;
}

size_t Deque::size() const
{
    return deqSize;
}

Deque &Deque::push_back(CommercialOrg *const value)
{
    Node *node = new Node{nullptr, deqTail, value};

    if (deqTail) {
        deqTail = deqTail->next = node;
    } else {
        deqTail = deqHead = node;
    }
    ++deqSize;
    return *this;
}

Deque &Deque::push_front(CommercialOrg *const value) 
{
    Node *node = new Node{ deqHead, nullptr, value};

    if (deqHead) {
        deqHead = deqHead->prev = node;
    } else {
        deqHead = deqTail = node;
    }
    ++deqSize;
    return *this;
}

CommercialOrg *Deque::pop_front() 
{
    Node *temp = deqHead;
    CommercialOrg *comOrg = temp->value;

    deqHead = deqHead->next;
    delete temp;

    if (deqHead) {
        deqHead->prev = nullptr;
    } else {
        deqTail = nullptr;
    }
    --deqSize;
    return comOrg;
}

CommercialOrg* Deque::pop_back() 
{
    Node* temp = deqTail;
    CommercialOrg* comOrg = temp->value;

    deqTail = deqTail->prev;
    delete temp;

    if (deqTail) {
        deqTail->next = nullptr;
    }
    else {
        deqHead = nullptr;
    }
    --deqSize;
    return comOrg;
}

Deque& Deque::clear() {
    for (Node* temp = deqHead; temp; temp = deqHead) {
        deqHead = deqHead->next;
        delete temp->value;
        delete temp;
    }
    deqTail = nullptr;
    deqSize = 0;
    return *this;
}

CommercialOrg* Deque::getById(int _id)
{
    for (Node* node = deqHead; node; node = node->next) {
        CommercialOrg* comorg = node->value;
        if (comorg && comorg->getId() == _id) {
            return comorg;
        }
    }
}

const Deque& Deque::for_each(const function<void(const CommercialOrg*)>& pred) const {
    for (const Node* node = deqHead; node; node = node->next) {
        pred(node->value);
    }
    return *this;
}