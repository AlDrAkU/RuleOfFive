#pragma once

class Container
{
public:
	Container( int space  = 10);
	Container(const Container& other);
	Container(Container&& other);
	Container&  operator=(const Container& rhs); 
	Container&  operator=(int rhs) = delete;
	~Container( );
	int Size( ) const;
	int Capacity( ) const;
	int Get( int index ) const;
	void Set( int index, int value );
	void PushBack( int element );
	int & operator[](int index) const ;
	int & operator[](int index);
	Container& operator=(Container&& rhs);
	//Container& operator[](int index);

private:
	int m_Size;
	int m_Capacity;
	int *m_pElement;
	void Reserve( int newCapacity );
};
