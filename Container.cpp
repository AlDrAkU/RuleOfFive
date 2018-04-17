#include "stdafx.h"
#include "Container.h"
#include <cassert>
#include<iostream>

Container::Container( int capacity ) 
	: m_Size{ 0 }
	, m_Capacity{ capacity }
	, m_pElement{ new int[capacity] }
{
}

Container::Container(const Container & other)
	:m_Size{other.m_Size },
	m_pElement{ new int[other.m_Size] },
	m_Capacity{ m_Size }
{

	for (int i = 0; i < m_Size; ++i)
	{
		m_pElement[i] = other.m_pElement[i];
	}

}

Container::Container(Container && other)
	:m_Size(other.m_Size)
	,m_pElement(other.m_pElement)
	,m_Capacity(other.m_Capacity)
{
	other.m_pElement = nullptr;
	other.m_Size = 0;
	other.m_Capacity = 0;
	std::cout << "Move Constructor\n";
}

Container & Container::operator=(const Container & rhs)
{
	
	if (this != &rhs) {

		
		//delete[] this->m_pElement;
		//delete this;
		m_Capacity = rhs.m_Size;
		this->m_Capacity = rhs.m_Capacity;
		for (int i = 0; i < rhs.m_Size; ++i)
		{
			this->m_pElement[i] = rhs.m_pElement[i];
		}
			}
	return *this;
}

Container::~Container( ) 
{ 
	delete[] m_pElement; 
}

int Container::Size( ) const
{ 
	return m_Size; 
}

int Container::Capacity( ) const
{
	return m_Capacity;
}

int Container::Get( int index ) const
{
	assert( index >= 0 && index < m_Size );
	return m_pElement[index];
}

void Container::Set( int index, int value )
{
	assert( index >= 0 && index < m_Size );
	m_pElement[index] = value;
}

void Container::PushBack( int value )
{
	if ( !( m_Size < m_Capacity ) )
	{
		Reserve( m_Capacity * 2 );
	}
	m_pElement[m_Size] = value;
	++m_Size;
}

int & Container::operator[](int index) const
{
	return m_pElement[index];
}
int & Container::operator[](int index) 
{
	return m_pElement[index];
	}

Container & Container::operator=(Container && rhs)
{
	if (&rhs != this) {
		std::cout << "Move Assignment\n";
		m_Size = rhs.m_Size;
		m_Capacity = rhs.m_Capacity;

		delete[]m_pElement;
		m_pElement = rhs.m_pElement;
		rhs.m_pElement = nullptr;
		rhs.m_Size = 0;
		rhs.m_Capacity = 0;

	
	}
	return *this;

}

void Container::Reserve( int newCapacity )
{
	if ( newCapacity <= m_Capacity )
	{
		return;
	}

	// Dynamically allocate memory
	int * pNew = new int[newCapacity] {};
	// Copy the elements into this new memory
	for ( int i{ 0 }; i < m_Size; ++i )
	{
		pNew[i] = m_pElement[i];
	}
	// Free the old memory
	delete[] m_pElement;

	// Adapt the data members to this new situation
	m_pElement = pNew;
	m_Capacity = newCapacity;
}



