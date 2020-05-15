#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

template<typename T>
class ThreadSafeQueue
{
public:
	ThreadSafeQueue() {}

	void enqueue(const T& e)
	{
        std::unique_lock<std::mutex> lock(_mu);
        _queue.push(e);
    }

	void dequeue(T& e)
	{
        std::unique_lock<std::mutex> lock(_mu);
        if (!empty() )
        {
            e = _queue.front();
            _queue.pop();
        }
    }

    bool empty() const
    {
        return _queue.empty();
    }

private:
    std::queue<T> _queue;
	std::mutex _mu;
};

#endif
