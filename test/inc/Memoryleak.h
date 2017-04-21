/*
 * Memoryleak.h
 *
 *  Created on: 21 apr. 2017
 *      Author: Acer
 */

#ifndef TEST_INC_MEMORYLEAK_H_
#define TEST_INC_MEMORYLEAK_H_

#include <cstdio>

class Memory_leak {
public:
								Memory_leak();
								Memory_leak(Memory_leak &item);
								Memory_leak(Memory_leak &&item);
	virtual 					~Memory_leak();

public:
	virtual Memory_leak			&operator=(const Memory_leak &item);

public:
	virtual void				*reserve(std::size_t size);
	virtual void				free(void *ptr);
	virtual bool				check();
	virtual bool				checkAndFree();

public:
	static Memory_leak			current;

private:
	void						**m_pointers;
	int							m_nPointers;

	std::size_t					*m_ptrSize;
	int							m_nPtrSizes;
};

extern void *operator new(std::size_t size);
extern void operator delete(void *ptr) noexcept;

#endif /* TEST_INC_MEMORYLEAK_H_ */
