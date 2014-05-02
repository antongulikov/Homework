#pragma once

/// Template Class for SharedPointer
template <typename T>
class SharedPointer
{
public:
	
	
	SharedPointer() : sharedPointer( new Pointer()){
	}
	
	SharedPointer(T *ptr) : sharedPointer(new Pointer(ptr)){
	}
	
	SharedPointer(SharedPointer &shp) : sharedPointer(shp.sharedPointer){
		sharedPointer->count++;
	}
	
	/// Reference to value
	int getCount(){
		return sharedPointer->count;
	}
	/// Count of copies
	T *getPointer(){
		return sharedPointer->ptr;
	}
	
		
	SharedPointer& operator = (SharedPointer const &shp){
		if (sharedPointer != shp.sharedPointer){
			sharedPointer->count--;
			if (sharedPointer->count == -1)
				delete sharedPointer;
			sharedPointer = shp.sharedPointer;
			sharedPointer->count++;
		}
		return *this;
	}
	
	~SharedPointer(){
		sharedPointer->count--;
		if (sharedPointer->count == 0){
			delete sharedPointer;
		}
	} 
	

private :
	struct Pointer{
	
		Pointer() : ptr(nullptr), count(0){
		}
		
		Pointer(T *newPtr) : ptr(newPtr), count(1){
		}
		
		~Pointer(){
			delete ptr;
		}
		
		T *ptr;
		int count;
	};
	
	Pointer *sharedPointer; 		
};

