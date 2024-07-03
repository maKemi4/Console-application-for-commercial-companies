#pragma once
#include <functional>

using namespace std;

class CommercialOrg;

class Deque 
{
	struct Node 
    {
		Node* next;
		Node* prev;
		CommercialOrg* value;
	};
	size_t deqSize;
	Node* deqHead;
	Node* deqTail;

public:
    Deque();
    ~Deque();

    Deque(const Deque& d) = delete;
    Deque(Deque&& d) noexcept;

    Deque& operator=(const Deque& d) = delete;
    Deque& operator=(Deque&& d) noexcept;

    size_t size() const;

    CommercialOrg* getById(int _id);
    const Deque& for_each(const function<void(const CommercialOrg*)>& pred) const;
    
    Deque& push_back(CommercialOrg* const value);
    Deque& push_front(CommercialOrg* const value);

    CommercialOrg* pop_front();
    CommercialOrg* pop_back();

    Deque& clear();
};